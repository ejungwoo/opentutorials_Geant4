#include "OTSteppingAction.hh"
#include "OTEventAction.hh"

#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4SystemOfUnits.hh"

#include "G4EventManager.hh"

OTSteppingAction::OTSteppingAction()
: G4UserSteppingAction()
{
}

OTSteppingAction::~OTSteppingAction()
{
}

void OTSteppingAction::UserSteppingAction(const G4Step* step)
{
  G4int eventID = G4RunManager::GetRunManager() -> GetCurrentEvent() -> GetEventID();
  G4int volumeID = step -> GetPreStepPoint() -> GetPhysicalVolume() -> GetCopyNo();
  G4double totalEdep = step -> GetTotalEnergyDeposit();

  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
  analysisManager -> FillNtupleIColumn(0, eventID);
  analysisManager -> FillNtupleIColumn(1, volumeID);
  analysisManager -> FillNtupleDColumn(2, totalEdep);
  analysisManager -> AddNtupleRow();

  OTEventAction *eventAction = (OTEventAction *) G4EventManager::GetEventManager() -> GetUserEventAction();
  if (volumeID == 1)
    eventAction -> AddEnergyDeposit1(totalEdep);
}
