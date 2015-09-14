import ROOT, os, commands

files=[]

# NEW DATASETS  2178.0(A) + 2520.8(B)
# --- ELECTRONS
#files.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/Data/DoubleElectron_Run2011A_03Oct2011_v1.root")
#files.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/Data/DoubleElectron_Run2011A_05Aug2011_v1.root")
#files.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/Data/DoubleElectron_Run2011A_05Aug2011_v1_excTrg_addCSC.root")
#ifiles.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/Data/DoubleElectron_Run2011A_May10ReReco_v1.root")
#files.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/Data/DoubleElectron_Run2011A_PromptReco_v4.root")
files.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/Data/DoubleElectron_Run2011B_PromptReco_v1_run175860_178078.root")
#files.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/Data/DoubleElectron_Run2011B_PromptReco_v1_run178098_178677.root")
#files.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/Data/DoubleElectron_Run2011B_PromptReco_v1_run178703_179431.root")
#files.append("DoubleElectron_Run2011B-PromptReco-v1_run179434_180252.root")

# --- MUONS
#files.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/Data/DoubleMu_Run2011A_03Oct2011_v1.root")
#files.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/Data/DoubleMu_Run2011A_05Aug2011_v1.root")
#files.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/Data/DoubleMu_Run2011A_May10ReReco_v1.root")
#files.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/Data/DoubleMu_Run2011A_PromptReco_v4.root")
#files.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/Data/DoubleMu_Run2011B_PromptReco_v1_run175860_178078.root")
#files.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/Data/DoubleMu_Run2011B_PromptReco_v1_run178098_178677.root")
#files.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/Data/DoubleMu_Run2011B_PromptReco_v1_run178703_179431.root")
#files.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/Data/DoubleMu_Run2011B_PromptReco_v1_run179434_180252.root")

#files.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/MC/ZgammaMu_1Jet_Madgraph_Fall11.root")
#files.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/MC/ZgammaEle_1Jet_Madgraph_Fall11.root")
#files.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/MC/DYJetsToLL_TuneZ2_M50_Madgraph_Fall11.root")

# OLD DATASETS ~750 1/pb
#files.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/Data_CMSSW425_vgamma_42x_v8/DoubleElectron_Run2011A_May10ReRecov1.root")
#files.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/Data_CMSSW425_vgamma_42x_v8/DoubleElectron_Run2011A_PromptRecov4_Run165088to167913.root")
#files.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/Data_CMSSW425_vgamma_42x_v8/DoubleMu_Run2011A_May10ReRecov1.root")
#files.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/Data_CMSSW425_vgamma_42x_v8/DoubleMu_Run2011A_PromptRecov4_Run165088to167913.root")

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

"""

    createNewFile = """\
	int electronID = 11;
	int photonID = 12;
	int nBunches = nBunches_CONDOR;
	int currBunch = currBunch_CONDOR;
	Long64_t nentries = fChain->GetEntriesFast();
	Long64_t startEntry = 0;
	if (last_batch < last_batch_CONDOR)
		{
		double bunchSize = nentries / nBunches;
		startEntry = nentries * currBunch;
		nentries = startEntry + bunchSize;
		}
	TFile *newFile = new TFile(\"skim.root\",\"recreate\");
	TChain *newchain = (TChain*)fChain->CloneTree(0);
	TTree *newTree = newchain->GetTree();
    
    """

    Selection = """\
	if (jentry < startEntry) continue;
	if ((ientry % 100000) == 0)
		{
		float perc = float(ientry)*100./float(nentries);
		printf(\"Processed Events \t\t%i\t out of %i \t%.0f %%\\n\",int(ientry), int (nentries), perc);
		}

		float dRcut = 0.7; 
		float phoEtCut = 10;
		float lepPtCut = 15;
		vector<int> cleanPho;
		vector<int> cleanEle;
		vector<int> cleanMu;

		if (nVtx == 0) continue;
//		if (IsVtxGood == 0) continue;
		if (IsTracksGood == 0) continue;
/*
		for (int iPho=0; iPho < nPho; iPho++)
			{
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
*/
		for (int iEle=0; iEle < nEle; iEle++)
			{

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
		if (cleanEle.size() < 2 && cleanMu.size() < 2) continue;
    

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
#    h = f.Get("hEvents").Clone()
    h = f.Get("VgAnalyzerKit/hEvents").Clone()
#    h = f.Get("VgNtuplizer/hEvents").Clone()
    f.Close()
    f = ROOT.TFile.Open(outF,"UPDATE")
    f.cd()
    h.Write()
    f.Close()
