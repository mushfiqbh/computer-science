#include <bits/stdc++.h>
using namespace std;
const int MX = 10;

struct Stack
{
    int arr[MX];
    int cnt = 0;

    int Size();
    bool Empty();
    void push(int d);
    int pop();
    int top();
};

int Stack::Size()
{
    return cnt;
}
bool Stack::Empty()
{
    return Size() == 0;
}

void Stack::push(int d)
{
    if (cnt < MX)
    {
        arr[cnt++] = d;
    }
    else
    {
        cout << "Stack Overflow..." << endl;
    }
}

int Stack::pop()
{
    if (Size() == 0)
    {
        cout << "Stack Underflow..." << endl;
        return -1;
    }
    else
    {
        return arr[--cnt];
    }
}

int Stack::top()
{
    if (Size() == 0)
    {
        cout << "Stack is Empty" << endl;
        return -1;
    }
    return arr[cnt - 1];
}

int main()
{
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(50);

    cout << "TOP is " << st.top() << endl;
    cout << "Deleted " << st.pop() << endl;
    cout << "TOP is " << st.top() << endl;
    cout << "Size " << st.Size() << endl;
    if (st.Empty())
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        cout << "Stack is not Empty" << endl;
    }

    return 0;
}
