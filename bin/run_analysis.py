import os, commands

# get the CMSSW BASE
base_path = commands.getoutput("echo $CMSSW_BASE")
curD      = commands.getoutput("pwd")

# this is the list of files to run on

mcFiles=[]

# MC SM Samples
#======================================================================
# test sample
#mcFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/NTUPLE_TEST_skim.root")
#mcFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/NTUPLE_TEST_ee_skim.root")
#mcFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/NTUPLE_TEST_ee.root")

# BAUR
#mcFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/BAUR_SM/ZeeGamma_Baur.root")
#mcFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/BAUR_SM/ZmumuGamma_baur.root")
#mcFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/BAUR_SM/TGC/ZmumuGamma_Baur_LO_7TeV_zzg_h3_0.12_h4_0.004_vgtree.root");

# MADGRAPH
#mcFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/MADGRAPH_MC_SAMPLES/ZgammaEle_1Jet_42x_Madgraph_TuneZ2.root")
#mcFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/MADGRAPH_MC_SAMPLES/ZgammaMu_1Jet_42x_Madgraph_TuneZ2.root")
#mcFiles.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/FALL10/ZGToEEG_TuneD6T_Madgraph.root")
#mcFiles.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/MC/ZGTo2MuG_7TeV-madgraph_Spring10-START3X_V26-v1_GEN-SIM-RECO.root")

# PYTHIA
#mcFiles.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/FALL10/ZGtoLLG_TuneZ2.root")

# SHERPA
#mcFiles.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/aTGC_WithUE/job_Zgamma_1j_ZZg_h3_0_h4_0.root")

#======================================================================
## # SIGNAL MC

#BAUR SM_ee Samples
#mcFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/SKIMS/BAUR/SM_ee/NTUPLE_BAUR_SM_ee.root")
#mcFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/SKIMS/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_P.root")
#mcFiles.append("/eos/uscms/store/user/iraklich/SKIMS/BAUR/SM_ee/NTUPLE_BAUR_SM_ee.root")

#BAUR NSM_ee Samples
#mcFiles.append("rfio:/eos/uscms/store/user/iraklich/SKIMS/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee.root") #SOMETHING IS WRONG WITH THIS ONE
#mcFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/SKIMS/BAUR/NSM_ee/PYTHIA_ISR_FSR_OFF/NTUPLE_BAUR_NSM_ee_PYTHIA_F_ISR_OFF.root")
#mcFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/SKIMS/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee.root")


#BAUR SM_mm Sample
mcFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/SKIMS/BAUR/SM_mm/NTUPLE_BAUR_SM_mm.root")
#mcFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/SKIMS/BAUR/SM_mm/PYTHIA_ISR_FSR_OFF/NTUPLE_BAUR_SM_mm.root")

#BAUR NSM_mm Sample
#ramcFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/SKIMS/BAUR/NSM_mm/PYTHIA_ISR_FSR_OFF/NTUPLE_BAUR_NSM_mm.root")
#mcFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/SKIMS/BAUR/NSM_mm/NTUPLE_BAUR_NSM_mm.root")

#-------------------------------------------------------------------------

#MG5 LO SAMPLES (ISR ONLY) FOR ACCEPTANCE CALCULATIONS
#mcFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/SKIMS/MG5/SM_mm/PYTHIA_ISR_FSR_OFF/NTUPLE_MG5_SM_mm_ISR_ONLY.root")
#mcFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/SKIMS/MG5/SM_ee/ISR/NTUPLE_MG5_SM_ee_ISR_P.root")
#mcFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/SKIMS/MG5/SM_mm/NTUPLE_MG5_SM_mm_ISR_ONLY.root")

#MG5 (LO) SAMPLES
#mcFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/SKIMS/MG5/SM_ee/LO/NTUPLE_MG5_SM_ee_LO.root")
#mcFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/SKIMS/MG5/SM_ee/LO/NTUPLE_MG5_SM_ee_LO_P.root")

#mcFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/SKIMS/MG5/SM_mm/PYTHIA_ISR_FSR_OFF/LO/NTUPLE_MG5_SM_mm_LO_P.root")
#mcFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/SKIMS/MG5/SM_mm/NTUPLE_MG_SM_mm_LO.root")

#MG5 SAMPLES LO + up to 2 jets (NLO) - MY SAMPLES PYTHIA ISR/FSR OFF
#mcFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/SKIMS/MG5/SM_mm_2jet/NTUPLE_MG5_SM_mm_2jets.root")
#mcFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/SKIMS/MG5/SM_ee_2jet/NTUPLE_MG5_SM_ee_2jets_P.root")
#mcFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/SKIMS/MG5/SM_mm/NTUPLE_MG_SM_mm_NLO.root")
#mcFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/SKIMS/MG5/SM_ee/NLO/NTUPLE_MG_SM_ee_NLO.root")

#MG5 SAMPLES LO + up to 2 jets
#mcFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/MADGRAPH_MC_SAMPLES/ZGammaToMuMuGamma_2Jet_MG5_TuneZ2_skim.root")
#mcFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/MADGRAPH_MC_SAMPLES/ZGammaToEEGamma_2Jet_MG5_TuneZ2_skim.root")

#MG4 SAMPLES
#mcFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/MADGRAPH_MC_SAMPLES/ZgammaMu_1Jet_Madgraph_Fall11_skim.root")
#mcFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/MADGRAPH_MC_SAMPLES/ZgammaEle_1Jet_Madgraph_Fall11_skim.root")

#======================================================================
#BACKGROUND
# with right HLT
#mcFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/MADGRAPH_MC_SAMPLES/DYJets_Madgraph_Fall11_skim.root")
# no photon
#mcFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/NOPHO_DATA/DYJetsToLL_TuneZ2_M50_Madgraph_Fall11_skim.root")

#LATEST BESTEST BACKGROUND SAMPLE
#mcFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/SKIMS/BG/DYJetsToLL_TuneZ2_M50_Madgraph_Fall11_skim.root")

#======================================================================


# photon IDs:
# 0 - egamma isLoose (probably old???)
# 1 - poter's scaling WP95
# 2 - poter's scaling WP90
# 3 - poter's scaling WP85
# 4 - poter's scaling WP80
# 5 - poter's scaling WP75
# 6 - poter's scaling WP65
# 7 - QCD photon group
# 8 - exotica group
# 9 - monophoton analysis using old e/g isTight
# 10- e/g isEM
# 11- e/g isLoose
# 12- e/g isTight

# electron IDs:
# 0 - simpleEleId60cIso
# 1 - simpleEleId70cIso
# 2 - simpleEleId80cIso
# 3 - simpleEleId85cIso
# 4 - simpleEleId90cIso
# 5 - simpleEleId95cIso
# 6 - simpleEleId60relIso
# 7 - simpleEleId70relIso
# 8 - simpleEleId80relIso
# 9 - simpleEleId85relIso
# 10 - simpleEleId90relIso
# 11 - simpleEleId95relIso
# eID for 38X is different then in 36X...

doEEG = True
doMMG = True

phoID = 12
# ===========================================
os.chdir(curD)
for file in mcFiles:
    file1 = file.split("/")[-1]

    if "ZgammaEle" in file1:
        print " ----------- COPIED Ele_MDG_MC -----------"
        os.system("pwd")
        os.system("cp VarLists/ZgammaEle_1Jet_Madgraph_Fall11.h VarList.h")
	removeMcPhotonsFromZjets = 0
	matchMC = 0
    elif "ZgammaMu_1Jet" in file1:
        print " ----------- COPIED Mu_MDG_MC ------------"
        os.system("cp VarLists/ZgammaMu_1Jet_Madgraph_Fall11.h VarList.h")
	removeMcPhotonsFromZjets = 0
	matchMC = 0
    elif "ZGammaToMuMu" in file1:
        print " ----------- COPIED Mu_MG5_MC ------------"
        os.system("cp VarLists/ZgammaMu_MG5.h VarList.h")
	removeMcPhotonsFromZjets = 0
	matchMC = 0
    elif "ZGammaToEE" in file1:
        print " ----------- COPIED Mu_MG5_MC ------------"
        os.system("cp VarLists/ZgammaMu_MG5.h VarList.h")
	removeMcPhotonsFromZjets = 0
	matchMC = 0

    elif "ZmumuGamma" in file1:
        print " ----------- COPIED Mu_MDG_MC ------------"
        os.system("cp VarLists/Mu_BAUR.h VarList.h")
	removeMcPhotonsFromZjets = 0
	matchMC = 0

    elif "NTUPLE_TEST" in file1:
        print " ----------- COPIED MG5 ISR ------------"
        os.system("cp VarLists/MG5_ISR.h VarList.h")
	removeMcPhotonsFromZjets = 0
	matchMC = 0

    elif "NTUPLE_MG5_SM_ee_ISR" in file1:
        print " ----------- COPIED MG5 ISR ------------"
        os.system("cp VarLists/MG5_ISR.h VarList.h")
	removeMcPhotonsFromZjets = 0
	matchMC = 0

    elif "NTUPLE_MG5_SM_mm_ISR" in file1:
        print " ----------- COPIED MG5_mm_ISR ------------"
        os.system("cp VarLists/MG5_mm_ISR.h VarList.h")
	removeMcPhotonsFromZjets = 0
	matchMC = 0

    elif "NTUPLE_MG5_SM_mm_2jets" in file1:
        print " ----------- COPIED MY MG5_mm_2jet ------------"
        os.system("cp VarLists/MG5_my2jets.h VarList.h")
	removeMcPhotonsFromZjets = 0
	matchMC = 0

    elif "_NLO" in file1:
        print " ----------- COPIED MY NLO  ------------"
        os.system("cp VarLists/MG5_2jets.h VarList.h")
	removeMcPhotonsFromZjets = 0
	matchMC = 0

    elif "_LO" in file1:
        print " ----------- COPIED MY MG5_mm_2jet ------------"
        os.system("cp VarLists/MG5_my2jets.h VarList.h")
	removeMcPhotonsFromZjets = 0
	matchMC = 0

    elif "NTUPLE_MG5_SM_ee_491443" in file1:
        print " ----------- COPIED MG5 ISR ------------"
        os.system("cp VarLists/MG5.h VarList.h")
	removeMcPhotonsFromZjets = 0
	matchMC = 0

    elif "NTUPLE_BAUR_SM" in file1:
        print " ----------- COPIED BAUR ------------"
        os.system("cp VarLists/BAUR.h VarList.h")
	removeMcPhotonsFromZjets = 0
	matchMC = 0

    elif "NTUPLE_BAUR_NSM" in file1:
        print " ----------- COPIED BAUR ------------"
        os.system("cp VarLists/BAUR_NSM.h VarList.h")
	removeMcPhotonsFromZjets = 0
	matchMC = 0

    elif "NTUPLE_MG5_SM_ee_2jets" in file1:
        print " ----------- COPIED MG5 2Jets ------------"
        os.system("cp VarLists/MG5_2jets.h VarList.h")
	removeMcPhotonsFromZjets = 0
	matchMC = 0


    elif "DYJets" in file1:
        print " ----------- COPIED DYJets ------------"
        os.system("cp VarLists/DYJetsToLL_TuneZ2_M50_Madgraph_Fall11.h VarList.h")
	removeMcPhotonsFromZjets = 1
	matchMC = 1

    run = 1 # 1 for Run2011A and 2 for Run2011B scale factors
    noPhoton = 0 # 1 for noPhoton requirement and 0 if u want to require photon

    os.chdir("%s/src/ElectroWeakAnalysis/MultiBosons/bin/"%base_path)
    print "PREPARING .h for mc"
    #if "146428" in file1:

#    os.system("cp VarLists/Mu_MDG_MC.h VarList.h")
    os.system("python parseCode.py --isMC=1")
    os.chdir("%s/src/"%base_path)
    os.system("scram b")

    # eeg
    if doEEG:
        eleID = 11
        muID  = -1
        file2 = "histos_ee_phoID_%s_eleID_%s_%s"%(phoID,eleID,file1)
        out  = "%s.txt"%file2[:-5]
#    removeMcPhotonsFromZjets = 0
#    if "ZJet" in file1: removeMcPhotonsFromZjets = 1
        com = "ZgammaAnalysis.exe inputFiles=%s outputfile=%s photonID=%s electronID=%s matchMC=%s removeMcPhoJ=%s Run=%s noPhoton=%s"%(file,file2, phoID, eleID, matchMC, removeMcPhotonsFromZjets, run, noPhoton)
        print com
    if doEEG:
        os.system(com)
        os.system("mv %s/src/%s %s/src/ElectroWeakAnalysis/MultiBosons/bin/output/"%(base_path,file2,base_path))
            
    #mmg
    if doMMG:
        eleID = -1
        muID  = 2
        file2 = "histos_mm_phoID_%s_muID_%s_%s"%(phoID,muID,file1)
        out   = "%s.txt"%file2[:-5]
        com = "ZgammaAnalysis.exe inputFiles=%s outputfile=%s photonID=%s muonID=%s matchMC=%s removeMcPhoJ=%s Run=%s noPhoton=%s"%(file,file2, phoID, muID, matchMC, removeMcPhotonsFromZjets, run, noPhoton)
        print com
    if doMMG:
        os.system(com)
        os.system("mv %s/src/%s %s/src/ElectroWeakAnalysis/MultiBosons/bin/output/"%(base_path,file2,base_path))
    
# go back to /bin
os.chdir("%s/src/ElectroWeakAnalysis/MultiBosons/bin/"%base_path)

print "==========================="
print "DONE PROCESSING ALL SAMPLES"
print "==========================="
