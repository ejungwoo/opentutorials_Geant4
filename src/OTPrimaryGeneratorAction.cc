#include "OTPrimaryGeneratorAction.hh"

OTPrimaryGeneratorAction::OTPrimaryGeneratorAction()
: G4VUserPrimaryGeneratorAction()
{
  fParticleGun = new G4GeneralParticleSource();
}

OTPrimaryGeneratorAction::~OTPrimaryGeneratorAction()
{
  delete fParticleGun;
}

void OTPrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
  fParticleGun -> GeneratePrimaryVertex(anEvent);
}
