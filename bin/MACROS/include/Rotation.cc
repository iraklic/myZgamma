//////////////////////////////////////////////
// description : rotates vector V0 from     //
// system where Z axis is along Z0 vector   //
// and X and Y gotten from euler rotation   //
// with angles (a,b,c) where c = -a         //
// authot : Irakli Chakaberia               //
// date written : 24 Sep 2011               //
//////////////////////////////////////////////

#include "TROOT.h"
#include "TMath.h"
#include "TLorentzVector.h"

#include <iostream>
#include "../include/Rotation.h"

using namespace std;


TLorentzVector RotateFromZ(TLorentzVector V0, TLorentzVector Z0)
	{
	TVector3 Z = Z0.Vect();
	TVector3 V = V0.Vect();

	double PI = TMath::Pi();
	double thetaZ	= 0;
	double phiZ	= 0;

	thetaZ = Z.Theta();
	phiZ = Z.Phi();

	TVector3 XPrime, ZPrime;
	double alpha;

	alpha = PI/2 + phiZ;

	XPrime.SetMagThetaPhi(1, PI/2, alpha);
	ZPrime.SetMagThetaPhi(1, thetaZ, phiZ);

	V.Rotate(alpha, ZPrime);
	V.Rotate(-thetaZ, XPrime);
	V.RotateZ(-1*alpha);

	TLorentzVector newV(V, V0.E());

	return newV;
	}

TLorentzVector RotateToZ(TLorentzVector V0, TLorentzVector Z0)
	{
	TVector3 Z = Z0.Vect();
	TVector3 V = V0.Vect();

	double PI = TMath::Pi();
	double thetaZ	= 0;
	double phiZ	= 0;

	thetaZ = Z.Theta();
	phiZ = Z.Phi();

	TVector3 XPrime, ZPrime;
	double alpha = PI/2 + phiZ;
	XPrime.SetMagThetaPhi(1, PI/2, alpha);
	ZPrime.SetMagThetaPhi(1, thetaZ, phiZ);

	V.RotateZ(alpha);
	V.Rotate(thetaZ, XPrime);
	V.Rotate(-1*alpha, ZPrime);

	TLorentzVector newV(V, V0.E());

	return newV;
	}
