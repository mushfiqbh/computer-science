#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

bool isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

int precedence(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '^')
    {
        return 3;
    }
    else if (ch == ')' || ch == '}' || ch == ']')
    {
        return 4;
    }
}

int main()
{
    stack<char> st;
    string exp, prefixResult = "";
    cin >> exp;

    // Step 1
    reverse(exp.begin(), exp.end());

    // Step 2
    for (int i = 0; i < exp.size(); i++)
    {
        // Step 3
        if (exp[i] >= 'A' && exp[i] <= 'Z')
        {
            prefixResult += exp[i];
        }
        else if (isOperator(exp[i]))
        {
            // Step 4 + 5
            if (st.empty() || st.top() == ')' || precedence(exp[i]) >= precedence(st.top()))
            {
                st.push(exp[i]);
            }
            // Step 6
            else if (exp[i] == '^' && st.top() == '^')
            {
                prefixResult += st.top();
                st.pop();
                st.push(exp[i]);
            }
            else
            {
                while (!st.empty() && (precedence(exp[i]) < precedence(st.top())))
                {
                    prefixResult += st.top();
                    st.pop();
                }
                st.push(exp[i]);
            }
        }
        // Step 7
        else if (exp[i] == ')')
        {
            st.push(exp[i]);
        }
        else if (exp[i] == '(')
        {
            while (st.top() != ')')
            {
                prefixResult += st.top();
                st.pop();
            }
            st.pop();
        }
    }

    // Step 8
    while (!st.empty())
    {
        prefixResult += st.top();
        st.pop();
    }

    // Step 9
    reverse(prefixResult.begin(), prefixResult.end());

    cout << prefixResult << endl;

    return 0;
}

// Testcase: K+L-M*N+(O^P)*W/U/V*T+Q
