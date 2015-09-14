import os, commands

# get the CMSSW BASE
base_path = commands.getoutput("echo $CMSSW_BASE")
curD      = commands.getoutput("pwd")

# this is the list of files to run on

mcFiles=[]
dataFiles=[]
dataFiles384=[]

##### SKIMS FROM 2011A and 2011B data #####
### ELECTRONS ###
dataFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/DATA_SKIM/03/DoubleElectron_Run2011B_PromptReco_v1_run175860_178078_skim.root")
dataFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/DATA_SKIM/03/DoubleElectron_Run2011B_PromptReco_v1_run178098_178677_skim.root")
dataFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/DATA_SKIM/03/DoubleElectron_Run2011B_PromptReco_v1_run178703_179431_skim.root")
dataFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/DATA_SKIM/03/DoubleElectron_Run2011B-PromptReco-v1_run179434_180252_skim.root")
dataFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/DATA_SKIM/03/DoubleElectron_Run2011A_03Oct2011_v1_skim.root")
dataFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/DATA_SKIM/03/DoubleElectron_Run2011A_05Aug2011_v1_excTrg_addCSC_skim.root")
dataFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/DATA_SKIM/03/DoubleElectron_Run2011A_May10ReReco_v1_skim.root")
dataFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/DATA_SKIM/03/DoubleElectron_Run2011A_PromptReco_v4_skim.root")


#NO PHOTON SKIMS
#dataFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/NOPHO_DATA/DoubleElectron_Run2011A_03Oct2011_v1_skim.root")
#dataFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/NOPHO_DATA/DoubleElectron_Run2011A_05Aug2011_v1_excTrg_addCSC_skim.root")
#dataFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/NOPHO_DATA/DoubleElectron_Run2011A_May10ReReco_v1_skim.root")
#dataFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/NOPHO_DATA/DoubleElectron_Run2011A_PromptReco_v4_skim.root")

#dataFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/NOPHO_DATA/DoubleMu_Run2011A_03Oct2011_v1_skim.root")
#dataFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/NOPHO_DATA/DoubleMu_Run2011A_05Aug2011_v1_skim.root")
#dataFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/NOPHO_DATA/DoubleMu_Run2011A_May10ReReco_v1_skim.root")
#dataFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/NOPHO_DATA/DoubleMu_Run2011A_PromptReco_v4_skim.root")
#dataFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/NOPHO_DATA/DoubleMu_Run2011B_PromptReco_v1_run175860_178078_skim.root")
#dataFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/NOPHO_DATA/DoubleMu_Run2011B_PromptReco_v1_run178098_178677_skim.root")
#dataFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/NOPHO_DATA/DoubleMu_Run2011B_PromptReco_v1_run178703_179431_skim.root")
#dataFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/NOPHO_DATA/DoubleMu_Run2011B_PromptReco_v1_run179434_180252_skim.root")




### MUONS ###
#dataFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/DATA_SKIM/03/DoubleMu_Run2011A_03Oct2011_v1_skim.root")
#dataFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/DATA_SKIM/03/DoubleMu_Run2011A_05Aug2011_v1_skim.root")
#dataFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/DATA_SKIM/03/DoubleMu_Run2011A_May10ReReco_v1_skim.root")
#dataFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/DATA_SKIM/03/DoubleMu_Run2011A_PromptReco_v4_skim.root")
#dataFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/DATA_SKIM/03/DoubleMu_Run2011B_PromptReco_v1_run175860_178078_skim.root")
#dataFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/DATA_SKIM/03/DoubleMu_Run2011B_PromptReco_v1_run178098_178677_skim.root")
#dataFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/DATA_SKIM/03/DoubleMu_Run2011B_PromptReco_v1_run178703_179431_skim.root")
#dataFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/DATA_SKIM/03/DoubleMu_Run2011B_PromptReco_v1_run179434_180252_skim.root")


# OLD -----------------------
#dataFiles.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/Data_CMSSW423_vgamma_42x_v5_NewRho/SingleElectron_Run2011A_May10ReRecov1.root")
#dataFiles.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/Data_CMSSW423_vgamma_42x_v5_NewRho/DoubleElectron_Run2011A_May10ReRecov1.root")
#dataFiles.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/Data_CMSSW423_vgamma_42x_v5_NewRho/SingleMu_Run2011A_May10ReRecov1.root")
#dataFiles.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/Data_CMSSW423_vgamma_42x_v5_NewRho/DoubleMu_Run2011A_May10ReRecov1.root")
#dataFiles.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/Data_CMSSW423_vgamma_42x_v5_NewRho/SingleElectron_Run2011A_PromptRecov4_Run165088to166861.root")
#dataFiles.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/Data_CMSSW423_vgamma_42x_v5_NewRho/DoubleElectron_Run2011A_PromptRecov4_Run165088to166861.root")
#dataFiles.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/Data_CMSSW423_vgamma_42x_v5_NewRho/SingleMu_Run2011A_PromptRecov4_Run165088to166861.root")
# with right HLT
#dataFiles.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/Data_CMSSW423_vgamma_42x_v5_NewRho/DoubleMu_Run2011A_PromptRecov4_Run165088to166861.root")

# =============================================================================================
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

for file in dataFiles:
    file1 = file.split("/")[-1]

    os.chdir(curD)
#    os.system("cp VarLists/hope.h VarList.h")
    os.system("rm VarList.h")
#    if "DoubleMu_Run2011A_PromptReco_v4_skim" in file1:
#	os.system("cp VarLists/DoubleMu_Run2011A_PromptReco_v4.h VarList.h")

    if "DoubleElectron_Run2011B_PromptReco_v1_run175860_178078" in file1:
        print " : : : : cp VarLists/DoubleElectron_Run2011B_PromptReco_v1_run175860_178078.h VarList.h"
        os.system("cp VarLists/DoubleElectron_Run2011B_PromptReco_v1_run175860_178078.h VarList.h")
    elif "DoubleElectron_Run2011B_PromptReco_v1_run178098_178677" in file1:
        print " : : : : cp VarLists/DoubleElectron_Run2011B_PromptReco_v1_run178098_178677.h VarList.h"
        os.system("cp VarLists/DoubleElectron_Run2011B_PromptReco_v1_run178098_178677.h VarList.h")
    elif "DoubleElectron_Run2011B_PromptReco_v1_run178703_179431" in file1:
        print " : : : : cp VarLists/DoubleElectron_Run2011B_PromptReco_v1_run178703_179431.h VarList.h"
        os.system("cp VarLists/DoubleElectron_Run2011B_PromptReco_v1_run178703_179431.h VarList.h")
    elif "DoubleElectron_Run2011A_03Oct2011_v1" in file1:
        print " : : : : cp VarLists/DoubleElectron_Run2011A_03Oct2011_v1.h VarList.h"
        os.system("cp VarLists/DoubleElectron_Run2011A_03Oct2011_v1.h VarList.h")
    elif "DoubleElectron_Run2011A_05Aug2011_v1_excTrg_addCSC" in file1:
        print " : : : : cp VarLists/DoubleElectron_Run2011A_05Aug2011_v1_excTrg_addCSC.h VarList.h"
        os.system("cp VarLists/DoubleElectron_Run2011A_05Aug2011_v1_excTrg_addCSC.h VarList.h")
    elif "DoubleElectron_Run2011A_May10ReReco_v1" in file1:
        print " : : : : cp VarLists/DoubleElectron_Run2011A_May10ReReco_v1.h VarList.h"
        os.system("cp VarLists/DoubleElectron_Run2011A_May10ReReco_v1.h VarList.h")
    elif "DoubleElectron_Run2011A_PromptReco_v4" in file1:
        print " : : : : cp VarLists/DoubleElectron_Run2011A_PromptReco_v4.h VarList.h"
        os.system("cp VarLists/DoubleElectron_Run2011A_PromptReco_v4.h VarList.h")
    elif "DoubleElectron_Run2011B-PromptReco-v1_run179434_180252" in file1:
        print " : : : : cp VarLists/DoubleElectron_Run2011B-PromptReco-v1_run179434_180252.h VarList.h"
        os.system("cp VarLists/DoubleElectron_Run2011B-PromptReco-v1_run179434_180252.h VarList.h")
    elif "DoubleMu_Run2011A_03Oct2011_v1" in file1:
        print " : : : : cp VarLists/DoubleMu_Run2011A_03Oct2011_v1.h VarList.h"
        os.system("cp VarLists/DoubleMu_Run2011A_03Oct2011_v1.h VarList.h")
    elif "DoubleMu_Run2011A_05Aug2011_v1" in file1:
        print " : : : : cp VarLists/DoubleMu_Run2011A_05Aug2011_v1.h VarList.h"
        os.system("cp VarLists/DoubleMu_Run2011A_05Aug2011_v1.h VarList.h")
    elif "DoubleMu_Run2011A_May10ReReco_v1" in file1:
        print " : : : : cp VarLists/DoubleMu_Run2011A_May10ReReco_v1.h VarList.h"
        os.system("cp VarLists/DoubleMu_Run2011A_May10ReReco_v1.h VarList.h")
    elif "DoubleMu_Run2011A_PromptReco_v4" in file1:
        print " : : : : cp VarLists/DoubleMu_Run2011A_PromptReco_v4.h VarList.h"
        os.system("cp VarLists/DoubleMu_Run2011A_PromptReco_v4.h VarList.h")
    elif "DoubleMu_Run2011B_PromptReco_v1_run175860_178078" in file1:
        print " : : : : cp VarLists/DoubleMu_Run2011B_PromptReco_v1_run175860_178078.h VarList.h"
        os.system("cp VarLists/DoubleMu_Run2011B_PromptReco_v1_run175860_178078.h VarList.h")
    elif "DoubleMu_Run2011B_PromptReco_v1_run178098_178677" in file1:
        print " : : : : cp VarLists/DoubleMu_Run2011B_PromptReco_v1_run178098_178677.h VarList.h"
        os.system("cp VarLists/DoubleMu_Run2011B_PromptReco_v1_run178098_178677.h VarList.h")
    elif "DoubleMu_Run2011B_PromptReco_v1_run178703_179431" in file1:
        print " : : : : cp VarLists/DoubleMu_Run2011B_PromptReco_v1_run178703_179431.h VarList.h"
        os.system("cp VarLists/DoubleMu_Run2011B_PromptReco_v1_run178703_179431.h VarList.h")
    elif "DoubleMu_Run2011B_PromptReco_v1_run179434_180252" in file1:
        print " : : : : cp VarLists/DoubleMu_Run2011B_PromptReco_v1_run179434_180252.h VarList.h"
        os.system("cp VarLists/DoubleMu_Run2011B_PromptReco_v1_run179434_180252.h VarList.h")
       
    os.system("python my_parseCode.py --isMC=0")
    os.chdir("%s/src/"%base_path)
    os.system("scram b")
    

    if "2011A" in file1:
       run = 1
    else:
       run = 2


    if "Eg" in file1 or "EG" in file1 or "Electron" in file1:
        eleID = 11
        muID  = -1
        file2 = "histos_ee_phoID_%s_eleID_%s_%s"%(phoID,eleID,file1)
        out   = "%s.txt"%file2[:-5]
        com = "ZgammaAnalysis.exe inputFiles=%s outputfile=%s photonID=%s electronID=%s Run=%s"%(file,file2, phoID, eleID, run)
        print com
        if doEEG:
            os.system(com)
            os.system("mv %s/src/%s %s/src/ElectroWeakAnalysis/MultiBosons/bin/output"%(base_path,file2,base_path))

    elif "Mu" in file1:
        eleID = -1
        muID  = 2
        file2 = "histos_mm_phoID_%s_muID_%s_%s"%(phoID,muID,file1)
        out   = "%s.txt"%file2[:-5]
        com = "ZgammaAnalysis.exe inputFiles=%s outputfile=%s photonID=%s muonID=%s Run=%s"%(file,file2, phoID, muID, run)
        print com
        if doMMG:
            os.system(com)
            os.system("mv %s/src/%s %s/src/ElectroWeakAnalysis/MultiBosons/bin/output"%(base_path,file2,base_path))
        

if not len(mcFiles) == 0:
    os.chdir("%s/src/ElectroWeakAnalysis/MultiBosons/bin/"%base_path)
    print "PREPARING .h for mc"
    #if "146428" in file1:

#    os.system("cp VarLists/VarList_v149.h VarList.h")
    os.system("python my_parseCode.py --isMC=1")
    os.chdir("%s/src/"%base_path)
    os.system("scram b")

for file in mcFiles:
    file1 = file.split("/")[-1]

    # eeg
    eleID = 11
    muID  = -1
    file2 = "histos_ee_phoID_%s_eleID_%s_%s"%(phoID,eleID,file1)
    out   = "%s.txt"%file2[:-5]
    removeMcPhotonsFromZjets = 0
    if "ZJet" in file1: removeMcPhotonsFromZjets = 1
    com = "ZgammaAnalysis.exe inputFiles=%s outputfile=%s debug=0 photonID=%s electronID=%s matchMC=1 removeMcPhoJ=%s"%(file,file2, phoID, eleID, removeMcPhotonsFromZjets)
    print com
    if doEEG:
        os.system(com)
        os.system("mv %s/src/%s %s/src/ElectroWeakAnalysis/MultiBosons/bin/output"%(base_path,file2,base_path))
            
    #mmg
    eleID = -1
    muID  = 2
    file2 = "histos_mm_phoID_%s_muID_%s_%s"%(phoID,muID,file1)
    out   = "%s.txt"%file2[:-5]
    com = "ZgammaAnalysis.exe inputFiles=%s outputfile=%s debug=1 photonID=%s muonID=%s     matchMC=1"%(file,file2, phoID, muID)
    print com
    if doMMG:
        os.system(com)
        os.system("mv %s/src/%s %s/src/ElectroWeakAnalysis/MultiBosons/bin/output"%(base_path,file2,base_path))
	os.system("mv %s/src/%s %s/src/ElectroWeakAnalysis/MultiBosons/bin/output"%(base_path,out  ,base_path))
    
# go back to /bin
os.chdir("%s/src/ElectroWeakAnalysis/MultiBosons/bin/"%base_path)

print "==========================="
print "DONE PROCESSING ALL SAMPLES"
print "==========================="
