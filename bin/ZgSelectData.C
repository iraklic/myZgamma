#define ZgSelectData_cxx
#include "ZgSelectData.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <fstream>
#include <TTree.h>      
#include <TLorentzVector.h>
#include <TH2D.h>
#include <TString.h>
#include <iomanip>
#include <TClonesArray.h>
#include <vector>
#include <time.h>

void ZgSelectData::printEvent(int index_e1, int index_e2, int index_pho, vector<Float_t> elePt_){
	cout << "PassedZeeGamma: run " << run << " event " << event << " rho " << rho << endl ;
	cout << "electron :index,pt,eta,phi,En " << endl ;
	cout << index_e1 << " , " << elePt_[index_e1] << " , " << eleEta[index_e1] ;
	cout << " , " << elePhi[index_e1] << " , " << eleEn[index_e1] << endl ;
	cout << index_e2 << " , " << elePt_[index_e2] << " , " << eleEta[index_e2] ;
	cout << " , " << elePhi[index_e2] << " , " << eleEn[index_e2] << endl ;

	cout << "Electron Pass " << endl ;
	cout << "TrackIso " << eleIsoTrkDR03[index_e1] << " EcalIso " << eleIsoEcalDR03[index_e1] << " HcalSolidIso ";
	cout << eleIsoHcalSolidDR03[index_e1] << " passID = " << elePassID(index_e1,3,elePt_) << endl ;
	cout << "TrackIso " << eleIsoTrkDR03[index_e2] << " EcalIso " << eleIsoEcalDR03[index_e2] << " HcalSolidIso ";
	cout << eleIsoHcalSolidDR03[index_e2] << " passID = " << elePassID(index_e2,3,elePt_) <<  endl ;
	TLorentzVector ve1, ve2, vZ ;
	ve1.SetPtEtaPhiE(elePt[index_e1],eleEta[index_e1],elePhi[index_e1],eleEn[index_e1]);
	ve2.SetPtEtaPhiE(elePt[index_e2],eleEta[index_e2],elePhi[index_e2],eleEn[index_e2]);
	vZ = ve1 + ve2 ;
	
	cout << "ZMass = " << vZ.M() << endl ;

	cout << "Photon : index, pt, eta, phi, dr1, dr2 " << endl ;
	TLorentzVector vp ;
	vp.SetPtEtaPhiM(phoEt[index_pho],phoEta[index_pho],phoPhi[index_pho],0);
	cout << index_pho << " , " << vp.Pt() << " , " << vp.Eta() << " , " << vp.Phi() ;
	cout << " , " << vp.DeltaR(ve1) << " , " << vp.DeltaR(ve2) << endl ;
	cout << "=================================================================" << endl ;

}

Float_t getCorrection(Float_t En_, 
Float_t scEta , Float_t R9_, Int_t run_,
Int_t option =  0){
	//option - 0, defaule , 1, + uncertainty, -1 - uncertainty
	Float_t myEn = En_ ;
	Int_t cat = 0; 
	if (fabs(scEta) < 1.44442 ){
		if ( R9_ > 0.94 ) cat = 0 ;
		else cat = 1 ;
	} else {
		if ( R9_ > 0.94 ) cat = 2 ;
		else cat = 3 ;
	}
	// categgory : 
	// 0 : EB (R9>0.94) 1 : EB (R9<0.94)
	// 2 : EB (R9>0.94) 3 : EB (R9<0.94)
	Float_t scale[][4] = // [run][class]
	{
		{ 0.47  , -0.25 , -0.58 , 0.10  },
		{ 0.07  , -0.49 , -2.49 , -0.62 },
		{ -0.03 , -0.67 , -3.76 , -1.33 },
		{ -0.11 , -0.63 , -4.50 , -1.78 },
		{ -0.14 , -0.74 , -5.61 , -2.73 },
		{ 0.00  , 0.00  , -0.11 , -0.06 }
	};
	Float_t error[][4] = // [run][category]
	{
		{ 0.05  , 0.04 , 0.19 , 0.16 },
		{ 0.07  , 0.04 , 0.22 , 0.18 },
		{ 0.06  , 0.04 , 0.19 , 0.15 },
		{ 0.06  , 0.04 , 0.20 , 0.15 },
		{ 0.05  , 0.03 , 0.18 , 0.13 },
		{ 0.04  , 0.02 , 0.09 , 0.07 }
	};
	Int_t iRun = -1 ;
	if      ( run_ >= 160431 && run_ <= 163869 ) iRun = 0 ;
	else if ( run_ >= 165071 && run_ <= 165970 ) iRun = 1 ;
	else if ( run_ >= 165971 && run_ <= 166502 ) iRun = 2 ;
	else if ( run_ >= 166503 && run_ <= 166861 ) iRun = 3 ;
	else if ( run_ >= 166862 && run_ <= 167784 ) iRun = 4 ;
//	if ( run_ >= 160431 && run_ <= 167784 ) iRun = 0 ;
	if ( iRun == -1 ) return En_ ;
	myEn = En_ * ( 1. - ( 0.01 * ( scale[iRun][cat] + option * error[iRun][cat] ) ) ) ;
//	myEn = En_ * ( 1. - ( 0.01 *  scale[iRun][cat]  ) ) ;
//	cout << "before " << En_ << " after " << myEn << " run " << run_ << " iRun " << iRun << " class " << cat << endl ;
	return myEn ;
}
vector<Float_t> ZgSelectData::newEleEn(){
	vector<Float_t> _eleEn ;
	float corrEn(0.);
	for (int i = 0; i < nEle; i++){
		Float_t r9 = eleE3x3[i] / eleSCRawEn[i] ;
		corrEn = getCorrection(eleEn[i],eleSCEta[i],r9,run);
		_eleEn.push_back(corrEn);
	}
	return _eleEn ;
}
vector<Float_t> ZgSelectData::newPhoEn(){
	vector<Float_t> _phoEn ;
	float corrEn(0.);
	for (int i = 0; i < nPho; i++){
		corrEn = getCorrection(phoE[i],phoSCEta[i],phoR9[i],run);
		_phoEn.push_back(corrEn);
	}
	return _phoEn ;
}
vector<Float_t> ZgSelectData::newElePt(vector<Float_t> EnCorr){
	float theta ;
	vector<Float_t> _elePt ;
	unsigned int nnEle = nEle ;
	for (int i = 0; i < nEle; i++){
		if ( nnEle == EnCorr.size() ){
			theta = 2. * atan(exp(-eleEta[i]));
			_elePt.push_back( fabs(sin(theta)) * EnCorr[i] );
		}
		else {
			_elePt.push_back(elePt[i]) ;
		}
	}
	return _elePt ;
}
vector<Float_t> ZgSelectData::newPhoEt(vector<Float_t> EnCorr){
	float theta ;
	vector<Float_t> _phoPt ;
	unsigned int nnEle = nEle ;
	for (int i = 0; i < nPho; i++){
		if ( nnEle == EnCorr.size() ){
			theta = 2. * atan(exp(-phoEta[i]));
			_phoPt.push_back( fabs(sin(theta)) * EnCorr[i] );
		}
		else {
			_phoPt.push_back(phoEt[i]) ;
		}
	}
	return _phoPt ;
}

void ZgSelectData::Loop(Int_t eleID_index, Int_t phoID_index, Float_t DelRCut, Float_t ZMassCutL, Float_t ZMassCutU)
{
   FILE * fZeegammaOut ;
	fZeegammaOut  = fopen(Form("ZeegammaList.txt"),"w");
	Double_t phoEtV2,phoEtaV2,a_phoEt,a_phoEta,a_Mee,a_Meeg,phoSeedTime_;

//	TNtuple *NTMass = new TNtuple("ntuple_mass","mll:mllg");

	//photonID table

	TString phoID_String[]={"Poter's95","Poter's90","Poter's85","RS-Ming","Poter's70","Poter's60","EG Loose","EG Tight","QCD photon"
	,"MIT","Roma","RS-Ming"};
	TString eleID_String[]={"HWWRelIso60","HWWRelIso70","HWWRelIso80","HWWRelIso85","HWWRelIso90","HWWRelIso95",
	"RelIso60","RelIso70","RelIso80","RelIso85","RelIso90","RelIso95",
	"HWWRelIso60","HWWRelIso70","HWWRelIso80","HWWRelIso85","HWWRelIso90","HWWRelIso95"};

	//Some Cuts
	Int_t NPhoLeft=0;
	Float_t  ElePtCut=20,PhoPtCut=15;
	//Upper and Lower cuts for anti-selection(use for bgk)
	Float_t  PhoHoverPreCut=0.5;

	//Some Variables
	Int_t 	  EID_Level[100];
	Int_t     nWrite=0;   
	Int_t     PhoInEE=0, Ele1InEE=0, Ele2InEE=0;
	Int_t     Ele_num=0;
	Int_t     PassEID[100];
	Int_t     ele1_index=0, ele2_index=0, pho_index=0;
	Int_t     iCheck[10]={0,0,0,0,0,0,0,0,0,0};

	Float_t   Leading1=0, Leading2=0;
	Float_t   ThisValue=0;
	Float_t   MZee=0;
	Float_t   MC_dPhi=0, MC_dEta=0, DelR1=0, DelR2=0;

	Double_t  MaxPhoEt(0) , MaxZee(0), MaxZeeg(0);
	TLorentzVector ele1,ele2,gamma,Zee,Mllg;

	//Histograms..

	clock_t start, end ;
	start = clock();

	if (fChain == 0) return;
	cout << "Total events need to run : " << fChain->GetEntries() << endl ;
	Long64_t nTest1=0,nTest2=0,nTest3=0;

	Long64_t nentries = fChain->GetEntriesFast();

	Long64_t nbytes = 0, nb = 0;
	//Long64_t ThisRun=9999999;
	Int_t GoodVtx=0;
	for (Long64_t jentry=0; jentry<nentries;jentry++) {
		Long64_t ientry = LoadTree(jentry);
		if (ientry < 0) break;
		nb = fChain->GetEntry(jentry);   nbytes += nb;
		
		// if (Cut(ientry) < 0) continue;
		//if (nWrite>=1) break;
		if ( run > 166861 ) continue ;
		GoodVtx=0;
		//      if (jentry % 1000000 ==1) cout<<jentry<<endl;
		iCheck[0]++;
		for (Int_t iVtx=0;iVtx<nVtx;iVtx++){
			if (vtxNDF[iVtx] > 4 && fabs(vtx[iVtx][2]) <= 24 && vtxD0[iVtx] <= 2) GoodVtx++;
		}
		if (GoodVtx<1) continue;
		if (IsVtxGood ==0 ) continue;
		if (IsTracksGood ==0 ) continue;
		// electron and photon energy correction
		vector<Float_t> eleEn_ ;
		vector<Float_t> phoE_  ;
		vector<Float_t> elePt_ ;
		vector<Float_t> phoEt_ ;
		eleEn_.clear();
		phoE_.clear();
		elePt_.clear();
		phoEt_.clear();
		eleEn_ = newEleEn() ;
		phoE_  = newPhoEn() ;
		elePt_ = newElePt(eleEn_) ;
		phoEt_ = newPhoEt(phoE_ ) ;
		iCheck[1]++;
		Int_t eleTrg_index = -1;
		phoEtV2   = -999;
		phoEtaV2  = -999;
		a_phoEt  = -999;
		a_phoEta = -999;
		a_Mee    = -999;
		a_Meeg   = -999;
		phoSeedTime_ = -9999;

		if (HLTIndex[121] >= 0){ // HLT_Ele17_CaloIdL_CaloIsoVL_Ele8_CaloIdL_CaloIsoVL_v1
			if ( HLT[HLTIndex[121]] != 1 ) continue ;
			eleTrg_index = 20 ;
		}
		else
		if (HLTIndex[122] >= 0){ // HLT_Ele17_CaloIdL_CaloIsoVL_Ele8_CaloIdL_CaloIsoVL_v2
			if ( HLT[HLTIndex[122]] != 1 ) continue ;
			eleTrg_index = 21 ;
		}
		else
		if (HLTIndex[123] >= 0){ // HLT_Ele17_CaloIdL_CaloIsoVL_Ele8_CaloIdL_CaloIsoVL_v3
			if ( HLT[HLTIndex[123]] != 1 ) continue ;
			eleTrg_index = 22 ;
		}
		else
		if (HLTIndex[124] >= 0){ // HLT_Ele17_CaloIdL_CaloIsoVL_Ele8_CaloIdL_CaloIsoVL_v4
			if ( HLT[HLTIndex[124]] != 1 ) continue ;
			eleTrg_index = 23 ;
		}
		else
		if (HLTIndex[125] >= 0){ // HLT_Ele17_CaloIdL_CaloIsoVL_Ele8_CaloIdL_CaloIsoVL_v5
			if ( HLT[HLTIndex[125]] != 1 ) continue ;
			eleTrg_index = 24 ;
		}
		else {
			continue ;
		}

		if (eleTrg_index == -1 ) continue ;
		iCheck[2]++;
		for (Int_t ii=0;ii<100;ii++) {
			PassEID[ii]=-1;
			EID_Level[ii] = 0 ;
		}
		
		iCheck[3]++ ;

		Ele_num=0;//1
		Ele1InEE=-1, Ele2InEE=-1, PhoInEE=-1;
		for (Int_t iEle=0;iEle<nEle;iEle++){
			if ( fabs(eleSCEta[iEle])          > 2.5                                    ) continue;
			if ( fabs(eleSCEta[iEle])          > 1.4442 && fabs(eleSCEta[iEle]) < 1.566 ) continue;
			if ( fabs(eleSCEta[iEle])          < 1.4442                                 ) {
				if(eleSigmaIEtaIEta[iEle]      < 0.002) continue;
			}
			if ( fabs(eleSCEta[iEle])          <= 1.4442 ) Ele1InEE = 0;
			else if (fabs(eleSCEta[iEle])      <= 2.5 && fabs(eleSCEta[iEle])>=1.566) Ele1InEE = 1;
			// Electron ID and trigger
			if (elePassID(iEle,eleID_index,elePt_) ){
				EID_Level[iEle]++ ;
				if ( eleTrg[iEle][eleTrg_index] == 1 ) {
					EID_Level[iEle]++ ;
				}
			}
			if (EID_Level[iEle] >= 2 ) Ele_num++;
		}

		MZee=0;
		Ele1InEE=-1, Ele2InEE=-1, PhoInEE=-1;
		if (Ele_num < 2 ) continue ;

		// Select 2 leading electrons
		if (Ele_num>=2) {
			//pass the Z mass cut, no cut for now... 
			Leading1=-1,Leading2=-1;
			ele2_index=-1,ele1_index=-1;
			for (Int_t i1=0; i1<nEle; i1++){
				int pre_Index1 = ele1_index ;
				int pre_Index2 = ele2_index ;
				if (elePt_[i1]>Leading1 && elePt_[i1]>Leading2) {
					Leading2=Leading1;
					ele2_index=ele1_index;

					Leading1=elePt_[i1];
					ele1_index=i1;     
				} else if (elePt_[i1]<Leading1 && elePt_[i1]>Leading2) {
					Leading2=elePt_[i1];
					ele2_index=i1;
				}
				// judge if this pair will pass selection
				if (ele1_index != -1 && ele2_index != -1){
					if ( ( EID_Level[ele1_index] + EID_Level[ele2_index] < 4) ||
						 elePt_[ele1_index] < ElePtCut  || elePt_[ele2_index] < ElePtCut 
					   )
					{
						ele1_index = pre_Index1 ;
						ele2_index = pre_Index2 ;
					}
				}
			}
			if (ele1_index != -1 && ele2_index != -1){
				ele1.SetPtEtaPhiE(elePt_[ele1_index],eleEta[ele1_index],elePhi[ele1_index],eleEn_[ele1_index]);
				ele2.SetPtEtaPhiE(elePt_[ele2_index],eleEta[ele2_index],elePhi[ele2_index],eleEn_[ele2_index]);
				Zee=ele1+ele2;
				MZee=Zee.M();
			} else {
				MZee = 0. ;
			}
		}
		if (ele1_index == -1 || ele2_index == -1) continue ;
			iCheck[4]++ ;

		if (MZee > ZMassCutL && MZee < ZMassCutU) {
				iCheck[8]++;
			iCheck[5]++;

			//Photon selection

			pho_index=-1;
			ThisValue=0;
			NPhoLeft =0;
			bool flagPhoID = false ;
			for (Int_t iPho=0;iPho<nPho;iPho++){
				if (phoEt_[iPho] < PhoPtCut) continue;
				if (fabs(phoSCEta[iPho]) > 2.5) continue;
				if (fabs(phoSCEta[iPho]) > 1.4442 && fabs(phoSCEta[iPho]) < 1.566 ) continue;
				if (phohasPixelSeed[iPho] == 1) continue;
				if (phoHoverE[iPho] > PhoHoverPreCut) continue;

				if (fabs(phoSCEta[iPho]) < 1.4442) {
					if (phoSigmaIEtaIEta[iPho]<0.002) continue;
				}

				if ( fabs(phoSCEta[iPho]) < 1.4442 ) PhoInEE = 0;
				else if (fabs(phoSCEta[iPho])<2.5 && fabs(phoSCEta[iPho])>1.566) PhoInEE = 1;

				if (PhoInEE != 1 && PhoInEE != 0) continue ;
				if (!phoPassID(iPho,3,phoEt_)) continue ;
				flagPhoID = true ;
				MC_dPhi=0.0;
				MC_dEta=0.0;
				DelR1=0.0;

				MC_dPhi = phoPhi[iPho] - elePhi[ele1_index];
				if (MC_dPhi >  3.1415927) MC_dPhi -= 2*3.1415927;
				if (MC_dPhi < -3.1415927) MC_dPhi += 2*3.1415927;
				MC_dEta = phoEta[iPho] - eleEta[ele1_index];
				DelR1=sqrt(MC_dEta*MC_dEta + MC_dPhi*MC_dPhi);

				MC_dPhi=0.0;
				MC_dEta=0.0;
				DelR2=0.0;

				MC_dPhi = phoPhi[iPho] - elePhi[ele2_index];
				if (MC_dPhi >  3.1415927) MC_dPhi -= 2*3.1415927;
				if (MC_dPhi < -3.1415927) MC_dPhi += 2*3.1415927;
				MC_dEta = phoEta[iPho] - eleEta[ele2_index];
				DelR2=sqrt(MC_dEta*MC_dEta + MC_dPhi*MC_dPhi);

				if (DelR1 < DelRCut || DelR2 < DelRCut) continue;
				if (ThisValue < phoEt_[iPho]){
					NPhoLeft++;
					ThisValue = phoEt_[iPho];
					pho_index = iPho;
				}
			}

			if (flagPhoID)	iCheck[6]++;
			if (pho_index!=-1) {
				if ( fabs(phoSCEta[pho_index]) < 1.4442 ) PhoInEE = 0;
				else if (fabs(phoSCEta[pho_index]) < 2.5 && fabs(phoSCEta[pho_index]) > 1.566) PhoInEE = 1;

				ele1.SetPtEtaPhiE(elePt_[ele1_index],eleEta[ele1_index],elePhi[ele1_index],eleEn_[ele1_index]);
				ele2.SetPtEtaPhiE(elePt_[ele2_index],eleEta[ele2_index],elePhi[ele2_index],eleEn_[ele2_index]);
				gamma.SetPtEtaPhiE(phoEt_[pho_index],phoEta[pho_index],phoPhi[pho_index],phoE_[pho_index]);

				Zee=ele1+ele2;
				Mllg=ele1+ele2+gamma;
				//Fill Pho2 & Meeg1

//				overFlowFill(hMeeg[0],Mllg.M(),EvtWeight);

				MC_dPhi=0.0;
				MC_dEta=0.0;
				DelR1=0.0;

				MC_dPhi = phoPhi[pho_index] - elePhi[ele1_index];
				if (MC_dPhi >  3.1415927) MC_dPhi -= 2*3.1415927;
				if (MC_dPhi < -3.1415927) MC_dPhi += 2*3.1415927;
				MC_dEta = phoEta[pho_index] - eleEta[ele1_index];
				DelR1=sqrt(MC_dEta*MC_dEta + MC_dPhi*MC_dPhi);

				MC_dPhi=0.0;
				MC_dEta=0.0;
				DelR2=0.0;

				MC_dPhi = phoPhi[pho_index] - elePhi[ele2_index];
				if (MC_dPhi >  3.1415927) MC_dPhi -= 2*3.1415927;
				if (MC_dPhi < -3.1415927) MC_dPhi += 2*3.1415927;
				MC_dEta = phoEta[pho_index] - eleEta[ele2_index];
				DelR2=sqrt(MC_dEta*MC_dEta + MC_dPhi*MC_dPhi);

				if (DelR1> DelRCut && DelR2>DelRCut){
				
//					NTMass->Fill(Mllg.M(),Zee.M());
					iCheck[7]++;
					printEvent(ele1_index,ele2_index,pho_index,elePt_) ;

					if (MaxPhoEt < phoEt_[pho_index]) MaxPhoEt = phoEt_[pho_index] ;
					if (phoEt_[pho_index] > 150. ){
						cout << "checkEvent " << "nPho " << nPho ;
						cout << " " << phoEt_.size() << " " << " " << phoE_.size() ;
						cout << " phoEt " << phoEt[pho_index] << " " << phoEt_[pho_index] ;
						cout << " phoE  " << phoE[pho_index] << " " << phoE_[pho_index] << endl ;
					}
					if (MaxZee < Zee.M() ) MaxZee = Zee.M() ;
					if (MaxZeeg < Mllg.M() ) MaxZeeg = Mllg.M() ;

					nWrite++;
					phoEtV2  = phoEt_[pho_index];
					phoEtaV2 = phoEta[pho_index];
					phoSeedTime_ = phoSeedTime[pho_index];
//					tree_->Fill();

					cout<<"#Zgamma:"<<setw(3)<<nWrite<<setw(8)<<"run:"<<setw(7)<<run<<setw(10)<<"event:"<<setw(12)<<event<<setw(12)<<"lumis:"<<setw(5)<<lumis<<endl;
					cout<<"  ele1:"<<elePt_[ele1_index]<<","<<eleEta[ele1_index]<<",ele2:"<<elePt_[ele2_index]<<","<<eleEta[ele2_index]<<",pho:"<<phoEt_[pho_index]<<","<<phoEta[pho_index]<<","<<Zee.M()<<","<<Mllg.M()<<",phoSeedTime:"<<phoSeedTime[pho_index]<<",nPho:"<<NPhoLeft<<endl;
					fprintf(fZeegammaOut ,"#Zgamma: %d run %d event %d lumi %d\n" , nWrite , run , event , lumis ) ;
					//               for (Int_t iHLT=0;iHLT<20;iHLT++) cout<<"   iHLT:"<<iHLT<<":"<<HLTIndex[iHLT]<<endl;
				}
			}

		}

	}

	float passRatio[8] = { 0. } ;
	for (int i = 0; i < 7; i++){
		passRatio[i] = (iCheck[i]==0) ? 0. : float(1.0*iCheck[i+1]/iCheck[i]) ;
	}
	cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	cout<<"Selection information:"<<endl;
	cout<<"elePt         : Pt > "<< ElePtCut  <<"  ,eleID:" << eleID_String[eleID_index] << endl;
	cout<<"phoPt         : Pt > "<< PhoPtCut  <<"  ,phoID:" << phoID_String[phoID_index] << endl;
	cout<<"Z mass window : "     << ZMassCutL <<" < MZee < "<< ZMassCutU << endl;
	cout<<"deltaR        : dR > "<< DelRCut   <<endl;
	cout<<"Total event   : "<<iCheck[0]<<"  "<<1.<<endl;
	cout<<"Pass  event   : "<<iCheck[1]<<"  "<<passRatio[0]<<endl;
	cout<<"Pass  HLT     : "<<iCheck[2]<<"  "<<passRatio[1]<<endl;
	cout<<"Fired elec    : "<<iCheck[3]<<"	"<<passRatio[2]<<endl ;
	cout<<"Pass  EleID   : "<<iCheck[4]<<"  "<<passRatio[3]<<endl;
	cout<<"Pass  mass    : "<<iCheck[5]<<"  "<<passRatio[4]<<endl;
	cout<<"Pass  PhoID   : "<<iCheck[6]<<"  "<<passRatio[5]<<endl;
	cout<<"Pass  dR      : "<<iCheck[7]<<"  "<<passRatio[6]<<endl;
	cout<<"Found Zee+gamma candidades:"<<nWrite<<endl;
	cout<<"Max phoEt     : "<< MaxPhoEt << endl ;
	cout<<"Max phoZee    : "<< MaxZee << endl ;
	cout<<"Max phoZeeg   : "<< MaxZeeg << endl ;
	cout<<"ZMass pairs   : "<<iCheck[8]<<endl ;
	//cout<<ThisRun<<endl;
	cout<<"Save Anti:"<<nTest1<<",Zg:"<<nTest2<<",All:"<<nTest3<<endl;
	cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	
	fclose (fZeegammaOut ) ;

	end = clock();
	double dif = (double)( end - start) / CLOCKS_PER_SEC ;
	cout << "Execute time = " << dif << " s" << endl ;
}

Bool_t ZgSelectData::elePassID(int index_e , int index_eID, vector<Float_t> elePt_){
	Bool_t passID = false ;
	//index_eID 0: wp
	int BE =  ( fabs(eleSCEta[index_e]) < 1.4442) ? 0 : 1 ;
	if (eleConvMissinghit[index_e] != 0) return passID ;
	//ID [WP95,WP90,WP85,WP80,WP70,WP60][Dist,Dcot,cIso,SIEIE,dPhiIn,dEtaIn]
	Double_t cutEB[6][6] = { 
							 {0.02,0.02, 0.016 ,0.01  ,0.02  ,0.004},
							 {0.02,0.02, 0.03  ,0.01  ,0.02  ,0.004},
							 {0.02,0.02, 0.04  ,0.01  ,0.027 ,0.005},
							 {0.02,0.02, 0.053 ,0.01  ,0.039 ,0.005},
							 {0.,0., 0.085 ,0.01  ,0.071 ,0.007},
							 {0.,0., 0.15  ,0.012 ,0.8   ,0.007}
	};
	Double_t cutEE[6][6] = { 
							 {0.02,0.02, 0.008 ,0.031 ,0.021 ,0.004},
							 {0.02,0.02, 0.016 ,0.031 ,0.021 ,0.005},
							 {0.02,0.02, 0.033 ,0.031 ,0.021 ,0.006},
							 {0.02,0.02, 0.042 ,0.031 ,0.028 ,0.007},
							 {0.,0., 0.051 ,0.031 ,0.047 ,0.011},
							 {0.,0., 0.1   ,0.031 ,0.7   ,0.011}
	};
	float cIso = 100. ;
	// calculate cIso
	if ( fabs(eleSCEta[index_e] < 1.4442) ){
		cIso = ( eleIsoTrkDR03[index_e] + TMath::Max(eleIsoEcalDR03[index_e]-1.,0.) + eleIsoHcalSolidDR03[index_e] - rho*TMath::Pi()*0.3*0.3) / elePt_[index_e];
	}
	else cIso = ( eleIsoTrkDR03[index_e] + eleIsoEcalDR03[index_e] + eleIsoHcalSolidDR03[index_e] - rho*TMath::Pi()*0.3*0.3) / elePt_[index_e];
	// ID 
	if (BE == 0){
		passID = ( (fabs(eleConvDist[index_e]) > cutEB[index_eID][0] || 
		fabs(eleConvDcot[index_e]) > cutEB[index_eID][1]) &&
		cIso < cutEB[index_eID][2] &&
		eleSigmaIEtaIEta[index_e] < cutEB[index_eID][3] &&
		fabs(eledPhiAtVtx[index_e]) < cutEB[index_eID][4] &&
		fabs(eledEtaAtVtx[index_e]) < cutEB[index_eID][5] ) ;
	} else if (BE == 1){
		passID = ( (fabs(eleConvDist[index_e]) > cutEE[index_eID][0] || 
		fabs(eleConvDcot[index_e]) > cutEE[index_eID][1]) &&
		cIso < cutEE[index_eID][2] &&
		eleSigmaIEtaIEta[index_e] < cutEE[index_eID][3] &&
		fabs(eledPhiAtVtx[index_e]) < cutEE[index_eID][4] &&
		fabs(eledEtaAtVtx[index_e]) < cutEE[index_eID][5] ) ;
	}
	return passID ;
}

Bool_t ZgSelectData::phoPassID(int index_g , int index_gID, vector<Float_t> phoEt_){
	bool flag = false ;
	int BE =  ( fabs(phoSCEta[index_g]) < 1.4442) ? 0 : 1 ;
//	BE =  ( fabs(phoSCEta[index_g]) > 1.56 && fabs(phoSCEta[index_g]) < 2.5 ) ? 1 : -1 ;
	if (phoOverlap[index_g] != 0) return flag ;

	double ecalIso = phoEcalIsoDR04[index_g] ;
	double hcalIso = phoHcalIsoDR04[index_g] ;
	double trkIso =  phoTrkIsoHollowDR04[index_g] ;
	double hovere =  phoHoverE[index_g] ;
	Double_t PhoIDScale[][3] = {
		{0.006,0.0025,0.001},
		{0.006,0.0025,0.001},
		{0.006,0.0025,0.001},
		{0.006,0.0025,0.001}
	};
	// photonID [scaled EcalIso, scaled HcalIso, 
	// scaled TrkIsoHollowd, h/e, sigmaIEtaIEta, 
	// ,etaWidth, phiWidth]
	Double_t cutEB[][7] = {
		{4.2,2.2,2.0,0.05,0.013 , 999., 999.} ,
		{2.0,2.0,1.5,0.02,0.01 , 999., 999.} ,
		{1.59, 1.5, 0.834 , 0.0196,0.01 , 999., 999.} ,
		{4.2,2.2,2.0,0.05,0.011 , 999., 999.} 
		};
	Double_t cutEE[][7] = {
		{4.2,2.2,2.0,0.05 ,0.03 ,999., 999. } ,
		{2.0,2.0,1.5,0.02 ,0.028 ,999., 999. } ,
		{0.832, 1.25, 0.887, 0.0195 ,0.028 ,999., 999. } ,
		{4.2,2.2,2.0,0.05 ,0.03 ,999., 999. } 
		};

	switch(index_gID){
		case 3: // RS-Ming
			if (BE == 0){
				trkIso  -= 0.167 * rho ;
				ecalIso -= 0.183 * rho ;
				hcalIso -= 0.062 * rho ;
				flag =          ( ecalIso - PhoIDScale[index_gID][0]*phoEt_[index_g] < cutEB[index_gID][0] ) ;
				flag = (flag) ? ( hcalIso - PhoIDScale[index_gID][1]*phoEt_[index_g] < cutEB[index_gID][1] ) : false ;
				flag = (flag) ? ( trkIso -  PhoIDScale[index_gID][2]*phoEt_[index_g] < cutEB[index_gID][2] ) : false ;
				flag = (flag) ? ( hovere                                            < cutEB[index_gID][3] ) : false ; 
				flag = (flag) ?  ( phoSigmaIEtaIEta[index_g]                        < cutEB[index_gID][4] ) : false ;
				return flag ;
			} else if (BE == 1){
				trkIso  -=  0.032 * rho ;
				ecalIso -=  0.090 * rho ;
				hcalIso -=  0.180 * rho ;
				flag =          ( ecalIso - PhoIDScale[index_gID][0]*phoEt_[index_g] < cutEE[index_gID][0] ) ;
				flag = (flag) ? ( hcalIso - PhoIDScale[index_gID][1]*phoEt_[index_g] < cutEE[index_gID][1] ) : false ;
				flag = (flag) ? ( trkIso -  PhoIDScale[index_gID][2]*phoEt_[index_g] < cutEE[index_gID][2] ) : false ;
				flag = (flag) ? ( hovere                                            < cutEE[index_gID][3] ) : false ;
				flag = (flag) ?  ( phoSigmaIEtaIEta[index_g]                        < cutEE[index_gID][4] ) : false ;
				return flag ;
			}
			break ;
		case 2: // RomaIso
			if (BE == 0){
				trkIso -= 0.548 * rho ;
				ecalIso -= 0.299 * rho ;
				hcalIso -= 0.245 * rho ;
				hovere -= 0.001 * rho ;
				flag =          ( ecalIso - PhoIDScale[index_gID][0]*phoEt_[index_g] < cutEB[index_gID][0] ) ;
				flag = (flag) ? ( hcalIso - PhoIDScale[index_gID][1]*phoEt_[index_g] < cutEB[index_gID][1] ) : false ;
				flag = (flag) ? ( trkIso -  PhoIDScale[index_gID][2]*phoEt_[index_g] < cutEB[index_gID][2] ) : false ;
				flag = (flag) ? ( hovere                                            < cutEB[index_gID][3] ) : false ; 
				return flag ;
			} else if (BE == 1){
				trkIso -= 0.525 * rho ;
				ecalIso -= 0.192 * rho ;
				hcalIso -= 0.275 * rho ;
				hovere -= 0.001 * rho ;
				flag =          ( ecalIso - PhoIDScale[index_gID][0]*phoEt_[index_g] < cutEE[index_gID][0] ) ;
				flag = (flag) ? ( hcalIso - PhoIDScale[index_gID][1]*phoEt_[index_g] < cutEE[index_gID][1] ) : false ;
				flag = (flag) ? ( trkIso -  PhoIDScale[index_gID][2]*phoEt_[index_g] < cutEE[index_gID][2] ) : false ;
				flag = (flag) ? ( hovere                                            < cutEE[index_gID][3] ) : false ;
				return flag ;
			}
			break ;
		case 1: // MIT HWW
			if (BE == 0){
				if ( rho > -0.5 ){
					double fEffAreaEcalEB(0.162);
					double fEffAreaHcalEB(0.042);
					double fEffAreaTrkEB(0.317);
					ecalIso -= rho * fEffAreaEcalEB ;
					hcalIso -= rho * fEffAreaHcalEB ;
					trkIso  -= rho * fEffAreaTrkEB  ;
				}
				flag =           ( ecalIso - PhoIDScale[index_gID][0]*phoEt_[index_g] < cutEB[index_gID][0] ) ;
				flag = (flag) ?  ( hcalIso - PhoIDScale[index_gID][1]*phoEt_[index_g] < cutEB[index_gID][1] ) : false ;
				flag = (flag) ?  ( trkIso -  PhoIDScale[index_gID][2]*phoEt_[index_g] < cutEB[index_gID][2] ) : false ;
				flag = (flag) ?  ( phoHoverE[index_g]                                < cutEB[index_gID][3] ) : false ;
				flag = (flag) ?  ( phoSigmaIEtaIEta[index_g]                         < cutEB[index_gID][4] ) : false ;
			} else if (BE == 1){
				if ( rho > -0.5 ){
					double fEffAreaEcalEE(0.071);
					double fEffAreaHcalEE(0.095);
					double fEffAreaTrkEE(0.269);
					ecalIso -= rho * fEffAreaEcalEE ;
					hcalIso -= rho * fEffAreaHcalEE ;
					trkIso  -= rho * fEffAreaTrkEE  ;
				}
				flag =          ( ecalIso - PhoIDScale[index_gID][0]*phoEt_[index_g] < cutEE[index_gID][0] ) ;
				flag = (flag) ? ( hcalIso - PhoIDScale[index_gID][1]*phoEt_[index_g] < cutEE[index_gID][1] ) : false ;
				flag = (flag) ? ( trkIso -  PhoIDScale[index_gID][2]*phoEt_[index_g] < cutEE[index_gID][2] ) : false ;
				flag = (flag) ? ( phoHoverE[index_g]                                < cutEE[index_gID][3] ) : false ;
				flag = (flag) ? ( phoSigmaIEtaIEta[index_g] 						< cutEE[index_gID][4] )	: false ;
			}
			break ;
		case 0: // pID tight
			if (BE == 0){
				flag =          ( ecalIso - PhoIDScale[index_gID][0]*phoEt_[index_g] < cutEB[index_gID][0] ) ;
				flag = (flag) ? ( hcalIso - PhoIDScale[index_gID][1]*phoEt_[index_g] < cutEB[index_gID][1] ) : false ;
				flag = (flag) ? ( trkIso  - PhoIDScale[index_gID][2]*phoEt_[index_g] < cutEB[index_gID][2] ) : false ;
				flag = (flag) ? ( phoHoverE[index_g]                                < cutEB[index_gID][3] ) : false ;
				flag = (flag) ? ( phoSigmaIEtaIEta[index_g]                         < cutEB[index_gID][4] ) : false ;
			} else if (BE == 1){
				flag =          ( ecalIso - PhoIDScale[index_gID][0]*phoEt_[index_g] < cutEE[index_gID][0] ) ;
				flag = (flag) ? ( hcalIso - PhoIDScale[index_gID][1]*phoEt_[index_g] < cutEE[index_gID][1] ) : false ;
				flag = (flag) ? ( trkIso  - PhoIDScale[index_gID][2]*phoEt_[index_g] < cutEE[index_gID][2] ) : false ;
				flag = (flag) ? ( phoHoverE[index_g]                                < cutEE[index_gID][3] ) : false ;
				flag = (flag) ? ( phoSigmaIEtaIEta[index_g]                         < cutEE[index_gID][4] ) : false ;
			}
			break ;
	}
	return flag ;
}
Int_t ZgSelectData::elePassLevel(Int_t index_e, Int_t index_eTrg, Int_t index_eID ,
Int_t index_eIDloose,  vector<Float_t> elePt_,
Int_t useLoose){
	bool level1 = false ;
	bool level2 = false ;
	if (elePt_[index_e] < 20. ) return 0 ;
	if (useLoose == 0 && elePt_[index_e] < 20. ) return 0 ;
	if (useLoose == 1){
		if (index_eID < 12){
			if (eleID[index_e][index_eIDloose] == 1) level1 = true ;
			if (eleID[index_e][index_eID] == 1 && eleTrg[index_e][index_eTrg] == 1) level2 = true ;
		}
		else if (index_eID >= 12){
			if (elePassID(index_e,index_eIDloose - 12, elePt_) ) level1 = true ;
			if (elePassID(index_e,index_eID - 12, elePt_) && eleTrg[index_e][index_eTrg]) level2 = true ;
		}
	} else if (useLoose == 0){
		if (index_eID < 12){
			if (eleID[index_e][index_eID] == 1) level1 = true ;
			if (eleID[index_e][index_eID] == 1 && eleTrg[index_e][index_eTrg] == 1) level2 = true ;
		}
		else if (index_eID >= 12){

			if (elePassID(index_e,index_eID - 12, elePt_) ) level1 = true ;
			if (elePassID(index_e,index_eID - 12, elePt_) && eleTrg[index_e][index_eTrg]) level2 = true ;
		}
	}
	level2 =  (level2 && level1 && elePt_[index_e] > 20.) ;
	if (level1 && ! level2 ) return 1 ;
	else if ( level2 ) return 2 ;
	else return 0 ;
}
