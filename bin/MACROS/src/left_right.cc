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

//	Fill maps with hsitograms from root files
	map<string, TH1F *> histoMap_sherpa, histoMap_baur_right, histoMap_baur_left, histoMap_sherpa_tgc;

	histoMap_baur_right	= histoToMap("../input/histos_baur.root");
	histoMap_baur_left	= histoToMap("../input/histos_baur_left.root");
	histoMap_sherpa		= histoToMap("../input/histos_sherpa.root");
	histoMap_sherpa_tgc	= histoToMap("../../output/SHERPA_TGC/01/histos_ee_phoID_12_eleID_11_job_Zgamma_1j_Zgg_h3_0.12_h4_0.004.root");

	TCanvas * c = new TCanvas();
	c->Divide(2, 1);

	TLegend * leg = new TLegend(0.2984715,0.5657754,0.696294,0.7666572,NULL,"brNDC");
	leg->SetTextSize(0.08);
	leg->SetFillColor(0);
	leg->SetLineColor(0);

	c->cd(1);

	double start = -1;
	double end = 1;
	float min = 10000;

	TF1 * myFit = new TF1("myFit","pol2", -0.7 , 0.7);

	histoMap_baur_right["MC_cosThetaZ_cm"]->Scale(histoMap_baur_right["_cosThetaZ_cm"]->Integral()/histoMap_baur_right["MC_cosThetaZ_cm"]->Integral());
	histoMap_baur_right["MC_cosThetaZ_cm"]->SetLineStyle(3);
	histoMap_baur_right["_cosThetaZ_cm"]->SetLineStyle(3);
//	histoMap_baur_right["_cosThetaZ_cm"]->Fit("myFit", "R");
//	histoMap_baur_right["MC_cosThetaZ_cm"]->Fit("myFit", "R");

	histoMap_baur_right["MC_cosThetaZ_cm"]->SetLineColor(2);
	histoMap_baur_right["MC_cosThetaZ_cm"]->Draw("hist");
	histoMap_baur_right["_cosThetaZ_cm"]->Draw("SAMEhist");

	c->cd(2);
	histoMap_baur_left["MC_cosThetaZ_cm"]->Scale(histoMap_baur_left["_cosThetaZ_cm"]->Integral()/histoMap_baur_left["MC_cosThetaZ_cm"]->Integral());
//	histoMap_baur_left["_cosThetaZ_cm"]->Fit("myFit", "R");
//	histoMap_baur_left["MC_cosThetaZ_cm"]->Fit("myFit", "R");

	histoMap_baur_left["MC_cosThetaZ_cm"]->SetLineColor(2);
	histoMap_baur_left["MC_cosThetaZ_cm"]->Draw("hist");
	histoMap_baur_left["_cosThetaZ_cm"]->Draw("SAMEhist");

	leg->AddEntry(histoMap_baur_right["MC_cosThetaZ_cm"], "GEN (right)");
	leg->AddEntry(histoMap_baur_right["_cosThetaZ_cm"], "RECO (right)");
	leg->AddEntry(histoMap_baur_left["MC_cosThetaZ_cm"], "GEN (left)");
	leg->AddEntry(histoMap_baur_left["_cosThetaZ_cm"], "RECO (leftt)");

	leg->Draw();

/*

	TH1F * h1 = new TH1F("h1", "h1", 100, 0, 500);

	for (double i = -1; i < -0.5; i+=0.001)
		{
		TF1 * myFit = new TF1("myFit","pol2", i , -i);

		histoMap_baur_right["_cosThetaZ_cm"]->Scale(histoMap_baur_right["_cosThetaZ_cm"]->Integral()/histoMap_baur_right["MC_cosThetaZ_cm"]->Integral());
		histoMap_baur_right["_cosThetaZ_cm"]->Fit("myFit", "R");
		float p1 = myFit->GetParameter(2);
//		histoMap_baur_right["_cosThetaZ_cm"]->Draw();

		histoMap_baur_right["MC_cosThetaZ_cm"]->Fit("myFit", "R");
		float p2 = myFit->GetParameter(2);
//		histoMap_baur_right["_cosThetaZ_cm"]->Draw("SAME");

		if (fabs((p1-p2)) < min)
			{
			min = fabs(p1-p2);
			start = i;
			end = - i;
			}
		cout << fabs(p1-p2) << endl;
		h1->Fill(fabs(p1-p2));

		}
	h1->Draw();
	cout << start << " - " << end << endl;
*/
	c->SaveAs("../output/left_right.gif");

	return 0;
	}
//==========================================================================================
