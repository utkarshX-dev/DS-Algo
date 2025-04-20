#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '^') return 3;
    return 0;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^';
}

bool isOperand(char c) {
    return isalnum(c);
}

string infixToPostfix(string infix) {
    stack<char> st;
    string postfix;
    for (char c : infix) {
        if (isOperand(c)) {
            postfix += c;
        } else if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        } else if (isOperator(c)) {
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }
    return postfix;
}
int main() {
    string infix1 = "a+b*c";
    cout << "Infix: " << infix1 << endl;
    cout << "Postfix: " << infixToPostfix(infix1) << endl << endl;

    string infix2 = "(a+b)*(c-d)";
    cout << "Infix: " << infix2 << endl;
    cout << "Postfix: " << infixToPostfix(infix2) << endl << endl;

    string infix3 = "a+b*(c^d-e)^(f+g*h)-i";
    cout << "Infix: " << infix3 << endl;
    cout << "Postfix: " << infixToPostfix(infix3) << endl << endl;

    return 0;
}
