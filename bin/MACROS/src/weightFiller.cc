#include <iostream>
#include <map>
#include <string>
#include <stdio.h>

#include <math.h>
#include <vector>
#include <TCanvas.h>
#include <TF3.h>
#include <TF1.h>
#include <TF2.h>
#include <TF12.h>
#include <TH3.h>
#include <TH2.h>
#include <TGraph.h>
#include <TLegend.h>
#include <TROOT.h>
#include <TStyle.h>
#include <TLatex.h>
#include <THStack.h>
#include <TTree.h>
#include <TFile.h>

#include "../include/plotter.h"
#include "../include/fitFunc.h"
#include "../include/tChannel.h"

using namespace std;

//==========================================================================================
double weightExtractor(double * var, double * par)
	{
	int c = 0;
	double sum = 0;
	for (int i = 0; i < 3; i++)
		{
		for (int j = 0; j < 11; j++)
			{
			sum += par[c]*pow(var[0], i)*pow(var[1], j);
			c++;
			}
		}
	sum*=tChannel(var[1], 91, 140);
	return sum;
	}
//==========================================================================================
int main(int argc, char **arg)
	{
	string rfileName = "";
	string wfileName = "";
	if (argc != 2)
		{
		cout << "Please enter file you want to fill with event weights" << endl;
		return 0;
		}
	else
		{
		wfileName = arg[1];
		if (std::string::npos != wfileName.find("mm") || std::string::npos != wfileName.find("Mu"))
			rfileName = "../input/histos_MG5_SM_mm_ISR_ONLY.root";
		if (std::string::npos != wfileName.find("ee") || std::string::npos != wfileName.find("Ele"))
			rfileName = "../input/histos_MG5_SM_ee_ISR_ONLY.root";
		}

	bool data = false;
	if (std::string::npos != wfileName.find("Ele") || std::string::npos != wfileName.find("Mu")) data = true;

	if (data) cout << "WORKING WITH REAL DATA" << endl;
	else cout << "WORKING WITH MC" << endl;

	cout << "Reading histogram from " << rfileName << " file" << endl;
	cout << "Filling " << wfileName << " with weights" << endl;

	TFile * readFile = TFile::Open(rfileName.c_str(), "UPDATE");
	TH2F * cosThetaZ_L = (TH2F*) readFile->Get("MC_cosThetaZ_L");

	TFile * outFile = TFile::Open(wfileName.c_str(), "UPDATE");

//	==============================================================================
//	PARAMETRIZING THE cosThetaZ vs. cosThetaL distribution and getting the weights for the events
	TH1::SetDefaultSumw2();
	TH2::SetDefaultSumw2();

	int npar = 33;
	TF2 * fit2 = new TF2("fit2", weightExtractor, -1, 1, -1, 1, npar);
	for (int i = 0; i < npar; i++)
		fit2->SetParameter(i, 1);

	cosThetaZ_L->Fit(fit2);
	double  myPar[npar];
	for (int i = 0; i < npar; i++)
		myPar[i] = fit2->GetParameter(i);

	readFile->Close();
//	=====================================================================
	double weight, mcweight, mcCutweight;

	TTree * anglesTree	= (TTree*) outFile->Get("angles;");				// FOR RECO
	TBranch * angleWeights	= anglesTree->Branch("weights", &weight, "weights /D");

	TTree * mcanglesTree;
	TTree * mcCutanglesTree;

	TBranch * mcangleWeights;
	TBranch * mcCutangleWeights;

	Long64_t nentries	= anglesTree->GetEntries();
	Long64_t mcCutnentries	= 0;
	Long64_t mcnentries	= 0;

//	Declaration of leaf types
	Double_t        cosThetaL;
	Double_t        cosThetaZ;

	Double_t        mc_cosThetaL;
	Double_t        mc_cosThetaZ;

	Double_t        mcCut_cosThetaL;
	Double_t        mcCut_cosThetaZ;

//	List of branches
	TBranch        *b_cosThetaL;   //!
	TBranch        *b_cosThetaZ;   //!

	TBranch        *b_mc_cosThetaL;   //!
	TBranch        *b_mc_cosThetaZ;   //!

	TBranch        *b_mcCut_cosThetaL;   //!
	TBranch        *b_mcCut_cosThetaZ;   //!

//	fetching branches
	b_cosThetaL = anglesTree->GetBranch("cosThetaL");
	b_cosThetaZ = anglesTree->GetBranch("cosThetaZ");

	b_cosThetaL->SetAddress(&cosThetaL);
	b_cosThetaZ->SetAddress(&cosThetaZ);

	if (!data)
		{
		mcanglesTree	= (TTree*) outFile->Get("mcangles;");			// FOR PURE GEN
		mcCutanglesTree	= (TTree*) outFile->Get("mcCutangles;");	// FOR GEN WITH CUTS

		mcCutnentries	= mcCutanglesTree->GetEntries();
		mcnentries	= mcanglesTree->GetEntries();

		mcangleWeights	= mcanglesTree->Branch("weights", &mcweight, "weights /D");
		mcCutangleWeights	= mcCutanglesTree->Branch("weights", &mcCutweight, "weights /D");

		b_mc_cosThetaL = mcanglesTree->GetBranch("cosThetaL");
		b_mc_cosThetaZ = mcanglesTree->GetBranch("cosThetaZ");

		b_mcCut_cosThetaL = mcCutanglesTree->GetBranch("cosThetaL");
		b_mcCut_cosThetaZ = mcCutanglesTree->GetBranch("cosThetaZ");

		b_mc_cosThetaL->SetAddress(&mc_cosThetaL);
		b_mc_cosThetaZ->SetAddress(&mc_cosThetaZ);

		b_mcCut_cosThetaL->SetAddress(&mcCut_cosThetaL);
		b_mcCut_cosThetaZ->SetAddress(&mcCut_cosThetaZ);
		}

	cout << "Variable ready and linked" << endl;

	for (Long64_t jentry = 0; jentry < nentries; jentry++)
		{
		anglesTree->GetEntry(jentry);

		double myVar[2];
		myVar[0] = cosThetaL;
		myVar[1] = cosThetaZ;

		weight = weightExtractor(myVar, myPar);
		angleWeights->Fill();
		}
	if (!data)
		{
		for (Long64_t jentry = 0; jentry < mcnentries; jentry++)
			{
			mcanglesTree->GetEntry(jentry);

			double myVar[2];
			myVar[0] = mc_cosThetaL;
			myVar[1] = mc_cosThetaZ;

			mcweight = weightExtractor(myVar, myPar);
			mcangleWeights->Fill();
			}
		for (Long64_t jentry = 0; jentry < mcCutnentries; jentry++)
			{
			mcCutanglesTree->GetEntry(jentry);

			double myVar[2];
			myVar[0] = mcCut_cosThetaL;
			myVar[1] = mcCut_cosThetaZ;

			mcCutweight = weightExtractor(myVar, myPar);
			mcCutangleWeights->Fill();
			}
		}

	anglesTree->Write("", TObject::kOverwrite);
	if (!data) mcanglesTree->Write("", TObject::kOverwrite);
	if (!data) mcCutanglesTree->Write("", TObject::kOverwrite);

	outFile->Close();

	delete outFile;
	delete readFile;

	return 0;
	}
//==========================================================================================
