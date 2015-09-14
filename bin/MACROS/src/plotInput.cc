//================================================================================================================
//== Author		: Irakli Chakaberia							 		==
//== Date		: 2010 Dec 10       					                		==
//== Last Update	: 2013 Feb 20							 			==
//== Running		: ./myMinexam [inputFile] [runType ][1/0] [if 0 initParam / if 1 filename with params]	==
//== finalFileName	: is the fileName for file with weights for acceptances					==
//================================================================================================================

#include "TROOT.h"
#include <TTree.h>
#include "TMinuit.h"
#include "TMath.h"
#include "TCanvas.h"
#include <TStyle.h>
#include "TH1.h"
#include "../include/likelihoodFunc.h"

#include <iostream>
#include <map>
#include "../include/plotter.h"
#include "../include/readParams.h"

using namespace std;

int main(int argc, char **arg)
	{
	gROOT->ProcessLine(".L ../src/CMSStyle.C");
	gROOT->ProcessLine("CMSstyle()");
	gStyle->SetOptStat(0);
	gStyle->SetOptTitle(0);

	TCanvas * c = new TCanvas();

	vector<double> hist;

	string inputFile = arg[1];

	hist = readParams(arg[1]);

	int nBins = 20;
	if (inputFile.find("cos") != string::npos) nBins = 40;

	TH1F * h = new TH1F("h","h", nBins, -1, 1);

	for (int i = 0; i < hist.size(); i++)
		{
		h->SetBinContent(i+1, hist[i]);
		cout << "setting bin" << i << " to " << hist[i] << endl;
		}

	h->SetMinimum(0);
	h->UseCurrentStyle();

	if (inputFile.find("cosL") != string::npos)
		{
		h->GetYaxis()->SetTitle("#int_{} f(#Omega) d(cos#theta_{Z}) d#phi_{l} d#phi_{Z}");
		h->GetXaxis()->SetTitle("cos#theta_{l}");
		}
	if (inputFile.find("cosZ") != string::npos)
		{
		h->GetYaxis()->SetTitle("#int_{} f(#Omega) d(cos#theta_{l}) d#phi_{l} d#phi_{Z}");
		h->GetXaxis()->SetTitle("cos#theta_{Z}");
		}
	if (inputFile.find("phiL") != string::npos)
		{
		h->GetYaxis()->SetTitle("#int_{} f(#Omega) d(cos#theta_{l}) d(cos#theta_{Z}) d#phi_{Z}");
		h->GetXaxis()->SetTitle("#phi_{l}");
		}
	if (inputFile.find("phiZ") != string::npos)
		{
		h->GetYaxis()->SetTitle("#int_{} f(#Omega) d(cos#theta_{l}) d(cos#theta_{Z}) d#phi_{l}");
		h->GetXaxis()->SetTitle("#phi_{Z}");
		}

//	h->DrawNormalized();
	h->Draw();

	string outFile = "/afs/fnal.gov/files/home/room2/iraklich/public_html/ZGAMMA/MACROS/output/function_";

	outFile.append(arg[1]);
	outFile.append(".gif");

	c->SaveAs(outFile.c_str());

	return 0;
	}

