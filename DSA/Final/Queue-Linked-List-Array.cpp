#include <bits/stdc++.h>
using namespace std;
const int MX = 50;

struct Queue
{
    int arr[MX];
    int front = 0;
    int rear = 0;
    int cnt = 0;

    int Size();
    bool Empty();
    void push(int d);
    int pop();
    int Front();
};

int Queue::Size()
{
    return cnt;
}

bool Queue::Empty()
{
    return Size() == 0;
}

void Queue::push(int d)
{
    if (cnt < MX)
    {
        arr[rear] = d;
        rear++;
        cnt++;
    }
    else
    {
        cout << "Queue is full already. Overflow..." << endl;
    }
}

int Queue::pop()
{
    if (Size() == 0)
    {
        cout << "Queue is already Empty. Underflow..." << endl;
        return -1;
    }
    else
    {
        int deletedData = arr[front];
        front++;
        cnt--;
        return deletedData;
    }
}

int Queue::Front()
{
    if (Size() == 0)
    {
        cout << "Queue is Empty" << endl;
        return -1;
    }
    return arr[front];
}

int main()
{
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    cout << "Size is " << q.Size() << endl;
    cout << "Front is " << q.Front() << endl;
    q.pop();
    cout << "Front is " << q.Front() << endl;
    cout << "Size " << q.Size() << endl;
    cout << q.Empty() << endl;
    while (!q.Empty())
    {
        cout << q.Front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
