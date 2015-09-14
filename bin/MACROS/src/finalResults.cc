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

#include "../include/plotter.h"
#include "../include/fitFunc.h"
#include "../include/tChannel.h"
#include "../include/readParams.h"

using namespace std;

//===========================================================================================
int main(int argc, char **arg)
	{
	gROOT->ProcessLine(".L ../src/CMSStyle.C");
	gROOT->ProcessLine("CMSstyle()");
	gStyle->SetOptStat(0);
	gStyle->SetOptFit(1100);
	gStyle->SetPalette(1);

	map<string, TH1F *> histoMap, histoMap_BAUR_SM_mm;
	histoMap = histoToMap("../input/histos_MG5_SM_mm_ISR_ONLY.root");
	histoMap_BAUR_SM_mm = histoToMap("../input/histos_MG5_SM_mm_ISR_ONLY.root");
//	histoMap_BAUR_SM_mm = histoToMap("../input/histos_BAUR_SM_ee.root");

//	==============================================================================

	double epsCosL[40];
	double epsCosZ[40];
	double epsPhiL[64];
	double epsPhiZ[64];

	for (int i = 1; i< 41; i++)
		{
		epsCosL[i-1] = histoMap["_cosThetaL"]->GetBinContent(i) / histoMap["MC_cosThetaL"]->GetBinContent(i);
		epsCosZ[i-1] = histoMap["_cosThetaZ"]->GetBinContent(i) / histoMap["MC_cosThetaZ"]->GetBinContent(i);
		}
	for (int i = 1; i< 21; i++)
		{
		epsPhiL[i-1] = histoMap["_phiL"]->GetBinContent(i) / histoMap["MC_phiL"]->GetBinContent(i);
		epsPhiZ[i-1] = histoMap["_phiZ"]->GetBinContent(i) / histoMap["MC_phiZ"]->GetBinContent(i);
		}

	char inputCosL[50];
	char inputCosZ[50];
	char inputPhiL[50];
	char inputPhiZ[50];


	if (argc > 1)
		{
		sprintf (inputCosL, "%s_cosL_2.txt", arg[1]);
		sprintf (inputCosZ, "%s_cosZ_2.txt", arg[1]);
		sprintf (inputPhiL, "%s_phiL_2.txt", arg[1]);
		sprintf (inputPhiZ, "%s_phiZ_2.txt", arg[1]);
		cout << inputCosL << endl;
		}
	else
		{
		cout << "I am here" << endl;
		sprintf (inputCosL, "fitResultcosL.txt");
		sprintf (inputCosZ, "fitResultcosZ.txt");
		sprintf (inputPhiL, "fitResultphiL.txt");
		sprintf (inputPhiZ, "fitResultphiZ.txt");
		cout << inputCosL << endl;
		}

	cout << "Working with " << inputCosL << endl << inputCosZ << endl << inputPhiL << endl << inputPhiZ << endl; 

	vector<double>  cosL = readParams(inputCosL);
	vector<double>  cosZ = readParams(inputCosZ);
	vector<double>  phiL = readParams(inputPhiL);
	vector<double>  phiZ = readParams(inputPhiZ);

	TH1F * _cosThetaL = new TH1F("cosThetaL", "cosThetaL", 40, -1, 1);
	TH1F * _cosThetaZ = new TH1F("cosThetaZ", "cosThetaZ", 40, -1, 1);
	TH1F * _phiL = new TH1F("phiL", "phiL", 20, -3.14, 3.14);
	TH1F * _phiZ = new TH1F("phiZ", "phiZ", 20, -3.14, 3.14);

	TH1F * RECO_cosThetaL = new TH1F("RECO_cosThetaL", "RECO_cosThetaL", 40, -1, 1);
	TH1F * RECO_cosThetaZ = new TH1F("RECO_cosThetaZ", "RECO_cosThetaZ", 40, -1, 1);
	TH1F * RECO_phiL = new TH1F("RECO_phiL", "RECO_phiL", 20, -3.14, 3.14);
	TH1F * RECO_phiZ = new TH1F("RECO_phiZ", "RECO_phiZ", 20, -3.14, 3.14);

	for (int i = 1; i < 41; i++)
		{
		_cosThetaL->SetBinContent(i, cosL[i-1]);
		RECO_cosThetaL->SetBinContent(i, cosL[i-1]*epsCosL[i-1]);
		_cosThetaZ->SetBinContent(i, cosZ[i-1]);
		RECO_cosThetaZ->SetBinContent(i, cosZ[i-1]*epsCosZ[i-1]);
		}
	for (int i = 1; i < 21; i++)
		{
		_phiL->SetBinContent(i, phiL[i-1]);
		RECO_phiL->SetBinContent(i, phiL[i-1]*epsPhiL[i-1]);
		_phiZ->SetBinContent(i, phiZ[i-1]);
		RECO_phiZ->SetBinContent(i, phiZ[i-1]*epsPhiZ[i-1]);

		}

	double scale = histoMap["MC_cosThetaL"]->Integral() / _cosThetaL->Integral();

	cout << " : " << _cosThetaL->Integral() << endl;
	cout << " : " << _cosThetaZ->Integral() << endl;
	cout << " : " << _phiL->Integral() << endl;
	cout << " : " << _phiZ->Integral() << endl;

	_cosThetaL->Scale(scale);
	_cosThetaL->SetMinimum(0);

	_cosThetaZ->Scale(scale);
	_cosThetaZ->SetMinimum(0);

	_phiL->Scale(scale);
	_phiL->SetMinimum(0);

	_phiZ->Scale(scale);
	_phiZ->SetMinimum(0);

	RECO_cosThetaL->Scale(scale);
	RECO_cosThetaL->SetMinimum(0);

	RECO_cosThetaZ->Scale(scale);
	RECO_cosThetaZ->SetMinimum(0);

	RECO_phiL->Scale(scale);
	RECO_phiL->SetMinimum(0);

	RECO_phiZ->Scale(scale);
	RECO_phiZ->SetMinimum(0);

//	===============================================================
//	chi2 calculation
	double chi2cosL = 0;
	double chi2cosZ = 0;
	double chi2phiL = 0;
	double chi2phiZ = 0;

	double chi2RECOcosL = 0;
	double chi2RECOcosZ = 0;
	double chi2RECOphiL = 0;
	double chi2RECOphiZ = 0;

	for (int i  = 1; i < 21; i++)
		{
		double sigmaL = histoMap["MC_cosThetaL"]->GetBinError(i);
		double sigmaZ = histoMap["MC_cosThetaZ"]->GetBinError(i);

		double sigmaPhiL = histoMap["MC_phiL"]->GetBinError(i);
		double sigmaPhiZ = histoMap["MC_phiZ"]->GetBinError(i);

		double cosL1 = histoMap["MC_cosThetaL"]->GetBinContent(i);
		double cosZ1 = histoMap["MC_cosThetaZ"]->GetBinContent(i);

		double cosL2 = _cosThetaL->GetBinContent(i);
		double cosZ2 = _cosThetaZ->GetBinContent(i);

		double phiL1 = histoMap["MC_phiL"]->GetBinContent(i);
		double phiZ1 = histoMap["MC_phiZ"]->GetBinContent(i);

		double phiL2 = _phiL->GetBinContent(i);
		double phiZ2 = _phiZ->GetBinContent(i);

		chi2cosL += (cosL1 - cosL2)*(cosL1 - cosL2) / (sigmaL*sigmaL);
		chi2cosZ += (cosZ1 - cosZ2)*(cosZ1 - cosZ2) / (sigmaZ*sigmaZ);

		chi2phiL += (phiL1 - phiL2)*(phiL1 - phiL2) / (sigmaPhiL*sigmaPhiL);
		chi2phiZ += (phiZ1 - phiZ2)*(phiZ1 - phiZ2) / (sigmaPhiZ*sigmaPhiZ);
		}

	for (int i  = 1; i < 21; i++)
		{
		double sigmaL = histoMap["_cosThetaL"]->GetBinError(i);
		double sigmaZ = histoMap["_cosThetaZ"]->GetBinError(i);

		double sigmaPhiL = histoMap["_phiL"]->GetBinError(i);
		double sigmaPhiZ = histoMap["_phiZ"]->GetBinError(i);

		double cosL1 = histoMap["_cosThetaL"]->GetBinContent(i);
		double cosZ1 = histoMap["_cosThetaZ"]->GetBinContent(i);

		double cosL2 = RECO_cosThetaL->GetBinContent(i);
		double cosZ2 = RECO_cosThetaZ->GetBinContent(i);

		double phiL1 = histoMap["_phiL"]->GetBinContent(i);
		double phiZ1 = histoMap["_phiZ"]->GetBinContent(i);

		double phiL2 = RECO_phiL->GetBinContent(i);
		double phiZ2 = RECO_phiZ->GetBinContent(i);

		chi2RECOcosL += (cosL1 - cosL2)*(cosL1 - cosL2) / (sigmaL*sigmaL);
		chi2RECOcosZ += (cosZ1 - cosZ2)*(cosZ1 - cosZ2) / (sigmaZ*sigmaZ);

		chi2RECOphiL += (phiL1 - phiL2)*(phiL1 - phiL2) / (sigmaPhiL*sigmaPhiL);
		chi2RECOphiZ += (phiZ1 - phiZ2)*(phiZ1 - phiZ2) / (sigmaPhiZ*sigmaPhiZ);
		}

	char aZ[50];

	sprintf (aZ, "#chi^{2} / NDF = %.2f / 20", chi2cosL);
	_cosThetaL->SetTitle(aZ);
	_cosThetaL->GetXaxis()->SetTitle("cos#theta_{l}");

	sprintf (aZ, "#chi^{2} / NDF = %.2f / 20", chi2RECOcosL);
	RECO_cosThetaL->SetTitle(aZ);
	RECO_cosThetaL->GetXaxis()->SetTitle("cos#theta_{l}");

	sprintf (aZ, "#chi^{2} / NDF = %.2f / 20", chi2cosZ);
	_cosThetaZ->SetTitle(aZ);
	_cosThetaZ->GetXaxis()->SetTitle("cos#theta_{Z}");

	sprintf (aZ, "#chi^{2} / NDF = %.2f / 20", chi2RECOcosZ);
	RECO_cosThetaZ->SetTitle(aZ);
	RECO_cosThetaZ->GetXaxis()->SetTitle("cos#theta_{Z}");

	sprintf (aZ, "#chi^{2} / NDF = %.2f / 20", chi2phiL);
	_phiL->SetTitle(aZ);
	_phiL->GetXaxis()->SetTitle("#phi_{l}");

	sprintf (aZ, "#chi^{2} / NDF = %.2f / 20", chi2RECOphiL);
	RECO_phiL->SetTitle(aZ);
	RECO_phiL->GetXaxis()->SetTitle("#phi_{l}");

	sprintf (aZ, "#chi^{2} / NDF = %.2f / 20", chi2phiZ);
	_phiZ->SetTitle(aZ);
	_phiZ->GetXaxis()->SetTitle("#phi_{Z}");

	sprintf (aZ, "#chi^{2} / NDF = %.2f / 20", chi2RECOphiZ);
	RECO_phiZ->SetTitle(aZ);
	RECO_phiZ->GetXaxis()->SetTitle("#phi_{Z}");

//	===============================================================

	cout << _phiL->Integral() << endl;
	cout << histoMap["MC_phiL"]->Integral() << endl;


	for (map<string, TH1F*>::iterator mit = histoMap_BAUR_SM_mm.begin(); mit != histoMap_BAUR_SM_mm.end(); mit++)
		{
		mit->second->SetLineColor(2);
		mit->second->SetMarkerStyle(7);
		mit->second->SetMarkerColor(2);
		}

	TLegend * leg = new TLegend(0.35, 0.2, 0.5, 0.5);
	leg->SetFillColor(0);
//	leg->SetBorderColor(0);
	leg->SetTextSize(0.08);
	leg->AddEntry(histoMap["MC_cosThetaZ"],"MadGraph5 ISR","lp");
	leg->AddEntry(_cosThetaZ,"Fit Result","l");

	TCanvas * c1 = new TCanvas("c1");
	c1->Divide(2,1);
	c1->cd(1);
	_cosThetaL->Draw();
	histoMap_BAUR_SM_mm["MC_cosThetaL"]->Draw("SAME");
	c1->cd(2);
	RECO_cosThetaL->Draw();
	histoMap_BAUR_SM_mm["_cosThetaL"]->Draw("SAME");
	leg->Draw();
	c1->SaveAs("/afs/fnal.gov/files/home/room2/iraklich/public_html/ZGAMMA/MACROS/output/finalResultCosThetaL.gif");

	TCanvas * c2 = new TCanvas("c2");
	c2->Divide(2,1);
	c2->cd(1);
	histoMap_BAUR_SM_mm["MC_cosThetaZ"]->Draw();
	_cosThetaZ->Draw("SAME");
//	histoMap_BAUR_SM_mm["MC_cosThetaZ"]->Draw("SAME");
	c2->cd(2);
	histoMap_BAUR_SM_mm["_cosThetaZ"]->Draw();
	RECO_cosThetaZ->Draw("SAME");
//	histoMap_BAUR_SM_mm["_cosThetaZ"]->Draw("SAME");
	leg->Draw();
	c2->SaveAs("/afs/fnal.gov/files/home/room2/iraklich/public_html/ZGAMMA/MACROS/output/finalResultCosThetaZ.gif");

	TCanvas * c3 = new TCanvas("c3");
	c3->Divide(2,1);
	c3->cd(1);
	_phiL->Draw();
	histoMap_BAUR_SM_mm["MC_phiL"]->Draw("SAME");
	c3->cd(2);
	RECO_phiL->Draw();
	histoMap_BAUR_SM_mm["_phiL"]->Draw("SAME");
	leg->Draw();
	c3->SaveAs("/afs/fnal.gov/files/home/room2/iraklich/public_html/ZGAMMA/MACROS/output/finalResultPhiL.gif");

	TCanvas * c4 = new TCanvas("c4");
	c4->Divide(2,1);
	c4->cd(1);
	_phiZ->Draw();
	histoMap_BAUR_SM_mm["MC_phiZ"]->Draw("SAME");
	c4->cd(2);
	RECO_phiZ->Draw();
	histoMap_BAUR_SM_mm["_phiZ"]->Draw("SAME");
	leg->Draw();
	c4->SaveAs("/afs/fnal.gov/files/home/room2/iraklich/public_html/ZGAMMA/MACROS/output/finalResultPhiZ.gif");

	return 0;
	}
//==========================================================================================
