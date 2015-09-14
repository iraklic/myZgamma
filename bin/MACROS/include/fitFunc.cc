//////////////////////////////////////////////
// Process : qqbar->Zgamma->llgamma         //
// Function to fit to angular distribution  //
// Authot : Irakli Chakaberia               //
// Date Written : 16 Feb 2011               //
// Date Updated : 16 Feb 2011               //
//////////////////////////////////////////////

#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include "fitFunc.h"

using namespace std;

// Helper fuction to reduce pairs of d function to orthogonal pairs
bool samePair(pair<int, int> pair1, pair<int, int> pair2)
	{
	if (pair1.first == pair2.first && pair1.second == pair2.second) return true;
	else return false;
	}
int similarPair(pair<int, int> pair1, pair<int, int> pair2)
	{
	if (pair1.first == -pair2.second && pair1.second == -pair2.first) return 1;
	if (pair1.first == pair2.second && pair1.second == pair2.first) return (int) pow(-1, pair1.second-pair1.first);
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
		else if	(pairIndex.first == 1)	d = -sqrt(3/2)*cos(theta)*sin(theta);
		else if	(pairIndex.first == 2)	d = ((1 - cos(theta))/2)*(2*cos(theta) + 1);
		else if	(pairIndex.first == 3)	d = ((1 + cos(theta))/2)*(2*cos(theta) - 1);
		else if	(pairIndex.first == 4)	d = sqrt(6)*pow(sin(theta), 2)/4;
		else if	(pairIndex.first == 5)	d = -((1 + cos(theta))/2)*sin(theta);
		else if	(pairIndex.first == 6)	d = pow((1 + cos(theta)/2), 2);
		else if	(pairIndex.first == 7)	d = -((1 - cos(theta))/2)*sin(theta);
		else				d = pow((1 - cos(theta)/2), 2);
		}

//	printf("d[%d,%d,%d](cos(%f)) = %f\n", J, lambda1, lambda2, theta, pairIndex.second*d);

	return pairIndex.second*d;
	}

// calculation of result of angular distribution
double fitFunc(double * x, double * par)
	{
//	parameter counter
	int parCounter = 0;
	int parTCounter = 0;
	int parACounter = 1000;

//	variables
//	double thetaZ = acos(x[0]);
	double thetaZ = 0.5;
	double thetaL = acos(x[0]);
//	double thetaL = 0.5;
//	double phiZ = x[0];
	double phiZ = 0.5;
//	double phiL = x[3];
	double phiL = 0.5;
//	double phi = x[0];
	double phi = 0.5;

//	parameters
	parT Tpar;
	parA Apar;
	map<parT, int, parTsort> Tmap;
	map<parA, int, parAsort> Amap;

//	summation parameters
	int lambdagamma, J, lambdaz;
	double lambdalplus, lambdalminus, lambdaq, lambdaqbar;
	vector<double> expC, expP;
	double square, sum = 0;


	double T, A;
//	LOOPS AFTER SQUARING
	for (lambdagamma = -1; lambdagamma <= 1; lambdagamma+=2)
		for (lambdalplus = -0.5; lambdalplus <= 0.5; lambdalplus++)
			for (lambdalminus = -0.5; lambdalminus <= 0.5; lambdalminus++)
				{
				square = 0;
				expC.clear();
				expP.clear();
//				LOOPS BEFORE SQUARING
				for (lambdaq = -0.5; lambdaq <= 0.5; lambdaq++)
					for (lambdaqbar = -0.5; lambdaqbar <= 0.5; lambdaqbar++)
						for (J = 0; J <= 0; J++)
							for (lambdaz = -1; lambdaz <= 1; lambdaz++)
								{
								Tpar.J = J;
								Tpar.lambdaq = lambdaq;
								Tpar.lambdaqbar = lambdaqbar;
								Tpar.lambdaz = lambdaz;
								Tpar.lambdagamma = lambdagamma;

								Apar.lambdaz = lambdaz;
								Apar.lambdalplus = lambdalplus;
								Apar.lambdalminus = lambdalminus;

								int lambdaqqbar = (int) (lambdaq-lambdaqbar);
								int lambdazgamma = (lambdaz - lambdagamma);
								int lambdall = (int) (lambdalplus - lambdalminus);
								double dZ = wignerd(J, lambdaqqbar, lambdazgamma, thetaZ);
								double dl = wignerd(1, lambdaz, lambdall, thetaL);
								if (dZ == -999.999 || dl == -999.999) continue;
								if (Tmap.find(Tpar) == Tmap.end())
									{
									T = par[parCounter];
									Tmap[Tpar] = parCounter;
//									parCounter++;
									}
								if (Amap.find(Apar) == Amap.end())
									{
									A = par[parCounter];
									Amap[Apar] = parCounter;
									parCounter++;
									}
								T = 1;
//								A = 1;
								expC.push_back((2*J + 1)*T*A*dZ*dl);
								expP.push_back((lambdaqqbar-lambdazgamma)*phiZ-(lambdaz-lambdall)*phiL); // most general
//								expP.push_back((lambdaqqbar-lambdazgamma-lambdaz+lambdall)*phi); // fir one phi
								}
//				SQUARING
				for (int i = 0; i < expC.size(); ++i)
					for (int j = 0; j < expC.size(); ++j)
						{
						double factor = 0;
						if (i == j) factor = 1;
						else factor = 2;
						square += factor*expC[i]*expC[j]*cos(expP[i] - expP[j]);
						}
//				cout << square << " + ";
//				SUMMATION AFTER SQUARING
				sum += square;
				}
//	cout << " = " << sum <<  endl;
	return sum;
	}
