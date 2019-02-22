#include "OTMasterRunAction.hh"
#include "G4ParticleTable.hh"
#include "G4SystemOfUnits.hh"
#include "G4AutoLock.hh"

namespace { G4Mutex fMutex = G4MUTEX_INITIALIZER; }

OTMasterRunAction::OTMasterRunAction(const char *fileName) // for master
: G4UserRunAction()
{
  fInputFile.open(fileName);
  G4int numEvents;
  fInputFile >> numEvents;

  fParticleGun = new G4ParticleGun(1);
}

OTMasterRunAction::~OTMasterRunAction()
{
  if(fInputFile.is_open())
    fInputFile.close();

  delete fParticleGun;
}

void OTMasterRunAction::BeginOfRunAction(const G4Run*)
{
}

void OTMasterRunAction::EndOfRunAction(const G4Run*)
{
}

bool OTMasterRunAction::GeneratePrimaries(G4Event *anEvent)
{
  G4AutoLock lock(&fMutex);

  G4int eventID, numTracks;
  G4double vx, vy, vz;
  if (!(fInputFile >> eventID >> numTracks >> vx >> vy >> vz))
    return false;

  if (numTracks <= 0)
    return false;

  fParticleGun -> SetParticlePosition(G4ThreeVector(vx,vy,vz));

  G4int pdg;
  G4double ke, px, py, pz;
  for (G4int iTrack = 0; iTrack < numTracks; ++iTrack) {
    fInputFile >> pdg >> ke >> px >> py >> pz;

    G4ParticleDefinition* particle = G4ParticleTable::GetParticleTable() -> FindParticle(pdg);
    G4ThreeVector direction(px,py,pz);

    fParticleGun -> SetParticleDefinition(particle);
    fParticleGun -> SetParticleEnergy(ke*MeV);
    fParticleGun -> SetParticleMomentumDirection(direction.unit());
    fParticleGun -> GeneratePrimaryVertex(anEvent);
  }

  return true;
}
