#include "OTRunAction.hh"

OTRunAction::OTRunAction()
: G4UserRunAction()
{
}

OTRunAction::~OTRunAction()
{
  delete G4AnalysisManager::Instance();
}

void OTRunAction::BeginOfRunAction(const G4Run*)
{
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
  analysisManager -> OpenFile("data");

  analysisManager -> CreateNtuple("event", "energy deposit per event in volume-1");
  analysisManager -> CreateNtupleDColumn("edep1");
  analysisManager -> FinishNtuple();
}

void OTRunAction::EndOfRunAction(const G4Run*)
{
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
  analysisManager -> Write();
  analysisManager -> CloseFile();
}
