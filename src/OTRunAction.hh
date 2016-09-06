#ifndef OTRUNACTION_HH
#define OTRUNACTION_HH

#include "G4UserRunAction.hh"
#include "G4Run.hh"
#include "globals.hh"

class OTRunAction : public G4UserRunAction
{
  public:
    OTRunAction();
    virtual ~OTRunAction();

    // method from the base class
    virtual void BeginOfEventAction(const G4Run* run);
    virtual void EndOfEventAction(const G4Run* run);
};

#endif
