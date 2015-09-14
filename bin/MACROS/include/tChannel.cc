///////////////////////////////////////////////
// Process : qqbar->Zgamma->llgamma          //
// Function to Correct for t-channel effects //
// Authot : Irakli Chakaberia                //
// Date Written : 16 Jun 2011                //
// Date Updated : 15 Apr 2013                //
///////////////////////////////////////////////

#include <TFile.h>
#include <TTree.h>
#include <TH1.h>
#include <TCanvas.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include "tChannel.h"

using namespace std;

double tChannel(double cosThetaZ, double MZ, double MZG)
	{
//	FOR TESTING // IRAKLI
	double NFactor = 1;
//	double NFactor = 0.0001;

//	cout << "cos(thetaZ) = " << cosThetaZ << "; M(Z) = " << MZ << "; M(Zgamma) = " << MZG << endl;

//	I think thi is more correct then the lower one, I don't know why I had it otherwise, while still  keeping this version of 'first' and 'second' but no D
//	double first	= sqrt(1/(MZG*MZG-(MZG*MZG-MZ*MZ)*cosThetaZ));
//	double second	= sqrt(1/(MZG*MZG+(MZG*MZG-MZ*MZ)*cosThetaZ));
//	double D = MZG*MZG*(first+second)*(first+second)/4;

	double first	= 1/(MZG*MZG-(MZG*MZG-MZ*MZ)*cosThetaZ);
	double second	= 1/(MZG*MZG+(MZG*MZG-MZ*MZ)*cosThetaZ);
//	double D = MZG*MZG*MZG*MZG*(first+second)*(first+second)/4;
//	FOR TESTING // IRAKLI
	double D = NFactor*MZG*MZG*MZG*MZG*(first+second)*(first+second)/4;

	return D; 
	}
