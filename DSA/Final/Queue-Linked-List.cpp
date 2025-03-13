// Queue Linked List
#include <bits/stdc++.h>
using namespace std;
const int MX = 50;

struct Node
{
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

struct Queue
{
    Node *front = NULL;
    Node *rear = NULL;
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
    Node *n = new Node(d);
    if (cnt < MX)
    {
        if (front == NULL)
        {
            front = rear = n;
        }
        else
        {
            rear->next = n;
            rear = n;
        }
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
    else if (front == rear)
    {
        int deletedData = front->data;
        Node *del = front;
        front = rear = NULL;

        delete del;
        return deletedData;
    }
    else
    {
        Node *h = front;
        front = front->next;
        int deletedData = h->data;

        delete h;
        cnt--;
        return deletedData;
    }
}

int Queue::Front()
{
    return front->data;
}

int main()
{
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    cout << "Size is" << q.Size() << endl;
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