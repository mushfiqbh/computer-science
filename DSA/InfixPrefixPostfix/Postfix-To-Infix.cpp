//========== Postix to Infix Expression ==========//
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<string> st;
    string exp;
    cin >> exp;

    for (int i=0; i<exp.size(); i++) {
        if (exp[i] >= 'A' && exp[i] <= 'Z') {
            string ss = "";
            ss += exp[i];
            st.push(ss);
        } else {
            string s1 = st.top();
            st.pop();
            string s2 = st.top();
            st.pop();

            string s = "(" + s2 + exp[i] + s1 + ")";
            st.push(s);
        }
    }

    cout << st.top() << endl;

    return 0;
}

// Testcase: AB+CDE/*-F+