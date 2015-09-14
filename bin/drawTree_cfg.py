import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

process.load("FWCore.MessageService.MessageLogger_cfi")
process.load("SimGeneral.HepPDTESSource.pythiapdt_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )


process.printTree = cms.EDAnalyzer("ParticleListDrawer",
                                   maxEventsToPrint = cms.untracked.int32(2),
                                   printVertex = cms.untracked.bool(False),
                                   src = cms.InputTag("genParticles")
                                   )

process.MessageLogger.cerr.FwkReport.reportEvery=cms.untracked.int32(5000)

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
    'file:/uscmst1b_scratch/lpc1/old_scratch/lpceg/yurii/iraklis/VGAMMA/2011/mc/MC_CMSSW415_vgamma_41x_v5_NewRho/DYJetsToLL_TuneZ2_M50_Madgraph_Spring11.root')
)


process.p = cms.Path(process.printTree)

