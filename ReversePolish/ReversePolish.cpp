/*
    ReversePolish.cpp
    created by Benjamin Duncan
    Dec 17, 2022

    Prompt: Given an arithmetic expr3ession in reverse polish notation,
        write a program to evaluate it. The expression is given as a list
        of numbers and operands. For example:

            [5, 3, '+'] should return 5 + 3 = 8

        Another example:

            [15, 7, 1, 1, '+', '-', '/', 3, '*', 2, 1, 1, '+', '+', '-']

        would return 5 since it is equivalent to 
        
            ((15 / (7 - (1 + 1))) * 3) - (2 + (1 + 1)) = 5

        You can assume that the given expression is always valid.


    Thoughts: 
        - My initial thought ws to go for two stack, stacking both the operands
            and the operators and we went along. However, I realized that was
            unnecessary because I could just apply the operators to the two previously
            stacked operands. So I'm going to try just one stack for the operands and
            apply the operators as I iterate through the list. (Dec 17, 2022)
        - I'm only going to apply +, -, *, and / and not any other operators to keep things
            simple. (Dec 17, 2022)
        - I'm also going to assume that all the operands are below 30. This is because c++
            doesn't support arrays or lists with multiple object types unlike other languages
            like python or javascript. I'm doing this to prevent some work scope creep. (Dec 17, 2022)

    Results (Dec 17, 2022):
        - It worked! That system did work although I had to make some serious assumptions
            about the operands and operators. I wasn't very happy that I had to limit the
            operands to be under 30 because that isn't very realistic or practical. However,
            it worked for these examples.
        - During my research for a work around of the above bullet point, I found out about c++
            unions which are really interesting. They also exist in c... very interesting.
        - Because of this particular limitation, I think that I need to begin branching out more
            to other langauges such as python or javascript because they could've handled that limitation
            very easily from what I know of those languages.
*/

#include <iostream>
#include <stack>

#define DEBUG false
#define ARRAY1 {15, 7, 1, 1, '+', '-', '/', 3, '*', 2, 1, 1, '+', '+', '-'}
#define ARRAY1SIZE 15
#define ARRAY2 {5, 3, '+'}
#define ARRAY2SIZE 3

#define ARRAY ARRAY2
#define ARRAYSIZE ARRAY2SIZE

using namespace std;

int evaluateReversePolish(char list[]) {
    stack<int> operands = stack<int>();

    for (int i = 0; i < ARRAYSIZE; i++) {
        if (list[i] < 31) {
            operands.push((int) list[i]);
        } else {
            int operand1 = operands.top();
            operands.pop();
            int operand2 = operands.top();
            operands.pop();
            int result;

            switch (list[i]) {
                case '+': result = operand2 + operand1; break;
                case '-': result = operand2 - operand1; break;
                case '*': result = operand2 * operand1; break;
                case '/': result = operand2 / operand1; break;
                default:
                    cout << "UNKNOWN OPERATOR";
                    result = 0;
                    break;
            }

            operands.push(result);
        }

        if (DEBUG) {
            cout << "top operand: " << operands.top() << endl;
        }
    }
    
    return operands.top();
}

int main() {
    char list [ARRAYSIZE] = ARRAY; 

    cout << "Evaluating: ";

    for (int i = 0; i < ARRAYSIZE; i++) {
        if (list[i] < 31) {
            cout << (int) list[i] << " ";
        } else {
            cout << list[i] << " ";
        }
    }

    cout << endl;

    int result = evaluateReversePolish(list);

    cout << "Evaluated to: " << result << endl;
    
    return 0;
}