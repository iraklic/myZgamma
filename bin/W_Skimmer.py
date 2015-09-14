import ROOT, os, commands

files=[]

#files.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/Data_CMSSW425_vgamma_42x_v8/SingleElectron_Run2011A_May10ReRecov1.root")
#files.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/Data_CMSSW425_vgamma_42x_v8/SingleElectron_Run2011A_PromptRecov4_Run165088to167913.root")
files.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/Data_CMSSW425_vgamma_42x_v8/SingleMu_Run2011A_May10ReRecov1.root")
files.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/Data_CMSSW425_vgamma_42x_v8/SingleMu_Run2011A_PromptRecov4_Run165088to167913.root")


def makeClass(file):

    f = ROOT.TFile.Open(file,"READ")
#    ROOT.gROOT.cd()
    f.cd("VgAnalyzerKit")
#    f.cd("VgNtuplizer")
    tr = ROOT.gDirectory.Get("EventTree")
    print tr

    tr.MakeClass("Skim")



def parseSkimmer(): 
    f = open("Skim.C","r")
    lines = f.readlines()
    f.close()

    f = open("Skim.C","w")

    includes = """\
#include <iostream>
//#include <stdio>
#include <string>
#include <TLorentzVector.h>
#include \"TROOT.h\"
#include \"TMath.h\"
#include \"TFile.h\"
#include \"TTree.h\"
#include \"TH2.h\"

bool muonId( float d0, float dZ, float chi2ndf, int stations, int pixels, int strips, int muonHits, float eIso, float hIso, float tIso, float pt, float RHO)
	{
	bool pass = false;
  
	if (	d0        < 0.02    &&
		dZ        < 0.1     &&
		chi2ndf   < 10.    &&
		stations  > 1      &&
		pixels    > 0      &&
		strips    > 10     &&
		muonHits  > 0      &&
		( eIso + hIso + tIso - RHO * 3.141592 * 0.3 * 0.3 ) < 0.1 * pt 
		) pass = true;
	return pass;
	}

bool electronId(float eleIsoHcalSolidDR03, float eleSCEta, float RHO, float eleIsoTrkDR03, float eleIsoEcalDR03, float elePt, float eledPhiAtVtx, float eledEtaAtVtx, float eleSigmaIEtaIEta, int run, int event)
	{
	double Pi = 3.14;
	bool pass = false;

	double cIsoEB = (eleIsoTrkDR03 + max(0., eleIsoEcalDR03 - 1.) + eleIsoHcalSolidDR03 - RHO*Pi*0.3*0.3) / elePt; 
	double cIsoEE = (eleIsoTrkDR03 + eleIsoEcalDR03 + eleIsoHcalSolidDR03 - RHO*Pi*0.3*0.3) / elePt;

//	EB
	if (	fabs(eleSCEta)		< 1.4442	&&
		cIsoEB			< 0.04		&&
		eleSigmaIEtaIEta	< 0.01		&&
		fabs(eledPhiAtVtx)	< 0.027		&&
		fabs(eledEtaAtVtx)	< 0.005) pass = true;

//	EE
	if (	fabs(eleSCEta)		< 2.5	&&
		fabs(eleSCEta)		> 1.566 &&
		cIsoEE			< 0.033	&&
		eleSigmaIEtaIEta	< 0.031	&&
		fabs(eledPhiAtVtx)	< 0.0281&&
		fabs(eledEtaAtVtx)	< 0.006) pass = true; 

	return pass;
	}

bool photonId(float eIso, float hIso, float tIso, float scEta, float HoE, float sigIEIE, float pt, float RHO)
	{
	bool pass = false;
  
	if (	fabs(scEta) < 1.4442  &&
		eIso        < ( 4.2 + 0.006 * pt + 0.183 * RHO ) &&
		hIso        < ( 2.2 + 0.0025* pt + 0.062 * RHO ) &&
		tIso        < ( 2.0 + 0.001 * pt + 0.167 * RHO ) &&
		HoE         < 0.05 &&
		sigIEIE     < 0.011 // new
//		sigIEIE     < 0.013 // old
//		sigIEIE     < 10000
		) pass = true;

	if (	fabs(scEta) < 2.5    &&
		fabs(scEta) > 1.566  &&
		eIso        < ( 4.2 + 0.006 * pt + 0.090 * RHO ) &&
		hIso        < ( 2.2 + 0.0025* pt + 0.180 * RHO ) &&
		tIso        < ( 2.0 + 0.001 * pt + 0.032 * RHO ) &&
		HoE         < 0.05 &&
		sigIEIE     < 0.03
//		sigIEIE     < 10000
		) pass = true;

	return pass;
	}
float correctedPhoEt(float PHOET, float PHOSCETA, float PHOR9, int RUN)
	{
	float corPhoEt = PHOET;
	if (fabs(PHOSCETA) < 1.5)
		{
		if (PHOR9 > 0.94)
			{
			if ( RUN >= 160431 && RUN <= 163869) corPhoEt = PHOET * (1. -0.47/100.);
			if ( RUN >= 165071 && RUN <= 165970) corPhoEt = PHOET * (1. -0.07/100.);
			if ( RUN >= 165971 && RUN <= 166502) corPhoEt = PHOET * (1. +0.03/100.);
			if ( RUN >= 166503 && RUN <= 166861) corPhoEt = PHOET * (1. +0.11/100.);
			if ( RUN >= 166862 && RUN <= 167784) corPhoEt = PHOET * (1. +0.14/100.);
			}
		else
			{
			if ( RUN >= 160431 && RUN <= 163869) corPhoEt = PHOET * (1. +0.25/100.);
			if ( RUN >= 165071 && RUN <= 165970) corPhoEt = PHOET * (1. +0.49/100.);
			if ( RUN >= 165971 && RUN <= 166502) corPhoEt = PHOET * (1. +0.67/100.);
			if ( RUN >= 166503 && RUN <= 166861) corPhoEt = PHOET * (1. +0.63/100.);
			if ( RUN >= 166862 && RUN <= 167784) corPhoEt = PHOET * (1. +0.74/100.);
			}
		}
	else
		{
		if (PHOR9 > 0.94)
			{
			if ( RUN >= 160431 && RUN <= 163869) corPhoEt = PHOET * (1. +0.58/100.);
			if ( RUN >= 165071 && RUN <= 165970) corPhoEt = PHOET * (1. +2.49/100.);
			if ( RUN >= 165971 && RUN <= 166502) corPhoEt = PHOET * (1. +3.76/100.);
			if ( RUN >= 166503 && RUN <= 166861) corPhoEt = PHOET * (1. +4.50/100.);
			if ( RUN >= 166862 && RUN <= 167784) corPhoEt = PHOET * (1. +5.61/100.);
			}
		else
			{
			if ( RUN >= 160431 && RUN <= 163869) corPhoEt = PHOET * (1. -0.10/100.);
			if ( RUN >= 165071 && RUN <= 165970) corPhoEt = PHOET * (1. +0.62/100.);
			if ( RUN >= 165971 && RUN <= 166502) corPhoEt = PHOET * (1. +1.33/100.);
			if ( RUN >= 166503 && RUN <= 166861) corPhoEt = PHOET * (1. +1.78/100.);
			if ( RUN >= 166862 && RUN <= 167784) corPhoEt = PHOET * (1. +2.73/100.);
			}
		}
//	cout << PHOET << "\t" << corPhoEt << endl;
	return corPhoEt;
	}
// ======================================================================
float correctedEleEn(float eleEn, float eleSCETA, int RUN, float eleE3x3, float eleSCRawEn)
	{
	float corEleEn = eleEn;
	double eleR9 = eleE3x3 / eleSCRawEn;
	if (fabs(eleSCETA) < 1.5)
		{
		if (eleR9 > 0.94)
			{
			if ( RUN >= 160431 && RUN <= 163869) corEleEn = eleEn * (1. -0.47/100.);
			if ( RUN >= 165071 && RUN <= 165970) corEleEn = eleEn * (1. -0.07/100.);
			if ( RUN >= 165971 && RUN <= 166502) corEleEn = eleEn * (1. +0.03/100.);
			if ( RUN >= 166503 && RUN <= 166861) corEleEn = eleEn * (1. +0.11/100.);
			if ( RUN >= 166862 && RUN <= 167784) corEleEn = eleEn * (1. +0.14/100.);
			}
		else
			{
			if ( RUN >= 160431 && RUN <= 163869) corEleEn = eleEn * (1. +0.25/100.);
			if ( RUN >= 165071 && RUN <= 165970) corEleEn = eleEn * (1. +0.49/100.);
			if ( RUN >= 165971 && RUN <= 166502) corEleEn = eleEn * (1. +0.67/100.);
			if ( RUN >= 166503 && RUN <= 166861) corEleEn = eleEn * (1. +0.63/100.);
			if ( RUN >= 166862 && RUN <= 167784) corEleEn = eleEn * (1. +0.74/100.);
			}
		}
	else
		{
		if (eleR9 > 0.94)
			{
			if ( RUN >= 160431 && RUN <= 163869) corEleEn = eleEn * (1. +0.58/100.);
			if ( RUN >= 165071 && RUN <= 165970) corEleEn = eleEn * (1. +2.49/100.);
			if ( RUN >= 165971 && RUN <= 166502) corEleEn = eleEn * (1. +3.76/100.);
			if ( RUN >= 166503 && RUN <= 166861) corEleEn = eleEn * (1. +4.50/100.);
			if ( RUN >= 166862 && RUN <= 167784) corEleEn = eleEn * (1. +5.61/100.);
			}
		else
			{
			if ( RUN >= 160431 && RUN <= 163869) corEleEn = eleEn * (1. -0.10/100.);
			if ( RUN >= 165071 && RUN <= 165970) corEleEn = eleEn * (1. +0.62/100.);
			if ( RUN >= 165971 && RUN <= 166502) corEleEn = eleEn * (1. +1.33/100.);
			if ( RUN >= 166503 && RUN <= 166861) corEleEn = eleEn * (1. +1.78/100.);
			if ( RUN >= 166862 && RUN <= 167784) corEleEn = eleEn * (1. +2.73/100.);
			}
		}
//	cout << eleEn << "\t" << corEleEn << endl;
	return corEleEn;
	}


    """

    createNewFile = """\
	int electronID = 11;
	int photonID = 12;
	Long64_t nentries = fChain->GetEntriesFast();
	TFile *newFile = new TFile(\"skim.root\",\"recreate\");
	TChain *newchain = (TChain*)fChain->CloneTree(0);
	TTree *newTree = newchain->GetTree();
    
    """

    Selection = """\
	if ((ientry % 500000) == 0)
		{
		float perc = float(ientry)*100./float(nentries);
		printf(\"Processed Events \t\t%i\t out of %i \t%.0f %%\\n\",int(ientry), int (nentries), perc);
		}

		float dRcut = 0.7; 
		float phoEtCut = 10;
		float lepPtCut = 30;
		vector<int> cleanPho;
		vector<int> cleanEle;
		vector<int> cleanMu;

		if (pfMET < 25) continue;

		if (nVtx == 0) continue;
		if (IsVtxGood == 0) continue;
		if (IsTracksGood == 0) continue;

		for (int iPho=0; iPho < nPho; iPho++)
			{
//			phoEt[iPho] = correctedPhoEt(phoEt[iPho],phoSCEta[iPho],phoR9[iPho],run);
//			ET cut
			if (phoEt[iPho] < phoEtCut)	continue;
			if (fabs(phoSCEta[iPho])> 2.5)	continue;
			if (fabs(phoSCEta[iPho]) > 1.4442 && fabs(phoSCEta[iPho]) < 1.566 ) continue;
			if (phoHoverE[iPho] > 0.5 )	continue;
//			if (phoOverlap[iPho] == 1)	continue;
			if (phohasPixelSeed[iPho] == 1)	continue;
			cleanPho.push_back(iPho);
			}
		if (cleanPho.size() == 0) continue;

		for (int iEle=0; iEle < nEle; iEle++)
			{
//			eleEn[iEle] = correctedEleEn(eleEn[iEle], eleSCEta[iEle], run, eleE3x3[iEle], eleSCRawEn[iEle]);
//			elePt[iEle] = correctedEleEn(elePt[iEle], eleSCEta[iEle], run, eleE3x3[iEle], eleSCRawEn[iEle]);

			if (elePt[iEle] < lepPtCut) continue;
			if (fabs(eleSCEta[iEle]) > 2.5 || ( fabs(eleSCEta[iEle]) > 1.4442 && fabs(eleSCEta[iEle]) < 1.566) ) continue;

			cleanEle.push_back(iEle);
			}

		for (int iMu=0; iMu < nMu; iMu++)
			{
			if (muPt[iMu] < lepPtCut) continue;
			if (fabs(muEta[iMu]) > 2.4 ) continue;
			if (muType[iMu] != 14) continue; // isGlobal && Tracker
			cleanMu.push_back(iMu);
			}
		if (cleanEle.size() < 1 && cleanMu.size() < 1) continue;
    

		newTree->Fill();
    """

    for line in lines:
        if ("#include <TCanvas.h>") in line:
            f.write(includes)
        elif "Long64_t nentries = fChain->GetEntriesFast();" in line:
            f.write(createNewFile)
        elif ("// if (Cut(ientry) < 0) continue;") in line:
            f.write(Selection)
        else:
            f.write(line)
    f.close()

    f = open("Skim.C","r")
    lines = f.readlines()
    f.close()
    temp = lines[:-1]
    f = open("Skim.C","w")
    for line in temp:
        f.write(line)

    f.write("""\
      newFile->cd();
      newTree->Write();
      newFile->Close();
      }\n
      """
            )
    f.close()
    
    
def runSkimmer():
    ROOT.gROOT.ProcessLine(".L Skim.C++")
    ROOT.gROOT.ProcessLine("Skim t")
    ROOT.gROOT.ProcessLine("t.Loop()")
    
for file in files:
    
    makeClass(file)
    parseSkimmer()
    runSkimmer()

    local = commands.getoutput("pwd");

    outF = "%s/%s_skim.root"%(local,file.split("/")[-1][:-5])
    os.system("mv skim.root %s"%outF)

    f = ROOT.TFile.Open(file,"READ")
    ROOT.gROOT.cd()
    h = f.Get("VgAnalyzerKit/hEvents").Clone()
#    h = f.Get("VgNtuplizer/hEvents").Clone()
    f.Close()
    f = ROOT.TFile.Open(outF,"UPDATE")
    f.cd()
    h.Write()
    f.Close()
