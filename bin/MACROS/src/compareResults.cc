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
#include <TMultiGraph.h>
#include <TLegend.h>
#include <TROOT.h>
#include <TStyle.h>
#include <TLatex.h>
#include <THStack.h>
#include <TTree.h>

#include "TMath.h"

#include "../include/plotter.h"

using namespace std;

//===========================================================================================
int main(int argc, char **arg)
	{

	if (argc != 3)
		{
		cout << "./compareResults <file1> <file2>" << endl;
		return 0;
		}

	gROOT->ProcessLine(".L ../src/CMSStyle.C");
	gROOT->ProcessLine("CMSstyle()");
	gStyle->SetOptStat(0);
	gStyle->SetOptFit(1100);
	gStyle->SetOptTitle(0);
	gStyle->SetPalette(1);

	string amplitudesNOZ_html[] = {
//			T^{J}_{lambdaqq}_{lambdaz}_{lambdagamma} as used for the thesis
			"T<sup>0</sup><sub>0,-1,-1</sub>",
			"T<sup>1</sup><sub>-1,-1,-1</sub>",
			"T<sup>1</sup><sub>-1,0,-1</sub>",
			"T<sup>1</sup><sub>0,-1,-1</sub>",
			"T<sup>1</sup><sub>0,0,-1</sub>",
			"T<sup>1</sup><sub>1,-1,-1</sub>",
			"T<sup>1</sup><sub>1,0,-1</sub>",
			"T<sup>2</sup><sub>-1,-1,-1</sub>",
			"T<sup>2</sup><sub>-1,0,-1</sub>",
			"T<sup>2</sup><sub>-1,1,-1</sub>",
			"T<sup>2</sup><sub>0,-1,-1</sub>",
			"T<sup>2</sup><sub>0,0,-1</sub>",
			"T<sup>2</sup><sub>0,1,-1</sub>",
			"T<sup>2</sup><sub>1,-1,-1</sub>",
			"T<sup>2</sup><sub>1,0,-1</sub>",
			"T<sup>2</sup><sub>1,1,-1</sub>",
			"A<sub>-1</sub>",
			"A<sub>1</sub>"
			};

	string amplitudesNOZ[] = {
//			T^{J}_{lambdaqq}_{lambdaz}_{lambdagamma} as used for the thesis
			"T^{0}_{0,-1,-1}",
			"T^{1}_{-1,-1,-1}",
			"T^{1}_{-1,0,-1}",
			"T^{1}_{0,-1,-1}",
			"T^{1}_{0,0,-1}",
			"T^{1}_{1,-1,-1}",
			"T^{1}_{1,0,-1}",
			"T^{2}_{-1,-1,-1}",
			"T^{2}_{-1,0,-1}",
			"T^{2}_{-1,1,-1}",
			"T^{2}_{0,-1,-1}",
			"T^{2}_{0,0,-1}",
			"T^{2}_{0,1,-1}",
			"T^{2}_{1,-1,-1}",
			"T^{2}_{1,0,-1}",
			"T^{2}_{1,1,-1}",
			"A_{-1}",
			"A_{1}"
			};


	string amplitudesZ_html[] = {
//			T^{J}_{lambdaqq}_{lambdaz}_{lambdagamma} as used for the thesis
			"Re T<sup>0</sup><sub>0,-1,-1</sub>",
			"Re T<sup>1</sup><sub>-1,-1,-1</sub>",
			"Im T<sup>1</sup><sub>-1,-1,-1</sub>",
			"Re T<sup>1</sup><sub>-1,0,-1</sub>",
			"Im T<sup>1</sup><sub>-1,0,-1</sub>",
			"Re T<sup>1</sup><sub>0,-1,-1</sub>",
			"Im T<sup>1</sup><sub>0,-1,-1</sub>",
			"Re T<sup>1</sup><sub>0,0,-1</sub>",
			"Im T<sup>1</sup><sub>0,0,-1</sub>",
			"Re T<sup>1</sup><sub>1,-1,-1</sub>",
			"Im T<sup>1</sup><sub>1,-1,-1</sub>",
			"Re T<sup>1</sup><sub>1,0,-1</sub>",
			"Im T<sup>1</sup><sub>1,0,-1</sub>",
			"Re T<sup>2</sup><sub>-1,-1,-1</sub>",
			"Im T<sup>2</sup><sub>-1,-1,-1</sub>",
			"Re T<sup>2</sup><sub>-1,0,-1</sub>",
			"Im T<sup>2</sup><sub>-1,0,-1</sub>",
			"Re T<sup>2</sup><sub>-1,1,-1</sub>",
			"Im T<sup>2</sup><sub>-1,1,-1</sub>",
			"Re T<sup>2</sup><sub>0,-1,-1</sub>",
			"Im T<sup>2</sup><sub>0,-1,-1</sub>",
			"Re T<sup>2</sup><sub>0,0,-1</sub>",
			"Im T<sup>2</sup><sub>0,0,-1</sub>",
			"Re T<sup>2</sup><sub>0,1,-1</sub>",
			"Im T<sup>2</sup><sub>0,1,-1</sub>",
			"Re T<sup>2</sup><sub>1,-1,-1</sub>",
			"Im T<sup>2</sup><sub>1,-1,-1</sub>",
			"Re T<sup>2</sup><sub>1,0,-1</sub>",
			"Im T<sup>2</sup><sub>1,0,-1</sub>",
			"Re T<sup>2</sup><sub>1,1,-1</sub>",
			"Im T<sup>2</sup><sub>1,1,-1</sub>",
			"A<sub>-1</sub>",
			"A<sub>1</sub>"
			};

	string amplitudesZ[] = {
//			T^{J}_{lambdaqq}_{lambdaz}_{lambdagamma} as used for the thesis
			"Re T^{0}_{0,-1,-1}",
			"Re T^{1}_{-1,-1,-1}",
			"Im T^{1}_{-1,-1,-1}",
			"Re T^{1}_{-1,0,-1}",
			"Im T^{1}_{-1,0,-1}",
			"Re T^{1}_{0,-1,-1}",
			"Im T^{1}_{0,-1,-1}",
			"Re T^{1}_{0,0,-1}",
			"Im T^{1}_{0,0,-1}",
			"Re T^{1}_{1,-1,-1}",
			"Im T^{1}_{1,-1,-1}",
			"Re T^{1}_{1,0,-1}",
			"Im T^{1}_{1,0,-1}",
			"Re T^{2}_{-1,-1,-1}",
			"Im T^{2}_{-1,-1,-1}",
			"Re T^{2}_{-1,0,-1}",
			"Im T^{2}_{-1,0,-1}",
			"Re T^{2}_{-1,1,-1}",
			"Im T^{2}_{-1,1,-1}",
			"Re T^{2}_{0,-1,-1}",
			"Im T^{2}_{0,-1,-1}",
			"Re T^{2}_{0,0,-1}",
			"Im T^{2}_{0,0,-1}",
			"Re T^{2}_{0,1,-1}",
			"Im T^{2}_{0,1,-1}",
			"Re T^{2}_{1,-1,-1}",
			"Im T^{2}_{1,-1,-1}",
			"Re T^{2}_{1,0,-1}",
			"Im T^{2}_{1,0,-1}",
			"Re T^{2}_{1,1,-1}",
			"Im T^{2}_{1,1,-1}",
			"A_{-1}",
			"A_{1}"
			};

	map<string, TObject *> histoMap1, histoMap2;

	string file1 = arg[1];
	string file2 = arg[2];
	string outPrefix = "/afs/fnal.gov/files/home/room2/iraklich/public_html/ZGAMMA/MACROS/output/comp";
	string outBase = "";
	string outGif = "";
	string outHTML = "";

	string legend1 = "";
	string legend2 = "";

	if (file1.find("Data") != string::npos)
		{
		legend1 = "Data";
		outBase.append("_Data");
		}
	if (file1.find("SIG") != string::npos)
		{
		legend1 = "SIG";
		outBase.append("_SIG");
		}
	if (file1.find("GEN") != string::npos)
		{
		legend1 = "GEN";
		outBase.append("_GEN");
		}
	if (file1.find("NSM") != string::npos)
		{
		legend1 = "NSM";
		outBase.append("_NSM");
		}
	if (file1.find("BS") != string::npos)
		{
		legend1 = "BS";
		outBase.append("_BS");
		}
	if (file1.find("NLO") != string::npos)
		{
		legend1 = "NLO";
		outBase.append("_NLO");
		}
	if (file1.find("ee") != string::npos)
		{
		outBase.append("_ee");
		}
 	if (file1.find("mm") != string::npos)
		{
		outBase.append("_mm");
		}
//-----------------------------------------------------
 	if (file2.find("Data") != string::npos)
		{
		legend2 = "Data";
		outBase.append("_Data");
		}
	if (file2.find("SIG") != string::npos)
		{
		legend2 = "SIG";
		outBase.append("_SIG");
		}
	if (file2.find("GEN") != string::npos)
		{
		legend2 = "GEN";
		outBase.append("_GEN");
		}
	if (file2.find("NSM") != string::npos)
		{
		legend2 = "NSM";
		outBase.append("_NSM");
		}
	if (file2.find("BS") != string::npos)
		{
		legend2 = "BS";
		outBase.append("_BS");
		}
	if (file2.find("NLO") != string::npos)
		{
		legend2 = "NLO";
		outBase.append("_NLO");
		}

	if (legend1 == "") legend1 = "SM";
	if (legend2 == "") legend2 = "SM";

	outHTML = outPrefix + outBase + ".html";
	outBase.append(".gif");
	outGif = outPrefix + outBase;
	outBase = "comp" + outBase;

	FILE * outFileHTML;
	outFileHTML = fopen(outHTML.c_str(), "w");

	histoMap1 = objToMap(file1);
	histoMap2 = objToMap(file2);

	TGraph * gr1 = new TGraph();
	TGraph * gr2 = new TGraph();
	TMultiGraph * mg = new TMultiGraph();

	gr1 = (TGraph *) histoMap1["Graph"];
	gr1->SetMarkerStyle(6);
	gr2 = (TGraph *) histoMap2["Graph"];
	gr2->SetMarkerStyle(7);
	gr2->SetMarkerColor(2);
	gr2->SetLineColor(2);

	const int npar = gr1->GetN();

	cout << "TOTAL NUMBER OF PARAMETERS = " << npar << endl;

	double * value1;
	double * value2;
	double * error1;
	double * error2;
	double chi2[npar];

	value1 = gr1->GetY();
	error1 = gr1->GetEY();
	value2 = gr2->GetY();
	error2 = gr2->GetEY();

	for (int i = 0; i < npar; i++)
		{
		if (error1[i] == 0 || error2[i] == 0) {cout << "skipping parameter # "<< i << endl; continue;}
		chi2[i] = (value1[i] - value2[i])*(value1[i] - value2[i]) / (error1[i]*error1[i] + error2[i]*error2[i]);
		}

	mg->Add(gr1, "p");
	mg->Add(gr2, "p");

	double * gr1Y = gr1->GetY();
	double * gr1EY = gr1->GetEY();

	double * gr2Y = gr2->GetY();
	double * gr2EY = gr2->GetEY();


	double grMax = 0;
	double grMin = 0;

	for(int i = 0; i < npar; i++)
		{
		if (grMax < gr1Y[i]) grMax = gr1Y[i] + 1.5*gr1EY[i];
		if (grMax < gr2Y[i]) grMax = gr2Y[i] + 1.5*gr2EY[i];
		if (grMin > gr1Y[i]) grMin = gr1Y[i] - 1.5*gr1EY[i];
		if (grMin > gr2Y[i]) grMin = gr2Y[i] - 1.5*gr2EY[i];
		}

	char chi2Text[30];

	TLatex * tex = new TLatex();
	tex->SetNDC();
	tex->SetTextSize(0.04);

	TH1F * hmg = new TH1F("hmg", "hmg", npar, 0, npar);

	TCanvas * c = new TCanvas();
	c->SetCanvasSize(800, 800);

	TLegend * leg = new TLegend(0.8, 0.8, 0.9, 0.9);
	leg->SetFillColor(0);
	leg->AddEntry(gr1, legend1.c_str() , "pl");
	leg->AddEntry(gr2, legend2.c_str() , "pl");

	for (int i = 0; i < npar; i++)
		if (npar == 18) hmg->GetXaxis()->SetBinLabel(i+1, amplitudesNOZ[i].c_str());
		else hmg->GetXaxis()->SetBinLabel(i+1, amplitudesZ[i].c_str());

	hmg->SetMinimum(grMin);
	hmg->SetMaximum(grMax);
	hmg->SetLineStyle(2);
	hmg->GetXaxis()->SetLabelSize(0.04);
	hmg->GetXaxis()->LabelsOption("v");
	hmg->Draw();

	mg->Draw();
//	for (int i = 0; i < npar; i++)
//		mg->GetXaxis()->SetBinLabel(6*(i+1), "#gamma_{T}");
//		mg->GetXaxis()->SetBinLabel(i+1, amplitudesZ[i].c_str());


	leg->Draw();
	c->SaveAs(outGif.c_str());

	delete c;

	string channel = "";
	if (file1.find("ee") != string::npos) channel.append("Electron Channel");
	if (file1.find("mm") != string::npos) channel.append("Muon Channel");

	string bgcolor[] =	{
				"#FF0000",
				"#FF1919",
				"#FF3333",
				"#FF4D4D",
				"#FF6666",
				"#FF8080",
				"#FF9999",
				"#FFB2B2",
				"#FFCCCC",
				"#FFE6E6",
				"#FFFFFF"
				};
	fprintf (outFileHTML, "<html>\n\t<head>\n\t\t<title>Irakli Chakaberia : Current Results of My Z&gamma; Analysis</title>\n\t</head>\n\t<body>");

	fprintf(outFileHTML, "<img src=\"%s\">\n", outBase.c_str());

	fprintf(outFileHTML, "<table border = 1>\n<tr>\n\t<td colspan = 34>%s</td>\n</tr>", channel.c_str());
	fprintf(outFileHTML, "<tr>\n\t<td></td>\n");
	for (int i = 0; i < npar; i++)
		{
		if (npar == 18) fprintf(outFileHTML, "\t<td>%s</td>\n", amplitudesNOZ_html[i].c_str());
		else fprintf(outFileHTML, "\t<td>%s</td>\n", amplitudesZ_html[i].c_str());
		}
	fprintf(outFileHTML, "</tr>\n");

	fprintf(outFileHTML, "<tr>\n\t<td>%s</td>\n", legend1.c_str());
	for (int i = 0; i < npar; i++)
		{
		fprintf(outFileHTML, "\t<td>%f &pm; %f</td>\n", gr1Y[i], gr1EY[i]);
		}
	fprintf(outFileHTML, "</tr>\n");

	fprintf(outFileHTML, "<tr>\n\t<td>%s</td>\n", legend2.c_str());
	for (int i = 0; i < npar; i++)
		{
		fprintf(outFileHTML, "\t<td>%f &pm; %f</td>\n", gr2Y[i], gr2EY[i]);
		}
	fprintf(outFileHTML, "</tr>\n");

	fprintf(outFileHTML, "<tr>\n\t<td>&chi;<sup>2</sup></td>\n");
	for (int i = 0; i < npar; i++)
		{
		int index = chi2[i] / 2;
		if (index > 10) index = 10;
		index = 10 - index;
		fprintf(outFileHTML, "\t<td bgcolor = %s>%f</td>\n", chi2[i], bgcolor[index].c_str());
		}
	fprintf(outFileHTML, "</tr>\n</table>\n");

	fprintf(outFileHTML, "\t</body>\n</html>\n");

	return 0;
	}
//==========================================================================================
