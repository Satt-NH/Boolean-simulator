//
// Created by Sat Naing Htun on 16/04/2025.
//

#ifndef TRUTHTABLE_H
#define TRUTHTABLE_H
#include "Boolean_Expression.h"

class TruthTable {
  private:
    Boolean_Expression& expression;

    public:
      TruthTable(Boolean_Expression& expr);

      void generate(); // generate the truth table
};


#endif //TRUTHTABLE_H
