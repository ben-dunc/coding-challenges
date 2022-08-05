/*
    Filename: BalancedBrackets.cpp
    Author: Benjamin Duncan
    Date of creation: Aug 4, 2022

    Daily Coding problem # 27
    Difficulty: Easy
    Interviewing company: Facebook

    To run: g++ BalancedBrackets.cpp && ./a.out asdf "([])[]({})" "([)]" "((()"

    Problem: Given a string of round, curly, and square open and closing brackets, return whether the brackets are balanced (well-formed).

    For example, given the string "([])[]({})", you should return true.
    Given the string "([)]" or "((()", you should return false.
*/

/*
    NOTES

    Initial ideas:
    -   I thought at first of just counting the different brackets and checking if they're above 0 while parsing the string and
        equal to 0 at the end. However, that wouldn't work well for the first negative example.
    -   My second thought that I think I will go with is to create a enum for the brackets and keep a stack of the open brackets,
        poping them off when I encounter a closing bracket. If they match, pop off the top and continue. If they don't, or there isn't
        anymore items in the stack, then it's unbalanced.
        -   On second thought, I'll just make a stack of characters.
*/

#include <string>
#include <stack>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

    const char OPENING_PAR = '(';
    const char CLOSING_PAR = ')';
    const char OPENING_BRACKET = '[';
    const char CLOSING_BRACKET = ']';
    const char OPENING_BRACE = '{';
    const char CLOSING_BRACE = '}';

    stack<char> bracketStack;

    bool success = true;
    bool hasBrackets = false;
    
    for (int i = 1; i < argc; i++) {
        string brackets = argv[i];

        cout << "Parsing " << brackets << endl;

        for (char c: brackets) {
            if (c == OPENING_BRACE || c == OPENING_BRACKET || c == OPENING_PAR) {
                hasBrackets = true;
                bracketStack.push(c);
            } else if (c == CLOSING_BRACE || c == CLOSING_BRACKET || c == CLOSING_PAR) {
                hasBrackets = true;
                if (bracketStack.empty()) {
                    success = false;
                    break;
                }

                char c1 = bracketStack.top();

                if (c1 == OPENING_BRACE && c == CLOSING_BRACE || c1 == OPENING_BRACKET && c == CLOSING_BRACKET || c1 == OPENING_PAR && c == CLOSING_PAR) {
                    bracketStack.pop();
                } else {
                    success = false;
                    break;
                }
            } else {
                cout << "\tIgnoring '" << c << "' because it is not a bracket." << endl;
            }
        }

        if (success && hasBrackets) {
            cout << "Success! The string (" << brackets << ") has balanced brackets." << endl;
        } else if (!hasBrackets) {
            cout << "This string (" << brackets << ") didn't even have brackets! " << endl;
        } else {
            cout << "Failure! The string (" << brackets << ") has imbalanced brackets." << endl;
        }
        cout << endl;
    }

    return 0;
}



