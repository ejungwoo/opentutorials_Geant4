#include "OTPrimaryGeneratorAction.hh"

#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4RunManager.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"

#include "G4MTRunManager.hh"
#include "OTRunAction.hh"

OTPrimaryGeneratorAction::OTPrimaryGeneratorAction()
: G4VUserPrimaryGeneratorAction()
{
}

OTPrimaryGeneratorAction::~OTPrimaryGeneratorAction()
{
}

void OTPrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
  //this function is called at the begining of each event

  auto runAction = (OTRunAction *) G4MTRunManager::GetMasterRunManager() -> GetUserRunAction();
  runAction -> GeneratePrimaries(anEvent);
}
