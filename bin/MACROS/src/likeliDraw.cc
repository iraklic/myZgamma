#include <iostream>
#include <map>
#include <string>
#include <stdio.h>

#include <math.h>
#include <vector>
#include <TTree.h>
#include <TCanvas.h>
#include <TF3.h>
#include <TF1.h>
#include <TF2.h>
#include <TF12.h>
#include <TH3.h>
#include <TH2.h>
#include <TH1.h>
#include <TGraph.h>
#include <TLegend.h>
#include <TROOT.h>
#include <TStyle.h>
#include <TLatex.h>
#include <THStack.h>

#include "../include/plotter.h"
//#include "../include/fitFunc.h"
#include "../include/likelihoodFunc.h"

using namespace std;

//==========================================================================================
double likeliDraw(double * var, double * par)
	{
	double vars[4];
	vars[0] = var[0];
	vars[1] = var[1];
	vars[2] = 0;
	vars[3] = 0;

	return likelihood(vars, par).first;
	}

double likeliDrawPhiL(double * var, double * par)
	{
	double vars[4];
	vars[0] = 0.95;
	vars[1] = 0.95;
	vars[2] = var[0];
	vars[3] = 0;

	double res = likelihood(vars, par).first;
	return res;
	}

double likeliDrawPhiZ(double * var, double * par)
	{
	double vars[4];
	vars[0] = 0.95;
	vars[1] = 0.95;
	vars[2] = 0;
	vars[3] = var[0];

	double res = likelihood(vars, par).first;
	return res;
	}

double likeliDrawCosThetaL(double * var, double * par)
	{
	double vars[4];
	vars[0] = var[0];
	vars[1] = 0.95;
	vars[2] = 0;
	vars[3] = 0;

	double res = likelihood(vars, par).first;
	return res;
	}

double likeliDrawCosThetaZ(double * var, double * par)
	{
	double vars[4];
	vars[0] = 0.95;
	vars[1] = var[0];
	vars[2] = 0;
	vars[3] = 0;

	double res = likelihood(vars, par).first;
	return res;
	}


int main()
	{
	gStyle->SetOptStat(0);
	gStyle->SetPalette(1);

	double min = 0.9;
	double max = 1;
	double point = (min + max)/2;
	int npar = 41;

//	double var[4] = {0.3, 0.4, 1.2, 0.7};

	double par[41] = {
//SM J <= 2
0.174560, 
0.586395 ,
1.095979 ,
0.046825 ,
-2.656078,
-0.832641,
-0.373545,
0.260122 ,
1.069062 ,
-0.082047,
-0.287532,
6.531704 ,
0.198234 ,
0.052983 ,
0.645893 ,
-0.039614,
-1.606673,
-0.121719,
0.679292 ,
-0.101153,
0.168079 ,
0.274040 ,
0.578503 ,
-0.268589,
0.477243 ,
1.372712 ,
0.971304 ,
0.388814 ,
-1.501095,
5.695551 ,
0.841537 ,
0.752454 ,
0.452569 ,
-1.520189,
3.136121 ,
1.334538 ,
1.359682 ,
0.814813 ,
1.890445 ,
3.155210 ,
-0.355729


/*
//TGC J <= 1
0.292206 ,
0.747203 ,
-0.199070,
0.540589 ,
-0.836476,
3.471991 ,
0.266722 ,
0.333053 ,
2.000626 ,
0.213677 ,
0.667999 ,
0.622064 ,
0.205725 ,
0.566446 ,
-0.255872,
-0.335816,
1.664900 ,
0.676961 ,
2.214945 ,
2.055665 ,
-1.037771,
-0.438558,
0.681380  
*/

/*
//SM J <= 1
-2.81697e-01,
 7.35900e-01,
 1.36611e+00,
 3.55307e-01,
 7.43098e-01,
 3.87615e+00,
 3.68741e-01,
-3.45529e-01,
 1.46371e+00,
 3.40025e-01,
 1.33415e+00,
 3.51257e-01,
 6.58424e-01,
 2.73454e-01,
 8.63417e-01,
-1.70061e-02,
-3.46858e-01,
 3.98531e-01,
 3.25215e-01,
 9.20889e-01,
 5.72639e-01,
 1.12451e+00,
-9.85265e-01
*/
			};

//	double par[npar];
//	for (int i = 0; i < npar; i++) par[i] = i;

	TH1::SetDefaultSumw2();
	TH2::SetDefaultSumw2();

	TCanvas * c2 = new TCanvas("c2","c2");
	c2->Divide(2,2);
	TCanvas * c1 = new TCanvas("c1","c1");
	TCanvas * c = new TCanvas("c","c");
	c->Divide(2,1);
	c->cd(1);

	TF1 * fit1PhiL = new TF1("fit1PhiL", likeliDrawPhiL, -3.15, 3.14, npar);
	fit1PhiL->SetTitle("#phi_{l}");
	fit1PhiL->SetMinimum(0);
	TF1 * fit1PhiZ = new TF1("fit1PhiZ", likeliDrawPhiZ, -3.15, 3.14, npar);
	fit1PhiZ->SetTitle("#phi_{Z}");
	fit1PhiZ->SetMinimum(0);
	TF1 * fit1CosThetaL = new TF1("fit1CosThetaL", likeliDrawCosThetaL, -1, 1, npar);
	fit1CosThetaL->SetTitle("cos#theta_{l}");
	fit1CosThetaL->SetMinimum(0);
	TF1 * fit1CosThetaZ = new TF1("fit1CosThetaZ", likeliDrawCosThetaZ, -1, 1, npar);
	fit1CosThetaZ->SetTitle("cos#theta_{Z}");
	fit1CosThetaZ->SetMinimum(0);

	TF2 * fit2 = new TF2("fit2", likeliDraw, -1, 1, -1, 1, npar);
	fit2->GetXaxis()->SetTitle("cos#theta_{l}");
	fit2->GetYaxis()->SetTitle("cos#theta_{Z}");

	TF12 * fit1x = new TF12("fit1x", fit2, point, "X");
	fit1x->SetLineColor(2);
	TF12 * fit1y = new TF12("fit1y", fit2, point, "Y");
	fit1y->SetLineColor(2);

	for (int i = 0; i < npar; i++)
		{
//		cout << par[i] << endl;
		fit2->SetParameter(i, par[i]);
		fit1PhiL->SetParameter(i, par[i]);
		fit1PhiZ->SetParameter(i, par[i]);
		fit1CosThetaL->SetParameter(i, par[i]);
		fit1CosThetaZ->SetParameter(i, par[i]);
		}
//	=================================================================================
	TH1F * _cosThetaZ = new TH1F("cosThetaZ","cosThetaZ", 20, -1, 1);
	_cosThetaZ->SetMinimum(0);
	TH1F * _cosThetaL = new TH1F("cosThetaL","cosThetaL", 20, -1, 1);
	_cosThetaL->SetMinimum(0);


	TFile * myFile = new TFile("../input/histos_baur_tree.root");
//	TFile * myFile = new TFile("../input/histos_baur_tree_TGC.root");
//	TFile * myFile = new TFile("../input/histos_data_tree.root");
	TTree * anglesTree = (TTree*) myFile->GetKey("mcangles")->ReadObj();

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

	for (Long64_t jentry = 0; jentry < nentries; jentry++)
		{
		anglesTree->GetEntry(jentry);
		if(cosThetaZ_cm > min && cosThetaZ_cm < max && phiL > -0.3 && phiL < 0.3 && phiZ > -0.3 && phiZ < 0.3) _cosThetaL->Fill(cosThetaL_cm);
		if(cosThetaL_cm > min && cosThetaL_cm < max && phiL > -0.3 && phiL < 0.3 && phiZ > -0.3 && phiZ < 0.3) _cosThetaZ->Fill(cosThetaZ_cm);
		}
//	================================================================================
	double chi2Z = 0;
	for (int i = 1; i < 21; i++)
		{
		double sigmaZ = _cosThetaZ->GetBinError(i);
		if (sigmaZ == 0) continue;
		double xZ = _cosThetaZ->GetBinCenter(i);
		double yZ = _cosThetaZ->GetBinContent(i);
		double chiVars[4] = {point, xZ, 0, 0};
		double E = likelihood(chiVars, par).first;
		double chi = (yZ - E)*(yZ - E) / (sigmaZ*sigmaZ);
		chi2Z += chi;
//		cout << chi2Z << " = " << sigmaZ << " - " << xZ << " - " << yZ<< " - " << E << endl;
		}
	cout << chi2Z << endl;

	double chi2L = 0;
	for (int i = 1; i < 21; i++)
		{
		double sigmaL = _cosThetaL->GetBinError(i);
		if (sigmaL == 0) continue;
		double xL = _cosThetaL->GetBinCenter(i);
		double yL = _cosThetaL->GetBinContent(i);
		double chiVars[4] = {point, xL, 0, 0};
		double E = likelihood(chiVars, par).first;
		double chi = (yL - E)*(yL - E) / (sigmaL*sigmaL);
		chi2L += chi;
//		cout << sigmaL << " - " << xL << " - " << yL<< " - " << E << endl;
		}
	cout << chi2L << endl;

	char * aZ;
	sprintf (aZ, "cos(#theta_{l}) in [%.1f, %.1f] : #chi^{2} / NDF = %.2f / 20", min, max, chi2Z);
	_cosThetaZ->SetTitle(aZ);
	_cosThetaZ->GetXaxis()->SetTitle("cos(#theta_{Z})");
	sprintf (aZ, "cos(#theta_{Z}) in [%.1f, %.1f] : #chi^{2} / NDF = %.2f / 20", min, max, chi2L);
	_cosThetaL->SetTitle(aZ);
	_cosThetaL->GetXaxis()->SetTitle("cos(#theta_{l})");

//	=================================================================================

	_cosThetaL->Draw("histoE");
//	fit1CosThetaL->Draw("SAME");
	fit1x->Draw("SAME");

	c->cd(2);
	_cosThetaZ->Draw("histoE");
//	fit1CosThetaZ->Draw("SAME");
	fit1y->Draw("SAME");


	c->SaveAs("overlied.gif");

	c2->cd(1);
	fit1PhiL->Draw();
	c2->cd(2);
	fit1PhiZ->Draw();
	c2->cd(3);
	fit1CosThetaL->Draw();
	c2->cd(4);
	fit1CosThetaZ->Draw();
	c2->SaveAs("likeliDraw.gif");

	c1->cd();
	fit2->Draw("lego2");

	c1->SaveAs("fit2.gif");

	return 0;
	}
//==========================================================================================
