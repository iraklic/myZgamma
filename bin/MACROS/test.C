#include <iostream>
#include "TLorentzVector.h"
#include "TVector3.h"

using namespace std;


void test()
	{
	TLorentzVector a, b;

	a.SetPx(1.3);
	a.SetPy(2.3);
	a.SetPz(3.3);
	a.SetE(6.3);

	b.SetPx(2.3);
	b.SetPy(3.3);
	b.SetPz(4.3);
	b.SetE(9.3);

//	TVector3 u = a.Vect().Unit();
	TVector3 u = (0,0,-1);

	a.Print();

	a.RotateUz(u);
	b.RotateUz(u);


	a.Print();
	cout << a.CosTheta() << " - " << b.CosTheta() << endl;
	}
