#include "OTRunAction.hh"
#include "G4ParticleTable.hh"
#include "G4SystemOfUnits.hh"
#include "G4AutoLock.hh"

namespace { G4Mutex fMutex = G4MUTEX_INITIALIZER; }

OTRunAction::OTRunAction()
: G4UserRunAction()
{
}

OTRunAction::OTRunAction(const char *fileName) // for master
: G4UserRunAction()
{
  fInputFile.open(fileName);
  fInputFile >> fNumEvents;
  fParticleGun = new G4ParticleGun(1);
}

OTRunAction::~OTRunAction()
{
  if(fInputFile.is_open())
    fInputFile.close();
  delete fParticleGun;
  delete G4AnalysisManager::Instance();
}

void OTRunAction::BeginOfRunAction(const G4Run*)
{
  if (IsMaster())
    return;

  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
  analysisManager -> OpenFile("data");

  analysisManager -> CreateNtuple("event", "energy deposit per event in volume-1");
  analysisManager -> CreateNtupleDColumn("edep1");
  analysisManager -> FinishNtuple();
}

void OTRunAction::EndOfRunAction(const G4Run*)
{
  if (IsMaster())
    return;

  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
  analysisManager -> Write();
  analysisManager -> CloseFile();
}

bool OTRunAction::GeneratePrimaries(G4Event *anEvent)
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
