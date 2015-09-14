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
//	TH1::SetDefaultSumw2();

	gROOT->ProcessLine(".L ../src/CMSStyle.C");
	gROOT->ProcessLine("CMSstyle()");
	gStyle->SetOptStat(0);
	gStyle->SetOptFit(1100);
	gStyle->SetPalette(1);

	map<string, TH1F *> histoMap;

	histoMap = histoToMap(arg[1]);

	cout << "Number of Events in RECO : " << histoMap["_cosThetaL"]->Integral() << endl;
	cout << "Number of Events in GEN : " << histoMap["MCCut_cosThetaL"]->Integral() << endl;;

	double scale = histoMap["_cosThetaL"]->Integral() / histoMap["MCCut_cosThetaL"]->Integral();
	cout << "Scale Factor : " << histoMap["_cosThetaL"]->Integral() / histoMap["MCCut_cosThetaL"]->Integral() << endl;

	TH1F * d_L = new TH1F ("d_L", "GEN/RECO", 40, -1, 1);
	TH1F * d_Z = new TH1F ("d_Z", "GEN/RECO", 40, -1, 1);

	TH1F * d_pL = new TH1F ("d_pL", "GEN/RECO", 20, -3.14, 3.14);
	TH1F * d_pZ = new TH1F ("d_pZ", "RECO/GEN", 20, -3.14, 3.13);

	for (int i = 1; i <= 40; i++)
		{
		cout << histoMap["MCCut_cosThetaL"]->GetBinContent(i) << " / " << histoMap["_cosThetaL"]->GetBinContent(i) << endl;
		double div_L = scale*histoMap["MCCut_cosThetaL"]->GetBinContent(i) / histoMap["_cosThetaL"]->GetBinContent(i);
		double div_Z = scale*histoMap["MCCut_cosThetaZ"]->GetBinContent(i) / histoMap["_cosThetaZ"]->GetBinContent(i);
//		cout << div_L << endl;
//		cout << div_Z << endl;
		if (div_L > 10) div_L = -1;
		if (div_Z > 10) div_Z = -1;
		d_L->SetBinContent(i, div_L);
		d_Z->SetBinContent(i, div_Z);
		}

	d_L->GetXaxis()->SetTitle("cos#theta_{l}");
	d_Z->GetXaxis()->SetTitle("cos#theta_{Z}");
	d_L->GetYaxis()->SetTitle("GEN + Cuts / RECO");
	d_Z->GetYaxis()->SetTitle("GEN + Cuts / RECO");

	double scale_p = histoMap["_phiL"]->Integral() / histoMap["MCCut_phiL"]->Integral();
	cout << "Scale Factor : " << scale_p << endl;

	for (int i = 1; i <= 20; i++)
		{
		double div_L = scale_p*histoMap["MCCut_phiL"]->GetBinContent(i) / histoMap["_phiL"]->GetBinContent(i);
		double div_Z = scale_p*histoMap["MCCut_phiZ"]->GetBinContent(i) / histoMap["_phiZ"]->GetBinContent(i);
		if (div_L > 10) div_L = -1;
		if (div_Z > 10) div_Z = -1;
		d_pL->SetBinContent(i, div_L);
		d_pZ->SetBinContent(i, div_Z);
		}

	d_pL->GetXaxis()->SetTitle("#phi_{l}");
	d_pZ->GetXaxis()->SetTitle("#phi_{Z}");
	d_pL->GetYaxis()->SetTitle("GEN + Cuts / RECO");
	d_pZ->GetYaxis()->SetTitle("GEN + Cuts / RECO");

//	TLegend * leg = new TLegend(0.35, 0.2, 0.5, 0.35);
//	leg->SetFillColor(0);
//	leg->SetBorderColor(0);
//	leg->SetTextSize(0.07);

	TCanvas * c1 = new TCanvas("c1");
	d_L->Draw("e");
//	leg->Draw();
	c1->SaveAs("/afs/fnal.gov/files/home/room2/iraklich/public_html/ZGAMMA/MACROS/output/MCCut_RECO_cosThetaL.gif");

	TCanvas * c2 = new TCanvas("c2");
	d_Z->Draw("e");
	c2->SaveAs("/afs/fnal.gov/files/home/room2/iraklich/public_html/ZGAMMA/MACROS/output/MCCut_RECO_cosThetaZ.gif");

	TCanvas * c3 = new TCanvas("c3");
	d_pL->Draw("e");
	c3->SaveAs("/afs/fnal.gov/files/home/room2/iraklich/public_html/ZGAMMA/MACROS/output/MCCut_RECO_phiL.gif");

	TCanvas * c4 = new TCanvas("c4");
	d_pZ->Draw("e");
	c4->SaveAs("/afs/fnal.gov/files/home/room2/iraklich/public_html/ZGAMMA/MACROS/output/MCCut_RECO_phiZ.gif");

	c1->Delete();	
	c2->Delete();	
	return 0;
	}
//==========================================================================================
