   Int_t           run;
   Int_t           event;
   Int_t           orbit;
   Int_t           bx;
   Int_t           lumis;
   Bool_t          isData;
   Int_t           ttbit0;
   Int_t           nHLT;
   Int_t           HLT[156];   //[nHLT]
   Int_t           HLTIndex[50];
   Int_t           nHFTowersP;
   Int_t           nHFTowersN;
   Int_t           nVtx;
   Float_t         vtx[11][3];   //[nVtx]
   Int_t           vtxNTrk[11];   //[nVtx]
   Int_t           vtxNDF[11];   //[nVtx]
   Float_t         vtxD0[11];   //[nVtx]
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
   Int_t           eleTrg[9][13];   //[nEle]
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
   Float_t         eleE2overE9[9];   //[nEle]
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
   Int_t           phoTrg[8][8];   //[nPho]
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
   Float_t         phoTrkIsoSolidDR04[8];   //[nPho]
   Float_t         phoTrkIsoHollowDR04[8];   //[nPho]
   Int_t           phoNTrkSolidDR04[8];   //[nPho]
   Int_t           phoNTrkHollowDR04[8];   //[nPho]
   Float_t         phoEcalIsoDR04[8];   //[nPho]
   Float_t         phoHcalIsoDR04[8];   //[nPho]
   Float_t         phoHoverE[8];   //[nPho]
   Float_t         phoSigmaEtaEta[8];   //[nPho]
   Float_t         phoSigmaIEtaIEta[8];   //[nPho]
   Float_t         phoE2overE9[8];   //[nPho]
   Float_t         phoE3x3[8];   //[nPho]
   Float_t         phoSeedTime[8];   //[nPho]
   Int_t           phoRecoFlag[8];   //[nPho]
   Int_t           phoSeverity[8];   //[nPho]
   Int_t           phoPos[8];   //[nPho]
   Float_t         phoRoundness[8];   //[nPho]
   Float_t         phoAngle[8];   //[nPho]
   Float_t         phoSCE[8];   //[nPho]
   Float_t         phoSCEt[8];   //[nPho]
   Float_t         phoSCEta[8];   //[nPho]
   Float_t         phoSCPhi[8];   //[nPho]
   Float_t         phoSCEtaWidth[8];   //[nPho]
   Float_t         phoSCPhiWidth[8];   //[nPho]
   Int_t           phoOverlap[8];   //[nPho]
   Int_t           phohasPixelSeed[8];   //[nPho]
   Int_t           phoIsConv[8];   //[nPho]
   Float_t         phoPi0Disc[8];   //[nPho]
   Int_t           nMu;
   Int_t           muTrg[49][6];   //[nMu]
   Float_t         muEta[49];   //[nMu]
   Float_t         muPhi[49];   //[nMu]
   Int_t           muCharge[49];   //[nMu]
   Float_t         muPt[49];   //[nMu]
   Float_t         muPz[49];   //[nMu]
   Float_t         muIsoTrk[49];   //[nMu]
   Float_t         muIsoCalo[49];   //[nMu]
   Float_t         muIsoEcal[49];   //[nMu]
   Float_t         muIsoHcal[49];   //[nMu]
   Float_t         muChi2NDF[49];   //[nMu]
   Float_t         muEmVeto[49];   //[nMu]
   Float_t         muHadVeto[49];   //[nMu]
   Int_t           muType[49];   //[nMu]
   Bool_t          muID[49][6];   //[nMu]
   Float_t         muD0[49];   //[nMu]
   Float_t         muDz[49];   //[nMu]
   Int_t           muNumberOfValidTrkHits[49];   //[nMu]
   Int_t           muNumberOfValidPixelHits[49];   //[nMu]
   Int_t           muNumberOfValidMuonHits[49];   //[nMu]
   Int_t           muStations[49];   //[nMu]
   Int_t           muChambers[49];   //[nMu]
   Int_t           nZee;
   Float_t         ZeeMass[36];   //[nZee]
   Float_t         ZeePt[36];   //[nZee]
   Float_t         ZeeEta[36];   //[nZee]
   Float_t         ZeePhi[36];   //[nZee]
   Int_t           ZeeLeg1Index[36];   //[nZee]
   Int_t           ZeeLeg2Index[36];   //[nZee]
   Int_t           nZmumu;
   Float_t         ZmumuMass[6];   //[nZmumu]
   Float_t         ZmumuPt[6];   //[nZmumu]
   Float_t         ZmumuEta[6];   //[nZmumu]
   Float_t         ZmumuPhi[6];   //[nZmumu]
   Int_t           ZmumuLeg1Index[6];   //[nZmumu]
   Int_t           ZmumuLeg2Index[6];   //[nZmumu]
