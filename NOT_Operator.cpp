//
// Created by Sat Naing Htun on 15/04/2025.
//

#include "NOT_Operator.h"

bool NOT_Operator::evaluate(bool a, bool)const {
  return !a;
}

string NOT_Operator::getExplanation () const {
  return "Inverts the input.";
}

string NOT_Operator::getSymbol () const {
  return "NOT";
}

