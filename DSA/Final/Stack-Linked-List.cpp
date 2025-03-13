// Stack Linked List
#include<bits/stdc++.h>
using namespace std;
const int MX = 5;

struct Node{
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

struct Stack
{
    Node *head = NULL;
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
    Node *n = new Node(d);
    if(cnt<MX)
    {
        if(head == NULL)
        {
            head = n;
        }
        else{
            n->next = head;
            head = n;
        }
        cnt++;
    }
    else{
        cout<<"Stack is full already. Overflow..."<<endl;
    }
}

int Stack::pop()
{
    if(Size()==0)
    {
        cout<<"Stack is already Empty. Underflow..."<<endl;
        return -1;
    }
    else{
        Node *h = head;
        head = head->next;
        int deletedData = h->data;

        delete h;
        cnt--;
        return deletedData;
    }
}

int Stack::top()
{
    if(head==NULL)
    {
        cout<<"Stack is Empty"<<endl;
        return -1;
    }
    return head->data;
}

int main()
{
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.pop()
    st.pop()
    st.pop()

    return 0;
}
