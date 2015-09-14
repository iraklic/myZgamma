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
   Int_t           mcPID[19];   //[nMC]
   Float_t         mcPt[19];   //[nMC]
   Float_t         mcMass[19];   //[nMC]
   Float_t         mcEta[19];   //[nMC]
   Float_t         mcPhi[19];   //[nMC]
   Int_t           mcGMomPID[19];   //[nMC]
   Int_t           mcMomPID[19];   //[nMC]
   Float_t         mcMomPt[19];   //[nMC]
   Float_t         mcMomMass[19];   //[nMC]
   Float_t         mcMomEta[19];   //[nMC]
   Float_t         mcMomPhi[19];   //[nMC]
   Int_t           mcIndex[19];   //[nMC]
   Int_t           mcDecayType[19];   //[nMC]
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
   Int_t           eleTrg[4][13];   //[nEle]
   Int_t           eleID[4][12];   //[nEle]
   Int_t           eleClass[4];   //[nEle]
   Int_t           eleCharge[4];   //[nEle]
   Float_t         eleEn[4];   //[nEle]
   Float_t         eleSCRawEn[4];   //[nEle]
   Float_t         eleESEn[4];   //[nEle]
   Float_t         eleSCEn[4];   //[nEle]
   Float_t         elePt[4];   //[nEle]
   Float_t         elePz[4];   //[nEle]
   Float_t         eleEta[4];   //[nEle]
   Float_t         elePhi[4];   //[nEle]
   Float_t         eleSCEta[4];   //[nEle]
   Float_t         eleSCPhi[4];   //[nEle]
   Float_t         eleSCEtaWidth[4];   //[nEle]
   Float_t         eleSCPhiWidth[4];   //[nEle]
   Float_t         eleVtx[4][3];   //[nEle]
   Float_t         eleCaloPos[4][3];   //[nEle]
   Float_t         eleSCPos[4][3];   //[nEle]
   Float_t         eleHoverE[4];   //[nEle]
   Float_t         eleEoverP[4];   //[nEle]
   Float_t         elePin[4];   //[nEle]
   Float_t         elePout[4];   //[nEle]
   Float_t         eleBrem[4];   //[nEle]
   Float_t         eledEtaAtVtx[4];   //[nEle]
   Float_t         eledPhiAtVtx[4];   //[nEle]
   Float_t         eleSigmaEtaEta[4];   //[nEle]
   Float_t         eleSigmaIEtaIEta[4];   //[nEle]
   Float_t         eleE2overE9[4];   //[nEle]
   Float_t         eleE3x3[4];   //[nEle]
   Float_t         eleSeedTime[4];   //[nEle]
   Int_t           eleRecoFlag[4];   //[nEle]
   Int_t           eleSeverity[4];   //[nEle]
   Int_t           eleGenIndex[4];   //[nEle]
   Int_t           eleGenGMomPID[4];   //[nEle]
   Int_t           eleGenMomPID[4];   //[nEle]
   Float_t         eleGenMomPt[4];   //[nEle]
   Float_t         eleIsoTrkDR03[4];   //[nEle]
   Float_t         eleIsoEcalDR03[4];   //[nEle]
   Float_t         eleIsoHcalDR03[4];   //[nEle]
   Float_t         eleIsoTrkDR04[4];   //[nEle]
   Float_t         eleIsoEcalDR04[4];   //[nEle]
   Float_t         eleIsoHcalDR04[4];   //[nEle]
   Int_t           nPho;
   Int_t           phoTrg[5][8];   //[nPho]
   Bool_t          phoIsPhoton[5];   //[nPho]
   Float_t         phoE[5];   //[nPho]
   Float_t         phoEt[5];   //[nPho]
   Float_t         phoPz[5];   //[nPho]
   Float_t         phoEta[5];   //[nPho]
   Float_t         phoPhi[5];   //[nPho]
   Float_t         phoR9[5];   //[nPho]
   Float_t         phoTrkIsoSolidDR03[5];   //[nPho]
   Float_t         phoTrkIsoHollowDR03[5];   //[nPho]
   Int_t           phoNTrkSolidDR03[5];   //[nPho]
   Int_t           phoNTrkHollowDR03[5];   //[nPho]
   Float_t         phoEcalIsoDR03[5];   //[nPho]
   Float_t         phoHcalIsoDR03[5];   //[nPho]
   Float_t         phoTrkIsoSolidDR04[5];   //[nPho]
   Float_t         phoTrkIsoHollowDR04[5];   //[nPho]
   Int_t           phoNTrkSolidDR04[5];   //[nPho]
   Int_t           phoNTrkHollowDR04[5];   //[nPho]
   Float_t         phoEcalIsoDR04[5];   //[nPho]
   Float_t         phoHcalIsoDR04[5];   //[nPho]
   Float_t         phoHoverE[5];   //[nPho]
   Float_t         phoSigmaEtaEta[5];   //[nPho]
   Float_t         phoSigmaIEtaIEta[5];   //[nPho]
   Float_t         phoE2overE9[5];   //[nPho]
   Float_t         phoE3x3[5];   //[nPho]
   Float_t         phoSeedTime[5];   //[nPho]
   Int_t           phoRecoFlag[5];   //[nPho]
   Int_t           phoSeverity[5];   //[nPho]
   Int_t           phoPos[5];   //[nPho]
   Float_t         phoRoundness[5];   //[nPho]
   Float_t         phoAngle[5];   //[nPho]
   Int_t           phoGenIndex[5];   //[nPho]
   Int_t           phoGenGMomPID[5];   //[nPho]
   Int_t           phoGenMomPID[5];   //[nPho]
   Float_t         phoGenMomPt[5];   //[nPho]
   Float_t         phoSCE[5];   //[nPho]
   Float_t         phoSCEt[5];   //[nPho]
   Float_t         phoSCEta[5];   //[nPho]
   Float_t         phoSCPhi[5];   //[nPho]
   Float_t         phoSCEtaWidth[5];   //[nPho]
   Float_t         phoSCPhiWidth[5];   //[nPho]
   Int_t           phoOverlap[5];   //[nPho]
   Int_t           phohasPixelSeed[5];   //[nPho]
   Int_t           phoIsConv[5];   //[nPho]
   Float_t         phoPi0Disc[5];   //[nPho]
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
   Int_t           jetTrg[9][14];   //[nJet]
   Float_t         jetEn[9];   //[nJet]
   Float_t         jetPt[9];   //[nJet]
   Float_t         jetEta[9];   //[nJet]
   Float_t         jetPhi[9];   //[nJet]
   Float_t         jetMass[9];   //[nJet]
   Float_t         jetEt[9];   //[nJet]
   Float_t         jetenergyFractionHadronic[9];   //[nJet]
   Float_t         jetemEnergyFraction[9];   //[nJet]
   Float_t         jetfHPD[9];   //[nJet]
   Int_t           jetN60[9];   //[nJet]
   Int_t           jetN90[9];   //[nJet]
   Int_t           jetGenIndex[9];   //[nJet]
   Int_t           jetGenJetIndex[9];   //[nJet]
   Float_t         jetGenJetEn[9];   //[nJet]
   Float_t         jetGenJetPt[9];   //[nJet]
   Float_t         jetGenJetEta[9];   //[nJet]
   Float_t         jetGenJetPhi[9];   //[nJet]
   Float_t         jetGenJetMass[9];   //[nJet]
   Int_t           jetGenPartonID[9];   //[nJet]
   Int_t           jetGenPartonMomID[9];   //[nJet]
   Int_t           jetpartonFlavour[9];   //[nJet]
   Float_t         jetRawPt[9];   //[nJet]
   Float_t         jetRawEn[9];   //[nJet]
   Float_t         jetCharge[9];   //[nJet]
   Int_t           nZee;
   Float_t         ZeeMass[6];   //[nZee]
   Float_t         ZeePt[6];   //[nZee]
   Float_t         ZeeEta[6];   //[nZee]
   Float_t         ZeePhi[6];   //[nZee]
   Int_t           ZeeLeg1Index[6];   //[nZee]
   Int_t           ZeeLeg2Index[6];   //[nZee]
   Int_t           nZmumu;
   Float_t         ZmumuMass[3];   //[nZmumu]
   Float_t         ZmumuPt[3];   //[nZmumu]
   Float_t         ZmumuEta[3];   //[nZmumu]
   Float_t         ZmumuPhi[3];   //[nZmumu]
   Int_t           ZmumuLeg1Index[3];   //[nZmumu]
   Int_t           ZmumuLeg2Index[3];   //[nZmumu]
   Int_t           nWenu;
   Float_t         WenuMassTCaloMET[4];   //[nWenu]
   Float_t         WenuEtCaloMET[4];   //[nWenu]
   Float_t         WenuACopCaloMET[4];   //[nWenu]
   Float_t         WenuMassTTcMET[4];   //[nWenu]
   Float_t         WenuEtTcMET[4];   //[nWenu]
   Float_t         WenuACopTcMET[4];   //[nWenu]
   Float_t         WenuMassTPfMET[4];   //[nWenu]
   Float_t         WenuEtPfMET[4];   //[nWenu]
   Float_t         WenuACopPfMET[4];   //[nWenu]
   Int_t           WenuEleIndex[4];   //[nWenu]
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
