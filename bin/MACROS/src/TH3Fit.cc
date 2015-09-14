#include <iostream>
#include <map>
#include <string>
#include <stdio.h>

#include <math.h>
#include <vector>
#include <TCanvas.h>
#include <TF3.h>
#include <TF1.h>
#include <TH3.h>
#include <TGraph.h>
#include <TLegend.h>
#include <TROOT.h>
#include <TStyle.h>
#include <TLatex.h>
#include <THStack.h>

#include "../include/plotter.h"
#include "../include/fitFunc.h"

using namespace std;
//==========================================================================================
int main()
	{
	gStyle->SetPalette(1);
	TCanvas * c1 = new TCanvas("c1","c1");
//	Fill maps with hsitograms from root files
	map<string, TH1F *> histoMap, histoMap1;

	histoMap = histoToMap("../input/histos_baur.root");
	histoMap1 = histoToMap("../input/histos_baur.root");

	int npar = 8;

	TF3 * fit3 = new TF3("fit3", fitFunc, -1, 1, -1, 1, -3.14, 3.14, npar);
//	TF2 * fit2 = new TF2("fit2", fitFunc, -1, 1, -1, 1, npar);
//	fit2->SetParameter(0, 1);
//	fit2->SetParameter(1, 2);
	TF1 * fit1 = new TF1("fit1", fitFunc, -1, 1, npar);
	TF1 * fit2 = new TF1("fit2", "pol2", -1, 1);
	fit2->SetLineColor(2);
	for (int i = 0; i < npar; i++)
		fit1->SetParameter(i, 1);

	histoMap["MC_cosThetaL_cm"]->Fit("fit1");
	histoMap1["MC_cosThetaL_cm"]->Fit("fit2");

	histoMap["MC_cosThetaL_cm"]->Draw();
	histoMap1["MC_cosThetaL_cm"]->Draw("SAMES");

	TLegend * leg = new TLegend(0.8, 0.8, 1, 1);
	leg->AddEntry(fit1, "fitFunc(0.5, #theta_{l}, 0.5)");
	leg->AddEntry(fit2, "pol2 fit");
	leg->Draw();

//	fit1->Draw();
//	fit2->Draw("lego2");

	c1->SaveAs("fit.root");

	return 0;
	}
//==========================================================================================
