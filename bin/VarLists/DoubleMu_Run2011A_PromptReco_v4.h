   Int_t           run;
   Long64_t        event;
   Int_t           orbit;
   Int_t           bx;
   Int_t           lumis;
   Bool_t          isData;
   Int_t           ttbit0;
   Int_t           nHLT;
   Int_t           HLT[385];   //[nHLT]
   Int_t           HLTIndex[125];
   Int_t           HLTprescale[385];   //[nHLT]
   Int_t           nHFTowersP;
   Int_t           nHFTowersN;
   Int_t           nVtx;
   Float_t         vtx[31][3];   //[nVtx]
   Int_t           vtxNTrk[31];   //[nVtx]
   Float_t         vtxNDF[31];   //[nVtx]
   Float_t         vtxD0[31];   //[nVtx]
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
   Int_t           eleTrg[9][31];   //[nEle]
   Int_t           eleID[9][30];   //[nEle]
   Float_t         eleIDLH[9];   //[nEle]
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
   Int_t           elenBrem[9];   //[nEle]
   Float_t         eledEtaAtVtx[9];   //[nEle]
   Float_t         eledPhiAtVtx[9];   //[nEle]
   Float_t         eleSigmaEtaEta[9];   //[nEle]
   Float_t         eleSigmaIEtaIEta[9];   //[nEle]
   Float_t         eleSigmaIEtaIPhi[9];   //[nEle]
   Float_t         eleSigmaIPhiIPhi[9];   //[nEle]
   Float_t         eleE3x3[9];   //[nEle]
   Float_t         eleSeedTime[9];   //[nEle]
   Float_t         eleSeedEnergy[9];   //[nEle]
   Int_t           eleRecoFlag[9];   //[nEle]
   Int_t           eleSeverity[9];   //[nEle]
   Float_t         eleIsoTrkDR03[9];   //[nEle]
   Float_t         eleIsoEcalDR03[9];   //[nEle]
   Float_t         eleIsoHcalDR03[9];   //[nEle]
   Float_t         eleIsoHcalSolidDR03[9];   //[nEle]
   Float_t         eleIsoTrkDR04[9];   //[nEle]
   Float_t         eleIsoEcalDR04[9];   //[nEle]
   Float_t         eleIsoHcalDR04[9];   //[nEle]
   Float_t         eleIsoHcalSolidDR04[9];   //[nEle]
   Float_t         eleConvDist[9];   //[nEle]
   Float_t         eleConvDcot[9];   //[nEle]
   Float_t         eleConvRadius[9];   //[nEle]
   Int_t           eleConvFlag[9];   //[nEle]
   Int_t           eleConvMissinghit[9];   //[nEle]
   Float_t         eleESRatio[9];   //[nEle]
   Float_t         eleESProfileFront[9][123];   //[nEle]
   Float_t         eleESProfileRear[9][123];   //[nEle]
   Float_t         elePV2D[9];   //[nEle]
   Float_t         elePV3D[9];   //[nEle]
   Float_t         eleBS2D[9];   //[nEle]
   Float_t         eleBS3D[9];   //[nEle]
   Float_t         elePVD0[9];   //[nEle]
   Float_t         elePVDz[9];   //[nEle]
   Int_t           nPho;
   Int_t           phoTrg[11][14];   //[nPho]
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
   Float_t         phoHcalIsoSolidDR03[11];   //[nPho]
   Float_t         phoTrkIsoSolidDR04[11];   //[nPho]
   Float_t         phoTrkIsoHollowDR04[11];   //[nPho]
   Int_t           phoNTrkSolidDR04[11];   //[nPho]
   Int_t           phoNTrkHollowDR04[11];   //[nPho]
   Float_t         phoEcalIsoDR04[11];   //[nPho]
   Float_t         phoHcalIsoDR04[11];   //[nPho]
   Float_t         phoHcalIsoSolidDR04[11];   //[nPho]
   Float_t         phoEtVtx[11][150];   //[nPho]
   Float_t         phoEtaVtx[11][150];   //[nPho]
   Float_t         phoPhiVtx[11][150];   //[nPho]
   Float_t         phoTrkIsoSolidDR03Vtx[11][150];   //[nPho]
   Float_t         phoTrkIsoHollowDR03Vtx[11][150];   //[nPho]
   Float_t         phoTrkIsoSolidDR04Vtx[11][150];   //[nPho]
   Float_t         phoTrkIsoHollowDR04Vtx[11][150];   //[nPho]
   Float_t         phoHoverE[11];   //[nPho]
   Float_t         phoSigmaEtaEta[11];   //[nPho]
   Float_t         phoSigmaIEtaIEta[11];   //[nPho]
   Float_t         phoSigmaIEtaIPhi[11];   //[nPho]
   Float_t         phoSigmaIPhiIPhi[11];   //[nPho]
   Float_t         phoE3x3[11];   //[nPho]
   Float_t         phoE5x5[11];   //[nPho]
   Float_t         phoSeedTime[11];   //[nPho]
   Float_t         phoSeedEnergy[11];   //[nPho]
   Int_t           phoRecoFlag[11];   //[nPho]
   Int_t           phoSeverity[11];   //[nPho]
   Int_t           phoPos[11];   //[nPho]
   Float_t         phoSCE[11];   //[nPho]
   Float_t         phoESE[11];   //[nPho]
   Float_t         phoSCEt[11];   //[nPho]
   Float_t         phoSCEta[11];   //[nPho]
   Float_t         phoSCPhi[11];   //[nPho]
   Float_t         phoSCEtaWidth[11];   //[nPho]
   Float_t         phoSCPhiWidth[11];   //[nPho]
   Float_t         phoVtx[11][3];   //[nPho]
   Float_t         phoVtxD0[11];   //[nPho]
   Int_t           phoOverlap[11];   //[nPho]
   Int_t           phohasPixelSeed[11];   //[nPho]
   Int_t           phoIsConv[11];   //[nPho]
   Float_t         phoESRatio[11];   //[nPho]
   Float_t         phoESProfileFront[11][123];   //[nPho]
   Float_t         phoESProfileRear[11][123];   //[nPho]
   Int_t           phoNTracks[11];   //[nPho]
   Float_t         phoConvPairInvariantMass[11];   //[nPho]
   Float_t         phoConvPairCotThetaSeparation[11];   //[nPho]
   Float_t         phoConvPairMomentumEta[11];   //[nPho]
   Float_t         phoConvPairMomentumPhi[11];   //[nPho]
   Float_t         phoConvPairMomentumX[11];   //[nPho]
   Float_t         phoConvPairMomentumY[11];   //[nPho]
   Float_t         phoConvPairMomentumZ[11];   //[nPho]
   Float_t         phoConvDistOfMinimumApproach[11];   //[nPho]
   Float_t         phoConvDPhiTracksAtVtx[11];   //[nPho]
   Float_t         phoConvDPhiTracksAtEcal[11];   //[nPho]
   Float_t         phoConvDEtaTracksAtEcal[11];   //[nPho]
   Float_t         phoConvVtxValid[11];   //[nPho]
   Float_t         phoConvVtxEta[11];   //[nPho]
   Float_t         phoConvVtxPhi[11];   //[nPho]
   Float_t         phoConvVtxR[11];   //[nPho]
   Float_t         phoConvVtxX[11];   //[nPho]
   Float_t         phoConvVtxY[11];   //[nPho]
   Float_t         phoConvVtxZ[11];   //[nPho]
   Float_t         phoConvVtxChi2[11];   //[nPho]
   Float_t         phoConvVtxNdof[11];   //[nPho]
   Float_t         phoConvChi2Prob[11];   //[nPho]
   Float_t         phoConvEoverP[11];   //[nPho]
   Int_t           phoNxtal[11];   //[nPho]
   Float_t         phoXtalTime[11][200];   //[nPho]
   Float_t         phoXtalEnergy[11][200];   //[nPho]
   Int_t           phoXtalZ[11][200];   //[nPho]
   Int_t           phoXtalX[11][200];   //[nPho]
   Int_t           phoXtalY[11][200];   //[nPho]
   Int_t           phoXtalEta[11][200];   //[nPho]
   Int_t           phoXtalPhi[11][200];   //[nPho]
   Float_t         pho5x5Time[11][25];   //[nPho]
   Float_t         pho5x5Energy[11][25];   //[nPho]
   Int_t           pho5x5Z[11][25];   //[nPho]
   Int_t           pho5x5X[11][25];   //[nPho]
   Int_t           pho5x5Y[11][25];   //[nPho]
   Int_t           pho5x5Eta[11][25];   //[nPho]
   Int_t           pho5x5Phi[11][25];   //[nPho]
   Int_t           nMu;
   Int_t           muTrg[61][16];   //[nMu]
   Float_t         muEta[61];   //[nMu]
   Float_t         muPhi[61];   //[nMu]
   Int_t           muCharge[61];   //[nMu]
   Float_t         muPt[61];   //[nMu]
   Float_t         muPz[61];   //[nMu]
   Float_t         muIsoTrk[61];   //[nMu]
   Float_t         muIsoCalo[61];   //[nMu]
   Float_t         muIsoEcal[61];   //[nMu]
   Float_t         muIsoHcal[61];   //[nMu]
   Float_t         muChi2NDF[61];   //[nMu]
   Float_t         muEmVeto[61];   //[nMu]
   Float_t         muHadVeto[61];   //[nMu]
   Int_t           muType[61];   //[nMu]
   Bool_t          muID[61][6];   //[nMu]
   Float_t         muD0[61];   //[nMu]
   Float_t         muDz[61];   //[nMu]
   Float_t         muPVD0[61];   //[nMu]
   Float_t         muPVDz[61];   //[nMu]
   Float_t         muValidFraction[61];   //[nMu]
   Float_t         muTrkdPt[61];   //[nMu]
   Int_t           muNumberOfHits[61];   //[nMu]
   Int_t           muNumberOfValidHits[61];   //[nMu]
   Int_t           muNumberOfInactiveHits[61];   //[nMu]
   Int_t           muNumberOfValidTrkHits[61];   //[nMu]
   Int_t           muNumberOfValidPixelHits[61];   //[nMu]
   Int_t           muNumberOfValidMuonHits[61];   //[nMu]
   Int_t           muStations[61];   //[nMu]
   Int_t           muChambers[61];   //[nMu]
   Float_t         muPV2D[61];   //[nMu]
   Float_t         muPV3D[61];   //[nMu]
   Float_t         muBS2D[61];   //[nMu]
   Float_t         muBS3D[61];   //[nMu]
   Float_t         muVtx[61][3];   //[nMu]
   Int_t           nJet;
   Int_t           jetTrg[31][23];   //[nJet]
   Float_t         jetEn[31];   //[nJet]
   Float_t         jetPt[31];   //[nJet]
   Float_t         jetEta[31];   //[nJet]
   Float_t         jetPhi[31];   //[nJet]
   Float_t         jetMass[31];   //[nJet]
   Float_t         jetEt[31];   //[nJet]
   Int_t           jetpartonFlavour[31];   //[nJet]
   Float_t         jetRawPt[31];   //[nJet]
   Float_t         jetRawEn[31];   //[nJet]
   Float_t         jetCharge[31];   //[nJet]
   Float_t         jetNeutralEmEnergy[31];   //[nJet]
   Float_t         jetNeutralEmEnergyFraction[31];   //[nJet]
   Float_t         jetNeutralHadronEnergy[31];   //[nJet]
   Float_t         jetNeutralHadronEnergyFraction[31];   //[nJet]
   Int_t           jetNConstituents[31];   //[nJet]
   Float_t         jetChargedEmEnergy[31];   //[nJet]
   Float_t         jetChargedEmEnergyFraction[31];   //[nJet]
   Float_t         jetChargedHadronEnergy[31];   //[nJet]
   Float_t         jetChargedHadronEnergyFraction[31];   //[nJet]
   Int_t           jetChargedHadronMultiplicity[31];   //[nJet]
   Float_t         jetChargedMuEnergy[31];   //[nJet]
   Float_t         jetChargedMuEnergyFraction[31];   //[nJet]
   Double_t        jetJVAlpha[31];   //[nJet]
   Double_t        jetJVBeta[31];   //[nJet]
   Int_t           nZee;
   Float_t         ZeeMass[36];   //[nZee]
   Float_t         ZeePt[36];   //[nZee]
   Float_t         ZeeEta[36];   //[nZee]
   Float_t         ZeePhi[36];   //[nZee]
   Int_t           ZeeLeg1Index[36];   //[nZee]
   Int_t           ZeeLeg2Index[36];   //[nZee]
   Int_t           nZmumu;
   Float_t         ZmumuMass[12];   //[nZmumu]
   Float_t         ZmumuPt[12];   //[nZmumu]
   Float_t         ZmumuEta[12];   //[nZmumu]
   Float_t         ZmumuPhi[12];   //[nZmumu]
   Int_t           ZmumuLeg1Index[12];   //[nZmumu]
   Int_t           ZmumuLeg2Index[12];   //[nZmumu]
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
   Float_t         WmunuMassTCaloMET[8];   //[nWmunu]
   Float_t         WmunuEtCaloMET[8];   //[nWmunu]
   Float_t         WmunuACopCaloMET[8];   //[nWmunu]
   Float_t         WmunuMassTTcMET[8];   //[nWmunu]
   Float_t         WmunuEtTcMET[8];   //[nWmunu]
   Float_t         WmunuACopTcMET[8];   //[nWmunu]
   Float_t         WmunuMassTPfMET[8];   //[nWmunu]
   Float_t         WmunuEtPfMET[8];   //[nWmunu]
   Float_t         WmunuACopPfMET[8];   //[nWmunu]
   Int_t           WmunuMuIndex[8];   //[nWmunu]
