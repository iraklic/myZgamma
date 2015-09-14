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

#include "TMath.h"
#include "../include/likelihoodFunc.h"
#include "../include/extern.h"

#include "../include/plotter.h"
#include "../include/tChannel.h"
#include "../include/readParams.h"

using namespace std;

vector<vector<double> > getVars(string type, string fileName)
	{
//	=====================================================================
	vector<vector<double> > varVec;

	cout << "getVars() : Reading variables from " << fileName << endl;

	TFile * myFile = new TFile(fileName.c_str());
	TTree * anglesTree;

	if (type == "mc") anglesTree = (TTree*) myFile->GetKey("mcangles")->ReadObj();
	if (type == "mcReco") anglesTree = (TTree*) myFile->GetKey("mcCutangles")->ReadObj();
	if (type == "data") anglesTree = (TTree*) myFile->GetKey("angles")->ReadObj();

	Long64_t nentries = anglesTree->GetEntries();

	cout << "getVars() : WORKING WITH " << nentries << " EVENTS" << endl;

//	cout << "Initializing variables" << endl;
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

//	cout << "Linking Branches" << endl;
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

//	double acc = 0;
//	bool accOnce = true;
//	double nEvents = 0;

	pair<double, double> tempLhood;
	vector<double> var;

	cout << "getVars() : Filling varVec" << endl;
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

	return varVec;
	}

//===========================================================================================
int main(int argc, char **arg)
	{

	if (argc != 4)
		{
		cout << "./recoResults <mcFile> <parameterFile> <dataFile>" << endl;
		return 0;
		}

	gROOT->ProcessLine(".L ../src/CMSStyle.C");
	gROOT->ProcessLine("CMSstyle()");
	gStyle->SetOptStat(0);
	gStyle->SetOptFit(1100);
	gStyle->SetOptTitle(0);
	gStyle->SetPalette(1);

	map<string, TH1F *> histoMap;
	vector<vector<double> > varVec;
	vector<vector<double> > mcvarVec;

	histoMap = histoToMap(arg[3]);
	varVec = getVars("data", arg[1]);

	cout << "Parameter File Base : " << arg[2] << endl;
	vector<double>  params = readParams((string) arg[2]);
	double finalParams[params.size()];

	finalFileName = arg[1];


	int j = 0;
	for (int i = 0; i < params.size(); i+=2)
		{
		finalParams[j] = params[i];
		cout << finalParams[j] << endl;
		j++;
		}

	pair<double, double> tempLhood;
	double vars[6];

	TCanvas * c = new TCanvas();

	TH1F * _cosThetaL = new TH1F("cosThetaL", "cosThetaL", 40, -1, 1);
	TH1F * _cosThetaZ = new TH1F("cosThetaZ", "cosThetaZ", 40, -1, 1);
	TH1F * _phiL = new TH1F("phiL", "phiL", 20, -3.14, 3.14);
	TH1F * _phiZ = new TH1F("phiZ", "phiZ", 20, -3.14, 3.14);
	TH1F * _Pw = new TH1F("pw", "pw", 100, 0, 2);
	TH2F * _Pw_cosZ = new TH2F("pw_cosZ", "pw_cosZ", 100, -1, 1, 100, 0, 1000);

	_cosThetaL->SetMinimum(0);
	_cosThetaZ->SetMinimum(0);
	_phiL->SetMinimum(0);
	_phiZ->SetMinimum(0);

	for (vector<vector<double> >::iterator it = varVec.begin(); it != varVec.end(); it++)
		{
		isData		= false;
		globalJ		= 2;
		runType		= "mc";
		finalFileName	= "../input/histos_MG5_SM_mm_ISR_ONLY.root";
		complexT	= false;
		doIt		= false;
		withTCORR	= true;
		onceDone	= true;
		debug		= false;

		vars[0] = it->at(0);
		vars[1] = it->at(1);
		vars[2] = it->at(2);
		vars[3] = it->at(3);
		vars[4] = it->at(4);
		vars[5] = it->at(5);
		double weight = it->at(6);

		tempLhood = likelihood(vars, finalParams);
		double Pw = tempLhood.first / weight;

//		cout << vars[0] << " : " << vars[1] << " : " << vars[2] << " : " << vars[3] << " : " << vars[4] <<  " : " << vars[5] << endl;
//		cout << tempLhood.first << endl;
//		cout << Pw << endl;

		_Pw->Fill(Pw);
		_Pw_cosZ->Fill(vars[1], tempLhood.first);

		_cosThetaL->Fill(vars[0], Pw);
		_cosThetaZ->Fill(vars[1], Pw);
		_phiL->Fill(vars[2], Pw);
		_phiZ->Fill(vars[3], Pw);

//		_cosThetaL->Fill(vars[0]);
//		_cosThetaZ->Fill(vars[1]);
//		_phiL->Fill(vars[2]);
//		_phiZ->Fill(vars[3]);

		}

	_cosThetaL->SetLineColor(2);
	_cosThetaL->DrawNormalized("SAMES");

	_cosThetaL->Scale(histoMap["_cosThetaL"]->Integral()/_cosThetaL->Integral());
	_cosThetaZ->Scale(histoMap["_cosThetaZ"]->Integral()/_cosThetaZ->Integral());
	_phiL->Scale(histoMap["_phiL"]->Integral()/_phiL->Integral());
	_phiZ->Scale(histoMap["_phiZ"]->Integral()/_phiZ->Integral());

	double chi2_cosL = histoMap["_cosThetaL"]->Chi2Test(_cosThetaL, "WWCHI2");
	double chi2_cosZ = histoMap["_cosThetaZ"]->Chi2Test(_cosThetaZ, "WWCHI2");
	double chi2_phiL = histoMap["_phiL"]->Chi2Test(_phiL, "WWCHI2");
	double chi2_phiZ = histoMap["_phiZ"]->Chi2Test(_phiZ, "WWCHI2");


	cout << "chi2_cosL = " << chi2_cosL << endl;
	cout << "chi2_cosZ = " << chi2_cosZ << endl;
	cout << "chi2_phiL = " << chi2_phiL << endl;
	cout << "chi2_phiZ = " << chi2_phiZ << endl;

	histoMap["_cosThetaL"]->SetMinimum(0);
	histoMap["_cosThetaZ"]->SetMinimum(0);
	histoMap["_phiL"]->SetMinimum(0);
	histoMap["_phiZ"]->SetMinimum(0);

	histoMap["_cosThetaL"]->GetXaxis()->SetTitle("cos#theta_{l}");
	histoMap["_cosThetaL"]->GetYaxis()->SetTitle("Number of Events");


	char chi2Text[30];

	TLatex * tex = new TLatex();
	tex->SetNDC();
	tex->SetTextSize(0.04);


	histoMap["_cosThetaL"]->Draw("E");
	_cosThetaL->SetLineColor(2);
	_cosThetaL->Draw("SAME");
	tex->DrawLatex(0.18, 0.96, "CMS Preliminary, 2011");
	sprintf(chi2Text, "#chi^{2} / NDF = %.2f / 40", chi2_cosL);
	tex->DrawLatex(0.7, 0.85, chi2Text);
	c->SaveAs("recoResults_cosL.gif");

	histoMap["_cosThetaZ"]->Draw("E");
	_cosThetaZ->SetLineColor(2);
	_cosThetaZ->Draw("SAME");
	sprintf(chi2Text, "#chi^{2} / NDF = %.2f / 40", chi2_cosZ);
	tex->DrawLatex(0.7, 0.85, chi2Text);
	c->SaveAs("recoResults_cosZ.gif");

	histoMap["_phiL"]->Draw("E");
	_phiL->SetLineColor(2);
	_phiL->Draw("SAME");
	tex->DrawLatex(0.18, 0.96, "CMS Preliminary, 2011");
	sprintf(chi2Text, "#chi^{2} / NDF = %.2f / 20", chi2_phiL);
	tex->DrawLatex(0.7, 0.85, chi2Text);
	c->SaveAs("recoResults_phiL.gif");

	histoMap["_phiZ"]->Draw("E");
	_phiZ->SetLineColor(2);
	_phiZ->Draw("SAME");
	tex->DrawLatex(0.18, 0.96, "CMS Preliminary, 2011");
	sprintf(chi2Text, "#chi^{2} / NDF = %.2f / 20", chi2_phiZ);
	tex->DrawLatex(0.7, 0.85, chi2Text);
	c->SaveAs("recoResults_phiZ.gif");

	_Pw_cosZ->Draw("hist");
	c->SaveAs("recoResults_Pw_cosZ.root");

	_Pw->Draw("hist");
	c->SaveAs("recoResults_Pw.root");

	return 0;
	}
//==========================================================================================
