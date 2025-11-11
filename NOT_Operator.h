//
// Created by Sat Naing Htun on 15/04/2025.
//

#ifndef NOT_OPERATOR_H
#define NOT_OPERATOR_H
#include "Boolean_Operator.h"

class NOT_Operator : public Boolean_Operator {
  public:
    //return NOT
    bool evaluate(bool a, bool b= false) const override;
    // retrun the explanation of NOT
    string getExplanation () const override;
    //return symbol
    string getSymbol () const override;
};


#endif //NOT_OPERATOR_H
