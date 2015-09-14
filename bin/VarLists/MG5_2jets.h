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
   Float_t         vtx[46][3];   //[nVtx]
   Int_t           vtxNTrk[46];   //[nVtx]
   Float_t         vtxNDF[46];   //[nVtx]
   Float_t         vtxD0[46];   //[nVtx]
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
   Int_t           mcPID[38];   //[nMC]
   Float_t         mcVtx[38][3];   //[nMC]
   Float_t         mcPt[38];   //[nMC]
   Float_t         mcMass[38];   //[nMC]
   Float_t         mcEta[38];   //[nMC]
   Float_t         mcPhi[38];   //[nMC]
   Int_t           mcGMomPID[38];   //[nMC]
   Int_t           mcMomPID[38];   //[nMC]
   Float_t         mcMomPt[38];   //[nMC]
   Float_t         mcMomMass[38];   //[nMC]
   Float_t         mcMomEta[38];   //[nMC]
   Float_t         mcMomPhi[38];   //[nMC]
   Int_t           mcIndex[38];   //[nMC]
   Int_t           mcDecayType[38];   //[nMC]
   Float_t         mcIsoDR03[38];   //[nMC]
   Float_t         mcCalIsoDR03[38];   //[nMC]
   Float_t         mcTrkIsoDR03[38];   //[nMC]
   Float_t         mcIsoDR04[38];   //[nMC]
   Float_t         mcCalIsoDR04[38];   //[nMC]
   Float_t         mcTrkIsoDR04[38];   //[nMC]
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
   Int_t           eleTrg[7][31];   //[nEle]
   Int_t           eleID[7][30];   //[nEle]
   Float_t         eleIDLH[7];   //[nEle]
   Int_t           eleClass[7];   //[nEle]
   Int_t           eleCharge[7];   //[nEle]
   Float_t         eleEn[7];   //[nEle]
   Float_t         eleSCRawEn[7];   //[nEle]
   Float_t         eleESEn[7];   //[nEle]
   Float_t         eleSCEn[7];   //[nEle]
   Float_t         elePt[7];   //[nEle]
   Float_t         elePz[7];   //[nEle]
   Float_t         eleEta[7];   //[nEle]
   Float_t         elePhi[7];   //[nEle]
   Float_t         eleSCEta[7];   //[nEle]
   Float_t         eleSCPhi[7];   //[nEle]
   Float_t         eleSCEtaWidth[7];   //[nEle]
   Float_t         eleSCPhiWidth[7];   //[nEle]
   Float_t         eleVtx[7][3];   //[nEle]
   Float_t         eleCaloPos[7][3];   //[nEle]
   Float_t         eleSCPos[7][3];   //[nEle]
   Float_t         eleHoverE[7];   //[nEle]
   Float_t         eleEoverP[7];   //[nEle]
   Float_t         elePin[7];   //[nEle]
   Float_t         elePout[7];   //[nEle]
   Float_t         eleBrem[7];   //[nEle]
   Int_t           elenBrem[7];   //[nEle]
   Float_t         eledEtaAtVtx[7];   //[nEle]
   Float_t         eledPhiAtVtx[7];   //[nEle]
   Float_t         eleSigmaEtaEta[7];   //[nEle]
   Float_t         eleSigmaIEtaIEta[7];   //[nEle]
   Float_t         eleSigmaIEtaIPhi[7];   //[nEle]
   Float_t         eleSigmaIPhiIPhi[7];   //[nEle]
   Float_t         eleE3x3[7];   //[nEle]
   Float_t         eleSeedTime[7];   //[nEle]
   Float_t         eleSeedEnergy[7];   //[nEle]
   Int_t           eleRecoFlag[7];   //[nEle]
   Int_t           eleSeverity[7];   //[nEle]
   Int_t           eleGenIndex[7];   //[nEle]
   Int_t           eleGenGMomPID[7];   //[nEle]
   Int_t           eleGenMomPID[7];   //[nEle]
   Float_t         eleGenMomPt[7];   //[nEle]
   Float_t         eleIsoTrkDR03[7];   //[nEle]
   Float_t         eleIsoEcalDR03[7];   //[nEle]
   Float_t         eleIsoHcalDR03[7];   //[nEle]
   Float_t         eleIsoHcalSolidDR03[7];   //[nEle]
   Float_t         eleIsoTrkDR04[7];   //[nEle]
   Float_t         eleIsoEcalDR04[7];   //[nEle]
   Float_t         eleIsoHcalDR04[7];   //[nEle]
   Float_t         eleIsoHcalSolidDR04[7];   //[nEle]
   Float_t         eleConvDist[7];   //[nEle]
   Float_t         eleConvDcot[7];   //[nEle]
   Float_t         eleConvRadius[7];   //[nEle]
   Int_t           eleConvFlag[7];   //[nEle]
   Int_t           eleConvMissinghit[7];   //[nEle]
   Float_t         eleESRatio[7];   //[nEle]
   Float_t         eleESProfileFront[7][123];   //[nEle]
   Float_t         eleESProfileRear[7][123];   //[nEle]
   Float_t         elePV2D[7];   //[nEle]
   Float_t         elePV3D[7];   //[nEle]
   Float_t         eleBS2D[7];   //[nEle]
   Float_t         eleBS3D[7];   //[nEle]
   Float_t         elePVD0[7];   //[nEle]
   Float_t         elePVDz[7];   //[nEle]
   Int_t           nPho;
   Int_t           phoTrg[9][14];   //[nPho]
   Bool_t          phoIsPhoton[9];   //[nPho]
   Float_t         phoE[9];   //[nPho]
   Float_t         phoEt[9];   //[nPho]
   Float_t         phoPz[9];   //[nPho]
   Float_t         phoEta[9];   //[nPho]
   Float_t         phoPhi[9];   //[nPho]
   Float_t         phoR9[9];   //[nPho]
   Float_t         phoTrkIsoSolidDR03[9];   //[nPho]
   Float_t         phoTrkIsoHollowDR03[9];   //[nPho]
   Int_t           phoNTrkSolidDR03[9];   //[nPho]
   Int_t           phoNTrkHollowDR03[9];   //[nPho]
   Float_t         phoEcalIsoDR03[9];   //[nPho]
   Float_t         phoHcalIsoDR03[9];   //[nPho]
   Float_t         phoHcalIsoSolidDR03[9];   //[nPho]
   Float_t         phoTrkIsoSolidDR04[9];   //[nPho]
   Float_t         phoTrkIsoHollowDR04[9];   //[nPho]
   Int_t           phoNTrkSolidDR04[9];   //[nPho]
   Int_t           phoNTrkHollowDR04[9];   //[nPho]
   Float_t         phoEcalIsoDR04[9];   //[nPho]
   Float_t         phoHcalIsoDR04[9];   //[nPho]
   Float_t         phoHcalIsoSolidDR04[9];   //[nPho]
   Float_t         phoEtVtx[9][150];   //[nPho]
   Float_t         phoEtaVtx[9][150];   //[nPho]
   Float_t         phoPhiVtx[9][150];   //[nPho]
   Float_t         phoTrkIsoSolidDR03Vtx[9][150];   //[nPho]
   Float_t         phoTrkIsoHollowDR03Vtx[9][150];   //[nPho]
   Float_t         phoTrkIsoSolidDR04Vtx[9][150];   //[nPho]
   Float_t         phoTrkIsoHollowDR04Vtx[9][150];   //[nPho]
   Float_t         phoHoverE[9];   //[nPho]
   Float_t         phoSigmaEtaEta[9];   //[nPho]
   Float_t         phoSigmaIEtaIEta[9];   //[nPho]
   Float_t         phoSigmaIEtaIPhi[9];   //[nPho]
   Float_t         phoSigmaIPhiIPhi[9];   //[nPho]
   Float_t         phoE3x3[9];   //[nPho]
   Float_t         phoE5x5[9];   //[nPho]
   Float_t         phoSeedTime[9];   //[nPho]
   Float_t         phoSeedEnergy[9];   //[nPho]
   Int_t           phoRecoFlag[9];   //[nPho]
   Int_t           phoSeverity[9];   //[nPho]
   Int_t           phoPos[9];   //[nPho]
   Int_t           phoGenIndex[9];   //[nPho]
   Int_t           phoGenGMomPID[9];   //[nPho]
   Int_t           phoGenMomPID[9];   //[nPho]
   Float_t         phoGenMomPt[9];   //[nPho]
   Float_t         phoSCE[9];   //[nPho]
   Float_t         phoESE[9];   //[nPho]
   Float_t         phoSCEt[9];   //[nPho]
   Float_t         phoSCEta[9];   //[nPho]
   Float_t         phoSCPhi[9];   //[nPho]
   Float_t         phoSCEtaWidth[9];   //[nPho]
   Float_t         phoSCPhiWidth[9];   //[nPho]
   Float_t         phoVtx[9][3];   //[nPho]
   Float_t         phoVtxD0[9];   //[nPho]
   Int_t           phoOverlap[9];   //[nPho]
   Int_t           phohasPixelSeed[9];   //[nPho]
   Int_t           phoIsConv[9];   //[nPho]
   Float_t         phoESRatio[9];   //[nPho]
   Float_t         phoESProfileFront[9][123];   //[nPho]
   Float_t         phoESProfileRear[9][123];   //[nPho]
   Int_t           phoNTracks[9];   //[nPho]
   Float_t         phoConvPairInvariantMass[9];   //[nPho]
   Float_t         phoConvPairCotThetaSeparation[9];   //[nPho]
   Float_t         phoConvPairMomentumEta[9];   //[nPho]
   Float_t         phoConvPairMomentumPhi[9];   //[nPho]
   Float_t         phoConvPairMomentumX[9];   //[nPho]
   Float_t         phoConvPairMomentumY[9];   //[nPho]
   Float_t         phoConvPairMomentumZ[9];   //[nPho]
   Float_t         phoConvDistOfMinimumApproach[9];   //[nPho]
   Float_t         phoConvDPhiTracksAtVtx[9];   //[nPho]
   Float_t         phoConvDPhiTracksAtEcal[9];   //[nPho]
   Float_t         phoConvDEtaTracksAtEcal[9];   //[nPho]
   Float_t         phoConvVtxValid[9];   //[nPho]
   Float_t         phoConvVtxEta[9];   //[nPho]
   Float_t         phoConvVtxPhi[9];   //[nPho]
   Float_t         phoConvVtxR[9];   //[nPho]
   Float_t         phoConvVtxX[9];   //[nPho]
   Float_t         phoConvVtxY[9];   //[nPho]
   Float_t         phoConvVtxZ[9];   //[nPho]
   Float_t         phoConvVtxChi2[9];   //[nPho]
   Float_t         phoConvVtxNdof[9];   //[nPho]
   Float_t         phoConvChi2Prob[9];   //[nPho]
   Float_t         phoConvEoverP[9];   //[nPho]
   Int_t           phoNxtal[9];   //[nPho]
   Float_t         phoXtalTime[9][200];   //[nPho]
   Float_t         phoXtalEnergy[9][200];   //[nPho]
   Int_t           phoXtalZ[9][200];   //[nPho]
   Int_t           phoXtalX[9][200];   //[nPho]
   Int_t           phoXtalY[9][200];   //[nPho]
   Int_t           phoXtalEta[9][200];   //[nPho]
   Int_t           phoXtalPhi[9][200];   //[nPho]
   Float_t         pho5x5Time[9][25];   //[nPho]
   Float_t         pho5x5Energy[9][25];   //[nPho]
   Int_t           pho5x5Z[9][25];   //[nPho]
   Int_t           pho5x5X[9][25];   //[nPho]
   Int_t           pho5x5Y[9][25];   //[nPho]
   Int_t           pho5x5Eta[9][25];   //[nPho]
   Int_t           pho5x5Phi[9][25];   //[nPho]
   Int_t           nMu;
   Int_t           muTrg[22][16];   //[nMu]
   Float_t         muEta[22];   //[nMu]
   Float_t         muPhi[22];   //[nMu]
   Int_t           muCharge[22];   //[nMu]
   Float_t         muPt[22];   //[nMu]
   Float_t         muPz[22];   //[nMu]
   Int_t           muGenIndex[22];   //[nMu]
   Int_t           muGenGMomPID[22];   //[nMu]
   Int_t           muGenMomPID[22];   //[nMu]
   Float_t         muGenMomPt[22];   //[nMu]
   Float_t         muIsoTrk[22];   //[nMu]
   Float_t         muIsoCalo[22];   //[nMu]
   Float_t         muIsoEcal[22];   //[nMu]
   Float_t         muIsoHcal[22];   //[nMu]
   Float_t         muChi2NDF[22];   //[nMu]
   Float_t         muEmVeto[22];   //[nMu]
   Float_t         muHadVeto[22];   //[nMu]
   Int_t           muType[22];   //[nMu]
   Bool_t          muID[22][6];   //[nMu]
   Float_t         muD0[22];   //[nMu]
   Float_t         muDz[22];   //[nMu]
   Float_t         muPVD0[22];   //[nMu]
   Float_t         muPVDz[22];   //[nMu]
   Float_t         muValidFraction[22];   //[nMu]
   Float_t         muTrkdPt[22];   //[nMu]
   Int_t           muNumberOfHits[22];   //[nMu]
   Int_t           muNumberOfValidHits[22];   //[nMu]
   Int_t           muNumberOfInactiveHits[22];   //[nMu]
   Int_t           muNumberOfValidTrkHits[22];   //[nMu]
   Int_t           muNumberOfValidPixelHits[22];   //[nMu]
   Int_t           muNumberOfValidMuonHits[22];   //[nMu]
   Int_t           muStations[22];   //[nMu]
   Int_t           muChambers[22];   //[nMu]
   Float_t         muPV2D[22];   //[nMu]
   Float_t         muPV3D[22];   //[nMu]
   Float_t         muBS2D[22];   //[nMu]
   Float_t         muBS3D[22];   //[nMu]
   Float_t         muVtx[22][3];   //[nMu]
   Int_t           nJet;
   Int_t           jetTrg[28][23];   //[nJet]
   Float_t         jetEn[28];   //[nJet]
   Float_t         jetPt[28];   //[nJet]
   Float_t         jetEta[28];   //[nJet]
   Float_t         jetPhi[28];   //[nJet]
   Float_t         jetMass[28];   //[nJet]
   Float_t         jetEt[28];   //[nJet]
   Int_t           jetpartonFlavour[28];   //[nJet]
   Float_t         jetRawPt[28];   //[nJet]
   Float_t         jetRawEn[28];   //[nJet]
   Float_t         jetCharge[28];   //[nJet]
   Float_t         jetNeutralEmEnergy[28];   //[nJet]
   Float_t         jetNeutralEmEnergyFraction[28];   //[nJet]
   Float_t         jetNeutralHadronEnergy[28];   //[nJet]
   Float_t         jetNeutralHadronEnergyFraction[28];   //[nJet]
   Int_t           jetNConstituents[28];   //[nJet]
   Float_t         jetChargedEmEnergy[28];   //[nJet]
   Float_t         jetChargedEmEnergyFraction[28];   //[nJet]
   Float_t         jetChargedHadronEnergy[28];   //[nJet]
   Float_t         jetChargedHadronEnergyFraction[28];   //[nJet]
   Int_t           jetChargedHadronMultiplicity[28];   //[nJet]
   Float_t         jetChargedMuEnergy[28];   //[nJet]
   Float_t         jetChargedMuEnergyFraction[28];   //[nJet]
   Double_t        jetJVAlpha[28];   //[nJet]
   Double_t        jetJVBeta[28];   //[nJet]
   Int_t           jetGenJetIndex[28];   //[nJet]
   Float_t         jetGenJetEn[28];   //[nJet]
   Float_t         jetGenJetPt[28];   //[nJet]
   Float_t         jetGenJetEta[28];   //[nJet]
   Float_t         jetGenJetPhi[28];   //[nJet]
   Float_t         jetGenJetMass[28];   //[nJet]
   Int_t           jetGenPartonID[28];   //[nJet]
   Int_t           jetGenPartonMomID[28];   //[nJet]
   Int_t           nZee;
   Float_t         ZeeMass[21];   //[nZee]
   Float_t         ZeePt[21];   //[nZee]
   Float_t         ZeeEta[21];   //[nZee]
   Float_t         ZeePhi[21];   //[nZee]
   Int_t           ZeeLeg1Index[21];   //[nZee]
   Int_t           ZeeLeg2Index[21];   //[nZee]
   Int_t           nZmumu;
   Float_t         ZmumuMass[4];   //[nZmumu]
   Float_t         ZmumuPt[4];   //[nZmumu]
   Float_t         ZmumuEta[4];   //[nZmumu]
   Float_t         ZmumuPhi[4];   //[nZmumu]
   Int_t           ZmumuLeg1Index[4];   //[nZmumu]
   Int_t           ZmumuLeg2Index[4];   //[nZmumu]
   Int_t           nWenu;
   Float_t         WenuMassTCaloMET[7];   //[nWenu]
   Float_t         WenuEtCaloMET[7];   //[nWenu]
   Float_t         WenuACopCaloMET[7];   //[nWenu]
   Float_t         WenuMassTTcMET[7];   //[nWenu]
   Float_t         WenuEtTcMET[7];   //[nWenu]
   Float_t         WenuACopTcMET[7];   //[nWenu]
   Float_t         WenuMassTPfMET[7];   //[nWenu]
   Float_t         WenuEtPfMET[7];   //[nWenu]
   Float_t         WenuACopPfMET[7];   //[nWenu]
   Int_t           WenuEleIndex[7];   //[nWenu]
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
