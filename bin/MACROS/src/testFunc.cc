//================================================================================================================
//== Author		: Irakli Chakaberia							 		==
//== Date		: 2010 Dec 10       					                		==
//== Last Update	: 2013 Feb 20							 			==
//== Running		: ./myMinexam [inputFile] [runType ][1/0] [if 0 initParam / if 1 filename with params]	==
//== finalFileName	: is the fileName for file with weights for acceptances					==
//================================================================================================================

#include "TROOT.h"
#include <TTree.h>
#include "TMinuit.h"
#include "TMath.h"
#include "TCanvas.h"
#include "TH1.h"
#include "../include/likelihoodFunc.h"

#include <iostream>
#include <map>
#include "../include/plotter.h"
#include "../include/readParams.h"
// global variables for not doing same routine many times in functions outside this cc file
#include "../include/extern.h"

//#ifdef __SC__
//long G__globalvarpointer; // To make the Symantec linker happy
//#endif

extern void myFcn(Int_t &npar, Double_t *gin, Double_t &f, Double_t *x, Int_t iflag);

using namespace std;

//TH1F * h1 = new TH1F("h1","h1", 200, -40, 80);

vector<vector<double> > varVec;


// arrays for -ln(L) minimization process graph
double X[10000];
double Y[10000];
int  minIterCount = 0;

//==============================================================================
void myFunc(Double_t *x)
	{
	FILE * outFitResultcosL;
	FILE * outFitResultcosZ;
	FILE * outFitResultphiL;
	FILE * outFitResultphiZ;
	outFitResultcosL = fopen("fitGENResultcosL.txt","w");
	outFitResultcosZ = fopen("fitGENResultcosZ.txt","w");
	outFitResultphiL = fopen("fitGENResultphiL.txt","w");
	outFitResultphiZ = fopen("fitGENResultphiZ.txt","w");
	double varsL[10];
	double varsZ[10];

	map<int, double> cosZMap, cosLMap, phiLMap, phiZMap;

	pair<double, double> tempLhoodL;
	pair<double, double> tempLhoodZ;

	cout << "FINAL BIN BY BIN RESULT CALCULATION STARTED!" << endl;

	for (int icosInterest = -975; icosInterest < 1000; icosInterest += 50)
		{
		cout << icosInterest << endl;
		for (int icosIntegral = -975; icosIntegral< 1000; icosIntegral += 50)
			for (double iphiL = -2.983; iphiL < 3.14; iphiL += 0.314)
				for (double iphiZ = -2.983; iphiZ < 3.14; iphiZ += 0.314)
					{
					varsL[0] = (double) icosInterest / 1000.;
					varsL[1] = (double) icosIntegral / 1000.;
					varsL[2] = iphiL;
					varsL[3] = iphiZ;
					varsL[4] = 91.19;
					varsL[5] = 300.0;

					varsZ[0] = (double) icosIntegral / 1000.;
					varsZ[1] = (double) icosInterest / 1000.;
					varsZ[2] = iphiL;
					varsZ[3] = iphiZ;
					varsZ[4] = 91.19;
					varsZ[5] = 300.0;

					tempLhoodL = likelihood(varsL, x);
					tempLhoodZ = likelihood(varsZ, x);

					if (cosLMap.find(icosInterest) == cosLMap.end()) cosLMap[icosInterest] = tempLhoodL.first;
					else cosLMap[icosInterest] += tempLhoodL.first;

					if (cosZMap.find(icosInterest) == cosZMap.end()) cosZMap[icosInterest] = tempLhoodZ.first;
					else cosZMap[icosInterest] += tempLhoodZ.first;
					}
		}

	for (int iphiInterest = -2983; iphiInterest < 3140; iphiInterest += 314) // this is for -3.14 to 3.14 in 20 bins
		{
		cout << iphiInterest << endl;
		for (int iphiIntegral = -2983; iphiIntegral< 3140; iphiIntegral += 314)
			for (double icosL = -0.95; icosL < 1; icosL += 0.1)
				for (double icosZ = -0.95; icosZ < 1; icosZ += 0.1)
					{
					varsL[0] = icosL;
					varsL[1] = icosZ;
					varsL[2] = (double) iphiInterest / 1000.;
					varsL[3] = (double) iphiIntegral / 1000.;
					varsL[4] = 91.19;
					varsL[5] = 300.0;

					varsZ[0] = icosL;
					varsZ[1] = icosZ;
					varsZ[2] = (double) iphiIntegral / 1000.;
					varsZ[3] = (double) iphiInterest / 1000.;
					varsZ[4] = 91.19;
					varsZ[5] = 300.0;

					tempLhoodL = likelihood(varsL, x);
					tempLhoodZ = likelihood(varsZ, x);

					if (phiLMap.find(iphiInterest) == phiLMap.end()) phiLMap[iphiInterest] = tempLhoodL.first;
					else phiLMap[iphiInterest] += tempLhoodL.first;

					if (phiZMap.find(iphiInterest) == phiZMap.end()) phiZMap[iphiInterest] = tempLhoodZ.first;
					else phiZMap[iphiInterest] += tempLhoodZ.first;
					}
		}

	for (map<int, double>::iterator mit = cosLMap.begin(); mit != cosLMap.end(); mit++)
		fprintf(outFitResultcosL, "%f\n", mit->second);
	for (map<int, double>::iterator mit = cosZMap.begin(); mit != cosZMap.end(); mit++)
		fprintf(outFitResultcosZ, "%f\n", mit->second);
	for (map<int, double>::iterator mit = phiLMap.begin(); mit != phiLMap.end(); mit++)
		fprintf(outFitResultphiL, "%f\n", mit->second);
	for (map<int, double>::iterator mit = phiZMap.begin(); mit != phiZMap.end(); mit++)
		fprintf(outFitResultphiZ, "%f\n", mit->second);

	fclose(outFitResultcosL);
	fclose(outFitResultcosZ);
	fclose(outFitResultphiL);
	fclose(outFitResultphiZ);
	}
//==============================================================================
void getVars(string type, string fileName)
	{
//	=====================================================================
	cout << "Reading variables from " << fileName << endl;

	TFile * myFile = new TFile(fileName.c_str());
	TTree * anglesTree;

	if (type == "mc") anglesTree = (TTree*) myFile->GetKey("mcangles")->ReadObj();
	if (type == "mcReco") anglesTree = (TTree*) myFile->GetKey("mcCutangles")->ReadObj();
	if (type == "data") anglesTree = (TTree*) myFile->GetKey("angles")->ReadObj();

	Long64_t nentries = anglesTree->GetEntries();

	// set the number of measurements you want to use by hand, about same as number of events in data, in order to have reasonable job length
	if (nentries > 5000)
		{
		nentries = 5000;
		cout << "LIMITING NUMBER OF EVENTS TO 5000" << endl;
		}

	cout << "Initializing variables" << endl;
//	Declaration of leaf types
	Double_t        ZMass;
	Double_t        ZGMass;
	Double_t        cosThetaL;
	Double_t        cosThetaZ;
	Double_t        phiL;
	Double_t        phiZ;
	Double_t        weights;

//	List of branches
	TBranch        *b_ZMass;   //!
	TBranch        *b_ZGMass;   //!
	TBranch        *b_cosThetaL;   //!
	TBranch        *b_cosThetaZ;   //!
	TBranch        *b_phiL;   //!
	TBranch        *b_phiZ;   //!
	TBranch        *b_weights;   //!

	cout << "Linking Branches" << endl;
//	fetching branches
	b_ZMass = anglesTree->GetBranch("ZMass");
	b_ZGMass = anglesTree->GetBranch("ZGMass");
	b_cosThetaL = anglesTree->GetBranch("cosThetaL");
	b_cosThetaZ = anglesTree->GetBranch("cosThetaZ");
	b_phiZ = anglesTree->GetBranch("phiZ");
	b_phiL = anglesTree->GetBranch("phiL");
	b_weights = anglesTree->GetBranch("weights");

//	linking branch to variable
	b_ZMass->SetAddress(&ZMass);
	b_ZGMass->SetAddress(&ZGMass);
	b_cosThetaL->SetAddress(&cosThetaL);
	b_cosThetaZ->SetAddress(&cosThetaZ);
	b_phiL->SetAddress(&phiL);
	b_phiZ->SetAddress(&phiZ);
	b_weights->SetAddress(&weights);

	double acc = 0;
	bool accOnce = true;
	double nEvents = 0;

	pair<double, double> tempLhood;
	vector<double> var;

	cout << "Filling varVec" << endl;
	for (Long64_t jentry = 0; jentry < nentries; jentry++)
		{
		anglesTree->GetEntry(jentry);

		var.push_back(cosThetaL);
		var.push_back(cosThetaZ);
		var.push_back(phiL);
		var.push_back(phiZ);
		var.push_back(ZMass);
		var.push_back(ZGMass);
		var.push_back(weights);

		varVec.push_back(var);
		var.clear();
		}
	delete anglesTree;
	myFile->Close();
	}
//==============================================================================
int main(int argc, char **arg)
	{
	withTCORR	= false;
	globalJ		= 2;
	runType		= "mc";
	finalFileName	= "../input/histos_MG5_SM_mm_ISR_ONLY.root";
	complexT	= false;
	onceDone = true;

	doIt = false;

	if (argc != 2)
		{
		cout << "please enter <parameterFile>" << endl;
		return 0;
		}
	string parFile = arg[1];

	vector<double> params;
	params = readParams(parFile);

	double x[params.size()/2];

	for (int i = 0; i < params.size() / 2; i++)
		{
		x[i] = params[2*i];
		cout << x[i] << endl;
		}

	myFunc(x);

	return 0;
	}
//==============================================================================

