   Int_t           run;
   Int_t           event;
   Int_t           orbit;
   Int_t           bx;
   Int_t           lumis;
   Bool_t          isData;
   Int_t           ttbit0;
   Int_t           nHLT;
   Int_t           HLT[194];   //[nHLT]
   Int_t           HLTIndex[50];
   Int_t           nHFTowersP;
   Int_t           nHFTowersN;
   Int_t           nVtx;
   Float_t         vtx[15][3];   //[nVtx]
   Int_t           vtxNTrk[15];   //[nVtx]
   Int_t           vtxNDF[15];   //[nVtx]
   Float_t         vtxD0[15];   //[nVtx]
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
   Int_t           eleTrg[12][13];   //[nEle]
   Int_t           eleID[12][12];   //[nEle]
   Int_t           eleClass[12];   //[nEle]
   Int_t           eleCharge[12];   //[nEle]
   Float_t         eleEn[12];   //[nEle]
   Float_t         eleSCRawEn[12];   //[nEle]
   Float_t         eleESEn[12];   //[nEle]
   Float_t         eleSCEn[12];   //[nEle]
   Float_t         elePt[12];   //[nEle]
   Float_t         elePz[12];   //[nEle]
   Float_t         eleEta[12];   //[nEle]
   Float_t         elePhi[12];   //[nEle]
   Float_t         eleSCEta[12];   //[nEle]
   Float_t         eleSCPhi[12];   //[nEle]
   Float_t         eleSCEtaWidth[12];   //[nEle]
   Float_t         eleSCPhiWidth[12];   //[nEle]
   Float_t         eleVtx[12][3];   //[nEle]
   Float_t         eleCaloPos[12][3];   //[nEle]
   Float_t         eleSCPos[12][3];   //[nEle]
   Float_t         eleHoverE[12];   //[nEle]
   Float_t         eleEoverP[12];   //[nEle]
   Float_t         elePin[12];   //[nEle]
   Float_t         elePout[12];   //[nEle]
   Float_t         eleBrem[12];   //[nEle]
   Float_t         eledEtaAtVtx[12];   //[nEle]
   Float_t         eledPhiAtVtx[12];   //[nEle]
   Float_t         eleSigmaEtaEta[12];   //[nEle]
   Float_t         eleSigmaIEtaIEta[12];   //[nEle]
   Float_t         eleE2overE9[12];   //[nEle]
   Float_t         eleE3x3[12];   //[nEle]
   Float_t         eleSeedTime[12];   //[nEle]
   Int_t           eleRecoFlag[12];   //[nEle]
   Int_t           eleSeverity[12];   //[nEle]
   Float_t         eleIsoTrkDR03[12];   //[nEle]
   Float_t         eleIsoEcalDR03[12];   //[nEle]
   Float_t         eleIsoHcalDR03[12];   //[nEle]
   Float_t         eleIsoTrkDR04[12];   //[nEle]
   Float_t         eleIsoEcalDR04[12];   //[nEle]
   Float_t         eleIsoHcalDR04[12];   //[nEle]
   Int_t           nPho;
   Int_t           phoTrg[11][8];   //[nPho]
   Bool_t          phoIsPhoton[11];   //[nPho]
   Float_t         phoE[11];   //[nPho]
   Float_t         phoEt[11];   //[nPho]
   Float_t         phoPz[11];   //[nPho]
   Float_t         phoEta[11];   //[nPho]
   Float_t         phoPhi[11];   //[nPho]
   Float_t         phoR9[11];   //[nPho]
   Float_t         phoTrkIsoSolidDR03[11];   //[nPho]
   Float_t         phoTrkIsoHollowDR03[11];   //[nPho]
   Int_t           phoNTrkSolidDR03[11];   //[nPho]
   Int_t           phoNTrkHollowDR03[11];   //[nPho]
   Float_t         phoEcalIsoDR03[11];   //[nPho]
   Float_t         phoHcalIsoDR03[11];   //[nPho]
   Float_t         phoTrkIsoSolidDR04[11];   //[nPho]
   Float_t         phoTrkIsoHollowDR04[11];   //[nPho]
   Int_t           phoNTrkSolidDR04[11];   //[nPho]
   Int_t           phoNTrkHollowDR04[11];   //[nPho]
   Float_t         phoEcalIsoDR04[11];   //[nPho]
   Float_t         phoHcalIsoDR04[11];   //[nPho]
   Float_t         phoHoverE[11];   //[nPho]
   Float_t         phoSigmaEtaEta[11];   //[nPho]
   Float_t         phoSigmaIEtaIEta[11];   //[nPho]
   Float_t         phoE2overE9[11];   //[nPho]
   Float_t         phoE3x3[11];   //[nPho]
   Float_t         phoSeedTime[11];   //[nPho]
   Int_t           phoRecoFlag[11];   //[nPho]
   Int_t           phoSeverity[11];   //[nPho]
   Int_t           phoPos[11];   //[nPho]
   Float_t         phoRoundness[11];   //[nPho]
   Float_t         phoAngle[11];   //[nPho]
   Float_t         phoSCE[11];   //[nPho]
   Float_t         phoSCEt[11];   //[nPho]
   Float_t         phoSCEta[11];   //[nPho]
   Float_t         phoSCPhi[11];   //[nPho]
   Float_t         phoSCEtaWidth[11];   //[nPho]
   Float_t         phoSCPhiWidth[11];   //[nPho]
   Int_t           phoOverlap[11];   //[nPho]
   Int_t           phohasPixelSeed[11];   //[nPho]
   Int_t           phoIsConv[11];   //[nPho]
   Float_t         phoPi0Disc[11];   //[nPho]
   Int_t           nMu;
   Int_t           muTrg[33][6];   //[nMu]
   Float_t         muEta[33];   //[nMu]
   Float_t         muPhi[33];   //[nMu]
   Int_t           muCharge[33];   //[nMu]
   Float_t         muPt[33];   //[nMu]
   Float_t         muPz[33];   //[nMu]
   Float_t         muIsoTrk[33];   //[nMu]
   Float_t         muIsoCalo[33];   //[nMu]
   Float_t         muIsoEcal[33];   //[nMu]
   Float_t         muIsoHcal[33];   //[nMu]
   Float_t         muChi2NDF[33];   //[nMu]
   Float_t         muEmVeto[33];   //[nMu]
   Float_t         muHadVeto[33];   //[nMu]
   Int_t           muType[33];   //[nMu]
   Bool_t          muID[33][6];   //[nMu]
   Float_t         muD0[33];   //[nMu]
   Float_t         muDz[33];   //[nMu]
   Int_t           muNumberOfValidTrkHits[33];   //[nMu]
   Int_t           muNumberOfValidPixelHits[33];   //[nMu]
   Int_t           muNumberOfValidMuonHits[33];   //[nMu]
   Int_t           muStations[33];   //[nMu]
   Int_t           muChambers[33];   //[nMu]
   Int_t           nZee;
   Float_t         ZeeMass[66];   //[nZee]
   Float_t         ZeePt[66];   //[nZee]
   Float_t         ZeeEta[66];   //[nZee]
   Float_t         ZeePhi[66];   //[nZee]
   Int_t           ZeeLeg1Index[66];   //[nZee]
   Int_t           ZeeLeg2Index[66];   //[nZee]
   Int_t           nZmumu;
   Float_t         ZmumuMass[6];   //[nZmumu]
   Float_t         ZmumuPt[6];   //[nZmumu]
   Float_t         ZmumuEta[6];   //[nZmumu]
   Float_t         ZmumuPhi[6];   //[nZmumu]
   Int_t           ZmumuLeg1Index[6];   //[nZmumu]
   Int_t           ZmumuLeg2Index[6];   //[nZmumu]
   Int_t           nWenu;
   Float_t         WenuMassTCaloMET[12];   //[nWenu]
   Float_t         WenuEtCaloMET[12];   //[nWenu]
   Float_t         WenuACopCaloMET[12];   //[nWenu]
   Float_t         WenuMassTTcMET[12];   //[nWenu]
   Float_t         WenuEtTcMET[12];   //[nWenu]
   Float_t         WenuACopTcMET[12];   //[nWenu]
   Float_t         WenuMassTPfMET[12];   //[nWenu]
   Float_t         WenuEtPfMET[12];   //[nWenu]
   Float_t         WenuACopPfMET[12];   //[nWenu]
   Int_t           WenuEleIndex[12];   //[nWenu]
   Int_t           nWmunu;
   Float_t         WmunuMassTCaloMET[6];   //[nWmunu]
   Float_t         WmunuEtCaloMET[6];   //[nWmunu]
   Float_t         WmunuACopCaloMET[6];   //[nWmunu]
   Float_t         WmunuMassTTcMET[6];   //[nWmunu]
   Float_t         WmunuEtTcMET[6];   //[nWmunu]
   Float_t         WmunuACopTcMET[6];   //[nWmunu]
   Float_t         WmunuMassTPfMET[6];   //[nWmunu]
   Float_t         WmunuEtPfMET[6];   //[nWmunu]
   Float_t         WmunuACopPfMET[6];   //[nWmunu]
   Int_t           WmunuMuIndex[6];   //[nWmunu]
