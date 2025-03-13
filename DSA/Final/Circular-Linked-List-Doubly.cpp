/**
 * Circular Doubly Linked List
 *
 * @author Md. Mushfiqur Rahman
 * ID: 0182320012101295
 */

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

struct DLLC
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

void DLLC::insertHead(int d)
{
    Node *newNode = new Node(d);
    if (head == NULL)
    {
        head = newNode;
        head->next = head;
        head->prev = head;
    }
    else
    {
        Node *tail = head->prev;
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
}

void DLLC::insertEnd(int d)
{
    Node *newNode = new Node(d);
    if (head == NULL)
    {
        head = newNode;
        head->next = head;
        head->prev = head;
    }
    else
    {
        Node *tail = head->prev;
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
    }
}

void DLLC::insertAtPos(int pos, int d)
{
    if (pos == 1)
    {
        insertHead(d);
        return;
    }
    Node *newNode = new Node(d);
    Node *h = head;
    for (int i = 1; i < pos - 1 && h->next != head; i++)
    {
        h = h->next;
    }
    newNode->next = h->next;
    newNode->prev = h;
    h->next->prev = newNode;
    h->next = newNode;
}

void DLLC::deleteHead()
{
    if (head == NULL)
        return;
    if (head->next == head)
    {
        delete head;
        head = NULL;
    }
    else
    {
        Node *tail = head->prev;
        Node *dl = head;
        head = head->next;
        tail->next = head;
        head->prev = tail;
        delete dl;
    }
}

void DLLC::deleteEnd()
{
    if (head == NULL)
        return;
    if (head->next == head)
    {
        delete head;
        head = NULL;
    }
    else
    {
        Node *tail = head->prev;
        Node *dl = tail;
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        delete dl;
    }
}

void DLLC::deleteAtPos(int pos)
{
    if (pos == 1)
    {
        deleteHead();
        return;
    }
    Node *h = head;
    for (int i = 1; i < pos - 1 && h->next != head; i++)
    {
        h = h->next;
    }
    Node *dl = h->next;
    h->next = dl->next;
    dl->next->prev = h;
    delete dl;
}

void DLLC::searchItem(int item)
{
    if (head == NULL)
    {
        cout << "List is Empty" << endl;
        return;
    }
    Node *h = head;
    int pos = 1;
    do
    {
        if (h->data == item)
        {
            cout << "Item " << item << " Found at Position " << pos << endl;
            return;
        }
        h = h->next;
        pos++;
    } while (h != head);
    cout << "Item " << item << " Not Found" << endl;
}

void DLLC::print()
{
    if (head == NULL)
    {
        cout << "List is Empty" << endl;
        return;
    }
    Node *h = head;
    do
    {
        cout << h->data << " ";
        h = h->next;
    } while (h != head);
    cout << endl;
}

int main()
{
    DLLC dllc;
    dllc.insertHead(10);
    dllc.insertHead(20);
    dllc.insertHead(30);
    dllc.insertEnd(40);
    dllc.insertEnd(50);
    dllc.insertEnd(60);
    dllc.insertAtPos(2, 100);
    dllc.print();
    dllc.deleteHead();
    dllc.deleteEnd();
    dllc.deleteAtPos(2);
    dllc.searchItem(100);
    dllc.print();
    return 0;
}