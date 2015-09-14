//////////////////////////////////////////////
// Process : qqbar->Zgamma->llgamma         //
// Function to fit to angular distribution  //
// Authot : Irakli Chakaberia               //
// Date Written : 16 Feb 2011               //
// Date Updated : 16 Jun 2011               //
//////////////////////////////////////////////

#include <TFile.h>
#include <TTree.h>
#include <TMath.h>
#include <TH1.h>
#include <TCanvas.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include "readParams.h"
#include "tChannel.h"
#include "likelihoodFunc.h"
#include "extern.h"

using namespace std;

// omega function for likelihood
double omegaFunc(Omega O, outerSum oSum)
	{
	if (doIt) cout << oSum.innerSumi.J << " - " << oSum.innerSumi.lambdaqq << " - " <<  oSum.innerSumi.lambdaz << " - " << oSum.lambdagamma << " - " << O.thetaZ << endl;
	double dzi = wignerd(oSum.innerSumi.J, oSum.innerSumi.lambdaqq, oSum.lambdagamma-oSum.innerSumi.lambdaz, O.thetaZ); // lambdagamma-lambdaz
	double dzj = wignerd(oSum.innerSumj.J, oSum.innerSumj.lambdaqq, oSum.lambdagamma-oSum.innerSumj.lambdaz, O.thetaZ);

//	if (doIt) cout << dzi << " : " << dzj << endl;

	double dli = wignerd(1, oSum.innerSumi.lambdaz, oSum.lambdall, O.thetaL);
	double dlj = wignerd(1, oSum.innerSumj.lambdaz, oSum.lambdall, O.thetaL);

	double jFactor = 1;

	jFactor = (2*oSum.innerSumi.J + 1)*(2*oSum.innerSumj.J + 1);

	double cosine = 1;

	if (!oSum.delta) cosine = cos((oSum.innerSumi.alfal()*O.phiL+oSum.innerSumi.alfaz()*O.phiZ) - (oSum.innerSumj.alfal()*O.phiL+oSum.innerSumj.alfaz()*O.phiZ));

	if (debug && doIt)
		{
		cout << "dzi[" << oSum.innerSumi.J << ", " << oSum.innerSumi.lambdaqq << ", " <<  oSum.innerSumi.lambdaz-oSum.lambdagamma << ", "  <<  O.thetaZ << "] = " << dzi << endl;;
		cout << "dzj[" << oSum.innerSumj.J << ", " << oSum.innerSumj.lambdaqq << ", " <<  oSum.innerSumj.lambdaz-oSum.lambdagamma << ", "  <<  O.thetaZ << "] = " << dzj << endl;;
		cout << "dli[1, " << oSum.innerSumi.lambdaz << ", " << oSum.lambdall << ", " << O.thetaL << "] = " << dli<< endl;
		cout << "dlj[1, " << oSum.innerSumj.lambdaz << ", " << oSum.lambdall << ", " << O.thetaL << "] = " << dlj<< endl;
		cout << "cosisne =" << cosine << endl;

		cout << "cosine = cos(" << (oSum.innerSumi.alfal()*O.phiL+oSum.innerSumi.alfaz()*O.phiZ) << " - " << (oSum.innerSumj.alfal()*O.phiL+oSum.innerSumj.alfaz()*O.phiZ) << ") = " << cosine << endl;
		if (cosine == 1)
			{
			cout << " similar ij " << endl;
			cout	<< oSum.innerSumi.J  << " - " << oSum.innerSumi.lambdaz << " - " << oSum.innerSumi.lambdaqq << "\n"
				<< oSum.innerSumj.J  << " - " << oSum.innerSumj.lambdaz << " - " << oSum.innerSumj.lambdaqq
				<< endl;

			cout << "cosine = cos(" << (oSum.innerSumi.alfal()*O.phiL+oSum.innerSumi.alfaz()*O.phiZ) << " - " << (oSum.innerSumj.alfal()*O.phiL+oSum.innerSumj.alfaz()*O.phiZ) << ") = " << cosine << endl;
			}

		cout << oSum.delta << " - " << cosine << endl;
		}

	if (doIt)
		{
		FILE * myParamFile;
		myParamFile = fopen("omegaFile.txt", "a");
		if (oSum.delta)
			{
			fprintf(myParamFile, "\\omega_{i} = 2[(2*%d + 1)(2*%d+1)d^{%d}_{%d,%d}*d^{%d}_{%d,%d}*d^{1}_{%d,%d}*d^{1}_{%d,%d}\n]", oSum.innerSumi.J, oSum.innerSumj.J, oSum.innerSumi.J, oSum.innerSumi.lambdaqq, oSum.innerSumi.lambdaz-oSum.lambdagamma, oSum.innerSumj.J, oSum.innerSumj.lambdaqq, oSum.innerSumj.lambdaz-oSum.lambdagamma, oSum.innerSumi.lambdaz, oSum.lambdall, oSum.innerSumj.lambdaz, oSum.lambdall);
			}
		else
			{
			fprintf(myParamFile, "\\omega_{i} = (2*%d + 1)(2*%d+1)d^{%d}_{%d,%d}*d^{%d}_{%d,%d}*d^{1}_{%d,%d}*d^{1}_{%d,%d}\n", oSum.innerSumi.J, oSum.innerSumj.J, oSum.innerSumi.J, oSum.innerSumi.lambdaqq, oSum.innerSumi.lambdaz-oSum.lambdagamma, oSum.innerSumj.J, oSum.innerSumj.lambdaqq, oSum.innerSumj.lambdaz-oSum.lambdagamma, oSum.innerSumi.lambdaz, oSum.lambdall, oSum.innerSumj.lambdaz, oSum.lambdall);
			}
		fclose(myParamFile);
		}

//	FOR TESTING //IRAKLI
	double omegaNormalizer = 1; // set 1 if don't neet to test this

	if (oSum.delta) return jFactor*dzi*dzj*dli*dlj*omegaNormalizer;
	else return 2*jFactor*dzi*dzj*dli*dlj*cosine*omegaNormalizer;
	}

// Kronecker delta
int kroneckerDelta(int i, int j)
	{
	return (i == j) ? 1 : 0;
	}

// Helper fuction to reduce pairs of d function to orthogonal pairs
bool samePair(pair<int, int> pair1, pair<int, int> pair2)
	{
	if (pair1.first == pair2.first && pair1.second == pair2.second) return true;
	else return false;
	}
int similarPair(pair<int, int> pair1, pair<int, int> pair2)
	{
	if (	(pair1.first == -pair2.second && pair1.second == -pair2.first) ||
		(pair1.first == pair2.first && pair1.second == pair2.second))		return 1;
	if (	(pair1.first == pair2.second && pair1.second == pair2.first) ||
		(pair1.first == -pair2.first && pair1.second == -pair2.second))		return (int) pow(-1, pair1.second-pair1.first);
	return 0;
	}

// wigner d functions
double wignerd(int J, int lambda1, int lambda2, double theta) // for J = 0, 1, 2
	{
	if (fabs(lambda1) > J || fabs(lambda2) > J || J > 2) return -999.999;

	double d;
	pair<int, int> pairIndex; // first element of this pair shows which otrhogonal pair to use and second index shows the sign that goes with the index
	pair<int, int> orthogonalPairs[9]; // all other pair of lamda1 and lambda2 is commutation/commutation with sign change of these

	orthogonalPairs[0] = make_pair(0, 0);
	orthogonalPairs[1] = make_pair(1, 0);	// equal to | (0, -1)	| -(-1, 0)	| -(0, 1)	|
	orthogonalPairs[2] = make_pair(1, -1);	// equal to | (-1, 1)	|		|		|
	orthogonalPairs[3] = make_pair(1, 1);	// equal to | (-1, -1)	|		|		|
	orthogonalPairs[4] = make_pair(2, 0);	// equal to | (0, -2)	| (-2, 2)	| (0,2)		|
	orthogonalPairs[5] = make_pair(2, 1);	// equal to | (-2,-1)	| -(1,2)	| -(-2, -1)	|
	orthogonalPairs[6] = make_pair(2, 2);	// equal to | (-2, -2)	|		|		|
	orthogonalPairs[7] = make_pair(2, -1);	// equal to | (1, -2)	| -(-2, 1)	| -(-1, 2)	|
	orthogonalPairs[8] = make_pair(2, -2);	// equal to | (-2, 2)	|		|		|

	for (int i = 0; i < 9; ++i)
		if (similarPair(make_pair(lambda1, lambda2), orthogonalPairs[i]) != 0)
			{
			pairIndex = make_pair(i, similarPair(make_pair(lambda1, lambda2), orthogonalPairs[i]));
			break;
			}

	if (J == 0) d = 1;
	if (J == 1)
		{
		if	(pairIndex.first == 0)	d = cos(theta);
		else if	(pairIndex.first == 1)	d = -sin(theta/sqrt(2));
		else if	(pairIndex.first == 2)	d = (1 - cos(theta))/2;
		else 				d = (1 + cos(theta))/2;
		}
	if (J == 2)
		{
		if	(pairIndex.first == 0)	d = (3*pow(cos(theta), 2) - 1)/2;
		else if	(pairIndex.first == 1)	d = -sqrt(1.5)*cos(theta)*sin(theta);
		else if	(pairIndex.first == 2)	d = ((1 - cos(theta))/2)*(2*cos(theta) + 1);
		else if	(pairIndex.first == 3)	d = ((1 + cos(theta))/2)*(2*cos(theta) - 1);
		else if	(pairIndex.first == 4)	d = sqrt(6)*pow(sin(theta), 2)/4;
		else if	(pairIndex.first == 5)	d = -((1 + cos(theta))/2)*sin(theta);
		else if	(pairIndex.first == 6)	d = pow((1 + cos(theta)/2), 2);
		else if	(pairIndex.first == 7)	d = -((1 - cos(theta))/2)*sin(theta);
		else				d = pow((1 - cos(theta)/2), 2);
		}
//	printf("d[%d,%d,%d](cos(%f)) = %f [A = %d; index = %d]\n", J, lambda1, lambda2, theta, pairIndex.second*d, pairIndex.second, pairIndex.first);

	return pairIndex.second*d;
	}

// calculation of result of angular distribution
pair<double, double> likelihood(double * x, double * par)
	{
//	variables
	double thetaL = acos(x[0]);
	double thetaZ = acos(x[1]);

	double phiL = x[2];
	double phiZ = x[3];

	double ZMass = x[4];
	double ZGMass = x[5];

	Omega omegaVar;
	omegaVar.thetaL = thetaL;
	omegaVar.thetaZ = thetaZ;
	omegaVar.phiL = phiL;
	omegaVar.phiZ = phiZ;

	if (debug && doIt)
		{
		cout << "cosThetaL = " << cos(omegaVar.thetaL) << "\ncosThetaZ = " << cos(omegaVar.thetaZ) << "\nphiL = " << omegaVar.phiL << "\nphiZ = " << omegaVar.phiZ << "\nZMass = " << ZMass << "\nZGMass = " << ZGMass << endl;
		for (int i = 0; i < NPAR; i++)
			cout << "parameter # " << i << " = "  << par[i] << endl;
		}

	vector<innerSum> inSum;
	vector<outerSum> outSum;

//	parameter counter
	int parTCounter = 0;
	int parACounter = 0;
	int parCounter = 0;

//	parameters
	parT Tpar, TparRe, TparIm;
	parA Apar, AparRe, AparIm;
	map<parT, double, parTsort> TmapRe, TmapIm;
//	map<parA, double, parAsort> AmapRe, AmapIm;

	map<double, double> AmapNoLambdaZ;

//	summation parameters
	int lambdagamma, J, lambdaz, lambdall, lambdaqq;
	double acceptance = 0;
	double sum = 0;

	double TRe, TIm, ARe, AIm;
//	LOOPS AFTER SQUARING
	for (lambdagamma = -1; lambdagamma <= 1; lambdagamma+=2)
		for (lambdall = -1; lambdall <= 1; lambdall+=2)
			{
//			LOOPS BEFORE SQUARING
			for (J = 0; J <= globalJ; J++)
				for (lambdaqq = -1; lambdaqq <= 1; lambdaqq++)
					for (lambdaz = -1; lambdaz <= 1; lambdaz++)
						{
						Tpar.J = J;
						Tpar.lambdaqq = lambdaqq;
						Tpar.lambdaz = lambdaz;
						Tpar.lambdagamma = lambdagamma;

//						Apar.lambdaz = lambdaz;
//						Apar.lambdall = lambdall;

//						int lambdazgamma = (lambdaz - lambdagamma);
						int lambdazgamma = (lambdagamma - lambdaz);
						double dZ = wignerd(J, lambdaqq, lambdazgamma, thetaZ);
						double dl = wignerd(1, lambdaz, lambdall, thetaL);
						if (dZ == -999.999 || dl == -999.999) continue;
						if (TmapRe.find(Tpar) == TmapRe.end())
							{
							TRe = par[parCounter];
							parCounter++;
							if (complexT && (parCounter != 1))
								{
								TIm = par[parCounter];
								parCounter++;
								}
							else TIm = 0;
							TmapRe[Tpar] = TRe;
							TmapIm[Tpar] = TIm;
							if (debug) cout << "T = " << TRe << " + i " << TIm << endl;
							}
/*
//						Uncommend Amap part if you want to switch back to ussing AlambdaZlambdal
						if (AmapRe.find(Apar) == AmapRe.end())
							{
							ARe = par[parCounter];
//							parCounter++;
//							AIm = par[parCounter];
							AIm = 0;
							parCounter++;
//							Amap[Apar] = parCounter;
							AmapRe[Apar] = ARe;
							AmapIm[Apar] = AIm;
//							cout << "A = " << ARe << " + i" << AIm << endl;
							}
*/
						if (debug) cout << parCounter << endl;
						innerSum * tempInSum = new innerSum(J, lambdaqq, lambdaz);
						inSum.push_back(*tempInSum);
//						cout << inSum[inSum.size()-1].J << " : " << inSum[inSum.size()-1].alfaz() << endl;
						delete tempInSum;
//						cout << inSum[inSum.size()-1].J << " : " << inSum[inSum.size()-1].alfaz() << endl;
						}

			if (AmapNoLambdaZ.find(lambdall) == AmapNoLambdaZ.end())
				{
				ARe = par[parCounter];
				parCounter++;
				if (debug) cout << "A = " << ARe << endl;
				if (debug) cout << parCounter << endl;
				AmapNoLambdaZ[lambdall] = ARe;
//				AmapNoLambdaZ[lambdall] = ARe / 1000; // FOR TESTING // IRAKLI
				}

/*
			if (AmapNoLambdaZ.find(lambdall) == AmapNoLambdaZ.end())
				{
				parT tempTpar;
				tempTpar.J = 1;
				tempTpar.lambdaqq = -1;
				tempTpar.lambdaz = -1;
				tempTpar.lambdagamma = -1;

//				fixing first parameter in this expended summation by calculating A from 1/T
				if (lambdall == -1) // -1 is the first in loop
					{
					ARe = sqrt(1 / (TmapRe[tempTpar]*TmapRe[tempTpar] + TmapIm[tempTpar]*TmapIm[tempTpar]));
					AmapNoLambdaZ[lambdall] = ARe;
					}
				else
					{
					ARe = par[parCounter];
					parCounter++;
					AmapNoLambdaZ[lambdall] = ARe;
					}
				}
*/

//			Below I put all possible couples (all different, that's why I need kDelta) of the inner summation into the container
			for (vector<innerSum>::iterator initi = inSum.begin(); initi != inSum.end(); initi++)
				for (vector<innerSum>::iterator initj = initi; initj != inSum.end(); initj++)
					{
					bool kDelta;
					if (initi == initj) kDelta = true;
					else kDelta = false;
					outerSum * tempOutSum = new outerSum(lambdall, lambdagamma, *initi, *initj, kDelta);
					outSum.push_back(*tempOutSum);
//					cout << outSum[outSum.size()-1].lambdall <<  " | " << outSum[outSum.size()-1].innerSumi.alfaz() << endl;
					delete tempOutSum;
//					cout << outSum[outSum.size()-1].lambdall <<  " | " << outSum[outSum.size()-1].innerSumi.alfaz() << endl;
					}
			inSum.clear();
			}// END INNERSUM
		// END OUTERSUM

//	==============================================================
//	variables for epsilon calculation
//	==============================================================
//	these variables should be outside the onceDone scope, the others just bind them to branches and ocne defined no binding needed
//	Declaration of leaf types
	Double_t        TmccosThetaL;
	Double_t        TmccosThetaZ;
	Double_t        TmcphiL;
	Double_t        TmcphiZ;
	Double_t        Tmcweight;
	Double_t        TmcZMass;
	Double_t        TmcZGMass;

	Double_t        TcosThetaL;
	Double_t        TcosThetaZ;
	Double_t        TphiL;
	Double_t        TphiZ;
	Double_t        Tweight;
	Double_t        TZMass;
	Double_t        TZGMass;

	TFile * tfile = NULL;
	TTree * tree = NULL;
	TTree * mctree = NULL;

	Long64_t nentries = 0;
	Long64_t mcnentries = 0;

	if (!onceDone && isData)
		{
//		FILE FOR ACCEPTANCES
		cout << "Openning file " << finalFileName << " for epsilon calculations" << endl;
		tfile = new TFile(finalFileName.c_str(), "READ");


//		cout << "FILE OPENED" << endl;
//		I SHOULD BE CONSISTENT IN USING THE VARIABLES FOR EPSILONS OTHERWISE IT WILL BE MESSED UP I THINK SO I AM COMMENTING OUT TWO LINES BELOW
//		if (runType == "mcReco")	tree	= (TTree*) tfile->Get("mcCutangles");
//		else				tree	= (TTree*) tfile->Get("angles");
		tree	= (TTree*) tfile->Get("angles");
		mctree	= (TTree*) tfile->Get("mcangles");

//		cout << "TREES EXTRACTED" << endl;

		nentries = tree->GetEntries();
		mcnentries = mctree->GetEntries();

//		List of branches
		TBranch        *b_cosThetaL;   //!
		TBranch        *b_cosThetaZ;   //!
		TBranch        *b_phiL;   //!
		TBranch        *b_phiZ;   //!
		TBranch        *b_weight;   //!
		TBranch        *b_ZMass;   //!
		TBranch        *b_ZGMass;   //!

		TBranch        *b_mc_cosThetaL;   //!
		TBranch        *b_mc_cosThetaZ;   //!
		TBranch        *b_mc_phiL;   //!
		TBranch        *b_mc_phiZ;   //!
		TBranch        *b_mc_weight;   //!
		TBranch        *b_mc_ZMass;   //!
		TBranch        *b_mc_ZGMass;   //!

//		cout << "VARIABLES INITIALIZED" << endl;

//		fetching branches
		b_cosThetaL	= tree->GetBranch("cosThetaL");
		b_cosThetaZ	= tree->GetBranch("cosThetaZ");
		b_phiZ		= tree->GetBranch("phiZ");
		b_phiL		= tree->GetBranch("phiL");
		b_weight	= tree->GetBranch("weights");
		b_ZMass		= tree->GetBranch("ZMass");
		b_ZGMass	= tree->GetBranch("ZGMass");

		b_mc_cosThetaL	= mctree->GetBranch("cosThetaL");
		b_mc_cosThetaZ	= mctree->GetBranch("cosThetaZ");
		b_mc_phiZ	= mctree->GetBranch("phiZ");
		b_mc_phiL	= mctree->GetBranch("phiL");
		b_mc_weight	= mctree->GetBranch("weights");
		b_mc_ZMass	= mctree->GetBranch("ZMass");
		b_mc_ZGMass	= mctree->GetBranch("ZGMass");

//		cout << "BRANCHED FETCHED" << endl;

//		linking branch to variable
		b_cosThetaL->SetAddress(&TcosThetaL);
		b_cosThetaZ->SetAddress(&TcosThetaZ);
		b_phiL->SetAddress(&TphiL);
		b_phiZ->SetAddress(&TphiZ);
		b_weight->SetAddress(&Tweight);
		b_ZMass->SetAddress(&TZMass);
		b_ZGMass->SetAddress(&TZGMass);

		b_mc_cosThetaL->SetAddress(&TmccosThetaL);
		b_mc_cosThetaZ->SetAddress(&TmccosThetaZ);
		b_mc_phiL->SetAddress(&TmcphiL);
		b_mc_phiZ->SetAddress(&TmcphiZ);
		b_mc_weight->SetAddress(&Tmcweight);
		b_mc_ZMass->SetAddress(&TmcZMass);
		b_mc_ZGMass->SetAddress(&TmcZGMass);

//		cout << "BRANCHES LINKED TO VARIABLES" << endl;
		}

//	==============================================================
	Omega TomegaVar, TmcomegaVar;

//	TCanvas * c1 = new TCanvas();
//	TH1F * h1 = new TH1F("h1","h1", 200, -0.02, 0.2);
//	==============================================================
//	double tCorrection = tChannel(cos(omegaVar.thetaZ), ZMass, ZGMass); // moved to a better place, cus its usd only once
	int count = 0;
	bool testPrint = true;
//	=================================================================================================
//	====== STARTING THE MAIN LOOP FOR FINAL CALCULATION =============================================
//	=================================================================================================
//	denominator does not depend on the omega function so need to be calculated only once
	double TaccDenom = 0;

	for (vector<outerSum>::iterator outit = outSum.begin(); outit != outSum.end(); outit++)
		{
		if (debug) cout << "Doing Summation for Final Calculation!!!" << endl;
		if (!onceDone && isData)
			{
//			FILE * epsFile;
//			epsFile = fopen("epsilons.txt", "a");
			if (testPrint) 
				{
				cout << "CALCULATING EPSILONS FOR RECO DATA!!!" << endl;
				if (withTCORR) cout << "NOTE : t-Channel Correction Applied!!!" << endl;
				testPrint = false;
				}
//			-------------------------------------------------------------------------
//			Acceptance Calculation
//			-------------------------------------------------------------------------
			double TaccNom = 0;

			for (Long64_t jentry = 0; jentry < nentries; jentry++)
				{
				tree->GetEntry(jentry);

				TomegaVar.thetaZ = acos(TcosThetaZ); 
				TomegaVar.thetaL = acos(TcosThetaL);
				TomegaVar.phiZ = TphiZ;
				TomegaVar.phiL = TphiL;

				double AcctCorrection = tChannel(TcosThetaZ, TZMass, TZGMass);

//				cout << TomegaVar.thetaZ << " - " << TomegaVar.thetaL << " - " << TomegaVar.phiZ << " - " << TomegaVar.phiL << endl;
				double omega_f = 0;
				if (withTCORR) omega_f = omegaFunc(TomegaVar, *outit)*AcctCorrection;
				else  omega_f = omegaFunc(TomegaVar, *outit);

//				cout << omega_f << endl;
				TaccNom += omega_f/Tweight;
				} // loop over MC RECO

			if (TaccDenom == 0)
				for (Long64_t jentry = 0; jentry < mcnentries; jentry++)
					{
					mctree->GetEntry(jentry);

					TmcomegaVar.thetaZ = acos(TmccosThetaZ); 
					TmcomegaVar.thetaL = acos(TmccosThetaL);
					TmcomegaVar.phiZ = TmcphiZ;
					TmcomegaVar.phiL = TmcphiL;
//					cout << TomegaVar.thetaZ << " - " << TomegaVar.thetaL << " - " << TomegaVar.phiZ << " - " << TomegaVar.phiL << endl;
					TaccDenom += 1/Tmcweight;
					} // loop over MC GEN

			epsilon.push_back(16*TMath::Pi()*TMath::Pi()*(TaccNom / TaccDenom));

//			cout << count << " : Acc = " << 16*TMath::Pi()*TMath::Pi() << " * " << TaccNom << " / " << TaccDenom << " = " << epsilon.back() << endl;
//			fprintf (epsFile, "%f\n", epsilon.back());
//			fclose(epsFile);


//			h1->Fill(epsilon.back());
			} // onceDone
//		-------------------------------------------------------------------------

//		UNCOMMENT COMMENTED Apar IF YOU GO BACK TO AlmbdaZlambdaL
//		parA Apari, Aparj;
		parT Tpari, Tparj;
		int aParNoLambdaZ;
		int parityFactori = 1;
		int parityFactorj = 1;

//		Apari.lambdaz = outit->innerSumi.lambdaz;
//		Apari.lambdall = outit->lambdall;

//		Aparj.lambdaz = outit->innerSumj.lambdaz;
//		Aparj.lambdall = outit->lambdall;

		aParNoLambdaZ = outit->lambdall;

		Tpari.J = outit->innerSumi.J;
		Tpari.lambdaz = outit->innerSumi.lambdaz;
		Tpari.lambdaqq = outit->innerSumi.lambdaqq;
		Tpari.lambdagamma = outit->lambdagamma;

		Tparj.J = outit->innerSumj.J;
		Tparj.lambdaz = outit->innerSumj.lambdaz;
		Tparj.lambdaqq = outit->innerSumj.lambdaqq;
		Tparj.lambdagamma = outit->lambdagamma;

//		This is to account for parity T = -T
//		if the parameter (Tpari) found in the map has different helicity indices that means that this parameter is the symmetric one
//		and need a right parity sign in front of it
		if (	Tpari.lambdaz		!= (TmapRe.find(Tpari)->first).lambdaz		||
			Tpari.lambdagamma	!= (TmapRe.find(Tpari)->first).lambdagamma	||
			Tpari.lambdaqq		!= (TmapRe.find(Tpari)->first).lambdaqq) parityFactori = -1;

		if (	Tparj.lambdaz		!= (TmapRe.find(Tparj)->first).lambdaz		||
			Tparj.lambdagamma	!= (TmapRe.find(Tparj)->first).lambdagamma	||
			Tparj.lambdaqq		!= (TmapRe.find(Tparj)->first).lambdaqq) parityFactorj = -1;

		if (AmapNoLambdaZ.find(aParNoLambdaZ) == AmapNoLambdaZ.end() ||
			TmapRe.find(Tpari) == TmapRe.end() || TmapIm.find(Tpari) == TmapIm.end() ||
			TmapRe.find(Tparj) == TmapRe.end() || TmapIm.find(Tparj) == TmapIm.end())
				cout << "oh Mammaaaaaaa something terrible happened with PARAMETERS!!!" << endl;

		double AparNoLambdaZ = AmapNoLambdaZ.find(aParNoLambdaZ)->second;

//		double ReA_i = AmapRe.find(Apari)->second;
//		double ImA_i = AmapIm.find(Apari)->second;
		double ReT_i = parityFactori*TmapRe.find(Tpari)->second;
		double ImT_i = parityFactori*TmapIm.find(Tpari)->second;
		
//		double ReA_j = AmapRe.find(Aparj)->second;
//		double ImA_j = AmapIm.find(Aparj)->second;
		double ReT_j = parityFactorj*TmapRe.find(Tparj)->second;
		double ImT_j = parityFactorj*TmapIm.find(Tparj)->second;

//		double a_i = ReA_i*ReT_i - ImA_i*ImT_i;
//		double a_j = ReA_j*ReT_j - ImA_j*ImT_j;

//		double b_i = ReA_i*ImT_i + ReT_i*ImA_i;
//		double b_j = ReA_j*ImT_j + ReT_j*ImA_j;

//		double ampl = a_i*a_j + b_i*b_j;

//		FOR TESTING // IRAKLI
		double NamplFactor = 1;

//		THIS WAS BEFORE
//		double ampl = (AparNoLambdaZ*AparNoLambdaZ) * (ReT_i*ReT_j + ImT_i*ImT_j);
//		THERE IS NO REASON TO TAKE PARAMETER IN ABSOLUTE SQUARE IF THAT IS THE ONLY WAY IT SHOWS UP
		double ampl = NamplFactor*(AparNoLambdaZ*AparNoLambdaZ) * (ReT_i*ReT_j + ImT_i*ImT_j);
		if (debug) cout << "ampl = (AparNoLambdaZ*AparNoLambdaZ) * (ReT_i*ReT_j + ImT_i*ImT_j)" << endl;
		if (debug) cout << "ampl = " << AparNoLambdaZ << " * " << AparNoLambdaZ << " * (" << ReT_i << " * " << ReT_j << " + " << ImT_i << " * " << ImT_j << " ) = " << ampl << endl;

		if (debug)
			{
			if (!onceDone)
				{
				FILE * myParamFile;
				myParamFile = fopen("amplitudes.tex", "a");
				fprintf(myParamFile, "A'_{%d} = |A_{%d}|^2[Re(T^{%d}_{%d,%d,%d})Re(T^{%d}_{%d,%d,%d}) + Im(T^{%d}_{%d,%d,%d})Im(T^{%d}_{%d,%d,%d})] \\\\ \n", count, aParNoLambdaZ, Tpari.J, Tpari.lambdaz, Tpari.lambdagamma, Tpari.lambdaqq, Tparj.J, Tparj.lambdaz, Tparj.lambdagamma, Tparj.lambdaqq, Tpari.J, Tpari.lambdaz, Tpari.lambdagamma, Tpari.lambdaqq, Tparj.J, Tparj.lambdaz, Tparj.lambdagamma, Tparj.lambdaqq);
				if (outit->delta)
					{
					fprintf(myParamFile, "\\omega_{%d} = 2[(2*%d + 1)(2*%d+1)d^{%d}_{%d,%d}*d^{%d}_{%d,%d}*d^{1}_{%d,%d}*d^{1}_{%d,%d}] \\\\\n \\\\ \n", count, Tpari.J, Tparj.J, Tpari.J, Tpari.lambdaqq, Tpari.lambdaz - Tpari.lambdagamma, Tparj.J, Tparj.lambdaqq, Tparj.lambdaz - Tparj.lambdagamma, Tpari.lambdaz, aParNoLambdaZ, Tparj.lambdaz, aParNoLambdaZ);
					}
				else
					{
					fprintf(myParamFile, "\\omega_{%d} = [(2*%d + 1)(2*%d+1)d^{%d}_{%d,%d}*d^{%d}_{%d,%d}*d^{1}_{%d,%d}*d^{1}_{%d,%d}]*\\cos([%d\\phi_{\\ell} + %d\\phi_{Z}] - [%d\\phi_{\\ell} + %d\\phi_{Z}]) \\\\\n \\\\ \n", count, Tpari.J, Tparj.J, Tpari.J, Tpari.lambdaqq, Tpari.lambdaz - Tpari.lambdagamma, Tparj.J, Tparj.lambdaqq, Tparj.lambdaz - Tparj.lambdagamma, Tpari.lambdaz, aParNoLambdaZ, Tparj.lambdaz, aParNoLambdaZ, outit->innerSumi.alfal(), outit->innerSumi.alfaz(), outit->innerSumj.alfal(),outit->innerSumj.alfaz());
					}
				fclose(myParamFile);
				}
			}


//		cout << "A = " << ampl;
		if (debug && doIt)
			{
			cout << " --------------------- " << endl;
			cout << "A_lambdall = A_" << aParNoLambdaZ << endl;

			cout << "T_i = T^"<< Tpari.J << "_" << Tpari.lambdaz << "_" << Tpari.lambdagamma << "_" << Tpari.lambdaqq << endl;
			cout << "T_j = T^"<< Tparj.J << "_" << Tparj.lambdaz << "_" << Tparj.lambdagamma << "_" << Tparj.lambdaqq << endl;
			}

		double tempOmegaFunc	= omegaFunc(omegaVar, *outit);

		if (debug && doIt) cout << "omegaFunc(Omega) = " << tempOmegaFunc << endl;

		if (accOnce) myAmplitudes[count].push_back(ampl);

		if (withTCORR)
			{
			double tCorrection = tChannel(cos(omegaVar.thetaZ), ZMass, ZGMass);

			if (debug) cout << "tCorrection = " << tCorrection << endl;

//			with t channel correction
			if (debug) cout << "sum = " << sum << " + " << ampl << " * " << tempOmegaFunc << " * " << tCorrection << " = " ;
			sum += ampl*tempOmegaFunc*tCorrection;
//			sum += ampl*tCorrection; // this is just for testing tCorrection alone
			if (debug) cout << sum << endl;

			if (debug) cout << "acceptance = " << acceptance << " + " << ampl << " * " << epsilon.at(count) << " * " << tCorrection << " = " ;
			if (isData) acceptance += ampl*epsilon.at(count)*tCorrection; // FOR RECO
			else acceptance += ampl*tCorrection; // FOR MC TRUTH
			if (debug) cout << acceptance << endl;
			}
		else
			{
//			without t channel correction (in particular for J = 0 case)
			if (debug) cout << "sum = " << sum << " + " << ampl << " * " << tempOmegaFunc << " = " ;
			sum += ampl*tempOmegaFunc; // without t channel correction (in particular for J = 0 case)
			if (debug) cout << sum << endl;

			if (debug) cout << "acceptance = " << acceptance << " + " << ampl << " * " << epsilon.at(count) << " = " ;
			if (isData) acceptance += ampl*epsilon.at(count); // FOR RECO
			else acceptance += ampl; // FOR MC TRUTH
			if (debug) cout << acceptance << endl;
			}

//		cout << ampl << " * " << epsilon.at(count) << " * " << tCorrection << " = " << acceptance << endl;
//		cout << "; sum = " << sum << endl;

		count++;
		if (debug) cout << " ----------- end of omegFunc " << count << "-----------" << endl;
		if (debug) cout << " THIS IS A CALL NUMBER " << count - 1 << endl;
		}
//	=================================================================================================
//	======== END OF THE LOOP FOR FINAL SUMMATION OF THE DISTRIBUTION FUNCTION COMPONENTS ============
//	=================================================================================================

	if (!onceDone)
		{
//		h1->Draw();
//		c1->SaveAs("acceptance.gif");
		cout << "FULL CYCLE ONCE DONE!!!" << endl;
		if (isData) tfile->Close();
		onceDone = true;
		}

	if (acceptance < 0) { cout << "oh Mammaaaaaaa something terrible happened with ACCEPTANCE!!!" << endl;/* return make_pair(0, 0);*/}
	if (sum < 0) { cout << "oh Mammaaaaaaa something terrible happened with LIKELIHOOD!!!" << endl;/* return make_pair(0, 0);*/}
//	==============================================================
//	cout << " - " << count << " - " << endl;
//	cout << "Number of Amplitudes = " << parCounter << endl;

/*
	for (map<parT, double>::iterator it = TmapRe.begin(); it != TmapRe.end(); it++)
		cout << "Re : T[" << it->first.J << "," << it->first.lambdaz << "," << it->first.lambdagamma << "," << it->first.lambdaqq << "] ->" << it->second << endl;
	for (map<parT, double>::iterator it = TmapIm.begin(); it != TmapIm.end(); it++)
		cout << "Im : T[" << it->first.J << "," << it->first.lambdaz << "," << it->first.lambdagamma << "," << it->first.lambdaqq << "] ->" << it->second << endl;

	for (map<parA, double>::iterator it = AmapRe.begin(); it != AmapRe.end(); it++)
		cout << "Re : A[" << it->first.lambdaz << "," << it->first.lambdall << "] ->" << it->second << endl;
	for (map<parA, double>::iterator it = AmapIm.begin(); it != AmapIm.end(); it++)
		cout << "Im : A[" << it->first.lambdaz << "," << it->first.lambdall << "] ->" << it->second << endl;
*/
//	Old Version
/*
	for (map<parT, int>::iterator it = Tmap.begin(); it != Tmap.end(); it++)
		cout << "T[" << it->first.J << "," << it->first.lambdaz << "," << it->first.lambdagamma << "," << it->first.lambdaqq << "] ->" << it->second << endl;

	for (map<parA, int>::iterator it = Amap.begin(); it != Amap.end(); it++)
		cout << "A[" << it->first.lambdaz << "," << it->first.lambdall << "] ->" << it->second << endl;
*/
//	cout << sum << " - " << acceptance << endl;

//	delete &inSum;
//	delete &outSum;

	return make_pair(sum, acceptance);
	}
