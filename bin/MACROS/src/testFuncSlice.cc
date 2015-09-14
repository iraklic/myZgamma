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
#include <TStyle.h>
#include "TCanvas.h"
#include "TH1.h"
#include "TH2.h"
#include "../include/likelihoodFunc.h"
#include "TGraphTime.h"

#include <iostream>
#include <map>
#include "../include/plotter.h"
#include "../include/readParams.h"
// global variables for not doing same routine many times in functions outside this cc file
#include "../include/extern.h"

//#ifdef __SC__
//long G__globalvarpointer; // To make the Symantec linker happy
//#endif

extern void myFcn(Int_t &npar, Double_t *gin, Double_t &f, Double_t *x, Int_t iflag);

using namespace std;

//TH1F * h1 = new TH1F("h1","h1", 200, -40, 80);

vector<vector<double> > varVec;


// arrays for -ln(L) minimization process graph
double X[10000];
double Y[10000];
int  minIterCount = 0;

//==============================================================================
void myFunc(Double_t *x)
	{
	FILE * outFitResultcosL;
	FILE * outFitResultcosZ;
	FILE * outFitResultphiL;
	FILE * outFitResultphiZ;
	outFitResultcosL = fopen("fitGENResultcosL.txt","w");
	outFitResultcosZ = fopen("fitGENResultcosZ.txt","w");
	outFitResultphiL = fopen("fitGENResultphiL.txt","w");
	outFitResultphiZ = fopen("fitGENResultphiZ.txt","w");
	double varsL[10];
	double varsZ[10];

	map<int, double> cosZMap, cosLMap, phiLMap, phiZMap;

	pair<double, double> tempLhoodL;
	pair<double, double> tempLhoodZ;

	cout << "FINAL BIN BY BIN RESULT CALCULATION STARTED!" << endl;

	for (int icosInterest = -975; icosInterest < 1000; icosInterest += 50)
		{
		cout << icosInterest << endl;
		for (int icosIntegral = -975; icosIntegral< 1000; icosIntegral += 50)
			for (double iphiL = -2.983; iphiL < 3.14; iphiL += 0.314)
				for (double iphiZ = -2.983; iphiZ < 3.14; iphiZ += 0.314)
					{
					varsL[0] = (double) icosInterest / 1000.;
					varsL[1] = (double) icosIntegral / 1000.;
					varsL[2] = iphiL;
					varsL[3] = iphiZ;
					varsL[4] = 91.19;
					varsL[5] = 300.0;

					varsZ[0] = (double) icosIntegral / 1000.;
					varsZ[1] = (double) icosInterest / 1000.;
					varsZ[2] = iphiL;
					varsZ[3] = iphiZ;
					varsZ[4] = 91.19;
					varsZ[5] = 300.0;

					tempLhoodL = likelihood(varsL, x);
					tempLhoodZ = likelihood(varsZ, x);

					if (cosLMap.find(icosInterest) == cosLMap.end()) cosLMap[icosInterest] = tempLhoodL.first;
					else cosLMap[icosInterest] += tempLhoodL.first;

					if (cosZMap.find(icosInterest) == cosZMap.end()) cosZMap[icosInterest] = tempLhoodZ.first;
					else cosZMap[icosInterest] += tempLhoodZ.first;
					}
		}
/*
	for (int iphiInterest = -2983; iphiInterest < 3140; iphiInterest += 314) // this is for -3.14 to 3.14 in 20 bins
		{
		cout << iphiInterest << endl;
		for (int iphiIntegral = -2983; iphiIntegral< 3140; iphiIntegral += 314)
			for (double icosL = -0.95; icosL < 1; icosL += 0.1)
				for (double icosZ = -0.95; icosZ < 1; icosZ += 0.1)
					{
					varsL[0] = icosL;
					varsL[1] = icosZ;
					varsL[2] = (double) iphiInterest / 1000.;
					varsL[3] = (double) iphiIntegral / 1000.;
					varsL[4] = 91.19;
					varsL[5] = 300.0;

					varsZ[0] = icosL;
					varsZ[1] = icosZ;
					varsZ[2] = (double) iphiIntegral / 1000.;
					varsZ[3] = (double) iphiInterest / 1000.;
					varsZ[4] = 91.19;
					varsZ[5] = 300.0;

					tempLhoodL = likelihood(varsL, x);
					tempLhoodZ = likelihood(varsZ, x);

					if (phiLMap.find(iphiInterest) == phiLMap.end()) phiLMap[iphiInterest] = tempLhoodL.first;
					else phiLMap[iphiInterest] += tempLhoodL.first;

					if (phiZMap.find(iphiInterest) == phiZMap.end()) phiZMap[iphiInterest] = tempLhoodZ.first;
					else phiZMap[iphiInterest] += tempLhoodZ.first;
					}
		}
*/
	for (map<int, double>::iterator mit = cosLMap.begin(); mit != cosLMap.end(); mit++)
		fprintf(outFitResultcosL, "%f\n", mit->second);
	for (map<int, double>::iterator mit = cosZMap.begin(); mit != cosZMap.end(); mit++)
		fprintf(outFitResultcosZ, "%f\n", mit->second);
//	for (map<int, double>::iterator mit = phiLMap.begin(); mit != phiLMap.end(); mit++)
//		fprintf(outFitResultphiL, "%f\n", mit->second);
//	for (map<int, double>::iterator mit = phiZMap.begin(); mit != phiZMap.end(); mit++)
//		fprintf(outFitResultphiZ, "%f\n", mit->second);

	fclose(outFitResultcosL);
	fclose(outFitResultcosZ);
	fclose(outFitResultphiL);
	fclose(outFitResultphiZ);
	}
//==============================================================================
int main(int argc, char **arg)
	{
	gROOT->ProcessLine(".L ../src/CMSStyle.C");
	gROOT->ProcessLine("CMSstyle()");
	gStyle->SetOptStat(0);
	gStyle->SetOptTitle(0);
	gStyle->SetPalette(1);

	withTCORR	= false;
	globalJ		= 2;
	runType		= "mc";
	finalFileName	= "../input/histos_MG5_SM_mm_ISR_ONLY.root";
	complexT	= false;
	doIt		= false;
	isData		= false;
	onceDone	= true;
	debug		= false;

	if (argc < 6)
		{
		cout << "please enter <parameterFile> <cosThetaL> <cosThetaZ> <phiL> <phiZ>" << endl;
		cout << "set -999 for the variable you want to plot with respect to others" << endl;
		return 0;
		}
	string parFile = arg[1];

	vector<double> params;
	params = readParams(parFile);

	double x[params.size()/2];

	for (int i = 0; i < params.size() / 2; i++)
		{
		x[i] = params[2*i];
		cout << x[i] << endl;
		}

	double vars[6];
	vars[0] = atof(arg[2]);
	vars[1] = atof(arg[3]);
	vars[2] = atof(arg[4]);
	vars[3] = atof(arg[5]);

	if (argc  == 8)
		{
		vars[4] = atof(arg[6]);
		vars[5] = atof(arg[7]);
		}
	else
		{
		vars[4] = 91.19;
		vars[5] = 300.0;
		}

	char * title;
	int k = 0;
	bool value = false;

	if (vars[0] == -999) {k = 0; title = "cos#theta_{l}";}
	else if (vars[1] == -999) {k = 1; title = "cos#theta_{Z}";}
	else if (vars[2] == -999) {k = 2; title = "$phi_{l}";}
	else if (vars[3] == -999) {k = 3; title = "$phi_{Z}";}
	else value = true;

	cout << vars[0] << " : " << vars[1] << " : " << vars[2] << " : " << vars[3] << " : " << vars[4] << " : " << vars[5] << endl;

//	myFunc(x);
	pair<double, double> tempLhood;

	TCanvas * c = new TCanvas();
	TH1F * h = new TH1F("", "" , 2001, -1, 1);

	h->SetMinimum(0);
//	h->SetMaximum(0.18);
	h->GetXaxis()->SetTitle(title);

	TGraphTime * grt = new TGraphTime(61, -1, 0, 1, 0.2);

	int counter = 1;
	int slot = 0;

	for (int i = -1000; i <= 1000; i++)
			{
			if (value) 
				{
				cout << likelihood(vars, x).first << endl;
				return 0;
				}
			vars[k] = i / 1000.;
			tempLhood = likelihood(vars, x);
			h->SetBinContent(counter, tempLhood.first);
//			cout << "filling bin " << counter << " for variable " << k << " = " << vars[k] << endl;
			counter++;
			}

	h->Draw();
	c->SaveAs("/afs/fnal.gov/files/home/room2/iraklich/public_html/ZGAMMA/MACROS/output/funcSlice.gif");

	char fileName[20];
/*
	TH2F * h2 = new TH2F("h2","h2", 81, -1, 1, 81, -1, 1);

	for (int pl = -29; pl < 30; pl+=2)
		{
		for (int i = 1; i <= 81; i++)
			for (int j = 1; j <= 81; j++)
				{
				vars[0] = -1 + 0.025*(i-1);
				vars[1] = -1 + 0.025*(j-1);
				vars[2] = pl / 10.;
				tempLhood = likelihood(vars, x);
				h2->SetBinContent(i, j, tempLhood.first);
//				cout << i << " : " << vars[0] << "; " << j << " : " << vars[1] << "; " << vars[2] << "; " << vars[3] << endl;
				}
		h2->SetMinimum(0);
		h2->SetMaximum(0.03);
		h2->Draw("lego2hist");
		sprintf(fileName, "test_%d.gif", pl);
		cout << fileName << endl;
		c->SaveAs(fileName);

//		grt->Add(h, slot);
//		cout << "Adding to slot # " << slot << endl;
//		slot++;
		}
	cout << "Number of measurements (bins) : " << counter << endl;
*/
//	grt->Draw();
//	grt->SaveAnimatedGif("/afs/fnal.gov/files/home/room2/iraklich/public_html/ZGAMMA/MACROS/output/funcSlice_anime.gif");
//	c->SaveAs("anime.root");
	return 0;
	}
//==============================================================================

