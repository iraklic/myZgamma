   Int_t           run;
   Long64_t        event;
   Int_t           orbit;
   Int_t           bx;
   Int_t           lumis;
   Bool_t          isData;
   Int_t           ttbit0;
   Int_t           nHLT;
   Int_t           HLT[389];   //[nHLT]
   Int_t           HLTIndex[125];
   Int_t           HLTprescale[389];   //[nHLT]
   Int_t           nHFTowersP;
   Int_t           nHFTowersN;
   Int_t           nVtx;
   Float_t         vtx[30][3];   //[nVtx]
   Int_t           vtxNTrk[30];   //[nVtx]
   Float_t         vtxNDF[30];   //[nVtx]
   Float_t         vtxD0[30];   //[nVtx]
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
   Int_t           eleTrg[8][31];   //[nEle]
   Int_t           eleID[8][30];   //[nEle]
   Float_t         eleIDLH[8];   //[nEle]
   Int_t           eleClass[8];   //[nEle]
   Int_t           eleCharge[8];   //[nEle]
   Float_t         eleEn[8];   //[nEle]
   Float_t         eleSCRawEn[8];   //[nEle]
   Float_t         eleESEn[8];   //[nEle]
   Float_t         eleSCEn[8];   //[nEle]
   Float_t         elePt[8];   //[nEle]
   Float_t         elePz[8];   //[nEle]
   Float_t         eleEta[8];   //[nEle]
   Float_t         elePhi[8];   //[nEle]
   Float_t         eleSCEta[8];   //[nEle]
   Float_t         eleSCPhi[8];   //[nEle]
   Float_t         eleSCEtaWidth[8];   //[nEle]
   Float_t         eleSCPhiWidth[8];   //[nEle]
   Float_t         eleVtx[8][3];   //[nEle]
   Float_t         eleCaloPos[8][3];   //[nEle]
   Float_t         eleSCPos[8][3];   //[nEle]
   Float_t         eleHoverE[8];   //[nEle]
   Float_t         eleEoverP[8];   //[nEle]
   Float_t         elePin[8];   //[nEle]
   Float_t         elePout[8];   //[nEle]
   Float_t         eleBrem[8];   //[nEle]
   Int_t           elenBrem[8];   //[nEle]
   Float_t         eledEtaAtVtx[8];   //[nEle]
   Float_t         eledPhiAtVtx[8];   //[nEle]
   Float_t         eleSigmaEtaEta[8];   //[nEle]
   Float_t         eleSigmaIEtaIEta[8];   //[nEle]
   Float_t         eleSigmaIEtaIPhi[8];   //[nEle]
   Float_t         eleSigmaIPhiIPhi[8];   //[nEle]
   Float_t         eleE3x3[8];   //[nEle]
   Float_t         eleSeedTime[8];   //[nEle]
   Float_t         eleSeedEnergy[8];   //[nEle]
   Int_t           eleRecoFlag[8];   //[nEle]
   Int_t           eleSeverity[8];   //[nEle]
   Float_t         eleIsoTrkDR03[8];   //[nEle]
   Float_t         eleIsoEcalDR03[8];   //[nEle]
   Float_t         eleIsoHcalDR03[8];   //[nEle]
   Float_t         eleIsoHcalSolidDR03[8];   //[nEle]
   Float_t         eleIsoTrkDR04[8];   //[nEle]
   Float_t         eleIsoEcalDR04[8];   //[nEle]
   Float_t         eleIsoHcalDR04[8];   //[nEle]
   Float_t         eleIsoHcalSolidDR04[8];   //[nEle]
   Float_t         eleConvDist[8];   //[nEle]
   Float_t         eleConvDcot[8];   //[nEle]
   Float_t         eleConvRadius[8];   //[nEle]
   Int_t           eleConvFlag[8];   //[nEle]
   Int_t           eleConvMissinghit[8];   //[nEle]
   Float_t         eleESRatio[8];   //[nEle]
   Float_t         eleESProfileFront[8][123];   //[nEle]
   Float_t         eleESProfileRear[8][123];   //[nEle]
   Float_t         elePV2D[8];   //[nEle]
   Float_t         elePV3D[8];   //[nEle]
   Float_t         eleBS2D[8];   //[nEle]
   Float_t         eleBS3D[8];   //[nEle]
   Float_t         elePVD0[8];   //[nEle]
   Float_t         elePVDz[8];   //[nEle]
   Int_t           nPho;
   Int_t           phoTrg[12][14];   //[nPho]
   Bool_t          phoIsPhoton[12];   //[nPho]
   Float_t         phoE[12];   //[nPho]
   Float_t         phoEt[12];   //[nPho]
   Float_t         phoPz[12];   //[nPho]
   Float_t         phoEta[12];   //[nPho]
   Float_t         phoPhi[12];   //[nPho]
   Float_t         phoR9[12];   //[nPho]
   Float_t         phoTrkIsoSolidDR03[12];   //[nPho]
   Float_t         phoTrkIsoHollowDR03[12];   //[nPho]
   Int_t           phoNTrkSolidDR03[12];   //[nPho]
   Int_t           phoNTrkHollowDR03[12];   //[nPho]
   Float_t         phoEcalIsoDR03[12];   //[nPho]
   Float_t         phoHcalIsoDR03[12];   //[nPho]
   Float_t         phoHcalIsoSolidDR03[12];   //[nPho]
   Float_t         phoTrkIsoSolidDR04[12];   //[nPho]
   Float_t         phoTrkIsoHollowDR04[12];   //[nPho]
   Int_t           phoNTrkSolidDR04[12];   //[nPho]
   Int_t           phoNTrkHollowDR04[12];   //[nPho]
   Float_t         phoEcalIsoDR04[12];   //[nPho]
   Float_t         phoHcalIsoDR04[12];   //[nPho]
   Float_t         phoHcalIsoSolidDR04[12];   //[nPho]
   Float_t         phoEtVtx[12][150];   //[nPho]
   Float_t         phoEtaVtx[12][150];   //[nPho]
   Float_t         phoPhiVtx[12][150];   //[nPho]
   Float_t         phoTrkIsoSolidDR03Vtx[12][150];   //[nPho]
   Float_t         phoTrkIsoHollowDR03Vtx[12][150];   //[nPho]
   Float_t         phoTrkIsoSolidDR04Vtx[12][150];   //[nPho]
   Float_t         phoTrkIsoHollowDR04Vtx[12][150];   //[nPho]
   Float_t         phoHoverE[12];   //[nPho]
   Float_t         phoSigmaEtaEta[12];   //[nPho]
   Float_t         phoSigmaIEtaIEta[12];   //[nPho]
   Float_t         phoSigmaIEtaIPhi[12];   //[nPho]
   Float_t         phoSigmaIPhiIPhi[12];   //[nPho]
   Float_t         phoE3x3[12];   //[nPho]
   Float_t         phoE5x5[12];   //[nPho]
   Float_t         phoSeedTime[12];   //[nPho]
   Float_t         phoSeedEnergy[12];   //[nPho]
   Int_t           phoRecoFlag[12];   //[nPho]
   Int_t           phoSeverity[12];   //[nPho]
   Int_t           phoPos[12];   //[nPho]
   Float_t         phoSCE[12];   //[nPho]
   Float_t         phoESE[12];   //[nPho]
   Float_t         phoSCEt[12];   //[nPho]
   Float_t         phoSCEta[12];   //[nPho]
   Float_t         phoSCPhi[12];   //[nPho]
   Float_t         phoSCEtaWidth[12];   //[nPho]
   Float_t         phoSCPhiWidth[12];   //[nPho]
   Float_t         phoVtx[12][3];   //[nPho]
   Float_t         phoVtxD0[12];   //[nPho]
   Int_t           phoOverlap[12];   //[nPho]
   Int_t           phohasPixelSeed[12];   //[nPho]
   Int_t           phoIsConv[12];   //[nPho]
   Float_t         phoESRatio[12];   //[nPho]
   Float_t         phoESProfileFront[12][123];   //[nPho]
   Float_t         phoESProfileRear[12][123];   //[nPho]
   Int_t           phoNTracks[12];   //[nPho]
   Float_t         phoConvPairInvariantMass[12];   //[nPho]
   Float_t         phoConvPairCotThetaSeparation[12];   //[nPho]
   Float_t         phoConvPairMomentumEta[12];   //[nPho]
   Float_t         phoConvPairMomentumPhi[12];   //[nPho]
   Float_t         phoConvPairMomentumX[12];   //[nPho]
   Float_t         phoConvPairMomentumY[12];   //[nPho]
   Float_t         phoConvPairMomentumZ[12];   //[nPho]
   Float_t         phoConvDistOfMinimumApproach[12];   //[nPho]
   Float_t         phoConvDPhiTracksAtVtx[12];   //[nPho]
   Float_t         phoConvDPhiTracksAtEcal[12];   //[nPho]
   Float_t         phoConvDEtaTracksAtEcal[12];   //[nPho]
   Float_t         phoConvVtxValid[12];   //[nPho]
   Float_t         phoConvVtxEta[12];   //[nPho]
   Float_t         phoConvVtxPhi[12];   //[nPho]
   Float_t         phoConvVtxR[12];   //[nPho]
   Float_t         phoConvVtxX[12];   //[nPho]
   Float_t         phoConvVtxY[12];   //[nPho]
   Float_t         phoConvVtxZ[12];   //[nPho]
   Float_t         phoConvVtxChi2[12];   //[nPho]
   Float_t         phoConvVtxNdof[12];   //[nPho]
   Float_t         phoConvChi2Prob[12];   //[nPho]
   Float_t         phoConvEoverP[12];   //[nPho]
   Int_t           phoNxtal[12];   //[nPho]
   Float_t         phoXtalTime[12][200];   //[nPho]
   Float_t         phoXtalEnergy[12][200];   //[nPho]
   Int_t           phoXtalZ[12][200];   //[nPho]
   Int_t           phoXtalX[12][200];   //[nPho]
   Int_t           phoXtalY[12][200];   //[nPho]
   Int_t           phoXtalEta[12][200];   //[nPho]
   Int_t           phoXtalPhi[12][200];   //[nPho]
   Float_t         pho5x5Time[12][25];   //[nPho]
   Float_t         pho5x5Energy[12][25];   //[nPho]
   Int_t           pho5x5Z[12][25];   //[nPho]
   Int_t           pho5x5X[12][25];   //[nPho]
   Int_t           pho5x5Y[12][25];   //[nPho]
   Int_t           pho5x5Eta[12][25];   //[nPho]
   Int_t           pho5x5Phi[12][25];   //[nPho]
   Int_t           nMu;
   Int_t           muTrg[45][16];   //[nMu]
   Float_t         muEta[45];   //[nMu]
   Float_t         muPhi[45];   //[nMu]
   Int_t           muCharge[45];   //[nMu]
   Float_t         muPt[45];   //[nMu]
   Float_t         muPz[45];   //[nMu]
   Float_t         muIsoTrk[45];   //[nMu]
   Float_t         muIsoCalo[45];   //[nMu]
   Float_t         muIsoEcal[45];   //[nMu]
   Float_t         muIsoHcal[45];   //[nMu]
   Float_t         muChi2NDF[45];   //[nMu]
   Float_t         muEmVeto[45];   //[nMu]
   Float_t         muHadVeto[45];   //[nMu]
   Int_t           muType[45];   //[nMu]
   Bool_t          muID[45][6];   //[nMu]
   Float_t         muD0[45];   //[nMu]
   Float_t         muDz[45];   //[nMu]
   Float_t         muPVD0[45];   //[nMu]
   Float_t         muPVDz[45];   //[nMu]
   Float_t         muValidFraction[45];   //[nMu]
   Float_t         muTrkdPt[45];   //[nMu]
   Int_t           muNumberOfHits[45];   //[nMu]
   Int_t           muNumberOfValidHits[45];   //[nMu]
   Int_t           muNumberOfInactiveHits[45];   //[nMu]
   Int_t           muNumberOfValidTrkHits[45];   //[nMu]
   Int_t           muNumberOfValidPixelHits[45];   //[nMu]
   Int_t           muNumberOfValidMuonHits[45];   //[nMu]
   Int_t           muStations[45];   //[nMu]
   Int_t           muChambers[45];   //[nMu]
   Float_t         muPV2D[45];   //[nMu]
   Float_t         muPV3D[45];   //[nMu]
   Float_t         muBS2D[45];   //[nMu]
   Float_t         muBS3D[45];   //[nMu]
   Float_t         muVtx[45][3];   //[nMu]
   Int_t           nJet;
   Int_t           jetTrg[15][23];   //[nJet]
   Float_t         jetEn[15];   //[nJet]
   Float_t         jetPt[15];   //[nJet]
   Float_t         jetEta[15];   //[nJet]
   Float_t         jetPhi[15];   //[nJet]
   Float_t         jetMass[15];   //[nJet]
   Float_t         jetEt[15];   //[nJet]
   Int_t           jetpartonFlavour[15];   //[nJet]
   Float_t         jetRawPt[15];   //[nJet]
   Float_t         jetRawEn[15];   //[nJet]
   Float_t         jetCharge[15];   //[nJet]
   Float_t         jetNeutralEmEnergy[15];   //[nJet]
   Float_t         jetNeutralEmEnergyFraction[15];   //[nJet]
   Float_t         jetNeutralHadronEnergy[15];   //[nJet]
   Float_t         jetNeutralHadronEnergyFraction[15];   //[nJet]
   Int_t           jetNConstituents[15];   //[nJet]
   Float_t         jetChargedEmEnergy[15];   //[nJet]
   Float_t         jetChargedEmEnergyFraction[15];   //[nJet]
   Float_t         jetChargedHadronEnergy[15];   //[nJet]
   Float_t         jetChargedHadronEnergyFraction[15];   //[nJet]
   Int_t           jetChargedHadronMultiplicity[15];   //[nJet]
   Float_t         jetChargedMuEnergy[15];   //[nJet]
   Float_t         jetChargedMuEnergyFraction[15];   //[nJet]
   Double_t        jetJVAlpha[15];   //[nJet]
   Double_t        jetJVBeta[15];   //[nJet]
   Int_t           nZee;
   Float_t         ZeeMass[28];   //[nZee]
   Float_t         ZeePt[28];   //[nZee]
   Float_t         ZeeEta[28];   //[nZee]
   Float_t         ZeePhi[28];   //[nZee]
   Int_t           ZeeLeg1Index[28];   //[nZee]
   Int_t           ZeeLeg2Index[28];   //[nZee]
   Int_t           nZmumu;
   Float_t         ZmumuMass[4];   //[nZmumu]
   Float_t         ZmumuPt[4];   //[nZmumu]
   Float_t         ZmumuEta[4];   //[nZmumu]
   Float_t         ZmumuPhi[4];   //[nZmumu]
   Int_t           ZmumuLeg1Index[4];   //[nZmumu]
   Int_t           ZmumuLeg2Index[4];   //[nZmumu]
   Int_t           nWenu;
   Float_t         WenuMassTCaloMET[8];   //[nWenu]
   Float_t         WenuEtCaloMET[8];   //[nWenu]
   Float_t         WenuACopCaloMET[8];   //[nWenu]
   Float_t         WenuMassTTcMET[8];   //[nWenu]
   Float_t         WenuEtTcMET[8];   //[nWenu]
   Float_t         WenuACopTcMET[8];   //[nWenu]
   Float_t         WenuMassTPfMET[8];   //[nWenu]
   Float_t         WenuEtPfMET[8];   //[nWenu]
   Float_t         WenuACopPfMET[8];   //[nWenu]
   Int_t           WenuEleIndex[8];   //[nWenu]
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
