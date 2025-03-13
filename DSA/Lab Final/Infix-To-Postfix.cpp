#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

bool isOperator(char ch) {
    return ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^';
}

int precedence(char ch) {
    if(ch=='+' || ch=='-') {
        return 1;
    }
    else if(ch=='*' || ch=='/') {
        return 2;
    }
    else if(ch=='^') {
        return 3;
    }
    else if(ch==')' || ch=='}' || ch==']') {
        return 4;
    }else{
        return -1;
    }
}

int main(){
    stack<char> st;
    string exp, postfixResult="";
    cin >> exp;

    // Step 1
    for(int i=0; i<exp.size(); i++){
        // Step 2
        if(exp[i] >= 'A' && exp[i] <= 'Z'){
            postfixResult += exp[i];
        // Step 3
        }else if(isOperator(exp[i])){
            // Step 4
            if(st.empty() || st.top()=='(' || precedence(exp[i]) > precedence(st.top())){
                st.push(exp[i]);
            }
            // Step 5
            else{
                while(!st.empty() && precedence(exp[i]) <= precedence(st.top())){
                    postfixResult += st.top();
                    st.pop();
                }
                st.push(exp[i]);
            }
        }
        // Step 6
        else if(exp[i] == '('){
            st.push(exp[i]);
        }
        else if(exp[i] == ')'){
            while(st.top() != '('){
                postfixResult += st.top();
                st.pop();
            }
            st.pop();
        }
    }

    // Step 7
    while(!st.empty()) {
        postfixResult += st.top();
        st.pop();
    }

    cout << postfixResult << endl;


    return 0;
}

// Testcase: ((A+B)-C*(D/E))+F


