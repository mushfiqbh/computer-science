#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node(int d)
    {
        data = d;
        next = NULL;
        prev = NULL;
    }
};

struct DLL
{
    Node *head = NULL;
    void insertHead(int d);
    void insertEnd(int d);
    void insertAtPos(int pos, int d);
    void deleteHead();
    void deleteEnd();
    void deleteAtPos(int pos);
    void searchItem(int item);
    void print();
};

void DLL::insertHead(int d)
{
    Node *newNode = new Node(d);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void DLL::insertEnd(int d)
{
    Node *newNode = new Node(d);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *h = head;
        while (h->next != NULL)
        {
            h = h->next;
        }
        h->next = newNode;
        newNode->prev = h;
    }
}

void DLL::insertAtPos(int pos, int d)
{
    if (pos < 0)
    {
        return;
    }

    Node *newNode = new Node(d);
    if (pos == 0 || head == NULL)
    {
        insertHead(d);
        return;
    }

    Node *h = head;
    int count = 0;
    while (count < pos - 1 && h != NULL)
    {
        h = h->next;
        count++;
    }

    if (h == NULL)
    {
        return;
    }

    newNode->next = h->next;
    h->next = newNode;
    newNode->prev = h;

    if (newNode->next != NULL)
    {
        newNode->next->prev = newNode;
    }
}

void DLL::deleteHead()
{
    if (head == NULL)
    {
        cout << "List is empty\n";
    }
    else
    {
        Node *h = head;
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        delete h;
    }
}

void DLL::deleteEnd()
{
    if (head == NULL)
    {
        cout << "List is empty\n";
    }
    else if (head->next == NULL)
    {
        delete head;
        head = NULL;
    }
    else
    {
        Node *h = head;
        while (h->next != NULL)
        {
            h = h->next;
        }
        h->prev->next = NULL;
        delete h;
    }
}

void DLL::deleteAtPos(int pos)
{
    if (head == NULL)
    {
        cout << "List is empty\n";
    }
    else if (pos == 0)
    {
        deleteHead();
    }
    else
    {
        Node *h = head;
        for (int i = 0; i < pos && h != NULL; i++)
        {
            h = h->next;
        }

        if (h == NULL)
        {
            return;
        }

        if (h->prev != NULL)
        {
            h->prev->next = h->next;
        }
        if (h->next != NULL)
        {
            h->next->prev = h->prev;
        }
        delete h;
    }
}

void DLL::searchItem(int item)
{
    Node *h = head;
    while (h != NULL)
    {
        if (h->data == item)
        {
            cout << "Item Found\n";
            return;
        }
        h = h->next;
    }
    cout << "Item Not Found\n";
}

void DLL::print()
{
    Node *h = head;
    while (h != NULL)
    {
        cout << h->data << " ";
        h = h->next;
    }
    cout << endl;
}

int main()
{
    DLL l1;
    l1.insertHead(10);
    l1.insertHead(20);
    l1.insertHead(30);
    l1.insertEnd(40);
    l1.insertEnd(50);
    l1.insertEnd(60);
    // l1.insertAtPos(2, 100);
    // l1.deleteHead();
    // l1.deleteEnd();
    // l1.deleteAtPos(2);
    // l1.searchItem(100);
    l1.print();

    return 0;
}



