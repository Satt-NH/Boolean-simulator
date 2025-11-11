//
// Created by Sat Naing Htun on 16/04/2025.
//

#ifndef BOOLEAN_EXPRESSION_H
#define BOOLEAN_EXPRESSION_H
#include <string>
#include <map>
#include <vector>
#include "Boolean_Operator.h"
using namespace std;

class Boolean_Expression {
  private:
    string rawExpression; // the org user input
    vector<string> LogicUnits; // parse into parts
    vector<string> stepLabels; // order of sub-expressions

    map<string, shared_ptr<Boolean_Operator>> operatorMap;
    vector<shared_ptr<Boolean_Operator>> operatorUsed;

    public:
      Boolean_Expression(const string& expr); // constructor for raw
      void parse();// parse the raw
      vector<string> toPostfix(const vector<string>& infixUnits); // converts infix to postfix
      bool evaluate (bool A, bool B, bool C);
      map <string, bool> evaluateWithSteps(bool A, bool B, bool C); // evaluates and tracks steps for truthtable


      string getRawExpression () const;
      vector<string> getUsedOperators() const;
      vector<string> getStepOrder() const;
      vector<shared_ptr<Boolean_Operator>> getUsedOperatorObj() const;

};

#endif //BOOLEAN_EXPRESSION_H
