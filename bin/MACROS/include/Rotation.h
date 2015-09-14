#ifndef IRAKLI_ROTATION_H
#define IRAKLI_ROTATION_H

#include "TROOT.h"
#include "TMath.h"
#include "TLorentzVector.h"

#include <iostream>
#include <stdlib.h>

using namespace std;

TLorentzVector RotateFromZ(TLorentzVector V0, TLorentzVector Z0);
TLorentzVector RotateToZ(TLorentzVector V0, TLorentzVector Z0);

#endif
