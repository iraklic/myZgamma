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

#include "../include/plotter.h"

using namespace std;
//==========================================================================================
int main()
	{
	gROOT->ProcessLine(".L ../src/CMSStyle.C");
	gROOT->ProcessLine("CMSstyle()");
	gStyle->SetOptStat(0);


	vector<string> drawVars;
	drawVars.push_back("_cosThetaL_cm");
	drawVars.push_back("_cosThetaZ_cm");
//	drawVars.push_back("MC_cosThetaL_cm");
//	drawVars.push_back("MC_cosThetaZ_cm");

//	Fill maps with hsitograms from root files
	map<string, TH1F *> histoMap1, histoMap2;

	histoMap1 = histoToMap("../input/histos_baur.root");
	histoMap2 = histoToMap("../input/histos_baur_TGC.root");

	for (vector<string>::iterator it = drawVars.begin(); it != drawVars.end(); it++)
		{
		TLegend * leg = new TLegend(0.2,0.4,0.6,0.7,NULL,"brNDC");
		leg->SetTextSize(0.06);
		leg->SetFillColor(0);

		TCanvas * c = new TCanvas();
		c->cd();

		double scale = histoMap1[*it]->Integral()/histoMap2[*it]->Integral();
		histoMap2[*it]->Scale(scale);
		c = (TCanvas*) histoDraw(histoMap1, histoMap2, *it);


		leg->AddEntry(histoMap1[*it], "BAUS SM RECO", "l");
		leg->AddEntry(histoMap2[*it], "BAUS SM TGC", "l");
		leg->Draw();

		string name = "draw" + *it + ".gif";

		c->SaveAs(name.c_str());
		}

	return 0;
	}
//==========================================================================================
