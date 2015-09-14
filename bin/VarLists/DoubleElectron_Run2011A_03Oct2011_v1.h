   Int_t           run;
   Long64_t        event;
   Int_t           orbit;
   Int_t           bx;
   Int_t           lumis;
   Bool_t          isData;
   Int_t           ttbit0;
   Int_t           nHLT;
   Int_t           HLT[392];   //[nHLT]
   Int_t           HLTIndex[125];
   Int_t           HLTprescale[392];   //[nHLT]
   Int_t           nHFTowersP;
   Int_t           nHFTowersN;
   Int_t           nVtx;
   Float_t         vtx[36][3];   //[nVtx]
   Int_t           vtxNTrk[36];   //[nVtx]
   Float_t         vtxNDF[36];   //[nVtx]
   Float_t         vtxD0[36];   //[nVtx]
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
   Int_t           eleTrg[13][31];   //[nEle]
   Int_t           eleID[13][30];   //[nEle]
   Float_t         eleIDLH[13];   //[nEle]
   Int_t           eleClass[13];   //[nEle]
   Int_t           eleCharge[13];   //[nEle]
   Float_t         eleEn[13];   //[nEle]
   Float_t         eleSCRawEn[13];   //[nEle]
   Float_t         eleESEn[13];   //[nEle]
   Float_t         eleSCEn[13];   //[nEle]
   Float_t         elePt[13];   //[nEle]
   Float_t         elePz[13];   //[nEle]
   Float_t         eleEta[13];   //[nEle]
   Float_t         elePhi[13];   //[nEle]
   Float_t         eleSCEta[13];   //[nEle]
   Float_t         eleSCPhi[13];   //[nEle]
   Float_t         eleSCEtaWidth[13];   //[nEle]
   Float_t         eleSCPhiWidth[13];   //[nEle]
   Float_t         eleVtx[13][3];   //[nEle]
   Float_t         eleCaloPos[13][3];   //[nEle]
   Float_t         eleSCPos[13][3];   //[nEle]
   Float_t         eleHoverE[13];   //[nEle]
   Float_t         eleEoverP[13];   //[nEle]
   Float_t         elePin[13];   //[nEle]
   Float_t         elePout[13];   //[nEle]
   Float_t         eleBrem[13];   //[nEle]
   Int_t           elenBrem[13];   //[nEle]
   Float_t         eledEtaAtVtx[13];   //[nEle]
   Float_t         eledPhiAtVtx[13];   //[nEle]
   Float_t         eleSigmaEtaEta[13];   //[nEle]
   Float_t         eleSigmaIEtaIEta[13];   //[nEle]
   Float_t         eleSigmaIEtaIPhi[13];   //[nEle]
   Float_t         eleSigmaIPhiIPhi[13];   //[nEle]
   Float_t         eleE3x3[13];   //[nEle]
   Float_t         eleSeedTime[13];   //[nEle]
   Float_t         eleSeedEnergy[13];   //[nEle]
   Int_t           eleRecoFlag[13];   //[nEle]
   Int_t           eleSeverity[13];   //[nEle]
   Float_t         eleIsoTrkDR03[13];   //[nEle]
   Float_t         eleIsoEcalDR03[13];   //[nEle]
   Float_t         eleIsoHcalDR03[13];   //[nEle]
   Float_t         eleIsoHcalSolidDR03[13];   //[nEle]
   Float_t         eleIsoTrkDR04[13];   //[nEle]
   Float_t         eleIsoEcalDR04[13];   //[nEle]
   Float_t         eleIsoHcalDR04[13];   //[nEle]
   Float_t         eleIsoHcalSolidDR04[13];   //[nEle]
   Float_t         eleConvDist[13];   //[nEle]
   Float_t         eleConvDcot[13];   //[nEle]
   Float_t         eleConvRadius[13];   //[nEle]
   Int_t           eleConvFlag[13];   //[nEle]
   Int_t           eleConvMissinghit[13];   //[nEle]
   Float_t         eleESRatio[13];   //[nEle]
   Float_t         eleESProfileFront[13][123];   //[nEle]
   Float_t         eleESProfileRear[13][123];   //[nEle]
   Float_t         elePV2D[13];   //[nEle]
   Float_t         elePV3D[13];   //[nEle]
   Float_t         eleBS2D[13];   //[nEle]
   Float_t         eleBS3D[13];   //[nEle]
   Float_t         elePVD0[13];   //[nEle]
   Float_t         elePVDz[13];   //[nEle]
   Int_t           nPho;
   Int_t           phoTrg[15][14];   //[nPho]
   Bool_t          phoIsPhoton[15];   //[nPho]
   Float_t         phoE[15];   //[nPho]
   Float_t         phoEt[15];   //[nPho]
   Float_t         phoPz[15];   //[nPho]
   Float_t         phoEta[15];   //[nPho]
   Float_t         phoPhi[15];   //[nPho]
   Float_t         phoR9[15];   //[nPho]
   Float_t         phoTrkIsoSolidDR03[15];   //[nPho]
   Float_t         phoTrkIsoHollowDR03[15];   //[nPho]
   Int_t           phoNTrkSolidDR03[15];   //[nPho]
   Int_t           phoNTrkHollowDR03[15];   //[nPho]
   Float_t         phoEcalIsoDR03[15];   //[nPho]
   Float_t         phoHcalIsoDR03[15];   //[nPho]
   Float_t         phoHcalIsoSolidDR03[15];   //[nPho]
   Float_t         phoTrkIsoSolidDR04[15];   //[nPho]
   Float_t         phoTrkIsoHollowDR04[15];   //[nPho]
   Int_t           phoNTrkSolidDR04[15];   //[nPho]
   Int_t           phoNTrkHollowDR04[15];   //[nPho]
   Float_t         phoEcalIsoDR04[15];   //[nPho]
   Float_t         phoHcalIsoDR04[15];   //[nPho]
   Float_t         phoHcalIsoSolidDR04[15];   //[nPho]
   Float_t         phoEtVtx[15][150];   //[nPho]
   Float_t         phoEtaVtx[15][150];   //[nPho]
   Float_t         phoPhiVtx[15][150];   //[nPho]
   Float_t         phoTrkIsoSolidDR03Vtx[15][150];   //[nPho]
   Float_t         phoTrkIsoHollowDR03Vtx[15][150];   //[nPho]
   Float_t         phoTrkIsoSolidDR04Vtx[15][150];   //[nPho]
   Float_t         phoTrkIsoHollowDR04Vtx[15][150];   //[nPho]
   Float_t         phoHoverE[15];   //[nPho]
   Float_t         phoSigmaEtaEta[15];   //[nPho]
   Float_t         phoSigmaIEtaIEta[15];   //[nPho]
   Float_t         phoSigmaIEtaIPhi[15];   //[nPho]
   Float_t         phoSigmaIPhiIPhi[15];   //[nPho]
   Float_t         phoE3x3[15];   //[nPho]
   Float_t         phoE5x5[15];   //[nPho]
   Float_t         phoSeedTime[15];   //[nPho]
   Float_t         phoSeedEnergy[15];   //[nPho]
   Int_t           phoRecoFlag[15];   //[nPho]
   Int_t           phoSeverity[15];   //[nPho]
   Int_t           phoPos[15];   //[nPho]
   Float_t         phoSCE[15];   //[nPho]
   Float_t         phoESE[15];   //[nPho]
   Float_t         phoSCEt[15];   //[nPho]
   Float_t         phoSCEta[15];   //[nPho]
   Float_t         phoSCPhi[15];   //[nPho]
   Float_t         phoSCEtaWidth[15];   //[nPho]
   Float_t         phoSCPhiWidth[15];   //[nPho]
   Float_t         phoVtx[15][3];   //[nPho]
   Float_t         phoVtxD0[15];   //[nPho]
   Int_t           phoOverlap[15];   //[nPho]
   Int_t           phohasPixelSeed[15];   //[nPho]
   Int_t           phoIsConv[15];   //[nPho]
   Float_t         phoESRatio[15];   //[nPho]
   Float_t         phoESProfileFront[15][123];   //[nPho]
   Float_t         phoESProfileRear[15][123];   //[nPho]
   Int_t           phoNTracks[15];   //[nPho]
   Float_t         phoConvPairInvariantMass[15];   //[nPho]
   Float_t         phoConvPairCotThetaSeparation[15];   //[nPho]
   Float_t         phoConvPairMomentumEta[15];   //[nPho]
   Float_t         phoConvPairMomentumPhi[15];   //[nPho]
   Float_t         phoConvPairMomentumX[15];   //[nPho]
   Float_t         phoConvPairMomentumY[15];   //[nPho]
   Float_t         phoConvPairMomentumZ[15];   //[nPho]
   Float_t         phoConvDistOfMinimumApproach[15];   //[nPho]
   Float_t         phoConvDPhiTracksAtVtx[15];   //[nPho]
   Float_t         phoConvDPhiTracksAtEcal[15];   //[nPho]
   Float_t         phoConvDEtaTracksAtEcal[15];   //[nPho]
   Float_t         phoConvVtxValid[15];   //[nPho]
   Float_t         phoConvVtxEta[15];   //[nPho]
   Float_t         phoConvVtxPhi[15];   //[nPho]
   Float_t         phoConvVtxR[15];   //[nPho]
   Float_t         phoConvVtxX[15];   //[nPho]
   Float_t         phoConvVtxY[15];   //[nPho]
   Float_t         phoConvVtxZ[15];   //[nPho]
   Float_t         phoConvVtxChi2[15];   //[nPho]
   Float_t         phoConvVtxNdof[15];   //[nPho]
   Float_t         phoConvChi2Prob[15];   //[nPho]
   Float_t         phoConvEoverP[15];   //[nPho]
   Int_t           phoNxtal[15];   //[nPho]
   Float_t         phoXtalTime[15][200];   //[nPho]
   Float_t         phoXtalEnergy[15][200];   //[nPho]
   Int_t           phoXtalZ[15][200];   //[nPho]
   Int_t           phoXtalX[15][200];   //[nPho]
   Int_t           phoXtalY[15][200];   //[nPho]
   Int_t           phoXtalEta[15][200];   //[nPho]
   Int_t           phoXtalPhi[15][200];   //[nPho]
   Float_t         pho5x5Time[15][25];   //[nPho]
   Float_t         pho5x5Energy[15][25];   //[nPho]
   Int_t           pho5x5Z[15][25];   //[nPho]
   Int_t           pho5x5X[15][25];   //[nPho]
   Int_t           pho5x5Y[15][25];   //[nPho]
   Int_t           pho5x5Eta[15][25];   //[nPho]
   Int_t           pho5x5Phi[15][25];   //[nPho]
   Int_t           nMu;
   Int_t           muTrg[25][16];   //[nMu]
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
   Float_t         muDz[25];   //[nMu]
   Float_t         muPVD0[25];   //[nMu]
   Float_t         muPVDz[25];   //[nMu]
   Float_t         muValidFraction[25];   //[nMu]
   Float_t         muTrkdPt[25];   //[nMu]
   Int_t           muNumberOfHits[25];   //[nMu]
   Int_t           muNumberOfValidHits[25];   //[nMu]
   Int_t           muNumberOfInactiveHits[25];   //[nMu]
   Int_t           muNumberOfValidTrkHits[25];   //[nMu]
   Int_t           muNumberOfValidPixelHits[25];   //[nMu]
   Int_t           muNumberOfValidMuonHits[25];   //[nMu]
   Int_t           muStations[25];   //[nMu]
   Int_t           muChambers[25];   //[nMu]
   Float_t         muPV2D[25];   //[nMu]
   Float_t         muPV3D[25];   //[nMu]
   Float_t         muBS2D[25];   //[nMu]
   Float_t         muBS3D[25];   //[nMu]
   Float_t         muVtx[25][3];   //[nMu]
   Int_t           nJet;
   Int_t           jetTrg[19][23];   //[nJet]
   Float_t         jetEn[19];   //[nJet]
   Float_t         jetPt[19];   //[nJet]
   Float_t         jetEta[19];   //[nJet]
   Float_t         jetPhi[19];   //[nJet]
   Float_t         jetMass[19];   //[nJet]
   Float_t         jetEt[19];   //[nJet]
   Int_t           jetpartonFlavour[19];   //[nJet]
   Float_t         jetRawPt[19];   //[nJet]
   Float_t         jetRawEn[19];   //[nJet]
   Float_t         jetCharge[19];   //[nJet]
   Float_t         jetNeutralEmEnergy[19];   //[nJet]
   Float_t         jetNeutralEmEnergyFraction[19];   //[nJet]
   Float_t         jetNeutralHadronEnergy[19];   //[nJet]
   Float_t         jetNeutralHadronEnergyFraction[19];   //[nJet]
   Int_t           jetNConstituents[19];   //[nJet]
   Float_t         jetChargedEmEnergy[19];   //[nJet]
   Float_t         jetChargedEmEnergyFraction[19];   //[nJet]
   Float_t         jetChargedHadronEnergy[19];   //[nJet]
   Float_t         jetChargedHadronEnergyFraction[19];   //[nJet]
   Int_t           jetChargedHadronMultiplicity[19];   //[nJet]
   Float_t         jetChargedMuEnergy[19];   //[nJet]
   Float_t         jetChargedMuEnergyFraction[19];   //[nJet]
   Double_t        jetJVAlpha[19];   //[nJet]
   Double_t        jetJVBeta[19];   //[nJet]
   Int_t           nZee;
   Float_t         ZeeMass[78];   //[nZee]
   Float_t         ZeePt[78];   //[nZee]
   Float_t         ZeeEta[78];   //[nZee]
   Float_t         ZeePhi[78];   //[nZee]
   Int_t           ZeeLeg1Index[78];   //[nZee]
   Int_t           ZeeLeg2Index[78];   //[nZee]
   Int_t           nZmumu;
   Float_t         ZmumuMass[4];   //[nZmumu]
   Float_t         ZmumuPt[4];   //[nZmumu]
   Float_t         ZmumuEta[4];   //[nZmumu]
   Float_t         ZmumuPhi[4];   //[nZmumu]
   Int_t           ZmumuLeg1Index[4];   //[nZmumu]
   Int_t           ZmumuLeg2Index[4];   //[nZmumu]
   Int_t           nWenu;
   Float_t         WenuMassTCaloMET[13];   //[nWenu]
   Float_t         WenuEtCaloMET[13];   //[nWenu]
   Float_t         WenuACopCaloMET[13];   //[nWenu]
   Float_t         WenuMassTTcMET[13];   //[nWenu]
   Float_t         WenuEtTcMET[13];   //[nWenu]
   Float_t         WenuACopTcMET[13];   //[nWenu]
   Float_t         WenuMassTPfMET[13];   //[nWenu]
   Float_t         WenuEtPfMET[13];   //[nWenu]
   Float_t         WenuACopPfMET[13];   //[nWenu]
   Int_t           WenuEleIndex[13];   //[nWenu]
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
