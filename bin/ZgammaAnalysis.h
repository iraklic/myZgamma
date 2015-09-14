#ifndef IRAKLI_ZGAMMAANALYSIS_H
#define IRAKLI_ZGAMMAANALYSIS_H

#include "TH1.h"
#include "TH2.h"
#include "TH3.h"

int   ptHistoNBINS = 20;
float ptHistoMin   = 0;
float ptHistoMax   = 100;

//HISTOS FOR DATA DRIVEN BACKGROUND
TH1F* ZMass_bg		= new TH1F("ZMass_bg",		"", 16,			40,		120);
TH1F* ZGMass_bg		= new TH1F("ZGMass_bg",		"", 28,			60,		200);
TH1F* _cosThetaL_cm_bg	= new TH1F("_cosThetaL_cm_bg",	"cos(#theta_{l})", 10,	-1,		1);

//TH1F* GammaEt		= new TH1F("GammaEt",		"", ptHistoNBINS,	ptHistoMin,	ptHistoMax);
TH1F* Leg1Pt		= new TH1F("ZLeg1Pt",		"", ptHistoNBINS,	ptHistoMin,	ptHistoMax);
TH1F* Leg2Pt		= new TH1F("ZLeg2Pt",		"", ptHistoNBINS,	ptHistoMin,	ptHistoMax);
TH1F* dRLeg1Gamma	= new TH1F("dRLeg1Gamma",	"", 60,			0,		6);
TH1F* dRLeg2Gamma	= new TH1F("dRLeg2Gamma",	"", 60,			0,		6);
TH1F* ZMass		= new TH1F("ZMass",		"", 100,		40,		120);
TH1F* ZGpt		= new TH1F("ZGpt",		"", 100,		0,		100);
TH1F* ZGMass		= new TH1F("ZGMass",		"", 100,		60,		200);
TH2F* ZM_ZgM		= new TH2F("ZM_ZgM",		"", 100,		0,	120,	100,	0,	250);

TH1F* _GammaEt		= new TH1F("_GammaEt",		"", 100,		0,		300);
TH1F* _GammaEta		= new TH1F("_GammaEta",		"", 12,			-3,		3);
TH1F* _GammaPhi		= new TH1F("_GammaPhi",		"", 18,			-3.5,		3.5);
TH1F* _GammaHoE		= new TH1F("_GammaHoE",		"", 15,			0,		0.15);
TH1F* _GammaSigIEIE	= new TH1F("_GammaSigIEIE",	"", 35,			0,		0.07);
TH1F* _GammaEcalIso	= new TH1F("_GammaEcalIso",	"", 20,			0,		5);
TH1F* _GammaHcalIso	= new TH1F("_GammaHcalIso",	"", 20,			0,		3);
TH1F* _GammaTrkIso	= new TH1F("_GammaTrkIso",	"", 20,			0,		3);
TH1F* _Gamma_eIso	= new TH1F("_Gamma_eIso",	"", 50,			-0.5,		7);
TH1F* _Gamma_hIso	= new TH1F("_Gamma_hIso",	"", 35,			-0.5,		3);
TH1F* _Gamma_tIso	= new TH1F("_Gamma_tIso",	"", 35,			-0.5,		3);

TH1I* nPassed		= new TH1I("nPassed",		"", 50,			0,50);

//for efficiency
TH1F* _photonEt		= new TH1F("_photonEt",		"", 10,			0,		100);
TH1F* _photonEta	= new TH1F("_photonEta",	"", 12,			-3,		3);
TH1F* _photonPhi	= new TH1F("_photonPhi",	"", 18,			-3.5,		3.5);
TH1F* _photonHoE	= new TH1F("_photonHoE",	"", 15,			0,		0.15);
TH1F* _photonSigIEIE	= new TH1F("_photonSigIEIE",	"", 35,			0,		0.07);
TH1F* _photonEcalIso	= new TH1F("_photonEcalIso",	"", 20,			0,		5);
TH1F* _photonHcalIso	= new TH1F("_photonHcalIso",	"", 20,			0,		3);
TH1F* _photonTrkIso	= new TH1F("_photonTrkIso",	"", 20,			0,		3);
TH1F* _photon_eIso	= new TH1F("_photon_eIso",	"", 50,			-0.5,		7);
TH1F* _photon_hIso	= new TH1F("_photon_hIso",	"", 35,			-0.5,		3);
TH1F* _photon_tIso	= new TH1F("_photon_tIso",	"", 35,			-0.5,		3);

TH1F* _cleanLepPt	= new TH1F("_cleanLepPt",	"", 20,			0,		100);
TH1F* _goodLepPt	= new TH1F("_goodLepPt",	"", 20,			0,		100);

//HISTOGRAMS FOR ANGLES
TH1F* _thetaL		= new TH1F("_thetaL",		"cos(#theta_{l})", 10,	-1,		1);
TH1F* _thetaL_cm	= new TH1F("_thetaL_cm",		"cos(#theta_{l})", 10,	-1,		1);
TH1F* _cosThetaL	= new TH1F("_cosThetaL",	"cos(#theta_{l})", 10,	-1,		1);
TH1F* _cosThetaL_cm	= new TH1F("_cosThetaL_cm",	"cos(#theta_{l})", 20,	-1,		1);
TH1F* _cosThetaL_cm_FSR	= new TH1F("_cosThetaL_cm_FSR",	"cos(#theta_{l})", 20,	-1,		1);

//TH1F* _phi		= new TH1F("_phi",		"#phi",		 100,	-1,		1);

TH1F* _cosThetaZ	= new TH1F("_cosThetaZ",	"cos(#theta_{Z})", 20,	-1,		1);
TH1F* _cosThetaZ_cm	= new TH1F("_cosThetaZ_cm",	"cos(#theta_{Z})", 20,	-1,		1);
TH1F* _thetaZ		= new TH1F("_thetaZ",		"cos(#theta_{Z})", 20,	-1,		1);
TH1F* _thetaZ_cm	= new TH1F("_thetaZ_cm",	"cos(#theta_{Z})", 20,	-1,		1);

TH2F* _cosThetaZ_L	= new TH2F("cosThetaZ_L",	"cos(#theta_{Z}) vs. cos(#theta_{l})", 10, -1, 1, 10, -1, 1);
TH2F* _cosThetaL_res	= new TH2F("cosThetaL_res",	"cos(#theta_{l}) GEN vs. RECO", 100, -1, 1, 100, -1, 1);
TH1F* _cosThetaL_res1	= new TH1F("cosThetaL_res1",	"cos(#theta_{l})((RECO-GEN)/GEN)", 100, -5, 5);
TH2F* _cosThetaZ_res	= new TH2F("cosThetaZ_res",	"cos(#theta_{Z}) GEN vs. RECO", 100, -1, 1, 100, -1, 1);
TH1F* _cosThetaZ_res1	= new TH1F("cosThetaZ_res1",	"cos(#theta_{Z})((RECO-GEN)/GEN)", 100, -5, 5);
TH3F* _cosThetaZ_L_phi	= new TH3F("cosThetaZ_L_phi",	"cos(#theta_{Z}) vs. cos(#theta_{l}) vs. #phi", 10, -1, 1, 10, -1, 1, 10, -4, 4);

TH2F* _phiL_res		= new TH2F("phiL_res",	"#phi_{l}) GEN vs. RECO", 100, -3.14, 3.14, 100, -3.14, 3.14);
TH1F* _phiL_res1	= new TH1F("phiL_res1",	"#phi_{l})((RECO-GEN)/GEN)", 100, -5, 5);
TH2F* _phiZ_res		= new TH2F("phiZ_res",	"#phi_{Z}) GEN vs. RECO", 100, -3.14, 3.14, 100, -3.14, 3.14);
TH1F* _phiZ_res1	= new TH1F("phi_res1",	"#phi_{Z})((RECO-GEN)/GEN)", 100, -5, 5);
TH1F* _phiL		= new TH1F("_phiL",		"", 20,			-4,		4);
TH1F* _phiZ		= new TH1F("_phiZ",		"", 20,			-4,		4);

TH1F* _phi		= new TH1F("phi",		"", 20,			-1.6,		1.6);
TH1F* _phi_cm		= new TH1F("phi_cm",		"", 20,			-4,		4);

//HISTOGRAMS FOR GEN PARTICLES
TH1F* MC_thetaL		= new TH1F("MC_thetaL",		"cos(#theta_{l})", 20,	-1,		1);
TH1F* MC_thetaL_cm	= new TH1F("MC_thetaL_cm",	"cos(#theta_{l})", 20,	-1,		1);
TH1F* MC_cosThetaL	= new TH1F("MC_cosThetaL",	"cos(#theta_{l})", 20,	-1,		1);
TH1F* MC_cosThetaL_cm	= new TH1F("MC_cosThetaL_cm",	"cos(#theta_{l})", 20,	-1,		1);
TH1F* MC_cosThetaL_cm_FSR	= new TH1F("MC_cosThetaL_cm_FSR",	"cos(#theta_{l})", 10,	-1,		1);

TH1F* MC_cosThetaZ	= new TH1F("MC_cosThetaZ",	"cos(#theta_{Z})", 20,	-1,		1);
TH1F* MC_cosThetaZ_cm	= new TH1F("MC_cosThetaZ_cm",	"cos(#theta_{Z})", 20,	-1,		1);
TH1F* MC_thetaZ		= new TH1F("MC_thetaZ",		"cos(#theta_{Z})", 20,	-1,		1);
TH1F* MC_thetaZ_cm	= new TH1F("MC_thetaZ_cm",	"cos(#theta_{Z})", 20,	-1,		1);

TH2F* MC_cosThetaZ_L	= new TH2F("MC_cosThetaZ_L",	"cos(#theta_{Z}) vs. cos(#theta_{l})", 20, -1, 1, 20, -1, 1);
TH3F* MC_cosThetaZ_L_phi= new TH3F("MC_cosThetaZ_L_phi",	"cos(#theta_{Z}) vs. cos(#theta_{l}) vs. #phi", 30, -1, 1, 30, -1, 1, 30, -7, 7);

TH1F* MC_goodLepEta	= new TH1F("MC_goodLepEta",	"", 100,		-4,		4);
TH1F* MC_goodPhoEta	= new TH1F("MC_goodPhoEta",	"", 100,		-4,		4);

//TH1F* MC_phi		= new TH1F("MC_phi",		"", 20,			-7,		7);
TH1F* MC_phiL		= new TH1F("MC_phiL",		"", 20,			-4,		4);
TH1F* MC_phiZ		= new TH1F("MC_phiZ",		"", 20,			-4,		4);

TH1F* MC_phi		= new TH1F("MC_phi",		"", 20,			-1.6,		1.6);
TH1F* MC_phi_cm		= new TH1F("MC_phi_cm",		"", 20,			-4,		4);

//GOOD PARTICLE KINEMATICS
TH1F* _goodLepEta	= new TH1F("_goodLepEta",	"", 100,		-4,		4);
TH1F* _goodPhoEta	= new TH1F("_goodPhoEta",	"", 100,		-4,		4);

TH2F * cosThetaZ_phoEta = new TH2F("cosThetaZ_phoEta",	"", 10,		-1,	1,	10,	-1,	1);

#endif
