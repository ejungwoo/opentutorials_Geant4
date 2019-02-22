#ifndef OTMASTERRUNACTION_HH
#define OTMASTERRUNACTION_HH

#include "G4UserRunAction.hh"
#include "G4Run.hh"
#include "globals.hh"
#include "g4root.hh"
#include <fstream>

#include "G4ParticleGun.hh"

class OTMasterRunAction : public G4UserRunAction
{
  public:
    OTMasterRunAction(const char *fileName);
    virtual ~OTMasterRunAction();

    // method from the base class
    virtual void BeginOfRunAction(const G4Run*);
    virtual void EndOfRunAction(const G4Run*);

    bool GeneratePrimaries(G4Event *anEvent);

  private:
    G4ParticleGun* fParticleGun;
    std::ifstream fInputFile;
    G4int fNumEvents;
    G4int fNumBeamOn;
};

#endif
