// -*- C++ -*-
//#include "ZgammaAnalysis.h"

#include <iostream>
#include <string>

// CMS includes
#include "FWCore/Utilities/interface/InputTag.h"
#include "DataFormats/Common/interface/Handle.h"
#include "DataFormats/PatCandidates/interface/Jet.h"

//#include "PhysicsTools/FWLite/interface/EventContainer.h"
#include "PhysicsTools/FWLite/interface/CommandLineParser.h" 
#include "ElectroWeakAnalysis/MultiBosons/interface/PhosphorCorrectionFunctor.h"

// USER INLCUDES
#include "DataFormats/Math/interface/deltaR.h"
#include <TLorentzVector.h>
#include "TROOT.h"
#include "TMath.h"
#include "TCanvas.h"
#include "TRandom3.h"
#include "TFile.h"
#include "TTree.h"
#include "TAxis.h"
#include "TH2.h"
#include "TH3.h"
#include "TPaletteAxis.h"
#include "TPave.h"
#include "TBox.h"
#include "TGaxis.h"
#include "TLine.h"


using namespace std;
using optutl::CommandLineParser;

TLorentzVector RotateFromZ(TLorentzVector V0, TLorentzVector Z0)
	{
	TVector3 Z = Z0.Vect();
	TVector3 V = V0.Vect();

	double PI = TMath::Pi();
	double thetaZ	= 0;
	double phiZ	= 0;

	thetaZ = Z.Theta();
	phiZ = Z.Phi();

	TVector3 XPrime, ZPrime;
	double alpha;

	alpha = PI/2 + phiZ;

	XPrime.SetMagThetaPhi(1, PI/2, alpha);
	ZPrime.SetMagThetaPhi(1, thetaZ, phiZ);

	V.Rotate(alpha, ZPrime);
	V.Rotate(-thetaZ, XPrime);
	V.RotateZ(-1*alpha);

	TLorentzVector newV(V, V0.E());

	return newV;
	}

TLorentzVector RotateToZ(TLorentzVector V0, TLorentzVector Z0)
	{
	TVector3 Z = Z0.Vect();
	TVector3 V = V0.Vect();

	double PI = TMath::Pi();
	double thetaZ	= 0;
	double phiZ	= 0;

	thetaZ = Z.Theta();
	phiZ = Z.Phi();

	TVector3 XPrime, ZPrime;
	double alpha = PI/2 + phiZ;
	XPrime.SetMagThetaPhi(1, PI/2, alpha);
	ZPrime.SetMagThetaPhi(1, thetaZ, phiZ);

	V.RotateZ(alpha);
	V.Rotate(thetaZ, XPrime);
	V.Rotate(-1*alpha, ZPrime);

	TLorentzVector newV(V, V0.E());

	return newV;
	}

//===========================================================================================
map<string, double> zgammaAngleCalculator(TLorentzVector l1, TLorentzVector l2, TLorentzVector gamma)
	{
//	Defining Variables
        TLorentzVector zgamma, Z;
        TLorentzVector Z_cm;
	TLorentzVector l1_Z_cm;

//	Defininf boost vectors;
	TVector3 betaZgamma, betaZ, beta_Z_cm;

//	Defininf container map
	map<string, double> angleMap;

//	constructing Z and ZGamma 4vectors
	Z = l1 + l2;
	zgamma = Z + gamma;

//	initializing all variables with variables in lab frame
	Z_cm = Z;
	l1_Z_cm = l1;

//	Initializing boostvectors
	betaZgamma = -1*zgamma.BoostVector();

//	BOOSTING into Zgamma CM Frame
	Z_cm.Boost(betaZgamma);

	l1_Z_cm.Boost(betaZgamma);

//	initializing boostvector for Z_cm rest frame from ZGamma CM frame
	beta_Z_cm = -1*Z_cm.BoostVector();

	l1_Z_cm.Boost(beta_Z_cm);

//	making correct rotations for angles
	TLorentzVector l1_CORR = RotateFromZ(l1_Z_cm, Z_cm);
	TLorentzVector Z_CORR = RotateFromZ(Z_cm, zgamma);


//	Angle Calculation
	angleMap["cosThetaL"]		= cos((l1_CORR.Vect()).Theta());
	angleMap["thetaL"]		= (l1_CORR.Vect()).Theta();
	angleMap["cosThetaZ"]		= cos((Z_CORR.Vect()).Theta());
	angleMap["thetaZ"]		= (Z_CORR.Vect()).Theta();
	angleMap["phiL"]		= (l1_CORR.Vect()).Phi();
	angleMap["phiZ"]		= (Z_CORR.Vect()).Phi();

	return angleMap;
	}

// ///////////////////// //
// // COUNTER HELPER  // //
// ///////////////////// //

void fillNPassed(int &passBin, TH1I* &nPassed,  map<int,string> &nPassedMap,string description)
	{
	nPassed->Fill(passBin);
	passBin++;
	if (nPassedMap.find(passBin - 1) == nPassedMap.end()) nPassedMap.insert(pair<int,string>(passBin - 1,description));
	}
// =======================================================
bool muonId( float d0, float dZ, float chi2ndf, int stations, int pixels, int strips, int muonHits, float eIso, float hIso, float tIso, float pt, float RHO)
	{
	bool pass = false;
	double Pi = TMath::Pi();
  
	if (	fabs(d0)  < 0.02    &&
		fabs(dZ)  < 0.1     &&
		chi2ndf   < 10.    &&
		stations  > 1      &&
		pixels    > 0      &&
		strips    > 10     &&
		muonHits  > 0      &&
		( eIso + hIso + tIso - RHO * Pi * 0.3 * 0.3 ) < 0.1 * pt 
		) pass = true;
	return pass;
	}
// -----------------------------------------------------------
bool electronId(float d0, float dZ, float eleIsoHcalSolidDR03, float eleSCEta, float RHO, float eleIsoTrkDR03, float eleIsoEcalDR03, float elePt, float eledPhiAtVtx, float eledEtaAtVtx, float eleSigmaIEtaIEta, int run, int event)
	{
	double Pi = TMath::Pi();
	bool pass = false;

	double cIsoEB = (eleIsoTrkDR03 + max(0., eleIsoEcalDR03 - 1.) + eleIsoHcalSolidDR03 - RHO*Pi*0.3*0.3) / elePt; 
	double cIsoEE = (eleIsoTrkDR03 + eleIsoEcalDR03 + eleIsoHcalSolidDR03 - RHO*Pi*0.3*0.3) / elePt;

	if (fabs(d0) > 0.02 || fabs(dZ) > 0.1) return false;

//	EB
	if (	fabs(eleSCEta)		< 1.4442	&&
		cIsoEB			< 0.053	&&
		eleSigmaIEtaIEta	< 0.01	&&
		fabs(eledPhiAtVtx)	< 0.039	&&
		fabs(eledEtaAtVtx)	< 0.005) pass = true;

//	EE
	if (	fabs(eleSCEta)		< 2.5	&&
		fabs(eleSCEta)		> 1.566 &&
		cIsoEE			< 0.042	&&
		eleSigmaIEtaIEta	< 0.031	&&
		fabs(eledPhiAtVtx)	< 0.028	&&
		fabs(eledEtaAtVtx)	< 0.007) pass = true; 

	return pass;
	}
// ======================================================================

double corrVgamma(double en, double scEta, double r9, TRandom3* rr, int run, int event)
	{
	double eta = fabs(scEta);
	double mz = 91.19;

	float scaleMCCorrEB[4]   = { 0.190, -0.635, -0.758,  0.445};
	float smearMCCorrEB[4]   = { 0.950,  0.000,  0.322,  1.750}; 

//	list of correction coefficients for EE
	float scaleMCCorrEE[4]   = {-1.70,   0.58,  -1.57,  -1.25};
	float smearMCCorrEE[4]   = { 2.48,   2.56,   3.32,   2.60}; 

//	Corrections for MC, EB
	if (eta < 1.5)
		{
//		energy scale
		en *= 1 + scaleMCCorrEB[0]/mz;
		en *= rr->Gaus(1, smearMCCorrEB[0]/mz); 

		if ( eta < 1.0 )
			{
			if ( r9 <= 0.94 )
				{
				en *= 1 + scaleMCCorrEB[1]/mz; // 0.14
				en *= rr->Gaus(1, smearMCCorrEB[1]/mz); // extra 0.35% smearing 
				}
			}
		else
			{
//			4th module
			en *= 1 + scaleMCCorrEB[2]/mz; 
			en *= rr->Gaus(1, smearMCCorrEB[2]/mz); // extra 1.8% ~0.80 GeV
			if ( r9 <= 0.94 )
				{
				en *= 1 + scaleMCCorrEB[3]/mz;
				en *= rr->Gaus(1, smearMCCorrEB[3]/mz); // 1.37
				}
			}
		}
	else
		{
//		scales
		if ( eta <  2.0 && r9 >  0.94 ) en *= 1 + scaleMCCorrEE[0]/mz;
		if ( eta <  2.0 && r9 <= 0.94 ) en *= 1 + scaleMCCorrEE[1]/mz;
		if ( eta >= 2.0 && r9 >  0.94 ) en *= 1 + scaleMCCorrEE[2]/mz;
		if ( eta >= 2.0 && r9 <= 0.94 ) en *= 1 + scaleMCCorrEE[3]/mz;

//		resolutions
		if ( eta <  2.0 && r9 >  0.94 ) en *= rr->Gaus(1, smearMCCorrEE[0]/mz);
		if ( eta <  2.0 && r9 <= 0.94 ) en *= rr->Gaus(1, smearMCCorrEE[1]/mz);
		if ( eta >= 2.0 && r9 >  0.94 ) en *= rr->Gaus(1, smearMCCorrEE[2]/mz);
		if ( eta >= 2.0 && r9 <= 0.94 ) en *= rr->Gaus(1, smearMCCorrEE[3]/mz);
		}
	return en;
	}

bool photonId(float eIso, float hIso, float tIso, float scEta, float HoE, float sigIEIE, float pt, float RHO)
	{
	bool pass = false;
  
	if (fabs(scEta) < 1.4442 && sigIEIE < 0.001) return false;

	if (	fabs(scEta) < 1.4442  &&
		eIso        < ( 4.2 + 0.006 * pt + 0.183 * RHO ) &&
		hIso        < ( 2.2 + 0.0025* pt + 0.062 * RHO ) &&
		tIso        < ( 2.0 + 0.001 * pt + 0.0167 * RHO ) &&
		HoE         < 0.05 &&
		sigIEIE     < 0.011 
		) pass = true;

	if (	fabs(scEta) < 2.5    &&
		fabs(scEta) > 1.566  &&
		eIso        < ( 4.2 + 0.006 * pt + 0.090 * RHO ) &&
		hIso        < ( 2.2 + 0.0025* pt + 0.180 * RHO ) &&
		tIso        < ( 2.0 + 0.001 * pt + 0.032 * RHO ) &&
		HoE         < 0.05 &&
		sigIEIE     < 0.03
		) pass = true;

	return pass;
	}
float getWeightFromPtVtxSF(float muonPT, float evVertex, TH2F* & SFH)
	{
//	X axis is PT and Y axis ETA
	int xb = 0;
	int yb = 0;

	int xbMax = SFH->GetXaxis()->GetNbins();
	xb = SFH->GetXaxis()->FindBin(evVertex);
	if (xb > xbMax) xb = xbMax;
	if (xb < 1) xb = 1;

	int ybMax = SFH->GetYaxis()->GetNbins();
	yb = SFH->GetYaxis()->FindBin(muonPT);
	if (yb > ybMax) yb = ybMax;
	if (yb < 1) yb = 1;

	return SFH->GetBinContent(xb,yb);
	}
float getWeightFromEtaSF(float muonEta, TH1F* & SFH)
	{
	int xb = 0;
	int xbMax = SFH->GetXaxis()->GetNbins();
	xb = SFH->GetXaxis()->FindBin(muonEta);
	if (xb > xbMax) xb = xbMax;
	if (xb < 1) xb = 1;
	return SFH->GetBinContent(xb);
	}

// ///////////////////// //
// // Main Subroutine // //
// ///////////////////// //

// OPENNING FILES ONCE TO BE READ FOR SOME SFs

// FOR PILEUP
TFile* dataPuFileRunA_3D =  TFile::Open("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/eleSF/PileupWeight_68mb_2011A.root","READ");
TFile* dataPuFileRunB_3D =  TFile::Open("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/eleSF/PileupWeight_68mb_2011B.root","READ");

// FOR ELECTRONS
TFile* eleIDScaleFactorA = TFile::Open("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/eleSF/eleIDSF_2011A.root","READ");
TFile* eleIDScaleFactorB = TFile::Open("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/eleSF/eleIDSF_2011B.root","READ");
TFile* eleRECOScaleFactorA = TFile::Open("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/eleSF/eRECO_SF_2011A.root","READ");
TFile* eleRECOScaleFactorB = TFile::Open("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/eleSF/eRECO_SF_2011B.root","READ");
TFile* eleHLTScaleFactorA = TFile::Open("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/eleSF/eleHLTSF_2011A.root","READ");
TFile* eleHLTScaleFactorB = TFile::Open("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/eleSF/eleHLTSF_2011B.root","READ");

// FOR MUONS
TFile * muIDScaleFactorA    = TFile::Open("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/muSF/bigSFa_Eta_Pt.root","READ");
TFile * muIDScaleFactorB    = TFile::Open("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/muSF/bigSFb_Eta_Pt.root","READ");

TFile * muTrigSF = TFile::Open("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/muSF/TrigSF.root","READ");


int main (int argc, char* argv[]) 
	{
	int eventCounter = 1;
//	FILE * pFile;
//	pFile = fopen ("mcEventList.txt" , "a");

//	mapts and TTree for angle variables
	map<string, double> angleMap, /*mcCutAngleMap,*/ mcAngleMap, TangleMap, TmcangleMap, TmcCutangleMap;
	TangleMap["cosThetaL"];
	TangleMap["thetaL"];
	TangleMap["cosThetaZ"];
	TangleMap["thetaZ"];
	TangleMap["phiL"];
	TangleMap["phiZ"];
	TangleMap["ZMass"];
	TangleMap["ZGMass"];
	TangleMap["Weight"];

	TmcangleMap["cosThetaL"];
	TmcangleMap["thetaL"];
	TmcangleMap["cosThetaZ"];
	TmcangleMap["thetaZ"];
	TmcangleMap["phiL"];
	TmcangleMap["phiZ"];
	TmcangleMap["ZMass"];
	TmcangleMap["ZGMass"];
	TmcangleMap["Weight"];

	TmcCutangleMap["cosThetaL"];
	TmcCutangleMap["thetaL"];
	TmcCutangleMap["cosThetaZ"];
	TmcCutangleMap["thetaZ"];
	TmcCutangleMap["phiL"];
	TmcCutangleMap["phiZ"];
	TmcCutangleMap["ZMass"];
	TmcCutangleMap["ZGMass"];
	TmcCutangleMap["Weight"];

	// ////////////////////////// //
	// // Command Line Options // //
	// ////////////////////////// //

//	Tell people what this analysis code does and setup default options.
	optutl::CommandLineParser parser ("make ZGamma plots");
//	parser.addOption ("CheckDub",		CommandLineParser::kBool,	"CheckDublicate",		false);
	parser.addOption ("matchMC",		CommandLineParser::kBool,	"matchObjectsToMc",		false);
	parser.addOption ("removeMcPhoJ",	CommandLineParser::kBool,	"remove mc photons from Zjets",	false);
	parser.addOption ("photonID",		CommandLineParser::kInteger,	"specify photon ID",		-1);
	parser.addOption ("electronID",		CommandLineParser::kInteger,	"specify electron ID",		-1);
	parser.addOption ("muonID",		CommandLineParser::kInteger,	"specify muon ID",		-1);
	parser.addOption ("Run",		CommandLineParser::kInteger,	"Run",				0);
	parser.addOption ("noPhoton",		CommandLineParser::kBool,	"noPhoton",			false);
//	parser.addOption ("aTgcTreeF",		CommandLineParser::kString,	"file atgc to be written to",	"EMPTY");
	parser.parseArguments (argc, argv);

//	Parse the command line arguments
	parser.parseArguments (argc, argv);

	// //////////////////////////// //
	// // Create Event Container // //
	// //////////////////////////// //
	vector<string> fileNames	= parser.stringVector ("inputFiles");
	string	outfileName		= parser.stringValue  ("outputfile");
//	bool CheckDub			= parser.boolValue    ("CheckDub");
	bool matchMC			= parser.boolValue    ("matchMC");
	bool removeMcPhoJ		= parser.boolValue    ("removeMcPhoJ");
	int photonID			= parser.integerValue ("photonID");
	int electronID			= parser.integerValue ("electronID");
	int muonID			= parser.integerValue ("muonID");
	int Run				= parser.integerValue ("Run");
	bool noPhoton			= parser.boolValue ("noPhoton");
	bool RunA			= (Run == 1);
	bool RunB			= (Run == 2);

	if (RunA) cout << " -= WORKING WITH Run A =- " << endl;
	if (RunB) cout << " -= WORKING WITH Run B =- " << endl;

	string iFile;
	if (!fileNames.size())
		{
		cout << "\nPLEASE PROVIDE INPUT FILE!!!!\n" << endl;
		return 0;
		}
	else  iFile = fileNames.at(0); // for now only 1 file at a time

//	get file name from path
	size_t pos    = iFile.find_last_of('/');
	string FILE   = iFile.substr(pos+1);

//	translate string to char for filenames
	char iF[200];
	char oF[200];
	sprintf(iF, "%s", iFile.c_str());
	sprintf(oF, "%s", outfileName.c_str());

//	open file
	TH1::SetDefaultSumw2();
	TH2::SetDefaultSumw2();
	TFile* f = TFile::Open(iF,"READ");
	if (!f)
		{
		cout << "=================================\n\nFILE NOT FOUND" << endl;
		return 0;
		}

//	TTree* tr	= (TTree*)f->Get("VgAnalyzerKit/EventTree");
	TTree* tr	= (TTree*)f->Get("EventTree");
//	TH1F* hEvents	= (TH1F *)f->Get("VgAnalyzerKit/hEvents");
	TH1F* hEvents	= (TH1F *)f->Get("hEvents");
	TFile* f_out	= TFile::Open(oF,"RECREATE");

	f_out->cd();

	TTree * outTree		= new TTree("angles", "qq->Zgamma->llgamma angles");
	TTree * mcoutTree	= new TTree("mcangles", "qq->Zgamma->llgamma MC angles");
	TTree * mcCutoutTree	= new TTree("mcCutangles", "qq->Zgamma->llgamma MC angles with selection cuts");

	for (map<string, double>::iterator mi = TangleMap.begin(); mi != TangleMap.end(); mi++)
		{
		string name = mi->first;
		string leafList = name + "/D";
		outTree->Branch(name.c_str(), &(mi->second), leafList.c_str());
		}

	for (map<string, double>::iterator mi = TmcangleMap.begin(); mi != TmcangleMap.end(); mi++)
		{
		string name = mi->first;
		string leafList = name + "/D";
		mcoutTree->Branch(name.c_str(), &(mi->second), leafList.c_str());
		}

	for (map<string, double>::iterator mi = TmcangleMap.begin(); mi != TmcangleMap.end(); mi++)
		{
		string name = mi->first;
		string leafList = name + "/D";
		mcCutoutTree->Branch(name.c_str(), &(mi->second), leafList.c_str());
		}

//	get number of entries in ttree
	long nEvents = tr->GetEntries();

	cout << "\n===================\n" << "PROCESSING FILE:\t" << f->GetName() << endl;
	cout << "NUMBER OF ENTRIES:\t" << nEvents  << endl;

	// ////////////////////////////////// //
	// //         Begin Run            // //
	// // (e.g., book histograms, etc) // //
	// ////////////////////////////////// //

	TTree *photonTree = new TTree("photonTree","");

	float photonEt;
	float weight;
	photonTree->Branch("photonEt",&photonEt,"photonEt/F");
  	photonTree->Branch("weight",  &weight,"weight/F");


//	used to check dub events, off by default
	vector<int> RUNS;
	vector<int> LUMIS;
	vector<int> EVENTS;

//	float ptBinBorders[14] = {10,20,30,40,60,100,150,200,300,400,500,600,700,800};
//	float ptBinBorders[nB+1] = {10,20,30,40,60,100,150};
//	const int nB = 3;
//	float ptBinBorders[nB+1] = {10,20,40,60};
//	TH1F* _GammaEt = new TH1F("_GammaEt", "", nB, ptBinBorders);
//	TH1F* _GammaEt = new TH1F("_GammaEt", "", 1,10,60);

	int   ptHistoNBINS = 20;
	float ptHistoMin   = 0;
	float ptHistoMax   = 100;

//	TH1F* GammaEt		= new TH1F("GammaEt",		"", ptHistoNBINS,	ptHistoMin,	ptHistoMax);
	TH1F* Leg1Pt		= new TH1F("ZLeg1Pt",		"", ptHistoNBINS,	ptHistoMin,	ptHistoMax);
	TH1F* Leg2Pt		= new TH1F("ZLeg2Pt",		"", ptHistoNBINS,	ptHistoMin,	ptHistoMax);
	TH1F* dRLeg1Gamma	= new TH1F("dRLeg1Gamma",	"", 60,			0,		6);
	TH1F* dRLeg2Gamma	= new TH1F("dRLeg2Gamma",	"", 60,			0,		6);
	TH1F* dRGamma		= new TH1F("dRGamma",		"", 60,			0,		6);
	TH1F* ZMass		= new TH1F("ZMass",		"", 50,			40,		120);
	TH1F* ZMass_noPho	= new TH1F("ZMassnoPho",	"", 50,			40,		120);
	TH1F* ZMass_noPho_PU	= new TH1F("ZMassnoPhoPU",	"", 50,			40,		120);
	TH1F* ZMass_noPho_PU_SF	= new TH1F("ZMassnoPhoPUSF",	"", 50,			40,		120);
	TH1F* ZGpt		= new TH1F("ZGpt",		"", 100,		0,		100);
	TH1F* ZGMass		= new TH1F("ZGMass",		"", 100,		60,		200);
	TH2F* ZM_ZgM		= new TH2F("ZM_ZgM",		"", 100,		0,	120,	100,	0,	250);

	Float_t EtBins[7]={30,35,40,60,90,120,500};
	TH1F* _GammaEt_sig	= new TH1F("_GammaEt_sig",	"", 6,			EtBins);
	TH1F* _GammaEt		= new TH1F("_GammaEt",		"", 100,		0,		300);
	TH1F* _GammaEta		= new TH1F("_GammaEta",		"", 12,			-3,		3);
	TH1F* _GammaPhi		= new TH1F("_GammaPhi",		"", 18,			-3.5,		3.5);
	TH1F* _GammaHoE		= new TH1F("_GammaHoE",		"", 15,			0,		0.15);
	TH1F* _GammaSigIEIE	= new TH1F("_GammaSigIEIE",	"", 35,			0,		0.07);
	TH1F* _GammaEcalIso	= new TH1F("_GammaEcalIso",	"", 20,			0,		5);
	TH1F* _GammaHcalIso	= new TH1F("_GammaHcalIso",	"", 20,			0,		3);
	TH1F* _GammaTrkIso	= new TH1F("_GammaTrkIso",	"", 20,			0,		3);
	TH1F* _Gamma_eIso	= new TH1F("_Gamma_eIso",	"", 50,			-0.5,		7);
	TH1F* _Gamma_hIso	= new TH1F("_Gamma_hIso",	"", 35,			-0.5,		3);
	TH1F* _Gamma_tIso	= new TH1F("_Gamma_tIso",	"", 35,			-0.5,		3);

	TH1I* nPassed		= new TH1I("nPassed",		"", 50,			0,50);

//	nPassed->SetBinContent(1,hEvents->GetBinContent(1));
//	nPassed->SetBinContent(2,hEvents->GetBinContent(2));

//	for efficiency
	TH1F* _photonEt		= new TH1F("_photonEt",		"", 100,		0,		200);
	TH1F* _photonEta	= new TH1F("_photonEta",	"", 12,			-3,		3);
	TH1F* _photonPhi	= new TH1F("_photonPhi",	"", 18,			-3.5,		3.5);
	TH1F* _photonHoE	= new TH1F("_photonHoE",	"", 15,			0,		0.15);
	TH1F* _photonSigIEIE	= new TH1F("_photonSigIEIE",	"", 35,			0,		0.07);
	TH1F* _photonEcalIso	= new TH1F("_photonEcalIso",	"", 20,			0,		5);
	TH1F* _photonHcalIso	= new TH1F("_photonHcalIso",	"", 20,			0,		3);
	TH1F* _photonTrkIso	= new TH1F("_photonTrkIso",	"", 20,			0,		3);
	TH1F* _photon_eIso	= new TH1F("_photon_eIso",	"", 50,			-0.5,		7);
	TH1F* _photon_hIso	= new TH1F("_photon_hIso",	"", 35,			-0.5,		3);
	TH1F* _photon_tIso	= new TH1F("_photon_tIso",	"", 35,			-0.5,		3);

	TH1F* _cleanLepPt	= new TH1F("_cleanLepPt",	"", 20,			0,		100);
	TH1F* _goodLepPt	= new TH1F("_goodLepPt",	"", 20,			0,		100);

//	HISTOGRAMS FOR ANGLES
	TH1F* _cosThetaL	= new TH1F("_cosThetaL",	"cos(#theta_{l})",	40,	-1,		1);
	TH1F* _thetaL		= new TH1F("_thetaL",		"#theta_{l}",		20,	-3.14,		3.14);
	TH1F* _cosThetaL_FSR	= new TH1F("_cosThetaL_FSR",	"cos(#theta_{l})",	20,	-1,		1);

	TH1F* _cosThetaZ	= new TH1F("_cosThetaZ",	"cos(#theta_{Z})",	40,	-1,		1);
	TH1F* _thetaZ		= new TH1F("_thetaZ",		"#theta_{Z}",		20,	-3.14,		3.14);
	TH2F* _cosThetaZ_L	= new TH2F("cosThetaZ_L",	"cos(#theta_{Z}) vs. cos(#theta_{l})",	40, -1, 1, 40, -1, 1);
	TH2F* _cosThetaL_res	= new TH2F("cosThetaL_res",	"cos(#theta_{l}) GEN vs. RECO",		100, -1, 1, 100, -1, 1);
	TH1F* _cosThetaL_res1	= new TH1F("cosThetaL_res1",	"cos(#theta_{l})((RECO-GEN)/GEN)",	100, -5, 5);
	TH2F* _cosThetaZ_res	= new TH2F("cosThetaZ_res",	"cos(#theta_{Z}) GEN vs. RECO",		100, -1, 1, 100, -1, 1);
	TH1F* _cosThetaZ_res1	= new TH1F("cosThetaZ_res1",	"cos(#theta_{Z})((RECO-GEN)/GEN)",	100, -5, 5);

	TH2F* _phiL_res		= new TH2F("phiL_res",	"#phi_{l}) GEN vs. RECO", 100, -3.14, 3.14, 100, -3.14, 3.14);
	TH1F* _phiL_res1	= new TH1F("phiL_res1",	"#phi_{l})((RECO-GEN)/GEN)", 100, -5, 5);
	TH2F* _phiZ_res		= new TH2F("phiZ_res",	"#phi_{Z}) GEN vs. RECO", 100, -3.14, 3.14, 100, -3.14, 3.14);
	TH1F* _phiZ_res1	= new TH1F("phi_res1",	"#phi_{Z})((RECO-GEN)/GEN)", 100, -5, 5);
	TH1F* _phiL		= new TH1F("_phiL",		"#phi_{l}",		20,	-3.14,		3.14);
	TH1F* _phiZ		= new TH1F("_phiZ",		"#phi_{Z}",		20,	-3.14,		3.14);

//	HISTOGRAMS FOR GEN PARTICLES
	TH1F* MC_cosThetaL	= new TH1F("MC_cosThetaL",	"cos(#theta_{l})",	40,	-1,		1);
	TH1F* MC_thetaL		= new TH1F("MC_thetaL",		"#theta_{l}",		20,	-3.14,		3.14);
	TH1F* MCCut_cosThetaL	= new TH1F("MCCut_cosThetaL",	"cos(#theta_{l})",	40,	-1,		1);
	TH1F* MC_cosThetaL_FSR	= new TH1F("MC_cosThetaL_FSR",	"cos(#theta_{l})",	20,	-1,		1);

	TH1F* MC_cosThetaZ	= new TH1F("MC_cosThetaZ",	"cos(#theta_{Z})",	40,	-1,		1);
	TH1F* MC_thetaZ		= new TH1F("MC_thetaZ",		"#theta_{Z}",		20,	-3.14,		3.14);
	TH1F* MCCut_cosThetaZ	= new TH1F("MCCut_cosThetaZ",	"cos(#theta_{Z})",	40,	-1,		1);
	TH2F* MC_cosThetaZ_L	= new TH2F("MC_cosThetaZ_L",	"cos(#theta_{Z}) vs. cos(#theta_{l})", 40, -1, 1, 40, -1, 1);
	TH2F* MCCut_cosThetaZ_L	= new TH2F("MCCut_cosThetaZ_L",	"cos(#theta_{Z}) vs. cos(#theta_{l})", 20, -1, 1, 20, -1, 1);

	TH1F* failed_cosThetaZ	= new TH1F("failed_cosThetaZ",	"cos(#theta_{Z})",	40,	-1,		1);

	TH1F* MCCut_phiL	= new TH1F("MCCut_phiL",	"#phi_{l})",		20,	-3.14,		3.14);
	TH1F* MCCut_phiZ	= new TH1F("MCCut_phiZ",	"#phi_{Z})",		20,	-3.14,		3.14);

	TH1F* MC_goodPhoEta	= new TH1F("MC_goodPhoEta",	"", 20,		-4,		4);

	TH1F* MC_phiL		= new TH1F("MC_phiL",		"", 20,			-3.14,		3.14);
	TH1F* MC_phiZ		= new TH1F("MC_phiZ",		"", 20,			-3.14,		3.14);

//	GOOD PARTICLE KINEMATICS
//	TH1F* _goodLepEta	= new TH1F("_goodLepEta",	"", 100,		-4,		4);
	TH1F* _goodPhoEta	= new TH1F("_goodPhoEta",	"", 100,		-4,		4);

	TH2F * cosThetaZ_phoEta = new TH2F("cosThetaZ_phoEta",	"", 20,		-1,	1,	10,	-1,	1);

//	GENERATED PHOTON AND LEPTON ET AND PT
	TH1F* _genPhoEt		= new TH1F("genPhoEt",		"genPhoEt", 100,	0,		500);
	TH1F* _genLepPt		= new TH1F("genLepPt",		"genLepPt", 100,	0,		500);


//	DEFINE SOME CUTS AND VARIABLES USED IN CALCULATIONS, making similar structure to taiwan script
	float dRcut = 0.7; 
	float phoEtCut = 30;
	float lepPtCut = 20;

	map<int,string> nPassedMap;

	TLorentzVector lep1, lep2, gamma, ll, llg;
	TLorentzVector mclep1, mclep2, mcGamma, mcll, mcllg;

	bool doEEG = false;
	bool doMMG = false;

	if (electronID >= 0) doEEG = true;
	if (muonID >= 0) doMMG = true;
	if (doEEG && doMMG)
		{
		cout << "SPECIFY EITHER MU OR ELE\nEXITING" << endl;
		return 0;
		}

// //////////////// //
// // leafs, branches, addresses
// //////////////// //
	int	run;
	unsigned long int	event;
	int	orbit;
	int	bx;
	int	lumis;
	int	isData;
	int	ttbit0;
	int	nHLT;
	int	HLT[395];
	int	HLTIndex[125];
	int	HLTprescale[395];
	int	nHFTowersP;
	int	nHFTowersN;
	int	nVtx;
	float	vtx[42][3];
	int	vtxNTrk[42];
	float	vtxNDF[42];
	float	vtxD0[42];
	int	nGoodVtx;
	int	IsVtxGood;
	int	nTrk;
	int	nGoodTrk;
	int	IsTracksGood;
	float	rho;
	float	sigma;
	float	rhoNeutral;
	float	pdf[7];
	float	pthat;
	float	processID;
	int	nBX;
	int	nPU[3];
	int	BXPU[3];
	int	nMC;
	int	mcPID[38];
	float	mcVtx[38][3];
	float	mcPt[38];
	float	mcMass[38];
	float	mcEta[38];
	float	mcPhi[38];
	int	mcGMomPID[38];
	int	mcMomPID[38];
	float	mcMomPt[38];
	float	mcMomMass[38];
	float	mcMomEta[38];
	float	mcMomPhi[38];
	int	mcIndex[38];
	int	mcDecayType[38];
	float	mcIsoDR03[38];
	float	mcCalIsoDR03[38];
	float	mcTrkIsoDR03[38];
	float	mcIsoDR04[38];
	float	mcCalIsoDR04[38];
	float	mcTrkIsoDR04[38];
	float	genMET;
	float	genMETx;
	float	genMETy;
	float	genMETPhi;
	float	MET;
	float	METx;
	float	METy;
	float	METPhi;
	float	METsumEt;
	float	uncorrMET[3];
	float	uncorrMETPhi[3];
	float	uncorrMETSumEt[3];
	float	tcMET;
	float	tcMETx;
	float	tcMETy;
	float	tcMETPhi;
	float	tcMETsumEt;
	float	tcMETmEtSig;
	float	tcMETSig;
	float	pfMET;
	float	pfMETx;
	float	pfMETy;
	float	pfMETPhi;
	float	pfMETsumEt;
	float	pfMETmEtSig;
	float	pfMETSig;
	float	TypeIpfMET;
	float	TypeIpfMETx;
	float	TypeIpfMETy;
	float	TypeIpfMETPhi;
	float	TypeIpfMETsumEt;
	float	TypeIpfMETmEtSig;
	float	TypeIpfMETSig;
	float	TypeIpIIpfMET;
	float	TypeIpIIpfMETx;
	float	TypeIpIIpfMETy;
	float	TypeIpIIpfMETPhi;
	float	TypeIpIIpfMETsumEt;
	float	TypeIpIIpfMETmEtSig;
	float	TypeIpIIpfMETSig;
	float	SmearedpfMET;
	float	SmearedpfMETx;
	float	SmearedpfMETy;
	float	SmearedpfMETPhi;
	float	SmearedpfMETsumEt;
	float	SmearedpfMETmEtSig;
	float	SmearedpfMETSig;
	float	SmearedTypeIpfMET;
	float	SmearedTypeIpfMETx;
	float	SmearedTypeIpfMETy;
	float	SmearedTypeIpfMETPhi;
	float	SmearedTypeIpfMETsumEt;
	float	SmearedTypeIpfMETmEtSig;
	float	SmearedTypeIpfMETSig;
	int	npfCharged;
	float	pfChargedSumPt;
	int	npfChargedHadron;
	float	pfChargedHadronSumPt;
	int	npfLepton;
	float	pfLeptonSumPt;
	int	npfNeutral;
	float	pfNeutralSumPt;
	int	npfNeutralHadron;
	float	pfNeutralHadronSumPt;
	int	npfPhoton;
	float	pfPhotonSumPt;
	int	nEle;
	int	eleTrg[6][31];
	int	eleID[6][30];
	float	eleIDLH[6];
	int	eleClass[6];
	int	eleCharge[6];
	float	eleEn[6];
	float	eleSCRawEn[6];
	float	eleESEn[6];
	float	eleSCEn[6];
	float	elePt[6];
	float	elePz[6];
	float	eleEta[6];
	float	elePhi[6];
	float	eleSCEta[6];
	float	eleSCPhi[6];
	float	eleSCEtaWidth[6];
	float	eleSCPhiWidth[6];
	float	eleVtx[6][3];
	float	eleCaloPos[6][3];
	float	eleSCPos[6][3];
	float	eleHoverE[6];
	float	eleEoverP[6];
	float	elePin[6];
	float	elePout[6];
	float	eleBrem[6];
	int	elenBrem[6];
	float	eledEtaAtVtx[6];
	float	eledPhiAtVtx[6];
	float	eleSigmaEtaEta[6];
	float	eleSigmaIEtaIEta[6];
	float	eleSigmaIEtaIPhi[6];
	float	eleSigmaIPhiIPhi[6];
	float	eleE3x3[6];
	float	eleSeedTime[6];
	float	eleSeedEnergy[6];
	int	eleRecoFlag[6];
	int	eleSeverity[6];
	int	eleGenIndex[6];
	int	eleGenGMomPID[6];
	int	eleGenMomPID[6];
	float	eleGenMomPt[6];
	float	eleIsoTrkDR03[6];
	float	eleIsoEcalDR03[6];
	float	eleIsoHcalDR03[6];
	float	eleIsoHcalSolidDR03[6];
	float	eleIsoTrkDR04[6];
	float	eleIsoEcalDR04[6];
	float	eleIsoHcalDR04[6];
	float	eleIsoHcalSolidDR04[6];
	float	eleConvDist[6];
	float	eleConvDcot[6];
	float	eleConvRadius[6];
	int	eleConvFlag[6];
	int	eleConvMissinghit[6];
	float	eleESRatio[6];
	float	eleESProfileFront[6][123];
	float	eleESProfileRear[6][123];
	float	elePV2D[6];
	float	elePV3D[6];
	float	eleBS2D[6];
	float	eleBS3D[6];
	float	elePVD0[6];
	float	elePVDz[6];
	int	nPho;
	int	phoTrg[7][14];
	int	phoIsPhoton[7];
	float	phoE[7];
	float	phoEt[7];
	float	phoPz[7];
	float	phoEta[7];
	float	phoPhi[7];
	float	phoR9[7];
	float	phoTrkIsoSolidDR03[7];
	float	phoTrkIsoHollowDR03[7];
	int	phoNTrkSolidDR03[7];
	int	phoNTrkHollowDR03[7];
	float	phoEcalIsoDR03[7];
	float	phoHcalIsoDR03[7];
	float	phoHcalIsoSolidDR03[7];
	float	phoTrkIsoSolidDR04[7];
	float	phoTrkIsoHollowDR04[7];
	int	phoNTrkSolidDR04[7];
	int	phoNTrkHollowDR04[7];
	float	phoEcalIsoDR04[7];
	float	phoHcalIsoDR04[7];
	float	phoHcalIsoSolidDR04[7];
	float	phoEtVtx[7][150];
	float	phoEtaVtx[7][150];
	float	phoPhiVtx[7][150];
	float	phoTrkIsoSolidDR03Vtx[7][150];
	float	phoTrkIsoHollowDR03Vtx[7][150];
	float	phoTrkIsoSolidDR04Vtx[7][150];
	float	phoTrkIsoHollowDR04Vtx[7][150];
	float	phoHoverE[7];
	float	phoSigmaEtaEta[7];
	float	phoSigmaIEtaIEta[7];
	float	phoSigmaIEtaIPhi[7];
	float	phoSigmaIPhiIPhi[7];
	float	phoE3x3[7];
	float	phoE5x5[7];
	float	phoSeedTime[7];
	float	phoSeedEnergy[7];
	int	phoRecoFlag[7];
	int	phoSeverity[7];
	int	phoPos[7];
	int	phoGenIndex[7];
	int	phoGenGMomPID[7];
	int	phoGenMomPID[7];
	float	phoGenMomPt[7];
	float	phoSCE[7];
	float	phoESE[7];
	float	phoSCEt[7];
	float	phoSCEta[7];
	float	phoSCPhi[7];
	float	phoSCEtaWidth[7];
	float	phoSCPhiWidth[7];
	float	phoVtx[7][3];
	float	phoVtxD0[7];
	int	phoOverlap[7];
	int	phohasPixelSeed[7];
	int	phoIsConv[7];
	float	phoESRatio[7];
	float	phoESProfileFront[7][123];
	float	phoESProfileRear[7][123];
	int	phoNTracks[7];
	float	phoConvPairInvariantMass[7];
	float	phoConvPairCotThetaSeparation[7];
	float	phoConvPairMomentumEta[7];
	float	phoConvPairMomentumPhi[7];
	float	phoConvPairMomentumX[7];
	float	phoConvPairMomentumY[7];
	float	phoConvPairMomentumZ[7];
	float	phoConvDistOfMinimumApproach[7];
	float	phoConvDPhiTracksAtVtx[7];
	float	phoConvDPhiTracksAtEcal[7];
	float	phoConvDEtaTracksAtEcal[7];
	float	phoConvVtxValid[7];
	float	phoConvVtxEta[7];
	float	phoConvVtxPhi[7];
	float	phoConvVtxR[7];
	float	phoConvVtxX[7];
	float	phoConvVtxY[7];
	float	phoConvVtxZ[7];
	float	phoConvVtxChi2[7];
	float	phoConvVtxNdof[7];
	float	phoConvChi2Prob[7];
	float	phoConvEoverP[7];
	int	phoNxtal[7];
	float	phoXtalTime[7][200];
	float	phoXtalEnergy[7][200];
	int	phoXtalZ[7][200];
	int	phoXtalX[7][200];
	int	phoXtalY[7][200];
	int	phoXtalEta[7][200];
	int	phoXtalPhi[7][200];
	float	pho5x5Time[7][25];
	float	pho5x5Energy[7][25];
	int	pho5x5Z[7][25];
	int	pho5x5X[7][25];
	int	pho5x5Y[7][25];
	int	pho5x5Eta[7][25];
	int	pho5x5Phi[7][25];
	int	nMu;
	int	muTrg[20][16];
	float	muEta[20];
	float	muPhi[20];
	int	muCharge[20];
	float	muPt[20];
	float	muPz[20];
	int	muGenIndex[20];
	int	muGenGMomPID[20];
	int	muGenMomPID[20];
	float	muGenMomPt[20];
	float	muIsoTrk[20];
	float	muIsoCalo[20];
	float	muIsoEcal[20];
	float	muIsoHcal[20];
	float	muChi2NDF[20];
	float	muEmVeto[20];
	float	muHadVeto[20];
	int	muType[20];
	int	muID[20][6];
	float	muD0[20];
	float	muDz[20];
	float	muPVD0[20];
	float	muPVDz[20];
	float	muValidFraction[20];
	float	muTrkdPt[20];
	int	muNumberOfHits[20];
	int	muNumberOfValidHits[20];
	int	muNumberOfInactiveHits[20];
	int	muNumberOfValidTrkHits[20];
	int	muNumberOfValidPixelHits[20];
	int	muNumberOfValidMuonHits[20];
	int	muStations[20];
	int	muChambers[20];
	float	muPV2D[20];
	float	muPV3D[20];
	float	muBS2D[20];
	float	muBS3D[20];
	float	muVtx[20][3];
	int	nJet;
	int	jetTrg[27][23];
	float	jetEn[27];
	float	jetPt[27];
	float	jetEta[27];
	float	jetPhi[27];
	float	jetMass[27];
	float	jetEt[27];
	int	jetpartonFlavour[27];
	float	jetRawPt[27];
	float	jetRawEn[27];
	float	jetCharge[27];
	float	jetNeutralEmEnergy[27];
	float	jetNeutralEmEnergyFraction[27];
	float	jetNeutralHadronEnergy[27];
	float	jetNeutralHadronEnergyFraction[27];
	int	jetNConstituents[27];
	float	jetChargedEmEnergy[27];
	float	jetChargedEmEnergyFraction[27];
	float	jetChargedHadronEnergy[27];
	float	jetChargedHadronEnergyFraction[27];
	int	jetChargedHadronMultiplicity[27];
	float	jetChargedMuEnergy[27];
	float	jetChargedMuEnergyFraction[27];
	Double_t	jetJVAlpha[27];
	Double_t	jetJVBeta[27];
	int	jetGenJetIndex[27];
	float	jetGenJetEn[27];
	float	jetGenJetPt[27];
	float	jetGenJetEta[27];
	float	jetGenJetPhi[27];
	float	jetGenJetMass[27];
	int	jetGenPartonID[27];
	int	jetGenPartonMomID[27];
	int	nZee;
	float	ZeeMass[15];
	float	ZeePt[15];
	float	ZeeEta[15];
	float	ZeePhi[15];
	int	ZeeLeg1Index[15];
	int	ZeeLeg2Index[15];
	int	nZmumu;
	float	ZmumuMass[2];
	float	ZmumuPt[2];
	float	ZmumuEta[2];
	float	ZmumuPhi[2];
	int	ZmumuLeg1Index[2];
	int	ZmumuLeg2Index[2];
	int	nWenu;
	float	WenuMassTCaloMET[6];
	float	WenuEtCaloMET[6];
	float	WenuACopCaloMET[6];
	float	WenuMassTTcMET[6];
	float	WenuEtTcMET[6];
	float	WenuACopTcMET[6];
	float	WenuMassTPfMET[6];
	float	WenuEtPfMET[6];
	float	WenuACopPfMET[6];
	int	WenuEleIndex[6];
	int	nWmunu;
	float	WmunuMassTCaloMET[3];
	float	WmunuEtCaloMET[3];
	float	WmunuACopCaloMET[3];
	float	WmunuMassTTcMET[3];
	float	WmunuEtTcMET[3];
	float	WmunuACopTcMET[3];
	float	WmunuMassTPfMET[3];
	float	WmunuEtPfMET[3];
	float	WmunuACopPfMET[3];
	int	WmunuMuIndex[3];
	TBranch* b_run;
	TBranch* b_event;
	TBranch* b_orbit;
	TBranch* b_bx;
	TBranch* b_lumis;
	TBranch* b_isData;
	TBranch* b_ttbit0;
	TBranch* b_nHLT;
	TBranch* b_HLT;
	TBranch* b_HLTIndex;
	TBranch* b_HLTprescale;
	TBranch* b_nHFTowersP;
	TBranch* b_nHFTowersN;
	TBranch* b_nVtx;
	TBranch* b_vtx;
	TBranch* b_vtxNTrk;
	TBranch* b_vtxNDF;
	TBranch* b_vtxD0;
	TBranch* b_nGoodVtx;
	TBranch* b_IsVtxGood;
	TBranch* b_nTrk;
	TBranch* b_nGoodTrk;
	TBranch* b_IsTracksGood;
	TBranch* b_rho;
	TBranch* b_sigma;
	TBranch* b_rhoNeutral;
	TBranch* b_pdf;
	TBranch* b_pthat;
	TBranch* b_processID;
	TBranch* b_nBX;
	TBranch* b_nPU;
	TBranch* b_BXPU;
	TBranch* b_nMC;
	TBranch* b_mcPID;
	TBranch* b_mcVtx;
	TBranch* b_mcPt;
	TBranch* b_mcMass;
	TBranch* b_mcEta;
	TBranch* b_mcPhi;
	TBranch* b_mcGMomPID;
	TBranch* b_mcMomPID;
	TBranch* b_mcMomPt;
	TBranch* b_mcMomMass;
	TBranch* b_mcMomEta;
	TBranch* b_mcMomPhi;
	TBranch* b_mcIndex;
	TBranch* b_mcDecayType;
	TBranch* b_mcIsoDR03;
	TBranch* b_mcCalIsoDR03;
	TBranch* b_mcTrkIsoDR03;
	TBranch* b_mcIsoDR04;
	TBranch* b_mcCalIsoDR04;
	TBranch* b_mcTrkIsoDR04;
	TBranch* b_genMET;
	TBranch* b_genMETx;
	TBranch* b_genMETy;
	TBranch* b_genMETPhi;
	TBranch* b_MET;
	TBranch* b_METx;
	TBranch* b_METy;
	TBranch* b_METPhi;
	TBranch* b_METsumEt;
	TBranch* b_uncorrMET;
	TBranch* b_uncorrMETPhi;
	TBranch* b_uncorrMETSumEt;
	TBranch* b_tcMET;
	TBranch* b_tcMETx;
	TBranch* b_tcMETy;
	TBranch* b_tcMETPhi;
	TBranch* b_tcMETsumEt;
	TBranch* b_tcMETmEtSig;
	TBranch* b_tcMETSig;
	TBranch* b_pfMET;
	TBranch* b_pfMETx;
	TBranch* b_pfMETy;
	TBranch* b_pfMETPhi;
	TBranch* b_pfMETsumEt;
	TBranch* b_pfMETmEtSig;
	TBranch* b_pfMETSig;
	TBranch* b_TypeIpfMET;
	TBranch* b_TypeIpfMETx;
	TBranch* b_TypeIpfMETy;
	TBranch* b_TypeIpfMETPhi;
	TBranch* b_TypeIpfMETsumEt;
	TBranch* b_TypeIpfMETmEtSig;
	TBranch* b_TypeIpfMETSig;
	TBranch* b_TypeIpIIpfMET;
	TBranch* b_TypeIpIIpfMETx;
	TBranch* b_TypeIpIIpfMETy;
	TBranch* b_TypeIpIIpfMETPhi;
	TBranch* b_TypeIpIIpfMETsumEt;
	TBranch* b_TypeIpIIpfMETmEtSig;
	TBranch* b_TypeIpIIpfMETSig;
	TBranch* b_SmearedpfMET;
	TBranch* b_SmearedpfMETx;
	TBranch* b_SmearedpfMETy;
	TBranch* b_SmearedpfMETPhi;
	TBranch* b_SmearedpfMETsumEt;
	TBranch* b_SmearedpfMETmEtSig;
	TBranch* b_SmearedpfMETSig;
	TBranch* b_SmearedTypeIpfMET;
	TBranch* b_SmearedTypeIpfMETx;
	TBranch* b_SmearedTypeIpfMETy;
	TBranch* b_SmearedTypeIpfMETPhi;
	TBranch* b_SmearedTypeIpfMETsumEt;
	TBranch* b_SmearedTypeIpfMETmEtSig;
	TBranch* b_SmearedTypeIpfMETSig;
	TBranch* b_npfCharged;
	TBranch* b_pfChargedSumPt;
	TBranch* b_npfChargedHadron;
	TBranch* b_pfChargedHadronSumPt;
	TBranch* b_npfLepton;
	TBranch* b_pfLeptonSumPt;
	TBranch* b_npfNeutral;
	TBranch* b_pfNeutralSumPt;
	TBranch* b_npfNeutralHadron;
	TBranch* b_pfNeutralHadronSumPt;
	TBranch* b_npfPhoton;
	TBranch* b_pfPhotonSumPt;
	TBranch* b_nEle;
	TBranch* b_eleTrg;
	TBranch* b_eleID;
	TBranch* b_eleIDLH;
	TBranch* b_eleClass;
	TBranch* b_eleCharge;
	TBranch* b_eleEn;
	TBranch* b_eleSCRawEn;
	TBranch* b_eleESEn;
	TBranch* b_eleSCEn;
	TBranch* b_elePt;
	TBranch* b_elePz;
	TBranch* b_eleEta;
	TBranch* b_elePhi;
	TBranch* b_eleSCEta;
	TBranch* b_eleSCPhi;
	TBranch* b_eleSCEtaWidth;
	TBranch* b_eleSCPhiWidth;
	TBranch* b_eleVtx;
	TBranch* b_eleCaloPos;
	TBranch* b_eleSCPos;
	TBranch* b_eleHoverE;
	TBranch* b_eleEoverP;
	TBranch* b_elePin;
	TBranch* b_elePout;
	TBranch* b_eleBrem;
	TBranch* b_elenBrem;
	TBranch* b_eledEtaAtVtx;
	TBranch* b_eledPhiAtVtx;
	TBranch* b_eleSigmaEtaEta;
	TBranch* b_eleSigmaIEtaIEta;
	TBranch* b_eleSigmaIEtaIPhi;
	TBranch* b_eleSigmaIPhiIPhi;
	TBranch* b_eleE3x3;
	TBranch* b_eleSeedTime;
	TBranch* b_eleSeedEnergy;
	TBranch* b_eleRecoFlag;
	TBranch* b_eleSeverity;
	TBranch* b_eleGenIndex;
	TBranch* b_eleGenGMomPID;
	TBranch* b_eleGenMomPID;
	TBranch* b_eleGenMomPt;
	TBranch* b_eleIsoTrkDR03;
	TBranch* b_eleIsoEcalDR03;
	TBranch* b_eleIsoHcalDR03;
	TBranch* b_eleIsoHcalSolidDR03;
	TBranch* b_eleIsoTrkDR04;
	TBranch* b_eleIsoEcalDR04;
	TBranch* b_eleIsoHcalDR04;
	TBranch* b_eleIsoHcalSolidDR04;
	TBranch* b_eleConvDist;
	TBranch* b_eleConvDcot;
	TBranch* b_eleConvRadius;
	TBranch* b_eleConvFlag;
	TBranch* b_eleConvMissinghit;
	TBranch* b_eleESRatio;
	TBranch* b_eleESProfileFront;
	TBranch* b_eleESProfileRear;
	TBranch* b_elePV2D;
	TBranch* b_elePV3D;
	TBranch* b_eleBS2D;
	TBranch* b_eleBS3D;
	TBranch* b_elePVD0;
	TBranch* b_elePVDz;
	TBranch* b_nPho;
	TBranch* b_phoTrg;
	TBranch* b_phoIsPhoton;
	TBranch* b_phoE;
	TBranch* b_phoEt;
	TBranch* b_phoPz;
	TBranch* b_phoEta;
	TBranch* b_phoPhi;
	TBranch* b_phoR9;
	TBranch* b_phoTrkIsoSolidDR03;
	TBranch* b_phoTrkIsoHollowDR03;
	TBranch* b_phoNTrkSolidDR03;
	TBranch* b_phoNTrkHollowDR03;
	TBranch* b_phoEcalIsoDR03;
	TBranch* b_phoHcalIsoDR03;
	TBranch* b_phoHcalIsoSolidDR03;
	TBranch* b_phoTrkIsoSolidDR04;
	TBranch* b_phoTrkIsoHollowDR04;
	TBranch* b_phoNTrkSolidDR04;
	TBranch* b_phoNTrkHollowDR04;
	TBranch* b_phoEcalIsoDR04;
	TBranch* b_phoHcalIsoDR04;
	TBranch* b_phoHcalIsoSolidDR04;
	TBranch* b_phoEtVtx;
	TBranch* b_phoEtaVtx;
	TBranch* b_phoPhiVtx;
	TBranch* b_phoTrkIsoSolidDR03Vtx;
	TBranch* b_phoTrkIsoHollowDR03Vtx;
	TBranch* b_phoTrkIsoSolidDR04Vtx;
	TBranch* b_phoTrkIsoHollowDR04Vtx;
	TBranch* b_phoHoverE;
	TBranch* b_phoSigmaEtaEta;
	TBranch* b_phoSigmaIEtaIEta;
	TBranch* b_phoSigmaIEtaIPhi;
	TBranch* b_phoSigmaIPhiIPhi;
	TBranch* b_phoE3x3;
	TBranch* b_phoE5x5;
	TBranch* b_phoSeedTime;
	TBranch* b_phoSeedEnergy;
	TBranch* b_phoRecoFlag;
	TBranch* b_phoSeverity;
	TBranch* b_phoPos;
	TBranch* b_phoGenIndex;
	TBranch* b_phoGenGMomPID;
	TBranch* b_phoGenMomPID;
	TBranch* b_phoGenMomPt;
	TBranch* b_phoSCE;
	TBranch* b_phoESE;
	TBranch* b_phoSCEt;
	TBranch* b_phoSCEta;
	TBranch* b_phoSCPhi;
	TBranch* b_phoSCEtaWidth;
	TBranch* b_phoSCPhiWidth;
	TBranch* b_phoVtx;
	TBranch* b_phoVtxD0;
	TBranch* b_phoOverlap;
	TBranch* b_phohasPixelSeed;
	TBranch* b_phoIsConv;
	TBranch* b_phoESRatio;
	TBranch* b_phoESProfileFront;
	TBranch* b_phoESProfileRear;
	TBranch* b_phoNTracks;
	TBranch* b_phoConvPairInvariantMass;
	TBranch* b_phoConvPairCotThetaSeparation;
	TBranch* b_phoConvPairMomentumEta;
	TBranch* b_phoConvPairMomentumPhi;
	TBranch* b_phoConvPairMomentumX;
	TBranch* b_phoConvPairMomentumY;
	TBranch* b_phoConvPairMomentumZ;
	TBranch* b_phoConvDistOfMinimumApproach;
	TBranch* b_phoConvDPhiTracksAtVtx;
	TBranch* b_phoConvDPhiTracksAtEcal;
	TBranch* b_phoConvDEtaTracksAtEcal;
	TBranch* b_phoConvVtxValid;
	TBranch* b_phoConvVtxEta;
	TBranch* b_phoConvVtxPhi;
	TBranch* b_phoConvVtxR;
	TBranch* b_phoConvVtxX;
	TBranch* b_phoConvVtxY;
	TBranch* b_phoConvVtxZ;
	TBranch* b_phoConvVtxChi2;
	TBranch* b_phoConvVtxNdof;
	TBranch* b_phoConvChi2Prob;
	TBranch* b_phoConvEoverP;
	TBranch* b_phoNxtal;
	TBranch* b_phoXtalTime;
	TBranch* b_phoXtalEnergy;
	TBranch* b_phoXtalZ;
	TBranch* b_phoXtalX;
	TBranch* b_phoXtalY;
	TBranch* b_phoXtalEta;
	TBranch* b_phoXtalPhi;
	TBranch* b_pho5x5Time;
	TBranch* b_pho5x5Energy;
	TBranch* b_pho5x5Z;
	TBranch* b_pho5x5X;
	TBranch* b_pho5x5Y;
	TBranch* b_pho5x5Eta;
	TBranch* b_pho5x5Phi;
	TBranch* b_nMu;
	TBranch* b_muTrg;
	TBranch* b_muEta;
	TBranch* b_muPhi;
	TBranch* b_muCharge;
	TBranch* b_muPt;
	TBranch* b_muPz;
	TBranch* b_muGenIndex;
	TBranch* b_muGenGMomPID;
	TBranch* b_muGenMomPID;
	TBranch* b_muGenMomPt;
	TBranch* b_muIsoTrk;
	TBranch* b_muIsoCalo;
	TBranch* b_muIsoEcal;
	TBranch* b_muIsoHcal;
	TBranch* b_muChi2NDF;
	TBranch* b_muEmVeto;
	TBranch* b_muHadVeto;
	TBranch* b_muType;
	TBranch* b_muID;
	TBranch* b_muD0;
	TBranch* b_muDz;
	TBranch* b_muPVD0;
	TBranch* b_muPVDz;
	TBranch* b_muValidFraction;
	TBranch* b_muTrkdPt;
	TBranch* b_muNumberOfHits;
	TBranch* b_muNumberOfValidHits;
	TBranch* b_muNumberOfInactiveHits;
	TBranch* b_muNumberOfValidTrkHits;
	TBranch* b_muNumberOfValidPixelHits;
	TBranch* b_muNumberOfValidMuonHits;
	TBranch* b_muStations;
	TBranch* b_muChambers;
	TBranch* b_muPV2D;
	TBranch* b_muPV3D;
	TBranch* b_muBS2D;
	TBranch* b_muBS3D;
	TBranch* b_muVtx;
	TBranch* b_nJet;
	TBranch* b_jetTrg;
	TBranch* b_jetEn;
	TBranch* b_jetPt;
	TBranch* b_jetEta;
	TBranch* b_jetPhi;
	TBranch* b_jetMass;
	TBranch* b_jetEt;
	TBranch* b_jetpartonFlavour;
	TBranch* b_jetRawPt;
	TBranch* b_jetRawEn;
	TBranch* b_jetCharge;
	TBranch* b_jetNeutralEmEnergy;
	TBranch* b_jetNeutralEmEnergyFraction;
	TBranch* b_jetNeutralHadronEnergy;
	TBranch* b_jetNeutralHadronEnergyFraction;
	TBranch* b_jetNConstituents;
	TBranch* b_jetChargedEmEnergy;
	TBranch* b_jetChargedEmEnergyFraction;
	TBranch* b_jetChargedHadronEnergy;
	TBranch* b_jetChargedHadronEnergyFraction;
	TBranch* b_jetChargedHadronMultiplicity;
	TBranch* b_jetChargedMuEnergy;
	TBranch* b_jetChargedMuEnergyFraction;
	TBranch* b_jetJVAlpha;
	TBranch* b_jetJVBeta;
	TBranch* b_jetGenJetIndex;
	TBranch* b_jetGenJetEn;
	TBranch* b_jetGenJetPt;
	TBranch* b_jetGenJetEta;
	TBranch* b_jetGenJetPhi;
	TBranch* b_jetGenJetMass;
	TBranch* b_jetGenPartonID;
	TBranch* b_jetGenPartonMomID;
	TBranch* b_nZee;
	TBranch* b_ZeeMass;
	TBranch* b_ZeePt;
	TBranch* b_ZeeEta;
	TBranch* b_ZeePhi;
	TBranch* b_ZeeLeg1Index;
	TBranch* b_ZeeLeg2Index;
	TBranch* b_nZmumu;
	TBranch* b_ZmumuMass;
	TBranch* b_ZmumuPt;
	TBranch* b_ZmumuEta;
	TBranch* b_ZmumuPhi;
	TBranch* b_ZmumuLeg1Index;
	TBranch* b_ZmumuLeg2Index;
	TBranch* b_nWenu;
	TBranch* b_WenuMassTCaloMET;
	TBranch* b_WenuEtCaloMET;
	TBranch* b_WenuACopCaloMET;
	TBranch* b_WenuMassTTcMET;
	TBranch* b_WenuEtTcMET;
	TBranch* b_WenuACopTcMET;
	TBranch* b_WenuMassTPfMET;
	TBranch* b_WenuEtPfMET;
	TBranch* b_WenuACopPfMET;
	TBranch* b_WenuEleIndex;
	TBranch* b_nWmunu;
	TBranch* b_WmunuMassTCaloMET;
	TBranch* b_WmunuEtCaloMET;
	TBranch* b_WmunuACopCaloMET;
	TBranch* b_WmunuMassTTcMET;
	TBranch* b_WmunuEtTcMET;
	TBranch* b_WmunuACopTcMET;
	TBranch* b_WmunuMassTPfMET;
	TBranch* b_WmunuEtPfMET;
	TBranch* b_WmunuACopPfMET;
	TBranch* b_WmunuMuIndex;
	b_run = tr->GetBranch("run");
	b_event = tr->GetBranch("event");
	b_orbit = tr->GetBranch("orbit");
	b_bx = tr->GetBranch("bx");
	b_lumis = tr->GetBranch("lumis");
	b_isData = tr->GetBranch("isData");
	b_ttbit0 = tr->GetBranch("ttbit0");
	b_nHLT = tr->GetBranch("nHLT");
	b_HLT = tr->GetBranch("HLT");
	b_HLTIndex = tr->GetBranch("HLTIndex");
	b_HLTprescale = tr->GetBranch("HLTprescale");
	b_nHFTowersP = tr->GetBranch("nHFTowersP");
	b_nHFTowersN = tr->GetBranch("nHFTowersN");
	b_nVtx = tr->GetBranch("nVtx");
	b_vtx = tr->GetBranch("vtx");
	b_vtxNTrk = tr->GetBranch("vtxNTrk");
	b_vtxNDF = tr->GetBranch("vtxNDF");
	b_vtxD0 = tr->GetBranch("vtxD0");
	b_nGoodVtx = tr->GetBranch("nGoodVtx");
	b_IsVtxGood = tr->GetBranch("IsVtxGood");
	b_nTrk = tr->GetBranch("nTrk");
	b_nGoodTrk = tr->GetBranch("nGoodTrk");
	b_IsTracksGood = tr->GetBranch("IsTracksGood");
	b_rho = tr->GetBranch("rho");
	b_sigma = tr->GetBranch("sigma");
	b_rhoNeutral = tr->GetBranch("rhoNeutral");
	b_pdf = tr->GetBranch("pdf");
	b_pthat = tr->GetBranch("pthat");
	b_processID = tr->GetBranch("processID");
	b_nBX = tr->GetBranch("nBX");
	b_nPU = tr->GetBranch("nPU");
	b_BXPU = tr->GetBranch("BXPU");
	b_nMC = tr->GetBranch("nMC");
	b_mcPID = tr->GetBranch("mcPID");
	b_mcVtx = tr->GetBranch("mcVtx");
	b_mcPt = tr->GetBranch("mcPt");
	b_mcMass = tr->GetBranch("mcMass");
	b_mcEta = tr->GetBranch("mcEta");
	b_mcPhi = tr->GetBranch("mcPhi");
	b_mcGMomPID = tr->GetBranch("mcGMomPID");
	b_mcMomPID = tr->GetBranch("mcMomPID");
	b_mcMomPt = tr->GetBranch("mcMomPt");
	b_mcMomMass = tr->GetBranch("mcMomMass");
	b_mcMomEta = tr->GetBranch("mcMomEta");
	b_mcMomPhi = tr->GetBranch("mcMomPhi");
	b_mcIndex = tr->GetBranch("mcIndex");
	b_mcDecayType = tr->GetBranch("mcDecayType");
	b_mcIsoDR03 = tr->GetBranch("mcIsoDR03");
	b_mcCalIsoDR03 = tr->GetBranch("mcCalIsoDR03");
	b_mcTrkIsoDR03 = tr->GetBranch("mcTrkIsoDR03");
	b_mcIsoDR04 = tr->GetBranch("mcIsoDR04");
	b_mcCalIsoDR04 = tr->GetBranch("mcCalIsoDR04");
	b_mcTrkIsoDR04 = tr->GetBranch("mcTrkIsoDR04");
	b_genMET = tr->GetBranch("genMET");
	b_genMETx = tr->GetBranch("genMETx");
	b_genMETy = tr->GetBranch("genMETy");
	b_genMETPhi = tr->GetBranch("genMETPhi");
	b_MET = tr->GetBranch("MET");
	b_METx = tr->GetBranch("METx");
	b_METy = tr->GetBranch("METy");
	b_METPhi = tr->GetBranch("METPhi");
	b_METsumEt = tr->GetBranch("METsumEt");
	b_uncorrMET = tr->GetBranch("uncorrMET");
	b_uncorrMETPhi = tr->GetBranch("uncorrMETPhi");
	b_uncorrMETSumEt = tr->GetBranch("uncorrMETSumEt");
	b_tcMET = tr->GetBranch("tcMET");
	b_tcMETx = tr->GetBranch("tcMETx");
	b_tcMETy = tr->GetBranch("tcMETy");
	b_tcMETPhi = tr->GetBranch("tcMETPhi");
	b_tcMETsumEt = tr->GetBranch("tcMETsumEt");
	b_tcMETmEtSig = tr->GetBranch("tcMETmEtSig");
	b_tcMETSig = tr->GetBranch("tcMETSig");
	b_pfMET = tr->GetBranch("pfMET");
	b_pfMETx = tr->GetBranch("pfMETx");
	b_pfMETy = tr->GetBranch("pfMETy");
	b_pfMETPhi = tr->GetBranch("pfMETPhi");
	b_pfMETsumEt = tr->GetBranch("pfMETsumEt");
	b_pfMETmEtSig = tr->GetBranch("pfMETmEtSig");
	b_pfMETSig = tr->GetBranch("pfMETSig");
	b_TypeIpfMET = tr->GetBranch("TypeIpfMET");
	b_TypeIpfMETx = tr->GetBranch("TypeIpfMETx");
	b_TypeIpfMETy = tr->GetBranch("TypeIpfMETy");
	b_TypeIpfMETPhi = tr->GetBranch("TypeIpfMETPhi");
	b_TypeIpfMETsumEt = tr->GetBranch("TypeIpfMETsumEt");
	b_TypeIpfMETmEtSig = tr->GetBranch("TypeIpfMETmEtSig");
	b_TypeIpfMETSig = tr->GetBranch("TypeIpfMETSig");
	b_TypeIpIIpfMET = tr->GetBranch("TypeIpIIpfMET");
	b_TypeIpIIpfMETx = tr->GetBranch("TypeIpIIpfMETx");
	b_TypeIpIIpfMETy = tr->GetBranch("TypeIpIIpfMETy");
	b_TypeIpIIpfMETPhi = tr->GetBranch("TypeIpIIpfMETPhi");
	b_TypeIpIIpfMETsumEt = tr->GetBranch("TypeIpIIpfMETsumEt");
	b_TypeIpIIpfMETmEtSig = tr->GetBranch("TypeIpIIpfMETmEtSig");
	b_TypeIpIIpfMETSig = tr->GetBranch("TypeIpIIpfMETSig");
	b_SmearedpfMET = tr->GetBranch("SmearedpfMET");
	b_SmearedpfMETx = tr->GetBranch("SmearedpfMETx");
	b_SmearedpfMETy = tr->GetBranch("SmearedpfMETy");
	b_SmearedpfMETPhi = tr->GetBranch("SmearedpfMETPhi");
	b_SmearedpfMETsumEt = tr->GetBranch("SmearedpfMETsumEt");
	b_SmearedpfMETmEtSig = tr->GetBranch("SmearedpfMETmEtSig");
	b_SmearedpfMETSig = tr->GetBranch("SmearedpfMETSig");
	b_SmearedTypeIpfMET = tr->GetBranch("SmearedTypeIpfMET");
	b_SmearedTypeIpfMETx = tr->GetBranch("SmearedTypeIpfMETx");
	b_SmearedTypeIpfMETy = tr->GetBranch("SmearedTypeIpfMETy");
	b_SmearedTypeIpfMETPhi = tr->GetBranch("SmearedTypeIpfMETPhi");
	b_SmearedTypeIpfMETsumEt = tr->GetBranch("SmearedTypeIpfMETsumEt");
	b_SmearedTypeIpfMETmEtSig = tr->GetBranch("SmearedTypeIpfMETmEtSig");
	b_SmearedTypeIpfMETSig = tr->GetBranch("SmearedTypeIpfMETSig");
	b_npfCharged = tr->GetBranch("npfCharged");
	b_pfChargedSumPt = tr->GetBranch("pfChargedSumPt");
	b_npfChargedHadron = tr->GetBranch("npfChargedHadron");
	b_pfChargedHadronSumPt = tr->GetBranch("pfChargedHadronSumPt");
	b_npfLepton = tr->GetBranch("npfLepton");
	b_pfLeptonSumPt = tr->GetBranch("pfLeptonSumPt");
	b_npfNeutral = tr->GetBranch("npfNeutral");
	b_pfNeutralSumPt = tr->GetBranch("pfNeutralSumPt");
	b_npfNeutralHadron = tr->GetBranch("npfNeutralHadron");
	b_pfNeutralHadronSumPt = tr->GetBranch("pfNeutralHadronSumPt");
	b_npfPhoton = tr->GetBranch("npfPhoton");
	b_pfPhotonSumPt = tr->GetBranch("pfPhotonSumPt");
	b_nEle = tr->GetBranch("nEle");
	b_eleTrg = tr->GetBranch("eleTrg");
	b_eleID = tr->GetBranch("eleID");
	b_eleIDLH = tr->GetBranch("eleIDLH");
	b_eleClass = tr->GetBranch("eleClass");
	b_eleCharge = tr->GetBranch("eleCharge");
	b_eleEn = tr->GetBranch("eleEn");
	b_eleSCRawEn = tr->GetBranch("eleSCRawEn");
	b_eleESEn = tr->GetBranch("eleESEn");
	b_eleSCEn = tr->GetBranch("eleSCEn");
	b_elePt = tr->GetBranch("elePt");
	b_elePz = tr->GetBranch("elePz");
	b_eleEta = tr->GetBranch("eleEta");
	b_elePhi = tr->GetBranch("elePhi");
	b_eleSCEta = tr->GetBranch("eleSCEta");
	b_eleSCPhi = tr->GetBranch("eleSCPhi");
	b_eleSCEtaWidth = tr->GetBranch("eleSCEtaWidth");
	b_eleSCPhiWidth = tr->GetBranch("eleSCPhiWidth");
	b_eleVtx = tr->GetBranch("eleVtx");
	b_eleCaloPos = tr->GetBranch("eleCaloPos");
	b_eleSCPos = tr->GetBranch("eleSCPos");
	b_eleHoverE = tr->GetBranch("eleHoverE");
	b_eleEoverP = tr->GetBranch("eleEoverP");
	b_elePin = tr->GetBranch("elePin");
	b_elePout = tr->GetBranch("elePout");
	b_eleBrem = tr->GetBranch("eleBrem");
	b_elenBrem = tr->GetBranch("elenBrem");
	b_eledEtaAtVtx = tr->GetBranch("eledEtaAtVtx");
	b_eledPhiAtVtx = tr->GetBranch("eledPhiAtVtx");
	b_eleSigmaEtaEta = tr->GetBranch("eleSigmaEtaEta");
	b_eleSigmaIEtaIEta = tr->GetBranch("eleSigmaIEtaIEta");
	b_eleSigmaIEtaIPhi = tr->GetBranch("eleSigmaIEtaIPhi");
	b_eleSigmaIPhiIPhi = tr->GetBranch("eleSigmaIPhiIPhi");
	b_eleE3x3 = tr->GetBranch("eleE3x3");
	b_eleSeedTime = tr->GetBranch("eleSeedTime");
	b_eleSeedEnergy = tr->GetBranch("eleSeedEnergy");
	b_eleRecoFlag = tr->GetBranch("eleRecoFlag");
	b_eleSeverity = tr->GetBranch("eleSeverity");
	b_eleGenIndex = tr->GetBranch("eleGenIndex");
	b_eleGenGMomPID = tr->GetBranch("eleGenGMomPID");
	b_eleGenMomPID = tr->GetBranch("eleGenMomPID");
	b_eleGenMomPt = tr->GetBranch("eleGenMomPt");
	b_eleIsoTrkDR03 = tr->GetBranch("eleIsoTrkDR03");
	b_eleIsoEcalDR03 = tr->GetBranch("eleIsoEcalDR03");
	b_eleIsoHcalDR03 = tr->GetBranch("eleIsoHcalDR03");
	b_eleIsoHcalSolidDR03 = tr->GetBranch("eleIsoHcalSolidDR03");
	b_eleIsoTrkDR04 = tr->GetBranch("eleIsoTrkDR04");
	b_eleIsoEcalDR04 = tr->GetBranch("eleIsoEcalDR04");
	b_eleIsoHcalDR04 = tr->GetBranch("eleIsoHcalDR04");
	b_eleIsoHcalSolidDR04 = tr->GetBranch("eleIsoHcalSolidDR04");
	b_eleConvDist = tr->GetBranch("eleConvDist");
	b_eleConvDcot = tr->GetBranch("eleConvDcot");
	b_eleConvRadius = tr->GetBranch("eleConvRadius");
	b_eleConvFlag = tr->GetBranch("eleConvFlag");
	b_eleConvMissinghit = tr->GetBranch("eleConvMissinghit");
	b_eleESRatio = tr->GetBranch("eleESRatio");
	b_eleESProfileFront = tr->GetBranch("eleESProfileFront");
	b_eleESProfileRear = tr->GetBranch("eleESProfileRear");
	b_elePV2D = tr->GetBranch("elePV2D");
	b_elePV3D = tr->GetBranch("elePV3D");
	b_eleBS2D = tr->GetBranch("eleBS2D");
	b_eleBS3D = tr->GetBranch("eleBS3D");
	b_elePVD0 = tr->GetBranch("elePVD0");
	b_elePVDz = tr->GetBranch("elePVDz");
	b_nPho = tr->GetBranch("nPho");
	b_phoTrg = tr->GetBranch("phoTrg");
	b_phoIsPhoton = tr->GetBranch("phoIsPhoton");
	b_phoE = tr->GetBranch("phoE");
	b_phoEt = tr->GetBranch("phoEt");
	b_phoPz = tr->GetBranch("phoPz");
	b_phoEta = tr->GetBranch("phoEta");
	b_phoPhi = tr->GetBranch("phoPhi");
	b_phoR9 = tr->GetBranch("phoR9");
	b_phoTrkIsoSolidDR03 = tr->GetBranch("phoTrkIsoSolidDR03");
	b_phoTrkIsoHollowDR03 = tr->GetBranch("phoTrkIsoHollowDR03");
	b_phoNTrkSolidDR03 = tr->GetBranch("phoNTrkSolidDR03");
	b_phoNTrkHollowDR03 = tr->GetBranch("phoNTrkHollowDR03");
	b_phoEcalIsoDR03 = tr->GetBranch("phoEcalIsoDR03");
	b_phoHcalIsoDR03 = tr->GetBranch("phoHcalIsoDR03");
	b_phoHcalIsoSolidDR03 = tr->GetBranch("phoHcalIsoSolidDR03");
	b_phoTrkIsoSolidDR04 = tr->GetBranch("phoTrkIsoSolidDR04");
	b_phoTrkIsoHollowDR04 = tr->GetBranch("phoTrkIsoHollowDR04");
	b_phoNTrkSolidDR04 = tr->GetBranch("phoNTrkSolidDR04");
	b_phoNTrkHollowDR04 = tr->GetBranch("phoNTrkHollowDR04");
	b_phoEcalIsoDR04 = tr->GetBranch("phoEcalIsoDR04");
	b_phoHcalIsoDR04 = tr->GetBranch("phoHcalIsoDR04");
	b_phoHcalIsoSolidDR04 = tr->GetBranch("phoHcalIsoSolidDR04");
	b_phoEtVtx = tr->GetBranch("phoEtVtx");
	b_phoEtaVtx = tr->GetBranch("phoEtaVtx");
	b_phoPhiVtx = tr->GetBranch("phoPhiVtx");
	b_phoTrkIsoSolidDR03Vtx = tr->GetBranch("phoTrkIsoSolidDR03Vtx");
	b_phoTrkIsoHollowDR03Vtx = tr->GetBranch("phoTrkIsoHollowDR03Vtx");
	b_phoTrkIsoSolidDR04Vtx = tr->GetBranch("phoTrkIsoSolidDR04Vtx");
	b_phoTrkIsoHollowDR04Vtx = tr->GetBranch("phoTrkIsoHollowDR04Vtx");
	b_phoHoverE = tr->GetBranch("phoHoverE");
	b_phoSigmaEtaEta = tr->GetBranch("phoSigmaEtaEta");
	b_phoSigmaIEtaIEta = tr->GetBranch("phoSigmaIEtaIEta");
	b_phoSigmaIEtaIPhi = tr->GetBranch("phoSigmaIEtaIPhi");
	b_phoSigmaIPhiIPhi = tr->GetBranch("phoSigmaIPhiIPhi");
	b_phoE3x3 = tr->GetBranch("phoE3x3");
	b_phoE5x5 = tr->GetBranch("phoE5x5");
	b_phoSeedTime = tr->GetBranch("phoSeedTime");
	b_phoSeedEnergy = tr->GetBranch("phoSeedEnergy");
	b_phoRecoFlag = tr->GetBranch("phoRecoFlag");
	b_phoSeverity = tr->GetBranch("phoSeverity");
	b_phoPos = tr->GetBranch("phoPos");
	b_phoGenIndex = tr->GetBranch("phoGenIndex");
	b_phoGenGMomPID = tr->GetBranch("phoGenGMomPID");
	b_phoGenMomPID = tr->GetBranch("phoGenMomPID");
	b_phoGenMomPt = tr->GetBranch("phoGenMomPt");
	b_phoSCE = tr->GetBranch("phoSCE");
	b_phoESE = tr->GetBranch("phoESE");
	b_phoSCEt = tr->GetBranch("phoSCEt");
	b_phoSCEta = tr->GetBranch("phoSCEta");
	b_phoSCPhi = tr->GetBranch("phoSCPhi");
	b_phoSCEtaWidth = tr->GetBranch("phoSCEtaWidth");
	b_phoSCPhiWidth = tr->GetBranch("phoSCPhiWidth");
	b_phoVtx = tr->GetBranch("phoVtx");
	b_phoVtxD0 = tr->GetBranch("phoVtxD0");
	b_phoOverlap = tr->GetBranch("phoOverlap");
	b_phohasPixelSeed = tr->GetBranch("phohasPixelSeed");
	b_phoIsConv = tr->GetBranch("phoIsConv");
	b_phoESRatio = tr->GetBranch("phoESRatio");
	b_phoESProfileFront = tr->GetBranch("phoESProfileFront");
	b_phoESProfileRear = tr->GetBranch("phoESProfileRear");
	b_phoNTracks = tr->GetBranch("phoNTracks");
	b_phoConvPairInvariantMass = tr->GetBranch("phoConvPairInvariantMass");
	b_phoConvPairCotThetaSeparation = tr->GetBranch("phoConvPairCotThetaSeparation");
	b_phoConvPairMomentumEta = tr->GetBranch("phoConvPairMomentumEta");
	b_phoConvPairMomentumPhi = tr->GetBranch("phoConvPairMomentumPhi");
	b_phoConvPairMomentumX = tr->GetBranch("phoConvPairMomentumX");
	b_phoConvPairMomentumY = tr->GetBranch("phoConvPairMomentumY");
	b_phoConvPairMomentumZ = tr->GetBranch("phoConvPairMomentumZ");
	b_phoConvDistOfMinimumApproach = tr->GetBranch("phoConvDistOfMinimumApproach");
	b_phoConvDPhiTracksAtVtx = tr->GetBranch("phoConvDPhiTracksAtVtx");
	b_phoConvDPhiTracksAtEcal = tr->GetBranch("phoConvDPhiTracksAtEcal");
	b_phoConvDEtaTracksAtEcal = tr->GetBranch("phoConvDEtaTracksAtEcal");
	b_phoConvVtxValid = tr->GetBranch("phoConvVtxValid");
	b_phoConvVtxEta = tr->GetBranch("phoConvVtxEta");
	b_phoConvVtxPhi = tr->GetBranch("phoConvVtxPhi");
	b_phoConvVtxR = tr->GetBranch("phoConvVtxR");
	b_phoConvVtxX = tr->GetBranch("phoConvVtxX");
	b_phoConvVtxY = tr->GetBranch("phoConvVtxY");
	b_phoConvVtxZ = tr->GetBranch("phoConvVtxZ");
	b_phoConvVtxChi2 = tr->GetBranch("phoConvVtxChi2");
	b_phoConvVtxNdof = tr->GetBranch("phoConvVtxNdof");
	b_phoConvChi2Prob = tr->GetBranch("phoConvChi2Prob");
	b_phoConvEoverP = tr->GetBranch("phoConvEoverP");
	b_phoNxtal = tr->GetBranch("phoNxtal");
	b_phoXtalTime = tr->GetBranch("phoXtalTime");
	b_phoXtalEnergy = tr->GetBranch("phoXtalEnergy");
	b_phoXtalZ = tr->GetBranch("phoXtalZ");
	b_phoXtalX = tr->GetBranch("phoXtalX");
	b_phoXtalY = tr->GetBranch("phoXtalY");
	b_phoXtalEta = tr->GetBranch("phoXtalEta");
	b_phoXtalPhi = tr->GetBranch("phoXtalPhi");
	b_pho5x5Time = tr->GetBranch("pho5x5Time");
	b_pho5x5Energy = tr->GetBranch("pho5x5Energy");
	b_pho5x5Z = tr->GetBranch("pho5x5Z");
	b_pho5x5X = tr->GetBranch("pho5x5X");
	b_pho5x5Y = tr->GetBranch("pho5x5Y");
	b_pho5x5Eta = tr->GetBranch("pho5x5Eta");
	b_pho5x5Phi = tr->GetBranch("pho5x5Phi");
	b_nMu = tr->GetBranch("nMu");
	b_muTrg = tr->GetBranch("muTrg");
	b_muEta = tr->GetBranch("muEta");
	b_muPhi = tr->GetBranch("muPhi");
	b_muCharge = tr->GetBranch("muCharge");
	b_muPt = tr->GetBranch("muPt");
	b_muPz = tr->GetBranch("muPz");
	b_muGenIndex = tr->GetBranch("muGenIndex");
	b_muGenGMomPID = tr->GetBranch("muGenGMomPID");
	b_muGenMomPID = tr->GetBranch("muGenMomPID");
	b_muGenMomPt = tr->GetBranch("muGenMomPt");
	b_muIsoTrk = tr->GetBranch("muIsoTrk");
	b_muIsoCalo = tr->GetBranch("muIsoCalo");
	b_muIsoEcal = tr->GetBranch("muIsoEcal");
	b_muIsoHcal = tr->GetBranch("muIsoHcal");
	b_muChi2NDF = tr->GetBranch("muChi2NDF");
	b_muEmVeto = tr->GetBranch("muEmVeto");
	b_muHadVeto = tr->GetBranch("muHadVeto");
	b_muType = tr->GetBranch("muType");
	b_muID = tr->GetBranch("muID");
	b_muD0 = tr->GetBranch("muD0");
	b_muDz = tr->GetBranch("muDz");
	b_muPVD0 = tr->GetBranch("muPVD0");
	b_muPVDz = tr->GetBranch("muPVDz");
	b_muValidFraction = tr->GetBranch("muValidFraction");
	b_muTrkdPt = tr->GetBranch("muTrkdPt");
	b_muNumberOfHits = tr->GetBranch("muNumberOfHits");
	b_muNumberOfValidHits = tr->GetBranch("muNumberOfValidHits");
	b_muNumberOfInactiveHits = tr->GetBranch("muNumberOfInactiveHits");
	b_muNumberOfValidTrkHits = tr->GetBranch("muNumberOfValidTrkHits");
	b_muNumberOfValidPixelHits = tr->GetBranch("muNumberOfValidPixelHits");
	b_muNumberOfValidMuonHits = tr->GetBranch("muNumberOfValidMuonHits");
	b_muStations = tr->GetBranch("muStations");
	b_muChambers = tr->GetBranch("muChambers");
	b_muPV2D = tr->GetBranch("muPV2D");
	b_muPV3D = tr->GetBranch("muPV3D");
	b_muBS2D = tr->GetBranch("muBS2D");
	b_muBS3D = tr->GetBranch("muBS3D");
	b_muVtx = tr->GetBranch("muVtx");
	b_nJet = tr->GetBranch("nJet");
	b_jetTrg = tr->GetBranch("jetTrg");
	b_jetEn = tr->GetBranch("jetEn");
	b_jetPt = tr->GetBranch("jetPt");
	b_jetEta = tr->GetBranch("jetEta");
	b_jetPhi = tr->GetBranch("jetPhi");
	b_jetMass = tr->GetBranch("jetMass");
	b_jetEt = tr->GetBranch("jetEt");
	b_jetpartonFlavour = tr->GetBranch("jetpartonFlavour");
	b_jetRawPt = tr->GetBranch("jetRawPt");
	b_jetRawEn = tr->GetBranch("jetRawEn");
	b_jetCharge = tr->GetBranch("jetCharge");
	b_jetNeutralEmEnergy = tr->GetBranch("jetNeutralEmEnergy");
	b_jetNeutralEmEnergyFraction = tr->GetBranch("jetNeutralEmEnergyFraction");
	b_jetNeutralHadronEnergy = tr->GetBranch("jetNeutralHadronEnergy");
	b_jetNeutralHadronEnergyFraction = tr->GetBranch("jetNeutralHadronEnergyFraction");
	b_jetNConstituents = tr->GetBranch("jetNConstituents");
	b_jetChargedEmEnergy = tr->GetBranch("jetChargedEmEnergy");
	b_jetChargedEmEnergyFraction = tr->GetBranch("jetChargedEmEnergyFraction");
	b_jetChargedHadronEnergy = tr->GetBranch("jetChargedHadronEnergy");
	b_jetChargedHadronEnergyFraction = tr->GetBranch("jetChargedHadronEnergyFraction");
	b_jetChargedHadronMultiplicity = tr->GetBranch("jetChargedHadronMultiplicity");
	b_jetChargedMuEnergy = tr->GetBranch("jetChargedMuEnergy");
	b_jetChargedMuEnergyFraction = tr->GetBranch("jetChargedMuEnergyFraction");
	b_jetJVAlpha = tr->GetBranch("jetJVAlpha");
	b_jetJVBeta = tr->GetBranch("jetJVBeta");
	b_jetGenJetIndex = tr->GetBranch("jetGenJetIndex");
	b_jetGenJetEn = tr->GetBranch("jetGenJetEn");
	b_jetGenJetPt = tr->GetBranch("jetGenJetPt");
	b_jetGenJetEta = tr->GetBranch("jetGenJetEta");
	b_jetGenJetPhi = tr->GetBranch("jetGenJetPhi");
	b_jetGenJetMass = tr->GetBranch("jetGenJetMass");
	b_jetGenPartonID = tr->GetBranch("jetGenPartonID");
	b_jetGenPartonMomID = tr->GetBranch("jetGenPartonMomID");
	b_nZee = tr->GetBranch("nZee");
	b_ZeeMass = tr->GetBranch("ZeeMass");
	b_ZeePt = tr->GetBranch("ZeePt");
	b_ZeeEta = tr->GetBranch("ZeeEta");
	b_ZeePhi = tr->GetBranch("ZeePhi");
	b_ZeeLeg1Index = tr->GetBranch("ZeeLeg1Index");
	b_ZeeLeg2Index = tr->GetBranch("ZeeLeg2Index");
	b_nZmumu = tr->GetBranch("nZmumu");
	b_ZmumuMass = tr->GetBranch("ZmumuMass");
	b_ZmumuPt = tr->GetBranch("ZmumuPt");
	b_ZmumuEta = tr->GetBranch("ZmumuEta");
	b_ZmumuPhi = tr->GetBranch("ZmumuPhi");
	b_ZmumuLeg1Index = tr->GetBranch("ZmumuLeg1Index");
	b_ZmumuLeg2Index = tr->GetBranch("ZmumuLeg2Index");
	b_nWenu = tr->GetBranch("nWenu");
	b_WenuMassTCaloMET = tr->GetBranch("WenuMassTCaloMET");
	b_WenuEtCaloMET = tr->GetBranch("WenuEtCaloMET");
	b_WenuACopCaloMET = tr->GetBranch("WenuACopCaloMET");
	b_WenuMassTTcMET = tr->GetBranch("WenuMassTTcMET");
	b_WenuEtTcMET = tr->GetBranch("WenuEtTcMET");
	b_WenuACopTcMET = tr->GetBranch("WenuACopTcMET");
	b_WenuMassTPfMET = tr->GetBranch("WenuMassTPfMET");
	b_WenuEtPfMET = tr->GetBranch("WenuEtPfMET");
	b_WenuACopPfMET = tr->GetBranch("WenuACopPfMET");
	b_WenuEleIndex = tr->GetBranch("WenuEleIndex");
	b_nWmunu = tr->GetBranch("nWmunu");
	b_WmunuMassTCaloMET = tr->GetBranch("WmunuMassTCaloMET");
	b_WmunuEtCaloMET = tr->GetBranch("WmunuEtCaloMET");
	b_WmunuACopCaloMET = tr->GetBranch("WmunuACopCaloMET");
	b_WmunuMassTTcMET = tr->GetBranch("WmunuMassTTcMET");
	b_WmunuEtTcMET = tr->GetBranch("WmunuEtTcMET");
	b_WmunuACopTcMET = tr->GetBranch("WmunuACopTcMET");
	b_WmunuMassTPfMET = tr->GetBranch("WmunuMassTPfMET");
	b_WmunuEtPfMET = tr->GetBranch("WmunuEtPfMET");
	b_WmunuACopPfMET = tr->GetBranch("WmunuACopPfMET");
	b_WmunuMuIndex = tr->GetBranch("WmunuMuIndex");
	b_run->SetAddress(&run);
	b_event->SetAddress(&event);
	b_orbit->SetAddress(&orbit);
	b_bx->SetAddress(&bx);
	b_lumis->SetAddress(&lumis);
	b_isData->SetAddress(&isData);
	b_ttbit0->SetAddress(&ttbit0);
	b_nHLT->SetAddress(&nHLT);
	b_HLT->SetAddress(&HLT);
	b_HLTIndex->SetAddress(&HLTIndex);
	b_HLTprescale->SetAddress(&HLTprescale);
	b_nHFTowersP->SetAddress(&nHFTowersP);
	b_nHFTowersN->SetAddress(&nHFTowersN);
	b_nVtx->SetAddress(&nVtx);
	b_vtx->SetAddress(&vtx);
	b_vtxNTrk->SetAddress(&vtxNTrk);
	b_vtxNDF->SetAddress(&vtxNDF);
	b_vtxD0->SetAddress(&vtxD0);
	b_nGoodVtx->SetAddress(&nGoodVtx);
	b_IsVtxGood->SetAddress(&IsVtxGood);
	b_nTrk->SetAddress(&nTrk);
	b_nGoodTrk->SetAddress(&nGoodTrk);
	b_IsTracksGood->SetAddress(&IsTracksGood);
	b_rho->SetAddress(&rho);
	b_sigma->SetAddress(&sigma);
	b_rhoNeutral->SetAddress(&rhoNeutral);
	b_pdf->SetAddress(&pdf);
	b_pthat->SetAddress(&pthat);
	b_processID->SetAddress(&processID);
	b_nBX->SetAddress(&nBX);
	b_nPU->SetAddress(&nPU);
	b_BXPU->SetAddress(&BXPU);
	b_nMC->SetAddress(&nMC);
	b_mcPID->SetAddress(&mcPID);
	b_mcVtx->SetAddress(&mcVtx);
	b_mcPt->SetAddress(&mcPt);
	b_mcMass->SetAddress(&mcMass);
	b_mcEta->SetAddress(&mcEta);
	b_mcPhi->SetAddress(&mcPhi);
	b_mcGMomPID->SetAddress(&mcGMomPID);
	b_mcMomPID->SetAddress(&mcMomPID);
	b_mcMomPt->SetAddress(&mcMomPt);
	b_mcMomMass->SetAddress(&mcMomMass);
	b_mcMomEta->SetAddress(&mcMomEta);
	b_mcMomPhi->SetAddress(&mcMomPhi);
	b_mcIndex->SetAddress(&mcIndex);
	b_mcDecayType->SetAddress(&mcDecayType);
	b_mcIsoDR03->SetAddress(&mcIsoDR03);
	b_mcCalIsoDR03->SetAddress(&mcCalIsoDR03);
	b_mcTrkIsoDR03->SetAddress(&mcTrkIsoDR03);
	b_mcIsoDR04->SetAddress(&mcIsoDR04);
	b_mcCalIsoDR04->SetAddress(&mcCalIsoDR04);
	b_mcTrkIsoDR04->SetAddress(&mcTrkIsoDR04);
	b_genMET->SetAddress(&genMET);
	b_genMETx->SetAddress(&genMETx);
	b_genMETy->SetAddress(&genMETy);
	b_genMETPhi->SetAddress(&genMETPhi);
	b_MET->SetAddress(&MET);
	b_METx->SetAddress(&METx);
	b_METy->SetAddress(&METy);
	b_METPhi->SetAddress(&METPhi);
	b_METsumEt->SetAddress(&METsumEt);
	b_uncorrMET->SetAddress(&uncorrMET);
	b_uncorrMETPhi->SetAddress(&uncorrMETPhi);
	b_uncorrMETSumEt->SetAddress(&uncorrMETSumEt);
	b_tcMET->SetAddress(&tcMET);
	b_tcMETx->SetAddress(&tcMETx);
	b_tcMETy->SetAddress(&tcMETy);
	b_tcMETPhi->SetAddress(&tcMETPhi);
	b_tcMETsumEt->SetAddress(&tcMETsumEt);
	b_tcMETmEtSig->SetAddress(&tcMETmEtSig);
	b_tcMETSig->SetAddress(&tcMETSig);
	b_pfMET->SetAddress(&pfMET);
	b_pfMETx->SetAddress(&pfMETx);
	b_pfMETy->SetAddress(&pfMETy);
	b_pfMETPhi->SetAddress(&pfMETPhi);
	b_pfMETsumEt->SetAddress(&pfMETsumEt);
	b_pfMETmEtSig->SetAddress(&pfMETmEtSig);
	b_pfMETSig->SetAddress(&pfMETSig);
	b_TypeIpfMET->SetAddress(&TypeIpfMET);
	b_TypeIpfMETx->SetAddress(&TypeIpfMETx);
	b_TypeIpfMETy->SetAddress(&TypeIpfMETy);
	b_TypeIpfMETPhi->SetAddress(&TypeIpfMETPhi);
	b_TypeIpfMETsumEt->SetAddress(&TypeIpfMETsumEt);
	b_TypeIpfMETmEtSig->SetAddress(&TypeIpfMETmEtSig);
	b_TypeIpfMETSig->SetAddress(&TypeIpfMETSig);
	b_TypeIpIIpfMET->SetAddress(&TypeIpIIpfMET);
	b_TypeIpIIpfMETx->SetAddress(&TypeIpIIpfMETx);
	b_TypeIpIIpfMETy->SetAddress(&TypeIpIIpfMETy);
	b_TypeIpIIpfMETPhi->SetAddress(&TypeIpIIpfMETPhi);
	b_TypeIpIIpfMETsumEt->SetAddress(&TypeIpIIpfMETsumEt);
	b_TypeIpIIpfMETmEtSig->SetAddress(&TypeIpIIpfMETmEtSig);
	b_TypeIpIIpfMETSig->SetAddress(&TypeIpIIpfMETSig);
	b_SmearedpfMET->SetAddress(&SmearedpfMET);
	b_SmearedpfMETx->SetAddress(&SmearedpfMETx);
	b_SmearedpfMETy->SetAddress(&SmearedpfMETy);
	b_SmearedpfMETPhi->SetAddress(&SmearedpfMETPhi);
	b_SmearedpfMETsumEt->SetAddress(&SmearedpfMETsumEt);
	b_SmearedpfMETmEtSig->SetAddress(&SmearedpfMETmEtSig);
	b_SmearedpfMETSig->SetAddress(&SmearedpfMETSig);
	b_SmearedTypeIpfMET->SetAddress(&SmearedTypeIpfMET);
	b_SmearedTypeIpfMETx->SetAddress(&SmearedTypeIpfMETx);
	b_SmearedTypeIpfMETy->SetAddress(&SmearedTypeIpfMETy);
	b_SmearedTypeIpfMETPhi->SetAddress(&SmearedTypeIpfMETPhi);
	b_SmearedTypeIpfMETsumEt->SetAddress(&SmearedTypeIpfMETsumEt);
	b_SmearedTypeIpfMETmEtSig->SetAddress(&SmearedTypeIpfMETmEtSig);
	b_SmearedTypeIpfMETSig->SetAddress(&SmearedTypeIpfMETSig);
	b_npfCharged->SetAddress(&npfCharged);
	b_pfChargedSumPt->SetAddress(&pfChargedSumPt);
	b_npfChargedHadron->SetAddress(&npfChargedHadron);
	b_pfChargedHadronSumPt->SetAddress(&pfChargedHadronSumPt);
	b_npfLepton->SetAddress(&npfLepton);
	b_pfLeptonSumPt->SetAddress(&pfLeptonSumPt);
	b_npfNeutral->SetAddress(&npfNeutral);
	b_pfNeutralSumPt->SetAddress(&pfNeutralSumPt);
	b_npfNeutralHadron->SetAddress(&npfNeutralHadron);
	b_pfNeutralHadronSumPt->SetAddress(&pfNeutralHadronSumPt);
	b_npfPhoton->SetAddress(&npfPhoton);
	b_pfPhotonSumPt->SetAddress(&pfPhotonSumPt);
	b_nEle->SetAddress(&nEle);
	b_eleTrg->SetAddress(&eleTrg);
	b_eleID->SetAddress(&eleID);
	b_eleIDLH->SetAddress(&eleIDLH);
	b_eleClass->SetAddress(&eleClass);
	b_eleCharge->SetAddress(&eleCharge);
	b_eleEn->SetAddress(&eleEn);
	b_eleSCRawEn->SetAddress(&eleSCRawEn);
	b_eleESEn->SetAddress(&eleESEn);
	b_eleSCEn->SetAddress(&eleSCEn);
	b_elePt->SetAddress(&elePt);
	b_elePz->SetAddress(&elePz);
	b_eleEta->SetAddress(&eleEta);
	b_elePhi->SetAddress(&elePhi);
	b_eleSCEta->SetAddress(&eleSCEta);
	b_eleSCPhi->SetAddress(&eleSCPhi);
	b_eleSCEtaWidth->SetAddress(&eleSCEtaWidth);
	b_eleSCPhiWidth->SetAddress(&eleSCPhiWidth);
	b_eleVtx->SetAddress(&eleVtx);
	b_eleCaloPos->SetAddress(&eleCaloPos);
	b_eleSCPos->SetAddress(&eleSCPos);
	b_eleHoverE->SetAddress(&eleHoverE);
	b_eleEoverP->SetAddress(&eleEoverP);
	b_elePin->SetAddress(&elePin);
	b_elePout->SetAddress(&elePout);
	b_eleBrem->SetAddress(&eleBrem);
	b_elenBrem->SetAddress(&elenBrem);
	b_eledEtaAtVtx->SetAddress(&eledEtaAtVtx);
	b_eledPhiAtVtx->SetAddress(&eledPhiAtVtx);
	b_eleSigmaEtaEta->SetAddress(&eleSigmaEtaEta);
	b_eleSigmaIEtaIEta->SetAddress(&eleSigmaIEtaIEta);
	b_eleSigmaIEtaIPhi->SetAddress(&eleSigmaIEtaIPhi);
	b_eleSigmaIPhiIPhi->SetAddress(&eleSigmaIPhiIPhi);
	b_eleE3x3->SetAddress(&eleE3x3);
	b_eleSeedTime->SetAddress(&eleSeedTime);
	b_eleSeedEnergy->SetAddress(&eleSeedEnergy);
	b_eleRecoFlag->SetAddress(&eleRecoFlag);
	b_eleSeverity->SetAddress(&eleSeverity);
	b_eleGenIndex->SetAddress(&eleGenIndex);
	b_eleGenGMomPID->SetAddress(&eleGenGMomPID);
	b_eleGenMomPID->SetAddress(&eleGenMomPID);
	b_eleGenMomPt->SetAddress(&eleGenMomPt);
	b_eleIsoTrkDR03->SetAddress(&eleIsoTrkDR03);
	b_eleIsoEcalDR03->SetAddress(&eleIsoEcalDR03);
	b_eleIsoHcalDR03->SetAddress(&eleIsoHcalDR03);
	b_eleIsoHcalSolidDR03->SetAddress(&eleIsoHcalSolidDR03);
	b_eleIsoTrkDR04->SetAddress(&eleIsoTrkDR04);
	b_eleIsoEcalDR04->SetAddress(&eleIsoEcalDR04);
	b_eleIsoHcalDR04->SetAddress(&eleIsoHcalDR04);
	b_eleIsoHcalSolidDR04->SetAddress(&eleIsoHcalSolidDR04);
	b_eleConvDist->SetAddress(&eleConvDist);
	b_eleConvDcot->SetAddress(&eleConvDcot);
	b_eleConvRadius->SetAddress(&eleConvRadius);
	b_eleConvFlag->SetAddress(&eleConvFlag);
	b_eleConvMissinghit->SetAddress(&eleConvMissinghit);
	b_eleESRatio->SetAddress(&eleESRatio);
	b_eleESProfileFront->SetAddress(&eleESProfileFront);
	b_eleESProfileRear->SetAddress(&eleESProfileRear);
	b_elePV2D->SetAddress(&elePV2D);
	b_elePV3D->SetAddress(&elePV3D);
	b_eleBS2D->SetAddress(&eleBS2D);
	b_eleBS3D->SetAddress(&eleBS3D);
	b_elePVD0->SetAddress(&elePVD0);
	b_elePVDz->SetAddress(&elePVDz);
	b_nPho->SetAddress(&nPho);
	b_phoTrg->SetAddress(&phoTrg);
	b_phoIsPhoton->SetAddress(&phoIsPhoton);
	b_phoE->SetAddress(&phoE);
	b_phoEt->SetAddress(&phoEt);
	b_phoPz->SetAddress(&phoPz);
	b_phoEta->SetAddress(&phoEta);
	b_phoPhi->SetAddress(&phoPhi);
	b_phoR9->SetAddress(&phoR9);
	b_phoTrkIsoSolidDR03->SetAddress(&phoTrkIsoSolidDR03);
	b_phoTrkIsoHollowDR03->SetAddress(&phoTrkIsoHollowDR03);
	b_phoNTrkSolidDR03->SetAddress(&phoNTrkSolidDR03);
	b_phoNTrkHollowDR03->SetAddress(&phoNTrkHollowDR03);
	b_phoEcalIsoDR03->SetAddress(&phoEcalIsoDR03);
	b_phoHcalIsoDR03->SetAddress(&phoHcalIsoDR03);
	b_phoHcalIsoSolidDR03->SetAddress(&phoHcalIsoSolidDR03);
	b_phoTrkIsoSolidDR04->SetAddress(&phoTrkIsoSolidDR04);
	b_phoTrkIsoHollowDR04->SetAddress(&phoTrkIsoHollowDR04);
	b_phoNTrkSolidDR04->SetAddress(&phoNTrkSolidDR04);
	b_phoNTrkHollowDR04->SetAddress(&phoNTrkHollowDR04);
	b_phoEcalIsoDR04->SetAddress(&phoEcalIsoDR04);
	b_phoHcalIsoDR04->SetAddress(&phoHcalIsoDR04);
	b_phoHcalIsoSolidDR04->SetAddress(&phoHcalIsoSolidDR04);
	b_phoEtVtx->SetAddress(&phoEtVtx);
	b_phoEtaVtx->SetAddress(&phoEtaVtx);
	b_phoPhiVtx->SetAddress(&phoPhiVtx);
	b_phoTrkIsoSolidDR03Vtx->SetAddress(&phoTrkIsoSolidDR03Vtx);
	b_phoTrkIsoHollowDR03Vtx->SetAddress(&phoTrkIsoHollowDR03Vtx);
	b_phoTrkIsoSolidDR04Vtx->SetAddress(&phoTrkIsoSolidDR04Vtx);
	b_phoTrkIsoHollowDR04Vtx->SetAddress(&phoTrkIsoHollowDR04Vtx);
	b_phoHoverE->SetAddress(&phoHoverE);
	b_phoSigmaEtaEta->SetAddress(&phoSigmaEtaEta);
	b_phoSigmaIEtaIEta->SetAddress(&phoSigmaIEtaIEta);
	b_phoSigmaIEtaIPhi->SetAddress(&phoSigmaIEtaIPhi);
	b_phoSigmaIPhiIPhi->SetAddress(&phoSigmaIPhiIPhi);
	b_phoE3x3->SetAddress(&phoE3x3);
	b_phoE5x5->SetAddress(&phoE5x5);
	b_phoSeedTime->SetAddress(&phoSeedTime);
	b_phoSeedEnergy->SetAddress(&phoSeedEnergy);
	b_phoRecoFlag->SetAddress(&phoRecoFlag);
	b_phoSeverity->SetAddress(&phoSeverity);
	b_phoPos->SetAddress(&phoPos);
	b_phoGenIndex->SetAddress(&phoGenIndex);
	b_phoGenGMomPID->SetAddress(&phoGenGMomPID);
	b_phoGenMomPID->SetAddress(&phoGenMomPID);
	b_phoGenMomPt->SetAddress(&phoGenMomPt);
	b_phoSCE->SetAddress(&phoSCE);
	b_phoESE->SetAddress(&phoESE);
	b_phoSCEt->SetAddress(&phoSCEt);
	b_phoSCEta->SetAddress(&phoSCEta);
	b_phoSCPhi->SetAddress(&phoSCPhi);
	b_phoSCEtaWidth->SetAddress(&phoSCEtaWidth);
	b_phoSCPhiWidth->SetAddress(&phoSCPhiWidth);
	b_phoVtx->SetAddress(&phoVtx);
	b_phoVtxD0->SetAddress(&phoVtxD0);
	b_phoOverlap->SetAddress(&phoOverlap);
	b_phohasPixelSeed->SetAddress(&phohasPixelSeed);
	b_phoIsConv->SetAddress(&phoIsConv);
	b_phoESRatio->SetAddress(&phoESRatio);
	b_phoESProfileFront->SetAddress(&phoESProfileFront);
	b_phoESProfileRear->SetAddress(&phoESProfileRear);
	b_phoNTracks->SetAddress(&phoNTracks);
	b_phoConvPairInvariantMass->SetAddress(&phoConvPairInvariantMass);
	b_phoConvPairCotThetaSeparation->SetAddress(&phoConvPairCotThetaSeparation);
	b_phoConvPairMomentumEta->SetAddress(&phoConvPairMomentumEta);
	b_phoConvPairMomentumPhi->SetAddress(&phoConvPairMomentumPhi);
	b_phoConvPairMomentumX->SetAddress(&phoConvPairMomentumX);
	b_phoConvPairMomentumY->SetAddress(&phoConvPairMomentumY);
	b_phoConvPairMomentumZ->SetAddress(&phoConvPairMomentumZ);
	b_phoConvDistOfMinimumApproach->SetAddress(&phoConvDistOfMinimumApproach);
	b_phoConvDPhiTracksAtVtx->SetAddress(&phoConvDPhiTracksAtVtx);
	b_phoConvDPhiTracksAtEcal->SetAddress(&phoConvDPhiTracksAtEcal);
	b_phoConvDEtaTracksAtEcal->SetAddress(&phoConvDEtaTracksAtEcal);
	b_phoConvVtxValid->SetAddress(&phoConvVtxValid);
	b_phoConvVtxEta->SetAddress(&phoConvVtxEta);
	b_phoConvVtxPhi->SetAddress(&phoConvVtxPhi);
	b_phoConvVtxR->SetAddress(&phoConvVtxR);
	b_phoConvVtxX->SetAddress(&phoConvVtxX);
	b_phoConvVtxY->SetAddress(&phoConvVtxY);
	b_phoConvVtxZ->SetAddress(&phoConvVtxZ);
	b_phoConvVtxChi2->SetAddress(&phoConvVtxChi2);
	b_phoConvVtxNdof->SetAddress(&phoConvVtxNdof);
	b_phoConvChi2Prob->SetAddress(&phoConvChi2Prob);
	b_phoConvEoverP->SetAddress(&phoConvEoverP);
	b_phoNxtal->SetAddress(&phoNxtal);
	b_phoXtalTime->SetAddress(&phoXtalTime);
	b_phoXtalEnergy->SetAddress(&phoXtalEnergy);
	b_phoXtalZ->SetAddress(&phoXtalZ);
	b_phoXtalX->SetAddress(&phoXtalX);
	b_phoXtalY->SetAddress(&phoXtalY);
	b_phoXtalEta->SetAddress(&phoXtalEta);
	b_phoXtalPhi->SetAddress(&phoXtalPhi);
	b_pho5x5Time->SetAddress(&pho5x5Time);
	b_pho5x5Energy->SetAddress(&pho5x5Energy);
	b_pho5x5Z->SetAddress(&pho5x5Z);
	b_pho5x5X->SetAddress(&pho5x5X);
	b_pho5x5Y->SetAddress(&pho5x5Y);
	b_pho5x5Eta->SetAddress(&pho5x5Eta);
	b_pho5x5Phi->SetAddress(&pho5x5Phi);
	b_nMu->SetAddress(&nMu);
	b_muTrg->SetAddress(&muTrg);
	b_muEta->SetAddress(&muEta);
	b_muPhi->SetAddress(&muPhi);
	b_muCharge->SetAddress(&muCharge);
	b_muPt->SetAddress(&muPt);
	b_muPz->SetAddress(&muPz);
	b_muGenIndex->SetAddress(&muGenIndex);
	b_muGenGMomPID->SetAddress(&muGenGMomPID);
	b_muGenMomPID->SetAddress(&muGenMomPID);
	b_muGenMomPt->SetAddress(&muGenMomPt);
	b_muIsoTrk->SetAddress(&muIsoTrk);
	b_muIsoCalo->SetAddress(&muIsoCalo);
	b_muIsoEcal->SetAddress(&muIsoEcal);
	b_muIsoHcal->SetAddress(&muIsoHcal);
	b_muChi2NDF->SetAddress(&muChi2NDF);
	b_muEmVeto->SetAddress(&muEmVeto);
	b_muHadVeto->SetAddress(&muHadVeto);
	b_muType->SetAddress(&muType);
	b_muID->SetAddress(&muID);
	b_muD0->SetAddress(&muD0);
	b_muDz->SetAddress(&muDz);
	b_muPVD0->SetAddress(&muPVD0);
	b_muPVDz->SetAddress(&muPVDz);
	b_muValidFraction->SetAddress(&muValidFraction);
	b_muTrkdPt->SetAddress(&muTrkdPt);
	b_muNumberOfHits->SetAddress(&muNumberOfHits);
	b_muNumberOfValidHits->SetAddress(&muNumberOfValidHits);
	b_muNumberOfInactiveHits->SetAddress(&muNumberOfInactiveHits);
	b_muNumberOfValidTrkHits->SetAddress(&muNumberOfValidTrkHits);
	b_muNumberOfValidPixelHits->SetAddress(&muNumberOfValidPixelHits);
	b_muNumberOfValidMuonHits->SetAddress(&muNumberOfValidMuonHits);
	b_muStations->SetAddress(&muStations);
	b_muChambers->SetAddress(&muChambers);
	b_muPV2D->SetAddress(&muPV2D);
	b_muPV3D->SetAddress(&muPV3D);
	b_muBS2D->SetAddress(&muBS2D);
	b_muBS3D->SetAddress(&muBS3D);
	b_muVtx->SetAddress(&muVtx);
	b_nJet->SetAddress(&nJet);
	b_jetTrg->SetAddress(&jetTrg);
	b_jetEn->SetAddress(&jetEn);
	b_jetPt->SetAddress(&jetPt);
	b_jetEta->SetAddress(&jetEta);
	b_jetPhi->SetAddress(&jetPhi);
	b_jetMass->SetAddress(&jetMass);
	b_jetEt->SetAddress(&jetEt);
	b_jetpartonFlavour->SetAddress(&jetpartonFlavour);
	b_jetRawPt->SetAddress(&jetRawPt);
	b_jetRawEn->SetAddress(&jetRawEn);
	b_jetCharge->SetAddress(&jetCharge);
	b_jetNeutralEmEnergy->SetAddress(&jetNeutralEmEnergy);
	b_jetNeutralEmEnergyFraction->SetAddress(&jetNeutralEmEnergyFraction);
	b_jetNeutralHadronEnergy->SetAddress(&jetNeutralHadronEnergy);
	b_jetNeutralHadronEnergyFraction->SetAddress(&jetNeutralHadronEnergyFraction);
	b_jetNConstituents->SetAddress(&jetNConstituents);
	b_jetChargedEmEnergy->SetAddress(&jetChargedEmEnergy);
	b_jetChargedEmEnergyFraction->SetAddress(&jetChargedEmEnergyFraction);
	b_jetChargedHadronEnergy->SetAddress(&jetChargedHadronEnergy);
	b_jetChargedHadronEnergyFraction->SetAddress(&jetChargedHadronEnergyFraction);
	b_jetChargedHadronMultiplicity->SetAddress(&jetChargedHadronMultiplicity);
	b_jetChargedMuEnergy->SetAddress(&jetChargedMuEnergy);
	b_jetChargedMuEnergyFraction->SetAddress(&jetChargedMuEnergyFraction);
	b_jetJVAlpha->SetAddress(&jetJVAlpha);
	b_jetJVBeta->SetAddress(&jetJVBeta);
	b_jetGenJetIndex->SetAddress(&jetGenJetIndex);
	b_jetGenJetEn->SetAddress(&jetGenJetEn);
	b_jetGenJetPt->SetAddress(&jetGenJetPt);
	b_jetGenJetEta->SetAddress(&jetGenJetEta);
	b_jetGenJetPhi->SetAddress(&jetGenJetPhi);
	b_jetGenJetMass->SetAddress(&jetGenJetMass);
	b_jetGenPartonID->SetAddress(&jetGenPartonID);
	b_jetGenPartonMomID->SetAddress(&jetGenPartonMomID);
	b_nZee->SetAddress(&nZee);
	b_ZeeMass->SetAddress(&ZeeMass);
	b_ZeePt->SetAddress(&ZeePt);
	b_ZeeEta->SetAddress(&ZeeEta);
	b_ZeePhi->SetAddress(&ZeePhi);
	b_ZeeLeg1Index->SetAddress(&ZeeLeg1Index);
	b_ZeeLeg2Index->SetAddress(&ZeeLeg2Index);
	b_nZmumu->SetAddress(&nZmumu);
	b_ZmumuMass->SetAddress(&ZmumuMass);
	b_ZmumuPt->SetAddress(&ZmumuPt);
	b_ZmumuEta->SetAddress(&ZmumuEta);
	b_ZmumuPhi->SetAddress(&ZmumuPhi);
	b_ZmumuLeg1Index->SetAddress(&ZmumuLeg1Index);
	b_ZmumuLeg2Index->SetAddress(&ZmumuLeg2Index);
	b_nWenu->SetAddress(&nWenu);
	b_WenuMassTCaloMET->SetAddress(&WenuMassTCaloMET);
	b_WenuEtCaloMET->SetAddress(&WenuEtCaloMET);
	b_WenuACopCaloMET->SetAddress(&WenuACopCaloMET);
	b_WenuMassTTcMET->SetAddress(&WenuMassTTcMET);
	b_WenuEtTcMET->SetAddress(&WenuEtTcMET);
	b_WenuACopTcMET->SetAddress(&WenuACopTcMET);
	b_WenuMassTPfMET->SetAddress(&WenuMassTPfMET);
	b_WenuEtPfMET->SetAddress(&WenuEtPfMET);
	b_WenuACopPfMET->SetAddress(&WenuACopPfMET);
	b_WenuEleIndex->SetAddress(&WenuEleIndex);
	b_nWmunu->SetAddress(&nWmunu);
	b_WmunuMassTCaloMET->SetAddress(&WmunuMassTCaloMET);
	b_WmunuEtCaloMET->SetAddress(&WmunuEtCaloMET);
	b_WmunuACopCaloMET->SetAddress(&WmunuACopCaloMET);
	b_WmunuMassTTcMET->SetAddress(&WmunuMassTTcMET);
	b_WmunuEtTcMET->SetAddress(&WmunuEtTcMET);
	b_WmunuACopTcMET->SetAddress(&WmunuACopTcMET);
	b_WmunuMassTPfMET->SetAddress(&WmunuMassTPfMET);
	b_WmunuEtPfMET->SetAddress(&WmunuEtPfMET);
	b_WmunuACopPfMET->SetAddress(&WmunuACopPfMET);
	b_WmunuMuIndex->SetAddress(&WmunuMuIndex);
//	==================================================================
	TRandom3* rr = new TRandom3();

	// //////////////// //
	// // Event Loop // //
	// //////////////// //

	int mcCounter = 0;
	int mceCounter = 0;
	int mcgCounter = 0;
	int mcCount = 0;
	int mcAllCount = 0;
//	bool checkallmc = true;

//	SINCE I AM USING UNBINNED LIKELIHOOD METHOD I CANNOT RESCALE HISTOGRAM I NEED TO HAVE RIGHT AMOUNT OF MC DATA TO COMPARE TO REAL DATA AT HAND
//	THESE NUMBERS ARE BASED ON THE INTEGRATED LUMINOSITY IN EACH SEGMENT (RUN A OR B, MUONS OR ELECTRONS) TIMES THE EVENT CROSSSECTION FROM MCFM
//	BUT TO USE THESE NUMBERS PLEASE REMOVE ANY SLECTION FROM SKIMMING PART. THSE ARE THE INITIAL INCOMMING EVENTS AS GENERATED (WITH GEMERATED CUTS)
//	if (doEEG && RunA) maxEvents = 27666;
//	if (doEEG && RunB) maxEvents = 33294;
//	if (doMMG && RunA) maxEvents = 29143;
//	if (doMMG && RunB) maxEvents = 33305;

	typedef vgamma::PhosphorCorrectionFunctor Corrector;
	Corrector getCorrectedPhotonPt_MC11A_ScaleSmeared(Corrector::kMonteCarloSmearedTo2011A, "");
	Corrector getCorrectedPhotonPt_MC11B_ScaleSmeared(Corrector::kMonteCarloSmearedTo2011B, "");

	vector<int> mcMuons;
	vector<int> mcElectrons;
	vector<int> mcLeptons;
	vector<int> mcPhotons;

	double LumiMuRunA = 2289.9;
	double LumiMuRunB = 2709.9;
	double LumiEleRunA = 2251.1;
	double LumiEleRunB = 2709.0;

	int minEvents = 0;
	int maxEvents = nEvents;

//	This only matters wheren runA and runB matters, thus in my case only for acceptance datasample - MG5_ISR_ONLY
/*
	if (doMMG && RunB) maxEvents = 150000;
	if (doMMG && RunA) {minEvents = 150000; maxEvents = 150000 + 150000 * LumiMuRunA / LumiMuRunB;}

	if (doEEG && RunB) maxEvents = 150000;
	if (doEEG && RunA) {minEvents = 150000; maxEvents = 150000 + 150000 * LumiEleRunA / LumiEleRunB;}
*/
//	this is to remove weird behaviour when populating trees with weights (it makes 2 trees if more then 490k)
//	apparantly I do not neet additional alyer of weights in any datasets other then ISR so I commended this line again
//	if (nEvents > 490000) maxEvents = 490000;

	minEvents = 0;
	maxEvents = nEvents;

	for (long index = minEvents; index < maxEvents; ++index )
		{
//		shows progress to keep awake
		if (index % 10000 == 0 )
			{
			float perc = float(index)*100./float(nEvents);
			printf("Processed Events\t%ld\t\t%.0f %%\n",index, perc);
			}
  
//		get current entry from the tree
		int  modeIn = getCorrectedPhotonPt_MC11B_ScaleSmeared.getMode();
		tr->GetEntry(index);
		int  modeOut = getCorrectedPhotonPt_MC11B_ScaleSmeared.getMode();

		if (modeIn != modeOut)
			{
			cout << "run = " << run << ", event = " << event << endl;
			cout << "Mammaaaaaaaaaaaaaa Miaaaaaa!!!!!!!!!!!!!!!" << endl;
			continue;
			}
		bool checkEvent = false;
		if (run == 1 && event == 8764 && lumis == 8) checkEvent = true;
		if (checkEvent) cout << "run : " << run << "; event : " << event << "; lumis : " << lumis << endl;

/*
//		search for dublicates, by default off
		bool isDub = false;
		if (CheckDub)
			{
			for (int iR = 0; iR < int(RUNS.size()); iR++)
				{
				cout << run << "\t" << lumis << "\t" << event << "\t" << RUNS.at(iR) << "\t" << LUMIS.at(iR) << "\t" << EVENTS.at(iR) << "\t" << endl;
				if (run   == RUNS.at(iR) && lumis == LUMIS.at(iR) && event == EVENTS.at(iR))
				isDub = true;
				}
			if (isDub) continue;
			}
*/
//		which value to fill in counter histrogram (nPassed) first
		int passBin = 1;
		if (checkEvent) cout << " : : CHECK POINT!" << endl;
		fillNPassed(passBin,nPassed,nPassedMap,"CHECK POINT");

//		========================================================================================
//		GENERATED LEVEL PARTICLES
		bool ismcCut = true;
		bool blepPt = false;
		bool blep1Eta = false;
		bool blep2Eta = false;
		bool bphoEt = false;
		bool bphoEta = false;
		bool bdR = false;
		bool bMass = false;

		for (int iMc = 0; iMc < nMC; iMc++)
			{
			if (	TMath::Abs(mcPID[iMc]) == 13	&&
				TMath::Abs(mcGMomPID[iMc]) < 30 &&
				TMath::Abs(mcGMomPID[iMc])!= 15 &&
				TMath::Abs(mcMomPID[iMc]) != 15 &&
				TMath::Abs(mcMomPID[iMc]) < 30
				) mcMuons.push_back(iMc);
			if (	TMath::Abs(mcPID[iMc])    == 11 &&
				TMath::Abs(mcGMomPID[iMc]) < 30 &&
				TMath::Abs(mcGMomPID[iMc])!= 15 &&
				TMath::Abs(mcMomPID[iMc]) != 15 &&
				TMath::Abs(mcMomPID[iMc])  < 30
				) mcElectrons.push_back(iMc);
	  		if ( TMath::Abs(mcPID[iMc]) == 22 ) mcPhotons.push_back(iMc);
			}

		if (mcMuons.size() > 1)		{mcLeptons = mcMuons; mcCounter++;}
		if (mcElectrons.size() > 1)	{mcLeptons = mcElectrons; mceCounter++;}
		if (mcPhotons.size() != 0)	mcgCounter++;

		if (mcLeptons.size() > 1 && mcPhotons.size() != 0  && mcCount < 70000000)
			{
			int mcLep1 = mcLeptons.at(0);
			int mcLep2 = mcLeptons.at(1);

			if (mcPID[mcLep1] + mcPID[mcLep2] != 0) { cout<< "THERE ARE SAME SIGN LEPTONS IN GEN!!!" << endl; continue;}

			if (mcPID[mcLep1] > 0)
				{
				int temp = mcLep2;
				mcLep2 = mcLep1;
				mcLep1 = temp;
				}

			int mcPho = mcPhotons.at(0);

//			cout << mcPt[mcLep1] << "\t" << mcMass[mcLep1] << endl;

			mclep1.SetPtEtaPhiM(mcPt[mcLep1],mcEta[mcLep1],mcPhi[mcLep1],mcMass[mcLep1]);
			mclep2.SetPtEtaPhiM(mcPt[mcLep2],mcEta[mcLep2],mcPhi[mcLep2],mcMass[mcLep2]);
			mcGamma.SetPtEtaPhiM(mcPt[mcPho],mcEta[mcPho],mcPhi[mcPho],0);

			mcAngleMap = zgammaAngleCalculator(mclep1, mclep2, mcGamma);
			TmcangleMap["cosThetaL"] = mcAngleMap["cosThetaL"];
			TmcangleMap["thetaL"] = mcAngleMap["thetaL"];
			TmcangleMap["cosThetaZ"] = mcAngleMap["cosThetaZ"];
			TmcangleMap["thetaZ"] = mcAngleMap["thetaZ"];
			TmcangleMap["phiL"] = mcAngleMap["phiL"];
			TmcangleMap["phiZ"] = mcAngleMap["phiZ"];

			mcll = mclep1 + mclep2;
			TmcangleMap["ZMass"] = mcll.M();
//			if (mcll.M() < 40) cout << mclep1.Px() << " - " << mclep2.Px() << endl;
//			cout << mcll.M() << " : " << mclep1.Px() << "\t" << mclep1.Py() << "\t" << mclep1.Pz() << "\t" << mclep1.Pt() << "\t" << mclep1.E() << endl;
			mcllg = mcll + mcGamma;
			TmcangleMap["ZGMass"] = mcllg.M();

//			FILL HISTOGRAMS
//			if ((mcllg.M() + mcll.M()) > 200 && mcll.M() > 50)
//			remove this if there is no cut on gen particles and put "if" that is in above line
//			if ((mcllg.M() + mcll.M()) > 200 && mclep1.Pt() > 5)
//				{
				MC_cosThetaL->Fill(mcAngleMap["cosThetaL"]);
				MC_thetaL->Fill(mcAngleMap["thetaL"]);
				MC_cosThetaZ->Fill(mcAngleMap["cosThetaZ"]);
				MC_thetaZ->Fill(mcAngleMap["thetaZ"]);

				MC_cosThetaZ_L->Fill(mcAngleMap["cosThetaL"],mcAngleMap["cosThetaZ"]);
				MC_phiL->Fill(mcAngleMap["phiL"]);
				MC_phiZ->Fill(mcAngleMap["phiZ"]);
				mcoutTree->Fill();

				if (fabs(mcAngleMap["cosThetaZ"]) < 0.1) MC_goodPhoEta->Fill(mcEta[mcPho]);

				mcCount++;
				_genPhoEt->Fill(mcGamma.Et());
				_genLepPt->Fill(mclep1.Pt());
//				}
//			else MC_cosThetaL_FSR->Fill(mcAngleMap["cosThetaL"]);

			cosThetaZ_phoEta->Fill(mcAngleMap["cosThetaZ"], mcEta[mcPho]);

//			===================================================================================================
//			SELECTION CRITERIA ON GEN PARTICLES SAME AS FOR RECO
//			===================================================================================================
			if (doEEG)
				{
				if (mclep1.Pt() < lepPtCut || mclep2.Pt() < lepPtCut) ismcCut = false;
				if (fabs(mclep1.PseudoRapidity()) > 2.5 || ( fabs(mclep1.PseudoRapidity()) > 1.4442 && fabs(mclep1.PseudoRapidity()) < 1.566) ) ismcCut = false;
				if (fabs(mclep2.PseudoRapidity()) > 2.5 || ( fabs(mclep2.PseudoRapidity()) > 1.4442 && fabs(mclep2.PseudoRapidity()) < 1.566) ) ismcCut = false;
				}
  
			if (doMMG)
				{
//				if(mcIsoDR04[mcLep1] >= (0.1 * mclep1.Pt())) ismcCut = false;
//				if(mcIsoDR04[mcLep2] >= (0.1 * mclep2.Pt())) ismcCut = false;

				if (mclep1.Pt() < lepPtCut || mclep2.Pt() < lepPtCut) 
					{
					ismcCut = false;
					blepPt = true;
					}
				if ( fabs(mclep1.PseudoRapidity()) > 2.4 )
					{
					ismcCut = false;
					blep1Eta = true;
					}
				if ( fabs(mclep2.PseudoRapidity()) > 2.4 )
					{
					ismcCut = false;
					blep2Eta = true;
					}
				}

			if (mcGamma.Pt() < phoEtCut)
				{
				ismcCut = false;
				bphoEt = true;
				}
			if (fabs(mcGamma.PseudoRapidity()) > 2.5 || (fabs(mcGamma.PseudoRapidity()) > 1.4442 && fabs(mcGamma.PseudoRapidity()) < 1.566))
				{
				ismcCut = false;
				bphoEta = true;
				}

			float MC_dR1 = -1;
			float MC_dR2 = -1;

			MC_dR1 = reco::deltaR( mcGamma.PseudoRapidity(), mcGamma.Phi(), mclep1.PseudoRapidity(), mclep1.Phi());
			MC_dR2 = reco::deltaR( mcGamma.PseudoRapidity(), mcGamma.Phi(), mclep2.PseudoRapidity(), mclep2.Phi());

			if (MC_dR1 <= dRcut || MC_dR2 <= dRcut)
				{
				ismcCut = false;
				bdR = true;
				}

			if ((mcllg.M() + mcll.M()) < 200 || mcll.M() < 50)
				{
				ismcCut = false;
				bMass = true;
				}

			if (ismcCut)
				{
//				mcCutAngleMap = zgammaAngleCalculator(mclep1, mclep2, mcGamma);
/*
				TmcCutangleMap["cosThetaL"] = mcAngleMap["cosThetaL"];
				TmcCutangleMap["thetaL"] = mcAngleMap["thetaL"];
				TmcCutangleMap["cosThetaZ"] = mcAngleMap["cosThetaZ"];
				TmcCutangleMap["thetaZ"] = mcAngleMap["thetaZ"];
				TmcCutangleMap["phiL"] = mcAngleMap["phiL"];
				TmcCutangleMap["phiZ"] = mcAngleMap["phiZ"];

				TmcCutangleMap["ZMass"] = mcll.M();
				TmcCutangleMap["ZGMass"] = mcllg.M();
*/
				MCCut_cosThetaL->Fill(mcAngleMap["cosThetaL"]);
				MCCut_cosThetaZ->Fill(mcAngleMap["cosThetaZ"]);
				MCCut_phiL->Fill(mcAngleMap["phiL"]);
				MCCut_phiZ->Fill(mcAngleMap["phiZ"]);
				MCCut_cosThetaZ_L->Fill(mcAngleMap["cosThetaL"], mcAngleMap["cosThetaZ"]);

//				mcCutoutTree->Fill();
				}
//			===================================================================================================
			} // if two electrons and one photon exist in the event

		mcMuons.clear();
		mcElectrons.clear();
		mcLeptons.clear();
		mcPhotons.clear();

//		if (checkallmc && mcCount == 10000) { mcAllCount = index; checkallmc = false; }
		mcAllCount = index+1;
// =======================================================================================


//		DEBUG BULEANS
		bool enCorrection = true;

//		if (nJet != 0) continue;
//		fillNPassed(passBin,nPassed,nPassedMap,"No Jets");

		if (nVtx == 0) continue;
		fillNPassed(passBin,nPassed,nPassedMap,"any Vertex");
		if (checkEvent) cout << " : : Any Vertex!" << endl;
  
		nGoodVtx = 0;
		for (int iVtx = 0; iVtx <= nVtx; iVtx++)
			if (vtxNDF[iVtx] >= 4 && fabs(vtx[iVtx][2]) <= 24 && fabs(vtxD0[iVtx]) <= 2) nGoodVtx++;
		if (nGoodVtx == 0) continue;
//		if (IsVtxGood == 0) continue;
		fillNPassed(passBin,nPassed,nPassedMap,"good Vertex");
		if (checkEvent) cout << " : : Good Vertex!" << endl;
  
		if (IsTracksGood ==0 ) continue;
		fillNPassed(passBin,nPassed,nPassedMap,"good Tracks");
		if (checkEvent) cout << " : : Good Tracks!" << endl;

		vector<int> cleanPho;
		vector<int> cleanDRPho;
		vector<int> cleanEle;
		vector<int> cleanMu;
		vector<int> goodPho;
		vector<int> goodLep;

//		clean photon selection -------------------------------------------------------
		for (int iPho = 0; iPho < nPho; iPho++)
			{
			float genEta = 0;
			float genPt = -1;
			float genEn = -1;
			int genPhotonNumber = -1;
			for (int iG = 0; iG < nMC; iG++)
				if (phoGenIndex[iPho] == mcIndex[iG])
					{
					genPhotonNumber = iG;
					genPt  = mcPt [iG];
					genEta = mcEta[iG];
					}
			if (genPt > 0) genEn = genPt*TMath::CosH(genEta);

			double tempEt = phoEt[iPho];

			if (enCorrection)
				{
				if (RunA) phoEt[iPho] = getCorrectedPhotonPt_MC11A_ScaleSmeared(phoEt[iPho], phoEta[iPho], genEn);
				if (RunB) phoEt[iPho] = getCorrectedPhotonPt_MC11B_ScaleSmeared(phoEt[iPho], phoEta[iPho], genEn);
				}

			double correctionFactor = phoEt[iPho] / tempEt;
			if (enCorrection) phoE[iPho] *= correctionFactor;

			if (checkEvent) cout << " - - Et = " << phoEt[iPho] << "; iPho = " << iPho << endl;
			if (checkEvent) cout << " - - eta = " << fabs(phoSCEta[iPho]) << "; iPho = " << iPho << endl;

//			ET cut
			if (phoEt[iPho] < phoEtCut) continue;
			if (checkEvent) cout << " : : Et Cut!" << endl;
			if (fabs(phoSCEta[iPho])> 2.5) continue;
			if (checkEvent) cout << " : : Eta Cut 1!" << endl;
			if (fabs(phoSCEta[iPho]) > 1.4442 && fabs(phoSCEta[iPho]) < 1.566 ) continue;
			if (checkEvent) cout << " : : Eta Cut 2!" << endl;
			if (phoHoverE[iPho] > 0.5 ) continue;
			if (checkEvent) cout << " : : H over E!" << endl;



//			for Zjets remove ISR/FSR photons, for signal keep only mc matched photons
			if (matchMC)
				{
				if (removeMcPhoJ)
					{
					if(	(TMath::Abs(phoGenMomPID[iPho])==11	||
						TMath::Abs(phoGenMomPID[iPho])==13	||
						TMath::Abs(phoGenMomPID[iPho])==15)	&&
						(TMath::Abs(phoGenGMomPID[iPho])==11	||
						TMath::Abs(phoGenGMomPID[iPho])==13	||
						TMath::Abs(phoGenGMomPID[iPho])==15))   continue;

					if (	(TMath::Abs(phoGenMomPID[iPho])	== 11	||
						TMath::Abs(phoGenMomPID[iPho])	== 13	||
						TMath::Abs(phoGenMomPID[iPho])	== 15)	&&
						(TMath::Abs(phoGenGMomPID[iPho])== 23	||
						TMath::Abs(phoGenGMomPID[iPho])	== 24))	continue;

					if (	phoGenMomPID[iPho]		== 21	||
						TMath::Abs(phoGenMomPID[iPho])	<  7)	continue;
					}
				} //matchMC

			if (phohasPixelSeed[iPho] == 1) continue;
			if (checkEvent) cout << " : : No Pixel Seeds!" << endl;
			cleanPho.push_back(iPho);
			}

		if (cleanPho.size()==0) continue;
		fillNPassed(passBin,nPassed,nPassedMap,"at least 1 clean photon");

//		------------------------------------------------------------------------------
		if (doEEG)
			for (int iEle=0; iEle < nEle; iEle++)
				{
				float eleR9 = eleE3x3[iEle] / eleSCRawEn[iEle];
				double tempE = eleEn[iEle];
				if(enCorrection) eleEn[iEle] = corrVgamma(eleEn[iEle], eleSCEta[iEle], eleR9, rr, run, event);
				double correctionFactor = eleEn[iEle] / tempE;
				if(enCorrection) elePt[iEle] *= correctionFactor; 

				if (elePt[iEle] < lepPtCut) continue;
				if (checkEvent) cout << " : : Electron Pt Cut!" << endl;

				if (fabs(eleSCEta[iEle]) > 2.5 || ( fabs(eleSCEta[iEle]) > 1.4442 && fabs(eleSCEta[iEle]) < 1.566) ) continue;
				if (checkEvent) cout << " : : Electron Eta Cut!" << endl;

				cleanEle.push_back(iEle);
				}
  
		if (doMMG)
			for (int iMu=0; iMu < nMu; iMu++)
				{
				if (checkEvent) cout << " - - muPt = " << muPt[iMu] << endl;
				if (muPt[iMu] < lepPtCut) continue;
				if (checkEvent) cout << " : : Muon Pt Cut!" << endl;
				if ( fabs(muEta[iMu]) > 2.4 ) continue;
				if (checkEvent) cout << " : : Muon Eta Cut!" << endl;
				if ( muType[iMu] != 14) continue; // isGlobal && Tracker
				if (checkEvent) cout << " : : Muon Is Global Cut!" << endl;
				cleanMu.push_back(iMu);
				}

		if (doEEG && cleanEle.size()<2) continue;
		if (doMMG && cleanMu.size()<2) continue;
		if (checkEvent) cout << " : : Two leptons selected!" << endl;

		fillNPassed(passBin,nPassed,nPassedMap,"at least 2 clean leptons");
  
		if (doEEG)
			for ( vector<int>::iterator it = cleanEle.begin(); it != cleanEle.end(); it++)
				{
				_cleanLepPt->Fill(elePt[*it]);
				bool pass = electronId(	elePVD0[*it], elePVDz[*it],
							eleIsoHcalSolidDR03[*it],
							eleSCEta[*it],
							rho,
							eleIsoTrkDR03[*it],
							eleIsoEcalDR03[*it],
							elePt[*it],
							eledPhiAtVtx[*it],
							eledEtaAtVtx[*it],
							eleSigmaIEtaIEta[*it],
							run,
							event);

				if (!pass) continue;
				if (checkEvent) cout << " : : Electron ID!" << endl;
				_goodLepPt->Fill(elePt[*it]);

				int ind1 = HLTIndex[83];
				int ind2 = HLTIndex[86];

				bool eleTrigger1 = false; 
				bool eleTrigger2 = false; 

				if (ind1 >= 0 && HLTprescale[ind1] == 1) eleTrigger1 = (eleTrg[*it][18] > 0);
				if (ind2 >= 0 && HLTprescale[ind2] == 1) eleTrigger2 = (eleTrg[*it][21] > 0);


				if (!(eleTrigger1 || eleTrigger2)) continue;
				if (checkEvent) cout << " : : Electron HLT!" << endl;
//				Conversion Rejection 	  	  	  	  	  	 
				if (!(eleConvMissinghit[*it] == 0 && (fabs(eleConvDist[*it]) > 0.02 || fabs(eleConvDcot[*it]) > 0.02))) continue;
				if (checkEvent) cout << " : : Electron Rejection!" << endl;

				goodLep.push_back(*it);
				}

		if (doMMG)
			for ( vector<int>::iterator it = cleanMu.begin(); it != cleanMu.end(); it++)
				{
				_cleanLepPt->Fill(muPt[*it]);
				bool pass = muonId(	muPVD0[*it], muPVDz[*it],
							muChi2NDF[*it], muStations[*it],
							muNumberOfValidPixelHits[*it],
							muNumberOfValidTrkHits[*it],
							muNumberOfValidMuonHits[*it],
							muIsoEcal[*it],muIsoHcal[*it],muIsoTrk[*it],
							muPt[*it], rho);
				if (!pass) continue;
				if (checkEvent) cout << " : : Muon ID!" << endl;

//				HLT Trigger Matching for Muons
				int ind1 = HLTIndex[72];
				int ind2 = HLTIndex[73];
				int ind3 = HLTIndex[74];

				bool mTrigger1 = false;
				bool mTrigger2 = false;
				bool mTrigger3 = false;

				if (ind1 >= 0 && HLTprescale[ind1] == 1) mTrigger1 = (muTrg[*it][13] > 0);
				if (ind2 >= 0 && HLTprescale[ind2] == 1) mTrigger2 = (muTrg[*it][14] > 0);
				if (ind3 >= 0 && HLTprescale[ind3] == 1) mTrigger3 = (muTrg[*it][15] > 0);

				bool mTrigger = (mTrigger1 || mTrigger2 || mTrigger3 );
				if (!mTrigger) continue;
				if (checkEvent) cout << " : : Muon HLT!" << endl;

				_goodLepPt->Fill(muPt[*it]);
				goodLep.push_back(*it);
				}
  
		if ( goodLep.size() < 2 ) continue;
		if (checkEvent) cout << " : : Good Leptons!" << endl;
		fillNPassed(passBin,nPassed,nPassedMap,"required 2 good leptons");
  
		int lep1ind  = int (goodLep.at(0));
		int lep2ind  = int (goodLep.at(1));

		if (doEEG)
			{
			if (eleCharge[lep1ind] + eleCharge[lep2ind] != 0) continue;
			fillNPassed(passBin,nPassed,nPassedMap,"leptons with opposite charge");
			if (eleCharge[lep1ind] == 1)
				{
				lep1.SetPtEtaPhiE(elePt[lep1ind],eleEta[lep1ind],elePhi[lep1ind],eleEn[lep1ind]);
				lep2.SetPtEtaPhiE(elePt[lep2ind],eleEta[lep2ind],elePhi[lep2ind],eleEn[lep2ind]);
				}
			else
				{
				lep2.SetPtEtaPhiE(elePt[lep1ind],eleEta[lep1ind],elePhi[lep1ind],eleEn[lep1ind]);
				lep1.SetPtEtaPhiE(elePt[lep2ind],eleEta[lep2ind],elePhi[lep2ind],eleEn[lep2ind]);
				}
			}
		if (doMMG)
			{
			if (muCharge[lep1ind] + muCharge[lep2ind] != 0) continue;
			fillNPassed(passBin,nPassed,nPassedMap,"leptons with opposite charge");
			float muEn1 = sqrt(muPt[lep1ind]*muPt[lep1ind] + muPz[lep1ind]*muPz[lep1ind]);
			float muEn2 = sqrt(muPt[lep2ind]*muPt[lep2ind] + muPz[lep2ind]*muPz[lep2ind]);
			if (muCharge[lep1ind] == 1)
				{
				lep1.SetPtEtaPhiE(muPt[lep1ind],muEta[lep1ind],muPhi[lep1ind],muEn1);
				lep2.SetPtEtaPhiE(muPt[lep2ind],muEta[lep2ind],muPhi[lep2ind],muEn2);
				}
			else
				{
				lep2.SetPtEtaPhiE(muPt[lep1ind],muEta[lep1ind],muPhi[lep1ind],muEn1);
				lep1.SetPtEtaPhiE(muPt[lep2ind],muEta[lep2ind],muPhi[lep2ind],muEn2);
				}
			}
		ll = lep1+lep2;

		ZMass_noPho->Fill(ll.M());

		double Weight = 1;

		for (int pho=0; pho <  int (cleanPho.size()); pho++)
			{
			int phoind = cleanPho.at(pho);
			float dR1 = -1;
			float dR2 = -1;
			if (doEEG)
				{
				dR1 = reco::deltaR( phoEta[phoind], phoPhi[phoind], eleEta[lep1ind], elePhi[lep1ind]);
				dR2 = reco::deltaR( phoEta[phoind], phoPhi[phoind], eleEta[lep2ind], elePhi[lep2ind]);
				}
			if (doMMG)
				{
				dR1 = reco::deltaR( phoEta[phoind], phoPhi[phoind], muEta[lep1ind], muPhi[lep1ind]);
				dR2 = reco::deltaR( phoEta[phoind], phoPhi[phoind], muEta[lep2ind], muPhi[lep2ind]);
				}
			if (dR1 > dRcut && dR2 > dRcut) cleanDRPho.push_back(phoind);
			}
  
		if (cleanDRPho.size()==0) continue;
		if (checkEvent) cout << " : : Photon DR Cut!" << endl;

		fillNPassed(passBin,nPassed,nPassedMap,"at least 1 pho > dR");

		int clPhoInd = cleanDRPho.at(0);
		_photonEt->Fill		(phoEt[clPhoInd]);
		_photonEta->Fill	(phoEta[clPhoInd]);
		_photonPhi->Fill	(phoPhi[clPhoInd]);
		_photonHoE->Fill	(phoHoverE[clPhoInd]);
		_photonSigIEIE->Fill	(phoSigmaIEtaIEta[ clPhoInd]);
		_photonEcalIso->Fill	(phoEcalIsoDR04[clPhoInd]);
		_photonHcalIso->Fill	(phoHcalIsoDR04[clPhoInd]);
		_photonTrkIso->Fill	(phoTrkIsoHollowDR04[clPhoInd]);
  
		for (int pho=0; pho <  int (cleanDRPho.size()); pho++)
			{
			int phoind = cleanDRPho.at(pho);
			if (photonID >= 0)
				{
				bool photonPass = false;
				photonPass = photonId(	phoEcalIsoDR04[phoind], phoHcalIsoDR04[phoind],
							phoTrkIsoHollowDR04[phoind], phoSCEta[phoind],
							phoHoverE[phoind], phoSigmaIEtaIEta[phoind],
							phoEt[phoind], rho);
				if (!photonPass) continue;
				}
			goodPho.push_back(phoind);
			}
  
		if (goodPho.size()==0) continue;
		if (checkEvent) cout << " : : Good Photon!" << endl;
		fillNPassed(passBin,nPassed,nPassedMap,"at least 1 good photon");

		int phoind = goodPho.at(0);
		gamma.SetPtEtaPhiE(phoEt[phoind],phoEta[phoind],phoPhi[phoind],phoE[phoind]);

		_goodPhoEta->Fill(phoEta[phoind]);

		llg = ll+gamma;
		if (ll.M() < 50) continue;
		if (checkEvent) cout << " : : MZ > 50!" << endl;
		fillNPassed(passBin,nPassed,nPassedMap,"ZMass < 50");

		if (checkEvent) cout << "  ======= EVENT SELECTED ======== " << endl;

//		ANGLE CALCULATIONS
		angleMap = zgammaAngleCalculator(lep1, lep2, gamma);
		TangleMap["cosThetaL"] = angleMap["cosThetaL"];
		TangleMap["thetaL"] = angleMap["thetaL"];
		TangleMap["cosThetaZ"] = angleMap["cosThetaZ"];
		TangleMap["thetaZ"] = angleMap["thetaZ"];
		TangleMap["phiL"] = angleMap["phiL"];
		TangleMap["phiZ"] = angleMap["phiZ"];
		TangleMap["ZMass"] = ll.M();
		TangleMap["ZGMass"] = llg.M();


		if ((llg.M() + ll.M()) < 200)
			{
			_cosThetaL_FSR->Fill(angleMap["cosThetaL"]);
			continue;
			}
		fillNPassed(passBin,nPassed,nPassedMap,"ZgammaMass + ZMass > 200");

//		REWEIGHTING BY leptonID, photon, pixel seed, 3D pileup and muon tirgger Scale Factors =======================
//		Electron SF ------------------------------------------------------------------------------------------
		if (doEEG)
			{
//			ElectronId SF
			TH2F * eleIDSFa_EB = (TH2F*)eleIDScaleFactorA->Get("eleSF_EB");
			TH2F * eleIDSFa_EE = (TH2F*)eleIDScaleFactorA->Get("eleSF_EE");
			TH2F * eleIDSFb_EB = (TH2F*)eleIDScaleFactorB->Get("eleSF_EB");
			TH2F * eleIDSFb_EE = (TH2F*)eleIDScaleFactorB->Get("eleSF_EE");

			double Weight1 = 1.;
			double Weight2 = 1.;

			if (RunA)
				{
				if (eleSCEta[lep1ind] < 1.4442)
					Weight1 = getWeightFromPtVtxSF(elePt[lep1ind], nGoodVtx, eleIDSFa_EB);
				else Weight1 = getWeightFromPtVtxSF(elePt[lep1ind], nGoodVtx, eleIDSFa_EE);
				if (eleSCEta[lep2ind] < 1.4442)
					Weight2 = getWeightFromPtVtxSF(elePt[lep2ind], nGoodVtx, eleIDSFa_EB);
				else Weight2 = getWeightFromPtVtxSF(elePt[lep2ind], nGoodVtx, eleIDSFa_EE);
				}
			if (RunB)
				{
				if (eleSCEta[lep1ind] < 1.4442)
					Weight1 = getWeightFromPtVtxSF(elePt[lep1ind], nGoodVtx, eleIDSFb_EB);
				else Weight1 = getWeightFromPtVtxSF(elePt[lep1ind], nGoodVtx, eleIDSFb_EE);
				if (eleSCEta[lep2ind] < 1.4442)
					Weight2 = getWeightFromPtVtxSF(elePt[lep2ind], nGoodVtx, eleIDSFb_EB);
				else Weight2 = getWeightFromPtVtxSF(elePt[lep2ind], nGoodVtx, eleIDSFb_EE);
				}

			Weight = Weight * Weight1 * Weight2;

//			electron RECO SF
			TH2F * eleRECOSFa_EB = (TH2F*)eleRECOScaleFactorA->Get("BarrelSF");
			TH2F * eleRECOSFa_EE = (TH2F*)eleRECOScaleFactorA->Get("EndcapSF");
			TH2F * eleRECOSFb_EB = (TH2F*)eleRECOScaleFactorB->Get("BarrelSF");
			TH2F * eleRECOSFb_EE = (TH2F*)eleRECOScaleFactorB->Get("EndcapSF");

			if (RunA)
				{
				if (eleSCEta[lep1ind] < 1.4442)
//					RECENT CHANGE - NOTICED A PRIBLEM WHEN WRITING THESIS - IF SOMEHOW OLD VERSION WAS RIGH FIX IT EVERYWHERE BELOW
//					Weight1 = getWeightFromPtVtxSF(nGoodVtx, elePt[lep1ind], eleRECOSFa_EB);
					Weight1 = getWeightFromPtVtxSF(elePt[lep1ind], nGoodVtx, eleRECOSFa_EB);
				else Weight1 = getWeightFromPtVtxSF(elePt[lep1ind], nGoodVtx, eleRECOSFa_EE);
				if (eleSCEta[lep2ind] < 1.4442) Weight2 = getWeightFromPtVtxSF(elePt[lep2ind], nGoodVtx, eleRECOSFa_EB);
				else Weight2 = getWeightFromPtVtxSF(elePt[lep2ind], nGoodVtx, eleRECOSFa_EE);
				}
			if (RunB)
				{
				if (eleSCEta[lep1ind] < 1.4442) Weight1 = getWeightFromPtVtxSF(elePt[lep1ind], nGoodVtx, eleRECOSFb_EB);
				else Weight1 = getWeightFromPtVtxSF(elePt[lep1ind], nGoodVtx, eleRECOSFb_EE);
				if (eleSCEta[lep2ind] < 1.4442) Weight2 = getWeightFromPtVtxSF(elePt[lep2ind], nGoodVtx, eleRECOSFb_EB);
				else Weight2 = getWeightFromPtVtxSF(elePt[lep2ind], nGoodVtx, eleRECOSFb_EE);
				}

			Weight = Weight * Weight1 * Weight2;

//			Electron HF SF
			TH2F * eleHLTSFa_EB = (TH2F*)eleHLTScaleFactorA->Get("eleSF_EB");
			TH2F * eleHLTSFa_EE = (TH2F*)eleHLTScaleFactorA->Get("eleSF_EE");
			TH2F * eleHLTSFb_EB = (TH2F*)eleHLTScaleFactorB->Get("eleSF_EB");
			TH2F * eleHLTSFb_EE = (TH2F*)eleHLTScaleFactorB->Get("eleSF_EE");

			if (RunA)
				{
				if (eleSCEta[lep1ind] < 1.4442)
					Weight1 = getWeightFromPtVtxSF(elePt[lep1ind], nGoodVtx, eleHLTSFa_EB);
				else Weight1 = getWeightFromPtVtxSF(elePt[lep1ind], nGoodVtx, eleHLTSFa_EE);
				if (eleSCEta[lep2ind] < 1.4442)
					Weight2 = getWeightFromPtVtxSF(elePt[lep2ind], nGoodVtx, eleHLTSFa_EB);
				else Weight2 = getWeightFromPtVtxSF(elePt[lep2ind], nGoodVtx, eleHLTSFa_EE);
				}
			if (RunB)
				{
				if (eleSCEta[lep1ind] < 1.4442)
					Weight1 = getWeightFromPtVtxSF(elePt[lep1ind], nGoodVtx, eleHLTSFb_EB);
				else Weight1 = getWeightFromPtVtxSF(elePt[lep1ind], nGoodVtx, eleHLTSFb_EE);
				if (eleSCEta[lep2ind] < 1.4442)
					Weight2 = getWeightFromPtVtxSF(elePt[lep2ind], nGoodVtx, eleHLTSFb_EB);
				else Weight2 = getWeightFromPtVtxSF(elePt[lep2ind], nGoodVtx, eleHLTSFb_EE);
				}

			Weight = Weight * Weight1 * Weight2;
			}
//		-----------------------------------------------------------------------------------------------------
		if (doMMG)
			{
//			MuonId SF
//			isolation scale factor
			TH2F * muIDSFa = (TH2F*)muIDScaleFactorA->Get("muonSF");
			TH2F * muIDSFb = (TH2F*)muIDScaleFactorB->Get("muonSF");

			double Weight1 = 1.;
			double Weight2 = 1.;
			if (RunA)
				{
//				RECENT CHANGE - NOTICED A PRIBLEM WHEN WRITING THESIS
				Weight1 = getWeightFromPtVtxSF(muPt[lep1ind], muEta[lep1ind], muIDSFa);
				Weight2 = getWeightFromPtVtxSF(muPt[lep2ind], muEta[lep2ind], muIDSFa);

//				Weight1 = getWeightFromPtVtxSF(muPt[lep1ind],nGoodVtx,muIDSFa);
//				Weight2 = getWeightFromPtVtxSF(muPt[lep2ind],nGoodVtx,muIDSFa);
				}
			if (RunB)
				{
				Weight1 = getWeightFromPtVtxSF(muPt[lep1ind], muEta[lep1ind], muIDSFb);
				Weight2 = getWeightFromPtVtxSF(muPt[lep2ind], muEta[lep2ind], muIDSFb);

//				Weight1 = getWeightFromPtVtxSF(muPt[lep1ind],nGoodVtx,muIDSFb);
//				Weight2 = getWeightFromPtVtxSF(muPt[lep2ind],nGoodVtx,muIDSFb);
				}

			Weight = Weight * Weight1 * Weight2 ;
/*
//			Muon Trigger SF
			TH1F * muTrigSFa = (TH1F*)muTrigSF->Get("rhoA");
			TH1F * muTrigSFb = (TH1F*)muTrigSF->Get("rhoB");

			if (RunA)
				{
				Weight1 = getWeightFromEtaSF(muEta[lep1ind],muTrigSFa);
				Weight2 = getWeightFromEtaSF(muEta[lep2ind],muTrigSFa);
				}
			if (RunB)
				{
				Weight1 = getWeightFromEtaSF(muEta[lep1ind],muTrigSFb);
				Weight2 = getWeightFromEtaSF(muEta[lep2ind],muTrigSFb);
				}
*/
			Weight = Weight * Weight1 * Weight2;
			}
//		COMMON SCALE FACTORS ===============================================================
//		Pixel Seed Veto SF
		if (RunA)
			{
			if (fabs(phoSCEta[phoind]) < 1.4442 ) Weight = Weight * 0.994;
			else Weight = Weight * 0.989;
			}
		else
			{
			if (fabs(phoSCEta[phoind]) < 1.4442 ) Weight = Weight * 0.990;
			else Weight = Weight * 0.978;
			}

//		3D PILEUP REWEIGHTING ----------------------------------------
		TH3D* dataPileUpDistRunA_3D = (TH3D*)dataPuFileRunA_3D->Get("WHist");
		TH3D* dataPileUpDistRunB_3D = (TH3D*)dataPuFileRunB_3D->Get("WHist");

		if (RunA) Weight = Weight * dataPileUpDistRunA_3D->GetBinContent(nPU[0]+1,nPU[1]+1,nPU[2]+1);
		if (RunB) Weight = Weight * dataPileUpDistRunB_3D->GetBinContent(nPU[0]+1,nPU[1]+1,nPU[2]+1);
//		--------------------------------------------------------------
//		photon SF
		TFile * photonEBSF;
		TFile * photonEESF;

		if (RunA)
			{
			photonEBSF = TFile::Open("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/eleSF/runA_photonId_EBEffsSF.root","READ");
			photonEESF = TFile::Open("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/eleSF/runA_photonId_EEEffsSF.root","READ");
			}
		if (RunB)
			{
			photonEBSF = TFile::Open("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/eleSF/runB_photonId_EBEffsSF.root","READ");
			photonEESF = TFile::Open("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/eleSF/runB_photonId_EEEffsSF.root","READ");
			}

		TH2F * phoEBSF = (TH2F*)photonEBSF->Get("BarrelSF");
		TH2F * phoEESF = (TH2F*)photonEESF->Get("EndcapSF");


		if (fabs(phoSCEta[phoind]) < 1.45)
			{
			int puMaxBin = phoEBSF->GetXaxis()->GetNbins();
			int puBin = phoEBSF->GetXaxis()->FindBin(nGoodVtx);
			if (puBin > puMaxBin) puBin = puMaxBin;
			if (puBin < 1) puBin = 1;
			int ptMaxBin = phoEBSF->GetYaxis()->GetNbins();
			int ptBin = phoEBSF->GetYaxis()->FindBin(phoEt[phoind]);
			if (ptBin > ptMaxBin) ptBin = ptMaxBin;
			if (ptBin < 1) ptBin = 1;
			Weight = Weight * phoEBSF->GetBinContent(puBin,ptBin);
			}
		else
			{
			int puMaxBin = phoEESF->GetXaxis()->GetNbins();
			int puBin = phoEESF->GetXaxis()->FindBin(nGoodVtx);
			if (puBin > puMaxBin) puBin = puMaxBin;
			if (puBin<1) puBin=1;
			int ptMaxBin = phoEESF->GetYaxis()->GetNbins();
			int ptBin = phoEESF->GetYaxis()->FindBin(phoEt[phoind]);
			if (ptBin > ptMaxBin) ptBin = ptMaxBin;
			if (ptBin<1) ptBin=1;
			Weight = Weight * phoEESF->GetBinContent(puBin,ptBin);
			}
		photonEBSF->Close();
		photonEESF->Close();
//		=============================================================================

		f_out->cd();
		weight = Weight;

//		COMMENT THIS if you want all the reweighting; I put this here to remove reweighting and work on pure MC // IRAKLI
//		Weight = 1;

//		fprintf(pFile, "#Zgamma:\t%d\trun:\t%d\tevent:\t%ld\tlumis:%d\t%.3f\n", eventCounter, run, event, lumis, Weight);

//		if (doEEG && RunA && eventCounter > 29) continue;
//		if (doEEG && RunB && eventCounter > 32) continue;
//		if (doMMG && RunA && eventCounter > 50) continue;
//		if (doMMG && RunB && eventCounter > 68) continue;


//		THIS IS TO SELECT ONLY REQUIRED NUMBER OF EVENTS IN THE FINAL FILE FOR BACKGROUND UNCERTAINTY
//		if (doEEG && eventCounter > 1114) continue; // FOR SIGNAL // 557 CORRESPONDS TO DATA
//		if (doEEG && eventCounter > 260) continue; // FOR BG // 130 CORRESPONDS TO DATA BG

//		if (doMMG && eventCounter > 796) continue; // FOR SIGNAL
//		if (doMMG && eventCounter > 199) continue; // FOR BG

//		if (checkEvent) cout << "photon SF Weight = " << Weight << endl;

//		IT SEEMS TAHT cosThetaZ < -0.9 is mostly populated by the misidentified jets so I am trying to cut it here (IRAKLI)
//		if (TangleMap["cosThetaZ"] < -0.9) continue;
//		fillNPassed(passBin,nPassed,nPassedMap,"cosThetaZ > -0.9");

		eventCounter++;

		TangleMap["Weight"] = Weight;
//		--------------------------------------------------------------
		_cosThetaL->Fill(angleMap["cosThetaL"],		Weight);
		_thetaL->Fill(angleMap["thetaL"],		Weight);
		_cosThetaZ->Fill(angleMap["cosThetaZ"],		Weight);
		_thetaZ->Fill(angleMap["thetaZ"],		Weight);

		_cosThetaZ_L->Fill(mcAngleMap["cosThetaL"],mcAngleMap["cosThetaZ"]);

		_phiL->Fill(angleMap["phiL"],	Weight);
		_phiZ->Fill(angleMap["phiZ"],	Weight);

//		ANGLE RESOLUTION PLOTS
		_cosThetaL_res1->Fill((mcAngleMap["cosThetaL"]-angleMap["cosThetaL"])/mcAngleMap["cosThetaL"]);
		_cosThetaL_res->Fill(mcAngleMap["cosThetaL"], angleMap["cosThetaL"]);
		_cosThetaZ_res1->Fill((mcAngleMap["cosThetaZ"]-angleMap["cosThetaZ"])/mcAngleMap["cosThetaZ"]);
		_cosThetaZ_res->Fill(mcAngleMap["cosThetaZ"], angleMap["cosThetaZ"]);

		_phiL_res1->Fill((mcAngleMap["phiL"]-angleMap["phiL"])/mcAngleMap["phiL"]);
		_phiL_res->Fill(mcAngleMap["phiL"], angleMap["phiL"]);
		_phiZ_res1->Fill((mcAngleMap["phiZ"]-angleMap["phiZ"])/mcAngleMap["phiZ"]);
		_phiZ_res->Fill(mcAngleMap["phiZ"], angleMap["phiZ"]);

//		END OF ANGLE CALCULATIONS

		photonEt = phoEt[phoind];
		photonTree->Fill();
		_GammaEt     ->Fill(phoEt[            phoind],	Weight);
		_GammaEta    ->Fill(phoEta[           phoind],	Weight);
		_GammaPhi    ->Fill(phoPhi[           phoind],	Weight);
		_GammaHoE    ->Fill(phoHoverE[        phoind],	Weight);
		_GammaSigIEIE->Fill(phoSigmaIEtaIEta[ phoind],	Weight);
		_GammaEcalIso->Fill(phoEcalIsoDR04[phoind],	Weight);
		_GammaHcalIso->Fill(phoHcalIsoDR04[phoind],	Weight);
		_GammaTrkIso ->Fill(phoTrkIsoHollowDR04[phoind],Weight);

		ZGMass->Fill(llg.M(),				Weight);
		ZGpt  ->Fill(llg.Pt(),				Weight);
		ZMass ->Fill(ll.M(),				Weight);
		int tempCount = 0;
		if (tempCount < 3000)
			{
			ZM_ZgM->Fill(ll.M(),llg.M(),		Weight);
			tempCount++;
			}
		float dR1 = 0;
		float dR2 = 0;
		if (doEEG)
			{
			dR1  = reco::deltaR( phoEta[phoind], phoPhi[phoind], eleEta[lep1ind], elePhi[lep1ind]);
			dR2  = reco::deltaR( phoEta[phoind], phoPhi[phoind], eleEta[lep2ind], elePhi[lep2ind]);
			Leg1Pt->Fill(elePt[lep1ind],		Weight);
			Leg2Pt->Fill(elePt[lep2ind],		Weight);
			}
		if (doMMG)
			{
			dR1  = reco::deltaR( phoEta[phoind], phoPhi[phoind], muEta[lep1ind], muPhi[lep1ind]);
			dR2  = reco::deltaR( phoEta[phoind], phoPhi[phoind], muEta[lep2ind], muPhi[lep2ind]);
			Leg1Pt->Fill(muPt[lep1ind],		Weight);
			Leg2Pt->Fill(muPt[lep2ind],		Weight);
			}
		dRLeg1Gamma->Fill(dR1,				Weight);
		dRLeg2Gamma->Fill(dR2,				Weight);

		if (dR1 < dR2) dRGamma->Fill(dR1);
		else dRGamma->Fill(dR2);

		outTree->Fill();
		mcCutoutTree->Fill();

/*
		if (ismcCut)
			mcCutoutTree->Fill();
		else
			{
			if (blepPt) cout << "lepton pt failed! " << mclep1.Pt() << " : " << lep1.Pt() << "; " << mclep2.Pt() << " : " << lep2.Pt()<< endl;
			else if (blep1Eta) cout << "lepton 1 eta failed! " << mclep1.PseudoRapidity() << " : " << lep1.PseudoRapidity() << endl;
			else if (blep2Eta) cout << "lepton 2 eta failed! " << mclep2.PseudoRapidity() << " : " << lep2.PseudoRapidity() << endl;
			else if (bphoEt) cout << "photon Et failed! " << mcGamma.Et() << " : " << gamma.Et() << endl;
			else if (bphoEta) cout << "photon Eta failed! " << mcGamma.PseudoRapidity() << " : " << gamma.PseudoRapidity() << endl;
			else if (bdR) cout << "dR failed! " << endl;
			else if (bMass) cout << "Mass failed! " << endl;
			else cout << "something else failed " << endl;
			failed_cosThetaZ->Fill(mcAngleMap["cosThetaZ"]);
			}
*/
		} // * ** *** END OF EVENT LOOP *** ** * \\


	f_out->cd();

	cout << " = = = = = = Number of MC Events Analyzed\t= " << mcAllCount << endl;
	cout << " = = = = = = Number of MC muons\t= " << mcCounter << endl;
	cout << " = = = = = = Number of MC electrons\t= " << mceCounter << endl;
	cout << " = = = = = = Number of MC photons\t= " << mcgCounter << endl;

	failed_cosThetaZ->Write();

//	GEN PARTICLE ET AND PT
//	_genPhoEt->Write();
//	_genLepPt->Write();

//	GOOD PARTICLE KINMATICS
	_goodPhoEta->Write();
	MC_goodPhoEta->Write();

//	ANGLES
	_cosThetaL->Write();
	_thetaL->Write();
	_cosThetaL_FSR->Write();
	_cosThetaZ->Write();
	_thetaZ->Write();
	_cosThetaZ_L->Write();

//	RESOLUTION PLOTS
	_cosThetaL_res1->Write();
	_cosThetaL_res->Write();
	_cosThetaZ_res1->Write();
	_cosThetaZ_res->Write();

	_phiL_res->Write();
	_phiL_res1->Write();
	_phiZ_res->Write();
	_phiZ_res1->Write();

	_phiL->Write();
	_phiZ->Write();

	MC_cosThetaL->Write();
	MC_thetaL->Write();
	MCCut_cosThetaL->Write();
	MC_cosThetaL_FSR->Write();

	MC_cosThetaZ->Write();
	MC_thetaZ->Write();
	MCCut_cosThetaZ->Write();
	cosThetaZ_phoEta->Write();

	MC_cosThetaZ_L->Write();
	MCCut_cosThetaZ_L->Write();
	MC_phiL->Write();
	MCCut_phiL->Write();
	MC_phiZ->Write();
	MCCut_phiZ->Write();

//	END ANDLES

	dRLeg1Gamma->Write();
	dRLeg2Gamma->Write();
	dRGamma->Write();
	ZMass->Write();
	ZMass_noPho->Write();
	ZMass_noPho_PU->Write();
	ZMass_noPho_PU_SF->Write();
	ZGMass->Write();
	ZGpt->Write();
	ZM_ZgM->Write();
	hEvents->Write();
	nPassed->Write();

	_GammaEt->Write();
	_GammaEta->Write();
	_GammaPhi->Write();
	_GammaHoE->Write();
	_GammaSigIEIE->Write();
	_GammaEcalIso->Write();
	_GammaHcalIso->Write();
	_GammaTrkIso->Write();
	_Gamma_eIso->Write();
	_Gamma_hIso->Write();
	_Gamma_tIso->Write();

//	photons
	_photonEt->Write();
	_photonEta->Write();
	_photonPhi->Write();
	_photonHoE->Write();
	_photonSigIEIE->Write();
	_photonEcalIso->Write();
	_photonHcalIso->Write();
	_photonTrkIso->Write();
	_photon_eIso->Write();
	_photon_hIso->Write();
	_photon_tIso->Write();

	_cleanLepPt->Write();
	_goodLepPt->Write();
	photonTree->Write();

	outTree->Write();
	mcoutTree->Write();
	mcCutoutTree->Write();

//	notify user of success
	cout << "\nWROTE FILE:\t\t" << f_out->GetName() << "\n=======================================\n" << endl;

	map<int,string>::iterator iter;
	for (iter = nPassedMap.begin(); iter != nPassedMap.end(); ++iter)
		{
		if (nPassed->GetBinContent(int(iter->first)) != 0)
			cout	<< iter->first << "\t" << nPassed->GetBinContent(int(iter->first+1)) << "\t" << iter->second
				<< "\t" << float (nPassed->GetBinContent(int(iter->first+1))) / float (nPassed->GetBinContent(int(iter->first))) * 100. << "\t%"
				<< endl;
		else 
			cout	<< iter->first << "\t" << nPassed->GetBinContent(int(iter->first+1)) << "\t" << iter->second
				<< "\t" << "100%"  << "\t%"
				<< endl;
		}

	dataPuFileRunA_3D->Close();
	dataPuFileRunB_3D->Close();

	eleIDScaleFactorA->Close();
	eleIDScaleFactorB->Close();

	eleRECOScaleFactorA->Close();
	eleRECOScaleFactorB->Close();

	eleHLTScaleFactorA->Close();
	eleHLTScaleFactorB->Close();

	muIDScaleFactorA->Close();
	muIDScaleFactorB->Close();


	f_out->Close();
  	f->Close();

//	fclose(pFile);

	cout << "\n<----------------------DONE \n" << endl;
	return 0;
	}
