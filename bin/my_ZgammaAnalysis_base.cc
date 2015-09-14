#include "ZgammaAnalysis.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

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
#include "TFile.h"
#include "TTree.h"
#include "TH2.h"

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
	angleMap["cosThetaZ"]		= cos((Z_CORR.Vect()).Theta());
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

// ///////////////////// //
// // MUON ID HELPER  // //
// ///////////////////// //
// ======================================================================
bool muonId( float d0, float dZ, float chi2ndf, int stations, int pixels, int strips, int muonHits, float eIso, float hIso, float tIso, float pt, float RHO)
	{
	double Pi = TMath::Pi();
	bool pass = false;
  
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
// ======================================================================
bool electronId(float eleIsoHcalSolidDR03, float eleSCEta, float RHO, float eleIsoTrkDR03, float eleIsoEcalDR03, float elePt, float eledPhiAtVtx, float eledEtaAtVtx, float eleSigmaIEtaIEta, float sigmaPhiPhi, int run, bool checkEvent, int eleSeverity, float d0, float dz)
	{
	double Pi = TMath::Pi();
	bool pass = false;

	double cIsoEB = (eleIsoTrkDR03 + max(0., eleIsoEcalDR03 - 1.) + eleIsoHcalSolidDR03 - RHO*Pi*0.3*0.3) / elePt; 
	double cIsoEE = (eleIsoTrkDR03 + eleIsoEcalDR03 + eleIsoHcalSolidDR03 - RHO*Pi*0.3*0.3) / elePt;

	if (checkEvent)
		{
		cout	<< "Combined Isolation EE = (" << eleIsoTrkDR03 << " + " 
			<< eleIsoEcalDR03 << " + " << eleIsoHcalSolidDR03 << " - " 
			<< RHO << " * Pi * 0.3 * 0.3) / " << elePt << " = " 
			<< cIsoEE << endl;
		cout	<< "Combined Isolation EB = " << cIsoEB << endl;
		cout	<< fabs(eleSCEta) << "\t<\t1.4442\n"
			<< cIsoEB << "\t<\t0.053\n"
			<< eleSigmaIEtaIEta << "\t<\t0.01\n"
			<< eledPhiAtVtx << "\t<\t0.039\n"
			<< eledEtaAtVtx << "\t<\t0.005" << endl;
		cout	<< fabs(eleSCEta) << "\t<\t2.5\n"
			<< cIsoEE << "\t<\t0.042\n"
			<< eleSigmaIEtaIEta << "\t<\t0.031\n"
			<< eledPhiAtVtx << "\t<\t0.028\n"
			<< eledEtaAtVtx << "\t<\t0.007\n" << endl;
		}

//	Spike cleaning in Barrel for data
	if (fabs(eleSCEta) < 1.4442 && (eleSigmaIEtaIEta < 0.001 || sigmaPhiPhi < 0.001)) return false;
	if (checkEvent) cout << "eta = " << fabs(eleSCEta) << "; sigmaiEtaiEta = " << eleSigmaIEtaIEta << "; sigmaiPhiPhi = " << sigmaPhiPhi << endl;


	if (checkEvent) cout << "d0 = " << d0 << " < 0.02\ndz = " << dz << " < 0.1\n-----------" << endl;
	if (fabs(d0) > 0.02 || fabs(dz) > 0.1) return false;

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

bool photonId(float eIso, float hIso, float tIso, float scEta, float HoE, float sigIEIE, float sigmaPhiPhi, float pt, float RHO, int phoSeverity, int run, bool checkEvent)
	{
	bool pass = false;
 
	if (checkEvent)
		{
		cout << "Photon ID\n----------------\n" << endl;
		cout << "fabs(scEta) = " << fabs(scEta) << " < 1.4442; " <<  "sigIEIE = " << sigIEIE <<  " < 0.001 " << endl;
		cout << "eIso = " << eIso << " < " << ( 4.2 + 0.006 * pt + 0.183 * RHO ) << endl;
		}

	if (fabs(scEta) < 1.4442 && (sigIEIE < 0.001 || sigmaPhiPhi < 0.001)) return false; // Spike Cleaning

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
// ======================================================================
double corrVgamma(double en, double scEta, double r9, int run, bool checkEvent)
	{
	double eta = fabs(scEta);
	double mz = 91.19;

	if (checkEvent) cout << "Energy Correction : E = " << en << "; scEta = " << eta << "; R9 = " << r9 << endl;

//	list of correction coefficiencints for EB
//	|eta| < 1.0 r9 > 0.94, |eta| < 1.0 r9 < 0.94, 4th r9 > 0.94, 4th r9 < 0.94

	float scaleDataCorrEB[4] = { 0.000, -0.355, -0.210,  1.480}; 

//	list of correction coefficients for EE
	float scaleDataCorrEE[4] = { 0.00,   2.40,   0.00,   1.05}; 

//	Corrections for data, EB
	if (eta < 1.5)
		{
//		run ranges between interventions
		float corr = 0;
		if (run < 161016)			corr = 1 - 0.130/mz;	// very small
		if (run >= 161016 && run < 162762) 	corr = 1 + 0.040/mz;	// technical stop
		if (run >= 162762 && run < 163869)	corr = 1 - 0.200/mz; 
		if (run >= 163869 && run < 165204)	corr = 1 - 0.000/mz;	// technical stop
		if (run >= 165204 && run < 166380)	corr = 1 + 0.112/mz;
		if (run >= 166380 && run < 166839)	corr = 1 + 0.279/mz;	// noisy period
		if (run >= 166839 && run < 167284)	corr = 1 + 0.373/mz;
		if (run >= 167284 && run < 167674)	corr = 1 + 0.120/mz;	// noisy period
		if (run >= 167674 && run < 167898)	corr = 1 + 0.611/mz;
		if (run >= 167898 && run < 176100)	corr = 1 + 0.206/mz;
		if (run >= 176100 && run < 176400)	corr = 1 + 0.580/mz;
		if (run >= 176400 && run < 176600)	corr = 1 + 0.528/mz;
		if (run >= 176600 && run < 177000)	corr = 1 + 0.390/mz;
		if (run >= 177000 && run < 177500)	corr = 1 + 0.593/mz;
		if (run >= 177500 && run < 178000)	corr = 1 + 0.485/mz;
		if (run >= 178000 && run < 178300)	corr = 1 + 0.639/mz;
		if (run >= 178300 && run < 178600)	corr = 1 + 0.617/mz;
		if (run >= 178600 && run < 179100)	corr = 1 + 0.829/mz;
		if (run >= 179100 && run < 179600)	corr = 1 + 0.676/mz;
		if (run >= 179600)			corr = 1 + 1.171/mz;

//		data scaling factors
		en *= corr;

		if (checkEvent) cout << "Energy correction Step 1 : " << en << endl;
		if ( eta < 1.0 )
			{
			if ( r9 <= 0.94 )
				{
				en *= 1 + scaleDataCorrEB[1]/mz; // DONE!
				}
			if (checkEvent) cout << "Energy correction Step 2 : " << en << endl;
			}
		else
			{
//			4th module
			en *= 1 + scaleDataCorrEB[2]/mz; // r9 > 0.94; DONE!
			if ( r9 <= 0.94 ) 
//				additional correction for r9 < 0.94 DONE!
				en *= 1 + scaleDataCorrEB[3]/mz; 

			if (checkEvent) cout << "Energy correction Step 2 : " << en << endl;
			}
		}
//	EE corrections for data
	if (eta > 1.5)
		{
//		Use Paolo's run ranges
		int iRun = 0;
		if (run <= 167913)			iRun = 0;
		if (run > 167913 && run <= 172619)	iRun = 1;
		if (run > 172619 && run <= 173692)	iRun = 2;
		if (run > 173692 && run <= 177139)	iRun = 3;
		if (run > 177139 && run <= 178421)	iRun = 4;
		if (run > 178421)			iRun = 5;

		float eeCorr1[6] = {	1 - 1.28/mz,
					1 - 2.90/mz,
					1 - 1.65/mz,
					1 - 3.70/mz,
					1 - 4.14/mz,
					1 - 4.14/mz};

		float eeCorr2[6] = {	1 + 3.00/mz,
					1 - 1.85/mz,
					1 - 1.84/mz,
					1 - 1.33/mz,
					1 - 2.05/mz,
					1 - 1.62/mz};

		if ( eta < 2.0 )
			{
			en *= eeCorr1[iRun];
			if (checkEvent) cout << "Energy correction Step 1 : " << en << endl;
			if ( r9 <= 0.94 ) en *= 1 + scaleDataCorrEE[1]/mz;
			if (checkEvent) cout << "Energy correction Step 2 : " << en << endl;
			}
		else
			{
			en *= eeCorr2[iRun];
			if (checkEvent) cout << "Energy correction Step 1 : " << en << endl;
			if ( r9 <= 0.94 ) en *= 1 + scaleDataCorrEE[3]/mz;
			if (checkEvent) cout << "Energy correction Step 2 : " << en << endl;
			}
		}
	return en;
	}
// ======================================================================

// ///////////////////// //
// // Main Subroutine // //
// ///////////////////// //

int main (int argc, char* argv[]) 
	{
	int eventCounter = 1;
	FILE * pFile;
	pFile = fopen ("dataList.txt" , "a");

	map<string, double> angleMap, angleMap_bg, TangleMap;;
	TangleMap["cosThetaL"];
	TangleMap["cosThetaZ"];
	TangleMap["phiL"];
	TangleMap["phiZ"];
	TangleMap["phi"];
	TangleMap["phi_cm"];
	TangleMap["ZMass"];
	TangleMap["ZGMass"];

	TTree * outTree = new TTree("angles", "qq->Zgamma->llgamma angles");
	for (map<string, double>::iterator mi = TangleMap.begin(); mi != TangleMap.end(); mi++)
		{
		string name = mi->first;
		string leafList = name + "/D";
		outTree->Branch(name.c_str(), &(mi->second), leafList.c_str());
		}

	// ////////////////////////// //
	// // Command Line Options // //
	// ////////////////////////// //

//	Tell people what this analysis code does and setup default options.
	optutl::CommandLineParser parser ("make ZGamma plots");
	parser.addOption ("CheckDub",		CommandLineParser::kBool,	"CheckDublicate",		false);
	parser.addOption ("matchMC",		CommandLineParser::kBool,	"matchObjectsToMc",		false);
	parser.addOption ("removeMcPhoJ",	CommandLineParser::kBool,	"remove mc photons from Zjets",	false);
	parser.addOption ("photonID",		CommandLineParser::kInteger,	"specify photon ID",		-1);
	parser.addOption ("electronID",		CommandLineParser::kInteger,	"specify electron ID",		-1);
	parser.addOption ("muonID",		CommandLineParser::kInteger,	"specify muon ID",		-1);
	parser.addOption ("Run",		CommandLineParser::kInteger,	"specify 2011A or 2011B",	-1);
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
	bool	CheckDub		= parser.boolValue    ("CheckDub"  );
	bool	matchMC			= parser.boolValue    ("matchMC"   );
	bool	removeMcPhoJ		= parser.boolValue    ("removeMcPhoJ");
	int	photonID		= parser.integerValue ("photonID"  );
	int	electronID		= parser.integerValue ("electronID");
	int	muonID			= parser.integerValue ("muonID"    );
	int	Run			= parser.integerValue ("Run"    );

	bool RunA = (Run == 1);
	bool RunB = (Run == 2);
	bool RunAB = (RunA && RunB);

	if (RunA) cout << " ============ IT IS Run 2011A ===============" << endl;
	if (RunB) cout << " ============ IT IS Run 2011B ===============" << endl;
	if (RunAB) cout << " ============ IT IS Run 2011A and 2011B ===============" << endl;

	string iFile;

	if (!fileNames.size())
		{
		cout << "\nPLEASE PROVIDE INPUT FILE!!!!\n" << endl;
		return 0;
		}
	else  iFile = fileNames.at(0); // for now only 1 file at a time

//	get file name from path
//	size_t pos    = iFile.find_last_of('/');
//	string FILE   = iFile.substr(pos+1);

//	translate string to char for filenames
	char iF[200];
	char oF[200];
	sprintf(iF, "%s", iFile.c_str());
	sprintf(oF, "%s", outfileName.c_str());

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

	f_out->cd();
//	histos for background template method scale factor calculations (comment sigmaIetaIeta in photon Id for these)
	double Pho_Pt(0);
	double Pho_Eta(99);
	double Pho_SigmaIEtaIEta(99);

	TTree *tree_Data = new TTree("DataTree", "Data");
	tree_Data->Branch("Pho_Pt", &Pho_Pt, "Pho_Pt/D");
	tree_Data->Branch("Pho_Eta", &Pho_Eta, "Pho_Eta/D");
	tree_Data->Branch("Pho_SigmaIEtaIEta", &Pho_SigmaIEtaIEta, "Pho_SigmaIEtaIEta/D");

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
	TH1F* ZGpt		= new TH1F("ZGpt",		"", 20,			0,		100);
	TH1F* ZGMass		= new TH1F("ZGMass",		"", 28,			60,		300);
	TH2F* ZM_ZgM		= new TH2F("ZM_ZgM",		"", 16,			40,		120, 28, 60, 200);

	TH1F* _nVtx		= new TH1F("nVtx",		"", 50,			0,		25);
	TH1F* _nJet		= new TH1F("nJet",		"", 50,			0,		10);


	Float_t EtBins[7]={30,35,40,60,90,120,500};
	TH1F* _GammaEt_bg	= new TH1F("_GammaEt_bg",	"", 6,			EtBins);
	TH1F* _GammaEt_sig	= new TH1F("_GammaEt_sig",	"", 6,			EtBins);
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
	TH1F* ZGMass_bg		= new TH1F("ZGMass_bg",		"", 28,			60,		300);

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
	TH1F* _cosThetaL	= new TH1F("_cosThetaL",	"cos(#theta_{l})", 40,	-1,		1);
	TH1F* _cosThetaL_bg	= new TH1F("_cosThetaL_bg",	"cos(#theta_{l})", 40,	-1,		1);
	TH1F* _cosThetaL_FSR	= new TH1F("_cosThetaL_FSR",	"cos(#theta_{l})", 20,	-1,		1);

	TH1F* _cosThetaZ	= new TH1F("_cosThetaZ",	"cos(#theta_{Z})", 40,	-1,		1);
	TH1F* _cosThetaZ_bg	= new TH1F("_cosThetaZ_bg",	"cos(#theta_{Z})", 40,	-1,		1);

	TH1F* _phiL		= new TH1F("_phiL",		"", 20,			-3.14,		3.14);
	TH1F* _phiZ		= new TH1F("_phiZ",		"", 20,			-3.14,		3.14);

//	DEFINE SOME CUTS AND VARIABLES USED IN CALCULATIONS, making similar structure to taiwan script
	float AntiUEB=999;
	float AntiUEE=999;
	float AntiLEB=3;
	float AntiLEE=3;

	float dRcut = 0.7; 
	float phoEtCut = 30;
	float lepPtCut = 20;

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
//	====== initiate branches
//	====== set branches
//	====== set address
//	==================================================================

	// //////////////// //
	// // Event Loop // //
	// //////////////// //

	FILE * myBKGDFile;
	myBKGDFile = fopen("myBKGDFile.txt", "a");

	map<int, int> bkgdYield;
	for (int myI = 0; myI < 8; myI++) bkgdYield[myI] = 0;

	typedef vgamma::PhosphorCorrectionFunctor Corrector;
	Corrector getCorrectedPhotonPt_Data(Corrector::kRealData, "");
	for (long index = 0; index < nEvents; ++index )
		{
//		progress
		if (index % 10000 == 0 )
			{
			float perc = float(index)*100./float(nEvents);
			printf("Processed Events\t%ld\t\t%.0f %%\n",index, perc);
			}

//		get current entry from the tree
		tr->GetEntry(index);

//		search for dublicates, by default off
		bool isDub = false;
		if (CheckDub)
			{
			for (int iR = 0; iR < int(RUNS.size()); iR++)
				{
				cout << run << "\t" << lumis << "\t" << event << "\t" << RUNS.at(iR) << "\t" << LUMIS.at(iR) << "\t" << EVENTS.at(iR) << "\t" << endl;
				if (run == RUNS.at(iR) && lumis == LUMIS.at(iR) && event == EVENTS.at(iR))
				isDub = true;
				}
			if (isDub) continue;
			}
//		which value to fill in counter histrogram (nPassed) first
		int passBin = 1;
		bool checkEvent = false;

		if (run == 170722) continue; //removed becase JSON wasn't good which was used to make the datasets bla bla bla

		if (run == 166514 && event == 77399749) checkEvent = true;

		fillNPassed(passBin,nPassed,nPassedMap,"CHECK POINT");
		if (checkEvent) cout << "CHECKING" << endl;

		if (nVtx == 0) continue;
		fillNPassed(passBin,nPassed,nPassedMap,"any Vertex");
		if (checkEvent) cout << "Any Vertex!!!!!!" << endl;
  
                nGoodVtx = 0;
                for (int iVtx = 0; iVtx <= nVtx; iVtx++)
                        if (vtxNDF[iVtx] >= 4 && fabs(vtx[iVtx][2]) <= 24 && fabs(vtxD0[iVtx]) <= 2) nGoodVtx++;
                if (nGoodVtx == 0) continue;
//		if (IsVtxGood == 0) continue;
		fillNPassed(passBin,nPassed,nPassedMap,"good Vertex");
		if (checkEvent) cout << "GOOD Vertex!!!!!!" << endl;
  
		if (IsTracksGood == 0) continue;
		fillNPassed(passBin,nPassed,nPassedMap,"good Tracks");
		if (checkEvent) cout << "Good Tracks!!!!!!" << endl;

		vector<int> cleanPho;
		vector<int> cleanDRPho;
		vector<int> cleanEle;
		vector<int> cleanMu;
		vector<int> goodPho;
		vector<int> goodLep;

		vector<int> nonIsoPho;

//		clean photon selection -------------------------------------------------------------
		for (int iPho = 0; iPho < nPho; iPho++)
			{
			if (checkEvent) cout << "Et = " << phoE[iPho] << " - ";
			double tempEt = phoEt[iPho];
			phoEt[iPho] = getCorrectedPhotonPt_Data(phoEt[iPho], phoSCEta[iPho], run);
//			phoE[iPho] = corrVgamma(phoE[iPho], phoSCEta[iPho], phoR9[iPho], run, checkEvent);
			if (checkEvent) cout << "Et = " << phoE[iPho] << endl;

			double correctionFactor = phoEt[iPho] / tempEt; 

			if (checkEvent) cout << "E = " << phoEt[iPho] << " - ";
			phoE[iPho] *= correctionFactor;
			if (checkEvent) cout << "E = " << phoEt[iPho] << endl;

//			ET cut
			if (phoEt[iPho] < phoEtCut)	continue;
			if (checkEvent) cout << "Et cut passed!!!!!!" << endl;

			if (fabs(phoSCEta[iPho])> 2.5)	continue;
			if (checkEvent) cout << "eta passed!!!!!!" << endl;

			if (fabs(phoSCEta[iPho]) > 1.4442 && fabs(phoSCEta[iPho]) < 1.566 ) continue;
			if (checkEvent) cout << "eta 2 passed!!!!!!" << endl;

			if (phoHoverE[iPho] > 0.5 )	continue;
			if (checkEvent) cout << "phoHoverE passd = " << phoHoverE[iPho] << endl;

//			if (phoOverlap[iPho] == 1)	continue;
			if (phohasPixelSeed[iPho] == 1)	continue;
			if (checkEvent) cout << "pixel seed!!!!!!" << endl;

			cleanPho.push_back(iPho);
			}

		if (cleanPho.size() == 0) continue;
		fillNPassed(passBin,nPassed,nPassedMap,"at least 1 clean photon");
		if (checkEvent) cout << "1 clean photon!!!!!!" << endl;

//		------------------------------------------------------------------------------------

		if (doEEG)
			for (int iEle=0; iEle < nEle; iEle++)
				{
				float eleR9 = eleE3x3[iEle] / eleSCRawEn[iEle];
				if (checkEvent) cout << "eleEn = " << eleEn[iEle] << " - ";
				double tempE = eleEn[iEle];
				eleEn[iEle] = corrVgamma(eleEn[iEle], eleSCEta[iEle], eleR9, run, checkEvent);
				if (checkEvent) cout << eleEn[iEle] << endl;

				double correctionFactor = eleEn[iEle] / tempE;

				if (checkEvent) cout << "elePt = " << elePt[iEle] << " - ";
				elePt[iEle] *= correctionFactor;
				if (checkEvent) cout << elePt[iEle] << endl;

				if (elePt[iEle] < lepPtCut) continue;
				if (fabs(eleSCEta[iEle]) > 2.5 || ( fabs(eleSCEta[iEle]) > 1.4442 && fabs(eleSCEta[iEle]) < 1.566) ) continue;

				cleanEle.push_back(iEle);
				}
  
		if (doMMG)
			for (int iMu=0; iMu < nMu; iMu++)
				{
				if (muPt[iMu] < lepPtCut) continue;
				if ( fabs(muEta[iMu]) > 2.4 ) continue;
				if ( muType[iMu] != 14) continue; // isGlobal && Tracker

				cleanMu.push_back(iMu);
				}
		if (doEEG && cleanEle.size()<2) continue;
		if (doMMG && cleanMu.size()<2) continue;

		fillNPassed(passBin,nPassed,nPassedMap,"at least 2 clean leptons");
		if (checkEvent) cout << "2 clean leptons!!!!!!" << endl;
  

		if (doEEG)
			for ( vector<int>::iterator it = cleanEle.begin(); it != cleanEle.end(); it++)
				{
				_cleanLepPt->Fill(elePt[*it]);
				bool pass = electronId( eleIsoHcalSolidDR03[*it],
							eleSCEta[*it],
							rho,
							eleIsoTrkDR03[*it],
							eleIsoEcalDR03[*it],
							elePt[*it],
							eledPhiAtVtx[*it],
							eledEtaAtVtx[*it],
							eleSigmaIEtaIEta[*it],
							eleSigmaIPhiIPhi[*it],
							run,
							checkEvent,
							eleSeverity[*it],
							elePVD0[*it], elePVDz[*it]);

				if (!pass) continue;
				_goodLepPt->Fill(elePt[*it]);

				if (checkEvent) cout << "electronId passed!!!!!!" << endl;

				int ind1 = HLTIndex[83];
				int ind2 = HLTIndex[86];

				bool eleTrigger1 = false; 
				bool eleTrigger2 = false; 

				if (ind1 >= 0 && HLTprescale[ind1] == 1) eleTrigger1 = (eleTrg[*it][18] > 0);
				if (ind2 >= 0 && HLTprescale[ind2] == 1) eleTrigger2 = (eleTrg[*it][21] > 0);

				if (!(eleTrigger1 || eleTrigger2)) continue;
				if (checkEvent) cout << "HLT passed!!!!!!" << endl;

				if (checkEvent)
					cout << "conversion : " << eleConvMissinghit[*it] << " - " << fabs(eleConvDist[*it]) << " - " << fabs(eleConvDcot[*it]) << endl;
				if (!(eleConvMissinghit[*it] == 0 && (fabs(eleConvDist[*it]) > 0.02 || fabs(eleConvDcot[*it]) > 0.02))) continue;
//				if (!doOnceConv) continue;

				if (checkEvent) cout << "conversion passed!!!!!!" << endl;

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

				_goodLepPt->Fill(muPt[*it]);
				goodLep.push_back(*it);
				}
  
		if ( goodLep.size() < 2 ) continue;
		fillNPassed(passBin,nPassed,nPassedMap,"required 2 good leptons");

		if (checkEvent) cout << "2 good leptons!!!!!!" << endl;
  
		int lep1ind  = int (goodLep.at(0));
		int lep2ind  = int (goodLep.at(1));

		if (doEEG)
			{
			if ((eleCharge[lep1ind] + eleCharge[lep2ind]) != 0) continue;
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
			if ((muCharge[lep1ind] + muCharge[lep2ind]) != 0) continue;
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
//		lep1.SetPtEtaPhiE(elePt[lep1ind],eleEta[lep1ind],elePhi[lep1ind],eleEn[lep1ind]);
//		lep2.SetPtEtaPhiE(elePt[lep2ind],eleEta[lep2ind],elePhi[lep2ind],eleEn[lep2ind]);

		ll = lep1+lep2;
  
		ZMass_noPho->Fill(ll.M());
		for (int pho = 0; pho <  int (cleanPho.size()); pho++)
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

		fillNPassed(passBin,nPassed,nPassedMap,"at least 1 pho > dR");
		if (checkEvent) cout << "pho > dR!!!!!!" << endl;

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
//			float eta = fabs(phoEta[phoind]);

			if (photonID >= 0)
				{
				bool photonPass = false;
				photonPass = photonId(	phoEcalIsoDR04[phoind],
							phoHcalIsoDR04[phoind],
							phoTrkIsoHollowDR04[phoind],
							phoSCEta[phoind],
							phoHoverE[phoind],
							phoSigmaIEtaIEta[phoind],
							phoSigmaIPhiIPhi[phoind],
							phoEt[phoind],
							rho, phoSeverity[phoind],
							run, checkEvent);
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
//============================================================

		if (goodPho.size() == 0) continue;
		fillNPassed(passBin,nPassed,nPassedMap,"at least 1 good photon");
		if (checkEvent) cout << "1 good photon!!!!!!" << endl;

		int phoind = goodPho.at(0);
		gamma.SetPtEtaPhiE(phoEt[phoind],phoEta[phoind],phoPhi[phoind],phoE[phoind]);

		llg = ll+gamma;
		if (ll.M() < 0) cout << "ERROOOOOOOOOOOOOOOOOOOOOOOR!!!!!!!! - " << ll.M() << "; run = " << run << "; event = " << event << endl;
		if (checkEvent) cout << "M(Z) = " << ll.M() << endl;
		if (ll.M() < 50) continue;
		fillNPassed(passBin,nPassed,nPassedMap,"ZMass < 50");
		if (checkEvent) cout << " > 50!!!!!!\n - - EVENT SELECTED - - " << endl;

//		========= WRITING OUTPUT EVENT FILE ===============================
		fprintf(pFile, "#Zgamma:\t%d\trun:\t%d\tlumi%d\tevent:\t%ld\n", eventCounter, run, lumis, event);
		eventCounter++;
//		===================================================================

//		ANGLE CALCULATIONS
		angleMap = zgammaAngleCalculator(lep1, lep2, gamma);
		TangleMap["cosThetaL"] = angleMap["cosThetaL"];
		TangleMap["cosThetaZ"] = angleMap["cosThetaZ"];
		TangleMap["phiL"] = angleMap["phiL"];
		TangleMap["phiZ"] = angleMap["phiZ"];
		TangleMap["phi"] = angleMap["phi"];
		TangleMap["phi_cm"] = angleMap["phi_cm"];
		TangleMap["ZMass"] = ll.M();
		TangleMap["ZGMass"] = llg.M();

		if ((llg.M() + ll.M() ) < 200)
			{
			_cosThetaL_FSR->Fill(angleMap["cosThetaL"]);
			continue;
			}
		fillNPassed(passBin,nPassed,nPassedMap,"ZgammaMass + ZMass > 200");

//		if (angleMap["cosThetaZ"] > 0.9) continue;
//		fillNPassed(passBin,nPassed,nPassedMap,"cosThetaZs < 0.9");

//		BACKGROUND BY TEMPLATE METHOD =====================================
		float photonPT = phoEt[phoind];

//		Vgamma group version where I think RunA and RunB separately are screwed up, so I am trying AB for both
/*
		int RatIndex = 6;
		if (photonPT >= 15 && photonPT < 20 ) RatIndex = 0;
		if (photonPT >= 20 && photonPT < 25 ) RatIndex = 1;
		if (photonPT >= 25 && photonPT < 30 ) RatIndex = 2;
		if (photonPT >= 30 && photonPT < 35 ) RatIndex = 3;
		if (photonPT >= 35 && photonPT < 40 ) RatIndex = 4;
		if (photonPT >= 40 && photonPT < 60 ) RatIndex = 5;
		if (photonPT >= 60 && photonPT < 90 ) RatIndex = 6;
		if (photonPT >= 90                  ) RatIndex = 7;
		if (RunAB)
			{
			if (photonPT >= 90 && photonPT < 120) RatIndex = 7;
			if (photonPT >= 120                 ) RatIndex = 8;
			}
*/
		int RatIndex = 6;
		if (photonPT >= 15 && photonPT < 20 ) RatIndex = 0;
		if (photonPT >= 20 && photonPT < 25 ) RatIndex = 1;
		if (photonPT >= 25 && photonPT < 30 ) RatIndex = 2;
		if (photonPT >= 30 && photonPT < 35 ) RatIndex = 3;
		if (photonPT >= 35 && photonPT < 40 ) RatIndex = 4;
		if (photonPT >= 40 && photonPT < 60 ) RatIndex = 5;
		if (photonPT >= 60 && photonPT < 90 ) RatIndex = 6;
		if (photonPT >= 90 && photonPT < 120) RatIndex = 7;
		if (photonPT >= 120                 ) RatIndex = 8;

		bkgdYield[RatIndex]++;


//		template method scale factors from Kuan-Hsin (Electrons)
		double ratScale_EB_Ele_RunA[8] = {0.18, 0.14, 0.10, 0.18, 0.31, 0.10, 0.19, 0.21};
		double ratScale_EE_Ele_RunA[8] = {0.34, 0.23, 0.15, 0.25, 0.28, 0.24, 0.11, 0.00};

		double ratScale_EB_Ele_RunB[8] = {0.25, 0.20, 0.16, 0.16, 0.32, 0.20, 0.19, 0.00};
		double ratScale_EE_Ele_RunB[8] = {0.40, 0.37, 0.38, 0.22, 0.53, 0.16, 0.11, 0.00};


		double ratScale_EB_Ele_RunCombined[9] = {0.22, 0.17, 0.13, 0.17, 0.31, 0.14, 0.17, 0.00, 0.29};
		double ratScale_EE_Ele_RunCombined[9] = {0.40, 0.29, 0.24, 0.24, 0.40, 0.19, 0.11, 0.00, 0.00};

//		template method scale factors from Irakli S. (Muons)
		double ratScale_EB_Mu_RunA[8] = {0.17, 0.14, 0.17, 0.14, 0.25, 0.16, 0.13, 0.09};
		double ratScale_EE_Mu_RunA[8] = {0.34, 0.23, 0.23, 0.35, 0.28, 0.38, 0.13, 0.51};

		double ratScale_EB_Mu_RunB[8] = {0.24, 0.18, 0.15, 0.22, 0.21, 0.12, 0.21, 0.36};
		double ratScale_EE_Mu_RunB[8] = {0.31, 0.33, 0.27, 0.27, 0.20, 0.21, 0.18, 0.81};

		double ratScale_EB_Mu_RunCombined[9] = {0.22, 0.16, 0.16, 0.19, 0.22, 0.14, 0.16, 0.24, 0.00};
		double ratScale_EE_Mu_RunCombined[9] = {0.34, 0.28, 0.24, 0.31, 0.24, 0.27, 0.16, 0.54, 0.83};

		double ratScale_EB[9]={0, 0, 0, 0, 0, 0, 0, 0, 0};
		double ratScale_EE[9]={0, 0, 0, 0, 0, 0, 0, 0, 0};

//		I am removing this separate version because I think the scale factors are wrong
/*
		if (!RunAB)
			for (int ii = 0; ii < 8; ii++)
				{
				if (doMMG)
					{
					if(RunA)
						{
						ratScale_EB[ii] = ratScale_EB_Mu_RunA[ii];
						ratScale_EE[ii] = ratScale_EE_Mu_RunA[ii];
						}
					if(RunB)
						{
						ratScale_EB[ii] = ratScale_EB_Mu_RunB[ii];
						ratScale_EE[ii] = ratScale_EE_Mu_RunB[ii];
						}
					}
				if (doEEG)
					{
					if(RunA)
						{
						ratScale_EB[ii] = ratScale_EB_Ele_RunA[ii];
						ratScale_EE[ii] = ratScale_EE_Ele_RunA[ii];
						}
					if(RunB)
						{
						ratScale_EB[ii] = ratScale_EB_Ele_RunB[ii];
						ratScale_EE[ii] = ratScale_EE_Ele_RunB[ii];
						}
					}
				}
		else

*/
		for (int ii = 0; ii < 9; ii++)
			{
			if (doMMG)
				{
				ratScale_EB[ii] = ratScale_EB_Mu_RunCombined[ii];
				ratScale_EE[ii] = ratScale_EE_Mu_RunCombined[ii];
				}
			if (doEEG)
				{
				ratScale_EB[ii] = ratScale_EB_Ele_RunCombined[ii];
				ratScale_EE[ii] = ratScale_EE_Ele_RunCombined[ii];
				}
			}

		if (fabs(phoSCEta[phoind]) < 1.4442 )
			{
			_GammaEt_bg->Fill(phoEt[phoind], ratScale_EB[RatIndex]);
			_GammaEt_sig->Fill(phoEt[phoind]);
			_cosThetaZ_bg->Fill(angleMap["cosThetaZ"], ratScale_EB[RatIndex]);
			_cosThetaL_bg->Fill(angleMap["cosThetaL"], ratScale_EB[RatIndex]);
			}
		else
			{
			_GammaEt_bg->Fill(phoEt[phoind], ratScale_EE[RatIndex]);
			_GammaEt_sig->Fill(phoEt[phoind]);
			_cosThetaZ_bg->Fill(angleMap["cosThetaZ"], ratScale_EE[RatIndex]);
			_cosThetaL_bg->Fill(angleMap["cosThetaL"], ratScale_EE[RatIndex]);
			}
//		===================================================================
		Pho_Pt			= phoEt[phoind];
		Pho_Eta			= phoSCEta[phoind];
		Pho_SigmaIEtaIEta	= phoSigmaIEtaIEta[ phoind];
		tree_Data->Fill();
//		===================================================================
		_cosThetaL->Fill(angleMap["cosThetaL"]);

		_cosThetaZ->Fill(angleMap["cosThetaZ"]);

		_phiL->Fill(angleMap["phiL"]);
		_phiZ->Fill(angleMap["phiZ"]);
//		END OF ANGLE CALCULATIONS

		photonEt = phoEt[phoind];
		photonTree->Fill();
		_GammaEt     ->Fill(phoEt[            phoind]);
		_GammaEta    ->Fill(phoEta[           phoind]);
		_GammaPhi    ->Fill(phoPhi[           phoind]);
		_GammaHoE    ->Fill(phoHoverE[        phoind]);
		_GammaSigIEIE->Fill(phoSigmaIEtaIEta[ phoind]);
		_GammaEcalIso->Fill(phoEcalIsoDR04[phoind]);
		_GammaHcalIso->Fill(phoHcalIsoDR04[phoind]);
		_GammaTrkIso ->Fill(phoTrkIsoHollowDR04[phoind]);
//		_Gamma_eIso  ->Fill(phoEcalIsoDR04[phoind]      - phoIdCuts_eScale[photonID]*phoEt[phoind]);
//		_Gamma_hIso  ->Fill(phoHcalIsoDR04[phoind]      - phoIdCuts_hScale[photonID]*phoEt[phoind]);
//		_Gamma_tIso  ->Fill(phoTrkIsoHollowDR04[phoind] - phoIdCuts_tScale[photonID]*phoEt[phoind]);

		ZGMass->Fill(llg.M());
		ZGpt  ->Fill(llg.Pt());
		ZMass ->Fill(ll.M());
		_nVtx ->Fill(nVtx);
		_nJet ->Fill(nJet);
		ZM_ZgM->Fill(ll.M(),llg.M());

		float dR1 = 0;
		float dR2 = 0;

		if (doEEG)
			{
			dR1  = reco::deltaR( phoEta[phoind], phoPhi[phoind], eleEta[lep1ind], elePhi[lep1ind]);
			dR2  = reco::deltaR( phoEta[phoind], phoPhi[phoind], eleEta[lep2ind], elePhi[lep2ind]);
			Leg1Pt->Fill(elePt[lep1ind]);
			Leg2Pt->Fill(elePt[lep2ind]);
			}
		if (doMMG)
			{
			dR1  = reco::deltaR( phoEta[phoind], phoPhi[phoind], muEta[lep1ind], muPhi[lep1ind]);
			dR2  = reco::deltaR( phoEta[phoind], phoPhi[phoind], muEta[lep2ind], muPhi[lep2ind]);
			Leg1Pt->Fill(muPt[lep1ind]);
			Leg2Pt->Fill(muPt[lep2ind]);
			}
		dRLeg1Gamma->Fill(dR1);
		dRLeg2Gamma->Fill(dR2);

		if (dR1 < dR2)	dRGamma->Fill(dR1);
		else		dRGamma->Fill(dR2);
		outTree->Fill();

		} // END OF EVENT LOOP 

	outTree->Write();
	_cosThetaL->Write();
	_cosThetaL_FSR->Write();
	_cosThetaL_bg->Write();

	_cosThetaZ->Write();
	_cosThetaZ_bg->Write();

//	_thetaZ->Write();
	_phiL->Write();
	_phiZ->Write();

	dRLeg1Gamma->Write();
	dRLeg2Gamma->Write();
	dRGamma->Write();
	ZMass->Write();
	ZMass_noPho->Write();
	_nVtx->Write();
	_nJet->Write();
	ZMass_bg->Write();
	ZGMass->Write();
	ZGMass_bg->Write();
	ZGpt->Write();
	ZM_ZgM->Write();
	hEvents->Write();
	nPassed->Write();

	_GammaEt_bg->Write();
	_GammaEt_sig->Write();
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
	tree_Data->Write();
	photonTree->Write();

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

	for (map<int,int>::iterator mit = bkgdYield.begin(); mit != bkgdYield.end(); mit++)
		fprintf(myBKGDFile, "%d : %d\n", mit->first, mit->second);

	fclose(myBKGDFile);


	cout << "\n<----------------------DONE \n" << endl;
	return 0;
	}
