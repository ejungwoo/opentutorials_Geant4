#include "OTField.hh"

void OTField::GetFieldValue(const G4double point[4], G4double *field) const
{
  field[0] = fBx;
  field[1] = fBy;
  field[2] = fBz;
}
