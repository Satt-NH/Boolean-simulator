//
// Created by Sat Naing Htun on 15/04/2025.
//

#include "NAND_Operator.h"

bool NAND_Operator::evaluate(bool a, bool b) const {
  return !(a && b);
}
string NAND_Operator::getExplanation () const {
  return "False if only both inputs are true. (Inverse of AND)";
}
string NAND_Operator::getSymbol () const {
  return "NAND";
}