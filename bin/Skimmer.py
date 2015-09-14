import ROOT, os, commands

files=[]

#local test input
#files.append("file:NTUPLE_TEST.root")
#files.append("NTUPLE_TEST_ee.root")


#================ ELECTRONS ==========================================================================================
#BAUR NSM WITH NEW COUPLINGS | PYTHIA BOOST ON
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_263279_10.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_263279_11.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_263279_12.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_263279_13.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_263279_14.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_263279_16.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_263279_17.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_263279_18.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_263279_19.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_263279_1.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_263279_20.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_263279_21.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_263279_22.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_263279_23.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_263279_24.root")
files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_263279_25.root")
files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_263279_26.root")
files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_263279_27.root")
files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_263279_28.root")
files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_263279_29.root")
files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_263279_2.root")
files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_263279_30.root")
files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_263279_31.root")
files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_263279_32.root")
files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_263279_33.root")
files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_263279_34.root")
files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_263279_35.root")
files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_263279_36.root")
files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_263279_37.root")
files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_263279_38.root")
files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_263279_39.root")
files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_263279_3.root")
files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_263279_40.root")
files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_263279_41.root")
files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_263279_43.root")
files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_263279_44.root")
files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_263279_45.root")
files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_263279_46.root")
files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_263279_47.root")
files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_263279_48.root")
files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_263279_4.root")
files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_263279_5.root")
files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_263279_6.root")
files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_263279_7.root")
files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_263279_8.root")
files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_263279_9.root")

# BAUR NSM | PYTHIA ISR/FSR OFF
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_PYTHIA_F_ISR_OFF_146847_0.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_PYTHIA_F_ISR_OFF_146847_1.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_PYTHIA_F_ISR_OFF_146847_2.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_PYTHIA_F_ISR_OFF_146847_3.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_PYTHIA_F_ISR_OFF_146847_4.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_PYTHIA_F_ISR_OFF_146847_5.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_PYTHIA_F_ISR_OFF_146847_6.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_PYTHIA_F_ISR_OFF_146847_7.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_PYTHIA_F_ISR_OFF_146847_8.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_PYTHIA_F_ISR_OFF_146847_9.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_PYTHIA_F_ISR_OFF_146847_10.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_PYTHIA_F_ISR_OFF_146847_11.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_PYTHIA_F_ISR_OFF_146847_12.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_PYTHIA_F_ISR_OFF_146847_13.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_PYTHIA_F_ISR_OFF_146847_14.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_PYTHIA_F_ISR_OFF_146847_15.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_PYTHIA_F_ISR_OFF_146847_16.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_PYTHIA_F_ISR_OFF_146847_17.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_PYTHIA_F_ISR_OFF_146847_18.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/NSM_ee/NTUPLE_BAUR_NSM_ee_PYTHIA_F_ISR_OFF_146847_19.root")



# BAUR SM | PYTHIA ISR/FSR ON
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_263088_0.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_263088_1.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_263088_10.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_263088_11.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_263088_12.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_263088_13.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_263088_14.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_263088_15.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_263088_16.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_263088_17.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_263088_18.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_263088_19.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_263088_2.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_263088_20.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_263088_21.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_263088_22.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_263088_23.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_263088_24.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_263088_25.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_263088_26.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_263088_27.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_263088_29.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_263088_3.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_263088_30.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_263088_31.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_263088_32.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_263088_33.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_263088_34.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_263088_4.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_263088_5.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_263088_6.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_263088_7.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_263088_8.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_263088_9.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_240852_36.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_240852_37.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_240852_38.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_240852_39.root")


# BAUR SM | PYTHIA ISR/FSR ON
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_392454_0.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_392454_10.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_392454_11.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_392454_12.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_392454_13.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_392454_14.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_392454_15.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_392454_16.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_392454_17.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_392454_18.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_392454_19.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_392454_1.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_392454_20.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_392454_21.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_392454_22.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_392454_23.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_392454_24.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_392454_25.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_392454_26.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_392454_27.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_392454_28.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_392454_29.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_392454_2.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_392454_30.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_392454_31.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_392454_32.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_392454_33.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_392454_34.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_392454_35.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_392454_36.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_392454_37.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_392454_38.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_392454_39.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_392454_3.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_392454_40.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_392454_41.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_392454_42.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_392454_43.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_392454_44.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_392454_45.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_392454_46.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_392454_47.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_392454_4.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_392454_5.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_392454_6.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_392454_7.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_392454_8.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_392454_9.root")


# BAUR SM | PYTHIA ISR/FSR OFF
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_P_214236_0.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_P_214236_1.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_P_214236_2.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_P_214236_3.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_P_214236_4.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_P_214236_5.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_P_214236_6.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_P_214236_7.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_P_214236_8.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_P_214236_9.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_P_214236_10.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_P_214236_11.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_P_214236_12.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_P_214236_13.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_P_214236_14.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_P_214236_15.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_P_214236_16.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_P_214236_17.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_P_214236_18.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_P_214236_19.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_P_214236_20.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_P_214236_21.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_P_214236_22.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_P_214236_23.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_P_214236_24.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_P_214236_25.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_P_214236_26.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_P_214236_27.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_P_214236_28.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_P_214236_29.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_P_214236_30.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_P_214236_31.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_P_214236_32.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_P_214236_33.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_P_214236_34.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_P_214236_35.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_P_214236_36.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_P_214236_37.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_P_214236_38.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_ee/NTUPLE_BAUR_SM_ee_P_214236_39.root")

# MG5 SM 2jets | PYTHIA ISR/FSR/OFF
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee_2jets/NTUPLE_MG5_SM_ee_2jets_P_166683_0.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee_2jets/NTUPLE_MG5_SM_ee_2jets_P_166683_1.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee_2jets/NTUPLE_MG5_SM_ee_2jets_P_166683_2.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee_2jets/NTUPLE_MG5_SM_ee_2jets_P_166683_3.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee_2jets/NTUPLE_MG5_SM_ee_2jets_P_166683_4.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee_2jets/NTUPLE_MG5_SM_ee_2jets_P_166683_5.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee_2jets/NTUPLE_MG5_SM_ee_2jets_P_166683_6.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee_2jets/NTUPLE_MG5_SM_ee_2jets_P_166683_7.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee_2jets/NTUPLE_MG5_SM_ee_2jets_P_166683_8.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee_2jets/NTUPLE_MG5_SM_ee_2jets_P_166683_9.root")

#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_ee/NLO/NTUPLE_MG_SM_ee_NLO_253281_0.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_ee/NLO/NTUPLE_MG_SM_ee_NLO_253281_10.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_ee/NLO/NTUPLE_MG_SM_ee_NLO_253281_11.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_ee/NLO/NTUPLE_MG_SM_ee_NLO_253281_12.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_ee/NLO/NTUPLE_MG_SM_ee_NLO_253281_13.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_ee/NLO/NTUPLE_MG_SM_ee_NLO_253281_14.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_ee/NLO/NTUPLE_MG_SM_ee_NLO_253281_15.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_ee/NLO/NTUPLE_MG_SM_ee_NLO_253281_16.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_ee/NLO/NTUPLE_MG_SM_ee_NLO_253281_17.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_ee/NLO/NTUPLE_MG_SM_ee_NLO_253281_18.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_ee/NLO/NTUPLE_MG_SM_ee_NLO_253281_19.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_ee/NLO/NTUPLE_MG_SM_ee_NLO_253281_1.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_ee/NLO/NTUPLE_MG_SM_ee_NLO_253281_20.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_ee/NLO/NTUPLE_MG_SM_ee_NLO_253281_21.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_ee/NLO/NTUPLE_MG_SM_ee_NLO_253281_22.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_ee/NLO/NTUPLE_MG_SM_ee_NLO_253281_23.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_ee/NLO/NTUPLE_MG_SM_ee_NLO_253281_24.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_ee/NLO/NTUPLE_MG_SM_ee_NLO_253281_25.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_ee/NLO/NTUPLE_MG_SM_ee_NLO_253281_26.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_ee/NLO/NTUPLE_MG_SM_ee_NLO_253281_27.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_ee/NLO/NTUPLE_MG_SM_ee_NLO_253281_28.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_ee/NLO/NTUPLE_MG_SM_ee_NLO_253281_29.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_ee/NLO/NTUPLE_MG_SM_ee_NLO_253281_2.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_ee/NLO/NTUPLE_MG_SM_ee_NLO_253281_30.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_ee/NLO/NTUPLE_MG_SM_ee_NLO_253281_31.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_ee/NLO/NTUPLE_MG_SM_ee_NLO_253281_32.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_ee/NLO/NTUPLE_MG_SM_ee_NLO_253281_33.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_ee/NLO/NTUPLE_MG_SM_ee_NLO_253281_34.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_ee/NLO/NTUPLE_MG_SM_ee_NLO_253281_3.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_ee/NLO/NTUPLE_MG_SM_ee_NLO_253281_4.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_ee/NLO/NTUPLE_MG_SM_ee_NLO_253281_5.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_ee/NLO/NTUPLE_MG_SM_ee_NLO_253281_6.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_ee/NLO/NTUPLE_MG_SM_ee_NLO_253281_7.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_ee/NLO/NTUPLE_MG_SM_ee_NLO_253281_8.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_ee/NLO/NTUPLE_MG_SM_ee_NLO_253281_9.root")

#MG5 SM (ee) as LO sample | PYTHIA ISR/FSR OFF
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG5_SM_ee_LO_P_233904_0.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG5_SM_ee_LO_P_233904_1.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG5_SM_ee_LO_P_233904_2.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG5_SM_ee_LO_P_233904_3.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG5_SM_ee_LO_P_233904_4.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG5_SM_ee_LO_P_233904_5.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG5_SM_ee_LO_P_233904_6.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG5_SM_ee_LO_P_233904_7.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG5_SM_ee_LO_P_233904_8.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG5_SM_ee_LO_P_233904_9.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG5_SM_ee_LO_P_233904_10.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG5_SM_ee_LO_P_233904_11.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG5_SM_ee_LO_P_233904_12.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG5_SM_ee_LO_P_233904_13.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG5_SM_ee_LO_P_233904_14.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG5_SM_ee_LO_P_233904_15.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG5_SM_ee_LO_P_233904_16.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG5_SM_ee_LO_P_233904_17.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG5_SM_ee_LO_P_233904_18.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG5_SM_ee_LO_P_233904_19.root")

#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG_SM_ee_LO_234743_0.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG_SM_ee_LO_234743_1.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG_SM_ee_LO_234743_10.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG_SM_ee_LO_234743_11.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG_SM_ee_LO_234743_12.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG_SM_ee_LO_234743_14.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG_SM_ee_LO_234743_15.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG_SM_ee_LO_234743_16.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG_SM_ee_LO_234743_17.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG_SM_ee_LO_234743_19.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG_SM_ee_LO_234743_2.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG_SM_ee_LO_234743_20.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG_SM_ee_LO_234743_22.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG_SM_ee_LO_234743_24.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG_SM_ee_LO_234743_25.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG_SM_ee_LO_234743_26.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG_SM_ee_LO_234743_27.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG_SM_ee_LO_234743_28.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG_SM_ee_LO_234743_3.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG_SM_ee_LO_234743_30.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG_SM_ee_LO_234743_31.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG_SM_ee_LO_234743_32.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG_SM_ee_LO_234743_33.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG_SM_ee_LO_234743_34.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG_SM_ee_LO_234743_35.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG_SM_ee_LO_234743_36.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG_SM_ee_LO_234743_37.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG_SM_ee_LO_234743_38.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG_SM_ee_LO_234743_4.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG_SM_ee_LO_234743_40.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG_SM_ee_LO_234743_42.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG_SM_ee_LO_234743_43.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG_SM_ee_LO_234743_44.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG_SM_ee_LO_234743_45.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG_SM_ee_LO_234743_46.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG_SM_ee_LO_234743_47.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG_SM_ee_LO_234743_48.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG_SM_ee_LO_234743_49.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG_SM_ee_LO_234743_5.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG_SM_ee_LO_234743_6.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG_SM_ee_LO_234743_7.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG_SM_ee_LO_234743_8.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/LO/NTUPLE_MG_SM_ee_LO_234743_9.root")


#MG5 SM (ee) ISR Only | PYTHIA ISR/FSR OFF
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/ISR/NTUPLE_MG5_SM_ee_ISR_P_285401_0.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/ISR/NTUPLE_MG5_SM_ee_ISR_P_285401_1.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/ISR/NTUPLE_MG5_SM_ee_ISR_P_285401_2.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/ISR/NTUPLE_MG5_SM_ee_ISR_P_285401_3.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/ISR/NTUPLE_MG5_SM_ee_ISR_P_285401_4.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/ISR/NTUPLE_MG5_SM_ee_ISR_P_285401_5.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/ISR/NTUPLE_MG5_SM_ee_ISR_P_285401_6.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/ISR/NTUPLE_MG5_SM_ee_ISR_P_285401_7.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/ISR/NTUPLE_MG5_SM_ee_ISR_P_285401_8.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/ISR/NTUPLE_MG5_SM_ee_ISR_P_285401_9.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/ISR/NTUPLE_MG5_SM_ee_ISR_P_285401_10.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/ISR/NTUPLE_MG5_SM_ee_ISR_P_285401_11.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/ISR/NTUPLE_MG5_SM_ee_ISR_P_285401_12.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/ISR/NTUPLE_MG5_SM_ee_ISR_P_285401_13.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/ISR/NTUPLE_MG5_SM_ee_ISR_P_285401_14.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/ISR/NTUPLE_MG5_SM_ee_ISR_P_285401_15.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/ISR/NTUPLE_MG5_SM_ee_ISR_P_285401_16.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/ISR/NTUPLE_MG5_SM_ee_ISR_P_285401_17.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/ISR/NTUPLE_MG5_SM_ee_ISR_P_285401_18.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/ISR/NTUPLE_MG5_SM_ee_ISR_P_285401_19.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/ISR/NTUPLE_MG5_SM_ee_ISR_P_285401_20.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/ISR/NTUPLE_MG5_SM_ee_ISR_P_285401_21.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/ISR/NTUPLE_MG5_SM_ee_ISR_P_285401_22.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/ISR/NTUPLE_MG5_SM_ee_ISR_P_285401_23.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/ISR/NTUPLE_MG5_SM_ee_ISR_P_285401_24.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/ISR/NTUPLE_MG5_SM_ee_ISR_P_285401_25.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/ISR/NTUPLE_MG5_SM_ee_ISR_P_285401_26.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/ISR/NTUPLE_MG5_SM_ee_ISR_P_285401_27.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/ISR/NTUPLE_MG5_SM_ee_ISR_P_285401_28.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/ISR/NTUPLE_MG5_SM_ee_ISR_P_285401_29.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/ISR/NTUPLE_MG5_SM_ee_ISR_P_285401_30.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/ISR/NTUPLE_MG5_SM_ee_ISR_P_285401_31.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/ISR/NTUPLE_MG5_SM_ee_ISR_P_285401_32.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/ISR/NTUPLE_MG5_SM_ee_ISR_P_285401_33.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/ISR/NTUPLE_MG5_SM_ee_ISR_P_285401_34.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/ISR/NTUPLE_MG5_SM_ee_ISR_P_285401_35.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/ISR/NTUPLE_MG5_SM_ee_ISR_P_285401_36.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/ISR/NTUPLE_MG5_SM_ee_ISR_P_285401_37.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/ISR/NTUPLE_MG5_SM_ee_ISR_P_285401_38.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/ISR/NTUPLE_MG5_SM_ee_ISR_P_285401_39.root")
#=====================================================================================================================
#================ ! M U O N S ! ======================================================================================
#=====================================================================================================================
#MG5 SM (mm) as LO sample | PYTHIA ISR/FSR OFF
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_mm/LO/NTUPLE_MG5_SM_mm_LO_P_168609_0.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_mm/LO/NTUPLE_MG5_SM_mm_LO_P_168609_1.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_mm/LO/NTUPLE_MG5_SM_mm_LO_P_168609_2.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_mm/LO/NTUPLE_MG5_SM_mm_LO_P_168609_3.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_mm/LO/NTUPLE_MG5_SM_mm_LO_P_168609_4.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_mm/LO/NTUPLE_MG5_SM_mm_LO_P_168609_5.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_mm/LO/NTUPLE_MG5_SM_mm_LO_P_168609_6.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_mm/LO/NTUPLE_MG5_SM_mm_LO_P_168609_7.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_mm/LO/NTUPLE_MG5_SM_mm_LO_P_168609_8.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_mm/LO/NTUPLE_MG5_SM_mm_LO_P_168609_9.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_mm/LO/NTUPLE_MG5_SM_mm_LO_P_168609_10.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_mm/LO/NTUPLE_MG5_SM_mm_LO_P_168609_11.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_mm/LO/NTUPLE_MG5_SM_mm_LO_P_168609_12.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_mm/LO/NTUPLE_MG5_SM_mm_LO_P_168609_13.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_mm/LO/NTUPLE_MG5_SM_mm_LO_P_168609_14.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_mm/LO/NTUPLE_MG5_SM_mm_LO_P_168609_15.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_mm/LO/NTUPLE_MG5_SM_mm_LO_P_168609_16.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_mm/LO/NTUPLE_MG5_SM_mm_LO_P_168609_17.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_mm/LO/NTUPLE_MG5_SM_mm_LO_P_168609_18.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_mm/LO/NTUPLE_MG5_SM_mm_LO_P_168609_19.root")

#MG5 SM (mm) as LO sample | PYTHIA ISR/FSR ON
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/LO/NTUPLE_MG_SM_mm_LO_280202_0.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/LO/NTUPLE_MG_SM_mm_LO_280202_1.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/LO/NTUPLE_MG_SM_mm_LO_280202_10.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/LO/NTUPLE_MG_SM_mm_LO_280202_11.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/LO/NTUPLE_MG_SM_mm_LO_280202_12.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/LO/NTUPLE_MG_SM_mm_LO_280202_13.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/LO/NTUPLE_MG_SM_mm_LO_280202_14.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/LO/NTUPLE_MG_SM_mm_LO_280202_15.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/LO/NTUPLE_MG_SM_mm_LO_280202_16.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/LO/NTUPLE_MG_SM_mm_LO_280202_17.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/LO/NTUPLE_MG_SM_mm_LO_280202_18.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/LO/NTUPLE_MG_SM_mm_LO_280202_19.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/LO/NTUPLE_MG_SM_mm_LO_280202_2.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/LO/NTUPLE_MG_SM_mm_LO_280202_20.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/LO/NTUPLE_MG_SM_mm_LO_280202_21.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/LO/NTUPLE_MG_SM_mm_LO_280202_22.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/LO/NTUPLE_MG_SM_mm_LO_280202_23.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/LO/NTUPLE_MG_SM_mm_LO_280202_24.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/LO/NTUPLE_MG_SM_mm_LO_280202_25.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/LO/NTUPLE_MG_SM_mm_LO_280202_26.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/LO/NTUPLE_MG_SM_mm_LO_280202_27.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/LO/NTUPLE_MG_SM_mm_LO_280202_28.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/LO/NTUPLE_MG_SM_mm_LO_280202_29.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/LO/NTUPLE_MG_SM_mm_LO_280202_3.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/LO/NTUPLE_MG_SM_mm_LO_280202_30.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/LO/NTUPLE_MG_SM_mm_LO_280202_31.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/LO/NTUPLE_MG_SM_mm_LO_280202_32.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/LO/NTUPLE_MG_SM_mm_LO_280202_33.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/LO/NTUPLE_MG_SM_mm_LO_280202_34.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/LO/NTUPLE_MG_SM_mm_LO_280202_35.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/LO/NTUPLE_MG_SM_mm_LO_280202_36.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/LO/NTUPLE_MG_SM_mm_LO_280202_37.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/LO/NTUPLE_MG_SM_mm_LO_280202_38.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/LO/NTUPLE_MG_SM_mm_LO_280202_39.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/LO/NTUPLE_MG_SM_mm_LO_280202_4.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/LO/NTUPLE_MG_SM_mm_LO_280202_40.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/LO/NTUPLE_MG_SM_mm_LO_280202_41.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/LO/NTUPLE_MG_SM_mm_LO_280202_42.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/LO/NTUPLE_MG_SM_mm_LO_280202_43.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/LO/NTUPLE_MG_SM_mm_LO_280202_44.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/LO/NTUPLE_MG_SM_mm_LO_280202_45.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/LO/NTUPLE_MG_SM_mm_LO_280202_46.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/LO/NTUPLE_MG_SM_mm_LO_280202_47.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/LO/NTUPLE_MG_SM_mm_LO_280202_48.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/LO/NTUPLE_MG_SM_mm_LO_280202_49.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/LO/NTUPLE_MG_SM_mm_LO_280202_5.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/LO/NTUPLE_MG_SM_mm_LO_280202_6.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/LO/NTUPLE_MG_SM_mm_LO_280202_7.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/LO/NTUPLE_MG_SM_mm_LO_280202_8.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/LO/NTUPLE_MG_SM_mm_LO_280202_9.root")


#MG5 SM (mm) + 2jet | PYTHIA ISR/FSR OFF
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_mm_2jets/NTUPLE_MG5_SM_mm_2jets_118533_0.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_mm_2jets/NTUPLE_MG5_SM_mm_2jets_118533_1.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_mm_2jets/NTUPLE_MG5_SM_mm_2jets_118533_2.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_mm_2jets/NTUPLE_MG5_SM_mm_2jets_118533_3.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_mm_2jets/NTUPLE_MG5_SM_mm_2jets_118533_4.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_mm_2jets/NTUPLE_MG5_SM_mm_2jets_118533_5.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_mm_2jets/NTUPLE_MG5_SM_mm_2jets_118533_6.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_mm_2jets/NTUPLE_MG5_SM_mm_2jets_118533_7.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_mm_2jets/NTUPLE_MG5_SM_mm_2jets_118533_8.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_mm_2jets/NTUPLE_MG5_SM_mm_2jets_118533_9.root")

#MG5 SM (mm) + 2jet | PYTHIA ISR/FSR ON
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/NLO/NTUPLE_MG_SM_mm_NLO_258007_0.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/NLO/NTUPLE_MG_SM_mm_NLO_258007_10.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/NLO/NTUPLE_MG_SM_mm_NLO_258007_11.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/NLO/NTUPLE_MG_SM_mm_NLO_258007_12.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/NLO/NTUPLE_MG_SM_mm_NLO_258007_13.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/NLO/NTUPLE_MG_SM_mm_NLO_258007_14.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/NLO/NTUPLE_MG_SM_mm_NLO_258007_15.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/NLO/NTUPLE_MG_SM_mm_NLO_258007_16.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/NLO/NTUPLE_MG_SM_mm_NLO_258007_17.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/NLO/NTUPLE_MG_SM_mm_NLO_258007_18.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/NLO/NTUPLE_MG_SM_mm_NLO_258007_19.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/NLO/NTUPLE_MG_SM_mm_NLO_258007_1.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/NLO/NTUPLE_MG_SM_mm_NLO_258007_20.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/NLO/NTUPLE_MG_SM_mm_NLO_258007_21.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/NLO/NTUPLE_MG_SM_mm_NLO_258007_22.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/NLO/NTUPLE_MG_SM_mm_NLO_258007_23.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/NLO/NTUPLE_MG_SM_mm_NLO_258007_24.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/NLO/NTUPLE_MG_SM_mm_NLO_258007_25.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/NLO/NTUPLE_MG_SM_mm_NLO_258007_26.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/NLO/NTUPLE_MG_SM_mm_NLO_258007_27.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/NLO/NTUPLE_MG_SM_mm_NLO_258007_28.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/NLO/NTUPLE_MG_SM_mm_NLO_258007_29.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/NLO/NTUPLE_MG_SM_mm_NLO_258007_2.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/NLO/NTUPLE_MG_SM_mm_NLO_258007_30.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/NLO/NTUPLE_MG_SM_mm_NLO_258007_31.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/NLO/NTUPLE_MG_SM_mm_NLO_258007_32.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/NLO/NTUPLE_MG_SM_mm_NLO_258007_33.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/NLO/NTUPLE_MG_SM_mm_NLO_258007_34.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/NLO/NTUPLE_MG_SM_mm_NLO_258007_35.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/NLO/NTUPLE_MG_SM_mm_NLO_258007_36.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/NLO/NTUPLE_MG_SM_mm_NLO_258007_37.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/NLO/NTUPLE_MG_SM_mm_NLO_258007_38.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/NLO/NTUPLE_MG_SM_mm_NLO_258007_39.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/NLO/NTUPLE_MG_SM_mm_NLO_258007_3.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/NLO/NTUPLE_MG_SM_mm_NLO_258007_40.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/NLO/NTUPLE_MG_SM_mm_NLO_258007_41.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/NLO/NTUPLE_MG_SM_mm_NLO_258007_42.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/NLO/NTUPLE_MG_SM_mm_NLO_258007_43.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/NLO/NTUPLE_MG_SM_mm_NLO_258007_44.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/NLO/NTUPLE_MG_SM_mm_NLO_258007_45.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/NLO/NTUPLE_MG_SM_mm_NLO_258007_46.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/NLO/NTUPLE_MG_SM_mm_NLO_258007_47.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/NLO/NTUPLE_MG_SM_mm_NLO_258007_48.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/NLO/NTUPLE_MG_SM_mm_NLO_258007_49.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/NLO/NTUPLE_MG_SM_mm_NLO_258007_4.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/NLO/NTUPLE_MG_SM_mm_NLO_258007_5.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/NLO/NTUPLE_MG_SM_mm_NLO_258007_6.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/NLO/NTUPLE_MG_SM_mm_NLO_258007_7.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/NLO/NTUPLE_MG_SM_mm_NLO_258007_8.root")
#files.append("rfio:/eos/uscms/store/user/iraklich/MG5/SM_mm/NLO/NTUPLE_MG_SM_mm_NLO_258007_9.root")


#BAUR NSM (mm) | PYTHIA ISR/FSR OFF
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/NSM_mm/NTUPLE_BAUR_NSM_mm_127682_0.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/NSM_mm/NTUPLE_BAUR_NSM_mm_127682_1.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/NSM_mm/NTUPLE_BAUR_NSM_mm_127682_2.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/NSM_mm/NTUPLE_BAUR_NSM_mm_127682_3.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/NSM_mm/NTUPLE_BAUR_NSM_mm_127682_4.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/NSM_mm/NTUPLE_BAUR_NSM_mm_127682_5.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/NSM_mm/NTUPLE_BAUR_NSM_mm_127682_6.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/NSM_mm/NTUPLE_BAUR_NSM_mm_127682_7.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/NSM_mm/NTUPLE_BAUR_NSM_mm_127682_8.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/NSM_mm/NTUPLE_BAUR_NSM_mm_127682_9.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/NSM_mm/NTUPLE_BAUR_NSM_mm_127682_10.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/NSM_mm/NTUPLE_BAUR_NSM_mm_127682_11.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/NSM_mm/NTUPLE_BAUR_NSM_mm_127682_12.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/NSM_mm/NTUPLE_BAUR_NSM_mm_127682_13.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/NSM_mm/NTUPLE_BAUR_NSM_mm_127682_14.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/NSM_mm/NTUPLE_BAUR_NSM_mm_127682_15.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/NSM_mm/NTUPLE_BAUR_NSM_mm_127682_16.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/NSM_mm/NTUPLE_BAUR_NSM_mm_127682_17.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/NSM_mm/NTUPLE_BAUR_NSM_mm_127682_18.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/NSM_mm/NTUPLE_BAUR_NSM_mm_127682_19.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/NSM_mm/NTUPLE_BAUR_NSM_mm_127682_20.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/NSM_mm/NTUPLE_BAUR_NSM_mm_127682_21.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/NSM_mm/NTUPLE_BAUR_NSM_mm_127682_22.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/NSM_mm/NTUPLE_BAUR_NSM_mm_127682_23.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/NSM_mm/NTUPLE_BAUR_NSM_mm_127682_24.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/NSM_mm/NTUPLE_BAUR_NSM_mm_127682_25.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/NSM_mm/NTUPLE_BAUR_NSM_mm_127682_26.root")

#BAUR SM (mm) | PYTHIA ISR/FSR OFF
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_mm/NTUPLE_BAUR_SM_mm_107631_0.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_mm/NTUPLE_BAUR_SM_mm_107631_1.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_mm/NTUPLE_BAUR_SM_mm_107631_2.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_mm/NTUPLE_BAUR_SM_mm_107631_3.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_mm/NTUPLE_BAUR_SM_mm_107631_4.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_mm/NTUPLE_BAUR_SM_mm_107631_5.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_mm/NTUPLE_BAUR_SM_mm_107631_6.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_mm/NTUPLE_BAUR_SM_mm_107631_7.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_mm/NTUPLE_BAUR_SM_mm_107631_8.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_mm/NTUPLE_BAUR_SM_mm_107631_9.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_mm/NTUPLE_BAUR_SM_mm_107631_10.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_mm/NTUPLE_BAUR_SM_mm_107631_11.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_mm/NTUPLE_BAUR_SM_mm_107631_12.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_mm/NTUPLE_BAUR_SM_mm_107631_13.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_mm/NTUPLE_BAUR_SM_mm_107631_14.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_mm/NTUPLE_BAUR_SM_mm_107631_15.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_mm/NTUPLE_BAUR_SM_mm_107631_16.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_mm/NTUPLE_BAUR_SM_mm_107631_17.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_mm/NTUPLE_BAUR_SM_mm_107631_18.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_mm/NTUPLE_BAUR_SM_mm_107631_19.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_mm/NTUPLE_BAUR_SM_mm_107631_20.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_mm/NTUPLE_BAUR_SM_mm_107631_21.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_mm/NTUPLE_BAUR_SM_mm_107631_22.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_mm/NTUPLE_BAUR_SM_mm_107631_23.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_mm/NTUPLE_BAUR_SM_mm_107631_24.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_mm/NTUPLE_BAUR_SM_mm_107631_25.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_mm/NTUPLE_BAUR_SM_mm_107631_26.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_mm/NTUPLE_BAUR_SM_mm_107631_27.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_mm/NTUPLE_BAUR_SM_mm_107631_28.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_mm/NTUPLE_BAUR_SM_mm_107631_29.root")

# MG5 SIR ONLY (ee)
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/NTUPLE_MG5_SM_ee_ISR_ONLY_87202_6.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/NTUPLE_MG5_SM_ee_ISR_ONLY_87202_2.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/NTUPLE_MG5_SM_ee_ISR_ONLY_87202_9.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/NTUPLE_MG5_SM_ee_ISR_ONLY_87202_3.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/NTUPLE_MG5_SM_ee_ISR_ONLY_87202_5.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/NTUPLE_MG5_SM_ee_ISR_ONLY_87202_1.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/NTUPLE_MG5_SM_ee_ISR_ONLY_87202_8.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/NTUPLE_MG5_SM_ee_ISR_ONLY_87202_7.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/NTUPLE_MG5_SM_ee_ISR_ONLY_87202_4.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_ee/NTUPLE_MG5_SM_ee_ISR_ONLY_87202_0.root")

# MG5 SIR ONLY (mm) | PYTHIA ISR/FSR OFF
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_mm/NTUPLE_MG5_SM_mm_ISR_ONLY_113519_0.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_mm/NTUPLE_MG5_SM_mm_ISR_ONLY_113519_1.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_mm/NTUPLE_MG5_SM_mm_ISR_ONLY_113519_2.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_mm/NTUPLE_MG5_SM_mm_ISR_ONLY_113519_3.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_mm/NTUPLE_MG5_SM_mm_ISR_ONLY_113519_4.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_mm/NTUPLE_MG5_SM_mm_ISR_ONLY_113519_5.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_mm/NTUPLE_MG5_SM_mm_ISR_ONLY_113519_6.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_mm/NTUPLE_MG5_SM_mm_ISR_ONLY_113519_7.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_mm/NTUPLE_MG5_SM_mm_ISR_ONLY_113519_8.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_mm/NTUPLE_MG5_SM_mm_ISR_ONLY_113519_9.root")

# MG5 ISR ONLY (mm) | PYTHIA ISR/FRS ON
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_mm/NTUPLE_MG5_SM_mm_ISR_ONLY_114761_0.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_mm/NTUPLE_MG5_SM_mm_ISR_ONLY_114761_1.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_mm/NTUPLE_MG5_SM_mm_ISR_ONLY_114761_2.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_mm/NTUPLE_MG5_SM_mm_ISR_ONLY_114761_3.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_mm/NTUPLE_MG5_SM_mm_ISR_ONLY_114761_4.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_mm/NTUPLE_MG5_SM_mm_ISR_ONLY_114761_5.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_mm/NTUPLE_MG5_SM_mm_ISR_ONLY_114761_6.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_mm/NTUPLE_MG5_SM_mm_ISR_ONLY_114761_7.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_mm/NTUPLE_MG5_SM_mm_ISR_ONLY_114761_8.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/MG5/SM_mm/NTUPLE_MG5_SM_mm_ISR_ONLY_114761_9.root")

#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_mm/NTUPLE_BAUR_SM_mm_24471_0.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_mm/NTUPLE_BAUR_SM_mm_24471_1.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_mm/NTUPLE_BAUR_SM_mm_24471_10.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_mm/NTUPLE_BAUR_SM_mm_24471_11.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_mm/NTUPLE_BAUR_SM_mm_24471_12.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_mm/NTUPLE_BAUR_SM_mm_24471_13.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_mm/NTUPLE_BAUR_SM_mm_24471_14.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_mm/NTUPLE_BAUR_SM_mm_24471_15.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_mm/NTUPLE_BAUR_SM_mm_24471_16.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_mm/NTUPLE_BAUR_SM_mm_24471_18.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_mm/NTUPLE_BAUR_SM_mm_24471_19.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_mm/NTUPLE_BAUR_SM_mm_24471_2.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_mm/NTUPLE_BAUR_SM_mm_24471_3.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_mm/NTUPLE_BAUR_SM_mm_24471_4.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_mm/NTUPLE_BAUR_SM_mm_24471_5.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_mm/NTUPLE_BAUR_SM_mm_24471_6.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_mm/NTUPLE_BAUR_SM_mm_24471_7.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_mm/NTUPLE_BAUR_SM_mm_24471_8.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_mm/NTUPLE_BAUR_SM_mm_24471_9.root")
#files.append("dcache:/pnfs/cms/WAX/11/store/user/iraklich/Zgamma/BAUR/SM_mm/NTUPLE_BAUR_SM_mm_25610_17.root")

# NEW DATASETS  2178.0(A) + 2520.8(B)
# --- ELECTRONS
#files.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/Data/DoubleElectron_Run2011A_03Oct2011_v1.root")
#files.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/Data/DoubleElectron_Run2011A_05Aug2011_v1.root")
#files.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/Data/DoubleElectron_Run2011A_05Aug2011_v1_excTrg_addCSC.root")
#ifiles.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/Data/DoubleElectron_Run2011A_May10ReReco_v1.root")
#files.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/Data/DoubleElectron_Run2011A_PromptReco_v4.root")
#files.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/Data/DoubleElectron_Run2011B_PromptReco_v1_run175860_178078.root")
#files.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/Data/DoubleElectron_Run2011B_PromptReco_v1_run178098_178677.root")
#files.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/Data/DoubleElectron_Run2011B_PromptReco_v1_run178703_179431.root")
#files.append("DoubleElectron_Run2011B-PromptReco-v1_run179434_180252.root")

# --- MUONS
#files.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/Data/DoubleMu_Run2011A_03Oct2011_v1.root")
#files.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/Data/DoubleMu_Run2011A_05Aug2011_v1.root")
#files.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/Data/DoubleMu_Run2011A_May10ReReco_v1.root")
#files.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/Data/DoubleMu_Run2011A_PromptReco_v4.root")
#files.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/Data/DoubleMu_Run2011B_PromptReco_v1_run175860_178078.root")
#files.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/Data/DoubleMu_Run2011B_PromptReco_v1_run178098_178677.root")
#files.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/Data/DoubleMu_Run2011B_PromptReco_v1_run178703_179431.root")
#files.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/Data/DoubleMu_Run2011B_PromptReco_v1_run179434_180252.root")

#files.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/MC/ZgammaMu_1Jet_Madgraph_Fall11.root")
#files.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/MC/ZgammaEle_1Jet_Madgraph_Fall11.root")
#files.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/MC/DYJetsToLL_TuneZ2_M50_Madgraph_Fall11.root")

# OLD DATASETS ~750 1/pb
#files.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/Data_CMSSW425_vgamma_42x_v8/DoubleElectron_Run2011A_May10ReRecov1.root")
#files.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/Data_CMSSW425_vgamma_42x_v8/DoubleElectron_Run2011A_PromptRecov4_Run165088to167913.root")
#files.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/Data_CMSSW425_vgamma_42x_v8/DoubleMu_Run2011A_May10ReRecov1.root")
#files.append("/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/data/Data_CMSSW425_vgamma_42x_v8/DoubleMu_Run2011A_PromptRecov4_Run165088to167913.root")

def makeClass(file):

    f = ROOT.TFile.Open(file,"READ")
#    ROOT.gROOT.cd()
    f.cd("VgAnalyzerKit")
#    f.cd("VgNtuplizer")
    tr = ROOT.gDirectory.Get("EventTree")
    print tr

    tr.MakeClass("Skim")



def parseSkimmer(): 
    f = open("Skim.C","r")
    lines = f.readlines()
    f.close()

    f = open("Skim.C","w")

    includes = """\
#include <iostream>
//#include <stdio>
#include <string>
#include <TLorentzVector.h>
#include \"TROOT.h\"
#include \"TMath.h\"
#include \"TFile.h\"
#include \"TTree.h\"
#include \"TH2.h\"

"""

    createNewFile = """\
	int electronID = 11;
	int photonID = 12;
//	int nBunches = nBunches_CONDOR;
//	int currBunch = currBunch_CONDOR;
	Long64_t nentries = fChain->GetEntriesFast();
	Long64_t startEntry = 0;
//	if (last_batch < last_batch_CONDOR)
//		{
//		double bunchSize = nentries / nBunches;
//		startEntry = nentries * currBunch;
//		nentries = startEntry + bunchSize;
//		}
	TFile *newFile = new TFile(\"skim.root\",\"recreate\");
	TChain *newchain = (TChain*)fChain->CloneTree(0);
	TTree *newTree = newchain->GetTree();
    
    """

    Selection = """\
//	if (jentry < startEntry) continue;
	if ((ientry % 2000) == 0)
		{
		float perc = float(ientry)*100./float(nentries);
		printf(\"Processed Events \t\t%i\t out of %i \t%.0f %%\\n\",int(ientry), int (nentries), perc);
		}

		float dRcut = 0.7; 
		float phoEtCut = 10;
		float lepPtCut = 15;
		vector<int> cleanPho;
		vector<int> cleanEle;
		vector<int> cleanMu;

//		if (nVtx == 0) continue;
//		if (IsVtxGood == 0) continue;
//		if (IsTracksGood == 0) continue;
/*
		for (int iPho=0; iPho < nPho; iPho++)
			{
//			ET cut
			if (phoEt[iPho] < phoEtCut)	continue;
			if (fabs(phoSCEta[iPho])> 2.5)	continue;
			if (fabs(phoSCEta[iPho]) > 1.4442 && fabs(phoSCEta[iPho]) < 1.566 ) continue;
			if (phoHoverE[iPho] > 0.5 )	continue;
//			if (phoOverlap[iPho] == 1)	continue;
			if (phohasPixelSeed[iPho] == 1)	continue;
			cleanPho.push_back(iPho);
			}
		if (cleanPho.size() == 0) continue;

		for (int iEle=0; iEle < nEle; iEle++)
			{

			if (elePt[iEle] < lepPtCut) continue;
			if (fabs(eleSCEta[iEle]) > 2.5 || ( fabs(eleSCEta[iEle]) > 1.4442 && fabs(eleSCEta[iEle]) < 1.566) ) continue;

			cleanEle.push_back(iEle);
			}

		for (int iMu=0; iMu < nMu; iMu++)
			{
			if (muPt[iMu] < lepPtCut) continue;
			if (fabs(muEta[iMu]) > 2.4 ) continue;
			if (muType[iMu] != 14) continue; // isGlobal && Tracker
			cleanMu.push_back(iMu);
			}
		if (cleanEle.size() < 2 && cleanMu.size() < 2) continue;
*/    

		newTree->Fill();
    """

    for line in lines:
        if ("#include <TCanvas.h>") in line:
            f.write(includes)
        elif "Long64_t nentries = fChain->GetEntriesFast();" in line:
            f.write(createNewFile)
        elif ("// if (Cut(ientry) < 0) continue;") in line:
            f.write(Selection)
        else:
            f.write(line)
    f.close()

    f = open("Skim.C","r")
    lines = f.readlines()
    f.close()
    temp = lines[:-1]
    f = open("Skim.C","w")
    for line in temp:
        f.write(line)

    f.write("""\
      newFile->cd();
      newTree->Write();
      newFile->Close();
      }\n
      """
            )
    f.close()
    
    
def runSkimmer():
    ROOT.gROOT.ProcessLine(".L Skim.C++")
    ROOT.gROOT.ProcessLine("Skim t")
    ROOT.gROOT.ProcessLine("t.Loop()")
    
for file in files:
    
    makeClass(file)
    parseSkimmer()
    runSkimmer()

    local = commands.getoutput("pwd");

    outF = "%s/%s_skim.root"%(local,file.split("/")[-1][:-5])
    os.system("mv skim.root %s"%outF)

    f = ROOT.TFile.Open(file,"READ")
    ROOT.gROOT.cd()
#    h = f.Get("hEvents").Clone()
    h = f.Get("VgAnalyzerKit/hEvents").Clone()
#    h = f.Get("VgNtuplizer/hEvents").Clone()
    f.Close()
    f = ROOT.TFile.Open(outF,"UPDATE")
    f.cd()
    h.Write()
    f.Close()
