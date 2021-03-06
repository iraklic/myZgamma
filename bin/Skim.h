//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Apr 14 10:01:16 2014 by ROOT version 5.27/06b
// from TTree EventTree/Event data
// found on file: rfio:///eos/uscms/store/user/iraklich/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_263279_9.root
//////////////////////////////////////////////////////////

#ifndef Skim_h
#define Skim_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
   const Int_t kMaxphoXtalTime = 1;
   const Int_t kMaxpho5x5Time = 1;
   const Int_t kMaxmuValidFraction = 1;

class Skim {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           run;
   Long64_t        event;
   Int_t           orbit;
   Int_t           bx;
   Int_t           lumis;
   Bool_t          isData;
   Int_t           ttbit0;
   Int_t           nHLT;
   Int_t           HLT[395];   //[nHLT]
   Int_t           HLTIndex[125];
   Int_t           HLTprescale[395];   //[nHLT]
   Int_t           nHFTowersP;
   Int_t           nHFTowersN;
   Int_t           nVtx;
   Float_t         vtx[42][3];   //[nVtx]
   Int_t           vtxNTrk[42];   //[nVtx]
   Float_t         vtxNDF[42];   //[nVtx]
   Float_t         vtxD0[42];   //[nVtx]
   Int_t           nGoodVtx;
   Int_t           IsVtxGood;
   Int_t           nTrk;
   Int_t           nGoodTrk;
   Int_t           IsTracksGood;
   Float_t         rho;
   Float_t         sigma;
   Float_t         rhoNeutral;
   Float_t         pdf[7];
   Float_t         pthat;
   Float_t         processID;
   Int_t           nBX;
   Int_t           nPU[3];   //[nBX]
   Int_t           BXPU[3];   //[nBX]
   Int_t           nMC;
   Int_t           mcPID[35];   //[nMC]
   Float_t         mcVtx[35][3];   //[nMC]
   Float_t         mcPt[35];   //[nMC]
   Float_t         mcMass[35];   //[nMC]
   Float_t         mcEta[35];   //[nMC]
   Float_t         mcPhi[35];   //[nMC]
   Int_t           mcGMomPID[35];   //[nMC]
   Int_t           mcMomPID[35];   //[nMC]
   Float_t         mcMomPt[35];   //[nMC]
   Float_t         mcMomMass[35];   //[nMC]
   Float_t         mcMomEta[35];   //[nMC]
   Float_t         mcMomPhi[35];   //[nMC]
   Int_t           mcIndex[35];   //[nMC]
   Int_t           mcDecayType[35];   //[nMC]
   Float_t         mcIsoDR03[35];   //[nMC]
   Float_t         mcCalIsoDR03[35];   //[nMC]
   Float_t         mcTrkIsoDR03[35];   //[nMC]
   Float_t         mcIsoDR04[35];   //[nMC]
   Float_t         mcCalIsoDR04[35];   //[nMC]
   Float_t         mcTrkIsoDR04[35];   //[nMC]
   Float_t         genMET;
   Float_t         genMETx;
   Float_t         genMETy;
   Float_t         genMETPhi;
   Float_t         MET;
   Float_t         METx;
   Float_t         METy;
   Float_t         METPhi;
   Float_t         METsumEt;
   Float_t         uncorrMET[3];
   Float_t         uncorrMETPhi[3];
   Float_t         uncorrMETSumEt[3];
   Float_t         tcMET;
   Float_t         tcMETx;
   Float_t         tcMETy;
   Float_t         tcMETPhi;
   Float_t         tcMETsumEt;
   Float_t         tcMETmEtSig;
   Float_t         tcMETSig;
   Float_t         pfMET;
   Float_t         pfMETx;
   Float_t         pfMETy;
   Float_t         pfMETPhi;
   Float_t         pfMETsumEt;
   Float_t         pfMETmEtSig;
   Float_t         pfMETSig;
   Float_t         TypeIpfMET;
   Float_t         TypeIpfMETx;
   Float_t         TypeIpfMETy;
   Float_t         TypeIpfMETPhi;
   Float_t         TypeIpfMETsumEt;
   Float_t         TypeIpfMETmEtSig;
   Float_t         TypeIpfMETSig;
   Float_t         TypeIpIIpfMET;
   Float_t         TypeIpIIpfMETx;
   Float_t         TypeIpIIpfMETy;
   Float_t         TypeIpIIpfMETPhi;
   Float_t         TypeIpIIpfMETsumEt;
   Float_t         TypeIpIIpfMETmEtSig;
   Float_t         TypeIpIIpfMETSig;
   Float_t         SmearedpfMET;
   Float_t         SmearedpfMETx;
   Float_t         SmearedpfMETy;
   Float_t         SmearedpfMETPhi;
   Float_t         SmearedpfMETsumEt;
   Float_t         SmearedpfMETmEtSig;
   Float_t         SmearedpfMETSig;
   Float_t         SmearedTypeIpfMET;
   Float_t         SmearedTypeIpfMETx;
   Float_t         SmearedTypeIpfMETy;
   Float_t         SmearedTypeIpfMETPhi;
   Float_t         SmearedTypeIpfMETsumEt;
   Float_t         SmearedTypeIpfMETmEtSig;
   Float_t         SmearedTypeIpfMETSig;
   Int_t           npfCharged;
   Float_t         pfChargedSumPt;
   Int_t           npfChargedHadron;
   Float_t         pfChargedHadronSumPt;
   Int_t           npfLepton;
   Float_t         pfLeptonSumPt;
   Int_t           npfNeutral;
   Float_t         pfNeutralSumPt;
   Int_t           npfNeutralHadron;
   Float_t         pfNeutralHadronSumPt;
   Int_t           npfPhoton;
   Float_t         pfPhotonSumPt;
   Int_t           nEle;
   Int_t           eleTrg[7][31];   //[nEle]
   Int_t           eleID[7][30];   //[nEle]
   Float_t         eleIDLH[7];   //[nEle]
   Int_t           eleClass[7];   //[nEle]
   Int_t           eleCharge[7];   //[nEle]
   Float_t         eleEn[7];   //[nEle]
   Float_t         eleSCRawEn[7];   //[nEle]
   Float_t         eleESEn[7];   //[nEle]
   Float_t         eleSCEn[7];   //[nEle]
   Float_t         elePt[7];   //[nEle]
   Float_t         elePz[7];   //[nEle]
   Float_t         eleEta[7];   //[nEle]
   Float_t         elePhi[7];   //[nEle]
   Float_t         eleSCEta[7];   //[nEle]
   Float_t         eleSCPhi[7];   //[nEle]
   Float_t         eleSCEtaWidth[7];   //[nEle]
   Float_t         eleSCPhiWidth[7];   //[nEle]
   Float_t         eleVtx[7][3];   //[nEle]
   Float_t         eleCaloPos[7][3];   //[nEle]
   Float_t         eleSCPos[7][3];   //[nEle]
   Float_t         eleHoverE[7];   //[nEle]
   Float_t         eleEoverP[7];   //[nEle]
   Float_t         elePin[7];   //[nEle]
   Float_t         elePout[7];   //[nEle]
   Float_t         eleBrem[7];   //[nEle]
   Int_t           elenBrem[7];   //[nEle]
   Float_t         eledEtaAtVtx[7];   //[nEle]
   Float_t         eledPhiAtVtx[7];   //[nEle]
   Float_t         eleSigmaEtaEta[7];   //[nEle]
   Float_t         eleSigmaIEtaIEta[7];   //[nEle]
   Float_t         eleSigmaIEtaIPhi[7];   //[nEle]
   Float_t         eleSigmaIPhiIPhi[7];   //[nEle]
   Float_t         eleE3x3[7];   //[nEle]
   Float_t         eleSeedTime[7];   //[nEle]
   Float_t         eleSeedEnergy[7];   //[nEle]
   Int_t           eleRecoFlag[7];   //[nEle]
   Int_t           eleSeverity[7];   //[nEle]
   Int_t           eleGenIndex[7];   //[nEle]
   Int_t           eleGenGMomPID[7];   //[nEle]
   Int_t           eleGenMomPID[7];   //[nEle]
   Float_t         eleGenMomPt[7];   //[nEle]
   Float_t         eleIsoTrkDR03[7];   //[nEle]
   Float_t         eleIsoEcalDR03[7];   //[nEle]
   Float_t         eleIsoHcalDR03[7];   //[nEle]
   Float_t         eleIsoHcalSolidDR03[7];   //[nEle]
   Float_t         eleIsoTrkDR04[7];   //[nEle]
   Float_t         eleIsoEcalDR04[7];   //[nEle]
   Float_t         eleIsoHcalDR04[7];   //[nEle]
   Float_t         eleIsoHcalSolidDR04[7];   //[nEle]
   Float_t         eleConvDist[7];   //[nEle]
   Float_t         eleConvDcot[7];   //[nEle]
   Float_t         eleConvRadius[7];   //[nEle]
   Int_t           eleConvFlag[7];   //[nEle]
   Int_t           eleConvMissinghit[7];   //[nEle]
   Float_t         eleESRatio[7];   //[nEle]
   Float_t         eleESProfileFront[7][123];   //[nEle]
   Float_t         eleESProfileRear[7][123];   //[nEle]
   Float_t         elePV2D[7];   //[nEle]
   Float_t         elePV3D[7];   //[nEle]
   Float_t         eleBS2D[7];   //[nEle]
   Float_t         eleBS3D[7];   //[nEle]
   Float_t         elePVD0[7];   //[nEle]
   Float_t         elePVDz[7];   //[nEle]
   Int_t           nPho;
   Int_t           phoTrg[8][14];   //[nPho]
   Bool_t          phoIsPhoton[8];   //[nPho]
   Float_t         phoE[8];   //[nPho]
   Float_t         phoEt[8];   //[nPho]
   Float_t         phoPz[8];   //[nPho]
   Float_t         phoEta[8];   //[nPho]
   Float_t         phoPhi[8];   //[nPho]
   Float_t         phoR9[8];   //[nPho]
   Float_t         phoTrkIsoSolidDR03[8];   //[nPho]
   Float_t         phoTrkIsoHollowDR03[8];   //[nPho]
   Int_t           phoNTrkSolidDR03[8];   //[nPho]
   Int_t           phoNTrkHollowDR03[8];   //[nPho]
   Float_t         phoEcalIsoDR03[8];   //[nPho]
   Float_t         phoHcalIsoDR03[8];   //[nPho]
   Float_t         phoHcalIsoSolidDR03[8];   //[nPho]
   Float_t         phoTrkIsoSolidDR04[8];   //[nPho]
   Float_t         phoTrkIsoHollowDR04[8];   //[nPho]
   Int_t           phoNTrkSolidDR04[8];   //[nPho]
   Int_t           phoNTrkHollowDR04[8];   //[nPho]
   Float_t         phoEcalIsoDR04[8];   //[nPho]
   Float_t         phoHcalIsoDR04[8];   //[nPho]
   Float_t         phoHcalIsoSolidDR04[8];   //[nPho]
   Float_t         phoEtVtx[8][150];   //[nPho]
   Float_t         phoEtaVtx[8][150];   //[nPho]
   Float_t         phoPhiVtx[8][150];   //[nPho]
   Float_t         phoTrkIsoSolidDR03Vtx[8][150];   //[nPho]
   Float_t         phoTrkIsoHollowDR03Vtx[8][150];   //[nPho]
   Float_t         phoTrkIsoSolidDR04Vtx[8][150];   //[nPho]
   Float_t         phoTrkIsoHollowDR04Vtx[8][150];   //[nPho]
   Float_t         phoHoverE[8];   //[nPho]
   Float_t         phoSigmaEtaEta[8];   //[nPho]
   Float_t         phoSigmaIEtaIEta[8];   //[nPho]
   Float_t         phoSigmaIEtaIPhi[8];   //[nPho]
   Float_t         phoSigmaIPhiIPhi[8];   //[nPho]
   Float_t         phoE3x3[8];   //[nPho]
   Float_t         phoE5x5[8];   //[nPho]
   Float_t         phoSeedTime[8];   //[nPho]
   Float_t         phoSeedEnergy[8];   //[nPho]
   Int_t           phoRecoFlag[8];   //[nPho]
   Int_t           phoSeverity[8];   //[nPho]
   Int_t           phoPos[8];   //[nPho]
   Int_t           phoGenIndex[8];   //[nPho]
   Int_t           phoGenGMomPID[8];   //[nPho]
   Int_t           phoGenMomPID[8];   //[nPho]
   Float_t         phoGenMomPt[8];   //[nPho]
   Float_t         phoSCE[8];   //[nPho]
   Float_t         phoESE[8];   //[nPho]
   Float_t         phoSCEt[8];   //[nPho]
   Float_t         phoSCEta[8];   //[nPho]
   Float_t         phoSCPhi[8];   //[nPho]
   Float_t         phoSCEtaWidth[8];   //[nPho]
   Float_t         phoSCPhiWidth[8];   //[nPho]
   Float_t         phoVtx[8][3];   //[nPho]
   Float_t         phoVtxD0[8];   //[nPho]
   Int_t           phoOverlap[8];   //[nPho]
   Int_t           phohasPixelSeed[8];   //[nPho]
   Int_t           phoIsConv[8];   //[nPho]
   Float_t         phoESRatio[8];   //[nPho]
   Float_t         phoESProfileFront[8][123];   //[nPho]
   Float_t         phoESProfileRear[8][123];   //[nPho]
   Int_t           phoNTracks[8];   //[nPho]
   Float_t         phoConvPairInvariantMass[8];   //[nPho]
   Float_t         phoConvPairCotThetaSeparation[8];   //[nPho]
   Float_t         phoConvPairMomentumEta[8];   //[nPho]
   Float_t         phoConvPairMomentumPhi[8];   //[nPho]
   Float_t         phoConvPairMomentumX[8];   //[nPho]
   Float_t         phoConvPairMomentumY[8];   //[nPho]
   Float_t         phoConvPairMomentumZ[8];   //[nPho]
   Float_t         phoConvDistOfMinimumApproach[8];   //[nPho]
   Float_t         phoConvDPhiTracksAtVtx[8];   //[nPho]
   Float_t         phoConvDPhiTracksAtEcal[8];   //[nPho]
   Float_t         phoConvDEtaTracksAtEcal[8];   //[nPho]
   Float_t         phoConvVtxValid[8];   //[nPho]
   Float_t         phoConvVtxEta[8];   //[nPho]
   Float_t         phoConvVtxPhi[8];   //[nPho]
   Float_t         phoConvVtxR[8];   //[nPho]
   Float_t         phoConvVtxX[8];   //[nPho]
   Float_t         phoConvVtxY[8];   //[nPho]
   Float_t         phoConvVtxZ[8];   //[nPho]
   Float_t         phoConvVtxChi2[8];   //[nPho]
   Float_t         phoConvVtxNdof[8];   //[nPho]
   Float_t         phoConvChi2Prob[8];   //[nPho]
   Float_t         phoConvEoverP[8];   //[nPho]
   Int_t           phoNxtal[8];   //[nPho]
   Float_t         phoXtalTime[8][200];   //[nPho]
   Float_t         phoXtalEnergy[8][200];   //[nPho]
   Int_t           phoXtalZ[8][200];   //[nPho]
   Int_t           phoXtalX[8][200];   //[nPho]
   Int_t           phoXtalY[8][200];   //[nPho]
   Int_t           phoXtalEta[8][200];   //[nPho]
   Int_t           phoXtalPhi[8][200];   //[nPho]
   Float_t         pho5x5Time[8][25];   //[nPho]
   Float_t         pho5x5Energy[8][25];   //[nPho]
   Int_t           pho5x5Z[8][25];   //[nPho]
   Int_t           pho5x5X[8][25];   //[nPho]
   Int_t           pho5x5Y[8][25];   //[nPho]
   Int_t           pho5x5Eta[8][25];   //[nPho]
   Int_t           pho5x5Phi[8][25];   //[nPho]
   Int_t           nMu;
   Int_t           muTrg[16][16];   //[nMu]
   Float_t         muEta[16];   //[nMu]
   Float_t         muPhi[16];   //[nMu]
   Int_t           muCharge[16];   //[nMu]
   Float_t         muPt[16];   //[nMu]
   Float_t         muPz[16];   //[nMu]
   Int_t           muGenIndex[16];   //[nMu]
   Int_t           muGenGMomPID[16];   //[nMu]
   Int_t           muGenMomPID[16];   //[nMu]
   Float_t         muGenMomPt[16];   //[nMu]
   Float_t         muIsoTrk[16];   //[nMu]
   Float_t         muIsoCalo[16];   //[nMu]
   Float_t         muIsoEcal[16];   //[nMu]
   Float_t         muIsoHcal[16];   //[nMu]
   Float_t         muChi2NDF[16];   //[nMu]
   Float_t         muEmVeto[16];   //[nMu]
   Float_t         muHadVeto[16];   //[nMu]
   Int_t           muType[16];   //[nMu]
   Bool_t          muID[16][6];   //[nMu]
   Float_t         muD0[16];   //[nMu]
   Float_t         muDz[16];   //[nMu]
   Float_t         muPVD0[16];   //[nMu]
   Float_t         muPVDz[16];   //[nMu]
   Float_t         muValidFraction[16];   //[nMu]
   Float_t         muTrkdPt[16];   //[nMu]
   Int_t           muNumberOfHits[16];   //[nMu]
   Int_t           muNumberOfValidHits[16];   //[nMu]
   Int_t           muNumberOfInactiveHits[16];   //[nMu]
   Int_t           muNumberOfValidTrkHits[16];   //[nMu]
   Int_t           muNumberOfValidPixelHits[16];   //[nMu]
   Int_t           muNumberOfValidMuonHits[16];   //[nMu]
   Int_t           muStations[16];   //[nMu]
   Int_t           muChambers[16];   //[nMu]
   Float_t         muPV2D[16];   //[nMu]
   Float_t         muPV3D[16];   //[nMu]
   Float_t         muBS2D[16];   //[nMu]
   Float_t         muBS3D[16];   //[nMu]
   Float_t         muVtx[16][3];   //[nMu]
   Int_t           nJet;
   Int_t           jetTrg[23][23];   //[nJet]
   Float_t         jetEn[23];   //[nJet]
   Float_t         jetPt[23];   //[nJet]
   Float_t         jetEta[23];   //[nJet]
   Float_t         jetPhi[23];   //[nJet]
   Float_t         jetMass[23];   //[nJet]
   Float_t         jetEt[23];   //[nJet]
   Int_t           jetpartonFlavour[23];   //[nJet]
   Float_t         jetRawPt[23];   //[nJet]
   Float_t         jetRawEn[23];   //[nJet]
   Float_t         jetCharge[23];   //[nJet]
   Float_t         jetNeutralEmEnergy[23];   //[nJet]
   Float_t         jetNeutralEmEnergyFraction[23];   //[nJet]
   Float_t         jetNeutralHadronEnergy[23];   //[nJet]
   Float_t         jetNeutralHadronEnergyFraction[23];   //[nJet]
   Int_t           jetNConstituents[23];   //[nJet]
   Float_t         jetChargedEmEnergy[23];   //[nJet]
   Float_t         jetChargedEmEnergyFraction[23];   //[nJet]
   Float_t         jetChargedHadronEnergy[23];   //[nJet]
   Float_t         jetChargedHadronEnergyFraction[23];   //[nJet]
   Int_t           jetChargedHadronMultiplicity[23];   //[nJet]
   Float_t         jetChargedMuEnergy[23];   //[nJet]
   Float_t         jetChargedMuEnergyFraction[23];   //[nJet]
   Double_t        jetJVAlpha[23];   //[nJet]
   Double_t        jetJVBeta[23];   //[nJet]
   Int_t           jetGenJetIndex[23];   //[nJet]
   Float_t         jetGenJetEn[23];   //[nJet]
   Float_t         jetGenJetPt[23];   //[nJet]
   Float_t         jetGenJetEta[23];   //[nJet]
   Float_t         jetGenJetPhi[23];   //[nJet]
   Float_t         jetGenJetMass[23];   //[nJet]
   Int_t           jetGenPartonID[23];   //[nJet]
   Int_t           jetGenPartonMomID[23];   //[nJet]
   Int_t           nZee;
   Float_t         ZeeMass[21];   //[nZee]
   Float_t         ZeePt[21];   //[nZee]
   Float_t         ZeeEta[21];   //[nZee]
   Float_t         ZeePhi[21];   //[nZee]
   Int_t           ZeeLeg1Index[21];   //[nZee]
   Int_t           ZeeLeg2Index[21];   //[nZee]
   Int_t           nZmumu;
   Float_t         ZmumuMass[2];   //[nZmumu]
   Float_t         ZmumuPt[2];   //[nZmumu]
   Float_t         ZmumuEta[2];   //[nZmumu]
   Float_t         ZmumuPhi[2];   //[nZmumu]
   Int_t           ZmumuLeg1Index[2];   //[nZmumu]
   Int_t           ZmumuLeg2Index[2];   //[nZmumu]
   Int_t           nWenu;
   Float_t         WenuMassTCaloMET[7];   //[nWenu]
   Float_t         WenuEtCaloMET[7];   //[nWenu]
   Float_t         WenuACopCaloMET[7];   //[nWenu]
   Float_t         WenuMassTTcMET[7];   //[nWenu]
   Float_t         WenuEtTcMET[7];   //[nWenu]
   Float_t         WenuACopTcMET[7];   //[nWenu]
   Float_t         WenuMassTPfMET[7];   //[nWenu]
   Float_t         WenuEtPfMET[7];   //[nWenu]
   Float_t         WenuACopPfMET[7];   //[nWenu]
   Int_t           WenuEleIndex[7];   //[nWenu]
   Int_t           nWmunu;
   Float_t         WmunuMassTCaloMET[3];   //[nWmunu]
   Float_t         WmunuEtCaloMET[3];   //[nWmunu]
   Float_t         WmunuACopCaloMET[3];   //[nWmunu]
   Float_t         WmunuMassTTcMET[3];   //[nWmunu]
   Float_t         WmunuEtTcMET[3];   //[nWmunu]
   Float_t         WmunuACopTcMET[3];   //[nWmunu]
   Float_t         WmunuMassTPfMET[3];   //[nWmunu]
   Float_t         WmunuEtPfMET[3];   //[nWmunu]
   Float_t         WmunuACopPfMET[3];   //[nWmunu]
   Int_t           WmunuMuIndex[3];   //[nWmunu]

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_event;   //!
   TBranch        *b_orbit;   //!
   TBranch        *b_bx;   //!
   TBranch        *b_lumis;   //!
   TBranch        *b_isData;   //!
   TBranch        *b_ttbit0;   //!
   TBranch        *b_nHLT;   //!
   TBranch        *b_HLT;   //!
   TBranch        *b_HLTIndex;   //!
   TBranch        *b_HLTprescale;   //!
   TBranch        *b_nHFTowersP;   //!
   TBranch        *b_nHFTowersN;   //!
   TBranch        *b_nVtx;   //!
   TBranch        *b_vtx;   //!
   TBranch        *b_vtxNTrk;   //!
   TBranch        *b_vtxNDF;   //!
   TBranch        *b_vtxD0;   //!
   TBranch        *b_nGoodVtx;   //!
   TBranch        *b_IsVtxGood;   //!
   TBranch        *b_nTrk;   //!
   TBranch        *b_nGoodTrk;   //!
   TBranch        *b_IsTracksGood;   //!
   TBranch        *b_rho;   //!
   TBranch        *b_sigma;   //!
   TBranch        *b_rhoNeutral;   //!
   TBranch        *b_pdf;   //!
   TBranch        *b_pthat;   //!
   TBranch        *b_processID;   //!
   TBranch        *b_nBX;   //!
   TBranch        *b_nPU;   //!
   TBranch        *b_BXPU;   //!
   TBranch        *b_nMC;   //!
   TBranch        *b_mcPID;   //!
   TBranch        *b_mcVtx;   //!
   TBranch        *b_mcPt;   //!
   TBranch        *b_mcMass;   //!
   TBranch        *b_mcEta;   //!
   TBranch        *b_mcPhi;   //!
   TBranch        *b_mcGMomPID;   //!
   TBranch        *b_mcMomPID;   //!
   TBranch        *b_mcMomPt;   //!
   TBranch        *b_mcMomMass;   //!
   TBranch        *b_mcMomEta;   //!
   TBranch        *b_mcMomPhi;   //!
   TBranch        *b_mcIndex;   //!
   TBranch        *b_mcDecayType;   //!
   TBranch        *b_mcIsoDR03;   //!
   TBranch        *b_mcCalIsoDR03;   //!
   TBranch        *b_mcTrkIsoDR03;   //!
   TBranch        *b_mcIsoDR04;   //!
   TBranch        *b_mcCalIsoDR04;   //!
   TBranch        *b_mcTrkIsoDR04;   //!
   TBranch        *b_genMET;   //!
   TBranch        *b_genMETx;   //!
   TBranch        *b_genMETy;   //!
   TBranch        *b_genMETPhi;   //!
   TBranch        *b_MET;   //!
   TBranch        *b_METx;   //!
   TBranch        *b_METy;   //!
   TBranch        *b_METPhi;   //!
   TBranch        *b_METsumEt;   //!
   TBranch        *b_uncorrMET;   //!
   TBranch        *b_uncorrMETPhi;   //!
   TBranch        *b_uncorrMETSumEt;   //!
   TBranch        *b_tcMET;   //!
   TBranch        *b_tcMETx;   //!
   TBranch        *b_tcMETy;   //!
   TBranch        *b_tcMETPhi;   //!
   TBranch        *b_tcMETsumEt;   //!
   TBranch        *b_tcMETmEtSig;   //!
   TBranch        *b_tcMETSig;   //!
   TBranch        *b_pfMET;   //!
   TBranch        *b_pfMETx;   //!
   TBranch        *b_pfMETy;   //!
   TBranch        *b_pfMETPhi;   //!
   TBranch        *b_pfMETsumEt;   //!
   TBranch        *b_pfMETmEtSig;   //!
   TBranch        *b_pfMETSig;   //!
   TBranch        *b_TypeIpfMET;   //!
   TBranch        *b_TypeIpfMETx;   //!
   TBranch        *b_TypeIpfMETy;   //!
   TBranch        *b_TypeIpfMETPhi;   //!
   TBranch        *b_TypeIpfMETsumEt;   //!
   TBranch        *b_TypeIpfMETmEtSig;   //!
   TBranch        *b_TypeIpfMETSig;   //!
   TBranch        *b_TypeIpIIpfMET;   //!
   TBranch        *b_TypeIpIIpfMETx;   //!
   TBranch        *b_TypeIpIIpfMETy;   //!
   TBranch        *b_TypeIpIIpfMETPhi;   //!
   TBranch        *b_TypeIpIIpfMETsumEt;   //!
   TBranch        *b_TypeIpIIpfMETmEtSig;   //!
   TBranch        *b_TypeIpIIpfMETSig;   //!
   TBranch        *b_SmearedpfMET;   //!
   TBranch        *b_SmearedpfMETx;   //!
   TBranch        *b_SmearedpfMETy;   //!
   TBranch        *b_SmearedpfMETPhi;   //!
   TBranch        *b_SmearedpfMETsumEt;   //!
   TBranch        *b_SmearedpfMETmEtSig;   //!
   TBranch        *b_SmearedpfMETSig;   //!
   TBranch        *b_SmearedTypeIpfMET;   //!
   TBranch        *b_SmearedTypeIpfMETx;   //!
   TBranch        *b_SmearedTypeIpfMETy;   //!
   TBranch        *b_SmearedTypeIpfMETPhi;   //!
   TBranch        *b_SmearedTypeIpfMETsumEt;   //!
   TBranch        *b_SmearedTypeIpfMETmEtSig;   //!
   TBranch        *b_SmearedTypeIpfMETSig;   //!
   TBranch        *b_npfCharged;   //!
   TBranch        *b_pfChargedSumPt;   //!
   TBranch        *b_npfChargedHadron;   //!
   TBranch        *b_pfChargedHadronSumPt;   //!
   TBranch        *b_npfLepton;   //!
   TBranch        *b_pfLeptonSumPt;   //!
   TBranch        *b_npfNeutral;   //!
   TBranch        *b_pfNeutralSumPt;   //!
   TBranch        *b_npfNeutralHadron;   //!
   TBranch        *b_pfNeutralHadronSumPt;   //!
   TBranch        *b_npfPhoton;   //!
   TBranch        *b_pfPhotonSumPt;   //!
   TBranch        *b_nEle;   //!
   TBranch        *b_eleTrg;   //!
   TBranch        *b_eleID;   //!
   TBranch        *b_eleIDLH;   //!
   TBranch        *b_eleClass;   //!
   TBranch        *b_eleCharge;   //!
   TBranch        *b_eleEn;   //!
   TBranch        *b_eleSCRawEn;   //!
   TBranch        *b_eleESEn;   //!
   TBranch        *b_eleSCEn;   //!
   TBranch        *b_elePt;   //!
   TBranch        *b_elePz;   //!
   TBranch        *b_eleEta;   //!
   TBranch        *b_elePhi;   //!
   TBranch        *b_eleSCEta;   //!
   TBranch        *b_eleSCPhi;   //!
   TBranch        *b_eleSCEtaWidth;   //!
   TBranch        *b_eleSCPhiWidth;   //!
   TBranch        *b_eleVtx;   //!
   TBranch        *b_eleCaloPos;   //!
   TBranch        *b_eleSCPos;   //!
   TBranch        *b_eleHoverE;   //!
   TBranch        *b_eleEoverP;   //!
   TBranch        *b_elePin;   //!
   TBranch        *b_elePout;   //!
   TBranch        *b_eleBrem;   //!
   TBranch        *b_elenBrem;   //!
   TBranch        *b_eledEtaAtVtx;   //!
   TBranch        *b_eledPhiAtVtx;   //!
   TBranch        *b_eleSigmaEtaEta;   //!
   TBranch        *b_eleSigmaIEtaIEta;   //!
   TBranch        *b_eleSigmaIEtaIPhi;   //!
   TBranch        *b_eleSigmaIPhiIPhi;   //!
   TBranch        *b_eleE3x3;   //!
   TBranch        *b_eleSeedTime;   //!
   TBranch        *b_eleSeedEnergy;   //!
   TBranch        *b_eleRecoFlag;   //!
   TBranch        *b_eleSeverity;   //!
   TBranch        *b_eleGenIndex;   //!
   TBranch        *b_eleGenGMomPID;   //!
   TBranch        *b_eleGenMomPID;   //!
   TBranch        *b_eleGenMomPt;   //!
   TBranch        *b_eleIsoTrkDR03;   //!
   TBranch        *b_eleIsoEcalDR03;   //!
   TBranch        *b_eleIsoHcalDR03;   //!
   TBranch        *b_eleIsoHcalSolidDR03;   //!
   TBranch        *b_eleIsoTrkDR04;   //!
   TBranch        *b_eleIsoEcalDR04;   //!
   TBranch        *b_eleIsoHcalDR04;   //!
   TBranch        *b_eleIsoHcalSolidDR04;   //!
   TBranch        *b_eleConvDist;   //!
   TBranch        *b_eleConvDcot;   //!
   TBranch        *b_eleConvRadius;   //!
   TBranch        *b_eleConvFlag;   //!
   TBranch        *b_eleConvMissinghit;   //!
   TBranch        *b_eleESRatio;   //!
   TBranch        *b_eleESProfileFront;   //!
   TBranch        *b_eleESProfileRear;   //!
   TBranch        *b_elePV2D;   //!
   TBranch        *b_elePV3D;   //!
   TBranch        *b_eleBS2D;   //!
   TBranch        *b_eleBS3D;   //!
   TBranch        *b_elePVD0;   //!
   TBranch        *b_elePVDz;   //!
   TBranch        *b_nPho;   //!
   TBranch        *b_phoTrg;   //!
   TBranch        *b_phoIsPhoton;   //!
   TBranch        *b_phoE;   //!
   TBranch        *b_phoEt;   //!
   TBranch        *b_phoPz;   //!
   TBranch        *b_phoEta;   //!
   TBranch        *b_phoPhi;   //!
   TBranch        *b_phoR9;   //!
   TBranch        *b_phoTrkIsoSolidDR03;   //!
   TBranch        *b_phoTrkIsoHollowDR03;   //!
   TBranch        *b_phoNTrkSolidDR03;   //!
   TBranch        *b_phoNTrkHollowDR03;   //!
   TBranch        *b_phoEcalIsoDR03;   //!
   TBranch        *b_phoHcalIsoDR03;   //!
   TBranch        *b_phoHcalIsoSolidDR03;   //!
   TBranch        *b_phoTrkIsoSolidDR04;   //!
   TBranch        *b_phoTrkIsoHollowDR04;   //!
   TBranch        *b_phoNTrkSolidDR04;   //!
   TBranch        *b_phoNTrkHollowDR04;   //!
   TBranch        *b_phoEcalIsoDR04;   //!
   TBranch        *b_phoHcalIsoDR04;   //!
   TBranch        *b_phoHcalIsoSolidDR04;   //!
   TBranch        *b_phoEtVtx;   //!
   TBranch        *b_phoEtaVtx;   //!
   TBranch        *b_phoPhiVtx;   //!
   TBranch        *b_phoTrkIsoSolidDR03Vtx;   //!
   TBranch        *b_phoTrkIsoHollowDR03Vtx;   //!
   TBranch        *b_phoTrkIsoSolidDR04Vtx;   //!
   TBranch        *b_phoTrkIsoHollowDR04Vtx;   //!
   TBranch        *b_phoHoverE;   //!
   TBranch        *b_phoSigmaEtaEta;   //!
   TBranch        *b_phoSigmaIEtaIEta;   //!
   TBranch        *b_phoSigmaIEtaIPhi;   //!
   TBranch        *b_phoSigmaIPhiIPhi;   //!
   TBranch        *b_phoE3x3;   //!
   TBranch        *b_phoE5x5;   //!
   TBranch        *b_phoSeedTime;   //!
   TBranch        *b_phoSeedEnergy;   //!
   TBranch        *b_phoRecoFlag;   //!
   TBranch        *b_phoSeverity;   //!
   TBranch        *b_phoPos;   //!
   TBranch        *b_phoGenIndex;   //!
   TBranch        *b_phoGenGMomPID;   //!
   TBranch        *b_phoGenMomPID;   //!
   TBranch        *b_phoGenMomPt;   //!
   TBranch        *b_phoSCE;   //!
   TBranch        *b_phoESE;   //!
   TBranch        *b_phoSCEt;   //!
   TBranch        *b_phoSCEta;   //!
   TBranch        *b_phoSCPhi;   //!
   TBranch        *b_phoSCEtaWidth;   //!
   TBranch        *b_phoSCPhiWidth;   //!
   TBranch        *b_phoVtx;   //!
   TBranch        *b_phoVtxD0;   //!
   TBranch        *b_phoOverlap;   //!
   TBranch        *b_phohasPixelSeed;   //!
   TBranch        *b_phoIsConv;   //!
   TBranch        *b_phoESRatio;   //!
   TBranch        *b_phoESProfileFront;   //!
   TBranch        *b_phoESProfileRear;   //!
   TBranch        *b_phoNTracks;   //!
   TBranch        *b_phoConvPairInvariantMass;   //!
   TBranch        *b_phoConvPairCotThetaSeparation;   //!
   TBranch        *b_phoConvPairMomentumEta;   //!
   TBranch        *b_phoConvPairMomentumPhi;   //!
   TBranch        *b_phoConvPairMomentumX;   //!
   TBranch        *b_phoConvPairMomentumY;   //!
   TBranch        *b_phoConvPairMomentumZ;   //!
   TBranch        *b_phoConvDistOfMinimumApproach;   //!
   TBranch        *b_phoConvDPhiTracksAtVtx;   //!
   TBranch        *b_phoConvDPhiTracksAtEcal;   //!
   TBranch        *b_phoConvDEtaTracksAtEcal;   //!
   TBranch        *b_phoConvVtxValid;   //!
   TBranch        *b_phoConvVtxEta;   //!
   TBranch        *b_phoConvVtxPhi;   //!
   TBranch        *b_phoConvVtxR;   //!
   TBranch        *b_phoConvVtxX;   //!
   TBranch        *b_phoConvVtxY;   //!
   TBranch        *b_phoConvVtxZ;   //!
   TBranch        *b_phoConvVtxChi2;   //!
   TBranch        *b_phoConvVtxNdof;   //!
   TBranch        *b_phoConvChi2Prob;   //!
   TBranch        *b_phoConvEoverP;   //!
   TBranch        *b_phoNxtal;   //!
   TBranch        *b_phoXtalTime;   //!
   TBranch        *b_phoXtalEnergy;   //!
   TBranch        *b_phoXtalZ;   //!
   TBranch        *b_phoXtalX;   //!
   TBranch        *b_phoXtalY;   //!
   TBranch        *b_phoXtalEta;   //!
   TBranch        *b_phoXtalPhi;   //!
   TBranch        *b_pho5x5Time;   //!
   TBranch        *b_pho5x5Energy;   //!
   TBranch        *b_pho5x5Z;   //!
   TBranch        *b_pho5x5X;   //!
   TBranch        *b_pho5x5Y;   //!
   TBranch        *b_pho5x5Eta;   //!
   TBranch        *b_pho5x5Phi;   //!
   TBranch        *b_nMu;   //!
   TBranch        *b_muTrg;   //!
   TBranch        *b_muEta;   //!
   TBranch        *b_muPhi;   //!
   TBranch        *b_muCharge;   //!
   TBranch        *b_muPt;   //!
   TBranch        *b_muPz;   //!
   TBranch        *b_muGenIndex;   //!
   TBranch        *b_muGenGMomPID;   //!
   TBranch        *b_muGenMomPID;   //!
   TBranch        *b_muGenMomPt;   //!
   TBranch        *b_muIsoTrk;   //!
   TBranch        *b_muIsoCalo;   //!
   TBranch        *b_muIsoEcal;   //!
   TBranch        *b_muIsoHcal;   //!
   TBranch        *b_muChi2NDF;   //!
   TBranch        *b_muEmVeto;   //!
   TBranch        *b_muHadVeto;   //!
   TBranch        *b_muType;   //!
   TBranch        *b_muID;   //!
   TBranch        *b_muD0;   //!
   TBranch        *b_muDz;   //!
   TBranch        *b_muPVD0;   //!
   TBranch        *b_muPVDz;   //!
   TBranch        *b_muValidFraction;   //!
   TBranch        *b_muTrkdPt;   //!
   TBranch        *b_muNumberOfHits;   //!
   TBranch        *b_muNumberOfValidHits;   //!
   TBranch        *b_muNumberOfInactiveHits;   //!
   TBranch        *b_muNumberOfValidTrkHits;   //!
   TBranch        *b_muNumberOfValidPixelHits;   //!
   TBranch        *b_muNumberOfValidMuonHits;   //!
   TBranch        *b_muStations;   //!
   TBranch        *b_muChambers;   //!
   TBranch        *b_muPV2D;   //!
   TBranch        *b_muPV3D;   //!
   TBranch        *b_muBS2D;   //!
   TBranch        *b_muBS3D;   //!
   TBranch        *b_muVtx;   //!
   TBranch        *b_nJet;   //!
   TBranch        *b_jetTrg;   //!
   TBranch        *b_jetEn;   //!
   TBranch        *b_jetPt;   //!
   TBranch        *b_jetEta;   //!
   TBranch        *b_jetPhi;   //!
   TBranch        *b_jetMass;   //!
   TBranch        *b_jetEt;   //!
   TBranch        *b_jetpartonFlavour;   //!
   TBranch        *b_jetRawPt;   //!
   TBranch        *b_jetRawEn;   //!
   TBranch        *b_jetCharge;   //!
   TBranch        *b_jetNeutralEmEnergy;   //!
   TBranch        *b_jetNeutralEmEnergyFraction;   //!
   TBranch        *b_jetNeutralHadronEnergy;   //!
   TBranch        *b_jetNeutralHadronEnergyFraction;   //!
   TBranch        *b_jetNConstituents;   //!
   TBranch        *b_jetChargedEmEnergy;   //!
   TBranch        *b_jetChargedEmEnergyFraction;   //!
   TBranch        *b_jetChargedHadronEnergy;   //!
   TBranch        *b_jetChargedHadronEnergyFraction;   //!
   TBranch        *b_jetChargedHadronMultiplicity;   //!
   TBranch        *b_jetChargedMuEnergy;   //!
   TBranch        *b_jetChargedMuEnergyFraction;   //!
   TBranch        *b_jetJVAlpha;   //!
   TBranch        *b_jetJVBeta;   //!
   TBranch        *b_jetGenJetIndex;   //!
   TBranch        *b_jetGenJetEn;   //!
   TBranch        *b_jetGenJetPt;   //!
   TBranch        *b_jetGenJetEta;   //!
   TBranch        *b_jetGenJetPhi;   //!
   TBranch        *b_jetGenJetMass;   //!
   TBranch        *b_jetGenPartonID;   //!
   TBranch        *b_jetGenPartonMomID;   //!
   TBranch        *b_nZee;   //!
   TBranch        *b_ZeeMass;   //!
   TBranch        *b_ZeePt;   //!
   TBranch        *b_ZeeEta;   //!
   TBranch        *b_ZeePhi;   //!
   TBranch        *b_ZeeLeg1Index;   //!
   TBranch        *b_ZeeLeg2Index;   //!
   TBranch        *b_nZmumu;   //!
   TBranch        *b_ZmumuMass;   //!
   TBranch        *b_ZmumuPt;   //!
   TBranch        *b_ZmumuEta;   //!
   TBranch        *b_ZmumuPhi;   //!
   TBranch        *b_ZmumuLeg1Index;   //!
   TBranch        *b_ZmumuLeg2Index;   //!
   TBranch        *b_nWenu;   //!
   TBranch        *b_WenuMassTCaloMET;   //!
   TBranch        *b_WenuEtCaloMET;   //!
   TBranch        *b_WenuACopCaloMET;   //!
   TBranch        *b_WenuMassTTcMET;   //!
   TBranch        *b_WenuEtTcMET;   //!
   TBranch        *b_WenuACopTcMET;   //!
   TBranch        *b_WenuMassTPfMET;   //!
   TBranch        *b_WenuEtPfMET;   //!
   TBranch        *b_WenuACopPfMET;   //!
   TBranch        *b_WenuEleIndex;   //!
   TBranch        *b_nWmunu;   //!
   TBranch        *b_WmunuMassTCaloMET;   //!
   TBranch        *b_WmunuEtCaloMET;   //!
   TBranch        *b_WmunuACopCaloMET;   //!
   TBranch        *b_WmunuMassTTcMET;   //!
   TBranch        *b_WmunuEtTcMET;   //!
   TBranch        *b_WmunuACopTcMET;   //!
   TBranch        *b_WmunuMassTPfMET;   //!
   TBranch        *b_WmunuEtPfMET;   //!
   TBranch        *b_WmunuACopPfMET;   //!
   TBranch        *b_WmunuMuIndex;   //!

   Skim(TTree *tree=0);
   virtual ~Skim();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef Skim_cxx
Skim::Skim(TTree *tree)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("rfio:///eos/uscms/store/user/iraklich/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_263279_9.root");
      if (!f) {
         f = new TFile("rfio:///eos/uscms/store/user/iraklich/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_263279_9.root");
         f->cd("rfio:///eos/uscms/store/user/iraklich/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_263279_9.root:/VgAnalyzerKit");
      }
      tree = (TTree*)gDirectory->Get("EventTree");

   }
   Init(tree);
}

Skim::~Skim()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t Skim::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t Skim::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (!fChain->InheritsFrom(TChain::Class()))  return centry;
   TChain *chain = (TChain*)fChain;
   if (chain->GetTreeNumber() != fCurrent) {
      fCurrent = chain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void Skim::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("orbit", &orbit, &b_orbit);
   fChain->SetBranchAddress("bx", &bx, &b_bx);
   fChain->SetBranchAddress("lumis", &lumis, &b_lumis);
   fChain->SetBranchAddress("isData", &isData, &b_isData);
   fChain->SetBranchAddress("ttbit0", &ttbit0, &b_ttbit0);
   fChain->SetBranchAddress("nHLT", &nHLT, &b_nHLT);
   fChain->SetBranchAddress("HLT", HLT, &b_HLT);
   fChain->SetBranchAddress("HLTIndex", HLTIndex, &b_HLTIndex);
   fChain->SetBranchAddress("HLTprescale", HLTprescale, &b_HLTprescale);
   fChain->SetBranchAddress("nHFTowersP", &nHFTowersP, &b_nHFTowersP);
   fChain->SetBranchAddress("nHFTowersN", &nHFTowersN, &b_nHFTowersN);
   fChain->SetBranchAddress("nVtx", &nVtx, &b_nVtx);
   fChain->SetBranchAddress("vtx", vtx, &b_vtx);
   fChain->SetBranchAddress("vtxNTrk", vtxNTrk, &b_vtxNTrk);
   fChain->SetBranchAddress("vtxNDF", vtxNDF, &b_vtxNDF);
   fChain->SetBranchAddress("vtxD0", vtxD0, &b_vtxD0);
   fChain->SetBranchAddress("nGoodVtx", &nGoodVtx, &b_nGoodVtx);
   fChain->SetBranchAddress("IsVtxGood", &IsVtxGood, &b_IsVtxGood);
   fChain->SetBranchAddress("nTrk", &nTrk, &b_nTrk);
   fChain->SetBranchAddress("nGoodTrk", &nGoodTrk, &b_nGoodTrk);
   fChain->SetBranchAddress("IsTracksGood", &IsTracksGood, &b_IsTracksGood);
   fChain->SetBranchAddress("rho", &rho, &b_rho);
   fChain->SetBranchAddress("sigma", &sigma, &b_sigma);
   fChain->SetBranchAddress("rhoNeutral", &rhoNeutral, &b_rhoNeutral);
   fChain->SetBranchAddress("pdf", pdf, &b_pdf);
   fChain->SetBranchAddress("pthat", &pthat, &b_pthat);
   fChain->SetBranchAddress("processID", &processID, &b_processID);
   fChain->SetBranchAddress("nBX", &nBX, &b_nBX);
   fChain->SetBranchAddress("nPU", nPU, &b_nPU);
   fChain->SetBranchAddress("BXPU", BXPU, &b_BXPU);
   fChain->SetBranchAddress("nMC", &nMC, &b_nMC);
   fChain->SetBranchAddress("mcPID", mcPID, &b_mcPID);
   fChain->SetBranchAddress("mcVtx", mcVtx, &b_mcVtx);
   fChain->SetBranchAddress("mcPt", mcPt, &b_mcPt);
   fChain->SetBranchAddress("mcMass", mcMass, &b_mcMass);
   fChain->SetBranchAddress("mcEta", mcEta, &b_mcEta);
   fChain->SetBranchAddress("mcPhi", mcPhi, &b_mcPhi);
   fChain->SetBranchAddress("mcGMomPID", mcGMomPID, &b_mcGMomPID);
   fChain->SetBranchAddress("mcMomPID", mcMomPID, &b_mcMomPID);
   fChain->SetBranchAddress("mcMomPt", mcMomPt, &b_mcMomPt);
   fChain->SetBranchAddress("mcMomMass", mcMomMass, &b_mcMomMass);
   fChain->SetBranchAddress("mcMomEta", mcMomEta, &b_mcMomEta);
   fChain->SetBranchAddress("mcMomPhi", mcMomPhi, &b_mcMomPhi);
   fChain->SetBranchAddress("mcIndex", mcIndex, &b_mcIndex);
   fChain->SetBranchAddress("mcDecayType", mcDecayType, &b_mcDecayType);
   fChain->SetBranchAddress("mcIsoDR03", mcIsoDR03, &b_mcIsoDR03);
   fChain->SetBranchAddress("mcCalIsoDR03", mcCalIsoDR03, &b_mcCalIsoDR03);
   fChain->SetBranchAddress("mcTrkIsoDR03", mcTrkIsoDR03, &b_mcTrkIsoDR03);
   fChain->SetBranchAddress("mcIsoDR04", mcIsoDR04, &b_mcIsoDR04);
   fChain->SetBranchAddress("mcCalIsoDR04", mcCalIsoDR04, &b_mcCalIsoDR04);
   fChain->SetBranchAddress("mcTrkIsoDR04", mcTrkIsoDR04, &b_mcTrkIsoDR04);
   fChain->SetBranchAddress("genMET", &genMET, &b_genMET);
   fChain->SetBranchAddress("genMETx", &genMETx, &b_genMETx);
   fChain->SetBranchAddress("genMETy", &genMETy, &b_genMETy);
   fChain->SetBranchAddress("genMETPhi", &genMETPhi, &b_genMETPhi);
   fChain->SetBranchAddress("MET", &MET, &b_MET);
   fChain->SetBranchAddress("METx", &METx, &b_METx);
   fChain->SetBranchAddress("METy", &METy, &b_METy);
   fChain->SetBranchAddress("METPhi", &METPhi, &b_METPhi);
   fChain->SetBranchAddress("METsumEt", &METsumEt, &b_METsumEt);
   fChain->SetBranchAddress("uncorrMET", uncorrMET, &b_uncorrMET);
   fChain->SetBranchAddress("uncorrMETPhi", uncorrMETPhi, &b_uncorrMETPhi);
   fChain->SetBranchAddress("uncorrMETSumEt", uncorrMETSumEt, &b_uncorrMETSumEt);
   fChain->SetBranchAddress("tcMET", &tcMET, &b_tcMET);
   fChain->SetBranchAddress("tcMETx", &tcMETx, &b_tcMETx);
   fChain->SetBranchAddress("tcMETy", &tcMETy, &b_tcMETy);
   fChain->SetBranchAddress("tcMETPhi", &tcMETPhi, &b_tcMETPhi);
   fChain->SetBranchAddress("tcMETsumEt", &tcMETsumEt, &b_tcMETsumEt);
   fChain->SetBranchAddress("tcMETmEtSig", &tcMETmEtSig, &b_tcMETmEtSig);
   fChain->SetBranchAddress("tcMETSig", &tcMETSig, &b_tcMETSig);
   fChain->SetBranchAddress("pfMET", &pfMET, &b_pfMET);
   fChain->SetBranchAddress("pfMETx", &pfMETx, &b_pfMETx);
   fChain->SetBranchAddress("pfMETy", &pfMETy, &b_pfMETy);
   fChain->SetBranchAddress("pfMETPhi", &pfMETPhi, &b_pfMETPhi);
   fChain->SetBranchAddress("pfMETsumEt", &pfMETsumEt, &b_pfMETsumEt);
   fChain->SetBranchAddress("pfMETmEtSig", &pfMETmEtSig, &b_pfMETmEtSig);
   fChain->SetBranchAddress("pfMETSig", &pfMETSig, &b_pfMETSig);
   fChain->SetBranchAddress("TypeIpfMET", &TypeIpfMET, &b_TypeIpfMET);
   fChain->SetBranchAddress("TypeIpfMETx", &TypeIpfMETx, &b_TypeIpfMETx);
   fChain->SetBranchAddress("TypeIpfMETy", &TypeIpfMETy, &b_TypeIpfMETy);
   fChain->SetBranchAddress("TypeIpfMETPhi", &TypeIpfMETPhi, &b_TypeIpfMETPhi);
   fChain->SetBranchAddress("TypeIpfMETsumEt", &TypeIpfMETsumEt, &b_TypeIpfMETsumEt);
   fChain->SetBranchAddress("TypeIpfMETmEtSig", &TypeIpfMETmEtSig, &b_TypeIpfMETmEtSig);
   fChain->SetBranchAddress("TypeIpfMETSig", &TypeIpfMETSig, &b_TypeIpfMETSig);
   fChain->SetBranchAddress("TypeIpIIpfMET", &TypeIpIIpfMET, &b_TypeIpIIpfMET);
   fChain->SetBranchAddress("TypeIpIIpfMETx", &TypeIpIIpfMETx, &b_TypeIpIIpfMETx);
   fChain->SetBranchAddress("TypeIpIIpfMETy", &TypeIpIIpfMETy, &b_TypeIpIIpfMETy);
   fChain->SetBranchAddress("TypeIpIIpfMETPhi", &TypeIpIIpfMETPhi, &b_TypeIpIIpfMETPhi);
   fChain->SetBranchAddress("TypeIpIIpfMETsumEt", &TypeIpIIpfMETsumEt, &b_TypeIpIIpfMETsumEt);
   fChain->SetBranchAddress("TypeIpIIpfMETmEtSig", &TypeIpIIpfMETmEtSig, &b_TypeIpIIpfMETmEtSig);
   fChain->SetBranchAddress("TypeIpIIpfMETSig", &TypeIpIIpfMETSig, &b_TypeIpIIpfMETSig);
   fChain->SetBranchAddress("SmearedpfMET", &SmearedpfMET, &b_SmearedpfMET);
   fChain->SetBranchAddress("SmearedpfMETx", &SmearedpfMETx, &b_SmearedpfMETx);
   fChain->SetBranchAddress("SmearedpfMETy", &SmearedpfMETy, &b_SmearedpfMETy);
   fChain->SetBranchAddress("SmearedpfMETPhi", &SmearedpfMETPhi, &b_SmearedpfMETPhi);
   fChain->SetBranchAddress("SmearedpfMETsumEt", &SmearedpfMETsumEt, &b_SmearedpfMETsumEt);
   fChain->SetBranchAddress("SmearedpfMETmEtSig", &SmearedpfMETmEtSig, &b_SmearedpfMETmEtSig);
   fChain->SetBranchAddress("SmearedpfMETSig", &SmearedpfMETSig, &b_SmearedpfMETSig);
   fChain->SetBranchAddress("SmearedTypeIpfMET", &SmearedTypeIpfMET, &b_SmearedTypeIpfMET);
   fChain->SetBranchAddress("SmearedTypeIpfMETx", &SmearedTypeIpfMETx, &b_SmearedTypeIpfMETx);
   fChain->SetBranchAddress("SmearedTypeIpfMETy", &SmearedTypeIpfMETy, &b_SmearedTypeIpfMETy);
   fChain->SetBranchAddress("SmearedTypeIpfMETPhi", &SmearedTypeIpfMETPhi, &b_SmearedTypeIpfMETPhi);
   fChain->SetBranchAddress("SmearedTypeIpfMETsumEt", &SmearedTypeIpfMETsumEt, &b_SmearedTypeIpfMETsumEt);
   fChain->SetBranchAddress("SmearedTypeIpfMETmEtSig", &SmearedTypeIpfMETmEtSig, &b_SmearedTypeIpfMETmEtSig);
   fChain->SetBranchAddress("SmearedTypeIpfMETSig", &SmearedTypeIpfMETSig, &b_SmearedTypeIpfMETSig);
   fChain->SetBranchAddress("npfCharged", &npfCharged, &b_npfCharged);
   fChain->SetBranchAddress("pfChargedSumPt", &pfChargedSumPt, &b_pfChargedSumPt);
   fChain->SetBranchAddress("npfChargedHadron", &npfChargedHadron, &b_npfChargedHadron);
   fChain->SetBranchAddress("pfChargedHadronSumPt", &pfChargedHadronSumPt, &b_pfChargedHadronSumPt);
   fChain->SetBranchAddress("npfLepton", &npfLepton, &b_npfLepton);
   fChain->SetBranchAddress("pfLeptonSumPt", &pfLeptonSumPt, &b_pfLeptonSumPt);
   fChain->SetBranchAddress("npfNeutral", &npfNeutral, &b_npfNeutral);
   fChain->SetBranchAddress("pfNeutralSumPt", &pfNeutralSumPt, &b_pfNeutralSumPt);
   fChain->SetBranchAddress("npfNeutralHadron", &npfNeutralHadron, &b_npfNeutralHadron);
   fChain->SetBranchAddress("pfNeutralHadronSumPt", &pfNeutralHadronSumPt, &b_pfNeutralHadronSumPt);
   fChain->SetBranchAddress("npfPhoton", &npfPhoton, &b_npfPhoton);
   fChain->SetBranchAddress("pfPhotonSumPt", &pfPhotonSumPt, &b_pfPhotonSumPt);
   fChain->SetBranchAddress("nEle", &nEle, &b_nEle);
   fChain->SetBranchAddress("eleTrg", eleTrg, &b_eleTrg);
   fChain->SetBranchAddress("eleID", eleID, &b_eleID);
   fChain->SetBranchAddress("eleIDLH", eleIDLH, &b_eleIDLH);
   fChain->SetBranchAddress("eleClass", eleClass, &b_eleClass);
   fChain->SetBranchAddress("eleCharge", eleCharge, &b_eleCharge);
   fChain->SetBranchAddress("eleEn", eleEn, &b_eleEn);
   fChain->SetBranchAddress("eleSCRawEn", eleSCRawEn, &b_eleSCRawEn);
   fChain->SetBranchAddress("eleESEn", eleESEn, &b_eleESEn);
   fChain->SetBranchAddress("eleSCEn", eleSCEn, &b_eleSCEn);
   fChain->SetBranchAddress("elePt", elePt, &b_elePt);
   fChain->SetBranchAddress("elePz", elePz, &b_elePz);
   fChain->SetBranchAddress("eleEta", eleEta, &b_eleEta);
   fChain->SetBranchAddress("elePhi", elePhi, &b_elePhi);
   fChain->SetBranchAddress("eleSCEta", eleSCEta, &b_eleSCEta);
   fChain->SetBranchAddress("eleSCPhi", eleSCPhi, &b_eleSCPhi);
   fChain->SetBranchAddress("eleSCEtaWidth", eleSCEtaWidth, &b_eleSCEtaWidth);
   fChain->SetBranchAddress("eleSCPhiWidth", eleSCPhiWidth, &b_eleSCPhiWidth);
   fChain->SetBranchAddress("eleVtx", eleVtx, &b_eleVtx);
   fChain->SetBranchAddress("eleCaloPos", eleCaloPos, &b_eleCaloPos);
   fChain->SetBranchAddress("eleSCPos", eleSCPos, &b_eleSCPos);
   fChain->SetBranchAddress("eleHoverE", eleHoverE, &b_eleHoverE);
   fChain->SetBranchAddress("eleEoverP", eleEoverP, &b_eleEoverP);
   fChain->SetBranchAddress("elePin", elePin, &b_elePin);
   fChain->SetBranchAddress("elePout", elePout, &b_elePout);
   fChain->SetBranchAddress("eleBrem", eleBrem, &b_eleBrem);
   fChain->SetBranchAddress("elenBrem", elenBrem, &b_elenBrem);
   fChain->SetBranchAddress("eledEtaAtVtx", eledEtaAtVtx, &b_eledEtaAtVtx);
   fChain->SetBranchAddress("eledPhiAtVtx", eledPhiAtVtx, &b_eledPhiAtVtx);
   fChain->SetBranchAddress("eleSigmaEtaEta", eleSigmaEtaEta, &b_eleSigmaEtaEta);
   fChain->SetBranchAddress("eleSigmaIEtaIEta", eleSigmaIEtaIEta, &b_eleSigmaIEtaIEta);
   fChain->SetBranchAddress("eleSigmaIEtaIPhi", eleSigmaIEtaIPhi, &b_eleSigmaIEtaIPhi);
   fChain->SetBranchAddress("eleSigmaIPhiIPhi", eleSigmaIPhiIPhi, &b_eleSigmaIPhiIPhi);
   fChain->SetBranchAddress("eleE3x3", eleE3x3, &b_eleE3x3);
   fChain->SetBranchAddress("eleSeedTime", eleSeedTime, &b_eleSeedTime);
   fChain->SetBranchAddress("eleSeedEnergy", eleSeedEnergy, &b_eleSeedEnergy);
   fChain->SetBranchAddress("eleRecoFlag", eleRecoFlag, &b_eleRecoFlag);
   fChain->SetBranchAddress("eleSeverity", eleSeverity, &b_eleSeverity);
   fChain->SetBranchAddress("eleGenIndex", eleGenIndex, &b_eleGenIndex);
   fChain->SetBranchAddress("eleGenGMomPID", eleGenGMomPID, &b_eleGenGMomPID);
   fChain->SetBranchAddress("eleGenMomPID", eleGenMomPID, &b_eleGenMomPID);
   fChain->SetBranchAddress("eleGenMomPt", eleGenMomPt, &b_eleGenMomPt);
   fChain->SetBranchAddress("eleIsoTrkDR03", eleIsoTrkDR03, &b_eleIsoTrkDR03);
   fChain->SetBranchAddress("eleIsoEcalDR03", eleIsoEcalDR03, &b_eleIsoEcalDR03);
   fChain->SetBranchAddress("eleIsoHcalDR03", eleIsoHcalDR03, &b_eleIsoHcalDR03);
   fChain->SetBranchAddress("eleIsoHcalSolidDR03", eleIsoHcalSolidDR03, &b_eleIsoHcalSolidDR03);
   fChain->SetBranchAddress("eleIsoTrkDR04", eleIsoTrkDR04, &b_eleIsoTrkDR04);
   fChain->SetBranchAddress("eleIsoEcalDR04", eleIsoEcalDR04, &b_eleIsoEcalDR04);
   fChain->SetBranchAddress("eleIsoHcalDR04", eleIsoHcalDR04, &b_eleIsoHcalDR04);
   fChain->SetBranchAddress("eleIsoHcalSolidDR04", eleIsoHcalSolidDR04, &b_eleIsoHcalSolidDR04);
   fChain->SetBranchAddress("eleConvDist", eleConvDist, &b_eleConvDist);
   fChain->SetBranchAddress("eleConvDcot", eleConvDcot, &b_eleConvDcot);
   fChain->SetBranchAddress("eleConvRadius", eleConvRadius, &b_eleConvRadius);
   fChain->SetBranchAddress("eleConvFlag", eleConvFlag, &b_eleConvFlag);
   fChain->SetBranchAddress("eleConvMissinghit", eleConvMissinghit, &b_eleConvMissinghit);
   fChain->SetBranchAddress("eleESRatio", eleESRatio, &b_eleESRatio);
   fChain->SetBranchAddress("eleESProfileFront", eleESProfileFront, &b_eleESProfileFront);
   fChain->SetBranchAddress("eleESProfileRear", eleESProfileRear, &b_eleESProfileRear);
   fChain->SetBranchAddress("elePV2D", elePV2D, &b_elePV2D);
   fChain->SetBranchAddress("elePV3D", elePV3D, &b_elePV3D);
   fChain->SetBranchAddress("eleBS2D", eleBS2D, &b_eleBS2D);
   fChain->SetBranchAddress("eleBS3D", eleBS3D, &b_eleBS3D);
   fChain->SetBranchAddress("elePVD0", elePVD0, &b_elePVD0);
   fChain->SetBranchAddress("elePVDz", elePVDz, &b_elePVDz);
   fChain->SetBranchAddress("nPho", &nPho, &b_nPho);
   fChain->SetBranchAddress("phoTrg", phoTrg, &b_phoTrg);
   fChain->SetBranchAddress("phoIsPhoton", phoIsPhoton, &b_phoIsPhoton);
   fChain->SetBranchAddress("phoE", phoE, &b_phoE);
   fChain->SetBranchAddress("phoEt", phoEt, &b_phoEt);
   fChain->SetBranchAddress("phoPz", phoPz, &b_phoPz);
   fChain->SetBranchAddress("phoEta", phoEta, &b_phoEta);
   fChain->SetBranchAddress("phoPhi", phoPhi, &b_phoPhi);
   fChain->SetBranchAddress("phoR9", phoR9, &b_phoR9);
   fChain->SetBranchAddress("phoTrkIsoSolidDR03", phoTrkIsoSolidDR03, &b_phoTrkIsoSolidDR03);
   fChain->SetBranchAddress("phoTrkIsoHollowDR03", phoTrkIsoHollowDR03, &b_phoTrkIsoHollowDR03);
   fChain->SetBranchAddress("phoNTrkSolidDR03", phoNTrkSolidDR03, &b_phoNTrkSolidDR03);
   fChain->SetBranchAddress("phoNTrkHollowDR03", phoNTrkHollowDR03, &b_phoNTrkHollowDR03);
   fChain->SetBranchAddress("phoEcalIsoDR03", phoEcalIsoDR03, &b_phoEcalIsoDR03);
   fChain->SetBranchAddress("phoHcalIsoDR03", phoHcalIsoDR03, &b_phoHcalIsoDR03);
   fChain->SetBranchAddress("phoHcalIsoSolidDR03", phoHcalIsoSolidDR03, &b_phoHcalIsoSolidDR03);
   fChain->SetBranchAddress("phoTrkIsoSolidDR04", phoTrkIsoSolidDR04, &b_phoTrkIsoSolidDR04);
   fChain->SetBranchAddress("phoTrkIsoHollowDR04", phoTrkIsoHollowDR04, &b_phoTrkIsoHollowDR04);
   fChain->SetBranchAddress("phoNTrkSolidDR04", phoNTrkSolidDR04, &b_phoNTrkSolidDR04);
   fChain->SetBranchAddress("phoNTrkHollowDR04", phoNTrkHollowDR04, &b_phoNTrkHollowDR04);
   fChain->SetBranchAddress("phoEcalIsoDR04", phoEcalIsoDR04, &b_phoEcalIsoDR04);
   fChain->SetBranchAddress("phoHcalIsoDR04", phoHcalIsoDR04, &b_phoHcalIsoDR04);
   fChain->SetBranchAddress("phoHcalIsoSolidDR04", phoHcalIsoSolidDR04, &b_phoHcalIsoSolidDR04);
   fChain->SetBranchAddress("phoEtVtx", phoEtVtx, &b_phoEtVtx);
   fChain->SetBranchAddress("phoEtaVtx", phoEtaVtx, &b_phoEtaVtx);
   fChain->SetBranchAddress("phoPhiVtx", phoPhiVtx, &b_phoPhiVtx);
   fChain->SetBranchAddress("phoTrkIsoSolidDR03Vtx", phoTrkIsoSolidDR03Vtx, &b_phoTrkIsoSolidDR03Vtx);
   fChain->SetBranchAddress("phoTrkIsoHollowDR03Vtx", phoTrkIsoHollowDR03Vtx, &b_phoTrkIsoHollowDR03Vtx);
   fChain->SetBranchAddress("phoTrkIsoSolidDR04Vtx", phoTrkIsoSolidDR04Vtx, &b_phoTrkIsoSolidDR04Vtx);
   fChain->SetBranchAddress("phoTrkIsoHollowDR04Vtx", phoTrkIsoHollowDR04Vtx, &b_phoTrkIsoHollowDR04Vtx);
   fChain->SetBranchAddress("phoHoverE", phoHoverE, &b_phoHoverE);
   fChain->SetBranchAddress("phoSigmaEtaEta", phoSigmaEtaEta, &b_phoSigmaEtaEta);
   fChain->SetBranchAddress("phoSigmaIEtaIEta", phoSigmaIEtaIEta, &b_phoSigmaIEtaIEta);
   fChain->SetBranchAddress("phoSigmaIEtaIPhi", phoSigmaIEtaIPhi, &b_phoSigmaIEtaIPhi);
   fChain->SetBranchAddress("phoSigmaIPhiIPhi", phoSigmaIPhiIPhi, &b_phoSigmaIPhiIPhi);
   fChain->SetBranchAddress("phoE3x3", phoE3x3, &b_phoE3x3);
   fChain->SetBranchAddress("phoE5x5", phoE5x5, &b_phoE5x5);
   fChain->SetBranchAddress("phoSeedTime", phoSeedTime, &b_phoSeedTime);
   fChain->SetBranchAddress("phoSeedEnergy", phoSeedEnergy, &b_phoSeedEnergy);
   fChain->SetBranchAddress("phoRecoFlag", phoRecoFlag, &b_phoRecoFlag);
   fChain->SetBranchAddress("phoSeverity", phoSeverity, &b_phoSeverity);
   fChain->SetBranchAddress("phoPos", phoPos, &b_phoPos);
   fChain->SetBranchAddress("phoGenIndex", phoGenIndex, &b_phoGenIndex);
   fChain->SetBranchAddress("phoGenGMomPID", phoGenGMomPID, &b_phoGenGMomPID);
   fChain->SetBranchAddress("phoGenMomPID", phoGenMomPID, &b_phoGenMomPID);
   fChain->SetBranchAddress("phoGenMomPt", phoGenMomPt, &b_phoGenMomPt);
   fChain->SetBranchAddress("phoSCE", phoSCE, &b_phoSCE);
   fChain->SetBranchAddress("phoESE", phoESE, &b_phoESE);
   fChain->SetBranchAddress("phoSCEt", phoSCEt, &b_phoSCEt);
   fChain->SetBranchAddress("phoSCEta", phoSCEta, &b_phoSCEta);
   fChain->SetBranchAddress("phoSCPhi", phoSCPhi, &b_phoSCPhi);
   fChain->SetBranchAddress("phoSCEtaWidth", phoSCEtaWidth, &b_phoSCEtaWidth);
   fChain->SetBranchAddress("phoSCPhiWidth", phoSCPhiWidth, &b_phoSCPhiWidth);
   fChain->SetBranchAddress("phoVtx", phoVtx, &b_phoVtx);
   fChain->SetBranchAddress("phoVtxD0", phoVtxD0, &b_phoVtxD0);
   fChain->SetBranchAddress("phoOverlap", phoOverlap, &b_phoOverlap);
   fChain->SetBranchAddress("phohasPixelSeed", phohasPixelSeed, &b_phohasPixelSeed);
   fChain->SetBranchAddress("phoIsConv", phoIsConv, &b_phoIsConv);
   fChain->SetBranchAddress("phoESRatio", phoESRatio, &b_phoESRatio);
   fChain->SetBranchAddress("phoESProfileFront", phoESProfileFront, &b_phoESProfileFront);
   fChain->SetBranchAddress("phoESProfileRear", phoESProfileRear, &b_phoESProfileRear);
   fChain->SetBranchAddress("phoNTracks", phoNTracks, &b_phoNTracks);
   fChain->SetBranchAddress("phoConvPairInvariantMass", phoConvPairInvariantMass, &b_phoConvPairInvariantMass);
   fChain->SetBranchAddress("phoConvPairCotThetaSeparation", phoConvPairCotThetaSeparation, &b_phoConvPairCotThetaSeparation);
   fChain->SetBranchAddress("phoConvPairMomentumEta", phoConvPairMomentumEta, &b_phoConvPairMomentumEta);
   fChain->SetBranchAddress("phoConvPairMomentumPhi", phoConvPairMomentumPhi, &b_phoConvPairMomentumPhi);
   fChain->SetBranchAddress("phoConvPairMomentumX", phoConvPairMomentumX, &b_phoConvPairMomentumX);
   fChain->SetBranchAddress("phoConvPairMomentumY", phoConvPairMomentumY, &b_phoConvPairMomentumY);
   fChain->SetBranchAddress("phoConvPairMomentumZ", phoConvPairMomentumZ, &b_phoConvPairMomentumZ);
   fChain->SetBranchAddress("phoConvDistOfMinimumApproach", phoConvDistOfMinimumApproach, &b_phoConvDistOfMinimumApproach);
   fChain->SetBranchAddress("phoConvDPhiTracksAtVtx", phoConvDPhiTracksAtVtx, &b_phoConvDPhiTracksAtVtx);
   fChain->SetBranchAddress("phoConvDPhiTracksAtEcal", phoConvDPhiTracksAtEcal, &b_phoConvDPhiTracksAtEcal);
   fChain->SetBranchAddress("phoConvDEtaTracksAtEcal", phoConvDEtaTracksAtEcal, &b_phoConvDEtaTracksAtEcal);
   fChain->SetBranchAddress("phoConvVtxValid", phoConvVtxValid, &b_phoConvVtxValid);
   fChain->SetBranchAddress("phoConvVtxEta", phoConvVtxEta, &b_phoConvVtxEta);
   fChain->SetBranchAddress("phoConvVtxPhi", phoConvVtxPhi, &b_phoConvVtxPhi);
   fChain->SetBranchAddress("phoConvVtxR", phoConvVtxR, &b_phoConvVtxR);
   fChain->SetBranchAddress("phoConvVtxX", phoConvVtxX, &b_phoConvVtxX);
   fChain->SetBranchAddress("phoConvVtxY", phoConvVtxY, &b_phoConvVtxY);
   fChain->SetBranchAddress("phoConvVtxZ", phoConvVtxZ, &b_phoConvVtxZ);
   fChain->SetBranchAddress("phoConvVtxChi2", phoConvVtxChi2, &b_phoConvVtxChi2);
   fChain->SetBranchAddress("phoConvVtxNdof", phoConvVtxNdof, &b_phoConvVtxNdof);
   fChain->SetBranchAddress("phoConvChi2Prob", phoConvChi2Prob, &b_phoConvChi2Prob);
   fChain->SetBranchAddress("phoConvEoverP", phoConvEoverP, &b_phoConvEoverP);
   fChain->SetBranchAddress("phoNxtal", phoNxtal, &b_phoNxtal);
   fChain->SetBranchAddress("phoXtalTime", phoXtalTime, &b_phoXtalTime);
   fChain->SetBranchAddress("phoXtalEnergy", phoXtalEnergy, &b_phoXtalEnergy);
   fChain->SetBranchAddress("phoXtalZ", phoXtalZ, &b_phoXtalZ);
   fChain->SetBranchAddress("phoXtalX", phoXtalX, &b_phoXtalX);
   fChain->SetBranchAddress("phoXtalY", phoXtalY, &b_phoXtalY);
   fChain->SetBranchAddress("phoXtalEta", phoXtalEta, &b_phoXtalEta);
   fChain->SetBranchAddress("phoXtalPhi", phoXtalPhi, &b_phoXtalPhi);
   fChain->SetBranchAddress("pho5x5Time", pho5x5Time, &b_pho5x5Time);
   fChain->SetBranchAddress("pho5x5Energy", pho5x5Energy, &b_pho5x5Energy);
   fChain->SetBranchAddress("pho5x5Z", pho5x5Z, &b_pho5x5Z);
   fChain->SetBranchAddress("pho5x5X", pho5x5X, &b_pho5x5X);
   fChain->SetBranchAddress("pho5x5Y", pho5x5Y, &b_pho5x5Y);
   fChain->SetBranchAddress("pho5x5Eta", pho5x5Eta, &b_pho5x5Eta);
   fChain->SetBranchAddress("pho5x5Phi", pho5x5Phi, &b_pho5x5Phi);
   fChain->SetBranchAddress("nMu", &nMu, &b_nMu);
   fChain->SetBranchAddress("muTrg", muTrg, &b_muTrg);
   fChain->SetBranchAddress("muEta", muEta, &b_muEta);
   fChain->SetBranchAddress("muPhi", muPhi, &b_muPhi);
   fChain->SetBranchAddress("muCharge", muCharge, &b_muCharge);
   fChain->SetBranchAddress("muPt", muPt, &b_muPt);
   fChain->SetBranchAddress("muPz", muPz, &b_muPz);
   fChain->SetBranchAddress("muGenIndex", muGenIndex, &b_muGenIndex);
   fChain->SetBranchAddress("muGenGMomPID", muGenGMomPID, &b_muGenGMomPID);
   fChain->SetBranchAddress("muGenMomPID", muGenMomPID, &b_muGenMomPID);
   fChain->SetBranchAddress("muGenMomPt", muGenMomPt, &b_muGenMomPt);
   fChain->SetBranchAddress("muIsoTrk", muIsoTrk, &b_muIsoTrk);
   fChain->SetBranchAddress("muIsoCalo", muIsoCalo, &b_muIsoCalo);
   fChain->SetBranchAddress("muIsoEcal", muIsoEcal, &b_muIsoEcal);
   fChain->SetBranchAddress("muIsoHcal", muIsoHcal, &b_muIsoHcal);
   fChain->SetBranchAddress("muChi2NDF", muChi2NDF, &b_muChi2NDF);
   fChain->SetBranchAddress("muEmVeto", muEmVeto, &b_muEmVeto);
   fChain->SetBranchAddress("muHadVeto", muHadVeto, &b_muHadVeto);
   fChain->SetBranchAddress("muType", muType, &b_muType);
   fChain->SetBranchAddress("muID", muID, &b_muID);
   fChain->SetBranchAddress("muD0", muD0, &b_muD0);
   fChain->SetBranchAddress("muDz", muDz, &b_muDz);
   fChain->SetBranchAddress("muPVD0", muPVD0, &b_muPVD0);
   fChain->SetBranchAddress("muPVDz", muPVDz, &b_muPVDz);
   fChain->SetBranchAddress("muValidFraction", muValidFraction, &b_muValidFraction);
   fChain->SetBranchAddress("muTrkdPt", muTrkdPt, &b_muTrkdPt);
   fChain->SetBranchAddress("muNumberOfHits", muNumberOfHits, &b_muNumberOfHits);
   fChain->SetBranchAddress("muNumberOfValidHits", muNumberOfValidHits, &b_muNumberOfValidHits);
   fChain->SetBranchAddress("muNumberOfInactiveHits", muNumberOfInactiveHits, &b_muNumberOfInactiveHits);
   fChain->SetBranchAddress("muNumberOfValidTrkHits", muNumberOfValidTrkHits, &b_muNumberOfValidTrkHits);
   fChain->SetBranchAddress("muNumberOfValidPixelHits", muNumberOfValidPixelHits, &b_muNumberOfValidPixelHits);
   fChain->SetBranchAddress("muNumberOfValidMuonHits", muNumberOfValidMuonHits, &b_muNumberOfValidMuonHits);
   fChain->SetBranchAddress("muStations", muStations, &b_muStations);
   fChain->SetBranchAddress("muChambers", muChambers, &b_muChambers);
   fChain->SetBranchAddress("muPV2D", muPV2D, &b_muPV2D);
   fChain->SetBranchAddress("muPV3D", muPV3D, &b_muPV3D);
   fChain->SetBranchAddress("muBS2D", muBS2D, &b_muBS2D);
   fChain->SetBranchAddress("muBS3D", muBS3D, &b_muBS3D);
   fChain->SetBranchAddress("muVtx", muVtx, &b_muVtx);
   fChain->SetBranchAddress("nJet", &nJet, &b_nJet);
   fChain->SetBranchAddress("jetTrg", jetTrg, &b_jetTrg);
   fChain->SetBranchAddress("jetEn", jetEn, &b_jetEn);
   fChain->SetBranchAddress("jetPt", jetPt, &b_jetPt);
   fChain->SetBranchAddress("jetEta", jetEta, &b_jetEta);
   fChain->SetBranchAddress("jetPhi", jetPhi, &b_jetPhi);
   fChain->SetBranchAddress("jetMass", jetMass, &b_jetMass);
   fChain->SetBranchAddress("jetEt", jetEt, &b_jetEt);
   fChain->SetBranchAddress("jetpartonFlavour", jetpartonFlavour, &b_jetpartonFlavour);
   fChain->SetBranchAddress("jetRawPt", jetRawPt, &b_jetRawPt);
   fChain->SetBranchAddress("jetRawEn", jetRawEn, &b_jetRawEn);
   fChain->SetBranchAddress("jetCharge", jetCharge, &b_jetCharge);
   fChain->SetBranchAddress("jetNeutralEmEnergy", jetNeutralEmEnergy, &b_jetNeutralEmEnergy);
   fChain->SetBranchAddress("jetNeutralEmEnergyFraction", jetNeutralEmEnergyFraction, &b_jetNeutralEmEnergyFraction);
   fChain->SetBranchAddress("jetNeutralHadronEnergy", jetNeutralHadronEnergy, &b_jetNeutralHadronEnergy);
   fChain->SetBranchAddress("jetNeutralHadronEnergyFraction", jetNeutralHadronEnergyFraction, &b_jetNeutralHadronEnergyFraction);
   fChain->SetBranchAddress("jetNConstituents", jetNConstituents, &b_jetNConstituents);
   fChain->SetBranchAddress("jetChargedEmEnergy", jetChargedEmEnergy, &b_jetChargedEmEnergy);
   fChain->SetBranchAddress("jetChargedEmEnergyFraction", jetChargedEmEnergyFraction, &b_jetChargedEmEnergyFraction);
   fChain->SetBranchAddress("jetChargedHadronEnergy", jetChargedHadronEnergy, &b_jetChargedHadronEnergy);
   fChain->SetBranchAddress("jetChargedHadronEnergyFraction", jetChargedHadronEnergyFraction, &b_jetChargedHadronEnergyFraction);
   fChain->SetBranchAddress("jetChargedHadronMultiplicity", jetChargedHadronMultiplicity, &b_jetChargedHadronMultiplicity);
   fChain->SetBranchAddress("jetChargedMuEnergy", jetChargedMuEnergy, &b_jetChargedMuEnergy);
   fChain->SetBranchAddress("jetChargedMuEnergyFraction", jetChargedMuEnergyFraction, &b_jetChargedMuEnergyFraction);
   fChain->SetBranchAddress("jetJVAlpha", jetJVAlpha, &b_jetJVAlpha);
   fChain->SetBranchAddress("jetJVBeta", jetJVBeta, &b_jetJVBeta);
   fChain->SetBranchAddress("jetGenJetIndex", jetGenJetIndex, &b_jetGenJetIndex);
   fChain->SetBranchAddress("jetGenJetEn", jetGenJetEn, &b_jetGenJetEn);
   fChain->SetBranchAddress("jetGenJetPt", jetGenJetPt, &b_jetGenJetPt);
   fChain->SetBranchAddress("jetGenJetEta", jetGenJetEta, &b_jetGenJetEta);
   fChain->SetBranchAddress("jetGenJetPhi", jetGenJetPhi, &b_jetGenJetPhi);
   fChain->SetBranchAddress("jetGenJetMass", jetGenJetMass, &b_jetGenJetMass);
   fChain->SetBranchAddress("jetGenPartonID", jetGenPartonID, &b_jetGenPartonID);
   fChain->SetBranchAddress("jetGenPartonMomID", jetGenPartonMomID, &b_jetGenPartonMomID);
   fChain->SetBranchAddress("nZee", &nZee, &b_nZee);
   fChain->SetBranchAddress("ZeeMass", ZeeMass, &b_ZeeMass);
   fChain->SetBranchAddress("ZeePt", ZeePt, &b_ZeePt);
   fChain->SetBranchAddress("ZeeEta", ZeeEta, &b_ZeeEta);
   fChain->SetBranchAddress("ZeePhi", ZeePhi, &b_ZeePhi);
   fChain->SetBranchAddress("ZeeLeg1Index", ZeeLeg1Index, &b_ZeeLeg1Index);
   fChain->SetBranchAddress("ZeeLeg2Index", ZeeLeg2Index, &b_ZeeLeg2Index);
   fChain->SetBranchAddress("nZmumu", &nZmumu, &b_nZmumu);
   fChain->SetBranchAddress("ZmumuMass", ZmumuMass, &b_ZmumuMass);
   fChain->SetBranchAddress("ZmumuPt", ZmumuPt, &b_ZmumuPt);
   fChain->SetBranchAddress("ZmumuEta", ZmumuEta, &b_ZmumuEta);
   fChain->SetBranchAddress("ZmumuPhi", ZmumuPhi, &b_ZmumuPhi);
   fChain->SetBranchAddress("ZmumuLeg1Index", ZmumuLeg1Index, &b_ZmumuLeg1Index);
   fChain->SetBranchAddress("ZmumuLeg2Index", ZmumuLeg2Index, &b_ZmumuLeg2Index);
   fChain->SetBranchAddress("nWenu", &nWenu, &b_nWenu);
   fChain->SetBranchAddress("WenuMassTCaloMET", WenuMassTCaloMET, &b_WenuMassTCaloMET);
   fChain->SetBranchAddress("WenuEtCaloMET", WenuEtCaloMET, &b_WenuEtCaloMET);
   fChain->SetBranchAddress("WenuACopCaloMET", WenuACopCaloMET, &b_WenuACopCaloMET);
   fChain->SetBranchAddress("WenuMassTTcMET", WenuMassTTcMET, &b_WenuMassTTcMET);
   fChain->SetBranchAddress("WenuEtTcMET", WenuEtTcMET, &b_WenuEtTcMET);
   fChain->SetBranchAddress("WenuACopTcMET", WenuACopTcMET, &b_WenuACopTcMET);
   fChain->SetBranchAddress("WenuMassTPfMET", WenuMassTPfMET, &b_WenuMassTPfMET);
   fChain->SetBranchAddress("WenuEtPfMET", WenuEtPfMET, &b_WenuEtPfMET);
   fChain->SetBranchAddress("WenuACopPfMET", WenuACopPfMET, &b_WenuACopPfMET);
   fChain->SetBranchAddress("WenuEleIndex", WenuEleIndex, &b_WenuEleIndex);
   fChain->SetBranchAddress("nWmunu", &nWmunu, &b_nWmunu);
   fChain->SetBranchAddress("WmunuMassTCaloMET", WmunuMassTCaloMET, &b_WmunuMassTCaloMET);
   fChain->SetBranchAddress("WmunuEtCaloMET", WmunuEtCaloMET, &b_WmunuEtCaloMET);
   fChain->SetBranchAddress("WmunuACopCaloMET", WmunuACopCaloMET, &b_WmunuACopCaloMET);
   fChain->SetBranchAddress("WmunuMassTTcMET", WmunuMassTTcMET, &b_WmunuMassTTcMET);
   fChain->SetBranchAddress("WmunuEtTcMET", WmunuEtTcMET, &b_WmunuEtTcMET);
   fChain->SetBranchAddress("WmunuACopTcMET", WmunuACopTcMET, &b_WmunuACopTcMET);
   fChain->SetBranchAddress("WmunuMassTPfMET", WmunuMassTPfMET, &b_WmunuMassTPfMET);
   fChain->SetBranchAddress("WmunuEtPfMET", WmunuEtPfMET, &b_WmunuEtPfMET);
   fChain->SetBranchAddress("WmunuACopPfMET", WmunuACopPfMET, &b_WmunuACopPfMET);
   fChain->SetBranchAddress("WmunuMuIndex", WmunuMuIndex, &b_WmunuMuIndex);
   Notify();
}

Bool_t Skim::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void Skim::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t Skim::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef Skim_cxx
