import os, re
from optparse import OptionParser
parser = OptionParser()
parser.add_option("-m", "--isMC", dest="isMC",
                  help="condifugureForMC", metavar="isMC")
options, args = parser.parse_args()

print options.isMC


file=open("ZgammaAnalysis_base.cc","r")
scriptLines = file.readlines()
file.close()

file=open("VarList.h","r")
Vars = file.readlines()
file.close()


def checkMC(line):
    mcPresent = False
    if "gen" in line or "Gen" in line or "GEN" in line: mcPresent = True
    if "mc" in line or "Mc" in line or "MC" in line: mcPresent = True
    if "pdf" in line or "pthat" in line: mcPresent = True
    return mcPresent


file = open("ZgammaAnalysis.cc","w")
for line in scriptLines:
    if not options.isMC=="1" and checkMC(line): continue

    if "= initiate leafs" in line:
        for var in Vars:
            if not options.isMC=="1" and checkMC(var): continue
            type     = var.split()[0]
            variable = var.split()[1]
            if "Int"   in type: type = "int"
            if "Long64"   in type: type = "unsigned long int"
#            if "Long"  in type: type = "long"
            if "Float" in type: type = "float"
            if "Bool"  in type: type = "int"
            file.write("\t%s\t%s\n"%(type,variable))
    elif "= initiate branches" in line:
        for var in Vars:
            if not options.isMC=="1" and checkMC(var): continue
            variable = var.split()[1].split("[")[0].split(";")[0]
            file.write("\tTBranch* b_%s;\n"%variable)
    elif "= set branches" in line:
        for var in Vars:
            if not options.isMC=="1" and checkMC(var): continue
            variable = var.split()[1].split("[")[0].split(";")[0]
            file.write("\tb_%s = tr->GetBranch(\"%s\");\n"%(variable,variable))
    elif "= set address" in line:
        for var in Vars:
            if not options.isMC=="1" and checkMC(var): continue
            variable = var.split()[1].split("[")[0].split(";")[0]
            file.write("\tb_%s->SetAddress(&%s);\n"%(variable,variable))
    else:
        file.write(line)
        
file.close()
