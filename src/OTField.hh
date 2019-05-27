#ifndef OTFIELD
#define OTFIELD

#include "G4ElectroMagneticField.hh"
#include "G4SystemOfUnits.hh"
#include "G4ThreeVector.hh"

class OTField : public G4ElectroMagneticField
{
  public:
    OTField() {}
    virtual ~OTField() {}

    virtual G4bool DoesFieldChangeEnergy() const { return false; }

    virtual void GetFieldValue(const G4double point[4], G4double *field) const;

    void SetFieldValue(G4ThreeVector value) {
      fBx = value.x();
      fBy = value.y();
      fBz = value.z();
    }

  private:
    G4double fBx = 0.;
    G4double fBy = 0.;
    G4double fBz = .5 * tesla;
};

#endif
