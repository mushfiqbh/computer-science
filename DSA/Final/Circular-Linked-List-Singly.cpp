/**
 * Circular Singly Linked List
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

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

struct SLLC
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

void SLLC::insertHead(int d)
{
    Node *newNode = new Node(d);
    if (head == NULL)
    {
        head = newNode;
        head->next = head;
    }
    else
    {
        Node *h = head;
        while (h->next != head)
        {
            h = h->next;
        }
        newNode->next = head;
        h->next = newNode;
        head = newNode;
    }
}

void SLLC::insertEnd(int d)
{
    Node *newNode = new Node(d);
    if (head == NULL)
    {
        head = newNode;
        head->next = head;
    }
    else
    {
        Node *h = head;
        while (h->next != head)
        {
            h = h->next;
        }
        h->next = newNode;
        newNode->next = head;
    }
}

void SLLC::insertAtPos(int pos, int d)
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
    h->next = newNode;
}

void SLLC::deleteHead()
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
        Node *h = head;
        while (h->next != head)
        {
            h = h->next;
        }
        Node *dl = head;
        h->next = head->next;
        head = head->next;
        delete dl;
    }
}

void SLLC::deleteEnd()
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
        Node *h = head;
        while (h->next->next != head)
        {
            h = h->next;
        }
        Node *dl = h->next;
        h->next = head;
        delete dl;
    }
}

void SLLC::deleteAtPos(int pos)
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
    delete dl;
}

void SLLC::searchItem(int item)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
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

void SLLC::print()
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
    SLLC sllc;

    sllc.insertHead(10);
    sllc.insertHead(20);
    sllc.insertEnd(30);
    sllc.insertEnd(40);
    sllc.insertAtPos(3, 50);
    sllc.print();
    sllc.searchItem(50);
    sllc.deleteHead();
    sllc.deleteEnd();
    sllc.deleteAtPos(3);
    sllc.print();

    return 0;
}