//
// Created by Sat Naing Htun on 16/04/2025.
//

#include "Boolean_Expression.h"
#include "Boolean_Operator.h"
#include "AND_Operator.h"
#include "OR_Operator.h"
#include "NOT_Operator.h"
#include "XOR_Operator.h"
#include "NAND_Operator.h"
#include "NOR_Operator.h"

#include <sstream>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

Boolean_Expression::Boolean_Expression(const string& expr) : rawExpression(expr) { // initialize all operators in Map
  operatorMap["AND"] = make_shared<AND_Operator>();
  operatorMap["OR"] = make_shared<OR_Operator>();
  operatorMap["NOT"] = make_shared<NOT_Operator>();
  operatorMap["NAND"] = make_shared<NAND_Operator>();
  operatorMap["NOR"] = make_shared<NOR_Operator>();
  operatorMap["XOR"] = make_shared<XOR_Operator>();
}
// parse the raw expression into logic units like ( A, AND , B , OR , NOT , C) seperately
void Boolean_Expression::parse() {
  stringstream ss(rawExpression);
  string unit;

  while (ss >> unit) { // handle the parenthesis
    if (unit.front() == '(' && unit.length() > 1) {
      LogicUnits.push_back("(");
      unit= unit.substr(1);
    }
    if (unit.back() == ')' && unit.length() > 1) {
      unit = unit.substr(0, unit.length() - 1);
      LogicUnits.push_back(unit);
      LogicUnits.push_back(")");
      continue;
    }
    LogicUnits.push_back(unit);
    string upperUnit = unit;
    // track the operators Used ( make case insensitive)
    transform(upperUnit.begin(), upperUnit.end(), upperUnit.begin() , ::toupper);
    if (operatorMap.count(upperUnit)) {
         operatorUsed.push_back (operatorMap[upperUnit]);
    }
  }
}
// Converts into post fix
vector<string> Boolean_Expression :: toPostfix (const vector<string>& infixUnits ) {
  vector<string> postfix;
  stack<string> opStack;

  // declare the precedence
  map <string, int> precedence = {
    {"NOT", 3},
    {"AND",2},
    {"OR",1},
    {"XOR",1},
    {"NAND",2},
    {"NOR",1}
  };

  for (const string& unit : LogicUnits) {
    string upper = unit;
    // convert into upper cases
    transform (upper.begin(), upper.end(), upper.begin(), :: toupper);
    //A,B,C go directly into postfix
    if (upper == "A" || upper == "B" || upper == "C") {
      postfix.push_back(upper);
    }
    // left parenthesis
    else if (upper == "(") {
      opStack.push(upper);
    }
    else if (upper == ")") { // pop everything until (
      while (!opStack.empty() && opStack.top() != "(") {
        postfix.push_back(opStack.top());
        opStack.pop();
      }
      if (!opStack.empty()) opStack.pop(); // remove ( from stack
    }
    else if (precedence.count(upper)) {
      // compare precedence with top of stack
      while (!opStack.empty() && precedence.count(opStack.top()) &&
             precedence[opStack.top()] >= precedence[upper]) {
        postfix.push_back(opStack.top());
        opStack.pop();
             }
             opStack.push(upper); // push current operator
    }
  }
  while (!opStack.empty()) { // pop remaining operators
    postfix.push_back(opStack.top());
    opStack.pop();
  }
  return postfix;
}

bool Boolean_Expression :: evaluate (bool A, bool B, bool C) {
  vector <string> postfix = toPostfix(LogicUnits);
  stack<bool> evalStack;

  for (const string& unit : postfix) { // converts to upper cases
    string upper = unit;
    transform (upper.begin(), upper.end() , upper.begin(), :: toupper);

    // Variable check to push the value onto the stack
    if (upper == "A") {
      evalStack.push(A);
    }
    else if (upper == "B"){
      evalStack.push(B);
    }
    else if (upper == "C"){
      evalStack.push(C);
    }
    //check the operators
    else if (operatorMap.count(upper)) {
      auto op = operatorMap[upper];

      if (upper == "NOT") { // evaluation for NOT
        bool a = evalStack.top(); evalStack.pop();
        bool result = op -> evaluate (a);
        evalStack.push(result);
      }
      else { // evaluate for other operators
        bool b = evalStack.top(); evalStack.pop();
        bool a = evalStack.top(); evalStack.pop();
        bool result = op -> evaluate (a,b);
        evalStack.push(result);
      }
    }
  }
  // check there is result in the stack
  return !evalStack.empty() ? evalStack.top() : false;
}

map<string, bool> Boolean_Expression :: evaluateWithSteps (bool A, bool B, bool C) {
  vector <string> postfix = toPostfix(LogicUnits);
  stack <pair <string, bool >> evalStack;

  map<string, bool> stepResults;
  stepLabels.clear();

  for (const string& unit : postfix) {
    string upper = unit;
    transform (upper.begin(), upper.end() , upper.begin(), :: toupper);

    if (upper == "A" || upper == "B" || upper == "C") {
      bool value = (upper == "A") ? A : (upper == "B") ? B : C;
      evalStack.push({upper, value});
    }
    else if (operatorMap.count(upper)) {
      auto op = operatorMap[upper];

     if (upper == "NOT") {
      auto a = evalStack.top(); evalStack.pop();
      bool result = op -> evaluate (a.second);
      string label = "NOT" + a.first;

      stepResults[label] = result;
      stepLabels.push_back(label);
      evalStack.push({label, result});
    }
    else {
      auto b = evalStack.top(); evalStack.pop();
      auto a = evalStack.top(); evalStack.pop();
      string label = "(" + a.first + " " + upper + " " + b.first + ")";
      bool result = op -> evaluate (a.second, b.second);

      stepResults[label] = result;
      stepLabels.push_back(label);
      evalStack.push({label, result});

        }
     }
  }
return stepResults;
}

string Boolean_Expression :: getRawExpression () const {
  return rawExpression;
}

vector <string> Boolean_Expression :: getUsedOperators () const {
  vector < string > result;
  for (const auto& op : operatorUsed) {
    result.push_back(op -> getSymbol());
  }
  return result;
}
vector <string> Boolean_Expression :: getStepOrder () const {
  return stepLabels;
}
vector <shared_ptr<Boolean_Operator>> Boolean_Expression ::getUsedOperatorObj () const {
  return operatorUsed;
}