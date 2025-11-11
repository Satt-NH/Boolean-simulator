//
// Created by Sat Naing Htun on 16/04/2025.
//

#include "TruthTable.h"
#include <iostream>
#include <iomanip> // formatting
#include <fstream> // to save file
using namespace std;

TruthTable :: TruthTable (Boolean_Expression & expr) : expression (expr) {}

void TruthTable :: generate () {
  cout << "\nGenerating TruthTable for : " << expression.getRawExpression() << endl;

  //explain the operators that user input
  cout << "\n Operators Detected and Explained:" << endl;
  for (const auto& opName : expression.getUsedOperators()) {
   for (const auto& ptr : expression.getUsedOperatorObj()) {
     if (ptr->getSymbol() == opName) {
       cout << "- " << ptr ->getSymbol() << " : " << ptr->getExplanation() << endl;
       break;
     }
   }
  }
  //to show the extract labels based on user input
  expression.evaluateWithSteps(0, 0, 0);
  auto headers = expression.getStepOrder();

  //print header
  cout << "\n| A | B | C ";
  for (const auto& label : headers) {
    cout << "| " << label << " ";
  }
  cout << "|\n";

  //format
  cout << "|---|---|---";
  for (const auto& label : headers) {
    cout << "|";
    cout << string(label.length() +2, '-');
  }
  cout << "|\n";

  //loop through all input and combine
  for (int i=0; i < 8 ; ++i) {
    bool A = (i & 0b100) >> 2;
    bool B = (i & 0b010) >> 1;
    bool C = (i & 0b001);

    cout << "| " << A << " | " << B << " | " << C << " ";

    auto stepResults = expression.evaluateWithSteps(A, B, C);
    for (const auto& label : headers) {
      string result = stepResults.count(label) ? (stepResults[label] ? "1" : "0") : "-";
      cout << "| " << setw(label.length()) << result << " ";
    }
    cout << "|\n";
  }
  cout << endl;

  char choice;
  cout << "Would you like to save this expression and truth table to a file? (Y/N): ";
  cin >> choice;
  cin.ignore();

  if (choice == 'Y' || choice == 'y') {
    string filename;
    cout << "Enter filename: ";
    getline(cin, filename);

    if (filename.find(".txt") == string::npos) {
      filename += ".txt";
    }

    ofstream outFile(filename);
    if (!outFile) {
      cerr << "Error opening file for writing.\n";
      return;
    }
    outFile << "Boolean Expression: " << expression.getRawExpression() <<"\n\n";

    outFile << "\n Operators Detected and Explained:" << endl;
    for (const auto& opName : expression.getUsedOperators()) {
      for (const auto& ptr : expression.getUsedOperatorObj()) {
        if (ptr->getSymbol() == opName) {
          outFile << "- " << ptr ->getSymbol() << " : " << ptr->getExplanation() << endl;
          break;
        }
      }
    }

    //print header
    outFile << "\n| A | B | C ";
    for (const auto& label : headers) {
      outFile << "| " << label << " ";
    }
    outFile << "|\n";

    //format
    outFile << "|---|---|---";
    for (const auto& label : headers) {
      outFile << "|";
      outFile << string(label.length() +2, '-');
    }
    outFile << "|\n";

    //loop through all input and combine
    for (int i=0; i < 8 ; ++i) {
      bool A = (i & 0b100) >> 2;
      bool B = (i & 0b010) >> 1;
      bool C = (i & 0b001);

      outFile << "| " << A << " | " << B << " | " << C << " ";

      auto stepResults = expression.evaluateWithSteps(A, B, C);
      for (const auto& label : headers) {
        string result = stepResults.count(label) ? (stepResults[label] ? "1" : "0") : "-";
        outFile << "| " << setw(label.length()) << result << " ";
      }
      outFile << "|\n";
    }
    outFile << endl;

    outFile.close();
    cout << "Expression saved successfully!" << endl;
  }
}





