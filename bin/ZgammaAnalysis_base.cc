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
//	====== initiate leafs
//	====== initiate branches
//	====== set branches
//	====== set address
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