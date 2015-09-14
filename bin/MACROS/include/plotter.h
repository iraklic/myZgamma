#ifndef IRAKLI_PLOTTER_H
#define IRAKLI_PLOTTER_H

#include <iostream>
#include <map>
#include <string>
#include <math.h>
#include <vector>

#include "TFile.h"
#include "TH1.h"
#include "TKey.h"
#include "TCollection.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TCanvas.h"
#include "TObject.h"

using namespace std;

map<string, TH1F *> histoToMap (string, string type = "TH1");
map<string, TObject *> objToMap (string);
void histoScale (map<string, TH1F *>, map<string, TH1F *>, string);
TObject * histoDraw (map<string, TH1F *>, map<string, TH1F *>, string);
TObject * histoSens (map<string, TH1F *>, map<string, TH1F *>, string, int N = 10, int parity = 1);

void rebin (vector<string>, map<string, TH1F *>, map<string, TH1F *>, int bin = 2);
void fit (vector<string>, map<string, TH1F *>, map<string, TH1F *>, double, double, string);

#endif
