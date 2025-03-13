//============= Postfix Evaluation =============//
#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

int main(){
    stack<int> st;
    string exp;
    cin >> exp;

    for(int i=0; i<exp.size(); i++){
        if(exp[i] >= '0' && exp[i] <= '9'){
            st.push(exp[i] - '0');
        }
        else{
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();

            if(exp[i] == '+'){
                st.push(b+a);
            }
            else if(exp[i] == '-'){
                st.push(b-a);
            }
            else if(exp[i] == '*'){
                st.push(b*a);
            }
            else if(exp[i] == '/'){
                st.push(b/a);
            }
            else if(exp[i] == '^'){
                st.push(pow(b, a));
            }
        }
    }

  cout << st.top();
  
  return 0;
}

// Testcase: 12+345/*-6+