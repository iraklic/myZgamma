#include "TFile.h"
#include "TTree.h"

void ClassMaker()
	{
	TFile *MyFile = new TFile("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/SKIMS/MG5/SM_mm_2jet/NTUPLE_MG5_SM_mm_2jets.root");

//	TFile *MyFile = new TFile("BAUR/Zmumug.root");


//	TTree* tree = (TTree*)MyFile->Get("DataTree");
	TTree* tree = (TTree*)MyFile->Get("EventTree");
//	TTree* tree = (TTree*)MyFile->Get("VgAnalyzerKit/EventTree");

	tree->MakeClass("Zg");

	MyFile->Close();
	}
