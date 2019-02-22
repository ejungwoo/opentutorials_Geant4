#include "OTActionInitialization.hh"
#include "OTPrimaryGeneratorAction.hh"
#include "OTMasterRunAction.hh"
#include "OTRunAction.hh"
#include "OTEventAction.hh"
#include "OTSteppingAction.hh"


OTActionInitialization::OTActionInitialization()
: G4VUserActionInitialization()
{
}

OTActionInitialization::~OTActionInitialization()
{
}

void OTActionInitialization::BuildForMaster() const
{
  SetUserAction(new OTMasterRunAction("../primaries.gen"));
}

void OTActionInitialization::Build() const
{
  SetUserAction(new OTPrimaryGeneratorAction);
  SetUserAction(new OTRunAction);
  SetUserAction(new OTEventAction);
  SetUserAction(new OTSteppingAction);
}
