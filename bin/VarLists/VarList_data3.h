   Int_t           run;
   Int_t           event;
   Int_t           orbit;
   Int_t           bx;
   Int_t           lumis;
   Bool_t          isData;
   Int_t           ttbit0;
   Int_t           nHLT;
   Int_t           HLT[156];   //[nHLT]
   Int_t           HLTIndex[25];
   Int_t           nHFTowersP;
   Int_t           nHFTowersN;
   Int_t           nVtx;
   Float_t         vtx[8][3];   //[nVtx]
   Int_t           vtxNTrk[8];   //[nVtx]
   Int_t           vtxNDF[8];   //[nVtx]
   Float_t         vtxD0[8];   //[nVtx]
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
   Int_t           eleTrg[10][5];   //[nEle]
   Int_t           eleID[10][12];   //[nEle]
   Int_t           eleClass[10];   //[nEle]
   Int_t           eleCharge[10];   //[nEle]
   Float_t         eleEn[10];   //[nEle]
   Float_t         eleSCRawEn[10];   //[nEle]
   Float_t         eleESEn[10];   //[nEle]
   Float_t         eleSCEn[10];   //[nEle]
   Float_t         elePt[10];   //[nEle]
   Float_t         elePz[10];   //[nEle]
   Float_t         eleEta[10];   //[nEle]
   Float_t         elePhi[10];   //[nEle]
   Float_t         eleSCEta[10];   //[nEle]
   Float_t         eleSCPhi[10];   //[nEle]
   Float_t         eleSCEtaWidth[10];   //[nEle]
   Float_t         eleSCPhiWidth[10];   //[nEle]
   Float_t         eleVtx[10][3];   //[nEle]
   Float_t         eleCaloPos[10][3];   //[nEle]
   Float_t         eleSCPos[10][3];   //[nEle]
   Float_t         eleHoverE[10];   //[nEle]
   Float_t         eleEoverP[10];   //[nEle]
   Float_t         elePin[10];   //[nEle]
   Float_t         elePout[10];   //[nEle]
   Float_t         eleBrem[10];   //[nEle]
   Float_t         eledEtaAtVtx[10];   //[nEle]
   Float_t         eledPhiAtVtx[10];   //[nEle]
   Float_t         eleSigmaEtaEta[10];   //[nEle]
   Float_t         eleSigmaIEtaIEta[10];   //[nEle]
   Float_t         eleE3x3[10];   //[nEle]
   Float_t         eleSeedTime[10];   //[nEle]
   Int_t           eleRecoFlag[10];   //[nEle]
   Int_t           eleSeverity[10];   //[nEle]
   Float_t         eleIsoTrkDR03[10];   //[nEle]
   Float_t         eleIsoEcalDR03[10];   //[nEle]
   Float_t         eleIsoHcalDR03[10];   //[nEle]
   Float_t         eleIsoTrkDR04[10];   //[nEle]
   Float_t         eleIsoEcalDR04[10];   //[nEle]
   Float_t         eleIsoHcalDR04[10];   //[nEle]
   Int_t           nPho;
   Bool_t          phoIsPhoton[87];   //[nPho]
   Float_t         phoE[87];   //[nPho]
   Float_t         phoEt[87];   //[nPho]
   Float_t         phoPz[87];   //[nPho]
   Float_t         phoEta[87];   //[nPho]
   Float_t         phoPhi[87];   //[nPho]
   Float_t         phoR9[87];   //[nPho]
   Float_t         phoTrkIsoSolidDR03[87];   //[nPho]
   Float_t         phoTrkIsoHollowDR03[87];   //[nPho]
   Int_t           phoNTrkSolidDR03[87];   //[nPho]
   Int_t           phoNTrkHollowDR03[87];   //[nPho]
   Float_t         phoEcalIsoDR03[87];   //[nPho]
   Float_t         phoHcalIsoDR03[87];   //[nPho]
   Float_t         phoTrkIsoSolidDR04[87];   //[nPho]
   Float_t         phoTrkIsoHollowDR04[87];   //[nPho]
   Int_t           phoNTrkSolidDR04[87];   //[nPho]
   Int_t           phoNTrkHollowDR04[87];   //[nPho]
   Float_t         phoEcalIsoDR04[87];   //[nPho]
   Float_t         phoHcalIsoDR04[87];   //[nPho]
   Float_t         phoHoverE[87];   //[nPho]
   Float_t         phoSigmaEtaEta[87];   //[nPho]
   Float_t         phoSigmaIEtaIEta[87];   //[nPho]
   Float_t         phoE3x3[87];   //[nPho]
   Float_t         phoSeedTime[87];   //[nPho]
   Int_t           phoRecoFlag[87];   //[nPho]
   Int_t           phoSeverity[87];   //[nPho]
   Int_t           phoPos[87];   //[nPho]
   Float_t         phoRoundness[87];   //[nPho]
   Float_t         phoAngle[87];   //[nPho]
   Float_t         phoSCE[87];   //[nPho]
   Float_t         phoSCEt[87];   //[nPho]
   Float_t         phoSCEta[87];   //[nPho]
   Float_t         phoSCPhi[87];   //[nPho]
   Float_t         phoSCEtaWidth[87];   //[nPho]
   Float_t         phoSCPhiWidth[87];   //[nPho]
   Int_t           phoOverlap[87];   //[nPho]
   Int_t           phohasPixelSeed[87];   //[nPho]
   Int_t           phoIsConv[87];   //[nPho]
   Float_t         phoPi0Disc[87];   //[nPho]
   Int_t           nMu;
   Int_t           muTrg;
   Float_t         muEta[58];   //[nMu]
   Float_t         muPhi[58];   //[nMu]
   Int_t           muCharge[58];   //[nMu]
   Float_t         muPt[58];   //[nMu]
   Float_t         muPz[58];   //[nMu]
   Float_t         muIsoTrk[58];   //[nMu]
   Float_t         muIsoCalo[58];   //[nMu]
   Float_t         muIsoEcal[58];   //[nMu]
   Float_t         muIsoHcal[58];   //[nMu]
   Float_t         muChi2NDF[58];   //[nMu]
   Float_t         muEmVeto[58];   //[nMu]
   Float_t         muHadVeto[58];   //[nMu]
   Int_t           muType[58];   //[nMu]
   Bool_t          muID[58][6];   //[nMu]
   Float_t         muD0[58];   //[nMu]
   Int_t           muNumberOfValidTrkHits[58];   //[nMu]
   Int_t           muNumberOfValidPixelHits[58];   //[nMu]
   Int_t           muNumberOfValidMuonHits[58];   //[nMu]
   Int_t           muStations[58];   //[nMu]
   Int_t           muChambers[58];   //[nMu]
   Int_t           nZee;
   Float_t         ZeeMass[45];   //[nZee]
   Float_t         ZeePt[45];   //[nZee]
   Float_t         ZeeEta[45];   //[nZee]
   Float_t         ZeePhi[45];   //[nZee]
   Int_t           ZeeLeg1Index[45];   //[nZee]
   Int_t           ZeeLeg2Index[45];   //[nZee]
   Int_t           nZmumu;
   Float_t         ZmumuMass[8];   //[nZmumu]
   Float_t         ZmumuPt[8];   //[nZmumu]
   Float_t         ZmumuEta[8];   //[nZmumu]
   Float_t         ZmumuPhi[8];   //[nZmumu]
   Int_t           ZmumuLeg1Index[8];   //[nZmumu]
   Int_t           ZmumuLeg2Index[8];   //[nZmumu]
   Int_t           nWenu;
   Float_t         WenuMassTCaloMET[10];   //[nWenu]
   Float_t         WenuEtCaloMET[10];   //[nWenu]
   Float_t         WenuACopCaloMET[10];   //[nWenu]
   Float_t         WenuMassTTcMET[10];   //[nWenu]
   Float_t         WenuEtTcMET[10];   //[nWenu]
   Float_t         WenuACopTcMET[10];   //[nWenu]
   Float_t         WenuMassTPfMET[10];   //[nWenu]
   Float_t         WenuEtPfMET[10];   //[nWenu]
   Float_t         WenuACopPfMET[10];   //[nWenu]
   Int_t           WenuEleIndex[10];   //[nWenu]
   Int_t           nWmunu;
   Float_t         WmunuMassTCaloMET[7];   //[nWmunu]
   Float_t         WmunuEtCaloMET[7];   //[nWmunu]
   Float_t         WmunuACopCaloMET[7];   //[nWmunu]
   Float_t         WmunuMassTTcMET[7];   //[nWmunu]
   Float_t         WmunuEtTcMET[7];   //[nWmunu]
   Float_t         WmunuACopTcMET[7];   //[nWmunu]
   Float_t         WmunuMassTPfMET[7];   //[nWmunu]
   Float_t         WmunuEtPfMET[7];   //[nWmunu]
   Float_t         WmunuACopPfMET[7];   //[nWmunu]
   Int_t           WmunuMuIndex[7];   //[nWmunu]
