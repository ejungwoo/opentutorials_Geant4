#include "OTField.hh"
#include "G4SystemOfUnits.hh"

void OTField::GetFieldValue(const G4double point[4], G4double *field) const
{
  // input
  G4double x = point[0]; // x-axis position
  G4double y = point[1]; // y-axis position
  G4double z = point[2]; // z-axis position
  G4double t = point[3]; // time

  //
  G4double bx = 0.;
  G4double by = 0.;
  G4double bz = .5*tesla;

  G4double ex = 0.;
  G4double ey = 0.;
  G4double ez = 0.;

  // set output
  field[0] = bx; // b-field x-component
  field[1] = by; // b-field y-component
  field[2] = bz; // b-field z-component

  field[3] = ex; // e-field x-component
  field[4] = ey; // e-field y-component
  field[5] = ez; // e-field z-component
}
