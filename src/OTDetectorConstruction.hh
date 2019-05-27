#ifndef OTDETECTORCONSTRUCTION_HH
#define OTDETECTORCONSTRUCTION_HH

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"
#include "OTField.hh"

class G4VPhysicalVolume;
class G4LogicalVolume;

class OTDetectorConstruction : public G4VUserDetectorConstruction
{
  public:
    OTDetectorConstruction();
    virtual ~OTDetectorConstruction();

    virtual G4VPhysicalVolume* Construct();

    void SetGlobalField();
    void SetLocalField();

  private:
    OTField *fField;
    G4LogicalVolume *logic_detector;
};

#endif
