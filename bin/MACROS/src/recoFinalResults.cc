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
//#include "../include/fitFunc.h"
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

	map<string, TH1F *> histoMap;

	histoMap = histoToMap(arg[1]);

//	==============================================================================
//	Defining the input files    ---------------------------------------
	string inputCosL;
	string inputCosZ;
	string inputPhiL;
	string inputPhiZ;

	cout << "Parameter File Base : " << arg[2] << endl;
	string base = arg[2];

	if (argc > 2)
		{
		inputCosL = base + "_cosL.txt";
		inputCosZ = base + "_cosZ.txt";
		inputPhiL = base + "_phiL.txt";
		inputPhiZ = base + "_phiZ.txt";
//		sprintf (inputCosL, "%s_cosL.txt", base.c_str());
//		sprintf (inputCosZ, "%s_cosZ.txt", base.c_str());
//		sprintf (inputPhiL, "%s_phiL.txt", base.c_str());
//		sprintf (inputPhiZ, "%s_phiZ.txt", base.c_str());
		}
	else
		{
//		sprintf (inputCosL, "fitResultcosL.txt");
//		sprintf (inputCosZ, "fitResultcosZ.txt");
//		sprintf (inputPhiL, "fitResultphiL.txt");
//		sprintf (inputPhiZ, "fitResultphiZ.txt");
		}

	cout << "Working with " << inputCosL << endl << inputCosZ << endl << inputPhiL << endl << inputPhiZ << endl; 

	vector<double>  cosL = readParams(inputCosL);
	vector<double>  cosZ = readParams(inputCosZ);
	vector<double>  phiL = readParams(inputPhiL);
	vector<double>  phiZ = readParams(inputPhiZ);
//	-------------------------------------------------------------------

	TH1F * _cosThetaL = new TH1F("cosThetaL", "cosThetaL", 40, -1, 1);
	TH1F * _cosThetaZ = new TH1F("cosThetaZ", "cosThetaZ", 40, -1, 1);
	TH1F * _phiL = new TH1F("phiL", "phiL", 20, -3.14, 3.14);
	TH1F * _phiZ = new TH1F("phiZ", "phiZ", 20, -3.14, 3.14);

	for (int i = 1; i < 41; i++)
		{
		_cosThetaL->SetBinContent(i, cosL[i-1]*histoMap["_cosThetaL"]->GetBinContent(i));
		_cosThetaZ->SetBinContent(i, cosZ[i-1]*histoMap["_cosThetaZ"]->GetBinContent(i));
		}
	for (int i = 1; i < 21; i++)
		{
		_phiL->SetBinContent(i, phiL[i-1]*histoMap["_phiL"]->GetBinContent(i));
		_phiZ->SetBinContent(i, phiZ[i-1]*histoMap["_phiZ"]->GetBinContent(i));
		}

	double scaleCos = histoMap["_cosThetaL"]->Integral() / _cosThetaL->Integral();
	double scalePhi = histoMap["_phiL"]->Integral() / _phiL->Integral();

	cout << " : " << _cosThetaL->Integral() << endl;
	cout << " : " << _cosThetaZ->Integral() << endl;
	cout << " : " << _phiL->Integral() << endl;
	cout << " : " << _phiZ->Integral() << endl;

	_cosThetaL->Scale(scaleCos);
	_cosThetaL->SetMinimum(0);

	_cosThetaZ->Scale(scaleCos);
	_cosThetaZ->SetMinimum(0);

	_phiL->Scale(scalePhi);
	_phiL->SetMinimum(0);

	_phiZ->Scale(scalePhi);
	_phiZ->SetMinimum(0);

//	===============================================================
//	chi2 calculation
	double chi2cosL = 0;
	double chi2cosZ = 0;
	double chi2phiL = 0;
	double chi2phiZ = 0;

	for (int i  = 1; i < 41; i++)
		{
		double sigmaL = histoMap["_cosThetaL"]->GetBinError(i);
		double sigmaZ = histoMap["_cosThetaZ"]->GetBinError(i);

		double cosL1 = histoMap["_cosThetaL"]->GetBinContent(i);
		double cosZ1 = histoMap["_cosThetaZ"]->GetBinContent(i);

		double cosL2 = _cosThetaL->GetBinContent(i);
		double cosZ2 = _cosThetaZ->GetBinContent(i);

		chi2cosL += (cosL1 - cosL2)*(cosL1 - cosL2) / (sigmaL*sigmaL);
		chi2cosZ += (cosZ1 - cosZ2)*(cosZ1 - cosZ2) / (sigmaZ*sigmaZ);
		}

	for (int i  = 1; i < 21; i++)
		{
		double sigmaPhiL = histoMap["_phiL"]->GetBinError(i);
		double sigmaPhiZ = histoMap["_phiZ"]->GetBinError(i);

		double phiL1 = histoMap["_phiL"]->GetBinContent(i);
		double phiZ1 = histoMap["_phiZ"]->GetBinContent(i);

		double phiL2 = _phiL->GetBinContent(i);
		double phiZ2 = _phiZ->GetBinContent(i);

		chi2phiL += (phiL1 - phiL2)*(phiL1 - phiL2) / (sigmaPhiL*sigmaPhiL);
		chi2phiZ += (phiZ1 - phiZ2)*(phiZ1 - phiZ2) / (sigmaPhiZ*sigmaPhiZ);
		}

	char aZ[50];

	sprintf (aZ, "#chi^{2} / NDF = %.2f / 40", chi2cosL);
	_cosThetaL->SetTitle(aZ);
	_cosThetaL->GetXaxis()->SetTitle("cos#theta_{l}");

	sprintf (aZ, "#chi^{2} / NDF = %.2f / 40", chi2cosZ);
	_cosThetaZ->SetTitle(aZ);
	_cosThetaZ->GetXaxis()->SetTitle("cos#theta_{Z}");

	sprintf (aZ, "#chi^{2} / NDF = %.2f / 20", chi2phiL);
	_phiL->SetTitle(aZ);
	_phiL->GetXaxis()->SetTitle("#phi_{l}");

	sprintf (aZ, "#chi^{2} / NDF = %.2f / 20", chi2phiZ);
	_phiZ->SetTitle(aZ);
	_phiZ->GetXaxis()->SetTitle("#phi_{Z}");

//	===============================================================

	for (map<string, TH1F*>::iterator mit = histoMap.begin(); mit != histoMap.end(); mit++)
		{
		mit->second->SetLineColor(2);
		mit->second->SetMarkerStyle(7);
		mit->second->SetMarkerColor(2);
		}

	TLegend * leg = new TLegend(0.35, 0.2, 0.5, 0.35);
	leg->SetFillColor(0);
//	leg->SetBorderColor(0);
	leg->SetTextSize(0.07);
	leg->AddEntry(histoMap["_cosThetaZ"],"Data Points (MC)","lp");
	leg->AddEntry(_cosThetaZ,"Fit Result","lp");

	TCanvas * c1 = new TCanvas("c1");
	_cosThetaL->Draw("E");
	histoMap["_cosThetaL"]->Draw("SAME");
	leg->Draw();
	c1->SaveAs("/afs/fnal.gov/files/home/room2/iraklich/public_html/ZGAMMA/MACROS/output/finalResultCosThetaL.gif");

	TCanvas * c2 = new TCanvas("c2");
	_cosThetaZ->Draw("E");
	histoMap["_cosThetaZ"]->Draw("SAME");
	leg->Draw();
	c2->SaveAs("/afs/fnal.gov/files/home/room2/iraklich/public_html/ZGAMMA/MACROS/output/finalResultCosThetaZ.gif");

	TCanvas * c3 = new TCanvas("c3");
	_phiL->Draw("E");
	histoMap["_phiL"]->Draw("SAME");
	leg->Draw("E");
	c3->SaveAs("/afs/fnal.gov/files/home/room2/iraklich/public_html/ZGAMMA/MACROS/output/finalResultPhiL.gif");

	TCanvas * c4 = new TCanvas("c4");
	_phiZ->Draw("E");
	histoMap["_phiZ"]->Draw("SAME");
	leg->Draw();
	c4->SaveAs("/afs/fnal.gov/files/home/room2/iraklich/public_html/ZGAMMA/MACROS/output/finalResultPhiZ.gif");

	return 0;
	}
//==========================================================================================
