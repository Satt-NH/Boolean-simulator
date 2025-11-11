//
// Created by Sat Naing Htun on 15/04/2025.
//

#ifndef AND_OPERATOR_H
#define AND_OPERATOR_H
#include "Boolean_Operator.h"

class AND_Operator : public Boolean_Operator {
  public:
    //return AND
    bool evaluate(bool a, bool b) const override;
    // return explanation of AND
    string getExplanation() const override;
    // return symbol
    string getSymbol() const override;

};
#endif //AND_OPERATOR_H
