#ifndef OTMESSENGER_HH
#define OTMESSENGER_HH

#include "G4UImessenger.hh"
#include "G4UIcommand.hh"
#include "G4UIcmdWithAString.hh"
#include "G4UIcmdWith3VectorAndUnit.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"
#include "OTDetectorConstruction.hh"
#include "OTField.hh"

class OTDCMessenger : public G4UImessenger
{
  public:
    OTDCMessenger(OTDetectorConstruction *dc, OTField *field);
    virtual ~OTDCMessenger();

    void SetNewValue(G4UIcommand *command, G4String value);

  private:
    OTDetectorConstruction *fDetectorConstruction = nullptr;
    OTField *fField = nullptr;

    G4UIcmdWithAString *fCmdSetFieldOption;
    G4UIcmdWith3VectorAndUnit *fCmdSetFieldValue;
    G4UIcmdWithADoubleAndUnit *fCmdSetDetectorRMax;
};

#endif
