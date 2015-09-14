   Int_t           run;
   Int_t           event;
   Int_t           orbit;
   Int_t           bx;
   Int_t           lumis;
   Bool_t          isData;
   Int_t           ttbit0;
   Int_t           nHLT;
   Int_t           HLT[144];   //[nHLT]
   Int_t           HLTIndex[23];
   Int_t           nHFTowersP;
   Int_t           nHFTowersN;
   Int_t           nVtx;
   Float_t         vtx[12][3];   //[nVtx]
   Int_t           vtxNTrk[12];   //[nVtx]
   Int_t           vtxNDF[12];   //[nVtx]
   Float_t         vtxD0[12];   //[nVtx]
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
   Int_t           eleTrg[9][7];   //[nEle]
   Int_t           eleID[9][12];   //[nEle]
   Int_t           eleClass[9];   //[nEle]
   Int_t           eleCharge[9];   //[nEle]
   Float_t         eleEn[9];   //[nEle]
   Float_t         eleSCRawEn[9];   //[nEle]
   Float_t         eleESEn[9];   //[nEle]
   Float_t         eleSCEn[9];   //[nEle]
   Float_t         elePt[9];   //[nEle]
   Float_t         elePz[9];   //[nEle]
   Float_t         eleEta[9];   //[nEle]
   Float_t         elePhi[9];   //[nEle]
   Float_t         eleSCEta[9];   //[nEle]
   Float_t         eleSCPhi[9];   //[nEle]
   Float_t         eleSCEtaWidth[9];   //[nEle]
   Float_t         eleSCPhiWidth[9];   //[nEle]
   Float_t         eleVtx[9][3];   //[nEle]
   Float_t         eleCaloPos[9][3];   //[nEle]
   Float_t         eleSCPos[9][3];   //[nEle]
   Float_t         eleHoverE[9];   //[nEle]
   Float_t         eleEoverP[9];   //[nEle]
   Float_t         elePin[9];   //[nEle]
   Float_t         elePout[9];   //[nEle]
   Float_t         eleBrem[9];   //[nEle]
   Float_t         eledEtaAtVtx[9];   //[nEle]
   Float_t         eledPhiAtVtx[9];   //[nEle]
   Float_t         eleSigmaEtaEta[9];   //[nEle]
   Float_t         eleSigmaIEtaIEta[9];   //[nEle]
   Float_t         eleE3x3[9];   //[nEle]
   Float_t         eleSeedTime[9];   //[nEle]
   Int_t           eleRecoFlag[9];   //[nEle]
   Int_t           eleSeverity[9];   //[nEle]
   Float_t         eleIsoTrkDR03[9];   //[nEle]
   Float_t         eleIsoEcalDR03[9];   //[nEle]
   Float_t         eleIsoHcalDR03[9];   //[nEle]
   Float_t         eleIsoTrkDR04[9];   //[nEle]
   Float_t         eleIsoEcalDR04[9];   //[nEle]
   Float_t         eleIsoHcalDR04[9];   //[nEle]
   Int_t           nPho;
   Int_t           phoTrg[9][4];   //[nPho]
   Bool_t          phoIsPhoton[9];   //[nPho]
   Float_t         phoE[9];   //[nPho]
   Float_t         phoEt[9];   //[nPho]
   Float_t         phoPz[9];   //[nPho]
   Float_t         phoEta[9];   //[nPho]
   Float_t         phoPhi[9];   //[nPho]
   Float_t         phoR9[9];   //[nPho]
   Float_t         phoTrkIsoSolidDR03[9];   //[nPho]
   Float_t         phoTrkIsoHollowDR03[9];   //[nPho]
   Int_t           phoNTrkSolidDR03[9];   //[nPho]
   Int_t           phoNTrkHollowDR03[9];   //[nPho]
   Float_t         phoEcalIsoDR03[9];   //[nPho]
   Float_t         phoHcalIsoDR03[9];   //[nPho]
   Float_t         phoTrkIsoSolidDR04[9];   //[nPho]
   Float_t         phoTrkIsoHollowDR04[9];   //[nPho]
   Int_t           phoNTrkSolidDR04[9];   //[nPho]
   Int_t           phoNTrkHollowDR04[9];   //[nPho]
   Float_t         phoEcalIsoDR04[9];   //[nPho]
   Float_t         phoHcalIsoDR04[9];   //[nPho]
   Float_t         phoHoverE[9];   //[nPho]
   Float_t         phoSigmaEtaEta[9];   //[nPho]
   Float_t         phoSigmaIEtaIEta[9];   //[nPho]
   Float_t         phoE3x3[9];   //[nPho]
   Float_t         phoSeedTime[9];   //[nPho]
   Int_t           phoRecoFlag[9];   //[nPho]
   Int_t           phoSeverity[9];   //[nPho]
   Int_t           phoPos[9];   //[nPho]
   Float_t         phoRoundness[9];   //[nPho]
   Float_t         phoAngle[9];   //[nPho]
   Float_t         phoSCE[9];   //[nPho]
   Float_t         phoSCEt[9];   //[nPho]
   Float_t         phoSCEta[9];   //[nPho]
   Float_t         phoSCPhi[9];   //[nPho]
   Float_t         phoSCEtaWidth[9];   //[nPho]
   Float_t         phoSCPhiWidth[9];   //[nPho]
   Int_t           phoOverlap[9];   //[nPho]
   Int_t           phohasPixelSeed[9];   //[nPho]
   Int_t           phoIsConv[9];   //[nPho]
   Float_t         phoPi0Disc[9];   //[nPho]
   Int_t           nMu;
   Int_t           muTrg[25][2];   //[nMu]
   Float_t         muEta[25];   //[nMu]
   Float_t         muPhi[25];   //[nMu]
   Int_t           muCharge[25];   //[nMu]
   Float_t         muPt[25];   //[nMu]
   Float_t         muPz[25];   //[nMu]
   Float_t         muIsoTrk[25];   //[nMu]
   Float_t         muIsoCalo[25];   //[nMu]
   Float_t         muIsoEcal[25];   //[nMu]
   Float_t         muIsoHcal[25];   //[nMu]
   Float_t         muChi2NDF[25];   //[nMu]
   Float_t         muEmVeto[25];   //[nMu]
   Float_t         muHadVeto[25];   //[nMu]
   Int_t           muType[25];   //[nMu]
   Bool_t          muID[25][6];   //[nMu]
   Float_t         muD0[25];   //[nMu]
   Int_t           muNumberOfValidTrkHits[25];   //[nMu]
   Int_t           muNumberOfValidPixelHits[25];   //[nMu]
   Int_t           muNumberOfValidMuonHits[25];   //[nMu]
   Int_t           muStations[25];   //[nMu]
   Int_t           muChambers[25];   //[nMu]
   Int_t           nZee;
   Float_t         ZeeMass[36];   //[nZee]
   Float_t         ZeePt[36];   //[nZee]
   Float_t         ZeeEta[36];   //[nZee]
   Float_t         ZeePhi[36];   //[nZee]
   Int_t           ZeeLeg1Index[36];   //[nZee]
   Int_t           ZeeLeg2Index[36];   //[nZee]
   Int_t           nZmumu;
   Float_t         ZmumuMass[3];   //[nZmumu]
   Float_t         ZmumuPt[3];   //[nZmumu]
   Float_t         ZmumuEta[3];   //[nZmumu]
   Float_t         ZmumuPhi[3];   //[nZmumu]
   Int_t           ZmumuLeg1Index[3];   //[nZmumu]
   Int_t           ZmumuLeg2Index[3];   //[nZmumu]
   Int_t           nWenu;
   Float_t         WenuMassTCaloMET[9];   //[nWenu]
   Float_t         WenuEtCaloMET[9];   //[nWenu]
   Float_t         WenuACopCaloMET[9];   //[nWenu]
   Float_t         WenuMassTTcMET[9];   //[nWenu]
   Float_t         WenuEtTcMET[9];   //[nWenu]
   Float_t         WenuACopTcMET[9];   //[nWenu]
   Float_t         WenuMassTPfMET[9];   //[nWenu]
   Float_t         WenuEtPfMET[9];   //[nWenu]
   Float_t         WenuACopPfMET[9];   //[nWenu]
   Int_t           WenuEleIndex[9];   //[nWenu]
   Int_t           nWmunu;
   Float_t         WmunuMassTCaloMET[4];   //[nWmunu]
   Float_t         WmunuEtCaloMET[4];   //[nWmunu]
   Float_t         WmunuACopCaloMET[4];   //[nWmunu]
   Float_t         WmunuMassTTcMET[4];   //[nWmunu]
   Float_t         WmunuEtTcMET[4];   //[nWmunu]
   Float_t         WmunuACopTcMET[4];   //[nWmunu]
   Float_t         WmunuMassTPfMET[4];   //[nWmunu]
   Float_t         WmunuEtPfMET[4];   //[nWmunu]
   Float_t         WmunuACopPfMET[4];   //[nWmunu]
   Int_t           WmunuMuIndex[4];   //[nWmunu]
