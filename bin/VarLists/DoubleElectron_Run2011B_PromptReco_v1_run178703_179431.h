   Int_t           run;
   Long64_t        event;
   Int_t           orbit;
   Int_t           bx;
   Int_t           lumis;
   Bool_t          isData;
   Int_t           ttbit0;
   Int_t           nHLT;
   Int_t           HLT[430];   //[nHLT]
   Int_t           HLTIndex[125];
   Int_t           HLTprescale[430];   //[nHLT]
   Int_t           nHFTowersP;
   Int_t           nHFTowersN;
   Int_t           nVtx;
   Float_t         vtx[43][3];   //[nVtx]
   Int_t           vtxNTrk[43];   //[nVtx]
   Float_t         vtxNDF[43];   //[nVtx]
   Float_t         vtxD0[43];   //[nVtx]
   Int_t           nGoodVtx;
   Int_t           IsVtxGood;
   Int_t           nTrk;
   Int_t           nGoodTrk;
   Int_t           IsTracksGood;
   Float_t         rho;
   Float_t         sigma;
   Float_t         rhoNeutral;
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
   Float_t         TypeIpfMET;
   Float_t         TypeIpfMETx;
   Float_t         TypeIpfMETy;
   Float_t         TypeIpfMETPhi;
   Float_t         TypeIpfMETsumEt;
   Float_t         TypeIpfMETmEtSig;
   Float_t         TypeIpfMETSig;
   Float_t         TypeIpIIpfMET;
   Float_t         TypeIpIIpfMETx;
   Float_t         TypeIpIIpfMETy;
   Float_t         TypeIpIIpfMETPhi;
   Float_t         TypeIpIIpfMETsumEt;
   Float_t         TypeIpIIpfMETmEtSig;
   Float_t         TypeIpIIpfMETSig;
   Int_t           npfCharged;
   Float_t         pfChargedSumPt;
   Int_t           npfChargedHadron;
   Float_t         pfChargedHadronSumPt;
   Int_t           npfLepton;
   Float_t         pfLeptonSumPt;
   Int_t           npfNeutral;
   Float_t         pfNeutralSumPt;
   Int_t           npfNeutralHadron;
   Float_t         pfNeutralHadronSumPt;
   Int_t           npfPhoton;
   Float_t         pfPhotonSumPt;
   Int_t           nEle;
   Int_t           eleTrg[10][31];   //[nEle]
   Int_t           eleID[10][30];   //[nEle]
   Float_t         eleIDLH[10];   //[nEle]
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
   Int_t           elenBrem[10];   //[nEle]
   Float_t         eledEtaAtVtx[10];   //[nEle]
   Float_t         eledPhiAtVtx[10];   //[nEle]
   Float_t         eleSigmaEtaEta[10];   //[nEle]
   Float_t         eleSigmaIEtaIEta[10];   //[nEle]
   Float_t         eleSigmaIEtaIPhi[10];   //[nEle]
   Float_t         eleSigmaIPhiIPhi[10];   //[nEle]
   Float_t         eleE3x3[10];   //[nEle]
   Float_t         eleSeedTime[10];   //[nEle]
   Float_t         eleSeedEnergy[10];   //[nEle]
   Int_t           eleRecoFlag[10];   //[nEle]
   Int_t           eleSeverity[10];   //[nEle]
   Float_t         eleIsoTrkDR03[10];   //[nEle]
   Float_t         eleIsoEcalDR03[10];   //[nEle]
   Float_t         eleIsoHcalDR03[10];   //[nEle]
   Float_t         eleIsoHcalSolidDR03[10];   //[nEle]
   Float_t         eleIsoTrkDR04[10];   //[nEle]
   Float_t         eleIsoEcalDR04[10];   //[nEle]
   Float_t         eleIsoHcalDR04[10];   //[nEle]
   Float_t         eleIsoHcalSolidDR04[10];   //[nEle]
   Float_t         eleConvDist[10];   //[nEle]
   Float_t         eleConvDcot[10];   //[nEle]
   Float_t         eleConvRadius[10];   //[nEle]
   Int_t           eleConvFlag[10];   //[nEle]
   Int_t           eleConvMissinghit[10];   //[nEle]
   Float_t         eleESRatio[10];   //[nEle]
   Float_t         eleESProfileFront[10][123];   //[nEle]
   Float_t         eleESProfileRear[10][123];   //[nEle]
   Float_t         elePV2D[10];   //[nEle]
   Float_t         elePV3D[10];   //[nEle]
   Float_t         eleBS2D[10];   //[nEle]
   Float_t         eleBS3D[10];   //[nEle]
   Float_t         elePVD0[10];   //[nEle]
   Float_t         elePVDz[10];   //[nEle]
   Int_t           nPho;
   Int_t           phoTrg[10][14];   //[nPho]
   Bool_t          phoIsPhoton[10];   //[nPho]
   Float_t         phoE[10];   //[nPho]
   Float_t         phoEt[10];   //[nPho]
   Float_t         phoPz[10];   //[nPho]
   Float_t         phoEta[10];   //[nPho]
   Float_t         phoPhi[10];   //[nPho]
   Float_t         phoR9[10];   //[nPho]
   Float_t         phoTrkIsoSolidDR03[10];   //[nPho]
   Float_t         phoTrkIsoHollowDR03[10];   //[nPho]
   Int_t           phoNTrkSolidDR03[10];   //[nPho]
   Int_t           phoNTrkHollowDR03[10];   //[nPho]
   Float_t         phoEcalIsoDR03[10];   //[nPho]
   Float_t         phoHcalIsoDR03[10];   //[nPho]
   Float_t         phoHcalIsoSolidDR03[10];   //[nPho]
   Float_t         phoTrkIsoSolidDR04[10];   //[nPho]
   Float_t         phoTrkIsoHollowDR04[10];   //[nPho]
   Int_t           phoNTrkSolidDR04[10];   //[nPho]
   Int_t           phoNTrkHollowDR04[10];   //[nPho]
   Float_t         phoEcalIsoDR04[10];   //[nPho]
   Float_t         phoHcalIsoDR04[10];   //[nPho]
   Float_t         phoHcalIsoSolidDR04[10];   //[nPho]
   Float_t         phoEtVtx[10][150];   //[nPho]
   Float_t         phoEtaVtx[10][150];   //[nPho]
   Float_t         phoPhiVtx[10][150];   //[nPho]
   Float_t         phoTrkIsoSolidDR03Vtx[10][150];   //[nPho]
   Float_t         phoTrkIsoHollowDR03Vtx[10][150];   //[nPho]
   Float_t         phoTrkIsoSolidDR04Vtx[10][150];   //[nPho]
   Float_t         phoTrkIsoHollowDR04Vtx[10][150];   //[nPho]
   Float_t         phoHoverE[10];   //[nPho]
   Float_t         phoSigmaEtaEta[10];   //[nPho]
   Float_t         phoSigmaIEtaIEta[10];   //[nPho]
   Float_t         phoSigmaIEtaIPhi[10];   //[nPho]
   Float_t         phoSigmaIPhiIPhi[10];   //[nPho]
   Float_t         phoE3x3[10];   //[nPho]
   Float_t         phoE5x5[10];   //[nPho]
   Float_t         phoSeedTime[10];   //[nPho]
   Float_t         phoSeedEnergy[10];   //[nPho]
   Int_t           phoRecoFlag[10];   //[nPho]
   Int_t           phoSeverity[10];   //[nPho]
   Int_t           phoPos[10];   //[nPho]
   Float_t         phoSCE[10];   //[nPho]
   Float_t         phoESE[10];   //[nPho]
   Float_t         phoSCEt[10];   //[nPho]
   Float_t         phoSCEta[10];   //[nPho]
   Float_t         phoSCPhi[10];   //[nPho]
   Float_t         phoSCEtaWidth[10];   //[nPho]
   Float_t         phoSCPhiWidth[10];   //[nPho]
   Float_t         phoVtx[10][3];   //[nPho]
   Float_t         phoVtxD0[10];   //[nPho]
   Int_t           phoOverlap[10];   //[nPho]
   Int_t           phohasPixelSeed[10];   //[nPho]
   Int_t           phoIsConv[10];   //[nPho]
   Float_t         phoESRatio[10];   //[nPho]
   Float_t         phoESProfileFront[10][123];   //[nPho]
   Float_t         phoESProfileRear[10][123];   //[nPho]
   Int_t           phoNTracks[10];   //[nPho]
   Float_t         phoConvPairInvariantMass[10];   //[nPho]
   Float_t         phoConvPairCotThetaSeparation[10];   //[nPho]
   Float_t         phoConvPairMomentumEta[10];   //[nPho]
   Float_t         phoConvPairMomentumPhi[10];   //[nPho]
   Float_t         phoConvPairMomentumX[10];   //[nPho]
   Float_t         phoConvPairMomentumY[10];   //[nPho]
   Float_t         phoConvPairMomentumZ[10];   //[nPho]
   Float_t         phoConvDistOfMinimumApproach[10];   //[nPho]
   Float_t         phoConvDPhiTracksAtVtx[10];   //[nPho]
   Float_t         phoConvDPhiTracksAtEcal[10];   //[nPho]
   Float_t         phoConvDEtaTracksAtEcal[10];   //[nPho]
   Float_t         phoConvVtxValid[10];   //[nPho]
   Float_t         phoConvVtxEta[10];   //[nPho]
   Float_t         phoConvVtxPhi[10];   //[nPho]
   Float_t         phoConvVtxR[10];   //[nPho]
   Float_t         phoConvVtxX[10];   //[nPho]
   Float_t         phoConvVtxY[10];   //[nPho]
   Float_t         phoConvVtxZ[10];   //[nPho]
   Float_t         phoConvVtxChi2[10];   //[nPho]
   Float_t         phoConvVtxNdof[10];   //[nPho]
   Float_t         phoConvChi2Prob[10];   //[nPho]
   Float_t         phoConvEoverP[10];   //[nPho]
   Int_t           phoNxtal[10];   //[nPho]
   Float_t         phoXtalTime[10][200];   //[nPho]
   Float_t         phoXtalEnergy[10][200];   //[nPho]
   Int_t           phoXtalZ[10][200];   //[nPho]
   Int_t           phoXtalX[10][200];   //[nPho]
   Int_t           phoXtalY[10][200];   //[nPho]
   Int_t           phoXtalEta[10][200];   //[nPho]
   Int_t           phoXtalPhi[10][200];   //[nPho]
   Float_t         pho5x5Time[10][25];   //[nPho]
   Float_t         pho5x5Energy[10][25];   //[nPho]
   Int_t           pho5x5Z[10][25];   //[nPho]
   Int_t           pho5x5X[10][25];   //[nPho]
   Int_t           pho5x5Y[10][25];   //[nPho]
   Int_t           pho5x5Eta[10][25];   //[nPho]
   Int_t           pho5x5Phi[10][25];   //[nPho]
   Int_t           nMu;
   Int_t           muTrg[29][16];   //[nMu]
   Float_t         muEta[29];   //[nMu]
   Float_t         muPhi[29];   //[nMu]
   Int_t           muCharge[29];   //[nMu]
   Float_t         muPt[29];   //[nMu]
   Float_t         muPz[29];   //[nMu]
   Float_t         muIsoTrk[29];   //[nMu]
   Float_t         muIsoCalo[29];   //[nMu]
   Float_t         muIsoEcal[29];   //[nMu]
   Float_t         muIsoHcal[29];   //[nMu]
   Float_t         muChi2NDF[29];   //[nMu]
   Float_t         muEmVeto[29];   //[nMu]
   Float_t         muHadVeto[29];   //[nMu]
   Int_t           muType[29];   //[nMu]
   Bool_t          muID[29][6];   //[nMu]
   Float_t         muD0[29];   //[nMu]
   Float_t         muDz[29];   //[nMu]
   Float_t         muPVD0[29];   //[nMu]
   Float_t         muPVDz[29];   //[nMu]
   Float_t         muValidFraction[29];   //[nMu]
   Float_t         muTrkdPt[29];   //[nMu]
   Int_t           muNumberOfHits[29];   //[nMu]
   Int_t           muNumberOfValidHits[29];   //[nMu]
   Int_t           muNumberOfInactiveHits[29];   //[nMu]
   Int_t           muNumberOfValidTrkHits[29];   //[nMu]
   Int_t           muNumberOfValidPixelHits[29];   //[nMu]
   Int_t           muNumberOfValidMuonHits[29];   //[nMu]
   Int_t           muStations[29];   //[nMu]
   Int_t           muChambers[29];   //[nMu]
   Float_t         muPV2D[29];   //[nMu]
   Float_t         muPV3D[29];   //[nMu]
   Float_t         muBS2D[29];   //[nMu]
   Float_t         muBS3D[29];   //[nMu]
   Float_t         muVtx[29][3];   //[nMu]
   Int_t           nJet;
   Int_t           jetTrg[24][23];   //[nJet]
   Float_t         jetEn[24];   //[nJet]
   Float_t         jetPt[24];   //[nJet]
   Float_t         jetEta[24];   //[nJet]
   Float_t         jetPhi[24];   //[nJet]
   Float_t         jetMass[24];   //[nJet]
   Float_t         jetEt[24];   //[nJet]
   Int_t           jetpartonFlavour[24];   //[nJet]
   Float_t         jetRawPt[24];   //[nJet]
   Float_t         jetRawEn[24];   //[nJet]
   Float_t         jetCharge[24];   //[nJet]
   Float_t         jetNeutralEmEnergy[24];   //[nJet]
   Float_t         jetNeutralEmEnergyFraction[24];   //[nJet]
   Float_t         jetNeutralHadronEnergy[24];   //[nJet]
   Float_t         jetNeutralHadronEnergyFraction[24];   //[nJet]
   Int_t           jetNConstituents[24];   //[nJet]
   Float_t         jetChargedEmEnergy[24];   //[nJet]
   Float_t         jetChargedEmEnergyFraction[24];   //[nJet]
   Float_t         jetChargedHadronEnergy[24];   //[nJet]
   Float_t         jetChargedHadronEnergyFraction[24];   //[nJet]
   Int_t           jetChargedHadronMultiplicity[24];   //[nJet]
   Float_t         jetChargedMuEnergy[24];   //[nJet]
   Float_t         jetChargedMuEnergyFraction[24];   //[nJet]
   Double_t        jetJVAlpha[24];   //[nJet]
   Double_t        jetJVBeta[24];   //[nJet]
   Int_t           nZee;
   Float_t         ZeeMass[45];   //[nZee]
   Float_t         ZeePt[45];   //[nZee]
   Float_t         ZeeEta[45];   //[nZee]
   Float_t         ZeePhi[45];   //[nZee]
   Int_t           ZeeLeg1Index[45];   //[nZee]
   Int_t           ZeeLeg2Index[45];   //[nZee]
   Int_t           nZmumu;
   Float_t         ZmumuMass[6];   //[nZmumu]
   Float_t         ZmumuPt[6];   //[nZmumu]
   Float_t         ZmumuEta[6];   //[nZmumu]
   Float_t         ZmumuPhi[6];   //[nZmumu]
   Int_t           ZmumuLeg1Index[6];   //[nZmumu]
   Int_t           ZmumuLeg2Index[6];   //[nZmumu]
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
