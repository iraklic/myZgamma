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
   Int_t           mcPID[40];   //[nMC]
   Float_t         mcVtx[40][3];   //[nMC]
   Float_t         mcPt[40];   //[nMC]
   Float_t         mcMass[40];   //[nMC]
   Float_t         mcEta[40];   //[nMC]
   Float_t         mcPhi[40];   //[nMC]
   Int_t           mcGMomPID[40];   //[nMC]
   Int_t           mcMomPID[40];   //[nMC]
   Float_t         mcMomPt[40];   //[nMC]
   Float_t         mcMomMass[40];   //[nMC]
   Float_t         mcMomEta[40];   //[nMC]
   Float_t         mcMomPhi[40];   //[nMC]
   Int_t           mcIndex[40];   //[nMC]
   Int_t           mcDecayType[40];   //[nMC]
   Float_t         mcIsoDR03[40];   //[nMC]
   Float_t         mcCalIsoDR03[40];   //[nMC]
   Float_t         mcTrkIsoDR03[40];   //[nMC]
   Float_t         mcIsoDR04[40];   //[nMC]
   Float_t         mcCalIsoDR04[40];   //[nMC]
   Float_t         mcTrkIsoDR04[40];   //[nMC]
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
   Int_t           eleTrg[6][31];   //[nEle]
   Int_t           eleID[6][30];   //[nEle]
   Float_t         eleIDLH[6];   //[nEle]
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
   Int_t           elenBrem[6];   //[nEle]
   Float_t         eledEtaAtVtx[6];   //[nEle]
   Float_t         eledPhiAtVtx[6];   //[nEle]
   Float_t         eleSigmaEtaEta[6];   //[nEle]
   Float_t         eleSigmaIEtaIEta[6];   //[nEle]
   Float_t         eleSigmaIEtaIPhi[6];   //[nEle]
   Float_t         eleSigmaIPhiIPhi[6];   //[nEle]
   Float_t         eleE3x3[6];   //[nEle]
   Float_t         eleSeedTime[6];   //[nEle]
   Float_t         eleSeedEnergy[6];   //[nEle]
   Int_t           eleRecoFlag[6];   //[nEle]
   Int_t           eleSeverity[6];   //[nEle]
   Int_t           eleGenIndex[6];   //[nEle]
   Int_t           eleGenGMomPID[6];   //[nEle]
   Int_t           eleGenMomPID[6];   //[nEle]
   Float_t         eleGenMomPt[6];   //[nEle]
   Float_t         eleIsoTrkDR03[6];   //[nEle]
   Float_t         eleIsoEcalDR03[6];   //[nEle]
   Float_t         eleIsoHcalDR03[6];   //[nEle]
   Float_t         eleIsoHcalSolidDR03[6];   //[nEle]
   Float_t         eleIsoTrkDR04[6];   //[nEle]
   Float_t         eleIsoEcalDR04[6];   //[nEle]
   Float_t         eleIsoHcalDR04[6];   //[nEle]
   Float_t         eleIsoHcalSolidDR04[6];   //[nEle]
   Float_t         eleConvDist[6];   //[nEle]
   Float_t         eleConvDcot[6];   //[nEle]
   Float_t         eleConvRadius[6];   //[nEle]
   Int_t           eleConvFlag[6];   //[nEle]
   Int_t           eleConvMissinghit[6];   //[nEle]
   Float_t         eleESRatio[6];   //[nEle]
   Float_t         eleESProfileFront[6][123];   //[nEle]
   Float_t         eleESProfileRear[6][123];   //[nEle]
   Float_t         elePV2D[6];   //[nEle]
   Float_t         elePV3D[6];   //[nEle]
   Float_t         eleBS2D[6];   //[nEle]
   Float_t         eleBS3D[6];   //[nEle]
   Float_t         elePVD0[6];   //[nEle]
   Float_t         elePVDz[6];   //[nEle]
   Int_t           nPho;
   Int_t           phoTrg[5][14];   //[nPho]
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
   Float_t         phoHcalIsoSolidDR03[5];   //[nPho]
   Float_t         phoTrkIsoSolidDR04[5];   //[nPho]
   Float_t         phoTrkIsoHollowDR04[5];   //[nPho]
   Int_t           phoNTrkSolidDR04[5];   //[nPho]
   Int_t           phoNTrkHollowDR04[5];   //[nPho]
   Float_t         phoEcalIsoDR04[5];   //[nPho]
   Float_t         phoHcalIsoDR04[5];   //[nPho]
   Float_t         phoHcalIsoSolidDR04[5];   //[nPho]
   Float_t         phoEtVtx[5][150];   //[nPho]
   Float_t         phoEtaVtx[5][150];   //[nPho]
   Float_t         phoPhiVtx[5][150];   //[nPho]
   Float_t         phoTrkIsoSolidDR03Vtx[5][150];   //[nPho]
   Float_t         phoTrkIsoHollowDR03Vtx[5][150];   //[nPho]
   Float_t         phoTrkIsoSolidDR04Vtx[5][150];   //[nPho]
   Float_t         phoTrkIsoHollowDR04Vtx[5][150];   //[nPho]
   Float_t         phoHoverE[5];   //[nPho]
   Float_t         phoSigmaEtaEta[5];   //[nPho]
   Float_t         phoSigmaIEtaIEta[5];   //[nPho]
   Float_t         phoSigmaIEtaIPhi[5];   //[nPho]
   Float_t         phoSigmaIPhiIPhi[5];   //[nPho]
   Float_t         phoE3x3[5];   //[nPho]
   Float_t         phoE5x5[5];   //[nPho]
   Float_t         phoSeedTime[5];   //[nPho]
   Float_t         phoSeedEnergy[5];   //[nPho]
   Int_t           phoRecoFlag[5];   //[nPho]
   Int_t           phoSeverity[5];   //[nPho]
   Int_t           phoPos[5];   //[nPho]
   Int_t           phoGenIndex[5];   //[nPho]
   Int_t           phoGenGMomPID[5];   //[nPho]
   Int_t           phoGenMomPID[5];   //[nPho]
   Float_t         phoGenMomPt[5];   //[nPho]
   Float_t         phoSCE[5];   //[nPho]
   Float_t         phoESE[5];   //[nPho]
   Float_t         phoSCEt[5];   //[nPho]
   Float_t         phoSCEta[5];   //[nPho]
   Float_t         phoSCPhi[5];   //[nPho]
   Float_t         phoSCEtaWidth[5];   //[nPho]
   Float_t         phoSCPhiWidth[5];   //[nPho]
   Float_t         phoVtx[5][3];   //[nPho]
   Float_t         phoVtxD0[5];   //[nPho]
   Int_t           phoOverlap[5];   //[nPho]
   Int_t           phohasPixelSeed[5];   //[nPho]
   Int_t           phoIsConv[5];   //[nPho]
   Float_t         phoESRatio[5];   //[nPho]
   Float_t         phoESProfileFront[5][123];   //[nPho]
   Float_t         phoESProfileRear[5][123];   //[nPho]
   Int_t           phoNTracks[5];   //[nPho]
   Float_t         phoConvPairInvariantMass[5];   //[nPho]
   Float_t         phoConvPairCotThetaSeparation[5];   //[nPho]
   Float_t         phoConvPairMomentumEta[5];   //[nPho]
   Float_t         phoConvPairMomentumPhi[5];   //[nPho]
   Float_t         phoConvPairMomentumX[5];   //[nPho]
   Float_t         phoConvPairMomentumY[5];   //[nPho]
   Float_t         phoConvPairMomentumZ[5];   //[nPho]
   Float_t         phoConvDistOfMinimumApproach[5];   //[nPho]
   Float_t         phoConvDPhiTracksAtVtx[5];   //[nPho]
   Float_t         phoConvDPhiTracksAtEcal[5];   //[nPho]
   Float_t         phoConvDEtaTracksAtEcal[5];   //[nPho]
   Float_t         phoConvVtxValid[5];   //[nPho]
   Float_t         phoConvVtxEta[5];   //[nPho]
   Float_t         phoConvVtxPhi[5];   //[nPho]
   Float_t         phoConvVtxR[5];   //[nPho]
   Float_t         phoConvVtxX[5];   //[nPho]
   Float_t         phoConvVtxY[5];   //[nPho]
   Float_t         phoConvVtxZ[5];   //[nPho]
   Float_t         phoConvVtxChi2[5];   //[nPho]
   Float_t         phoConvVtxNdof[5];   //[nPho]
   Float_t         phoConvChi2Prob[5];   //[nPho]
   Float_t         phoConvEoverP[5];   //[nPho]
   Int_t           phoNxtal[5];   //[nPho]
   Float_t         phoXtalTime[5][200];   //[nPho]
   Float_t         phoXtalEnergy[5][200];   //[nPho]
   Int_t           phoXtalZ[5][200];   //[nPho]
   Int_t           phoXtalX[5][200];   //[nPho]
   Int_t           phoXtalY[5][200];   //[nPho]
   Int_t           phoXtalEta[5][200];   //[nPho]
   Int_t           phoXtalPhi[5][200];   //[nPho]
   Float_t         pho5x5Time[5][25];   //[nPho]
   Float_t         pho5x5Energy[5][25];   //[nPho]
   Int_t           pho5x5Z[5][25];   //[nPho]
   Int_t           pho5x5X[5][25];   //[nPho]
   Int_t           pho5x5Y[5][25];   //[nPho]
   Int_t           pho5x5Eta[5][25];   //[nPho]
   Int_t           pho5x5Phi[5][25];   //[nPho]
   Int_t           nMu;
   Int_t           muTrg[31][16];   //[nMu]
   Float_t         muEta[31];   //[nMu]
   Float_t         muPhi[31];   //[nMu]
   Int_t           muCharge[31];   //[nMu]
   Float_t         muPt[31];   //[nMu]
   Float_t         muPz[31];   //[nMu]
   Int_t           muGenIndex[31];   //[nMu]
   Int_t           muGenGMomPID[31];   //[nMu]
   Int_t           muGenMomPID[31];   //[nMu]
   Float_t         muGenMomPt[31];   //[nMu]
   Float_t         muIsoTrk[31];   //[nMu]
   Float_t         muIsoCalo[31];   //[nMu]
   Float_t         muIsoEcal[31];   //[nMu]
   Float_t         muIsoHcal[31];   //[nMu]
   Float_t         muChi2NDF[31];   //[nMu]
   Float_t         muEmVeto[31];   //[nMu]
   Float_t         muHadVeto[31];   //[nMu]
   Int_t           muType[31];   //[nMu]
   Bool_t          muID[31][6];   //[nMu]
   Float_t         muD0[31];   //[nMu]
   Float_t         muDz[31];   //[nMu]
   Float_t         muPVD0[31];   //[nMu]
   Float_t         muPVDz[31];   //[nMu]
   Float_t         muValidFraction[31];   //[nMu]
   Float_t         muTrkdPt[31];   //[nMu]
   Int_t           muNumberOfHits[31];   //[nMu]
   Int_t           muNumberOfValidHits[31];   //[nMu]
   Int_t           muNumberOfInactiveHits[31];   //[nMu]
   Int_t           muNumberOfValidTrkHits[31];   //[nMu]
   Int_t           muNumberOfValidPixelHits[31];   //[nMu]
   Int_t           muNumberOfValidMuonHits[31];   //[nMu]
   Int_t           muStations[31];   //[nMu]
   Int_t           muChambers[31];   //[nMu]
   Float_t         muPV2D[31];   //[nMu]
   Float_t         muPV3D[31];   //[nMu]
   Float_t         muBS2D[31];   //[nMu]
   Float_t         muBS3D[31];   //[nMu]
   Float_t         muVtx[31][3];   //[nMu]
   Int_t           nJet;
   Int_t           jetTrg[29][23];   //[nJet]
   Float_t         jetEn[29];   //[nJet]
   Float_t         jetPt[29];   //[nJet]
   Float_t         jetEta[29];   //[nJet]
   Float_t         jetPhi[29];   //[nJet]
   Float_t         jetMass[29];   //[nJet]
   Float_t         jetEt[29];   //[nJet]
   Int_t           jetpartonFlavour[29];   //[nJet]
   Float_t         jetRawPt[29];   //[nJet]
   Float_t         jetRawEn[29];   //[nJet]
   Float_t         jetCharge[29];   //[nJet]
   Float_t         jetNeutralEmEnergy[29];   //[nJet]
   Float_t         jetNeutralEmEnergyFraction[29];   //[nJet]
   Float_t         jetNeutralHadronEnergy[29];   //[nJet]
   Float_t         jetNeutralHadronEnergyFraction[29];   //[nJet]
   Int_t           jetNConstituents[29];   //[nJet]
   Float_t         jetChargedEmEnergy[29];   //[nJet]
   Float_t         jetChargedEmEnergyFraction[29];   //[nJet]
   Float_t         jetChargedHadronEnergy[29];   //[nJet]
   Float_t         jetChargedHadronEnergyFraction[29];   //[nJet]
   Int_t           jetChargedHadronMultiplicity[29];   //[nJet]
   Float_t         jetChargedMuEnergy[29];   //[nJet]
   Float_t         jetChargedMuEnergyFraction[29];   //[nJet]
   Double_t        jetJVAlpha[29];   //[nJet]
   Double_t        jetJVBeta[29];   //[nJet]
   Int_t           jetGenJetIndex[29];   //[nJet]
   Float_t         jetGenJetEn[29];   //[nJet]
   Float_t         jetGenJetPt[29];   //[nJet]
   Float_t         jetGenJetEta[29];   //[nJet]
   Float_t         jetGenJetPhi[29];   //[nJet]
   Float_t         jetGenJetMass[29];   //[nJet]
   Int_t           jetGenPartonID[29];   //[nJet]
   Int_t           jetGenPartonMomID[29];   //[nJet]
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
