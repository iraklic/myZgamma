import os, commands

# get the CMSSW BASE
base_path = commands.getoutput("echo $CMSSW_BASE")
curD      = commands.getoutput("pwd")

# this is the list of files to run on

mcFiles=[]
dataFiles=[]
dataFiles384=[]
# NEW -----------------------
#dataFiles.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/Data_CMSSW425_vgamma_42x_v8/DoubleElectron_Run2011A_May10ReRecov1.root")
#dataFiles.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/Data_CMSSW425_vgamma_42x_v8/DoubleElectron_Run2011A_PromptRecov4_Run165088to167913.root")
#dataFiles.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/Data_CMSSW425_vgamma_42x_v8/DoubleMu_Run2011A_May10ReRecov1.root")
#dataFiles.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/Data_CMSSW425_vgamma_42x_v8/DoubleMu_Run2011A_PromptRecov4_Run165088to167913.root")

#dataFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/DATA_W_SKIM/SingleElectron_Run2011A_May10ReRecov1_skim.root")
#dataFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/DATA_W_SKIM/SingleElectron_Run2011A_PromptRecov4_Run165088to167913_skim.root")
dataFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/DATA_W_SKIM/SingleMu_Run2011A_May10ReRecov1_skim.root")
dataFiles.append("/uscms_data/d2/iraklich/Zgamma/CMSSW_4_2_0/src/ElectroWeakAnalysis/MultiBosons/bin/DATA_W_SKIM/SingleMu_Run2011A_PromptRecov4_Run165088to167913_skim.root")


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
    if "SingleElectron_Run2011A_May10ReRecov1" in file1:
	os.system("cp VarLists/W_SingleEle_Run2011_MayReReco.h VarList.h")
    elif "DoubleElectron_Run2011A_May10ReRecov1" in file1:
	os.system("cp VarLists/DoubleEle_Run2011_MayReReco.h VarList.h")
    elif "DoubleElectron_Run2011A_PromptRecov4" in file1:
	os.system("cp VarLists/DoubleEle_Run2011_PR.h VarList.h")
	print " - - - - - DoubleEle_Run2011_PR.h VarList.h - - - - - "
    elif "SingleElectron_Run2011A_PromptRecov4" in file1:
	os.system("cp VarLists/SingleEle_Run2011_PR.h VarList.h")
    elif "SingleMu_Run2011A_May10ReRecov1" in file1:
	os.system("cp VarLists/SingleMu_Run2011_MayReReco.h VarList.h")
    elif "SingleMu_Run2011A_PromptRecov4" in file1:
	os.system("cp VarLists/SingleMu_Run2011_PR.h VarList.h")
    elif "DoubleMu_Run2011A_May10ReRecov1" in file1:
	os.system("cp VarLists/DoubleMu_Run2011_MayReReco.h VarList.h")
	print " - - - - cp VarLists/DoubleMu_Run2011_MayReReco.h VarList.h - - - - "
    elif "DoubleMu_Run2011A_PromptRecov4" in file1:
	os.system("cp VarLists/DoubleMu_Run2011_PR.h VarList.h")
       
    os.system("python my_W_parseCode.py --isMC=0")
    os.chdir("%s/src/"%base_path)
    os.system("scram b")
    
    if "Eg" in file1 or "EG" in file1 or "Electron" in file1:

        eleID = 11
        muID  = -1
        file2 = "histos_ee_phoID_%s_eleID_%s_%s"%(phoID,eleID,file1)
        out   = "%s.txt"%file2[:-5]
        com = "ZgammaAnalysis.exe inputFiles=%s outputfile=%s debug=1 photonID=%s electronID=%s"%(file,file2, phoID, eleID)
        print com
        if doEEG:
            os.system(com)
            os.system("mv %s/src/%s %s/src/ElectroWeakAnalysis/MultiBosons/bin/output"%(base_path,file2,base_path))

    elif "Mu" in file1:
        eleID = -1
        muID  = 2
        file2 = "histos_mm_phoID_%s_muID_%s_%s"%(phoID,muID,file1)
        out   = "%s.txt"%file2[:-5]
        com = "ZgammaAnalysis.exe inputFiles=%s outputfile=%s debug=1 photonID=%s muonID=%s"%(file,file2, phoID, muID)
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
