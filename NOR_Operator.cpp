//
// Created by Sat Naing Htun on 15/04/2025.
//

#include "NOR_Operator.h"

bool NOR_Operator::evaluate (bool a, bool b) const {
    return !(a || b);
}

string NOR_Operator::getExplanation() const {
    return "True only if both inputs are false. (Inverse of OR)";
}

string NOR_Operator::getSymbol() const {
    return "NOR";
}


