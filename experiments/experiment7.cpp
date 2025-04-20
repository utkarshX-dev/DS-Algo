#include <iostream>
#include <stack>
#include <string>

using namespace std;

string postfixToInfix(string postfix) {
    stack<string> st;

    for (char ch : postfix) {
        if (isalnum(ch)) {
            st.push(string(1, ch));
        } else {
            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();
            string expr = "(" + op1 + " " + ch + " " + op2 + ")";
            st.push(expr);
        }
    }

    return st.top();
}

int main() {
    string postfix1 = "ab+c*";
    string postfix2 = "abc*+";
    string postfix3 = "ab+cd+*";
    string postfix5 = "xy+z*uv/-";
    cout << "Postfix: " << postfix1 << "\nInfix: " << postfixToInfix(postfix1) << "\n\n";
    cout << "Postfix: " << postfix2 << "\nInfix: " << postfixToInfix(postfix2) << "\n\n";
    cout << "Postfix: " << postfix3 << "\nInfix: " << postfixToInfix(postfix3) << "\n\n";
    cout << "Postfix: " << postfix5 << "\nInfix: " << postfixToInfix(postfix5) << "\n\n";
    return 0;
}
