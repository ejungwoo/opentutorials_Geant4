#include "OTDCMessenger.hh"
#include "G4ApplicationState.hh"

OTDCMessenger::OTDCMessenger(OTDetectorConstruction *dc, OTField *field)
{
  fDetectorConstruction = dc;
  fField = field;

  fCmdSetFieldOption = new G4UIcmdWithAString("/ot/field/option", this);
  fCmdSetFieldValue = new G4UIcmdWith3VectorAndUnit("/ot/field/value", this);
}

OTDCMessenger::~OTDCMessenger()
{
  delete fCmdSetFieldOption;
  delete fCmdSetFieldValue;
}

void OTDCMessenger::SetNewValue(G4UIcommand *command, G4String value)
{
  if (command == fCmdSetFieldOption) {
         if (value =="global") fDetectorConstruction -> SetGlobalField();
    else if (value =="local")  fDetectorConstruction -> SetLocalField();
    fCmdSetFieldOption -> GetStateList() -> clear();
  }
  else if (command == fCmdSetFieldValue) {
    fField -> SetFieldValue(fCmdSetFieldValue -> GetNew3VectorValue(value));
  }
}
