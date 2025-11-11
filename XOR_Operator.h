//
// Created by Sat Naing Htun on 15/04/2025.
//

#ifndef XOR_OPERATOR_H
#define XOR_OPERATOR_H
#include "Boolean_Operator.h"

class XOR_Operator : public Boolean_Operator {
  public:
    //return XOR
    bool evaluate (bool a , bool b) const override;
    //return the explanation of XOR
    string getExplanation () const override;
    //return symbol
    string getSymbol () const override;
};
#endif //XOR_OPERATOR_H
