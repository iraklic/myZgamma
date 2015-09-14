//////////////////////////////////////////////
// Process : qqbar->Zgamma->llgamma         //
// This routine calculates helicity angles  //
// Authot : Irakli Chakaberia               //
// Date Written : 16 Sep 2012               //
//////////////////////////////////////////////

#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include "TLorentzVector.h"
#include "Rotation.h"
#include "angleCalculator.h"

using namespace std;

map<string, double> zgammaAngleCalculator(TLorentzVector l1, TLorentzVector l2, TLorentzVector gamma)
	{
//	Defining Variables
        TLorentzVector zgamma, antizgamma, Z;
        TLorentzVector Z_Z, gamma_Z, l1_Z, l2_Z;				// Vectors BOOSTED into Z rest frame
        TLorentzVector antizgamma_cm, Z_cm, gamma_cm, l1_cm, l2_cm, zgamma_cm;	// Vectors BOOSTED into Zgamma CM frame
	TLorentzVector l1_Z_cm, gamma_Z_cm, Z_Z_cm;				// Vectors BOOSTED into Z_cm rest frame from ZGamma CM frame

//	Defininf boost vectors;
	TVector3 betaZgamma, betaZ, beta_Z_cm;

//	Defininf container map
	map<string, double> angleMap;

//	constructing Z and ZGamma 4vectors
	Z = l1 + l2;

	zgamma = Z + gamma;
	antizgamma.SetPx(-1*zgamma.Px());
	antizgamma.SetPy(-1*zgamma.Py());
	antizgamma.SetPz(-1*zgamma.Pz());
	antizgamma.SetE(zgamma.E());

	angleMap["ZMass"]	= Z.M();
	angleMap["ZGMass"]	= zgamma.M();
	angleMap["ZGPt"]	= zgamma.Pt();
	angleMap["ZGPx"]	= zgamma.Px();
	angleMap["ZGPy"]	= zgamma.Py();
	angleMap["ZGPz"]	= zgamma.Pz();
	angleMap["ZGY"]		= zgamma.Rapidity();
	angleMap["GammaPt"]	= gamma.Pt();
	angleMap["ZPt"]		= Z.Pt();
	angleMap["ZPz"]		= Z.Pz();
	angleMap["ZPx"]		= Z.Px();
	angleMap["ZPy"]		= Z.Py();


//	initializing all variables with variables in lab frame
	Z_Z = Z;
	gamma_Z = gamma;
	l1_Z = l1;
	l2_Z = l2;

	zgamma_cm = zgamma;
	antizgamma_cm = antizgamma;
	Z_cm = Z;
	gamma_cm = gamma;
	l1_cm = l1;
	l2_cm = l2;

	gamma_Z_cm = gamma;
	Z_Z_cm = Z;
	l1_Z_cm = l1;

//	Initializing boostvectors
	betaZgamma = -1*zgamma.BoostVector();
	zgamma_cm.Boost(betaZgamma);
	antizgamma_cm.Boost(betaZgamma);

	betaZ = -1*Z.BoostVector();

//	BOOSTING into Z rest frame
	l1_Z.Boost(betaZ);
	l2_Z.Boost(betaZ);
	gamma_Z.Boost(betaZ);

//	BOOSTING into Zgamma CM Frame
	l1_cm.Boost(betaZgamma);
	l2_cm.Boost(betaZgamma);
	Z_cm.Boost(betaZgamma);
	Z_Z_cm.Boost(betaZgamma);
	gamma_Z_cm.Boost(betaZgamma); 
	l1_Z_cm.Boost(betaZgamma);

//	initializing boostvector for Z_cm rest frame from ZGamma CM frame
	beta_Z_cm = -1*Z_cm.BoostVector();

	Z_Z_cm.Boost(beta_Z_cm);

	l1_Z_cm.Boost(beta_Z_cm);
	gamma_Z_cm.Boost(beta_Z_cm);

//	making correct rotations for angles
	TLorentzVector l1_CORR = RotateFromZ(l1_Z_cm, Z_cm);
	TLorentzVector Z_CORR = RotateFromZ(Z_cm, zgamma);

//	Angle Calculation
	angleMap["cosThetaL_cm"]	= cos(Z_cm.Vect().Angle(l1_Z_cm.Vect()));
//	angleMap["cosThetaL_cm"]	= cos(gamma_Z_cm.Vect().Angle(l1_Z_cm.Vect()));
	angleMap["cosThetaL"]		= cos(gamma_Z.Vect().Angle(l1_Z.Vect()));
//	angleMap["cosThetaL"]		= cos((l1_CORR.Vect()).Theta());

//	angleMap["cosThetaZ"]		= cos(Z.Vect().Angle(p.Vect()));
//	angleMap["cosThetaZ"]		= cos(Z.Vect().Angle(pp));
//	angleMap["cosThetaZ"]		= cos((Z_CORR.Vect()).Theta());
	angleMap["cosThetaZ"]		= cos(antizgamma_cm.Vect().Angle(Z_cm.Vect()));
	angleMap["cosThetaZ_cm"]	= cos(Z_cm.Vect().Angle(zgamma.Vect()));
	angleMap["thetaZ"]		= Z.CosTheta();
	angleMap["thetaZ_cm"]		= Z_cm.CosTheta();

//	angleMap["cosThetag"]		= cos(gamma_cm.Vect().Angle(p.Vect()));

//	angleMap["phiL"]		= l1_Z_cm.Phi();
	angleMap["phiL"]		= (l1_CORR.Vect()).Phi();
	angleMap["phiZ"]		= (Z_CORR.Vect()).Phi();
//	angleMap["phi"]			= angleMap["phiL"] - angleMap["phiZ"];
//	if (angleMap["phi"] < 0) angleMap["phi"] = 6.24 + angleMap["phi"];

	angleMap["phi"]		= ((l1.Vect()).Cross(l2.Vect())).Angle(gamma.Vect().Cross(Z.Vect()));
	if (angleMap["phi"] > 3.14/2) angleMap["phi"] -= 3.14;
//	angleMap["psi"]		= (l1_cm.Vect().Cross(l2_cm.Vect())).Angle(Z_cm.Vect().Cross(p.Vect()));
	angleMap["phi_cm"]	= 3.14/2 - ((l1_cm.Vect()).Cross(l2_cm.Vect())).Angle(gamma_cm.Vect());
//	angleMap["phil"]	= ((l1.Vect()).Cross(l2.Vect())).Angle((gamma.Vect()).Cross(Z.Vect()));

//	angleMap["thetaL"]	= Z.Vect().Angle(l1_Z.Vect());

	return angleMap;
	}
