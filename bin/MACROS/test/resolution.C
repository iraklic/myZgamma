#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void resolution()
	{
	TFile * myFile = new TFile("../input/histos_baur_tree.root");
	TTree * anglesTree = (TTree*) myFile->GetKey("angles")->ReadObj();
	TTree * mc_anglesTree = (TTree*) myFile->GetKey("mcangles")->ReadObj();

//	Declaration of leaf types
	Double_t        cosThetaL_cm;
	Double_t        cosThetaZ_cm;
	Double_t        phiL;
	Double_t        phiZ;

	Double_t        mc_cosThetaL_cm;
	Double_t        mc_cosThetaZ_cm;
	Double_t        mc_phiL;
	Double_t        mc_phiZ;

//	List of branches
	TBranch        *b_cosThetaL_cm;   //!
	TBranch        *b_cosThetaZ_cm;   //!
	TBranch        *b_phiL;   //!
	TBranch        *b_phiZ;   //!

	TBranch        *mc_b_cosThetaL_cm;   //!
	TBranch        *mc_b_cosThetaZ_cm;   //!
	TBranch        *mc_b_phiL;   //!
	TBranch        *mc_b_phiZ;   //!

//	fetching branches
	b_cosThetaL_cm = anglesTree->GetBranch("cosThetaL_cm");
	b_cosThetaZ_cm = anglesTree->GetBranch("cosThetaZ_cm");
	b_phiZ = anglesTree->GetBranch("phiZ");
	b_phiL = anglesTree->GetBranch("phiL");

	mc_b_cosThetaL_cm = mc_anglesTree->GetBranch("cosThetaL_cm");
	mc_b_cosThetaZ_cm = mc_anglesTree->GetBranch("cosThetaZ_cm");
	mc_b_phiZ = mc_anglesTree->GetBranch("phiZ");
	mc_b_phiL = mc_anglesTree->GetBranch("phiL");

//	linking branch to variable
	b_cosThetaL_cm->SetAddress(&cosThetaL_cm);
	b_cosThetaZ_cm->SetAddress(&cosThetaZ_cm);
	b_phiL->SetAddress(&phiL);
	b_phiZ->SetAddress(&phiZ);

	mc_b_cosThetaL_cm->SetAddress(&mc_cosThetaL_cm);
	mc_b_cosThetaZ_cm->SetAddress(&mc_cosThetaZ_cm);
	mc_b_phiL->SetAddress(&mc_phiL);
	mc_b_phiZ->SetAddress(&mc_phiZ);

	TH2F * hcosL = new TH2F("h1","cos#theta_{L}", 100, -1, 1, 100, -1, 1);
	TH2F * hcosZ = new TH2F("h2","cos#theta_{Z}", 100, -1, 1, 100, -1, 1);
	TH2F * hphiL = new TH2F("h3","#phi_{L}", 100, -3.14, 3.14, 100, -3.14, 3.14);
	TH2F * hphiZ = new TH2F("h4","#phi_{Z}", 100, -3.14, 3.14, 100, -3.14, 3.14);

	for (Long64_t jentry = 0; jentry < 5000; jentry++)
		{
		anglesTree->GetEntry(jentry);
		double cosL = cosThetaL_cm;
		double cosZ = cosThetaZ_cm;
		double phiL = phiL;
		double phiZ = phiZ;
		mc_anglesTree->GetEntry(jentry);
		double mc_cosL = mc_cosThetaL_cm;
		double mc_cosZ = mc_cosThetaZ_cm;
		double mc_phiL = mc_phiL;
		double mc_phiZ = mc_phiZ;

		hcosL->Fill(cosL, mc_cosL);
		cout << cosL << " - " << mc_cosL << endl;
		}
	hcosL->Draw();

	}
