//
// Created by Sat Naing Htun on 15/04/2025.
//

#ifndef NOR_OPERATOR_H
#define NOR_OPERATOR_H
#include "Boolean_Operator.h"
class NOR_Operator : public Boolean_Operator {
  public:
    //return NOR
    bool evaluate (bool a, bool b) const override;
    // return the explanation of NOR
    string getExplanation () const override;
    // return symbol
    string getSymbol () const override;

};
#endif //NOR_OPERATOR_H
