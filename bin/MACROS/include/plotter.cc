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
#include "TCanvas.h"
#include "TF1.h"
#include "TGraphErrors.h"
#include "TMath.h"

#include "plotter.h"

using namespace std;

map<string, TH1F *> histoToMap (string file, string type)
	{
	map<string, TH1F *> histoMap;
        TKey *key = 0;
        TFile * myFile = new TFile(file.c_str());

        TIter iter (myFile->GetListOfKeys());
        while((key = (TKey*) iter()))
		{
                histoMap[key->GetName()] = (TH1F*)key->ReadObj();
		}
//	myFile->Close();
	return histoMap;
	}

map<string, TObject *> objToMap (string file)
	{
	map<string, TObject *> objMap;
        TKey *key = 0;
        TFile * myFile = new TFile(file.c_str());

        TIter iter (myFile->GetListOfKeys());
        while((key = (TKey*) iter()))
		{
		objMap[key->GetName()] = key->ReadObj();
		}
	myFile->Close();
	return objMap;
	}


void histoScale (map<string, TH1F *> map1, map <string, TH1F *> map2, string name)
        {
        double scale_map = map1[name]->GetEntries() / map2[name]->GetEntries();
	map2[name]->Scale(scale_map);
        }


TObject * histoDraw(map<string, TH1F *> map1, map<string, TH1F *> map2, string name)
	{
	string cName = "histo_" + name;
	TCanvas * c = new TCanvas (cName.c_str(),cName.c_str());
	c->cd();
	map1[name]->SetMinimum(0);
	map1[name]->Draw("histo");
	map2[name]->SetLineColor(2);
	map2[name]->Draw("SAMEhisto");

	return c->DrawClonePad();
	}


TObject * histoSens (map<string, TH1F *> map1, map<string, TH1F *> map2, string name, int N, int parity)
	{
	string cName = "sens_" + name;
	TCanvas * c = new TCanvas (cName.c_str(),cName.c_str());
	c->cd();
	double xmin = map1[name]->GetXaxis()->GetXmin();
	double xmax = map1[name]->GetXaxis()->GetXmax();
	int bins = map1[name]->GetXaxis()->GetNbins();

	int lastbin = bins;

        double weight = bins / (xmax - xmin) ;

        float grCut[N], grSens[N];
        int i = 0;

	if (parity == -1) xmax = (xmax + xmin) / 2;
	double step = (xmax - xmin) / N;

        for (double cut = xmin; cut < xmax; cut+=step)
                {
                int bin = (cut - xmin) * weight;
		if (parity == -1) lastbin = bins -bin;
                double b = map1[name]->Integral(bin, lastbin);
                double s = map2[name]->Integral(bin, lastbin) - map1[name]->Integral(bin, lastbin);
                double sens = s / sqrt(s+b);
                grCut[i] = cut;
                grSens[i] = sens;
                i++;
                }
	TGraph * graph = new TGraph (N,grCut,grSens);
	string grName = "Sencitivity for " + name;
	graph->SetTitle(grName.c_str());
	graph->Draw("AC*");

	return c->DrawClonePad();
	}

void rebin (vector<string> v, map<string, TH1F *> m1, map<string, TH1F *> m2, int bin)
	{
	cout << "REBINING..." << endl;
	for (vector<string>::iterator it = v.begin(); it < v.end(); ++it)
		{
		if (m1.find(*it) == m1.end() || m2.find(*it) == m2.end())
			{
			cout << "From \"rebin\" Method : Histogram \"" << *it << "\" was not found in the file ! ! !" << endl;
			continue;
			}
		m1[*it]->Rebin(bin);
		m2[*it]->Rebin(bin);
		}
	cout << "REBINING SUCCESSFUL..." << endl;
	}

void fit(vector<string> v, map<string, TH1F *> m1, map<string, TH1F *> m2, double start, double end, string fileName)
        {
	FILE * myfile;
	myfile = fopen("FIT.txt", "w");

	int N = v.size();
	double lambda0_m1[N], lambda1_m1[N], lambda2_m1[N], error0_m1[N], error1_m1[N], error2_m1[N];
	double lambda0_m2[N], lambda1_m2[N], lambda2_m2[N], error0_m2[N], error1_m2[N], error2_m2[N];

	double ptRange[] = {5, 15, 25, 35, 45, 75, 105, 155, 205, 255,  305, 355, 405, 455, 505, 555, 605, 655, 705, 755, 805};
	double p[N], p_E[N];
	for (int i = 0; i < N; ++i)
		{
		p[i] = (ptRange[i+1] + ptRange[i]) / 2;
		p_E[i] = (ptRange[i+1] - ptRange[i]) / 2;
		}

	int divH, divV;
	divH = (int) sqrt(v.size());
	(v.size() % divH) ? divV = v.size() / divH + 1 : divV = v.size() / divH;

        TF1 *myFit = new TF1("myFit", "pol2", start, end);

	TCanvas * c = new TCanvas("c","c",1200,800);
	c->Divide(divH, divV);

	int divC = 1;
	int grC = 0;

	int grC_SM = 0;
	int grC_04 = 0;

        for (vector<string>::iterator it = v.begin(); it < v.end(); ++it)
                {
                if (m1.find(*it) == m1.end() || m2.find(*it) == m2.end())
                        {
                        cout << "From \"fit\" Method : Histogram \"" << *it << "\" was not found in the file ! ! !" << endl;
                        continue;
                        }
		c->cd(divC);
		if (m1[*it]->GetEntries() > 10)
			{
			myFit->SetLineColor(1);
        	        m1[*it]->Fit(myFit,"QR");

			lambda0_m1[grC] = myFit->GetParameter(0);
			lambda1_m1[grC] = myFit->GetParameter(1);
			lambda2_m1[grC] = myFit->GetParameter(2);
			error0_m1[grC] = myFit->GetParError(0);
			error1_m1[grC] = myFit->GetParError(1);
			error2_m1[grC] = myFit->GetParError(2);
			fprintf (myfile, "SM - %s - %6.2f / %i", it->c_str(), myFit->GetChisquare(), myFit->GetNDF() );
			fprintf (myfile, "; Probability = %f\n", TMath::Prob(myFit->GetChisquare(), myFit->GetNDF()));
			grC_SM++;
			}
		else
			{
                        lambda0_m1[grC] = 0;
                        lambda1_m1[grC] = 0;
                        lambda2_m1[grC] = 0;
                        error0_m1[grC] = 0;
                        error1_m1[grC] = 0;
                        error2_m1[grC] = 0;
			}

		if (m2[*it]->GetEntries() > 10)
			{
			myFit->SetLineColor(2);
                	m2[*it]->Fit(myFit,"QR");

	                lambda0_m2[grC] = myFit->GetParameter(0);
        	        lambda1_m2[grC] = myFit->GetParameter(1);
                	lambda2_m2[grC] = myFit->GetParameter(2);
	                error0_m2[grC] = myFit->GetParError(0);
        	        error1_m2[grC] = myFit->GetParError(1);
                	error2_m2[grC] = myFit->GetParError(2);
			fprintf (myfile, "TGC - %s - %6.2f / %i", it->c_str(), myFit->GetChisquare(), myFit->GetNDF() );
			fprintf (myfile, "; Probability = %f\n", TMath::Prob(myFit->GetChisquare(), myFit->GetNDF()));
			grC_04++;
			}
                else
                        {
                        lambda0_m2[grC] = 0;
                        lambda1_m2[grC] = 0;
                        lambda2_m2[grC] = 0;
                        error0_m2[grC] = 0;
                        error1_m2[grC] = 0;
                        error2_m2[grC] = 0;
                        }

		if(m1[*it]->GetEntries() > 10)
			{
			m1[*it]->Draw();
			m2[*it]->SetLineColor(2);
			m2[*it]->Draw("SAMES");
			}
		else
			{
			m2[*it]->SetLineColor(2);
			m2[*it]->Draw();
			}
		grC++;
		divC++;
		}
	c->SaveAs((fileName + "_FIT.C").c_str());

	TCanvas * cGr = new TCanvas("cGr","cGr",1200,800);
	cGr->Divide(3,1);

	TGraphErrors * gr0_m1 = new TGraphErrors (grC_SM, p, lambda0_m1, p_E, error0_m1);
	TGraphErrors * gr1_m1 = new TGraphErrors (grC_SM, p, lambda1_m1, p_E, error1_m1);
	TGraphErrors * gr2_m1 = new TGraphErrors (grC_SM, p, lambda2_m1, p_E, error2_m1);

        TGraphErrors * gr0_m2 = new TGraphErrors (grC_04, p, lambda0_m2, p_E, error0_m2);
        TGraphErrors * gr1_m2 = new TGraphErrors (grC_04, p, lambda1_m2, p_E, error1_m2);
        TGraphErrors * gr2_m2 = new TGraphErrors (grC_04, p, lambda2_m2, p_E, error2_m2);

	cGr->cd(1);
	gr0_m2->SetTitle("#lambda_{0} from (#lambda_{2}cos^{2}(#theta_{l}) + #lambda_{1}cos(#theta_{l}) + #lambda_{0})");
	gr0_m2->SetMarkerColor(2);
	gr0_m2->SetLineColor(2);
	gr0_m2->Draw("AP");
	gr0_m1->Draw("SAMEP");

        cGr->cd(2);
	gr1_m2->SetTitle("#lambda_{1} from (#lambda_{2}cos^{2}(#theta_{l}) + #lambda_{1}cos(#theta_{l}) + #lambda_{0})");
	gr1_m2->SetMarkerColor(2);
	gr1_m2->SetLineColor(2);
        gr1_m2->Draw("AP");
        gr1_m1->Draw("SAMEP");

        cGr->cd(3);
	gr2_m2->SetTitle("#lambda_{2} from (#lambda_{2}cos^{2}(#theta_{l}) + #lambda_{1}cos(#theta_{l}) + #lambda_{0})");
	gr2_m2->SetMarkerColor(2);
	gr2_m2->SetLineColor(2);
        gr2_m2->Draw("AP");
        gr2_m1->Draw("SAMEP");

	cGr->SaveAs((fileName + "_GR.C").c_str());

	fclose(myfile);
	}

