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
	string fitVar = "_cosThetaZ_cm";

	gROOT->ProcessLine(".L ../src/CMSStyle.C");
	gROOT->ProcessLine("CMSstyle()");
	gStyle->SetOptStat(0);

//	Fill maps with hsitograms from root files
	map<string, TH1F *> histoMap2, histoMap1;

	histoMap2	= histoToMap("../input/histos_baur.root");
	histoMap1	= histoToMap("../input/histos_baur_TGC.root");

	TF1 * myFit = new TF1("myFit","pol2", -0.7 , 0.7);

	TCanvas * c = new TCanvas();
	c->Divide(2,1);

	TLegend * leg = new TLegend(0.2984715,0.5657754,0.696294,0.7666572,NULL,"brNDC");
	leg->SetTextSize(0.08);
	leg->SetFillColor(0);
	leg->SetLineColor(0);

	c->cd(1);

	double scale = histoMap1[fitVar]->Integral()/histoMap2[fitVar]->Integral();
	histoMap2[fitVar]->Scale(scale);

	histoMap1[fitVar]->Fit("myFit", "R");
	histoMap1[fitVar]->SetMarkerStyle(22);
	histoMap1[fitVar]->Draw();

	c->cd(2);
	histoMap2[fitVar]->Fit("myFit", "R");
	histoMap2[fitVar]->SetLineColor(2);
	myFit->SetLineColor(2);
	histoMap2[fitVar]->Draw();
	myFit->Draw("SAME");

	leg->AddEntry(histoMap1[fitVar], "TGC Baur reco");
	leg->AddEntry(histoMap2[fitVar], "SM Baur reco");

	leg->Draw();

	c->SaveAs("../output/results.root");

/*
//	=====================================================		
//	DRAW BAUR RECO + DATA
//	=====================================================		
	TCanvas * c1 = new TCanvas ("cosTheta_cm", "cos(#theta_{l})");
	c1->Divide(3,1);
	c1->cd(1);

	THStack * st = new THStack ();

	TLegend *leg2 = new TLegend(0.669598,0.738676,0.919598,0.9076655,NULL,"brNDC");
	leg2->SetFillColor(0);
	leg2->SetTextSize(0.04);

//	Set Title
	histoMap1[fitVar]->GetYaxis()->SetTitle("Entries / 0.2");
	histoMap1[fitVar]->GetXaxis()->SetTitle("cos(#theta_{l})");
	histoMap1[fitVar]->SetTitle("");

//	Draw data
//	histoMap1[fitVar]->Add(histoMap1["_cosThetaL_cm_bg"]);
	histoMap1[fitVar]->SetMarkerStyle(8);
	histoMap1[fitVar]->SetMarkerSize(1.2);
	histoMap1[fitVar]->SetMinimum(0);
	histoMap1[fitVar]->SetMaximum(25);
	histoMap1[fitVar]->Draw();

//	FSR histo
//	histoMap2["_cosThetaL_cm_FSR"]->Scale(27.48*36.1 / 500000);
//	histoMap2["_cosThetaL_cm_FSR"]->Add(histoMap1["_cosThetaL_cm_bg"]);
//	histoMap2["_cosThetaL_cm_FSR"]->SetLineColor(3);
//	histoMap2["_cosThetaL_cm_FSR"]->SetFillColor(3);
//	histoMap2["_cosThetaL_cm_FSR"]->SetFillStyle(3006);

//	ISR histo
	histoMap2[fitVar]->Scale(27.48*36.1 / 500000);
	histoMap2[fitVar]->Add(histoMap1["_cosThetaL_cm_bg"]);

//	TH1F * temp = (TH1F*) histoMap2[fitVar]->Clone("temp");
//	temp->UseCurrentStyle();
//	temp->SetFillColor(10);
//	temp->Draw("SAMEhisto");

//	histoMap2[fitVar]->SetLineColor(2);
//	histoMap2[fitVar]->SetFillColor(2);
//	histoMap2[fitVar]->SetFillStyle(3005);
//	histoMap2[fitVar]->Draw("SAMEhisto");

//	histoMap1["_cosThetaL_cm_bg"]->SetLineColor(4);
//	histoMap1["_cosThetaL_cm_bg"]->SetFillColor(4);
//	histoMap1["_cosThetaL_cm_bg"]->Draw("SAMEhisto");

//	histoMap1[fitVar]->Draw("SAME");

//	st->Add(histoMap1["_cosThetaL_cm_bg"],"histo");
//	st->Add(histoMap2[fitVar],"histo");
//	st->Add(histoMap2["_cosThetaL_cm_FSR"],"histo");
//	st->Draw("SAME");
//	gPad->RedrawAxis();

//	histoMap1[fitVar]->Draw("SAME");

//	leg2->AddEntry(histoMap1[fitVar],"DATA","lp");
//	leg2->AddEntry(histoMap2["_cosThetaL_cm_FSR"],"BAUR FSR","f");
//	leg2->AddEntry(histoMap2[fitVar],"BAUR ISR","f");
//	leg2->AddEntry(histoMap2["_cosThetaL_cm_FSR"],"BAUR FSR","f");
//	leg2->AddEntry(histoMap1["_cosThetaL_cm_bg"],"Background","f");
//	leg2->Draw();

	histoMap1[fitVar]->Fit("myFit", "R");
//	histoMap1[fitVar]->Draw();

	histoMap1[fitVar]->SetLineColor(2);
	histoMap1[fitVar]->Fit("myFit", "R");
	histoMap1[fitVar]->Draw();
	myFit->SetLineColor(2);
	myFit->Draw("SAME");

	c1->cd(2);
	histoMap1[fitVar]->SetLineColor(2);
	histoMap1[fitVar]->Fit("myFit", "R");
	histoMap1[fitVar]->Draw("L");
	myFit->SetLineColor(2);
	myFit->Draw("SAME");

	c1->cd(3);
	histoMap1[fitVar]->SetLineColor(2);
	histoMap1[fitVar]->Fit("myFit", "R");
	histoMap1[fitVar]->Draw("histo");
	myFit->SetLineColor(2);
	myFit->Draw("SAME");


	c1->SaveAs("../output/drawOptions.gif");
*/

	return 0;
	}
//==========================================================================================
