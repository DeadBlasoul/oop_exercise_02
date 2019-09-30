// stdlib headers:
#include <cstdio>
#include <iostream>
#include <string>

// LabLib headers:
#include <lab/complex.hpp>

using namespace std;

void ToUpper(string& str);

int main() {
    string input;
    while (cin) {
        cin >> input;
        ToUpper(input);
        Complex left, right;
        left.Read(cin);
        right.Read(cin);

        if (cin.fail()) {
            break;
        }

        if (input == "ADD") {
            cout << left + right;
        }
        else if (input == "SUB") {
            cout << left - right;
        }
        else if (input == "MUL") {
            cout << left * right;
        }
        else if (input == "DIV") {
            cout << left / right;
        }
        else if (input == "EQU") {
            cout << ((left == right) ? "True" : "False");
        }
        else if (input == "CMP") {
            cout << Compare(left, right);
        }
        cout << endl;
        cout.flush();
    };
}

void ToUpper(string& str) {
    for (auto& c : str) {
        c = static_cast<remove_reference_t<decltype(c)>>(toupper(c));
    }
}
