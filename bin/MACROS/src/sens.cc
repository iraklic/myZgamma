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

	string sensVar = "_cosThetaL_cm";

//	Fill maps with hsitograms from root files
	map<string, TH1F *> histoMap1, histoMap2;

	histoMap1 = histoToMap("../input/histos_baur.root");
	histoMap2 = histoToMap("../input/histos_baur_TGC.root");

	TCanvas * c = new TCanvas();

	double scale = histoMap1[sensVar]->Integral()/histoMap2[sensVar]->Integral();
	histoMap2[sensVar]->Scale(scale);


	c = (TCanvas *) histoSens(histoMap1, histoMap2, sensVar, 10, -1); 
	c->Draw();

	c->SaveAs("sens.gif");


	return 0;
	}
//==========================================================================================
