#ifndef OTSTEPPINGACTION_HH
#define OTSTEPPINGACTION_HH

#include "G4UserSteppingAction.hh"
#include "G4Step.hh"
#include "globals.hh"
#include "g4root.hh"

class OTSteppingAction : public G4UserSteppingAction
{
  public:
    OTSteppingAction();
    virtual ~OTSteppingAction();

    // method from the base class
    virtual void UserSteppingAction(const G4Step*);
};

#endif
