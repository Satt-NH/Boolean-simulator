//
// Created by Sat Naing Htun on 15/04/2025.
//

#include "AND_Operator.h"

bool AND_Operator::evaluate (bool a, bool b) const {
  return a && b;
}
string AND_Operator::getExplanation() const {
  return "True only if both inputs are true";
}
string AND_Operator::getSymbol() const {
  return "AND";
}


