#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function to evaluate postfix expression with given variable values
int evaluatePostfix(string expression) {
    stack<int> st;
    for (char c : expression) {
        if (isdigit(c)) {
            st.push(c - '0');
        } else if (isalpha(c)) {
            switch (c) {
                case 'A':
                    st.push(5);
                    break;
                case 'B':
                    st.push(4);
                    break;
                case 'C':
                    st.push(3);
                    break;
                case 'D':
                    st.push(7);
                    break;
            }
        } else {
            int operand2 = st.top(); st.pop();
            int operand1 = st.top(); st.pop();
            switch (c) {
                case '+':
                    st.push(operand1 + operand2);
                    break;
                case '-':
                    st.push(operand1 - operand2);
                    break;
                case '*':
                    st.push(operand1 * operand2);
                    break;
                case '/':
                    st.push(operand1 / operand2);
                    break;
            }
        }
    }
    return st.top();
}

int main() {
    string expression = "ABCD-*+";
    int result = evaluatePostfix(expression);
    cout << "Result of evaluation: " << result << endl;
    return 0;
}
