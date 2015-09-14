#include <TH1.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TGraphErrors.h>
#include <TMultiGraph.h>
#include <TStyle.h>
#include <TROOT.h>

#include <map>
#include <utility>
#include <vector>
#include <string>
#include <TLatex.h>

using namespace std;

map<string, TH1F *> histoToMap (string file, string type)
	{
	map<string, TH1F *> histoMap;
        TKey *key = 0;
        TFile * myFile = new TFile(file.c_str());

        TIter iter (myFile->GetListOfKeys());
        while((key = (TKey*) iter()))
		{
                histoMap[key->GetName()] = (TH1F*)key->ReadObj();
		}
//	myFile->Close();
	return histoMap;
	}

vector<double> readParams(string fileName)
	{
	vector<double> vec;
	FILE * myParFile;
	myParFile = fopen(fileName.c_str(), "r");
	if (myParFile == NULL) { cout << "File error : " << fileName << endl; return vec;}
	float data = 0;
	while (fscanf(myParFile, "%f", &data) != EOF)
		vec.push_back(data);

	fclose(myParFile);
	return vec;
	}

void parameters()
	{
	gROOT->ProcessLine(".L ../include/CMSStyle.C");
	gROOT->ProcessLine("CMSstyle()");
	gStyle->SetOptStat(0);
	gStyle->SetOptTitle(0);

	map<string, TH1F *> histoMap;
	histoMap = histoToMap("../input/histos_BAUR_SM_mm.root");

	(0.728*histoMap["MCCut_cosThetaL"]/histoMap["_cosThetaL"])->Draw();
	


	TLatex * tex = new TLatex();
	tex->SetNDC();
	tex->SetTextSize(0.04);

	TLegend * leg = new TLegend(0.7, 0.9, 1.0, 1.0);
	leg->SetLineColor(0);
	leg->SetFillColor(0);


	TCanvas * c1 = new TCanvas();

	tex->DrawLatex(0.18, 0.96, "CMS Preliminary, 2011");


	tex->DrawLatex(0.18, 0.96, "CMS Preliminary, 2011, Electron Channel");
//	tex->DrawLatex(0.18, 0.96, "CMS Preliminary, 2011, Muon Channel");
	tex->DrawLatex(0.8, 0.96, "#sqrt{s} = 7 TeV");


	mg->Draw("APE");

	
	leg->Draw();

	c1->SaveAs("/afs/fnal.gov/files/home/room2/iraklich/public_html/ZGAMMA/MACROS/output/params.gif");

	}
