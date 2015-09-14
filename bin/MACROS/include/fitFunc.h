#ifndef IRAKLI_FITFUNC_H
#define IRAKLI_FITFUNC_H

using namespace std;

struct parT
	{
	int J;
	double lambdaq;
	double lambdaqbar;
	int lambdaz;
	int lambdagamma;
	};

// the "less then" operator for parT struct (for map)
struct parTsort
	{
	bool operator()(const parT &a, const parT &b)
		{
		int A, B;
		int sign;

		A = a.J*10000;
		(a.lambdaz < 0) ? sign = -1 : sign = 2;
		A += a.lambdaz*sign*1000;
		(a.lambdagamma < 0) ? sign = -1 : sign = 2;
		A += a.lambdagamma*sign*100;
		(a.lambdaq < 0) ? sign = -2 : sign = 4;
		A += a.lambdaq*sign*10;
		(a.lambdaqbar < 0) ? sign = -2 : sign = 4;
		A += a.lambdaqbar*sign;

		B = b.J*10000;
		(b.lambdaz < 0) ? sign = -1 : sign = 2;
		B += b.lambdaz*sign*1000;
		(b.lambdagamma < 0) ? sign = -1 : sign = 2;
		B += b.lambdagamma*sign*100;
		(b.lambdaq < 0) ? sign = -2 : sign = 4;
		B += b.lambdaq*sign*10;
		(b.lambdaqbar < 0) ? sign = -2 : sign = 4;
		B += b.lambdaqbar*sign;

		return (A < B);
		}
	};

struct parA
	{
	int lambdaz;
	double lambdalplus;
	double lambdalminus;
	};

// the "less then" operator for parA struct (for map)
struct parAsort
	{
	bool operator()(const parA &a, const parA &b)
		{
		int A, B;
		int sign;

		(a.lambdaz < 0) ? sign = -1 : sign = 2;
		A = a.lambdaz*sign*100;
		(a.lambdalminus < 0) ? sign = -2 : sign = 4;
		A += a.lambdalminus*sign*10;
		(a.lambdalplus < 0) ? sign = -2 : sign = 4;
		A += a.lambdalplus*sign;

		(b.lambdaz < 0) ? sign = -1 : sign = 2;
		B = b.lambdaz*sign*100;
		(b.lambdalminus < 0) ? sign = -2 : sign = 4;
		B += b.lambdalminus*sign*10;
		(b.lambdalplus < 0) ? sign = -2 : sign = 4;
		B += b.lambdalplus*sign;

		return (A < B);
		}
	};

int similarPair(pair<int, int> pair1, pair<int, int> pair2);
double wignerd(int J, int lambda1, int lambda2, double theta);
double fitFunc(double *, double *);

#endif
