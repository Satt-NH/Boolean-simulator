#include "Boolean_Expression.h"
#include "TruthTable.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int choice;
    cout << "\n*** BOOLEAN TRUTH TABLE SIMULATOR ***\n";
    cout << "1. Enter new Boolean Expression\n";
    cout << "2. Load and view saved truth table file\n";
    cout << "Choose an option (1 or 2): ";
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
        string input;
        cout << "\nEnter Boolean Expression (max 3 operators, variables A, B, C)\n> ";
        getline(cin, input);

        Boolean_Expression expr(input);
        expr.parse();

        TruthTable table(expr);
        table.generate();
    }
    else if (choice == 2) {
        string filename;
        cout << "\nEnter a filename to load : ";
        getline(cin, filename);

        if (filename.find(".txt") == string::npos) {
            filename += ".txt";
        }
        ifstream inFile(filename);
        if (!inFile) {
            cerr << "Error: could not open a file" << filename << "." << endl;
            return 1;
        }
        cout << "\n--- Contents of " << filename << " ---\n\n";
        string line;
        while (getline(inFile, line)) {
            cout << line << "\n";
        }
        inFile.close();
    }
    else {
        cout << "Invalid choice!"<<endl;
    }
    return 0;
}