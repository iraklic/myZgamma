#include <TH1.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TGraphErrors.h>
#include <TMultiGraph.h>
#include <TStyle.h>
#include <TROOT.h>

#include <map>
#include <utility>
#include <vector>
#include <string>
#include <TLatex.h>

using namespace std;

vector<double> readParams(string fileName)
	{
	vector<double> vec;
	FILE * myParFile;
	myParFile = fopen(fileName.c_str(), "r");
	if (myParFile == NULL) { cout << "File error : " << fileName << endl; return vec;}
	float data = 0;
	while (fscanf(myParFile, "%f", &data) != EOF)
		vec.push_back(data);

	fclose(myParFile);
	return vec;
	}

void parameters()
	{
	gROOT->ProcessLine(".L ../include/CMSStyle.C");
	gROOT->ProcessLine("CMSstyle()");
	gStyle->SetOptStat(0);
	gStyle->SetOptTitle(0);

//	actual helicity amplitudes for J = 2
	string aplitudes[] = {
			"T^{1}_{-1,-1,-1}",
			"T^{1}_{0,-1,-1}",
			"T^{2}_{-1,-1,-1}",
			"T^{2}_{0,-1,-1}",
			"T^{2}_{1,-1,-1}",
			"T^{0}_{-1,-1,0}",
			"T^{1}_{-1,-1,0}",
			"T^{1}_{0,-1,0}",
			"T^{2}_{-1,-1,0}",
			"T^{2}_{0,-1,0}",
			"T^{2}_{1,-1,0}",
			"T^{1}_{-1,-1,1}",
			"T^{1}_{0,-1,1}",
			"T^{2}_{-1,-1,1}",
			"T^{2}_{0,-1,1}",
			"T^{2}_{1,-1,1}",
			"A_{-1}",
			"A_{1}"
			};

//	read parameters into vectors
	vector<string> files;
	vector< vector<double> > params;

	TLatex * tex = new TLatex();
	tex->SetNDC();
	tex->SetTextSize(0.04);

	TMultiGraph * mg = new TMultiGraph();

	TLegend * leg = new TLegend(0.7, 0.9, 1.0, 1.0);
	leg->SetLineColor(0);
	leg->SetFillColor(0);


//	5/0 initParam
	string list3[] = {
//			"outParams_2_initParams_2_5_0_BAUR_mm_SM.txt_5_0_MG5_mm_SM.txt"		,	"NLO",
//			"initParams/initParams_2_5_0_BAUR_ee_SM.txt"				,	"",
//			"initParams/initParams_2_5_0_BAUR_mm_SM_V0.txt"				,	"",



//			"initParams/initParams_2_5_0_BAUR_ee_SM.txt"				,	"initParams",
//			"outParams_2_initParams_2_5_0_BAUR_ee_SM.txt_5_0_BAUR_ee_SM.txt"	,	"Monte Carlo (SM)"
//			"outParams_2_initParams_2_5_0_BAUR_ee_SM_SIG.txt_5_0_BAUR_ee_SM.txt"	,	"Monte Carlo (SM)",
//			"outParams_2_initParams_2_5_0_BAUR_ee_SM.txt_5_0_BAUR_ee_NSM.txt"	,	"Monte Carlo (NSM)"
//			"outParams_2_initParams_2_5_0_BAUR_ee_SM.txt_5_0_BAUR_ee_SM_GEN.txt"	,	"Monte Carlo (GEN Level)"
//			"outParams_2_initParams_2_5_0_BAUR_ee_SM.txt_5_0_Data_ee.txt"		,	"Data"
//			"outParams_2_initParams_2_5_0_BAUR_ee_SM.txt_5_0_BS_ee.txt"		,	"Monte Carlo (Signal + BG)"
//			"outParams_2_initParams_2_5_0_BS_ee.txt_5_0_BS_ee.txt"			,	"Monte Carlo (Signal + BG)"
//			"outParams_2_initParams_2_5_0_BAUR_ee_SM.txt_5_0_MG5_LO_ee_SM.txt"	,	"MG5 (LO)",
//			"outParams_2_initParams_2_5_0_BAUR_ee_SM.txt_5_0_MG5_NLO_ee_SM.txt"	,	"MG5 (NLO)"

//			"initParams/initParams_2_5_0_BAUR_mm_SM.txt"				,	"initParams",
//			"outParams_2_initParams_2_5_0_BAUR_mm_SM.txt_5_0_BAUR_mm_SM.txt"	,	"Monte Carlo (SM)"
			"outParams_2_initParams_2_5_0_BAUR_mm_SM_SIG.txt_5_0_BAUR_mm_SM.txt"	,	"Monte Carlo (SM 1)",
//			"outParams_2_initParams_2_5_0_BAUR_mm_NSM.txt_5_0_BAUR_mm_NSM.txt"	,	"Monte Carlo (NSM)"
//			"outParams_2_initParams_2_5_0_BAUR_mm_SM.txt_5_0_BAUR_mm_SM_GEN.txt"	,	"Monte Carlo (GEN Level)"
//			"outParams_2_initParams_2_5_0_BAUR_mm_SM.txt_5_0_Data_mm.txt"		,	"Data",
//			"outParams_2_initParams_2_5_0_BAUR_mm_SM.txt_5_0_BS_mm.txt"		,	"Monte Carlo (Signal + BG)",
//			"outParams_2_initParams_2_5_0_BS_mm.txt_5_0_BS_mm.txt"			,	"Monte Carlo (Signal + BG)"
//			"outParams_2_initParams_2_5_0_BAUR_mm_SM.txt_5_0_MG5_LO_mm_SM.txt"	,	"MG5 (LO)",
//			"outParams_2_initParams_2_5_0_BAUR_mm_SM.txt_5_0_MG5_NLO_mm_SM.txt"	,	"MG5 (NLO)"
	};


	int numOfFiles = (sizeof(list3) / sizeof(list3[0])) / 2;

	string list[2*numOfFiles];

	for (int i = 0; i < 2*numOfFiles; i++)
		list[i] = list3[i];

	cout << "Number of input files : " << (sizeof(list) / sizeof(list[0])) /2 << endl;

	int NPAR;

	map<int, vector<pair<double, double> > > parMap;

	for (int i = 0; i < (sizeof(list) / sizeof(list[0])) / 2; i++)
		{
		cout << "Working with file : " << list[2*i] << endl;
		params.push_back(readParams(list[2*i]));

		const int npar = params.back().size() / 2;
		NPAR = npar;

		double X[npar];
		double XE[npar];

		double axis[npar];
		double axisE[npar];

		for (int j = 0; j < npar; j++)
			{
			axis[j] = j;
			axisE[j] = 0;
			}

		for (int j = 0; j < npar; j++)
			{
//			X[j] = params.back().at(2*j) / params.back().at(0);
			X[j] = params.back().at(2*j);
//			cout << params.back().at(2*j) << " / " << params.back().at(0) << " = " << X[j] << endl;
//			XE[j] = params.back().at(2*j+1) / fabs(params.back().at(0));
			XE[j] = params.back().at(2*j+1);
//			cout << params.back().at(2*j+1) << " / " << params.back().at(0) << " = " << XE[j] << endl;

//			if (parMap.find(i) == parMap.end())
//				{
//				vector<pair<double, double> > parVec;
//				parVec.push_back(make_pair(X[j], XE[j]));
//				parMap[i] = parVec;
//				}
//			else parMap[i].push_back(make_pair(X[j]. XE[j]));
			parMap[i].push_back(make_pair(X[j], XE[j]));
			}

		TGraphErrors * gr = new TGraphErrors(npar, axis, X, axisE, XE);
		gr->SetLineColor(i+1);
		gr->SetMarkerStyle(4+i);
		gr->SetMarkerColor(i+1);

		leg->AddEntry(gr, (list[2*i+1]).c_str(), "lp");

		mg->Add(gr);
		}

	TCanvas * c1 = new TCanvas();

	tex->DrawLatex(0.18, 0.96, "CMS Preliminary, 2011");


//	tex->DrawLatex(0.18, 0.96, "CMS Preliminary, 2011, Electron Channel");
	tex->DrawLatex(0.18, 0.96, "CMS Preliminary, 2011, Muon Channel");
	tex->DrawLatex(0.8, 0.96, "#sqrt{s} = 7 TeV");


	mg->Draw("APE");

	for (int i = 0; i < NPAR; i++)
//		mg->GetXaxis()->SetBinLabel(6*(i+1), "#gamma_{T}");
		mg->GetXaxis()->SetBinLabel(5.4*(i+1), aplitudes[i].c_str());

//	mg->GetYaxis()->SetTitle("Parameter / T^{1}_{-1,-1,-1}");
	mg->GetYaxis()->SetTitle("Parameter Value");
	
	leg->Draw();

	c1->SaveAs("/afs/fnal.gov/files/home/room2/iraklich/public_html/ZGAMMA/MACROS/output/params.gif");

	if (numOfFiles == 2)
		for (int i = 0; i < NPAR; i++)
			{
			double diff = parMap[0].at(i).first - parMap[1].at(i).first;
			double sigma = parMap[0].at(i).second * parMap[0].at(i).second + parMap[1].at(i).second * parMap[1].at(i).second;
	
			cout << (diff*diff)/sigma << endl;
			}

	}
