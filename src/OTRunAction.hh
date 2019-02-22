#ifndef OTRUNACTION_HH
#define OTRUNACTION_HH

#include "G4UserRunAction.hh"
#include "G4Run.hh"
#include "globals.hh"
#include "g4root.hh"
#include <fstream>

#include "G4ParticleGun.hh"

class OTRunAction : public G4UserRunAction
{
  public:
    OTRunAction();
    virtual ~OTRunAction();

    // method from the base class
    virtual void BeginOfRunAction(const G4Run*);
    virtual void EndOfRunAction(const G4Run*);
};

#endif
