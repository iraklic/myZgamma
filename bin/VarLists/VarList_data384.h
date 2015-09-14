   Int_t           run;
   Int_t           event;
   Int_t           orbit;
   Int_t           bx;
   Int_t           lumis;
   Bool_t          isData;
   Int_t           ttbit0;
   Int_t           nHLT;
   Int_t           HLT[156];   //[nHLT]
   Int_t           HLTIndex[23];
   Int_t           nHFTowersP;
   Int_t           nHFTowersN;
   Int_t           nVtx;
   Float_t         vtx[14][3];   //[nVtx]
   Int_t           vtxNTrk[14];   //[nVtx]
   Int_t           vtxNDF[14];   //[nVtx]
   Float_t         vtxD0[14];   //[nVtx]
   Int_t           IsVtxGood;
   Int_t           nTrk;
   Int_t           nGoodTrk;
   Int_t           IsTracksGood;
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
   Int_t           eleTrg[11][7];   //[nEle]
   Int_t           eleID[11][12];   //[nEle]
   Int_t           eleClass[11];   //[nEle]
   Int_t           eleCharge[11];   //[nEle]
   Float_t         eleEn[11];   //[nEle]
   Float_t         eleSCRawEn[11];   //[nEle]
   Float_t         eleESEn[11];   //[nEle]
   Float_t         eleSCEn[11];   //[nEle]
   Float_t         elePt[11];   //[nEle]
   Float_t         elePz[11];   //[nEle]
   Float_t         eleEta[11];   //[nEle]
   Float_t         elePhi[11];   //[nEle]
   Float_t         eleSCEta[11];   //[nEle]
   Float_t         eleSCPhi[11];   //[nEle]
   Float_t         eleSCEtaWidth[11];   //[nEle]
   Float_t         eleSCPhiWidth[11];   //[nEle]
   Float_t         eleVtx[11][3];   //[nEle]
   Float_t         eleCaloPos[11][3];   //[nEle]
   Float_t         eleSCPos[11][3];   //[nEle]
   Float_t         eleHoverE[11];   //[nEle]
   Float_t         eleEoverP[11];   //[nEle]
   Float_t         elePin[11];   //[nEle]
   Float_t         elePout[11];   //[nEle]
   Float_t         eleBrem[11];   //[nEle]
   Float_t         eledEtaAtVtx[11];   //[nEle]
   Float_t         eledPhiAtVtx[11];   //[nEle]
   Float_t         eleSigmaEtaEta[11];   //[nEle]
   Float_t         eleSigmaIEtaIEta[11];   //[nEle]
   Float_t         eleE3x3[11];   //[nEle]
   Float_t         eleSeedTime[11];   //[nEle]
   Int_t           eleRecoFlag[11];   //[nEle]
   Int_t           eleSeverity[11];   //[nEle]
   Float_t         eleIsoTrkDR03[11];   //[nEle]
   Float_t         eleIsoEcalDR03[11];   //[nEle]
   Float_t         eleIsoHcalDR03[11];   //[nEle]
   Float_t         eleIsoTrkDR04[11];   //[nEle]
   Float_t         eleIsoEcalDR04[11];   //[nEle]
   Float_t         eleIsoHcalDR04[11];   //[nEle]
   Int_t           nPho;
   Int_t           phoTrg[40][4];   //[nPho]
   Bool_t          phoIsPhoton[40];   //[nPho]
   Float_t         phoE[40];   //[nPho]
   Float_t         phoEt[40];   //[nPho]
   Float_t         phoPz[40];   //[nPho]
   Float_t         phoEta[40];   //[nPho]
   Float_t         phoPhi[40];   //[nPho]
   Float_t         phoR9[40];   //[nPho]
   Float_t         phoTrkIsoSolidDR03[40];   //[nPho]
   Float_t         phoTrkIsoHollowDR03[40];   //[nPho]
   Int_t           phoNTrkSolidDR03[40];   //[nPho]
   Int_t           phoNTrkHollowDR03[40];   //[nPho]
   Float_t         phoEcalIsoDR03[40];   //[nPho]
   Float_t         phoHcalIsoDR03[40];   //[nPho]
   Float_t         phoTrkIsoSolidDR04[40];   //[nPho]
   Float_t         phoTrkIsoHollowDR04[40];   //[nPho]
   Int_t           phoNTrkSolidDR04[40];   //[nPho]
   Int_t           phoNTrkHollowDR04[40];   //[nPho]
   Float_t         phoEcalIsoDR04[40];   //[nPho]
   Float_t         phoHcalIsoDR04[40];   //[nPho]
   Float_t         phoHoverE[40];   //[nPho]
   Float_t         phoSigmaEtaEta[40];   //[nPho]
   Float_t         phoSigmaIEtaIEta[40];   //[nPho]
   Float_t         phoE3x3[40];   //[nPho]
   Float_t         phoSeedTime[40];   //[nPho]
   Int_t           phoRecoFlag[40];   //[nPho]
   Int_t           phoSeverity[40];   //[nPho]
   Int_t           phoPos[40];   //[nPho]
   Float_t         phoRoundness[40];   //[nPho]
   Float_t         phoAngle[40];   //[nPho]
   Float_t         phoSCE[40];   //[nPho]
   Float_t         phoSCEt[40];   //[nPho]
   Float_t         phoSCEta[40];   //[nPho]
   Float_t         phoSCPhi[40];   //[nPho]
   Float_t         phoSCEtaWidth[40];   //[nPho]
   Float_t         phoSCPhiWidth[40];   //[nPho]
   Int_t           phoOverlap[40];   //[nPho]
   Int_t           phohasPixelSeed[40];   //[nPho]
   Int_t           phoIsConv[40];   //[nPho]
   Float_t         phoPi0Disc[40];   //[nPho]
   Int_t           nMu;
   Int_t           muTrg[41][2];   //[nMu]
   Float_t         muEta[41];   //[nMu]
   Float_t         muPhi[41];   //[nMu]
   Int_t           muCharge[41];   //[nMu]
   Float_t         muPt[41];   //[nMu]
   Float_t         muPz[41];   //[nMu]
   Float_t         muIsoTrk[41];   //[nMu]
   Float_t         muIsoCalo[41];   //[nMu]
   Float_t         muIsoEcal[41];   //[nMu]
   Float_t         muIsoHcal[41];   //[nMu]
   Float_t         muChi2NDF[41];   //[nMu]
   Float_t         muEmVeto[41];   //[nMu]
   Float_t         muHadVeto[41];   //[nMu]
   Int_t           muType[41];   //[nMu]
   Bool_t          muID[41][6];   //[nMu]
   Float_t         muD0[41];   //[nMu]
   Int_t           muNumberOfValidTrkHits[41];   //[nMu]
   Int_t           muNumberOfValidPixelHits[41];   //[nMu]
   Int_t           muNumberOfValidMuonHits[41];   //[nMu]
   Int_t           muStations[41];   //[nMu]
   Int_t           muChambers[41];   //[nMu]
   Int_t           nJet;
   Int_t           jetTrg[26][5];   //[nJet]
   Float_t         jetEn[26];   //[nJet]
   Float_t         jetPt[26];   //[nJet]
   Float_t         jetEta[26];   //[nJet]
   Float_t         jetPhi[26];   //[nJet]
   Float_t         jetMass[26];   //[nJet]
   Float_t         jetEt[26];   //[nJet]
   Float_t         jetenergyFractionHadronic[26];   //[nJet]
   Float_t         jetemEnergyFraction[26];   //[nJet]
   Float_t         jetfHPD[26];   //[nJet]
   Int_t           jetN60[26];   //[nJet]
   Int_t           jetN90[26];   //[nJet]
   Int_t           jetpartonFlavour[26];   //[nJet]
   Float_t         jetRawPt[26];   //[nJet]
   Float_t         jetRawEn[26];   //[nJet]
   Float_t         jetCharge[26];   //[nJet]
   Int_t           nZee;
   Float_t         ZeeMass[55];   //[nZee]
   Float_t         ZeePt[55];   //[nZee]
   Float_t         ZeeEta[55];   //[nZee]
   Float_t         ZeePhi[55];   //[nZee]
   Int_t           ZeeLeg1Index[55];   //[nZee]
   Int_t           ZeeLeg2Index[55];   //[nZee]
   Int_t           nZmumu;
   Float_t         ZmumuMass[4];   //[nZmumu]
   Float_t         ZmumuPt[4];   //[nZmumu]
   Float_t         ZmumuEta[4];   //[nZmumu]
   Float_t         ZmumuPhi[4];   //[nZmumu]
   Int_t           ZmumuLeg1Index[4];   //[nZmumu]
   Int_t           ZmumuLeg2Index[4];   //[nZmumu]
   Int_t           nWenu;
   Float_t         WenuMassTCaloMET[11];   //[nWenu]
   Float_t         WenuEtCaloMET[11];   //[nWenu]
   Float_t         WenuACopCaloMET[11];   //[nWenu]
   Float_t         WenuMassTTcMET[11];   //[nWenu]
   Float_t         WenuEtTcMET[11];   //[nWenu]
   Float_t         WenuACopTcMET[11];   //[nWenu]
   Float_t         WenuMassTPfMET[11];   //[nWenu]
   Float_t         WenuEtPfMET[11];   //[nWenu]
   Float_t         WenuACopPfMET[11];   //[nWenu]
   Int_t           WenuEleIndex[11];   //[nWenu]
   Int_t           nWmunu;
   Float_t         WmunuMassTCaloMET[5];   //[nWmunu]
   Float_t         WmunuEtCaloMET[5];   //[nWmunu]
   Float_t         WmunuACopCaloMET[5];   //[nWmunu]
   Float_t         WmunuMassTTcMET[5];   //[nWmunu]
   Float_t         WmunuEtTcMET[5];   //[nWmunu]
   Float_t         WmunuACopTcMET[5];   //[nWmunu]
   Float_t         WmunuMassTPfMET[5];   //[nWmunu]
   Float_t         WmunuEtPfMET[5];   //[nWmunu]
   Float_t         WmunuACopPfMET[5];   //[nWmunu]
   Int_t           WmunuMuIndex[5];   //[nWmunu]
