#include "OTDetectorConstruction.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

#include "G4Tubs.hh"
#include "G4VisAttributes.hh"
#include "G4Colour.hh"

#include "G4TransportationManager.hh"
#include "G4FieldManager.hh"

#include "OTDCMessenger.hh"

OTDetectorConstruction::OTDetectorConstruction()
: G4VUserDetectorConstruction()
{
  fField = new OTField();
  new OTDCMessenger(this, fField);
}

OTDetectorConstruction::~OTDetectorConstruction()
{
}

G4VPhysicalVolume* OTDetectorConstruction::Construct()
{
  // Material
  G4NistManager* nist = G4NistManager::Instance();
  auto air = nist -> FindOrBuildMaterial("G4_AIR");
  auto vacuum = new G4Material("vacuum", 1.e-15*g/cm3, 1);
  vacuum -> AddMaterial(air, 1);


  // World
  G4double world_size = 5000*mm;
  auto solid_world = new G4Box("World", 0.5*world_size, 0.5*world_size, 0.5*world_size);
  auto logic_world = new G4LogicalVolume(solid_world, air, "World");
  auto physi_world = new G4PVPlacement(0, G4ThreeVector(), logic_world, "World", 0, false, 0, true);


  // Detector
  G4double detector_rMin = 500*mm;
  G4double detector_height = 500*mm;
  auto solid_detector = new G4Tubs("Detector", detector_rMin, detector_rMax, detector_height/2., 0, 2*CLHEP::pi);
  logic_detector = new G4LogicalVolume(solid_detector, vacuum, "Detector");
  new G4PVPlacement(0, G4ThreeVector(), logic_detector, "Detector", logic_world, false, 1, true);


  // Visualization Attribute
  auto visat_world = new G4VisAttributes();
  visat_world -> SetColor(G4Colour::Green());
  visat_world -> SetForceWireframe(true);
  logic_world -> SetVisAttributes(visat_world);

  auto visat_detector = new G4VisAttributes();
  visat_detector -> SetColor(G4Colour(0.8,0.8,0.8,0.3));
  logic_detector -> SetVisAttributes(visat_detector);




  return physi_world;
}

void OTDetectorConstruction::SetGlobalField()
{
  auto fieldManager = G4TransportationManager::GetTransportationManager() -> GetFieldManager();
  fieldManager -> SetDetectorField(fField);
  fieldManager -> CreateChordFinder((G4MagneticField *) fField);
}

void OTDetectorConstruction::SetLocalField()
{
  auto fieldManager = new G4FieldManager();
  fieldManager -> SetDetectorField(fField);
  fieldManager -> CreateChordFinder((G4MagneticField *) fField);
  logic_detector -> SetFieldManager(fieldManager, true);
}
