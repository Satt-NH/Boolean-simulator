//
// Created by Sat Naing Htun on 15/04/2025.
//

#ifndef BOOLEAN_OPERATOR_H
#define BOOLEAN_OPERATOR_H
#include <string>
using namespace std;

class Boolean_Operator {
  public:
    //pure virtual function to evaluate logic ( 2 inputs, = flase for NOT to ignore b)
    virtual bool evaluate(bool a, bool b=false) const = 0;
    virtual string getExplanation() const =0; // return explanation
    virtual string getSymbol () const = 0; // return symbol
    virtual ~Boolean_Operator() {} // destructor to cleanup
};


#endif //BOOLEAN_OPERATOR_H
