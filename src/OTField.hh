#ifndef OTFIELD
#define OTFIELD

#include "G4ElectroMagneticField.hh"

class OTField : public G4ElectroMagneticField
{
  public:
    OTField() {}
    virtual ~OTField() {}

    virtual G4bool DoesFieldChangeEnergy() const { return false; }

    virtual void GetFieldValue(const G4double point[4], G4double *field) const;
};

#endif
