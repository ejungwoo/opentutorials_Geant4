#include "OTRunAction.hh"
#include "G4AnalysisManager.hh"

OTRunAction::OTRunAction()
: G4UserRunAction()
{
}

OTRunAction::~OTRunAction()
{
}

void OTRunAction::BeginOfRunAction(const G4Run* run)
{
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
  analysisManager -> OpenFile("OTData");
}

void OTRunAction::EndOfRunAction(const G4Run* run)
{
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
  analysisManager -> Write();
  analysisManager -> CloseFile();
}
