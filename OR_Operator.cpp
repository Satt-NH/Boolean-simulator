#include "OR_Operator.h"

bool OR_Operator::evaluate (bool a, bool b) const {
  return a || b;
}

string OR_Operator::getExplanation () const {
  return "True if at least one input is true.";
}

string OR_Operator::getSymbol () const {
  return "OR";
}