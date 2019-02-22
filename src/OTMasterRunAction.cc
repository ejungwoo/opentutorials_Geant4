#include "G4MTRunManager.hh"
#include "OTMasterRunAction.hh"
#include "G4ParticleTable.hh"
#include "G4SystemOfUnits.hh"

OTMasterRunAction::OTMasterRunAction(const char *fileName) // for master
: G4UserRunAction()
{
  fInputFile.open(fileName);
  fInputFile >> fNumEvents;
  G4cout << "Number of events in file: " << fNumEvents << G4endl;

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
  fNumBeamOn = G4MTRunManager::GetMasterRunManager() -> GetNumberOfEventsToBeProcessed();
  G4cout << "Number of events in file: " << fNumEvents << G4endl;
  G4cout << "BeamOn " << fNumBeamOn << G4endl;
}

void OTMasterRunAction::EndOfRunAction(const G4Run*)
{
  G4cout << "End of Run" << G4endl;
}

bool OTMasterRunAction::GeneratePrimaries(G4Event *anEvent)
{
  G4int eventID, numTracks;
  G4double vx, vy, vz;
  if (!(fInputFile >> eventID >> numTracks >> vx >> vy >> vz))
    return false;

  if (numTracks <= 0)
    return false;

  G4int eventCheck = G4int(fNumBeamOn/10);
  if (eventCheck == 0)
    eventCheck = 1;

  if (eventID % eventCheck == 0)
    G4cout << eventID << " / " << fNumBeamOn << G4endl;

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
