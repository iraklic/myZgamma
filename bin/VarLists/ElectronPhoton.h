   Int_t           run;
   Int_t           event;
   Int_t           orbit;
   Int_t           bx;
   Int_t           lumis;
   Bool_t          isData;
   Int_t           ttbit0;
   Int_t           nHLT;
   Int_t           HLT[194];   //[nHLT]
   Int_t           HLTIndex[100];
   Int_t           nVtx;
   Float_t         vtx[15][3];   //[nVtx]
   Int_t           vtxNTrk[15];   //[nVtx]
   Int_t           vtxNDF[15];   //[nVtx]
   Float_t         vtxD0[15];   //[nVtx]
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
   Int_t           eleTrg[11][50];   //[nEle]
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
   Float_t         eleE2overE9[11];   //[nEle]
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
   Int_t           phoTrg[11][50];   //[nPho]
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
   Int_t           muTrg[24][50];   //[nMu]
   Float_t         muEta[24];   //[nMu]
   Float_t         muPhi[24];   //[nMu]
   Int_t           muCharge[24];   //[nMu]
   Float_t         muPt[24];   //[nMu]
   Float_t         muPz[24];   //[nMu]
   Float_t         muIsoTrk[24];   //[nMu]
   Float_t         muIsoCalo[24];   //[nMu]
   Float_t         muIsoEcal[24];   //[nMu]
   Float_t         muIsoHcal[24];   //[nMu]
   Float_t         muChi2NDF[24];   //[nMu]
   Float_t         muEmVeto[24];   //[nMu]
   Float_t         muHadVeto[24];   //[nMu]
   Int_t           muType[24];   //[nMu]
   Bool_t          muID[24][6];   //[nMu]
   Float_t         muD0[24];   //[nMu]
   Float_t         muDz[24];   //[nMu]
   Int_t           muNumberOfValidTrkHits[24];   //[nMu]
   Int_t           muNumberOfValidPixelHits[24];   //[nMu]
   Int_t           muNumberOfValidMuonHits[24];   //[nMu]
   Int_t           muStations[24];   //[nMu]
   Int_t           muChambers[24];   //[nMu]
   Int_t           nJet;
   Float_t         jetTrg[11][50];   //[nJet]
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
   Int_t           jetpartonFlavour[11];   //[nJet]
   Float_t         jetRawPt[11];   //[nJet]
   Float_t         jetRawEn[11];   //[nJet]
   Float_t         jetCharge[11];   //[nJet]
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
