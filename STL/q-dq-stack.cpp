#include <iostream>
#include <vector>
#include <cmath>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    // Deque
    deque<int> dq;
    dq.push_back(1);
    dq.push_front(2);
    dq.push_back(3);
    dq.push_front(4);

    for (int i : dq)
    {
        cout << i << " ";
    }
    cout << endl;

    // Stack
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    // Queue
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    // Priority Queue
    priority_queue<int> pq;
    pq.push(1);
    pq.push(3);
    pq.push(2);
    pq.push(4);

    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}
