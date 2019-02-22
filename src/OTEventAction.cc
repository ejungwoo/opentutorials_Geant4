#include "OTEventAction.hh"

OTEventAction::OTEventAction()
: G4UserEventAction()
{
}

OTEventAction::~OTEventAction()
{
}

void OTEventAction::BeginOfEventAction(const G4Event*)
{
  edep1 = 0.;
}

void OTEventAction::EndOfEventAction(const G4Event*)
{
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();

  analysisManager -> FillNtupleDColumn(0, edep1);
  analysisManager -> AddNtupleRow();
}
