#include "OTEventAction.hh"

#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4AnalysisManager.hh"

OTEventAction::OTEventAction()
: G4UserEventAction()
{
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
}

OTEventAction::~OTEventAction()
{
}

void OTEventAction::BeginOfEventAction(const G4Event* event)
{
}

void OTEventAction::EndOfEventAction(const G4Event* event)
{
}
