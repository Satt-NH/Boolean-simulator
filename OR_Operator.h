//
// Created by Sat Naing Htun on 15/04/2025.
//

#ifndef OR_OPERATOR_H
#define OR_OPERATOR_H
#include "Boolean_Operator.h"


class OR_Operator : public Boolean_Operator {
  public:
    // return a OR b
    bool evaluate (bool a, bool b) const override;

    // return the explanation of OR
    string getExplanation () const override;

    //return symbol
    string getSymbol () const override;
};

#endif //OR_OPERATOR_H
