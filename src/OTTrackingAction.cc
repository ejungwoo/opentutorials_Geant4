#include "OTTrackingAction.hh"

#include "G4Event.hh"
#include "G4RunManager.hh"

#include "G4ThreeVector.hh"

OTTrackingAction::OTTrackingAction()
: G4UserTrackingAction()
{
  fAna = OTAna::GetInstance();
}

OTTrackingAction::~OTTrackingAction()
{
}

void OTTrackingAction::PreUserTrackingAction(const G4Track* track)
{
  fAna -> SetTrackID(track -> GetTrackID());

  G4ThreeVector v = track -> GetMomentum();

  Double_t x = v.x();
  Double_t y = v.y();
  Double_t z = v.z();

  fAna -> Fill(track -> GetParentID(),
               track -> GetDefinition() -> GetPDGEncoding(),
               x, y, z);
}

void OTTrackingAction::PostUserTrackingAction(const G4Track* track)
{
}
