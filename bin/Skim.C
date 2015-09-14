#define Skim_cxx
#include "Skim.h"
#include <TH2.h>
#include <TStyle.h>
#include <iostream>
//#include <stdio>
#include <string>
#include <TLorentzVector.h>
#include "TROOT.h"
#include "TMath.h"
#include "TFile.h"
#include "TTree.h"
#include "TH2.h"


void Skim::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L Skim.C
//      Root > Skim t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

	int electronID = 11;
	int photonID = 12;
//	int nBunches = nBunches_CONDOR;
//	int currBunch = currBunch_CONDOR;
	Long64_t nentries = fChain->GetEntriesFast();
	Long64_t startEntry = 0;
//	if (last_batch < last_batch_CONDOR)
//		{
//		double bunchSize = nentries / nBunches;
//		startEntry = nentries * currBunch;
//		nentries = startEntry + bunchSize;
//		}
	TFile *newFile = new TFile("skim.root","recreate");
	TChain *newchain = (TChain*)fChain->CloneTree(0);
	TTree *newTree = newchain->GetTree();
    
    
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
//	if (jentry < startEntry) continue;
	if ((ientry % 2000) == 0)
		{
		float perc = float(ientry)*100./float(nentries);
		printf("Processed Events 		%i	 out of %i 	%.0f %%\n",int(ientry), int (nentries), perc);
		}

		float dRcut = 0.7; 
		float phoEtCut = 10;
		float lepPtCut = 15;
		vector<int> cleanPho;
		vector<int> cleanEle;
		vector<int> cleanMu;

//		if (nVtx == 0) continue;
//		if (IsVtxGood == 0) continue;
//		if (IsTracksGood == 0) continue;
/*
		for (int iPho=0; iPho < nPho; iPho++)
			{
//			ET cut
			if (phoEt[iPho] < phoEtCut)	continue;
			if (fabs(phoSCEta[iPho])> 2.5)	continue;
			if (fabs(phoSCEta[iPho]) > 1.4442 && fabs(phoSCEta[iPho]) < 1.566 ) continue;
			if (phoHoverE[iPho] > 0.5 )	continue;
//			if (phoOverlap[iPho] == 1)	continue;
			if (phohasPixelSeed[iPho] == 1)	continue;
			cleanPho.push_back(iPho);
			}
		if (cleanPho.size() == 0) continue;

		for (int iEle=0; iEle < nEle; iEle++)
			{

			if (elePt[iEle] < lepPtCut) continue;
			if (fabs(eleSCEta[iEle]) > 2.5 || ( fabs(eleSCEta[iEle]) > 1.4442 && fabs(eleSCEta[iEle]) < 1.566) ) continue;

			cleanEle.push_back(iEle);
			}

		for (int iMu=0; iMu < nMu; iMu++)
			{
			if (muPt[iMu] < lepPtCut) continue;
			if (fabs(muEta[iMu]) > 2.4 ) continue;
			if (muType[iMu] != 14) continue; // isGlobal && Tracker
			cleanMu.push_back(iMu);
			}
		if (cleanEle.size() < 2 && cleanMu.size() < 2) continue;
*/    

		newTree->Fill();
       }
      newFile->cd();
      newTree->Write();
      newFile->Close();
      }

      