#include "ZgammaAnalysis.h"

#include <iostream>
#include <string>

// CMS includes
#include "FWCore/Utilities/interface/InputTag.h"
#include "DataFormats/Common/interface/Handle.h"
#include "DataFormats/PatCandidates/interface/Jet.h"

//#include "PhysicsTools/FWLite/interface/EventContainer.h"
#include "PhysicsTools/FWLite/interface/CommandLineParser.h" 

// USER INLCUDES
#include "DataFormats/Math/interface/deltaR.h"
#include <TLorentzVector.h>
#include "TROOT.h"
#include "TMath.h"
#include "TFile.h"
#include "TTree.h"
#include "TH2.h"

using namespace std;
using optutl::CommandLineParser;


// ///////////////////// //
// // COUNTER HELPER  // //
// ///////////////////// //

void fillNPassed(int &passBin, TH1I* &nPassed,  map<int,string> &nPassedMap,string description)
	{
	nPassed->Fill(passBin);
	passBin++;
	if (nPassedMap.find(passBin - 1) == nPassedMap.end()) nPassedMap.insert(pair<int,string>(passBin - 1,description));
	}

// ///////////////////// //
// // MUON ID HELPER  // //
// ///////////////////// //
// ======================================================================
bool muonId( float d0, float dZ, float chi2ndf, int stations, int pixels, int strips, int muonHits, float eIso, float hIso, float tIso, float pt, float RHO)
	{
	bool pass = false;
  
	if (	fabs(d0)  < 0.02    &&
		fabs(dZ)  < 0.1     &&
		chi2ndf   < 10.    &&
		stations  > 1      &&
		pixels    > 0      &&
		strips    > 10     &&
		muonHits  > 0      &&
		( eIso + hIso + tIso - RHO * 3.141592 * 0.3 * 0.3 ) < 0.1 * pt 
		) pass = true;
	return pass;
	}
// ======================================================================
bool vetoMuonEvent( int muType,float pt, float eta, int run, int event)
	{
	bool veto = false;
  
	if (run == 161311 && event == 6770135) cout << "muType == " << muType << "\npt = " << pt << "\n eta = " << eta << endl;
        if ( muType == 14 && pt > 10 && eta < 2.4) veto = true;

	return veto;
	}
// ======================================================================
bool electronId(float eleIsoHcalSolidDR03, float eleSCEta, float RHO, float eleIsoTrkDR03, float eleIsoEcalDR03, float elePt, float eledPhiAtVtx, float eledEtaAtVtx, float eleSigmaIEtaIEta, int run, int event, int eleSeverity, float d0, float dz)
	{
	double Pi = 3.14;
	bool pass = false;

	double cIsoEB = (eleIsoTrkDR03 + max(0., eleIsoEcalDR03 - 1.) + eleIsoHcalSolidDR03 - RHO*Pi*0.3*0.3) / elePt; 
	double cIsoEE = (eleIsoTrkDR03 + eleIsoEcalDR03 + eleIsoHcalSolidDR03 - RHO*Pi*0.3*0.3) / elePt;

	if (run == 161311 && event == 6770135)
		cout << "Combined Isolation = (" << eleIsoTrkDR03 << " + " << eleIsoEcalDR03 << " + " << eleIsoHcalSolidDR03 << " - " << RHO << " * Pi * 0.3 * 0.3) / " << elePt << " = " << cIsoEE << endl;
	if (run == 161311 && event == 6770135)
		{
		cout << fabs(eleSCEta) << "\t<\t1.4442\n" << cIsoEB << "\t0.053\n" << eleSigmaIEtaIEta << "\t0.01\n" << eledPhiAtVtx	<< "\t0.039\n" << eledEtaAtVtx << "\t0.005" << endl;
		cout << fabs(eleSCEta) << "\t<\t2.5\n" << cIsoEE << "\t0.033\n" << eleSigmaIEtaIEta << "\t0.031\n" << eledPhiAtVtx	<< "\t0.028\n" << eledEtaAtVtx << "\t0.007" << "\n------------\n" << endl;
		}

	if (fabs(eleSCEta) < 1.4442 && eleSigmaIEtaIEta < 0.001) return false;
//	if (eleSeverity == 3 || eleSeverity == 4 || eleSeverity == 5) return false;


	if (run == 161311 && event == 6770135) cout << "d0 = " << d0 << "\ndz = " << dz << endl;
	if (fabs(d0) > 0.02 || fabs(dz) > 0.1) return false;


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
		fabs(eledPhiAtVtx)	< 0.021 &&
		fabs(eledEtaAtVtx)	< 0.006) pass = true; 

	return pass;
	}
// ======================================================================
bool vetoElectronEvent(float eleIsoHcalSolidDR03, float eleSCEta, float RHO, float eleIsoTrkDR03, float eleIsoEcalDR03, float elePt, float eledPhiAtVtx, float eledEtaAtVtx, float eleSigmaIEtaIEta, int run, int event, float eleConvMissinghit, int eleSeverity, float d0, float dz)
	{
	double Pi = 3.14;
	bool veto = false;

	double cIsoEB = (eleIsoTrkDR03 + max(0., eleIsoEcalDR03 - 1.) + eleIsoHcalSolidDR03 - RHO*Pi*0.3*0.3) / elePt; 
	double cIsoEE = (eleIsoTrkDR03 + eleIsoEcalDR03 + eleIsoHcalSolidDR03 - RHO*Pi*0.3*0.3) / elePt;

	if (elePt < 20) return false;

	if (fabs(eleSCEta) < 1.4442 && eleSigmaIEtaIEta < 0.001) return false;
//	if (eleSeverity == 3 || eleSeverity == 4 || eleSeverity == 5) return false;


	if (eleConvMissinghit != 0) return false;

	if (run == 161311 && event == 6770135) cout << elePt << endl;
	if (run == 161311 && event == 6770135) 
		cout	<< "eleSCEta = "	<< fabs(eleSCEta)	<< "\n" 
			<< "cIsoEB = "		<< cIsoEB		<< "\n"
			<< "cIsoEE = "		<< cIsoEE		<< "\n"
			<< "sigmaIetaIeta = "	<< eleSigmaIEtaIEta	<< "\n" 
			<< "deltaPhi = "	<< fabs(eledPhiAtVtx)	<< "\n"
			<< "deltaEta = "	<< fabs(eledEtaAtVtx)	<< endl;

//	EB
	if (	fabs(eleSCEta)		< 1.4442	&&
		cIsoEB			< 0.15		&&
		eleSigmaIEtaIEta	< 0.012		&&
		fabs(eledPhiAtVtx)	< 0.8		&&
		fabs(eledEtaAtVtx)	< 0.007) veto = true;

//	EE
	if (	fabs(eleSCEta)		< 2.5	&&
		fabs(eleSCEta)		> 1.566 &&
		cIsoEE			< 0.1	&&
		eleSigmaIEtaIEta	< 0.031	&&
		fabs(eledPhiAtVtx)	< 0.7	&&
		fabs(eledEtaAtVtx)	< 0.011) veto = true; 

	return veto;
	}
// ======================================================================

bool photonId(float eIso, float hIso, float tIso, float scEta, float HoE, float sigIEIE, float pt, float RHO, int phoSeverity)
	{
	bool pass = false;
  
	if (fabs(scEta) < 1.4442 && sigIEIE < 0.001) return false;
	if (phoSeverity == 3 || phoSeverity == 4 || phoSeverity == 5) return false;

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
// ======================================================================
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

float correctedElePt(float elePt, float elePz, float eleSCEta, int RUN, float eleE3x3, float eleSCRawEn)
	{
	float eleP = sqrt(elePt*elePt + elePz*elePz);
	eleP = correctedEleEn(eleP, eleSCEta, RUN, eleE3x3, eleSCRawEn);
        float theta = 2. * atan(exp(-eleSCEta));
        float corrElePt = eleP*fabs(sin(theta));
//	cout << elePt << "\t" << corElePt << endl;
	return corrElePt;
	}

// ======================================================================

// ///////////////////// //
// // Main Subroutine // //
// ///////////////////// //

int main (int argc, char* argv[]) 
	{
	int eventCounter = 1;
	FILE * pFile;
	pFile = fopen ("WGamma_data.txt" , "a");

	// ////////////////////////// //
	// // Command Line Options // //
	// ////////////////////////// //

//	Tell people what this analysis code does and setup default options.
	optutl::CommandLineParser parser ("make ZGamma plots");
	parser.addOption ("Debug",		CommandLineParser::kBool,	"debugMode",			false);
	parser.addOption ("CheckDub",		CommandLineParser::kBool,	"CheckDublicate",		false);
	parser.addOption ("matchMC",		CommandLineParser::kBool,	"matchObjectsToMc",		false);
	parser.addOption ("removeMcPhoJ",	CommandLineParser::kBool,	"remove mc photons from Zjets",	false);
	parser.addOption ("photonID",		CommandLineParser::kInteger,	"specify photon ID",		-1);
	parser.addOption ("electronID",		CommandLineParser::kInteger,	"specify electron ID",		-1);
	parser.addOption ("muonID",		CommandLineParser::kInteger,	"specify muon ID",		-1);
//	parser.addOption ("aTgcTreeF",		CommandLineParser::kString,	"file atgc to be written to",	"EMPTY");
	parser.parseArguments (argc, argv);

	////////////////////////////////////////////////
	// Change any defaults or add any new command //
	//      line options you would like here.     //
	////////////////////////////////////////////////

//	Parse the command line arguments
	parser.parseArguments (argc, argv);

	// //////////////////////////// //
	// // Create Event Container // //
	// //////////////////////////// //
	vector<string> fileNames	= parser.stringVector ("inputFiles");
	string	outfileName		= parser.stringValue  ("outputfile");
//	int	maxEvents		= parser.integerValue ("maxEvents" );
	bool	debug			= parser.boolValue    ("debug"     );
	bool	CheckDub		= parser.boolValue    ("CheckDub"  );
	bool	matchMC			= parser.boolValue    ("matchMC"   );
	bool	removeMcPhoJ		= parser.boolValue    ("removeMcPhoJ");
	int	photonID		= parser.integerValue ("photonID"  );
	int	electronID		= parser.integerValue ("electronID");
	int	muonID			= parser.integerValue ("muonID"    );

	string iFile;

	if (!fileNames.size())
		{
		cout << "\nPLEASE PROVIDE INPUT FILE!!!!\n" << endl;
		return 0;
		}
	else  iFile = fileNames.at(0); // for now only 1 file at a time

//	get file name from path
	if (debug) cout << "PARSED FULL PATH:\t" << iFile << endl;
	size_t pos    = iFile.find_last_of('/');
	string FILE   = iFile.substr(pos+1);
	if (debug) cout << "PARSED FILE NAME:\t" << FILE << endl;

//	translate string to char for filenames
	char iF[200];
	char oF[200];
	sprintf(iF, "%s", iFile.c_str());
	sprintf(oF, "%s", outfileName.c_str());
	if (debug) cout << "OUTPUT FILE NAME:\t" << oF << endl;
	if (debug) cout << "input file string called by TFile Open\t" << iF << endl;
	if (debug) cout << "output file string called by TFile Open\t" << oF << endl;

//	open file
	TH1::SetDefaultSumw2();
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
	if (debug) cout << "SUCCESSFULLY OPENED ALL FILES" << endl;

	f_out->cd();

//	get number of entries in ttree
	long nEvents = tr->GetEntries();

	cout << "\n===============\nPROCESSING FILE:\t" << f->GetName() << "\nNUMBER OF ENTRIES:\t" << nEvents << "\n" << endl;

	// ////////////////////////////////// //
	// //         Begin Run            // //
	// // (e.g., book histograms, etc) // //
	// ////////////////////////////////// //

	TTree *photonTree = new TTree("photonTree","");

	float photonEt;
	photonTree->Branch("photonEt",&photonEt,"photonEt/F");


//	used to check dub events, off by default
	vector<int> RUNS;
	vector<int> LUMIS;
	vector<int> EVENTS;

	int   ptHistoNBINS = 20;
	float ptHistoMin   = 0;
	float ptHistoMax   = 100;

//	TH1F* GammaEt		= new TH1F("GammaEt",		"", ptHistoNBINS,	ptHistoMin,	ptHistoMax);
	TH1F* Leg1Pt		= new TH1F("ZLeg1Pt",		"", ptHistoNBINS,	ptHistoMin,	ptHistoMax);
	TH1F* Leg2Pt		= new TH1F("ZLeg2Pt",		"", ptHistoNBINS,	ptHistoMin,	ptHistoMax);
	TH1F* dRLeg1Gamma	= new TH1F("dRLeg1Gamma",	"", 60,			0,		6);
	TH1F* dRLeg2Gamma	= new TH1F("dRLeg2Gamma",	"", 60,			0,		6);
	TH1F* dRGamma		= new TH1F("dRGamma",		"", 60,			0,		6);
	TH1F* ZMass		= new TH1F("ZMass",		"", 16,			40,		120);
	TH1F* ZGpt		= new TH1F("ZGpt",		"", 20,			0,		100);
	TH1F* ZGMass		= new TH1F("ZGMass",		"", 28,			60,		200);
	TH2F* ZM_ZgM		= new TH2F("ZM_ZgM",		"", 16,			40,		120, 28, 60, 200);

	TH1F* _GammaEt		= new TH1F("_GammaEt",		"", 100,			0,	300);
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

//	HISTOS FOR DATA DRIVEN BACKGROUND
	TH1F* ZMass_bg		= new TH1F("ZMass_bg",		"", 16,			40,		120);
	TH1F* ZGMass_bg		= new TH1F("ZGMass_bg",		"", 28,			60,		200);
	TH1F* _cosThetaL_cm_bg	= new TH1F("_cosThetaL_cm_bg",	"cos(#theta_{l})", 10,	-1,		1);

//	counter histo
	TH1I* nPassed		= new TH1I("nPassed",		"", 50,			0,50);

//	nPassed->SetBinContent(1,hEvents->GetBinContent(1));
//	nPassed->SetBinContent(2,hEvents->GetBinContent(2));

//	for efficiency
	TH1F* _photonEt		= new TH1F("_photonEt",		"", 10,			0,		100);
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
	TH1F* _thetaL		= new TH1F("_thetaL",		"cos(#theta_{l'})", 100,	-1,		1);
	TH1F* _thetaL_cm	= new TH1F("_thetaL_cm",	"cos(#theta_{l'})", 100,	-1,		1);
	TH1F* _cosThetaL	= new TH1F("_cosThetaL",	"cos(#theta_{l})", 100,	-1,		1);
	TH1F* _cosThetaL_bg	= new TH1F("_cosThetaL_bg",	"cos(#theta_{l})", 20,	-1,		1);
	TH1F* _cosThetaL_cm	= new TH1F("_cosThetaL_cm",	"cos(#theta_{l})", 20,	-1,		1);
	TH1F* _cosThetaL_cm_FSR	= new TH1F("_cosThetaL_cm_FSR",	"cos(#theta_{l})", 10,	-1,		1);

	TH1F* _thetaZ		= new TH1F("_thetaZ",		"cos(#theta_{Z'})", 100,	-1,		1);
	TH1F* _thetaZ_cm	= new TH1F("_thetaZ_cm",	"cos(#theta_{Z'})", 100,	-1,		1);
	TH1F* _cosThetaZ	= new TH1F("_cosThetaZ",	"cos(#theta_{Z})", 20,	-1,		1);
	TH1F* _cosThetaZ_bg	= new TH1F("_cosThetaZ_bg",	"cos(#theta_{Z})", 20,	-1,		1);
	TH1F* _cosThetaZ_cm	= new TH1F("_cosThetaZ_cm",	"cos(#theta_{Z})", 20,	-1,		1);

//	TH1F* _thetaZ		= new TH1F("_thetaZ",		"", 20,			-4,		4);
	TH1F* _phiL		= new TH1F("_phiL",		"", 20,			-4,		4);
	TH1F* _phiZ		= new TH1F("_phiZ",		"", 20,			-4,		4);

	TH1F* _phi		= new TH1F("phi",		"", 20,			-1.6,		1.6);
	TH1F* _phi_bg		= new TH1F("phi_bg",		"", 20,			-1.6,		1.6);
	TH1F* _phi_cm		= new TH1F("phi_cm",		"", 20,			-4,		4);


	if (debug) cout << "SUCCESSFULLY BOOKED HISTOS" << endl;

//	DEFINE SOME CUTS AND VARIABLES USED IN CALCULATIONS, making similar structure to taiwan script
	float AntiUEB=999;
	float AntiUEE=999;
	float AntiLEB=3;
	float AntiLEE=3;

	float dRcut = 0.7; 
	float phoEtCut = 15;
	float lepPtCut = 35;

	map<int,string> nPassedMap;

	TLorentzVector lep1, lep2, gamma, ll, llg, antigamma, antillg;

	bool doEEG = false;
	bool doMMG = false;
	if (electronID >= 0)	doEEG = true;
	if (muonID >= 0)	doMMG = true;
	if (doEEG && doMMG)
		{
		cout << "SPECIFY EITHER MU OR ELE\nEXITING" << endl;
		return 0;
		}

// //////////////// //
// // leafs, branches, addresses
// //////////////// //
//	====== initiate leafs
	if (debug) cout << "init leafs" << endl;
//	====== initiate branches
	if (debug) cout << "init branches" << endl;
//	====== set branches
	if (debug) cout << "set branches" << endl;
//	====== set address
	if (debug) cout << "set addresses" << endl;
//	==================================================================

	if (debug) cout << "SUCCESSFULLY INITIATED LEAFES" << endl;

	// //////////////// //
	// // Event Loop // //
	// //////////////// //
	for (long index = 0; index < nEvents; ++index )
//	for (long index = 0; index < 1000000; ++index )
//	for (long index = 21900000; index < nEvents; ++index )
		{
//		progress
		if (index % 100000 == 0 )
			{
			float perc = float(index)*100./float(nEvents);
			printf("Processed Events\t%ld\t\t%.0f %%\n",index, perc);
			}

//		get current entry from the tree
		tr->GetEntry(index);
		if (run > 166861) continue;

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
//		which value to fill in counter histrogram (nPassed) first
		int passBin = 1;

		fillNPassed(passBin,nPassed,nPassedMap,"CHECK POINT");
		if (run == 161311 && event == 6770135) cout << "CHECKING" << endl;

		if (nVtx == 0) continue;
		fillNPassed(passBin,nPassed,nPassedMap,"any Vertex");
		if (run == 161311 && event == 6770135) cout << "Any Vertex!!!!!!" << endl;
  
		if (IsVtxGood == 0) continue;
		fillNPassed(passBin,nPassed,nPassedMap,"good Vertex");
		if (run == 161311 && event == 6770135) cout << "GOOD Vertex!!!!!!" << endl;
  
		if (IsTracksGood == 0) continue;
		fillNPassed(passBin,nPassed,nPassedMap,"good Tracks");
		if (run == 161311 && event == 6770135) cout << "Good Tracks!!!!!!" << endl;

		vector<int> cleanPho;
		vector<int> cleanDRPho;
		vector<int> cleanEle;
		vector<int> cleanMu;
		vector<int> goodPho;
		vector<int> goodLep;

		vector<int> nonIsoPho;

		for (int iPho = 0; iPho < nPho; iPho++)
			{
		if (run == 161311 && event == 6770135) cout << "Et  = " << phoEt[iPho] << " - " << phoSCEta[iPho] << " - " << phoR9[iPho] << endl;
			phoEt[iPho] = correctedPhoEt(phoEt[iPho],phoSCEta[iPho],phoR9[iPho],run);
//			ET cut
		if (run == 161311 && event == 6770135) cout << "Et  = " << phoEt[iPho] << endl;
			if (phoEt[iPho] < phoEtCut)	continue;
		if (run == 161311 && event == 6770135) cout << "Et cut passed!!!!!!" << endl;
			if (fabs(phoSCEta[iPho])> 2.5)	continue;
		if (run == 161311 && event == 6770135) cout << "eta passed!!!!!!" << endl;
			if (fabs(phoSCEta[iPho]) > 1.4442 && fabs(phoSCEta[iPho]) < 1.566 ) continue;
		if (run == 161311 && event == 6770135) cout << "eta 2 passed!!!!!!" << endl;
			if (phoHoverE[iPho] > 0.5 )	continue;
		if (run == 161311 && event == 6770135) cout << "phoHoverE passd = " << phoHoverE[iPho] << endl;
//			if (phoOverlap[iPho] == 1)	continue;
			if (phohasPixelSeed[iPho] == 1)	continue;
		if (run == 161311 && event == 6770135) cout << "pixel seed!!!!!!" << endl;
			cleanPho.push_back(iPho);
			}

		if (cleanPho.size() == 0) continue;
		fillNPassed(passBin,nPassed,nPassedMap,"at least 1 clean photon");
		if (run == 161311 && event == 6770135) cout << "1 clean photon!!!!!!" << endl;
  
		int vetoCounter = 0;
		if (doEEG)
			{
			for (int iEle=0; iEle < nEle; iEle++)
				{
				eleEn[iEle] = correctedEleEn(eleEn[iEle], eleSCEta[iEle], run, eleE3x3[iEle], eleSCRawEn[iEle]);
				elePt[iEle] = correctedEleEn(elePt[iEle], eleSCEta[iEle], run, eleE3x3[iEle], eleSCRawEn[iEle]);

				bool veto = vetoElectronEvent(	eleIsoHcalSolidDR03[iEle],
								eleSCEta[iEle],
								rho,
								eleIsoTrkDR03[iEle],
								eleIsoEcalDR03[iEle],
								elePt[iEle],
								eledPhiAtVtx[iEle],
								eledEtaAtVtx[iEle],
								eleSigmaIEtaIEta[iEle],
								run,
								event,
								eleConvMissinghit[iEle],
								eleSeverity[iEle],
								elePVD0[iEle], elePVDz[iEle]);
				if (veto) vetoCounter++;
				}
			for (int iEle=0; iEle < nEle; iEle++)
				{
				if (elePt[iEle] < lepPtCut) continue;
				if (fabs(eleSCEta[iEle]) > 2.5 || ( fabs(eleSCEta[iEle]) > 1.4442 && fabs(eleSCEta[iEle]) < 1.566) ) continue;

				cleanEle.push_back(iEle);
				}
			}

		if (doMMG)
			for (int iMu=0; iMu < nMu; iMu++)
				{
				bool veto = vetoMuonEvent(muType[iMu], muPt[iMu], muEta[iMu], run, event);
				if (veto) vetoCounter++;
				}
			for (int iMu=0; iMu < nMu; iMu++)
				{
				if (muPt[iMu] < lepPtCut) continue;
				if ( fabs(muEta[iMu]) > 2.1 ) continue;
				if ( muType[iMu] != 14) continue; // isGlobal && Tracker

				cleanMu.push_back(iMu);
				}

		if (vetoCounter > 1) continue;
		fillNPassed(passBin,nPassed,nPassedMap,"Not Vetoed Events");
		if (run == 161311 && event == 6770135) cout << "NOT VETOED!!!!!!" << endl;

		if (doEEG && cleanEle.size() < 1) continue;
		if (doMMG && cleanMu.size() < 1) continue;
		fillNPassed(passBin,nPassed,nPassedMap,"at least 2 clean leptons");
		if (run == 161311 && event == 6770135) cout << "2 clean leptons!!!!!!" << endl;
  
//		bool doOnceHLT = false;
//		bool doOnceConv = false;
		if (doEEG)
			for ( vector<int>::iterator it = cleanEle.begin(); it != cleanEle.end(); it++)
				{
				bool pass = electronId(	eleIsoHcalSolidDR03[*it],
							eleSCEta[*it],
							rho,
							eleIsoTrkDR03[*it],
							eleIsoEcalDR03[*it],
							elePt[*it],
							eledPhiAtVtx[*it],
							eledEtaAtVtx[*it],
							eleSigmaIEtaIEta[*it],
							run,
							event,
							eleSeverity[*it],
							elePVD0[*it], elePVDz[*it]);

				if (!pass) continue;

				if (run == 161311 && event == 6770135) cout << "electronId passed!!!!!!" << endl;

				int ind1 = HLTIndex[111];
				int ind2 = HLTIndex[112];
				int ind3 = HLTIndex[113];
				int ind4 = HLTIndex[116];
				int ind5 = HLTIndex[117];

				bool eleTrigger1 = false; 
				bool eleTrigger2 = false; 
				bool eleTrigger3 = false; 
				bool eleTrigger4 = false; 
				bool eleTrigger5 = false; 

				if (ind1 >= 0 && HLTprescale[ind1] == 1) eleTrigger1 = (eleTrg[*it][10] > 0);
				if (ind2 >= 0 && HLTprescale[ind2] == 1) eleTrigger2 = (eleTrg[*it][11] > 0);
				if (ind3 >= 0 && HLTprescale[ind3] == 1) eleTrigger3 = (eleTrg[*it][12] > 0);
				if (ind4 >= 0 && HLTprescale[ind4] == 1) eleTrigger4 = (eleTrg[*it][15] > 0);
				if (ind5 >= 0 && HLTprescale[ind5] == 1) eleTrigger5 = (eleTrg[*it][16] > 0);

				if (run == 161311 && event == 6770135)
					{
					cout << "HLTprescale = " << HLTprescale[ind1] << "; eleTrg[" << *it << "][10] = " << eleTrg[*it][10] << endl;
					cout << "HLTprescale = " << HLTprescale[ind2] << "; eleTrg[" << *it << "][11] = " << eleTrg[*it][11] << endl;
					cout << "HLTprescale = " << HLTprescale[ind3] << "; eleTrg[" << *it << "][12] = " << eleTrg[*it][12] << endl;
					cout << "HLTprescale = " << HLTprescale[ind4] << "; eleTrg[" << *it << "][15] = " << eleTrg[*it][15] << endl;
					cout << "HLTprescale = " << HLTprescale[ind5] << "; eleTrg[" << *it << "][16] = " << eleTrg[*it][16] << endl;
					}

				if (!(eleTrigger1 || eleTrigger2 || eleTrigger3 || eleTrigger3 || eleTrigger4 || eleTrigger5)) continue;
				if (run == 161311 && event == 6770135) cout << "HLT passed!!!!!!" << endl;

				if (run == 161311 && event == 6770135)
					cout << "conversion : " << eleConvMissinghit[*it] << " - " << fabs(eleConvDist[*it]) << " - " << fabs(eleConvDcot[*it]) << endl;
				if (!(eleConvMissinghit[*it] == 0 && (fabs(eleConvDist[*it]) > 0.02 || fabs(eleConvDcot[*it]) > 0.02))) continue;
				if (run == 161311 && event == 6770135) cout << "conversion passed!!!!!!" << endl;

				goodLep.push_back(*it);
				}
  
		if (doMMG)
			for ( vector<int>::iterator it = cleanMu.begin(); it != cleanMu.end(); it++)
				{
				bool pass = muonId(	muPVD0[*it], muPVDz[*it],
							muChi2NDF[*it], muStations[*it],
							muNumberOfValidPixelHits[*it],
							muNumberOfValidTrkHits[*it],
							muNumberOfValidMuonHits[*it],
							muIsoEcal[*it],muIsoHcal[*it],muIsoTrk[*it],
							muPt[*it], rho);
				if (!pass) continue;

//				HLT Trigger Matching for Muons
				int ind1 = HLTIndex[88];
				int ind2 = HLTIndex[89];
				int ind3 = HLTIndex[90];
				int ind4 = HLTIndex[182];

				bool mTrigger1 = false;
				bool mTrigger2 = false;
				bool mTrigger3 = false;
				bool mTrigger4 = false;

				if (ind1 >= 0 && HLTprescale[ind1] == 1) mTrigger1 = (muTrg[*it][9] > 0);
				if (ind2 >= 0 && HLTprescale[ind2] == 1) mTrigger2 = (muTrg[*it][10] > 0);
				if (ind3 >= 0 && HLTprescale[ind3] == 1) mTrigger3 = (muTrg[*it][11] > 0);
				if (ind4 >= 0 && HLTprescale[ind4] == 1) mTrigger4 = (muTrg[*it][33] > 0);

				bool mTrigger = (mTrigger1 || mTrigger2 || mTrigger3 || mTrigger4);
				if (!mTrigger) continue;

				goodLep.push_back(*it);
				}
  
		if (run == 161311 && event == 6770135) cout << "Number of Good Leptons = " << goodLep.size() << endl;
		if ( goodLep.size() < 1 ) continue;
/*
		if (goodLep.size() > 2) 
			{

			fprintf(pFile, "#Zgamma:\t%d\trun:\t%d\tevent:\t%d\tlumis:%d\n", eventCounter, run, event, lumis);
			for (vector<int>::iterator it = goodLep.begin(); it != goodLep.end(); it++)
				{
				cout << " - " << *it << " - " << endl;
				}
			}
*/
		fillNPassed(passBin,nPassed,nPassedMap,"required 2 good leptons");
		if (run == 161311 && event == 6770135) cout << "2 good leptons!!!!!!" << endl;
  
		int lep1ind  = int (goodLep.at(0));

		if (doEEG) lep1.SetPtEtaPhiE(elePt[lep1ind],eleEta[lep1ind],elePhi[lep1ind],eleEn[lep1ind]);

		if (doMMG)
			{
			float muEn1 = sqrt(muPt[lep1ind]*muPt[lep1ind] + muPz[lep1ind]*muPz[lep1ind]);
			lep1.SetPtEtaPhiE(muPt[lep1ind],muEta[lep1ind],muPhi[lep1ind],muEn1);
			}

  
		for (int pho = 0; pho <  int (cleanPho.size()); pho++)
			{
			int phoind = cleanPho.at(pho);
			float dR = -1;
			if (doEEG) dR = reco::deltaR( phoEta[phoind], phoPhi[phoind], eleEta[lep1ind], elePhi[lep1ind]);
			if (doMMG) dR = reco::deltaR( phoEta[phoind], phoPhi[phoind], muEta[lep1ind], muPhi[lep1ind]);
			if (dR > dRcut) cleanDRPho.push_back(phoind);
			if (run == 161311 && event == 6770135) cout << "dR = "<< dR << endl;
			}
  
		if (cleanDRPho.size() == 0) continue;

		fillNPassed(passBin,nPassed,nPassedMap,"at least 1 pho > dR");
		if (run == 161311 && event == 6770135) cout << "pho > dR!!!!!!" << endl;

		int clPhoInd = cleanDRPho.at(0);
  
		for (int pho=0; pho <  int (cleanDRPho.size()); pho++)
			{
			int phoind = cleanDRPho.at(pho);
//			float eta = fabs(phoEta[phoind]);
			if (photonID >= 0)
				{
				bool photonPass = false;
				photonPass = photonId(	phoEcalIsoDR04[phoind], phoHcalIsoDR04[phoind],
							phoTrkIsoHollowDR04[phoind], phoSCEta[phoind],
							phoHoverE[phoind], phoSigmaIEtaIEta[phoind],
							phoEt[phoind], rho, phoSeverity[phoind]);
				if (!photonPass) continue;
				}
			goodPho.push_back(phoind);
			}
//============================================================
//		select non isolated photons, used for bkg estimation
		for (int pho=0; pho <  int (cleanDRPho.size()); pho++)
			{
			int phoind = cleanDRPho.at(pho);
//			float eta = fabs(phoEta[phoind]);
      
//			Anti-selection
			if (fabs(phoSCEta[phoind]) < 1.4442)
				{
				if (phoTrkIsoHollowDR04[phoind]-0.001*phoEt[phoind] < AntiLEB) continue;
				if (phoTrkIsoHollowDR04[phoind]-0.001*phoEt[phoind] > AntiUEB) continue;
				}
			else if (fabs(phoSCEta[phoind]) > 1.566 )
				{
				if (phoTrkIsoHollowDR04[phoind]-0.001*phoEt[phoind] < AntiLEE) continue;
				if (phoTrkIsoHollowDR04[phoind]-0.001*phoEt[phoind] > AntiUEE) continue;
				}
			else { continue; }
			nonIsoPho.push_back(phoind);
			}
    
		float Weight=1;
/* 
		int antiPhoInd = -100;
    
		if (nonIsoPho.size()!=0)
			{
			int antiPhoInd = nonIsoPho.at(0);
			float photonPT = phoEt[antiPhoInd];
			antigamma.SetPtEtaPhiE(phoEt[antiPhoInd],phoEta[antiPhoInd],phoPhi[antiPhoInd],phoE[antiPhoInd]);

			antillg = ll + antigamma;

			int RatIndex =  (photonPT - 10.)/(10.);
			if ( RatIndex > 9 ) RatIndex = 9;

			float ratScale_EB[10] = { 0.0523413 , 0.0333743 , 0.0212804 , 0.013569  , 0.00865196, 0.00551673 , 0.00351762 , 0.00224294 , 0.00143016 , 0.000911909};
			float ratScale_EE[10] = { 0.0416731 , 0.0319079 , 0.0244311 , 0.0187062 , 0.0143228 , 0.0109666  , 0.00839684 , 0.00642923 , 0.         , 0. };

			angleMap_bg = zgammaAngleCalculator(lep1, lep2, antigamma);

			if (fabs(phoSCEta[antiPhoInd]) < 1.4442 )
				{
				}
			else
				{
				}
			}
*/
//============================================================

		if (goodPho.size() == 0) continue;
		fillNPassed(passBin,nPassed,nPassedMap,"at least 1 good photon");

		if (run == 161311 && event == 6770135) cout << "1 good photon!!!!!!" << endl;

		int phoind = goodPho.at(0);
		gamma.SetPtEtaPhiE(phoEt[phoind],phoEta[phoind],phoPhi[phoind],phoE[phoind]);


//		BACKGROUND BY TEMPLATE METHOD =====================================
		float photonPT = phoEt[phoind];
		int RatIndex =  6;
		if (photonPT >=15 && photonPT < 20 ) RatIndex = 0;
		if (photonPT >=20 && photonPT < 25 ) RatIndex = 1;
		if (photonPT >=25 && photonPT < 30 ) RatIndex = 2;
		if (photonPT >=30 && photonPT < 40 ) RatIndex = 3;
		if (photonPT >=40 && photonPT < 60 ) RatIndex = 4;
		if (photonPT >=60                  ) RatIndex = 5;

//		central values from data template
		double ratScale_EB[6]={0.21329833896010264, 0.17562308894913367, 0.23509065905764598, 0.22168887969882478, 0.25471332291361154, 0.15206732921682878};
		double ratScale_EE[6]={0.32042608140566725, 0.20869409834946279, 0.18734025662055864, 0.20857108829980367, 0.12519025345506898, 0.20634818310680506};


		if (fabs(phoSCEta[phoind]) < 1.4442 )
			{
			}
		else
			{
			}
//		===================================================================
		fprintf(pFile, "%d\trun:\t%d\tevent:\t%d\n", eventCounter, run, event);
		eventCounter++;

		photonEt = phoEt[phoind];


/*
		float dR1 = 0;
		float dR2 = 0;
		if (doEEG)
			{
			dR1  = reco::deltaR( phoEta[phoind], phoPhi[phoind], eleEta[lep1ind], elePhi[lep1ind]);
			dR2  = reco::deltaR( phoEta[phoind], phoPhi[phoind], eleEta[lep2ind], elePhi[lep2ind]);
			}
		if (doMMG)
			{
			dR1  = reco::deltaR( phoEta[phoind], phoPhi[phoind], muEta[lep1ind], muPhi[lep1ind]);
			dR2  = reco::deltaR( phoEta[phoind], phoPhi[phoind], muEta[lep2ind], muPhi[lep2ind]);
			}

*/

		} // END OF EVENT LOOP 
/*
	outTree->Write();
        _thetaL->Write();
        _thetaL_cm->Write();
	_cosThetaL->Write();
	_cosThetaL_cm->Write();
	_cosThetaL_cm_FSR->Write();
	_cosThetaL_cm_bg->Write();
	_cosThetaL_bg->Write();

        _thetaZ->Write();
        _thetaZ_cm->Write();
	_cosThetaZ->Write();
	_cosThetaZ_cm->Write();
	_cosThetaZ_bg->Write();

//	_thetaZ->Write();
	_phi->Write();
	_phi_bg->Write();
	_phi_cm->Write();
	_phiL->Write();
	_phiZ->Write();

	dRLeg1Gamma->Write();
	dRLeg2Gamma->Write();
	dRGamma->Write();
	ZMass->Write();
	ZMass_bg->Write();
	ZGMass->Write();
	ZGMass_bg->Write();
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
*/
//	notify user of success
	cout << "\nWROTE FILE:\t\t" << f_out->GetName() << "\n=======================================\n" << endl;

	map<int,string>::iterator iter;
	for (iter = nPassedMap.begin(); iter != nPassedMap.end(); ++iter)
		{
		cout	<< iter->first << "\t" << nPassed->GetBinContent(int(iter->first+1)) << "\t" << iter->second
			<< "\t" << float (nPassed->GetBinContent(int(iter->first+1))) / float (nPassed->GetBinContent(int(iter->first))) * 100. << "\t%"
			<< endl;
		}

	f_out->Close();
	f->Close();

	fclose(pFile);

	cout << "\n<----------------------DONE \n" << endl;
	return 0;
	}
