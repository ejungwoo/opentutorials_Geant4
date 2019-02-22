#include "globals.hh"

#include "G4MTRunManager.hh"
#include "G4VisExecutive.hh"
#include "G4UImanager.hh"
#include "G4UIExecutive.hh"

#include "QGSP_BERT.hh"
#include "OTDetectorConstruction.hh"
#include "OTActionInitialization.hh"

int main(int argc, char** argv)
{
  G4MTRunManager* runManager = new G4MTRunManager;
  runManager -> SetNumberOfThreads(4);

  G4VModularPhysicsList* physicsList = new QGSP_BERT;
  runManager -> SetUserInitialization(physicsList);
  runManager -> SetUserInitialization(new OTDetectorConstruction());
  runManager -> SetUserInitialization(new OTActionInitialization());
  runManager -> Initialize();
  
  G4VisManager* visManager = new G4VisExecutive;
  visManager -> Initialize();

  G4UImanager* UImanager = G4UImanager::GetUIpointer();
  if (argc != 1) 
  {
    G4String command = "/control/execute ";
    G4String fileName = argv[1];
    UImanager -> ApplyCommand(command+fileName);
  }
  else 
  {
    G4UIExecutive* ui = new G4UIExecutive(argc, argv);
    UImanager -> ApplyCommand("/control/execute vis.mac"); 
    ui -> SessionStart();
    delete ui;
  }

  delete visManager;
  delete runManager;

  return 0;
}
