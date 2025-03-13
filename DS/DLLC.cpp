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

    void insertAtHead(int d)
    {
        Node *newNode = new Node(d);

        if (head == NULL)
        {
            head = newNode;
            head->next = newNode;
            head->prev = newNode;
        }
        else
        {
            newNode->next = head;
            newNode->prev = head->prev;
            head->prev->next = newNode;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int d)
    {
        Node *newNode = new Node(d);

        if (head == NULL)
        {
            head = newNode;
            head->next = newNode;
            head->prev = newNode;
        }
        else
        {
            newNode->next = head;
            newNode->prev = head->prev;
            head->prev->next = newNode;
            head->prev = newNode;
        }
    }

    void insertAtPosition(int d, int pos)
    {
        Node *newNode = new Node(d);

        if (pos == 0)
        {
            insertAtHead(d);
        }
        else
        {
            Node *h = head;

            for (int i = 0; i < pos - 1 && h->next != head; i++)
            {
                h = h->next;
            }

            newNode->next = h->next;
            newNode->prev = h;
            h->next->prev = newNode;
            h->next = newNode;
        }
    }

    void deleteHead()
    {
        if (head == NULL)
        {
            return;
        }
        else if (head->next == head)
        {
            Node *h = head;
            head = NULL;
            delete h;
        }
        else
        {
            Node *h = head;
            Node *p = head->prev;
            head = head->next;
            p->next = head;
            head->prev = p;
            delete h;
        }
    }

    void deleteAtPos(int pos)
    {
        if (pos == 0)
        {
            deleteHead();
        }
        else
        {
            Node *h = head;
            for (int i = 0; i < pos && h->next != head; i++)
            {
                h = h->next;
            }

            if (h->next == head) // Position out of bounds
            {
                return;
            }

            Node *dl = h->next;
            h->next = dl->next;
            dl->next->prev = h;
            delete dl;
        }
    }

    void traverse()
    {
        Node *h = head;

        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        do
        {
            cout << h->data << " ";
            h = h->next;
        } while (h != head);
        cout << endl;
    }

    void reverse_traverse()
    {
        Node *h = head;

        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        do
        {
            cout << h->data << " ";
            h = h->prev;
        } while (h != head);
        cout << endl;
    }
};

int main()
{
    DLLC dllc;

    dllc.insertAtHead(10);
    dllc.insertAtHead(20);
    dllc.insertAtPosition(30, 1);
    dllc.insertAtEnd(40);
    dllc.traverse();

    return 0;
}