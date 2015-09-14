//========================================================================================
//== Author		: Irakli Chakaberia						==
//== Date		: 2010 Dec 10       					        ==
//== Last Update	: 2013 Jul 11							==
//== Running		: ./myMinexam [cardFile] 					==
//== finalFileName	: is the fileName for file with weights for acceptances		==
//========================================================================================

#include "TROOT.h"
#include <TTree.h>
#include "TMinuit.h"
#include "TMath.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TH1.h"
#include "../include/likelihoodFunc.h"
#include "TMultiGraph.h"
#include "TGraphErrors.h"
#include "TLatex.h"

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

TH1F * h1 = new TH1F("h1","h1", 200, -40, 80);


double lumi = 0;
vector<vector<double> > varVec;
vector<vector<double> > varVecISR;
string fileName = "";


// arrays for -ln(L) minimization process graph
double X[10000];
double Y[10000];

double myFinalAcc[10000];
double myFinalLhood[10000];

map<int, vector<double> > myParameterMap;

int  minIterCount = 0;
string method = "";
int events = 0;
bool doCut = false;

//==============================================================================
void recoResults(vector<vector<double> > varVector, TFile * oFile, double * finalParams)
	{
	cout << "recoResults() : final fit vs. data comparison calculation started!" << endl;
	map<string, TH1F *> histoMap;
	histoMap = histoToMap(fileName);
	cout << "recoResults() : histograms to compare with fit retreived from : " << fileName << endl;
	pair<double, double> tempLhood;
	double vars[6];

	TCanvas * c_1 = new TCanvas();
	TCanvas * c_2 = new TCanvas();
	TCanvas * c_3 = new TCanvas();
	TCanvas * c_4 = new TCanvas();
//	c_1->Divide(2,2);

	TH1F * _cosThetaL = new TH1F("cosThetaL", "cosThetaL", 40, -1, 1);
	TH1F * _cosThetaZ = new TH1F("cosThetaZ", "cosThetaZ", 40, -1, 1);
	TH1F * _phiL = new TH1F("phiL", "phiL", 20, -3.14, 3.14);
	TH1F * _phiZ = new TH1F("phiZ", "phiZ", 20, -3.14, 3.14);

	_cosThetaL->UseCurrentStyle();
	_cosThetaZ->UseCurrentStyle();
	_phiL->UseCurrentStyle();
	_phiZ->UseCurrentStyle();

	_cosThetaL->SetMinimum(0);
	_cosThetaZ->SetMinimum(0);
	_phiL->SetMinimum(0);
	_phiZ->SetMinimum(0);

	for (vector<vector<double> >::iterator it = varVector.begin(); it != varVector.end(); it++)
		{
		vars[0] = it->at(0);
		vars[1] = it->at(1);
		vars[2] = it->at(2);
		vars[3] = it->at(3);
		vars[4] = it->at(4);
		vars[5] = it->at(5);
		double weight = it->at(6);

		tempLhood = likelihood(vars, finalParams);
		double Pw = tempLhood.first / weight;

//		cout << Pw  << " = " << tempLhood.first << " / " << weight << endl;

		_cosThetaL->Fill(vars[0], Pw);
		_cosThetaZ->Fill(vars[1], Pw);
		_phiL->Fill(vars[2], Pw);
		_phiZ->Fill(vars[3], Pw);
		}

//	_cosThetaL->SetLineColor(2);
//	_cosThetaL->DrawNormalized("SAMES");

	cout << "SCALING STUDY : " << _cosThetaL->Integral() << " : " << varVector.size() << endl;

	_cosThetaL->Scale(histoMap["_cosThetaL"]->Integral()/_cosThetaL->Integral());
	_cosThetaZ->Scale(histoMap["_cosThetaZ"]->Integral()/_cosThetaZ->Integral());
	_phiL->Scale(histoMap["_phiL"]->Integral()/_phiL->Integral());
	_phiZ->Scale(histoMap["_phiZ"]->Integral()/_phiZ->Integral());

	cout << "SCALING STUDY : " << _cosThetaL->Integral() << " : " << varVector.size() << endl;

	double chi2_cosL = histoMap["_cosThetaL"]->Chi2Test(_cosThetaL, "WWCHI2");
	double chi2_cosZ = histoMap["_cosThetaZ"]->Chi2Test(_cosThetaZ, "WWCHI2");
	double chi2_phiL = histoMap["_phiL"]->Chi2Test(_phiL, "WWCHI2");
	double chi2_phiZ = histoMap["_phiZ"]->Chi2Test(_phiZ, "WWCHI2");

	histoMap["_cosThetaL"]->SetMinimum(0);
	histoMap["_cosThetaZ"]->SetMinimum(0);
	histoMap["_phiL"]->SetMinimum(0);
	histoMap["_phiZ"]->SetMinimum(0);

	histoMap["_cosThetaL"]->GetXaxis()->SetTitle("cos#theta_{l}");
	histoMap["_cosThetaL"]->GetYaxis()->SetTitle("Number of Events");


	char chi2Text[30];

	TLegend * leg1 = new TLegend(0.5, 0.5, 0.6, 0.6);
	TLegend * leg2 = new TLegend(0.5, 0.5, 0.6, 0.6);
	TLegend * leg3 = new TLegend(0.5, 0.5, 0.6, 0.6);
	TLegend * leg4 = new TLegend(0.5, 0.5, 0.6, 0.6);

	leg1->SetBorderSize(1);
	leg2->SetBorderSize(1);
	leg3->SetBorderSize(1);
	leg4->SetBorderSize(1);

	TLatex * tex = new TLatex();
	tex->SetNDC();
	tex->SetTextSize(0.04);

	c_1->cd();
	histoMap["_cosThetaL"]->Draw("E");
	_cosThetaL->SetLineColor(2);
	_cosThetaL->Draw("SAME");
	tex->DrawLatex(0.18, 0.96, "CMS Preliminary, 2011");
	sprintf(chi2Text, "#chi^{2} / NDF = %.2f / 40", chi2_cosL);
	tex->DrawLatex(0.7, 0.85, chi2Text);
	leg1->AddEntry(histoMap["_cosThetaL"], "data", "pl");
	leg1->AddEntry(_cosThetaL, "fit", "l");
	leg1->Draw();

	c_2->cd();
	histoMap["_cosThetaZ"]->Draw("E");
	_cosThetaZ->SetLineColor(2);
	_cosThetaZ->Draw("SAME");
	tex->DrawLatex(0.18, 0.96, "CMS Preliminary, 2011");
	sprintf(chi2Text, "#chi^{2} / NDF = %.2f / 40", chi2_cosZ);
	tex->DrawLatex(0.7, 0.85, chi2Text);
	leg2->AddEntry(histoMap["_cosThetaZ"], "data", "pl");
	leg2->AddEntry(_cosThetaZ, "fit", "l");
	leg2->Draw();

	c_3->cd();
	histoMap["_phiL"]->Draw("E");
	_phiL->SetLineColor(2);
	_phiL->Draw("SAME");
	tex->DrawLatex(0.18, 0.96, "CMS Preliminary, 2011");
	sprintf(chi2Text, "#chi^{2} / NDF = %.2f / 20", chi2_phiL);
	tex->DrawLatex(0.7, 0.85, chi2Text);
	leg3->AddEntry(histoMap["_phiL"], "data", "pl");
	leg3->AddEntry(_phiL, "fit", "l");
	leg3->Draw();

	c_4->cd();
	histoMap["_phiZ"]->Draw("E");
	_phiZ->SetLineColor(2);
	_phiZ->Draw("SAME");
	tex->DrawLatex(0.18, 0.96, "CMS Preliminary, 2011");
	sprintf(chi2Text, "#chi^{2} / NDF = %.2f / 20", chi2_phiZ);
	tex->DrawLatex(0.7, 0.85, chi2Text);
	leg4->AddEntry(histoMap["_phiZ"], "data", "pl");
	leg4->AddEntry(_phiZ, "fit", "l");
	leg4->Draw();

	oFile->cd();
	c_1->Write();
	c_2->Write();
	c_3->Write();
	c_4->Write();
	}

void myFunc(Double_t *x, string outFile)
	{
//	doIt = true;
	doIt = false;

	FILE * outFitResultcosL;
	FILE * outFitResultcosZ;
	FILE * outFitResultphiL;
	FILE * outFitResultphiZ;

	string cosL = outFile.append("_cosL.txt");
	string cosZ = outFile.append("_cosZ.txt");
	string phiL = outFile.append("_phiL.txt");
	string phiZ = outFile.append("_phiZ.txt");

	outFitResultcosL = fopen(cosL.c_str(), "w");
	outFitResultcosZ = fopen(cosZ.c_str(), "w");
	outFitResultphiL = fopen(phiL.c_str(), "w");
	outFitResultphiZ = fopen(phiZ.c_str(), "w");

	double varsL[10];
	double varsZ[10];

	map<int, double> cosZMap, cosLMap, phiLMap, phiZMap;

	pair<double, double> tempLhoodL;
	pair<double, double> tempLhoodZ;

	cout << "FINAL BIN BY BIN RESULT CALCULATION STARTED!" << endl;

	for (int icosInterest = -95; icosInterest < 100; icosInterest += 10)
		{
		for (int icosIntegral = -95; icosIntegral< 100; icosIntegral += 10)
			for (double iphiL = -2.983; iphiL < 3.14; iphiL += 0.314)
				for (double iphiZ = -2.983; iphiZ < 3.14; iphiZ += 0.314)
					{
					varsL[0] = (double) icosInterest / 100.;
					varsL[1] = (double) icosIntegral / 100.;
					varsL[2] = iphiL;
					varsL[3] = iphiZ;
					varsL[4] = 91.19;
					varsL[5] = 145.0;

					varsZ[0] = (double) icosIntegral / 100.;
					varsZ[1] = (double) icosInterest / 100.;
					varsZ[2] = iphiL;
					varsZ[3] = iphiZ;
					varsZ[4] = 91.19;
					varsZ[5] = 145.0;

					tempLhoodL = likelihood(varsL, x);
					tempLhoodZ = likelihood(varsZ, x);

					if (cosLMap.find(icosInterest) == cosLMap.end()) cosLMap[icosInterest] = tempLhoodL.first;
					else cosLMap[icosInterest] += tempLhoodL.first;

					if (cosZMap.find(icosInterest) == cosZMap.end()) cosZMap[icosInterest] = tempLhoodZ.first;
					else cosZMap[icosInterest] += tempLhoodZ.first;
					}
		}

	for (int iphiInterest = -2983; iphiInterest < 3140; iphiInterest += 314) // this is for -3.14 to 3.14 in 20 bins
		{
		for (int iphiIntegral = -2983; iphiIntegral< 3140; iphiIntegral += 314)
			for (double icosL = -0.95; icosL < 1; icosL += 0.1)
				for (double icosZ = -0.95; icosZ < 1; icosZ += 0.1)
					{
					varsL[0] = icosL;
					varsL[1] = icosZ;
					varsL[2] = (double) iphiInterest / 1000.;
					varsL[3] = (double) iphiIntegral / 1000.;
					varsL[4] = 91.19;
					varsL[5] = 145.0;

					varsZ[0] = icosL;
					varsZ[1] = icosZ;
					varsZ[2] = (double) iphiIntegral / 1000.;
					varsZ[3] = (double) iphiInterest / 1000.;
					varsZ[4] = 91.19;
					varsZ[5] = 145.0;

					tempLhoodL = likelihood(varsL, x);
					tempLhoodZ = likelihood(varsZ, x);

					if (phiLMap.find(iphiInterest) == phiLMap.end()) phiLMap[iphiInterest] = tempLhoodL.first;
					else phiLMap[iphiInterest] += tempLhoodL.first;

					if (phiZMap.find(iphiInterest) == phiZMap.end()) phiZMap[iphiInterest] = tempLhoodZ.first;
					else phiZMap[iphiInterest] += tempLhoodZ.first;
					}
		}

	for (map<int, double>::iterator mit = cosLMap.begin(); mit != cosLMap.end(); mit++)
		fprintf(outFitResultcosL, "%f\n", mit->second);
	for (map<int, double>::iterator mit = cosZMap.begin(); mit != cosZMap.end(); mit++)
		fprintf(outFitResultcosZ, "%f\n", mit->second);
	for (map<int, double>::iterator mit = phiLMap.begin(); mit != phiLMap.end(); mit++)
		fprintf(outFitResultphiL, "%f\n", mit->second);
	for (map<int, double>::iterator mit = phiZMap.begin(); mit != phiZMap.end(); mit++)
		fprintf(outFitResultphiZ, "%f\n", mit->second);

	fclose(outFitResultcosL);
	fclose(outFitResultcosZ);
	fclose(outFitResultphiL);
	fclose(outFitResultphiZ);
	}
//==============================================================================
vector<vector<double> > getVars(string type, string varFile, bool getWeights)
	{
	vector<vector<double> > tempVec;
//	=====================================================================
	cout << "getVars() : Reading variables from " << varFile << endl;
	if (getWeights) cout << "getVars() : Requesting weights as well!!" << endl;

	TFile * myFile = new TFile(varFile.c_str());
	TTree * anglesTree;

	if (type == "mc") anglesTree = (TTree*) myFile->GetKey("mcangles")->ReadObj();
	if (type == "mcReco") anglesTree = (TTree*) myFile->GetKey("mcCutangles")->ReadObj();
	if (type == "data") anglesTree = (TTree*) myFile->GetKey("angles")->ReadObj();

	cout << "getVars() : Branch of [" << type << "] requested!" << endl;

	Long64_t nentries = anglesTree->GetEntries();

//	set the number of measurements you want to use by hand, about same as number of events in data, in order to have reasonable job length
	int entryBatch = 0;
	int beginEntry = 0;
	int endEntry = nentries;
	int entryCounter = 0;

	if (events != -1)
		{
		endEntry = events;
		if (events * entryBatch <= nentries)
			{
			beginEntry = events*entryBatch;
			endEntry = beginEntry + events;
			}
		}

	if (getWeights)
		{
		beginEntry = 0;
		endEntry = nentries;
		}


	if (debug && doIt)
		{
		cout << "getVars() : debug and doIt MODE = NUMBER OF FOR ISR SAME AS FOR MAIN DATA !!!  = "<< events << endl;
                beginEntry = 0;
                endEntry = events;
		}

	cout << "getVars() : WORKING WITH " << endEntry - beginEntry << " EVENTS IN BATCH " << entryBatch << endl;
	cout << "getVars() : EVENTS FROM " << beginEntry << " TO " << endEntry << endl;
 
//	cout << "Initializing variables" << endl;
//	Declaration of leaf types
	Double_t        ZMass;
	Double_t        ZGMass;
	Double_t        cosThetaL;
	Double_t        cosThetaZ;
	Double_t        phiL;
	Double_t        phiZ;
	Double_t        weights;

//	List of branches
	TBranch        *b_ZMass;   //!
	TBranch        *b_ZGMass;   //!
	TBranch        *b_cosThetaL;   //!
	TBranch        *b_cosThetaZ;   //!
	TBranch        *b_phiL;   //!
	TBranch        *b_phiZ;   //!
	TBranch        *b_weights;   //!

//	cout << "Linking Branches" << endl;
//	fetching branches
	b_ZMass = anglesTree->GetBranch("ZMass");
	b_ZGMass = anglesTree->GetBranch("ZGMass");
	b_cosThetaL = anglesTree->GetBranch("cosThetaL");
	b_cosThetaZ = anglesTree->GetBranch("cosThetaZ");
	b_phiZ = anglesTree->GetBranch("phiZ");
	b_phiL = anglesTree->GetBranch("phiL");
	if (getWeights) b_weights = anglesTree->GetBranch("weights");

//	linking branch to variable
	b_ZMass->SetAddress(&ZMass);
	b_ZGMass->SetAddress(&ZGMass);
	b_cosThetaL->SetAddress(&cosThetaL);
	b_cosThetaZ->SetAddress(&cosThetaZ);
	b_phiL->SetAddress(&phiL);
	b_phiZ->SetAddress(&phiZ);
	if (getWeights) b_weights->SetAddress(&weights);

	pair<double, double> tempLhood;
	vector<double> var;

	cout << "getVars() : Filling tempVec" << endl;

	for (Long64_t jentry = beginEntry; jentry < endEntry; jentry++)
		{
		anglesTree->GetEntry(jentry);

//		CUTS FOR PARTICLES TO RUN MINIMIZER ON ------------------------
		if (doCut && cosThetaZ < -0.9) 
			{
			cout << "getvars() : selection cut activated!!!" << endl;
			if(events != -1) endEntry++;
			continue;
			}
//		---------------------------------------------------------------

		var.push_back(cosThetaL);
		var.push_back(cosThetaZ);
		var.push_back(phiL);
		var.push_back(phiZ);
		var.push_back(ZMass);
		var.push_back(ZGMass);
		if (getWeights) var.push_back(weights);

		tempVec.push_back(var);
		var.clear();
		}
	delete anglesTree;
	myFile->Close();

	cout << "getVars() : " << tempVec.size() << " events selected for analysis from : " << varFile  << endl;
	return tempVec;
	}
//==============================================================================
void myFunction(Double_t *x, string outFile)
	{
	FILE * outFitResultcosL;
	FILE * outFitResultcosZ;
	FILE * outFitResultphiL;
	FILE * outFitResultphiZ;

	string cosL = outFile + "_cosL.txt";
	string cosZ = outFile + "_cosZ.txt";
	string phiL = outFile + "_phiL.txt";
	string phiZ = outFile + "_phiZ.txt";

	outFitResultcosL = fopen(cosL.c_str(), "w");
	outFitResultcosZ = fopen(cosZ.c_str(), "w");
	outFitResultphiL = fopen(phiL.c_str(), "w");
	outFitResultphiZ = fopen(phiZ.c_str(), "w");

	map<int, double> mapCosL, mapCosZ, mapPhiL, mapPhiZ;

	pair<double, double> tempLhood;
	double vars[6];

	for (vector<vector<double> >::iterator it = varVec.begin(); it != varVec.end(); it++)
		{
		vars[0] = it->at(0);
		vars[1] = it->at(1);
		vars[2] = it->at(2);
		vars[3] = it->at(3);
		vars[4] = it->at(4);
		vars[5] = it->at(5);
		double weight = it->at(6);

		tempLhood = likelihood(vars, x);
		double tempValue = tempLhood.first / weight;

//		crazy construct to bin up the variables with steps of 0.1 and set the result in the middle of the bin
		int keyCosL = ((int)(vars[0]*100)/5) * 5 + (vars[0] < 0 ? -1 : 1)*2;
		int keyCosZ = ((int)(vars[1]*100)/5) * 5 + (vars[1] < 0 ? -1 : 1)*2;

//		addition division to 3.14 in phi angles to push them into (-1,1) window, thus getting the 20 bins
		int keyPhiL = ((int)((vars[2]/TMath::Pi())*100)/10) * 10 + (vars[2] < 0 ? -1 : 1)*5;
		int keyPhiZ = ((int)((vars[3]/TMath::Pi())*100)/10) * 10 + (vars[3] < 0 ? -1 : 1)*5;

//		cout << keyCosL << "\t" << keyCosZ << "\t" << keyPhiL << "\t" << keyPhiZ << endl;

		if  (mapCosZ.find(keyCosZ) == mapCosZ.end()) mapCosZ[keyCosZ] = tempValue;
		else mapCosZ[keyCosZ] += tempValue;

		if  (mapCosL.find(keyCosL) == mapCosL.end()) mapCosL[keyCosL] = tempValue;
		else mapCosL[keyCosL] += tempValue;

		if  (mapPhiZ.find(keyPhiZ) == mapPhiZ.end()) mapPhiZ[keyPhiZ] = tempValue;
		else mapPhiZ[keyPhiZ] += tempValue;

		if  (mapPhiL.find(keyPhiL) == mapPhiL.end()) mapPhiL[keyPhiL] = tempValue;
		else mapPhiL[keyPhiL] += tempValue;
		}
	for (map<int, double>::iterator mit = mapCosL.begin(); mit != mapCosL.end(); mit++)
		fprintf(outFitResultcosL, "%f\n", mit->second);
	for (map<int, double>::iterator mit = mapCosZ.begin(); mit != mapCosZ.end(); mit++)
		fprintf(outFitResultcosZ, "%f\n", mit->second);
	for (map<int, double>::iterator mit = mapPhiL.begin(); mit != mapPhiL.end(); mit++)
		fprintf(outFitResultphiL, "%f\n", mit->second);
	for (map<int, double>::iterator mit = mapPhiZ.begin(); mit != mapPhiZ.end(); mit++)
		fprintf(outFitResultphiZ, "%f\n", mit->second);

	fclose(outFitResultcosL);
	fclose(outFitResultcosZ);
	fclose(outFitResultphiL);
	fclose(outFitResultphiZ);
	}
//==============================================================================
int main(int argc, char **arg)
	{
	if (argc != 2)
		{
		cout << "please enter <card_file>" << endl;
		return 0;
		}
	string cardFile = arg[1];

//	reading and preparing Card file
	vector<string> setupParams;
	map<string, string> setupMap;
	setupParams = sreadParams(cardFile);

	for (int i = 0; i < setupParams.size(); i+=2)
		{
		setupMap[setupParams[i]] = setupParams[i+1];
		cout << setupParams[i] << "\t\t " << setupParams[i+1] << endl;
		}

	globalJ		= atoi(setupMap["globalJ"].c_str());
	runType		= setupMap["runType"];
	bool file	= (bool) atoi(setupMap["inputParamsB"].c_str());
	fileName	= setupMap["inpFile"];
	finalFileName	= setupMap["accFile"];
	string input	= setupMap["inputParamsF"];
	double startValue = atof(setupMap["startValue"].c_str());
	complexT	= (bool) atoi(setupMap["complex"].c_str());
	int methodValue	= atoi(setupMap["method"].c_str());
	lumi		= atof(setupMap["lumi"].c_str());
	events		= atoi(setupMap["events"].c_str());
	doCut		= (bool) atoi(setupMap["doCut"].c_str());

	if (methodValue == 0) {withTCORR = true;	method = "EML";}
	if (methodValue == 1) {withTCORR = false;	method = "EML";}
	if (methodValue == 2) {withTCORR = true;	method = "ML";}
	if (methodValue == 3) {withTCORR = false;	method = "ML";}

	if (method == "EML") cout << "main(): USING EXTENDED MAXIMUM LIKELIHOOD METHOD" << endl;
	if (method == "ML") cout << "main(): USING MAXIMUM LIKELIHOOD METHOD - " << endl;

//	DEBUG VARIABLES
	doIt = false;
	debug = false;


	if (runType != "data" && runType != "mc" && runType != "mcReco")
		{
		cout << "please enter right runType <data> or <mc>" << endl;
		return 0; 
		}

	cout << "main(): Working with " << fileName << " and type [" << runType << "]" << endl;
	cout << "main(): Using " << finalFileName << " as acceptance file" << endl;

//	CONSTRUCTING THE OUTPUT FILENAME FROM INPUT PARAMETERS ===============
	string fileBase = "outParams_";
	string outParams = "";
	string outRoot = "";

	fileBase.append(setupMap["globalJ"]);
	fileBase.append("_");

	if (file) fileBase.append(input);
	fileBase.append("_");
	fileBase.append(setupMap["startValue"]);

	fileBase.append("_");
	fileBase.append(setupMap["method"]);

	if (fileName.find("BAUR") != string::npos) fileBase.append("_BAUR");
	else if (fileName.find("MG5") != string::npos)
		{
		fileBase.append("_MG5");
		if (fileName.find("_NLO") != string::npos) fileBase.append("_NLO");
		if (fileName.find("_BS") != string::npos) fileBase.append("_BS");
		else fileBase.append("_LO");
		}
	else if (fileName.find("BS") != string::npos) fileBase.append("_BS");
	else fileBase.append("_Data");

	if (fileName.find("ee") != string::npos || fileName.find("Ele") != string::npos) fileBase.append("_ee");
	else fileBase.append("_mm");

	if (fileName.find("NSM") != string::npos) fileBase.append("_NSM");
	else if (fileName.find("SM") != string::npos) fileBase.append("_SM");
	if (runType == "mcReco") fileBase.append("_GEN");

	if (complexT) fileBase.append("_Z");
	if (doCut) fileBase.append("_CUT");

	if (cardFile.find("SIG") != string::npos) fileBase.append("_SIG");

	outParams = fileBase + ".txt";
	outRoot = fileBase + ".root";

	cout << "main(): output filename is : " << fileBase << endl;

	FILE * outFile;
	outFile = fopen(outParams.c_str(), "w");

//	======================================================================

//	for (map<string, string>::iterator mit = setupMap.begin(); mit != setupMap.end(); mit++)
//		fprintf(outFile, "%s\t%s\n", mit->first.c_str(), mit->second.c_str());

//	fprintf(outFile, "---------\n");

	varVec		= getVars(runType, fileName, 0);
	varVecISR	= getVars(runType, finalFileName, 1);

	cout << "main(): WORKING WITH " << lumi << " 1/pb LUMINOSITY - " << endl;

//	if running over MC truth then epsilons should be set 1 and that is done by checking the isData
	if (runType == "mc") isData = false;
	else isData = true;

	cout << "main(): Variables Retrieved!" << endl;

	TFile* f_out = TFile::Open(outRoot.c_str(),"RECREATE");
	f_out->cd();

//	int NPAR = 0;
	int J = globalJ;


//	LAMBDA
//	if (J == 0) NPAR = 5;
//	if (J == 1) NPAR = 13;
//	if (J == 2) NPAR = 22;


//	NOLAMBDA
	if (J == 0) NPAR = 3;
	if (J == 1) NPAR = 9;
	if (J == 2) NPAR = 18;

	if (complexT) NPAR = 2*(NPAR - 2) + 2 - 1;
	else cout << "main(): Real Params Considered" << endl;


	cout << "main(): Number of parameters = " << NPAR << endl;

	Int_t ierflg = 0;
	TMinuit *gMinuit = new TMinuit(NPAR);  //initialize TMinuit with a maximum of NPAR params

	gMinuit->SetFCN(myFcn);

	cout << "main(): gMinuit Initilized!" << endl;

	char varName[100];

	vector<double> initParams;

	if (file)
		{
		cout << "main(): Getting initial parameters from : " << input << endl; 
		initParams = readParams(input);
		}

//	gMinuit->SetMaxIterations(5);


	map<int, double> paramToFix;

	paramToFix[0] = 1;
	paramToFix[1] = 1;
	paramToFix[2] = 1;
	paramToFix[3] = 1;
	paramToFix[4] = 1;
//	paramToFix[5] = 1;
	paramToFix[6] = 1;
	paramToFix[7] = 0.658921;
	paramToFix[8] = 1.846757;
//	paramToFix[9] = 1.327196;
	paramToFix[10] = 0.019637;
	paramToFix[11] = 1.327196;
	paramToFix[12] = 2.020541;
	paramToFix[13] = 3.483523;
	paramToFix[14] = 0.692712;
	paramToFix[15] = 0.410562;
	paramToFix[16] = -0.007800;
	paramToFix[17] = -0.008032;


//	paramToFix[0] = -0.357233;
//	paramToFix[1] = -0.41511;
//	paramToFix[2] = 0.108420;
//	paramToFix[3] = 0.131855;
//	paramToFix[4] = -0.216474;
//	paramToFix[5] = -10.763369;
//	paramToFix[6] = 1.76812;
//	paramToFix[7] = 0.658921;
//	paramToFix[8] = 1.846757;
//	paramToFix[9] = 1.327196;
//	paramToFix[10] = 0.019637;
//	paramToFix[11] = 1.327196;
//	paramToFix[12] = 2.020541;
//	paramToFix[13] = 3.483523;
//	paramToFix[14] = 0.692712;
//	paramToFix[15] = 0.410562;
//	paramToFix[16] = -0.007800;
//	paramToFix[17] = -0.008032;
//	paramToFix[18] = -0.008032;
//	paramToFix[19] = -0.008032;
//	paramToFix[20] = -0.008032;
//	paramToFix[21] = -0.008032;
//	paramToFix[22] = -0.008032;
//	paramToFix[23] = -0.008032;
//	paramToFix[24] = -0.008032;
//	paramToFix[25] = -0.008032;
//	paramToFix[26] = -0.008032;
//	paramToFix[27] = -0.008032;
//	paramToFix[28] = -0.008032;
//	paramToFix[29] = -0.008032;
//	paramToFix[30] = -0.008032;
//	paramToFix[31] = -0.008032;
//	paramToFix[32] = -0.008032;


	cout << "Setting gMinuit Initial Parameters!" << endl;

	double parMin = 0; // I think 0 is no limits
	double parMax = 0;
	double parStep = 0.1; // 0.1 is what I initially had

	for (int i = 0; i < NPAR; i++)
		{
		sprintf(varName, "X%d", i);
		if (file)
			{
			if (paramToFix.find(i) != paramToFix.end())	gMinuit->mnparm(i, varName, initParams[2*i], parStep, parMin, parMax, ierflg);
			else						gMinuit->mnparm(i, varName, initParams[2*i], parStep, parMin, parMax, ierflg);
//			else gMinuit->mnparm(i, varName, startValue, 0.1, 0, 0, ierflg);
			}
		else
			{
			if (paramToFix.find(i) != paramToFix.end()) gMinuit->mnparm(i, varName, paramToFix[i], parStep, parMin, parMax, ierflg);
			else gMinuit->mnparm(i, varName, startValue, parStep, parMin, parMax, ierflg);
			}
		}

	for (map<int, double>::iterator mit = paramToFix.begin(); mit != paramToFix.end(); mit++)
		{
		if (file)
			{
			cout << "Fixing Parameter #" << mit->first << " to " << initParams[2*mit->first] << " !" << endl;
			gMinuit->FixParameter(mit->first);
			}
		else
			{
			cout << "Fixing Parameter #" << mit->first << " to " << mit->second << " !" << endl;
			gMinuit->FixParameter(mit->first);
			}
		}

	cout << "main(): gMinuit Parameters Set!" << endl;

	if (ierflg)
		{
		Printf(" UNABLE TO DEFINE PARAMETER NO.");
		return ierflg;
		}
//	==============================================================================
/*
//	FOR TESTING OR FOR SINGLE PARAMETER MEASUREMENT OUTPUT // IRAKLI
	for (int i = 0; i < NPAR; i++)
//		if (i != 11) gMinuit->FixParameter(i);
		gMinuit->FixParameter(i);

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


	FILE * singleOutFile;
	singleOutFile = fopen("/eos/uscms/store/user/iraklich/singleOut.html", "a");

	fprintf(singleOutFile, "<tr>\n");

	fprintf(singleOutFile, "\t<td>%s</td>\n", fileBase.c_str());

	for (int i = 0; i < NPAR; i++)
		{
		gMinuit->Release(i);

		cout << "main() : Parameter " << i << " Released!" << endl;


//		gMinuit->mncomd("migrad",ierflg);
		gMinuit->Migrad();
	
		double singleCurrentValue = 0;
		double singleCurrentError = 0;

		gMinuit->GetParameter(i, singleCurrentValue, singleCurrentError);

		fprintf(singleOutFile, "\t<td>%f</td>\n\t<td>%f</td>\n", singleCurrentValue, singleCurrentError);
		gMinuit->mnparm(i, varName, paramToFix[i], parStep, parMin, parMax, ierflg);

		gMinuit->FixParameter(i);
		cout << "main() : Parameter " << i << " Fixed!" << endl;
		}

//	for (int i = 0; i < NPAR; i++)
//		gMinuit->Release(i);

	fprintf(singleOutFile, "</tr>\t");

	return 0;
*/
//	==============================================================================


//	gMinuit->mncomd("migrad",ierflg);
	gMinuit->Migrad();
//	gMinuit->mnimpr(); // does some kind of improve but for me it just returned to the same value

//	gMinuit->mnexcm("CALL FCN", &p1 ,0,ierflg);


	double currentValue = 0;
	double currentError = 0;

	double finalParams[NPAR];
	double finalParamErrors[NPAR];
	double tempX[NPAR];
	double tempXE[NPAR];

	for (int i = 0; i < NPAR; i++)
		{
		tempX[i] = i+1;
		tempXE[i] = 0;
		gMinuit->GetParameter(i, currentValue, currentError);
		finalParams[i] = currentValue;
		finalParamErrors[i] = currentError;
		fprintf(outFile, "%f\t%f\n", currentValue, currentError);
		}

	TGraphErrors * gr_outParams = new TGraphErrors(NPAR, tempX, finalParams, tempXE, finalParamErrors);
	gr_outParams->SetTitle("outParams");
	gr_outParams->Draw("a");
	f_out->cd();
	gr_outParams->Write();

	fclose(outFile);

//	myFunc(finalParams); // for f(Omega) fit and then consequesnt RECO
//	myFunction(finalParams, fileBase); // for f(Omega) / Wp direct RECO fit

//	Fixing params befor requesting the contour
//	for (int i = 0; i < NPAR; i++)
//		if (i != 5 || i != 8)
//			{
//			cout << "Fixing " << i << "th patameter to" << finalParams[i] << endl;
//			gMinuit->FixParameter(finalParams[i]);
//			}
//
//	c->cd();

	if ((NPAR - paramToFix.size()) == 2)
		{
		string amplitudesRe[] = {
//				T^{J}_{lambdaqq}_{lambdaz}_{lambdagamma} as used for the thesis
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

		string amplitudesZ[] = {
//				T^{J}_{lambdaqq}_{lambdaz}_{lambdagamma} as used for the thesis
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

		vector<int> freePars;

		for (int i = 0; i < NPAR; i++)
			if (paramToFix.find(i) == paramToFix.end()) freePars.push_back(i);

		cout << "CONTOUR CALCULATION FOR " << freePars[0] << " and " << freePars[1] << endl;

		TMultiGraph * mgr = new TMultiGraph("mgr", "mgr");

		gMinuit->SetErrorDef(16);
		TGraph * gr1 = (TGraph*) gMinuit->Contour(50, freePars[0], freePars[1]);
		gr1->SetFillColor(3);
		gr1->SetLineWidth(2);
//	   	gr1->Draw("alf");

		double * tempGraphX1 = gr1->GetX();
		double * tempGraphY1 = gr1->GetY();

		for (int mi = 0; mi < NPAR; mi++)
			{
			cout << tempGraphX1[mi] << endl;
			cout << tempGraphY1[mi] << endl;
			cout << " - - - - - - " << endl;
			}

		gMinuit->SetErrorDef(4);
		TGraph * gr2 = (TGraph*) gMinuit->Contour(50, freePars[0], freePars[1]);
		gr2->SetFillColor(7);
		gr2->SetLineWidth(2);
//		gr2->Draw("SAMElf");

		gMinuit->SetErrorDef(1);
		TGraph * gr3 = (TGraph*) gMinuit->Contour(50, freePars[0], freePars[1]);
		gr3->SetFillColor(9);
		gr3->SetLineWidth(2);

		double fakeX[1];
		double fakeY[1];
		fakeX[0] =  initParams[2*freePars[0]];
		fakeY[0] =  initParams[2*freePars[1]];

//		gMinuit->SetErrorDef(0);
		TGraph * grP = new TGraph (1, fakeX, fakeY);
		grP->SetMarkerStyle(30);
		grP->SetMarkerSize(2);
		grP->SetMarkerColor(2);
//		gr->SetLineColor(2);
//		gr->SetLineWidth(3);
//	   	gr->Draw("SAMEl");

		mgr->Add(gr1, "lCf");
		mgr->Add(gr2, "lCf");
//		mgr->Add(gr3, "lCf");
		mgr->Add(grP, "p");
//		mgr->Add(gr, "l");
		mgr->Draw("a");

		if (complexT)
			{
			mgr->GetXaxis()->SetTitle(amplitudesZ[freePars[0]].c_str());
			mgr->GetYaxis()->SetTitle(amplitudesZ[freePars[1]].c_str());
			}
		else
			{
			mgr->GetXaxis()->SetTitle(amplitudesRe[freePars[0]].c_str());
			mgr->GetYaxis()->SetTitle(amplitudesRe[freePars[1]].c_str());
			}
		f_out->cd();
		mgr->Write();
		}
//	h1->Draw();

	TMultiGraph * minMG = new TMultiGraph();

	TGraph * myFinalAccGraph  = new TGraph(minIterCount, X, myFinalAcc);
	TGraph * gr_min = new TGraph(minIterCount, X, Y);
//	gr_min->SetName("negLogL");
//	gr_min->Draw("a");
	f_out->cd();
//	gr_min->Write();

	myFinalAccGraph->SetLineColor(2);
	myFinalAccGraph->SetMarkerColor(2);

	TGraph * myFinalLhoodGraph  = new TGraph(minIterCount, X, myFinalLhood);
	myFinalLhoodGraph->SetLineColor(3);
	myFinalLhoodGraph->SetMarkerColor(3);


	minMG->Add(myFinalAccGraph, "pl");
	minMG->Add(myFinalLhoodGraph, "pl");
	minMG->Add(gr_min, "pl");
	minMG->SetName("negLogL");
	minMG->Draw("a");
	minMG->Write();

	cout << " --------- Minos Exit Status : " << gMinuit->GetStatus() << " -------- " << endl;

//	BUILDING GRAPH OF "AMPITUDES"
	TMultiGraph * myAmplitudesMGraph = new TMultiGraph();

	cout << " = = = = = = = = = = NUMBER OF FINAL PSEUDO-AMPLITUDES : " << myAmplitudes.size() << endl;

	int numberOfMyAmplitudes = 0;

	for (map<int, vector<double> >::iterator mit = myAmplitudes.begin(); mit != myAmplitudes.end(); mit++)
		{
//		if (numberOfMyAmplitudes > 20) continue;
		double myAmplitudesY[mit->second.size()];
		int myAmplitudeCounter = 0;

		for (vector<double>::iterator vit = mit->second.begin(); vit != mit->second.end(); vit++)
			{
			myAmplitudesY[myAmplitudeCounter] = *vit;
//			cout << " - - - - - - - - " << myAmplitudeCounter << " : " << *vit << endl;
			myAmplitudeCounter++;
			}
//		cout << " - - - - - - - - " << minIterCount << " = " << mit->second.size() << endl;
		TGraph * myAmplitudesGraph = new TGraph(minIterCount, X, myAmplitudesY);
		myAmplitudesGraph->SetLineColor(mit->first+1);
		myAmplitudesGraph->SetMarkerColor(mit->first+1);
		myAmplitudesMGraph->Add(myAmplitudesGraph, "pl");
		numberOfMyAmplitudes++;
		}
	myAmplitudesMGraph->SetName("ampls");
	myAmplitudesMGraph->Draw("a");
	myAmplitudesMGraph->Write();

//	BUILDING GRAPH OF PARAMETERS
	TMultiGraph * myParametersMGraph = new TMultiGraph();

	cout << " = = = = = = = = = = NUMBER OF PARAMETERS : " << myParameterMap.size() << endl;

	for (map<int, vector<double> >::iterator mit = myParameterMap.begin(); mit != myParameterMap.end(); mit++)
		{
		double myParametersY[mit->second.size()];
		int myParameterCounter = 0;

		for (vector<double>::iterator vit = mit->second.begin(); vit != mit->second.end(); vit++)
			{
			myParametersY[myParameterCounter] = *vit;
//			cout << " - - - - - - - - " << myAmplitudeCounter << " : " << *vit << endl;
			myParameterCounter++;
			}
//		cout << " - - - - - - - - " << minIterCount << " = " << mit->second.size() << endl;
		TGraph * myParametersGraph = new TGraph(minIterCount, X, myParametersY);
		myParametersGraph->SetLineColor(mit->first+1);
		myParametersGraph->SetMarkerColor(mit->first+1);
		myParametersMGraph->Add(myParametersGraph, "pl");
		}
	myParametersMGraph->SetName("parameters");
	myParametersMGraph->Draw("a");
	myParametersMGraph->Write();

//	FINAL CALCULATION OF THE RESULTANT FIT WITH THE FINAL PARAMETERS
	recoResults(varVecISR, f_out, finalParams);

	f_out->Close();
	delete gMinuit;
	return 0;
	}
//==============================================================================

void myFcn(Int_t &npar, Double_t *gin, Double_t &f, Double_t *x, Int_t iflag)
	{
//	cout << "minimizer called" << endl;
	double lhood = 0;
	f = 0;

	double acc = 0;
	accOnce = true;
	double nEvents = 0;

	pair<double, double> tempLhood;
	double vars[38];


	for (int i = 0; i < NPAR; i++)
		{
		myParameterMap[i].push_back(x[i]);
		}

	for (vector<vector<double> >::iterator it = varVec.begin(); it != varVec.end(); it++)
		{
		vars[0] = it->at(0);
		vars[1] = it->at(1);
		vars[2] = it->at(2);
		vars[3] = it->at(3);
		vars[4] = it->at(4);
		vars[5] = it->at(5);

		tempLhood = likelihood(vars, x);

		if (debug) cout << "W(" << vars[0] << ", " << vars[1] << ", " << vars[2] << ", " << vars[3] << ", " << vars[4] << ", " << vars[5] << ") = " << tempLhood.first << endl;
		if (debug) cout << "lhood = " << lhood << " + log(" << tempLhood.first << ") = " << lhood << " + " << log(tempLhood.first) << " = ";
		lhood += log(tempLhood.first);
		if (debug) cout << lhood << endl;


		if (accOnce)
			{
			acc = tempLhood.second;
			accOnce = false;
			}
		nEvents++;
		}
	
	if (method == "ML")
		{
//		Maximum Likelihood
		f = nEvents*log(acc) - lhood;
		
		if (debug) cout << "myFcn() : " << minIterCount << " : minimizing f = " << nEvents << " * log(" << acc << ") - " << lhood << endl;
		if (debug) cout << "myFcn() : " << minIterCount << " : minimizing f = " << nEvents << " * " << log(acc) << " - " << lhood  << " = " << f << endl;
		myFinalAcc[minIterCount] = nEvents*log(acc);
		myFinalLhood[minIterCount] = lhood;
		}
	else
		{
//		cout << "EML with lumi = " << lumi << endl;
//		Extended Maximum Likelihood
		f = lumi*acc - lhood;

		myFinalAcc[minIterCount] = lumi*acc;
		myFinalLhood[minIterCount] = lhood;

		if (debug) cout << "myFcn() : " << minIterCount << " : minimizing f = " << lumi << " * " << acc << " - " << lhood << " = " << f << endl;
		}

	X[minIterCount] = minIterCount;
	Y[minIterCount] = f;
	minIterCount++;

//	h1->Fill(f);
//	myFile->Close();
	}
//==============================================================================
