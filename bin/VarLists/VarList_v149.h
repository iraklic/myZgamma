   Int_t           run;
   Int_t           event;
   Int_t           orbit;
   Int_t           bx;
   Int_t           lumis;
   Bool_t          isData;
   Int_t           ttbit0;
   Int_t           nHLT;
   Int_t           HLT[77];   //[nHLT]
   Int_t           HLTIndex[25];
   Int_t           nHFTowersP;
   Int_t           nHFTowersN;
   Int_t           nVtx;
   Float_t         vtx[6][3];   //[nVtx]
   Int_t           vtxNTrk[6];   //[nVtx]
   Int_t           vtxNDF[6];   //[nVtx]
   Float_t         vtxD0[6];   //[nVtx]
   Int_t           IsVtxGood;
   Int_t           nTrk;
   Int_t           nGoodTrk;
   Int_t           IsTracksGood;
   Float_t         pdf[7];
   Float_t         pthat;
   Float_t         processID;
   Int_t           nMC;
   Int_t           mcPID[26];   //[nMC]
   Float_t         mcPt[26];   //[nMC]
   Float_t         mcMass[26];   //[nMC]
   Float_t         mcEta[26];   //[nMC]
   Float_t         mcPhi[26];   //[nMC]
   Int_t           mcGMomPID[26];   //[nMC]
   Int_t           mcMomPID[26];   //[nMC]
   Float_t         mcMomPt[26];   //[nMC]
   Float_t         mcMomMass[26];   //[nMC]
   Float_t         mcMomEta[26];   //[nMC]
   Float_t         mcMomPhi[26];   //[nMC]
   Int_t           mcIndex[26];   //[nMC]
   Int_t           mcDecayType[26];   //[nMC]
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
   Int_t           eleID[6][12];   //[nEle]
   Int_t           eleClass[6];   //[nEle]
   Int_t           eleCharge[6];   //[nEle]
   Float_t         eleEn[6];   //[nEle]
   Float_t         eleSCRawEn[6];   //[nEle]
   Float_t         eleESEn[6];   //[nEle]
   Float_t         eleSCEn[6];   //[nEle]
   Float_t         elePt[6];   //[nEle]
   Float_t         elePz[6];   //[nEle]
   Float_t         eleEta[6];   //[nEle]
   Float_t         elePhi[6];   //[nEle]
   Float_t         eleSCEta[6];   //[nEle]
   Float_t         eleSCPhi[6];   //[nEle]
   Float_t         eleSCEtaWidth[6];   //[nEle]
   Float_t         eleSCPhiWidth[6];   //[nEle]
   Float_t         eleVtx[6][3];   //[nEle]
   Float_t         eleCaloPos[6][3];   //[nEle]
   Float_t         eleSCPos[6][3];   //[nEle]
   Float_t         eleHoverE[6];   //[nEle]
   Float_t         eleEoverP[6];   //[nEle]
   Float_t         elePin[6];   //[nEle]
   Float_t         elePout[6];   //[nEle]
   Float_t         eleBrem[6];   //[nEle]
   Float_t         eledEtaAtVtx[6];   //[nEle]
   Float_t         eledPhiAtVtx[6];   //[nEle]
   Float_t         eleSigmaEtaEta[6];   //[nEle]
   Float_t         eleSigmaIEtaIEta[6];   //[nEle]
   Float_t         eleE3x3[6];   //[nEle]
   Float_t         eleSeedTime[6];   //[nEle]
   Int_t           eleRecoFlag[6];   //[nEle]
   Int_t           eleSeverity[6];   //[nEle]
   Int_t           eleGenIndex[6];   //[nEle]
   Int_t           eleGenGMomPID[6];   //[nEle]
   Int_t           eleGenMomPID[6];   //[nEle]
   Float_t         eleGenMomPt[6];   //[nEle]
   Float_t         eleIsoTrkDR03[6];   //[nEle]
   Float_t         eleIsoEcalDR03[6];   //[nEle]
   Float_t         eleIsoHcalDR03[6];   //[nEle]
   Float_t         eleIsoTrkDR04[6];   //[nEle]
   Float_t         eleIsoEcalDR04[6];   //[nEle]
   Float_t         eleIsoHcalDR04[6];   //[nEle]
   Int_t           nPho;
   Bool_t          phoIsPhoton[7];   //[nPho]
   Float_t         phoE[7];   //[nPho]
   Float_t         phoEt[7];   //[nPho]
   Float_t         phoPz[7];   //[nPho]
   Float_t         phoEta[7];   //[nPho]
   Float_t         phoPhi[7];   //[nPho]
   Float_t         phoR9[7];   //[nPho]
   Float_t         phoTrkIsoSolidDR03[7];   //[nPho]
   Float_t         phoTrkIsoHollowDR03[7];   //[nPho]
   Int_t           phoNTrkSolidDR03[7];   //[nPho]
   Int_t           phoNTrkHollowDR03[7];   //[nPho]
   Float_t         phoEcalIsoDR03[7];   //[nPho]
   Float_t         phoHcalIsoDR03[7];   //[nPho]
   Float_t         phoTrkIsoSolidDR04[7];   //[nPho]
   Float_t         phoTrkIsoHollowDR04[7];   //[nPho]
   Int_t           phoNTrkSolidDR04[7];   //[nPho]
   Int_t           phoNTrkHollowDR04[7];   //[nPho]
   Float_t         phoEcalIsoDR04[7];   //[nPho]
   Float_t         phoHcalIsoDR04[7];   //[nPho]
   Float_t         phoHoverE[7];   //[nPho]
   Float_t         phoSigmaEtaEta[7];   //[nPho]
   Float_t         phoSigmaIEtaIEta[7];   //[nPho]
   Float_t         phoE3x3[7];   //[nPho]
   Float_t         phoSeedTime[7];   //[nPho]
   Int_t           phoRecoFlag[7];   //[nPho]
   Int_t           phoSeverity[7];   //[nPho]
   Int_t           phoPos[7];   //[nPho]
   Float_t         phoRoundness[7];   //[nPho]
   Float_t         phoAngle[7];   //[nPho]
   Int_t           phoGenIndex[7];   //[nPho]
   Int_t           phoGenGMomPID[7];   //[nPho]
   Int_t           phoGenMomPID[7];   //[nPho]
   Float_t         phoGenMomPt[7];   //[nPho]
   Float_t         phoSCE[7];   //[nPho]
   Float_t         phoSCEt[7];   //[nPho]
   Float_t         phoSCEta[7];   //[nPho]
   Float_t         phoSCPhi[7];   //[nPho]
   Float_t         phoSCEtaWidth[7];   //[nPho]
   Float_t         phoSCPhiWidth[7];   //[nPho]
   Int_t           phoOverlap[7];   //[nPho]
   Int_t           phohasPixelSeed[7];   //[nPho]
   Int_t           phoIsConv[7];   //[nPho]
   Float_t         phoPi0Disc[7];   //[nPho]
   Int_t           nMu;
   Float_t         muEta[10];   //[nMu]
   Float_t         muPhi[10];   //[nMu]
   Int_t           muCharge[10];   //[nMu]
   Float_t         muPt[10];   //[nMu]
   Float_t         muPz[10];   //[nMu]
   Int_t           muGenIndex[10];   //[nMu]
   Float_t         muIsoTrk[10];   //[nMu]
   Float_t         muIsoCalo[10];   //[nMu]
   Float_t         muIsoEcal[10];   //[nMu]
   Float_t         muIsoHcal[10];   //[nMu]
   Float_t         muChi2NDF[10];   //[nMu]
   Float_t         muEmVeto[10];   //[nMu]
   Float_t         muHadVeto[10];   //[nMu]
   Int_t           muType[10];   //[nMu]
   Bool_t          muID[10][6];   //[nMu]
   Float_t         muD0[10];   //[nMu]
   Int_t           muNumberOfValidTrkHits[10];   //[nMu]
   Int_t           muNumberOfValidPixelHits[10];   //[nMu]
   Int_t           muNumberOfValidMuonHits[10];   //[nMu]
   Int_t           nZee;
   Float_t         ZeeMass[15];   //[nZee]
   Float_t         ZeePt[15];   //[nZee]
   Float_t         ZeeEta[15];   //[nZee]
   Float_t         ZeePhi[15];   //[nZee]
   Int_t           ZeeLeg1Index[15];   //[nZee]
   Int_t           ZeeLeg2Index[15];   //[nZee]
   Int_t           nZmumu;
   Float_t         ZmumuMass[6];   //[nZmumu]
   Float_t         ZmumuPt[6];   //[nZmumu]
   Float_t         ZmumuEta[6];   //[nZmumu]
   Float_t         ZmumuPhi[6];   //[nZmumu]
   Int_t           ZmumuLeg1Index[6];   //[nZmumu]
   Int_t           ZmumuLeg2Index[6];   //[nZmumu]
   Int_t           nWenu;
   Float_t         WenuMassTCaloMET[6];   //[nWenu]
   Float_t         WenuEtCaloMET[6];   //[nWenu]
   Float_t         WenuACopCaloMET[6];   //[nWenu]
   Float_t         WenuMassTTcMET[6];   //[nWenu]
   Float_t         WenuEtTcMET[6];   //[nWenu]
   Float_t         WenuACopTcMET[6];   //[nWenu]
   Float_t         WenuMassTPfMET[6];   //[nWenu]
   Float_t         WenuEtPfMET[6];   //[nWenu]
   Float_t         WenuACopPfMET[6];   //[nWenu]
   Int_t           WenuEleIndex[6];   //[nWenu]
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
