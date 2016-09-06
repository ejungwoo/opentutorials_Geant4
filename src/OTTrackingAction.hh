#pragma once

#include "G4UserTrackingAction.hh"
#include "G4Track.hh"
#include "globals.hh"

#include "OTAna.hh"

class OTTrackingAction : public G4UserTrackingAction
{
  public:
    OTTrackingAction();
    virtual ~OTTrackingAction();

    // method from the base class
    virtual void PreUserTrackingAction(const G4Track* track);
    virtual void PostUserTrackingAction(const G4Track* track);

  private:
    OTAna* fAna;
};
