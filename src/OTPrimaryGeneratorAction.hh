#ifndef OTPRIMARYGENERATORACTION_HH
#define OTPRIMARYGENERATORACTION_HH

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4Event.hh"
#include "globals.hh"

class OTPrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
  public:
    OTPrimaryGeneratorAction();    
    virtual ~OTPrimaryGeneratorAction();

    // method from the base class
    virtual void GeneratePrimaries(G4Event*);         
};

#endif
