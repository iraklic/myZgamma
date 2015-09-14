   Int_t           run;
   Long64_t        event;
   Int_t           orbit;
   Int_t           bx;
   Int_t           lumis;
   Bool_t          isData;
   Int_t           ttbit0;
   Int_t           nHLT;
   Int_t           HLT[395];   //[nHLT]
   Int_t           HLTIndex[125];
   Int_t           HLTprescale[395];   //[nHLT]
   Int_t           nHFTowersP;
   Int_t           nHFTowersN;
   Int_t           nVtx;
   Float_t         vtx[47][3];   //[nVtx]
   Int_t           vtxNTrk[47];   //[nVtx]
   Float_t         vtxNDF[47];   //[nVtx]
   Float_t         vtxD0[47];   //[nVtx]
   Int_t           nGoodVtx;
   Int_t           IsVtxGood;
   Int_t           nTrk;
   Int_t           nGoodTrk;
   Int_t           IsTracksGood;
   Float_t         rho;
   Float_t         sigma;
   Float_t         rhoNeutral;
   Float_t         pdf[7];
   Float_t         pthat;
   Float_t         processID;
   Int_t           nBX;
   Int_t           nPU[3];   //[nBX]
   Int_t           BXPU[3];   //[nBX]
   Int_t           nMC;
   Int_t           mcPID[37];   //[nMC]
   Float_t         mcVtx[37][3];   //[nMC]
   Float_t         mcPt[37];   //[nMC]
   Float_t         mcMass[37];   //[nMC]
   Float_t         mcEta[37];   //[nMC]
   Float_t         mcPhi[37];   //[nMC]
   Int_t           mcGMomPID[37];   //[nMC]
   Int_t           mcMomPID[37];   //[nMC]
   Float_t         mcMomPt[37];   //[nMC]
   Float_t         mcMomMass[37];   //[nMC]
   Float_t         mcMomEta[37];   //[nMC]
   Float_t         mcMomPhi[37];   //[nMC]
   Int_t           mcIndex[37];   //[nMC]
   Int_t           mcDecayType[37];   //[nMC]
   Float_t         mcIsoDR03[37];   //[nMC]
   Float_t         mcCalIsoDR03[37];   //[nMC]
   Float_t         mcTrkIsoDR03[37];   //[nMC]
   Float_t         mcIsoDR04[37];   //[nMC]
   Float_t         mcCalIsoDR04[37];   //[nMC]
   Float_t         mcTrkIsoDR04[37];   //[nMC]
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
   Float_t         SmearedpfMET;
   Float_t         SmearedpfMETx;
   Float_t         SmearedpfMETy;
   Float_t         SmearedpfMETPhi;
   Float_t         SmearedpfMETsumEt;
   Float_t         SmearedpfMETmEtSig;
   Float_t         SmearedpfMETSig;
   Float_t         SmearedTypeIpfMET;
   Float_t         SmearedTypeIpfMETx;
   Float_t         SmearedTypeIpfMETy;
   Float_t         SmearedTypeIpfMETPhi;
   Float_t         SmearedTypeIpfMETsumEt;
   Float_t         SmearedTypeIpfMETmEtSig;
   Float_t         SmearedTypeIpfMETSig;
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
   Int_t           eleTrg[5][31];   //[nEle]
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
   Float_t         eleE3x3[5];   //[nEle]
   Float_t         eleSeedTime[5];   //[nEle]
   Float_t         eleSeedEnergy[5];   //[nEle]
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
   Float_t         elePVD0[5];   //[nEle]
   Float_t         elePVDz[5];   //[nEle]
   Int_t           nPho;
   Int_t           phoTrg[6][14];   //[nPho]
   Bool_t          phoIsPhoton[6];   //[nPho]
   Float_t         phoE[6];   //[nPho]
   Float_t         phoEt[6];   //[nPho]
   Float_t         phoPz[6];   //[nPho]
   Float_t         phoEta[6];   //[nPho]
   Float_t         phoPhi[6];   //[nPho]
   Float_t         phoR9[6];   //[nPho]
   Float_t         phoTrkIsoSolidDR03[6];   //[nPho]
   Float_t         phoTrkIsoHollowDR03[6];   //[nPho]
   Int_t           phoNTrkSolidDR03[6];   //[nPho]
   Int_t           phoNTrkHollowDR03[6];   //[nPho]
   Float_t         phoEcalIsoDR03[6];   //[nPho]
   Float_t         phoHcalIsoDR03[6];   //[nPho]
   Float_t         phoHcalIsoSolidDR03[6];   //[nPho]
   Float_t         phoTrkIsoSolidDR04[6];   //[nPho]
   Float_t         phoTrkIsoHollowDR04[6];   //[nPho]
   Int_t           phoNTrkSolidDR04[6];   //[nPho]
   Int_t           phoNTrkHollowDR04[6];   //[nPho]
   Float_t         phoEcalIsoDR04[6];   //[nPho]
   Float_t         phoHcalIsoDR04[6];   //[nPho]
   Float_t         phoHcalIsoSolidDR04[6];   //[nPho]
   Float_t         phoEtVtx[6][150];   //[nPho]
   Float_t         phoEtaVtx[6][150];   //[nPho]
   Float_t         phoPhiVtx[6][150];   //[nPho]
   Float_t         phoTrkIsoSolidDR03Vtx[6][150];   //[nPho]
   Float_t         phoTrkIsoHollowDR03Vtx[6][150];   //[nPho]
   Float_t         phoTrkIsoSolidDR04Vtx[6][150];   //[nPho]
   Float_t         phoTrkIsoHollowDR04Vtx[6][150];   //[nPho]
   Float_t         phoHoverE[6];   //[nPho]
   Float_t         phoSigmaEtaEta[6];   //[nPho]
   Float_t         phoSigmaIEtaIEta[6];   //[nPho]
   Float_t         phoSigmaIEtaIPhi[6];   //[nPho]
   Float_t         phoSigmaIPhiIPhi[6];   //[nPho]
   Float_t         phoE3x3[6];   //[nPho]
   Float_t         phoE5x5[6];   //[nPho]
   Float_t         phoSeedTime[6];   //[nPho]
   Float_t         phoSeedEnergy[6];   //[nPho]
   Int_t           phoRecoFlag[6];   //[nPho]
   Int_t           phoSeverity[6];   //[nPho]
   Int_t           phoPos[6];   //[nPho]
   Int_t           phoGenIndex[6];   //[nPho]
   Int_t           phoGenGMomPID[6];   //[nPho]
   Int_t           phoGenMomPID[6];   //[nPho]
   Float_t         phoGenMomPt[6];   //[nPho]
   Float_t         phoSCE[6];   //[nPho]
   Float_t         phoESE[6];   //[nPho]
   Float_t         phoSCEt[6];   //[nPho]
   Float_t         phoSCEta[6];   //[nPho]
   Float_t         phoSCPhi[6];   //[nPho]
   Float_t         phoSCEtaWidth[6];   //[nPho]
   Float_t         phoSCPhiWidth[6];   //[nPho]
   Float_t         phoVtx[6][3];   //[nPho]
   Float_t         phoVtxD0[6];   //[nPho]
   Int_t           phoOverlap[6];   //[nPho]
   Int_t           phohasPixelSeed[6];   //[nPho]
   Int_t           phoIsConv[6];   //[nPho]
   Float_t         phoESRatio[6];   //[nPho]
   Float_t         phoESProfileFront[6][123];   //[nPho]
   Float_t         phoESProfileRear[6][123];   //[nPho]
   Int_t           phoNTracks[6];   //[nPho]
   Float_t         phoConvPairInvariantMass[6];   //[nPho]
   Float_t         phoConvPairCotThetaSeparation[6];   //[nPho]
   Float_t         phoConvPairMomentumEta[6];   //[nPho]
   Float_t         phoConvPairMomentumPhi[6];   //[nPho]
   Float_t         phoConvPairMomentumX[6];   //[nPho]
   Float_t         phoConvPairMomentumY[6];   //[nPho]
   Float_t         phoConvPairMomentumZ[6];   //[nPho]
   Float_t         phoConvDistOfMinimumApproach[6];   //[nPho]
   Float_t         phoConvDPhiTracksAtVtx[6];   //[nPho]
   Float_t         phoConvDPhiTracksAtEcal[6];   //[nPho]
   Float_t         phoConvDEtaTracksAtEcal[6];   //[nPho]
   Float_t         phoConvVtxValid[6];   //[nPho]
   Float_t         phoConvVtxEta[6];   //[nPho]
   Float_t         phoConvVtxPhi[6];   //[nPho]
   Float_t         phoConvVtxR[6];   //[nPho]
   Float_t         phoConvVtxX[6];   //[nPho]
   Float_t         phoConvVtxY[6];   //[nPho]
   Float_t         phoConvVtxZ[6];   //[nPho]
   Float_t         phoConvVtxChi2[6];   //[nPho]
   Float_t         phoConvVtxNdof[6];   //[nPho]
   Float_t         phoConvChi2Prob[6];   //[nPho]
   Float_t         phoConvEoverP[6];   //[nPho]
   Int_t           phoNxtal[6];   //[nPho]
   Float_t         phoXtalTime[6][200];   //[nPho]
   Float_t         phoXtalEnergy[6][200];   //[nPho]
   Int_t           phoXtalZ[6][200];   //[nPho]
   Int_t           phoXtalX[6][200];   //[nPho]
   Int_t           phoXtalY[6][200];   //[nPho]
   Int_t           phoXtalEta[6][200];   //[nPho]
   Int_t           phoXtalPhi[6][200];   //[nPho]
   Float_t         pho5x5Time[6][25];   //[nPho]
   Float_t         pho5x5Energy[6][25];   //[nPho]
   Int_t           pho5x5Z[6][25];   //[nPho]
   Int_t           pho5x5X[6][25];   //[nPho]
   Int_t           pho5x5Y[6][25];   //[nPho]
   Int_t           pho5x5Eta[6][25];   //[nPho]
   Int_t           pho5x5Phi[6][25];   //[nPho]
   Int_t           nMu;
   Int_t           muTrg[27][16];   //[nMu]
   Float_t         muEta[27];   //[nMu]
   Float_t         muPhi[27];   //[nMu]
   Int_t           muCharge[27];   //[nMu]
   Float_t         muPt[27];   //[nMu]
   Float_t         muPz[27];   //[nMu]
   Int_t           muGenIndex[27];   //[nMu]
   Int_t           muGenGMomPID[27];   //[nMu]
   Int_t           muGenMomPID[27];   //[nMu]
   Float_t         muGenMomPt[27];   //[nMu]
   Float_t         muIsoTrk[27];   //[nMu]
   Float_t         muIsoCalo[27];   //[nMu]
   Float_t         muIsoEcal[27];   //[nMu]
   Float_t         muIsoHcal[27];   //[nMu]
   Float_t         muChi2NDF[27];   //[nMu]
   Float_t         muEmVeto[27];   //[nMu]
   Float_t         muHadVeto[27];   //[nMu]
   Int_t           muType[27];   //[nMu]
   Bool_t          muID[27][6];   //[nMu]
   Float_t         muD0[27];   //[nMu]
   Float_t         muDz[27];   //[nMu]
   Float_t         muPVD0[27];   //[nMu]
   Float_t         muPVDz[27];   //[nMu]
   Float_t         muValidFraction[27];   //[nMu]
   Float_t         muTrkdPt[27];   //[nMu]
   Int_t           muNumberOfHits[27];   //[nMu]
   Int_t           muNumberOfValidHits[27];   //[nMu]
   Int_t           muNumberOfInactiveHits[27];   //[nMu]
   Int_t           muNumberOfValidTrkHits[27];   //[nMu]
   Int_t           muNumberOfValidPixelHits[27];   //[nMu]
   Int_t           muNumberOfValidMuonHits[27];   //[nMu]
   Int_t           muStations[27];   //[nMu]
   Int_t           muChambers[27];   //[nMu]
   Float_t         muPV2D[27];   //[nMu]
   Float_t         muPV3D[27];   //[nMu]
   Float_t         muBS2D[27];   //[nMu]
   Float_t         muBS3D[27];   //[nMu]
   Float_t         muVtx[27][3];   //[nMu]
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
   Int_t           jetGenJetIndex[31];   //[nJet]
   Float_t         jetGenJetEn[31];   //[nJet]
   Float_t         jetGenJetPt[31];   //[nJet]
   Float_t         jetGenJetEta[31];   //[nJet]
   Float_t         jetGenJetPhi[31];   //[nJet]
   Float_t         jetGenJetMass[31];   //[nJet]
   Int_t           jetGenPartonID[31];   //[nJet]
   Int_t           jetGenPartonMomID[31];   //[nJet]
   Int_t           nZee;
   Float_t         ZeeMass[10];   //[nZee]
   Float_t         ZeePt[10];   //[nZee]
   Float_t         ZeeEta[10];   //[nZee]
   Float_t         ZeePhi[10];   //[nZee]
   Int_t           ZeeLeg1Index[10];   //[nZee]
   Int_t           ZeeLeg2Index[10];   //[nZee]
   Int_t           nZmumu;
   Float_t         ZmumuMass[6];   //[nZmumu]
   Float_t         ZmumuPt[6];   //[nZmumu]
   Float_t         ZmumuEta[6];   //[nZmumu]
   Float_t         ZmumuPhi[6];   //[nZmumu]
   Int_t           ZmumuLeg1Index[6];   //[nZmumu]
   Int_t           ZmumuLeg2Index[6];   //[nZmumu]
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
