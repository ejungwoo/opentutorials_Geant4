#include "OTRunAction.hh"

OTRunAction::OTRunAction()
: G4UserRunAction()
{
  fName = "data";
}

OTRunAction::OTRunAction(const char *name)
: G4UserRunAction()
{
  fName = name;
}

OTRunAction::~OTRunAction()
{
  delete G4AnalysisManager::Instance();
}

void OTRunAction::BeginOfRunAction(const G4Run*)
{
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
  analysisManager -> OpenFile(fName);

  analysisManager -> CreateNtuple("step", "step");
  analysisManager -> CreateNtupleIColumn("eventID");
  analysisManager -> CreateNtupleIColumn("volumeID");
  analysisManager -> CreateNtupleDColumn("edep");
  analysisManager -> FinishNtuple();

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
