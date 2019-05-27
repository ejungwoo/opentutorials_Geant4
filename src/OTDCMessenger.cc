#include "OTDCMessenger.hh"
#include "G4ApplicationState.hh"

OTDCMessenger::OTDCMessenger(OTDetectorConstruction *dc, OTField *field)
{
  fDetectorConstruction = dc;
  fField = field;

  fCmdSetFieldOption = new G4UIcmdWithAString("/ot/field/option", this);
  fCmdSetFieldOption -> SetCandidates("global local");
  fCmdSetFieldOption -> SetGuidance("Set field option");
  fCmdSetFieldOption -> SetGuidance("global: set global field");
  fCmdSetFieldOption -> SetGuidance("local: set local field for the detector");

  fCmdSetFieldValue = new G4UIcmdWith3VectorAndUnit("/ot/field/value", this);

  fCmdSetDetectorRMax = new G4UIcmdWithADoubleAndUnit("/ot/detector/rmax", this);
  fCmdSetDetectorRMax -> AvailableForStates(G4State_PreInit);
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
  else if (command == fCmdSetDetectorRMax ) {
    fDetectorConstruction -> SetDetectorRMax(fCmdSetDetectorRMax  -> GetNewDoubleValue(value));
  }
}
