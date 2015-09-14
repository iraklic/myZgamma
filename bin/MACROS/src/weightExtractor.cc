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

using namespace std;

//==========================================================================================
double flatFunc(double * var, double * par)
	{
	return par[0];
	}

double weightExtractor(double * var, double * par)
	{
	int c = 0;

	double sum = 0;
	for (int i = 0; i < 3; i++)
		{
		for (int j = 0; j < 11; j++)
			{
			sum += par[c]*pow(var[0], i)*pow(var[1], j);
//			sum += tChannel(var[1], 96, 148)*par[c]*pow(var[0], i)*pow(var[1], j);
			c++;
			}
		}
	sum*=tChannel(var[1], 91, 140);
	return sum;
	}
//===========================================================================================
int main()
	{
	gROOT->ProcessLine(".L ../src/CMSStyle.C");
	gROOT->ProcessLine("CMSstyle()");
	gStyle->SetOptStat(0);
	gStyle->SetOptTitle(0);
	gStyle->SetOptFit(1100);
	gStyle->SetPalette(1);

//	==============================================================================

	TH1F * _cosThetaZ = new TH1F("cosThetaZ","cosThetaZ", 40, -1, 1);
	TH1F * _cosThetaL = new TH1F("cosThetaL","cosThetaL", 40, -1, 1);

	TH1F * _fullCosThetaZ = new TH1F("fullCosThetaZ","cosThetaZ", 40, -1, 1);
	TH1F * _fullCosThetaL = new TH1F("fillCosThetaL","cosThetaL", 40, -1, 1);

	TH1F * intCosL = new TH1F("intCosL", "intCosL", 40, -1, 1);
	TH1F * intCosZ = new TH1F("intCosZ", "intCosZ", 40, -1, 1);

	TH2F * _cosThetaZ_L = new TH2F("cosThetaZ_L", "cosThetaZ_L", 40, -1, 1, 40, -1, 1);

	TCanvas * c1 = new TCanvas("c1","c1");
	c1->Divide(2,1);
	c1->cd(1);

	map<string, TH1F *> histoMap;
	histoMap = histoToMap("../input/histos_MG5_SM_ee_ISR_ONLY.root");

//	Fill maps with hsitograms from root files
	TH1::SetDefaultSumw2();
	TH2::SetDefaultSumw2();

	int npar = 33;

	double min = 0.65;
	double max = 0.7;
	double point = (max + min)/2.;
//	cout << point << endl;

	TF2 * fit2 = new TF2("fit2", weightExtractor, -1, 1, -1, 1, npar);
//	TF2 * fit2 = new TF2("fit2", weightExtractor, -0.8, 0.8, -0.8, 0.8, npar);
	TF2 * flatFit = new TF2("flatFit", flatFunc, -1, 1, -1, 1, 1);
//	TF2 * flatFit = new TF2("flatFit", flatFunc, -0.8, 0.8, -0.8, 0.8, 1);

	TF12 * fit1x = new TF12("fit1x", fit2, point, "X");
	TF12 * fit1y = new TF12("fit1y", fit2, point, "Y");
/*
//	integrating over cosThetaZ and cosThetaL respectively
	vector<TF12 *> fitVecL, fitVecZ;
	int vecCounter = 0;
	char fitNameL[20];
	char fitNameZ[20];

	cout << "Initializing Projection Fits" << endl;
	for (double v = -0.95; v < 1; v+=0.1)
		{
		sprintf(fitNameL, "fitL%d", vecCounter);
		sprintf(fitNameZ, "fitZ%d", vecCounter);
		cout << fitNameL << " - " << fitNameZ << endl;
		fitVecL.push_back(new TF12(fitNameL, fit2, v, "X"));
		fitVecZ.push_back(new TF12(fitNameZ, fit2, v, "Y"));
		vecCounter++;
		}

	cout << "Initialization Successful" << endl;

	cout << "Constructing Integrated Fit" << endl;

	TF1 * fullFitL = new TF1("fullFitL", "fitL0+fitL1+fitL2+fitL3+fitL4+fitL5+fitL6+fitL7+fitL8+fitL9+fitL10+fitL11+fitL12+fitL13+fitL14+fitL15+fitL16+fitL16+fitL17+fitL18+fitL19");
	TF1 * fullFitZ = new TF1("fullFitZ", "fitZ0+fitZ1+fitZ2+fitZ3+fitZ4+fitZ5+fitZ6+fitZ7+fitZ8+fitZ9+fitZ10+fitZ11+fitZ12+fitZ13+fitZ14+fitZ15+fitZ16+fitZ16+fitZ17+fitZ18+fitZ19");
	cout << "Construction Successful" << endl;

//	integration over
*/
	for (int i = 0; i < npar; i++)
		fit2->SetParameter(i, 1);

	histoMap["MC_cosThetaZ_L"]->GetXaxis()->SetTitle("cos#theta_{l}");
	histoMap["MC_cosThetaZ_L"]->GetXaxis()->SetTitleOffset(1.6);
	histoMap["MC_cosThetaZ_L"]->GetYaxis()->SetTitle("cos#theta_{Z}");
	histoMap["MC_cosThetaZ_L"]->GetYaxis()->SetTitleOffset(1.6);

	histoMap["MC_cosThetaZ_L"]->Fit("fit2");
	histoMap["MC_cosThetaZ_L"]->Draw("lego2hist");

	cout << "postFit p = " << fit2->GetProb() << endl;
	cout << "postFit chi2 = " <<  fit2->GetChisquare() << endl;

//	=====================================================================
//	map<string, TObject *> objMap;
//	objMap = objToMap("../input/histos_MG5_SM_mm_ISR_ONLY.root");

	TFile * readFile = TFile::Open("../input/histos_MG5_SM_ee_ISR_ONLY.root", "READ");
	TTree * anglesTree = (TTree*) readFile->Get("mcangles;");

//	TTree * anglesTree = (TTree*) objMap["mcangles"];

	Long64_t nentries = anglesTree->GetEntries();

//	Declaration of leaf types
	Double_t        cosThetaL;
	Double_t        cosThetaZ;
	Double_t        phiL;
	Double_t        phiZ;

//	List of branches
	TBranch        *b_cosThetaL;   //!
	TBranch        *b_cosThetaZ;   //!
	TBranch        *b_phiL;   //!
	TBranch        *b_phiZ;   //!

//	fetching branches
	b_cosThetaL = anglesTree->GetBranch("cosThetaL");
	b_cosThetaZ = anglesTree->GetBranch("cosThetaZ");
	b_phiZ = anglesTree->GetBranch("phiZ");
	b_phiL = anglesTree->GetBranch("phiL");

//	linking branch to variable
	b_cosThetaL->SetAddress(&cosThetaL);
	b_cosThetaZ->SetAddress(&cosThetaZ);
	b_phiL->SetAddress(&phiL);
	b_phiZ->SetAddress(&phiZ);

	double  myPar[npar];
	for (int i = 0; i < npar; i++)
		myPar[i] = fit2->GetParameter(i);

	cout << "NUMBER OF ENTRIES IN THE FILE = " << nentries << endl;

	double _sigmaL = 0;
	double _sigmaZ = 0;

	double _cosL1 = 0;
	double _cosL2 = 0;
	double _cosZ1 = 0;
	double _cosZ2 = 0;

	for (Long64_t jentry = 0; jentry < nentries; jentry++)
		{
		anglesTree->GetEntry(jentry);
		double vars[] = {cosThetaL, cosThetaZ, phiL, phiZ};
		if (cosThetaL > min && cosThetaL < max) _cosThetaZ->Fill(cosThetaZ);
		if (cosThetaZ > min && cosThetaZ < max) _cosThetaL->Fill(cosThetaL);

		_fullCosThetaZ->Fill(cosThetaZ);
		_fullCosThetaL->Fill(cosThetaL);

		double myVar[2];
		myVar[0] = cosThetaL;
		myVar[1] = cosThetaZ;

		double w = 1./weightExtractor(myVar, myPar);
		_cosThetaZ_L->Fill(cosThetaL, cosThetaZ, w);
		}

	double chi2Z = 0;
	for (int i = 1; i < 41; i++)
		{
		double sigmaZ = _cosThetaZ->GetBinError(i);
		double xZ = _cosThetaZ->GetBinCenter(i);
		double yZ = _cosThetaZ->GetBinContent(i);
		double E = fit2->Eval(point, xZ);
		double chi = (yZ - E)*(yZ - E) / (sigmaZ*sigmaZ);
		chi2Z += chi;
//		cout << sigmaZ << " - " << xZ << " - " << yZ<< " - " << fit2->Eval(point, xZ) << endl;
		}
	cout << chi2Z << endl;

	double chi2L = 0;
	for (int i = 1; i < 41; i++)
		{
		double sigmaL = _cosThetaL->GetBinError(i);
		double xL = _cosThetaL->GetBinCenter(i);
		double yL = _cosThetaL->GetBinContent(i);
		double E = fit2->Eval(xL, point);
		double chi = (yL - E)*(yL - E) / (sigmaL*sigmaL);
		chi2L += chi;
//		cout << sigmaL << " - " << xL << " - " << yL<< " - " << fit2->Eval(xL, point) << endl;
		}
	cout << chi2L << endl;

	double intChi2L = 0;
	double intChi2Z = 0;

	TLatex * tex = new TLatex();
	tex->SetNDC();
	tex->SetTextSize(0.04);

	char * aZ;

	_cosThetaZ->SetMinimum(0);
	_cosThetaZ->GetXaxis()->SetTitle("cos#theta_{Z}");

	_cosThetaL->SetMinimum(0);
	_cosThetaL->GetXaxis()->SetTitle("cos#theta_{l}");

//	=====================================================================
//	INTEGRATING FITFUNCTION AND PROJECTING ON AXISES
	int intC = 1;
	for (double i = -97.5; i < 100; i+=5)
		{
		double binContentL = 0;
		double binContentZ = 0;
		for (double j = -97.5; j < 100; j+=5)
			{
			double cosL = i / 100.;
			double cosZ = j / 100.;
			binContentL += fit2->Eval(cosL, cosZ);
			binContentZ += fit2->Eval(cosZ, cosL);
			}
		intCosL->SetBinContent(intC, binContentL);
		intCosZ->SetBinContent(intC, binContentZ);
		intC++;
		}

	for (int i  = 1; i < 41; i++)
		{
		_sigmaL = histoMap["MC_cosThetaL"]->GetBinError(i);
		_sigmaZ = histoMap["MC_cosThetaZ"]->GetBinError(i);

		_cosL1 = histoMap["MC_cosThetaL"]->GetBinContent(i);
		_cosZ1 = histoMap["MC_cosThetaZ"]->GetBinContent(i);

		_cosL2 = intCosL->GetBinContent(i);
		_cosZ2 = intCosZ->GetBinContent(i);

		intChi2L += (_cosL1 - _cosL2)*(_cosL1 - _cosL2) / (_sigmaL*_sigmaL);
		intChi2Z += (_cosZ1 - _cosZ2)*(_cosZ1 - _cosZ2) / (_sigmaZ*_sigmaZ);
		}

	intCosZ->GetXaxis()->SetTitle("cos#theta_{Z}");
	intCosL->GetXaxis()->SetTitle("cos#theta_{l}");

//	=====================================================================

	c1->cd(2);
	fit2->Draw("lego2");
	c1->SaveAs("/afs/fnal.gov/files/home/room2/iraklich/public_html/ZGAMMA/MACROS/output/fit1.pdf");


	TLegend * leg = new TLegend(0.4, 0.7, 0.9, 0.9);
	leg->SetFillColor(0);
	leg->SetTextSize(0.04);

	TCanvas * c2 = new TCanvas("c2");
//	c2->Divide(2,1);
//	c2->cd(1);
	_cosThetaL->SetMarkerStyle(7);
	_cosThetaL->GetYaxis()->SetTitle("Events");
	_cosThetaL->Draw("E");
	sprintf (aZ, "#chi^{2} / NDF = %.2f / 40", chi2L);
	tex->DrawLatex(0.18, 0.96, "CMS Preliminary, 2011,#sqrt{s} = 7 TeV, Electron Channel");
	tex->DrawLatex(0.75, 0.96, aZ);
	fit1x->SetLineColor(2);
	fit1x->SetLineWidth(1);
	fit1x->Draw("SAME");
	leg = new TLegend(0.2, 0.2, 0.7, 0.4);
	leg->SetFillColor(0);
	leg->AddEntry(_cosThetaL, "MadGraph MC : cos#theta_{Z} #in [0.65, 0.7]", "pl");
	leg->AddEntry(fit1x, "fit : F(cos#theta_{l}, cos#theta_{Z} = 0.625)", "l");
	leg->Draw();
	c2->SaveAs("/afs/fnal.gov/files/home/room2/iraklich/public_html/ZGAMMA/MACROS/output/slice_fitL.pdf");

//	c2->cd(2);
	_cosThetaZ->SetMarkerStyle(7);
	_cosThetaZ->GetYaxis()->SetTitle("Events");
	_cosThetaZ->Draw("E");
	sprintf (aZ, "#chi^{2} / NDF = %.2f / 40", chi2Z);
	tex->DrawLatex(0.18, 0.96, "CMS Preliminary, 2011,#sqrt{s}=7 TeV, Electron Channel");
	tex->DrawLatex(0.75, 0.96, aZ);
	fit1y->SetLineColor(2);
	fit1y->SetLineWidth(1);
	fit1y->Draw("SAME");
	leg = new TLegend(0.4, 0.7, 0.9, 0.9);
	leg->SetFillColor(0);
	leg->AddEntry(_cosThetaZ, "MadGraph MC : cos#theta_{l} #in [0.65, 0.7]", "pl");
	leg->AddEntry(fit1x, "fit : F(cos#theta_{l} = 0.625, cos#theta_{Z})", "l");
	leg->Draw();
	c2->SaveAs("/afs/fnal.gov/files/home/room2/iraklich/public_html/ZGAMMA/MACROS/output/slice_fitZ.pdf");

	TCanvas * c3 = new TCanvas("c3");
	_cosThetaZ_L->SetMinimum(0);
	_cosThetaZ_L->Fit("flatFit");
	_cosThetaZ_L->Draw("lego2hist");
//	flatFit->Draw("SURFSAME");
	c3->SaveAs("/afs/fnal.gov/files/home/room2/iraklich/public_html/ZGAMMA/MACROS/output/weighted.pdf");

//	TCanvas * c4 = new TCanvas("c4");
//	_fullCosThetaL->SetMinimum(0);
//	_fullCosThetaL->Draw("histE");
//	fullFitL->Draw("SAME");
//	fitVecL[3]->Draw("SAME");
//	histoMap["MC_cosThetaL"]->Draw("SAMES");
//	c4->SaveAs("/afs/fnal.gov/files/home/room2/iraklich/public_html/ZGAMMA/MACROS/output/integratedFitL.pdf");

//	TCanvas * c5 = new TCanvas("c5");
//	_fullCosThetaL->Draw("histE");
//	histoMap["MC_cosThetaL"]->Draw("SAMES");
//	c5->SaveAs("/afs/fnal.gov/files/home/room2/iraklich/public_html/ZGAMMA/MACROS/output/full.pdf");

	TCanvas * c6 = new TCanvas("c6");
	intCosL->SetMinimum(0);
	intCosL->SetLineColor(2);
	intCosL->SetMarkerStyle(1);
	intCosL->Draw("hist");
	intCosL->GetYaxis()->SetTitle("Events");

	_fullCosThetaL->Draw("sameE");
	_fullCosThetaL->SetMarkerStyle(1);

	sprintf (aZ, "#chi^{2} / NDF = %.2f / 40", intChi2L);
	tex->DrawLatex(0.18, 0.96, "CMS Preliminary, 2011,#sqrt{s}=7 TeV, Electron Channel");
	tex->DrawLatex(0.75, 0.96, aZ);
	leg = new TLegend(0.2, 0.2, 0.7, 0.4);
	leg->SetFillColor(0);
	leg->AddEntry(_fullCosThetaL, "MadGraph MC", "pl");
	leg->AddEntry(intCosL, "fit : #int_{} F(cos#theta_{Z}, cos#theta_{l})dcos#theta_{Z}", "l");
	leg->Draw();

	c6->SaveAs("/afs/fnal.gov/files/home/room2/iraklich/public_html/ZGAMMA/MACROS/output/intCosL.pdf");

	TCanvas * c7 = new TCanvas("c7");
//	histoMap["MC_cosThetaZ"]->SetMarkerStyle(6);
//	histoMap["MC_cosThetaZ"]->SetMinimum(0);
//	histoMap["MC_cosThetaZ"]->SetMaximum(26000);
//	histoMap["MC_cosThetaZ"]->Draw("E");

	intCosZ->SetLineColor(2);
	intCosZ->SetMinimum(0);
	intCosZ->SetMarkerStyle(1);
	intCosZ->Draw("hist");
	intCosZ->GetYaxis()->SetTitle("Events");

	_fullCosThetaZ->Draw("sameE");
	_fullCosThetaZ->SetMarkerStyle(1);

	sprintf (aZ, "#chi^{2} / NDF = %.2f / 40", intChi2Z);
	tex->DrawLatex(0.18, 0.96, "CMS Preliminary, 2011,#sqrt{s}=7 TeV, Electron Channel");
	tex->DrawLatex(0.75, 0.96, aZ);
	leg = new TLegend(0.4, 0.7, 0.9, 0.9);
	leg->SetFillColor(0);
	leg->AddEntry(_fullCosThetaZ, "MadGraph MC", "pl");
	leg->AddEntry(intCosZ, "fit : #int_{} F(cos#theta_{Z}, cos#theta_{l})dcos#theta_{l}", "l");
	leg->Draw();

	c7->SaveAs("/afs/fnal.gov/files/home/room2/iraklich/public_html/ZGAMMA/MACROS/output/intCosZ.pdf");

	return 0;
	}
//==========================================================================================
