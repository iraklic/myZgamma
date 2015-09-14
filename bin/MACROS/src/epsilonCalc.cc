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
#include "TH1.h"
#include "../include/likelihoodFunc.h"

#include <iostream>
#include <map>
#include "../include/plotter.h"
#include "../include/readParams.h"
// global variables for not doing same routine many times in functions outside this cc file
#include "../include/extern.h"

//#ifdef __SC__
//long G__globalvarpointer; // To make the Symantec linker happy
//#endif

using namespace std;

double lumi = 0;

string method = "";
int events = 0;


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
	string fileName	= setupMap["inpFile"];
	finalFileName	= setupMap["accFile"];
	string input	= setupMap["inputParamsF"];
	double startValue = atoi(setupMap["startValue"].c_str());
	complexT	= (bool) atoi(setupMap["complex"].c_str());
	int methodValue	= atoi(setupMap["method"].c_str());
	lumi		= atoi(setupMap["lumi"].c_str());

	events		= atoi(setupMap["events"].c_str());

	if (methodValue == 0) {withTCORR = true;	method = "EML";}
	if (methodValue == 1) {withTCORR = false;	method = "EML";}
	if (methodValue == 2) {withTCORR = true;	method = "ML";}
	if (methodValue == 3) {withTCORR = false;	method = "ML";}

	if (method == "EML") cout << " - USING EXTENDED MAXIMUM LIKELIHOOD METHOD - " << endl;
	if (method == "ML") cout << " - USING MAXIMUM LIKELIHOOD METHOD - " << endl;

	doIt = false;

	if (runType != "data" && runType != "mc" && runType != "mcReco")
		{
		cout << "please enter right runType <data> or <mc>" << endl;
		return 0; 
		}

	cout << "Working with " << fileName << " and type [" << runType << "]" << endl;
	cout << "Using " << finalFileName << " as acceptance file" << endl;

//	CONSTRUCTING THE OUTPUT FILENAME FROM INPUT PARAMETERS ===============
	string fileBase = "outParams_";
	string outParams = "";

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
		if (fileName.find("2jets") != string::npos) fileBase.append("_NLO");
		else fileBase.append("_LO");
		}
	else if (fileName.find("BS") != string::npos) fileBase.append("_BS");
	else fileBase.append("_Data");

	if (fileName.find("ee") != string::npos || fileName.find("Ele") != string::npos) fileBase.append("_ee");
	else fileBase.append("_mm");

	if (fileName.find("NSM") != string::npos) fileBase.append("_NSM");
	else if (fileName.find("SM") != string::npos) fileBase.append("_SM");
	if (runType == "mcReco") fileBase.append("_GEN");

	outParams = fileBase + ".txt";
//	======================================================================

//	if running over MC truth then epsilons should be set 1 and that is done by checking the isData
	if (runType == "mc") isData = false;
	else isData = true;

	int NPAR = 0;
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
	else cout << "Real Params Considered" << endl;

	double x[NPAR];
	for (int i = 0; i < NPAR; i++)
		x[i] = 1;

	double vars[6] = {0.1, 0.1, 1, 1, 90, 150};

	likelihood(vars, x);

	return 0;
	}
//==============================================================================

