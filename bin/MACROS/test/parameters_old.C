#include <TH1.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TGraphErrors.h>
#include <TMultiGraph.h>

#include <vector>
#include <string>

vector<double> readParams(string fileName)
	{
	vector<double> vec;
	FILE * myParFile;
	myParFile = fopen(fileName.c_str(), "r");
	if (myParFile == NULL) { cout << "File error" << endl; return vec;}
	float data = 0;
	while (fscanf(myParFile, "%f", &data) != EOF)
		vec.push_back(data);

	fclose(myParFile);
	return vec;
	}

void parameters()
	{
//	read parameters into vectors
	vector<string> files;
	vector< vector<double> > params;
	vector< TMultiGraph *> mg;

	files.push_back("outParams_SM_ee_BAUR_-41.txt");
	files.push_back("outParams_SM_ee_BAUR_outParams_SM_ee_BAUR_5.txt");

	vector<double> x1 = readParams("outParams_SM_ee_BAUR_-41.txt");
	vector<double> x2 = readParams("outParams_SM_ee_BAUR_outParams_SM_ee_BAUR_5.txt");

	for (int i = 0; i < files.size(); i++)
		{
		params.push_back(readParams(files[i]));
		for (int i = 0; i < params.back().size)
			{
		X1[i] = x1[2*i];
		XE1[i] = x1[2*i+1];
		X2[i] = x2[2*i];
		XE2[i] = x2[2*i+1];

			double
			}
		}

	const int nPar = params[0].size() / 2;



	TCanvas * c1 = new TCanvas();

	TLegend * leg = new TLegend(0.8, 0.8, 1, 1);
	leg->SetLineColor(0);
	leg->SetFillColor(0);

	const int npar = x1.size()/2;
	cout << "NUMBER of PARAMETERS = " << npar << endl;
	double X1[npar]; 
	double XE1[npar];
	double X2[npar];
	double XE2[npar];

	for (int i = 0; i < npar; i++)
		{
		X1[i] = x1[2*i];
		XE1[i] = x1[2*i+1];
		X2[i] = x2[2*i];
		XE2[i] = x2[2*i+1];


//		cout << X1[2*i] << " : 1 : " << X1[2*i+1] << endl;
//		cout << X2[2*i] << " : 2 : " << X2[2*i+1] << endl;
		}

	double TGCXdata[1] = {4.362996};
	double TGCXEdata[1] = {0.105214};
	double TGCaxisdata[1] = {11};
	double TGCaxisEdata[1] = {0};

	double Xdata[1] = {8.796306};
	double XEdata[1] = {0.200194};
	double axisdata[1] = {11};
	double axisEdata[1] = {0};

	double axis[npar];
	double axisE[npar];

	for (int i = 0; i < npar; i++)
		{
		axis[i] = i;
		axisE[i] = 0;
		}

	TGraphErrors * grData = new TGraphErrors(1, axisdata, Xdata, axisEdata, XEdata);
	grData->SetMarkerStyle(24);
	grData->SetLineColor(2);
	grData->SetMarkerColor(2);

	TGraphErrors * grDataTGC = new TGraphErrors(1, TGCaxisdata, TGCXdata, TGCaxisEdata, TGCXEdata);
	grDataTGC->SetMarkerStyle(24);
	grDataTGC->SetLineColor(4);
	grDataTGC->SetMarkerColor(4);

	TGraphErrors * grSM = new TGraphErrors(npar, axis, X1, axisE, XE1);
	grSM->SetLineColor(2);
	grSM->SetMarkerStyle(7);
	grSM->SetMarkerColor(2);

	TGraphErrors * grTGC = new TGraphErrors(npar, axis, X2, axisE, XE2);
	grTGC->SetLineColor(4);
	grTGC->SetMarkerStyle(7);
	grTGC->SetMarkerColor(4);

	TH1F * hSM	= new TH1F("hSM", "STANDARD MODEL", npar, 0 , npar);
	hSM->SetLineColor(2);
	hSM->SetMarkerStyle(7);
	TH1F * hTGC	= new TH1F("hTGC", "TGC", npar, 0 , npar);
	hTGC->SetLineColor(4);
	hTGC->SetMarkerStyle(7);
	hTGC->SetFillColor(4);


	for (int i = 0; i < npar; i++)
		{
		hSM->SetBinContent(i+1, X1[i]);
		hSM->SetBinError(i+1, XE1[i]);
		hTGC->SetBinContent(i+1, X2[i]);
		hTGC->SetBinError(i+1, XE2[i]);
		}
//	hSM->Draw();
//	hTGC->Draw("SAME");

	TMultiGraph * mg = new TMultiGraph();
//	mg->Add(grData);
//	mg->Add(grDataTGC);
	mg->Add(grSM);
	mg->Add(grTGC);

	mg->Draw("APE");
	mg->GetXaxis()->SetTitle("Parameter Index");
	mg->GetYaxis()->SetTitle("Parameter Value");
	
//	leg->AddEntry(grData, "DATA / SM", "pl");
//	leg->AddEntry(grDataTGC, "DATA / TGC", "pl");
	leg->AddEntry(grSM, "SM", "pl");
	leg->AddEntry(grTGC, "Non-SM", "pl");
	leg->Draw();

	c1->SaveAs("params.root");

	}
