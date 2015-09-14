   Int_t           run;
   Int_t           event;
   Int_t           orbit;
   Int_t           bx;
   Int_t           lumis;
   Bool_t          isData;
   Int_t           ttbit0;
   Int_t           nHLT;
   Int_t           HLT[119];   //[nHLT]
   Int_t           HLTIndex[50];
   Int_t           nHFTowersP;
   Int_t           nHFTowersN;
   Int_t           nVtx;
   Float_t         vtx[4][3];   //[nVtx]
   Int_t           vtxNTrk[4];   //[nVtx]
   Int_t           vtxNDF[4];   //[nVtx]
   Float_t         vtxD0[4];   //[nVtx]
   Int_t           IsVtxGood;
   Int_t           nTrk;
   Int_t           nGoodTrk;
   Int_t           IsTracksGood;
   Float_t         pdf[7];
   Float_t         pthat;
   Float_t         processID;
   Int_t           nMC;
   Int_t           mcPID[20];   //[nMC]
   Float_t         mcPt[20];   //[nMC]
   Float_t         mcMass[20];   //[nMC]
   Float_t         mcEta[20];   //[nMC]
   Float_t         mcPhi[20];   //[nMC]
   Int_t           mcGMomPID[20];   //[nMC]
   Int_t           mcMomPID[20];   //[nMC]
   Float_t         mcMomPt[20];   //[nMC]
   Float_t         mcMomMass[20];   //[nMC]
   Float_t         mcMomEta[20];   //[nMC]
   Float_t         mcMomPhi[20];   //[nMC]
   Int_t           mcIndex[20];   //[nMC]
   Int_t           mcDecayType[20];   //[nMC]
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
   Int_t           nEle;
   Int_t           eleTrg[7][13];   //[nEle]
   Int_t           eleID[7][12];   //[nEle]
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
   Float_t         eledEtaAtVtx[7];   //[nEle]
   Float_t         eledPhiAtVtx[7];   //[nEle]
   Float_t         eleSigmaEtaEta[7];   //[nEle]
   Float_t         eleSigmaIEtaIEta[7];   //[nEle]
   Float_t         eleE2overE9[7];   //[nEle]
   Float_t         eleE3x3[7];   //[nEle]
   Float_t         eleSeedTime[7];   //[nEle]
   Int_t           eleRecoFlag[7];   //[nEle]
   Int_t           eleSeverity[7];   //[nEle]
   Int_t           eleGenIndex[7];   //[nEle]
   Int_t           eleGenGMomPID[7];   //[nEle]
   Int_t           eleGenMomPID[7];   //[nEle]
   Float_t         eleGenMomPt[7];   //[nEle]
   Float_t         eleIsoTrkDR03[7];   //[nEle]
   Float_t         eleIsoEcalDR03[7];   //[nEle]
   Float_t         eleIsoHcalDR03[7];   //[nEle]
   Float_t         eleIsoTrkDR04[7];   //[nEle]
   Float_t         eleIsoEcalDR04[7];   //[nEle]
   Float_t         eleIsoHcalDR04[7];   //[nEle]
   Int_t           nPho;
   Int_t           phoTrg[6][8];   //[nPho]
   Bool_t          phoIsPhoton[6];   //[nPho]
   Float_t         phoE[6];   //[nPho]
   Float_t         phoEt[6];   //[nPho]
   Float_t         phoPz[6];   //[nPho]
   Float_t         phoEta[6];   //[nPho]
   Float_t         phoPhi[6];   //[nPho]
   Float_t         phoR9[6];   //[nPho]
   Float_t         phoTrkIsoSolidDR03[6];   //[nPho]
   Float_t         phoTrkIsoHollowDR03[6];   //[nPho]
   Int_t           phoNTrkSolidDR03[6];   //[nPho]
   Int_t           phoNTrkHollowDR03[6];   //[nPho]
   Float_t         phoEcalIsoDR03[6];   //[nPho]
   Float_t         phoHcalIsoDR03[6];   //[nPho]
   Float_t         phoTrkIsoSolidDR04[6];   //[nPho]
   Float_t         phoTrkIsoHollowDR04[6];   //[nPho]
   Int_t           phoNTrkSolidDR04[6];   //[nPho]
   Int_t           phoNTrkHollowDR04[6];   //[nPho]
   Float_t         phoEcalIsoDR04[6];   //[nPho]
   Float_t         phoHcalIsoDR04[6];   //[nPho]
   Float_t         phoHoverE[6];   //[nPho]
   Float_t         phoSigmaEtaEta[6];   //[nPho]
   Float_t         phoSigmaIEtaIEta[6];   //[nPho]
   Float_t         phoE2overE9[6];   //[nPho]
   Float_t         phoE3x3[6];   //[nPho]
   Float_t         phoSeedTime[6];   //[nPho]
   Int_t           phoRecoFlag[6];   //[nPho]
   Int_t           phoSeverity[6];   //[nPho]
   Int_t           phoPos[6];   //[nPho]
   Float_t         phoRoundness[6];   //[nPho]
   Float_t         phoAngle[6];   //[nPho]
   Int_t           phoGenIndex[6];   //[nPho]
   Int_t           phoGenGMomPID[6];   //[nPho]
   Int_t           phoGenMomPID[6];   //[nPho]
   Float_t         phoGenMomPt[6];   //[nPho]
   Float_t         phoSCE[6];   //[nPho]
   Float_t         phoSCEt[6];   //[nPho]
   Float_t         phoSCEta[6];   //[nPho]
   Float_t         phoSCPhi[6];   //[nPho]
   Float_t         phoSCEtaWidth[6];   //[nPho]
   Float_t         phoSCPhiWidth[6];   //[nPho]
   Int_t           phoOverlap[6];   //[nPho]
   Int_t           phohasPixelSeed[6];   //[nPho]
   Int_t           phoIsConv[6];   //[nPho]
   Float_t         phoPi0Disc[6];   //[nPho]
   Int_t           nMu;
   Int_t           muTrg[8][6];   //[nMu]
   Float_t         muEta[8];   //[nMu]
   Float_t         muPhi[8];   //[nMu]
   Int_t           muCharge[8];   //[nMu]
   Float_t         muPt[8];   //[nMu]
   Float_t         muPz[8];   //[nMu]
   Int_t           muGenIndex[8];   //[nMu]
   Float_t         muIsoTrk[8];   //[nMu]
   Float_t         muIsoCalo[8];   //[nMu]
   Float_t         muIsoEcal[8];   //[nMu]
   Float_t         muIsoHcal[8];   //[nMu]
   Float_t         muChi2NDF[8];   //[nMu]
   Float_t         muEmVeto[8];   //[nMu]
   Float_t         muHadVeto[8];   //[nMu]
   Int_t           muType[8];   //[nMu]
   Bool_t          muID[8][6];   //[nMu]
   Float_t         muD0[8];   //[nMu]
   Float_t         muDz[8];   //[nMu]
   Int_t           muNumberOfValidTrkHits[8];   //[nMu]
   Int_t           muNumberOfValidPixelHits[8];   //[nMu]
   Int_t           muNumberOfValidMuonHits[8];   //[nMu]
   Int_t           muStations[8];   //[nMu]
   Int_t           muChambers[8];   //[nMu]
   Int_t           nJet;
   Int_t           jetTrg[11][14];   //[nJet]
   Float_t         jetEn[11];   //[nJet]
   Float_t         jetPt[11];   //[nJet]
   Float_t         jetEta[11];   //[nJet]
   Float_t         jetPhi[11];   //[nJet]
   Float_t         jetMass[11];   //[nJet]
   Float_t         jetEt[11];   //[nJet]
   Float_t         jetenergyFractionHadronic[11];   //[nJet]
   Float_t         jetemEnergyFraction[11];   //[nJet]
   Float_t         jetfHPD[11];   //[nJet]
   Int_t           jetN60[11];   //[nJet]
   Int_t           jetN90[11];   //[nJet]
   Int_t           jetGenIndex[11];   //[nJet]
   Int_t           jetGenJetIndex[11];   //[nJet]
   Float_t         jetGenJetEn[11];   //[nJet]
   Float_t         jetGenJetPt[11];   //[nJet]
   Float_t         jetGenJetEta[11];   //[nJet]
   Float_t         jetGenJetPhi[11];   //[nJet]
   Float_t         jetGenJetMass[11];   //[nJet]
   Int_t           jetGenPartonID[11];   //[nJet]
   Int_t           jetGenPartonMomID[11];   //[nJet]
   Int_t           jetpartonFlavour[11];   //[nJet]
   Float_t         jetRawPt[11];   //[nJet]
   Float_t         jetRawEn[11];   //[nJet]
   Float_t         jetCharge[11];   //[nJet]
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
