//
// Created by Sat Naing Htun on 15/04/2025.
//

#include "XOR_Operator.h"

bool XOR_Operator::evaluate (bool a, bool b) const {
  return a != b;
}

string XOR_Operator::getExplanation ()const {
  return "True if exactly one input is true.";
}

string XOR_Operator::getSymbol ()const {
  return "XOR";
}
