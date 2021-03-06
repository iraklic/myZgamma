   Int_t           run;
   Int_t           event;
   Int_t           orbit;
   Int_t           bx;
   Int_t           lumis;
   Bool_t          isData;
   Int_t           ttbit0;
   Int_t           nHLT;
   Int_t           HLT[239];   //[nHLT]
   Int_t           HLTIndex[172];
   Int_t           HLTprescale[239];   //[nHLT]
   Int_t           nHFTowersP;
   Int_t           nHFTowersN;
   Int_t           nVtx;
   Float_t         vtx[31][3];   //[nVtx]
   Int_t           vtxNTrk[31];   //[nVtx]
   Int_t           vtxNDF[31];   //[nVtx]
   Float_t         vtxD0[31];   //[nVtx]
   Int_t           nGoodVtx;
   Int_t           IsVtxGood;
   Int_t           nTrk;
   Int_t           nGoodTrk;
   Int_t           IsTracksGood;
   Float_t         rho;
   Float_t         sigma;
   Float_t         pdf[7];
   Float_t         pthat;
   Float_t         processID;
   Int_t           nBX;
   Int_t           nPU[3];   //[nBX]
   Int_t           BXPU[3];   //[nBX]
   Int_t           nMC;
   Int_t           mcPID[21];   //[nMC]
   Float_t         mcPt[21];   //[nMC]
   Float_t         mcMass[21];   //[nMC]
   Float_t         mcEta[21];   //[nMC]
   Float_t         mcPhi[21];   //[nMC]
   Int_t           mcGMomPID[21];   //[nMC]
   Int_t           mcMomPID[21];   //[nMC]
   Float_t         mcMomPt[21];   //[nMC]
   Float_t         mcMomMass[21];   //[nMC]
   Float_t         mcMomEta[21];   //[nMC]
   Float_t         mcMomPhi[21];   //[nMC]
   Int_t           mcIndex[21];   //[nMC]
   Int_t           mcDecayType[21];   //[nMC]
   Float_t         mcIsoDR03[21];   //[nMC]
   Float_t         mcCalIsoDR03[21];   //[nMC]
   Float_t         mcTrkIsoDR03[21];   //[nMC]
   Float_t         mcIsoDR04[21];   //[nMC]
   Float_t         mcCalIsoDR04[21];   //[nMC]
   Float_t         mcTrkIsoDR04[21];   //[nMC]
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
   Int_t           eleTrg[5][25];   //[nEle]
   Int_t           eleID[5][30];   //[nEle]
   Float_t         eleIDLH[5];   //[nEle]
   Int_t           eleClass[5];   //[nEle]
   Int_t           eleCharge[5];   //[nEle]
   Float_t         eleEn[5];   //[nEle]
   Float_t         eleSCRawEn[5];   //[nEle]
   Float_t         eleESEn[5];   //[nEle]
   Float_t         eleSCEn[5];   //[nEle]
   Float_t         elePt[5];   //[nEle]
   Float_t         elePz[5];   //[nEle]
   Float_t         eleEta[5];   //[nEle]
   Float_t         elePhi[5];   //[nEle]
   Float_t         eleSCEta[5];   //[nEle]
   Float_t         eleSCPhi[5];   //[nEle]
   Float_t         eleSCEtaWidth[5];   //[nEle]
   Float_t         eleSCPhiWidth[5];   //[nEle]
   Float_t         eleVtx[5][3];   //[nEle]
   Float_t         eleCaloPos[5][3];   //[nEle]
   Float_t         eleSCPos[5][3];   //[nEle]
   Float_t         eleHoverE[5];   //[nEle]
   Float_t         eleEoverP[5];   //[nEle]
   Float_t         elePin[5];   //[nEle]
   Float_t         elePout[5];   //[nEle]
   Float_t         eleBrem[5];   //[nEle]
   Int_t           elenBrem[5];   //[nEle]
   Float_t         eledEtaAtVtx[5];   //[nEle]
   Float_t         eledPhiAtVtx[5];   //[nEle]
   Float_t         eleSigmaEtaEta[5];   //[nEle]
   Float_t         eleSigmaIEtaIEta[5];   //[nEle]
   Float_t         eleSigmaIEtaIPhi[5];   //[nEle]
   Float_t         eleSigmaIPhiIPhi[5];   //[nEle]
   Float_t         eleE2overE9[5];   //[nEle]
   Float_t         eleE3x3[5];   //[nEle]
   Float_t         eleSeedTime[5];   //[nEle]
   Int_t           eleRecoFlag[5];   //[nEle]
   Int_t           eleSeverity[5];   //[nEle]
   Int_t           eleGenIndex[5];   //[nEle]
   Int_t           eleGenGMomPID[5];   //[nEle]
   Int_t           eleGenMomPID[5];   //[nEle]
   Float_t         eleGenMomPt[5];   //[nEle]
   Float_t         eleIsoTrkDR03[5];   //[nEle]
   Float_t         eleIsoEcalDR03[5];   //[nEle]
   Float_t         eleIsoHcalDR03[5];   //[nEle]
   Float_t         eleIsoHcalSolidDR03[5];   //[nEle]
   Float_t         eleIsoTrkDR04[5];   //[nEle]
   Float_t         eleIsoEcalDR04[5];   //[nEle]
   Float_t         eleIsoHcalDR04[5];   //[nEle]
   Float_t         eleIsoHcalSolidDR04[5];   //[nEle]
   Float_t         eleConvDist[5];   //[nEle]
   Float_t         eleConvDcot[5];   //[nEle]
   Float_t         eleConvRadius[5];   //[nEle]
   Int_t           eleConvFlag[5];   //[nEle]
   Int_t           eleConvMissinghit[5];   //[nEle]
   Float_t         eleESRatio[5];   //[nEle]
   Float_t         eleESProfileFront[5][123];   //[nEle]
   Float_t         eleESProfileRear[5][123];   //[nEle]
   Float_t         elePV2D[5];   //[nEle]
   Float_t         elePV3D[5];   //[nEle]
   Float_t         eleBS2D[5];   //[nEle]
   Float_t         eleBS3D[5];   //[nEle]
   Int_t           nPho;
   Int_t           phoTrg[7][8];   //[nPho]
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
   Float_t         phoHcalIsoSolidDR03[7];   //[nPho]
   Float_t         phoTrkIsoSolidDR04[7];   //[nPho]
   Float_t         phoTrkIsoHollowDR04[7];   //[nPho]
   Int_t           phoNTrkSolidDR04[7];   //[nPho]
   Int_t           phoNTrkHollowDR04[7];   //[nPho]
   Float_t         phoEcalIsoDR04[7];   //[nPho]
   Float_t         phoHcalIsoDR04[7];   //[nPho]
   Float_t         phoHcalIsoSolidDR04[7];   //[nPho]
   Float_t         phoHoverE[7];   //[nPho]
   Float_t         phoSigmaEtaEta[7];   //[nPho]
   Float_t         phoSigmaIEtaIEta[7];   //[nPho]
   Float_t         phoSigmaIEtaIPhi[7];   //[nPho]
   Float_t         phoSigmaIPhiIPhi[7];   //[nPho]
   Float_t         phoE2overE9[7];   //[nPho]
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
   Float_t         phoESRatio[7];   //[nPho]
   Float_t         phoESProfileFront[7][123];   //[nPho]
   Float_t         phoESProfileRear[7][123];   //[nPho]
   Int_t           nMu;
   Int_t           muTrg[20][32];   //[nMu]
   Float_t         muEta[20];   //[nMu]
   Float_t         muPhi[20];   //[nMu]
   Int_t           muCharge[20];   //[nMu]
   Float_t         muPt[20];   //[nMu]
   Float_t         muPz[20];   //[nMu]
   Int_t           muGenIndex[20];   //[nMu]
   Int_t           muGenGMomPID[20];   //[nMu]
   Int_t           muGenMomPID[20];   //[nMu]
   Float_t         muGenMomPt[20];   //[nMu]
   Float_t         muIsoTrk[20];   //[nMu]
   Float_t         muIsoCalo[20];   //[nMu]
   Float_t         muIsoEcal[20];   //[nMu]
   Float_t         muIsoHcal[20];   //[nMu]
   Float_t         muChi2NDF[20];   //[nMu]
   Float_t         muEmVeto[20];   //[nMu]
   Float_t         muHadVeto[20];   //[nMu]
   Int_t           muType[20];   //[nMu]
   Bool_t          muID[20][6];   //[nMu]
   Float_t         muD0[20];   //[nMu]
   Float_t         muDz[20];   //[nMu]
   Float_t         muPVD0[20];   //[nMu]
   Float_t         muPVDz[20];   //[nMu]
   Float_t         muValidFraction[20];   //[nMu]
   Float_t         muTrkdPt[20];   //[nMu]
   Int_t           muNumberOfHits[20];   //[nMu]
   Int_t           muNumberOfValidHits[20];   //[nMu]
   Int_t           muNumberOfInactiveHits[20];   //[nMu]
   Int_t           muNumberOfValidTrkHits[20];   //[nMu]
   Int_t           muNumberOfValidPixelHits[20];   //[nMu]
   Int_t           muNumberOfValidMuonHits[20];   //[nMu]
   Int_t           muStations[20];   //[nMu]
   Int_t           muChambers[20];   //[nMu]
   Float_t         muPV2D[20];   //[nMu]
   Float_t         muPV3D[20];   //[nMu]
   Float_t         muBS2D[20];   //[nMu]
   Float_t         muBS3D[20];   //[nMu]
   Int_t           nJet;
   Int_t           jetTrg[55][49];   //[nJet]
   Float_t         jetEn[55];   //[nJet]
   Float_t         jetPt[55];   //[nJet]
   Float_t         jetEta[55];   //[nJet]
   Float_t         jetPhi[55];   //[nJet]
   Float_t         jetMass[55];   //[nJet]
   Float_t         jetEt[55];   //[nJet]
   Int_t           jetpartonFlavour[55];   //[nJet]
   Float_t         jetRawPt[55];   //[nJet]
   Float_t         jetRawEn[55];   //[nJet]
   Float_t         jetCharge[55];   //[nJet]
   Float_t         jetNeutralEmEnergy[55];   //[nJet]
   Float_t         jetNeutralEmEnergyFraction[55];   //[nJet]
   Float_t         jetNeutralHadronEnergy[55];   //[nJet]
   Float_t         jetNeutralHadronEnergyFraction[55];   //[nJet]
   Int_t           jetNConstituents[55];   //[nJet]
   Float_t         jetChargedEmEnergy[55];   //[nJet]
   Float_t         jetChargedEmEnergyFraction[55];   //[nJet]
   Float_t         jetChargedHadronEnergy[55];   //[nJet]
   Float_t         jetChargedHadronEnergyFraction[55];   //[nJet]
   Float_t         jetChargedMuEnergy[55];   //[nJet]
   Float_t         jetChargedMuEnergyFraction[55];   //[nJet]
   Int_t           jetGenJetIndex[55];   //[nJet]
   Float_t         jetGenJetEn[55];   //[nJet]
   Float_t         jetGenJetPt[55];   //[nJet]
   Float_t         jetGenJetEta[55];   //[nJet]
   Float_t         jetGenJetPhi[55];   //[nJet]
   Float_t         jetGenJetMass[55];   //[nJet]
   Int_t           jetGenPartonID[55];   //[nJet]
   Int_t           jetGenPartonMomID[55];   //[nJet]
   Int_t           nZee;
   Float_t         ZeeMass[10];   //[nZee]
   Float_t         ZeePt[10];   //[nZee]
   Float_t         ZeeEta[10];   //[nZee]
   Float_t         ZeePhi[10];   //[nZee]
   Int_t           ZeeLeg1Index[10];   //[nZee]
   Int_t           ZeeLeg2Index[10];   //[nZee]
   Int_t           nZmumu;
   Float_t         ZmumuMass[4];   //[nZmumu]
   Float_t         ZmumuPt[4];   //[nZmumu]
   Float_t         ZmumuEta[4];   //[nZmumu]
   Float_t         ZmumuPhi[4];   //[nZmumu]
   Int_t           ZmumuLeg1Index[4];   //[nZmumu]
   Int_t           ZmumuLeg2Index[4];   //[nZmumu]
   Int_t           nWenu;
   Float_t         WenuMassTCaloMET[5];   //[nWenu]
   Float_t         WenuEtCaloMET[5];   //[nWenu]
   Float_t         WenuACopCaloMET[5];   //[nWenu]
   Float_t         WenuMassTTcMET[5];   //[nWenu]
   Float_t         WenuEtTcMET[5];   //[nWenu]
   Float_t         WenuACopTcMET[5];   //[nWenu]
   Float_t         WenuMassTPfMET[5];   //[nWenu]
   Float_t         WenuEtPfMET[5];   //[nWenu]
   Float_t         WenuACopPfMET[5];   //[nWenu]
   Int_t           WenuEleIndex[5];   //[nWenu]
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
