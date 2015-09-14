#!/bin/bash

#
# variables from arguments string in jdl
#
# format:
#
# 1: condor cluster number
# 2: condor process number
# 3: CMSSW_DIR
# 4: CARD FILE

CONDOR_CLUSTER=$1
CONDOR_PROCESS=$2
CMSSW_DIR=$3
CARD_FILE=$4

#
# header 
#

echo ""
echo "CMSSW on Condor"
echo ""

START_TIME=`/bin/date`
echo "started at $START_TIME"

echo ""
echo "parameter set:"
echo "CONDOR_CLUSTER: $CONDOR_CLUSTER"
echo "CONDOR_PROCESS: $CONDOR_PROCESS"
echo "CMSSW_DIR: $CMSSW_DIR"
echo "CARD FILE: $CARD_FILE"

#
# setup software environment at FNAL for the given CMSSW release
#
source /uscmst1/prod/sw/cms/shrc uaf
export SCRAM_ARCH=slc5_amd64_gcc434
cd $CMSSW_DIR
eval `scramv1 runtime -sh`

#
# setup certificate to copy files to dCache
#
export X509_USER_PROXY=/uscms/home/iraklich/x509up_u42293


#
# change to output directory
#
cd $_CONDOR_SCRATCH_DIR
#
# modify parameter-set
#

FINAL_LOG=`echo ${CONDOR_CLUSTER}_${CONDOR_PROCESS}_${CARD_FILE}.log`

#cat $CARD_FILE | sed -e s/CONDOR_METHOD/$CONDOR_PROCESS/ > $CARD_FILE

#
# run cmssw
#

echo "run: myMinexam $CARD_FILE > $FINAL_LOG 2>&1\n"
./myMinexam $CARD_FILE > $FINAL_LOG 2>&1

exitcode=$?

#
# move output file to dCache
#
#echo "copy to dCache: /opt/d-cache/srm/bin/srmcp \"file://localhost/${PWD}/$FINAL_OUTPUT_FILENAME\" \"srm://cmssrm.fnal.gov:8443/11/store/user/iraklich/Zgamma/BAUR/02_001/$FINAL_OUTPUT_FILENAME\""

#/opt/d-cache/srm/bin/srmcp "file://localhost/${PWD}/$FINAL_OUTPUT_FILENAME" "srm://cmssrm.fnal.gov:8443/11/store/user/iraklich/Zgamma/BAUR/02_001/$FINAL_OUTPUT_FILENAME"

#
# remove files from condor scratch directory so they are not transferred to local directory ON_EXIT (or whatever parameter given in batch.jdl)
#
#echo "rm $FINAL_OUTPUT_FILENAME"
#rm $FINAL_OUTPUT_FILENAME

#
# end run
#

echo ""
END_TIME=`/bin/date`
echo "finished at $END_TIME"
exit $exitcode
