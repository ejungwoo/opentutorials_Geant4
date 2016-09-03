#ifndef OTDETECTORCONSTRUCTION_HH
#define OTDETECTORCONSTRUCTION_HH

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"

class G4VPhysicalVolume;
class G4LogicalVolume;

class OTDetectorConstruction : public G4VUserDetectorConstruction
{
  public:
    OTDetectorConstruction();
    virtual ~OTDetectorConstruction();

    virtual G4VPhysicalVolume* Construct();
};

#endif
