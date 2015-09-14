#ifndef IRAKLI_LIKELIHOODFUNC_H
#define IRAKLI_LIKELIHOODFUNC_H

#include <math.h>

using namespace std;

struct Omega
	{
	double thetaL;
	double thetaZ;
	double phiL;
	double phiZ;
	};

struct parT
	{
	int J;
	int lambdaqq;
	int lambdaz;
	int lambdagamma;
	};

// the "less then" operator for parT struct (for std::map)
struct parTsort
	{
	bool operator()(const parT &a, const parT &b)
		{
		int A, B;
		int parityA, parityB;
		int sign;

								A = a.J*1000;
		(a.lambdaz	< 0) ? sign = -1 : sign = 2;	A += a.lambdaz*sign*100;
		(a.lambdagamma	< 0) ? sign = -1 : sign = 2;	A += a.lambdagamma*sign*10;
		(a.lambdaqq	< 0) ? sign = -1 : sign = 2;	A += a.lambdaqq*sign;

								B = b.J*1000;
		(b.lambdaz	< 0) ? sign = -1 : sign = 2;	B += b.lambdaz*sign*100;
		(b.lambdagamma	< 0) ? sign = -1 : sign = 2;	B += b.lambdagamma*sign*10;
		(b.lambdaqq	< 0) ? sign = -1 : sign = 2;	B += b.lambdaqq*sign;

//		This part is to account for parity conservation that says :
//		T[J,lambzaZ, lambdagamma, lambfaqq] = T[J, -lambzaZ, -lambdagamma, -lambfaqq]
								parityA = a.J*1000;
		(a.lambdaz	< 0) ? sign = -2 : sign = 1;	parityA += a.lambdaz*sign*100;
		(a.lambdagamma	< 0) ? sign = -2 : sign = 1;	parityA += a.lambdagamma*sign*10;
		(a.lambdaqq	< 0) ? sign = -2 : sign = 1;	parityA += a.lambdaqq*sign;

								parityB = b.J*1000;
		(b.lambdaz	< 0) ? sign = -2 : sign = 1;	parityB += b.lambdaz*sign*100;
		(b.lambdagamma	< 0) ? sign = -2 : sign = 1;	parityB += b.lambdagamma*sign*10;
		(b.lambdaqq	< 0) ? sign = -2 : sign = 1;	parityB += b.lambdaqq*sign;

		if (A > parityA) A = parityA;
		if (B > parityB) B = parityB;

		return (A < B);
		}
	};

struct parA
	{
	int lambdaz;
	int lambdall;
	};

// the "less then" operator for parA struct (for std::map)
struct parAsort
	{
	bool operator()(const parA &a, const parA &b)
		{
		int A, B;
		int sign;

		(a.lambdaz < 0) ? sign = -1 : sign = 2; 	A = a.lambdaz*sign*10;
		(a.lambdall < 0) ? sign = -1 : sign = 2;	A += a.lambdall*sign;

		(b.lambdaz < 0) ? sign = -1 : sign = 2;		B = b.lambdaz*sign*10;
		(b.lambdall < 0) ? sign = -1 : sign = 2;	B += b.lambdall*sign;

		return (A < B);
		}
	};

int similarPair(pair<int, int> pair1, pair<int, int> pair2);
double wignerd(int J, int lambda1, int lambda2, double theta);
double fitFunc(double *, double *);
pair<double, double> likelihood(double *, double *);

// classes for -log likelihood
class innerSum
	{
	public:
	int J, lambdaqq, lambdaz;
	int alfal() {return -lambdaz;};
//	int alfaz() {return lambdaqq - lambdaz;}; // when lambdazgamma = lambdaz - lambdagamma
	int alfaz() {return lambdaqq + lambdaz;}; // when lambdazgamma = lambdagamma - lambdaz
	innerSum(){};
	innerSum(int a, int b, int c)
		{
		J = a;
		lambdaqq = b;
		lambdaz = c;
		};
	~innerSum(){};

	};
class outerSum
	{
	public:
	bool delta;
	int lambdall, lambdagamma;
	innerSum innerSumi, innerSumj;

	outerSum(){};
	outerSum(int a, int b, innerSum aS, innerSum bS, bool d)
		{
		delta = d;
		lambdall = a;
		lambdagamma = b;
		innerSumi = aS;
		innerSumj = bS;
		};
	~outerSum(){};
	};
double omegaFunc(Omega O, outerSum oSum);
#endif
