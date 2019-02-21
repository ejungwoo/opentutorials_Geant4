#ifndef OTACTIONINITIALIZATION_H
#define OTACTIONINITIALIZATION_H

#include "G4VUserActionInitialization.hh"

class OTActionInitialization : public G4VUserActionInitialization
{
  public:
    OTActionInitialization();
    virtual ~OTActionInitialization();

    virtual void BuildForMaster() const;
    virtual void Build() const;
};

#endif
