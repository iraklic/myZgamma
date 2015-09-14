#ifndef IRAKLI_ANGLECALCULATOR_H
#define IRAKLI_ANGLECALCULATOR_H

#include <map>
#include "TLorentzVector.h"

using namespace std;

map<string, double> zgammaAngleCalculator(TLorentzVector l1, TLorentzVector l2, TLorentzVector gamma);

#endif
