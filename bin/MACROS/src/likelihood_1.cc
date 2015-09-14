#include <iostream>
#include <map>
#include <string>
#include <stdio.h>

#include <math.h>
#include <vector>
#include <TCanvas.h>
#include <TF1.h>
#include <TH1.h>
#include <TGraph.h>
#include <TLegend.h>
#include <TROOT.h>
#include <TStyle.h>
#include <TLatex.h>
#include <THStack.h>
#include <TTree.h>

#include "../include/plotter.h"
#include "../include/likelihoodFunc.h"

using namespace std;
//==========================================================================================
int main()
	{
	map<string, TObject *> objMap;
	objMap = objToMap("../input/histos_baur_tree.root");
	TTree * anglesTree = (TTree*) objMap["angles"];

	Long64_t nentries = anglesTree->GetEntries();

//	Declaration of leaf types
	Double_t        cosThetaL_cm;
	Double_t        cosThetaZ_cm;
	Double_t        phiL;
	Double_t        phiZ;

//	List of branches
	TBranch        *b_cosThetaL_cm;   //!
	TBranch        *b_cosThetaZ_cm;   //!
	TBranch        *b_phiL;   //!
	TBranch        *b_phiZ;   //!

//	fetching branches
	b_cosThetaL_cm = anglesTree->GetBranch("cosThetaL_cm");
	b_cosThetaZ_cm = anglesTree->GetBranch("cosThetaZ_cm");
	b_phiZ = anglesTree->GetBranch("phiZ");
	b_phiL = anglesTree->GetBranch("phiL");

//	linking branch to variable
	b_cosThetaL_cm->SetAddress(&cosThetaL_cm);
	b_cosThetaZ_cm->SetAddress(&cosThetaZ_cm);
	b_phiL->SetAddress(&phiL);
	b_phiZ->SetAddress(&phiZ);

	double W = 0;

	for (Long64_t jentry = 0; jentry < nentries; jentry++)
		{
		double pars[1000];
		for (int i = 0; i < 1000; i++)
			{
			pars[i] = (i+1) / 100.;
			}

		anglesTree->GetEntry(jentry);
		double vars[] = {cosThetaL_cm, cosThetaZ_cm, phiL, phiZ};
		W += likelihood(vars, pars);
		}

	cout << W << endl;

	return 0;
	}
//==========================================================================================
