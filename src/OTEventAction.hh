#ifndef OTEVENTACTION_HH
#define OTEVENTACTION_HH

#include "G4UserEventAction.hh"
#include "G4Event.hh"
#include "globals.hh"

class OTEventAction : public G4UserEventAction
{
  public:
    OTEventAction();
    virtual ~OTEventAction();

    // method from the base class
    virtual void BeginOfEventAction(const G4Event* event);
    virtual void EndOfEventAction(const G4Event* event);
};

#endif
