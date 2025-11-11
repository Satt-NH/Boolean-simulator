//
// Created by Sat Naing Htun on 15/04/2025.
//

#ifndef NAND_OPERATOR_H
#define NAND_OPERATOR_H
#include "Boolean_Operator.h"

class NAND_Operator : public Boolean_Operator {
  public:
    //return NAND
    bool evaluate(bool a, bool b) const override;
    // return the explanation of NAND
    string getExplanation() const override;
    // return symbol
    string getSymbol() const override;
};

#endif //NAND_OPERATOR_H
