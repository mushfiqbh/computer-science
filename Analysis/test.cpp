#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;

    node()
    {
        data = 0;
        next = NULL;
    }
    node(int d)
    {
        data = d;
        next = NULL;
    }
};
struct sll
{
    node *head = NULL;
    int counter = 0;

    void insertathead(int d);
    void insertatend(int d);
    void insertatanyposition(int d, int pos);
    void print();
};

void sll::insertathead(int d)
{
    node *n = new node(d);

    if (head == NULL)
    {
        head = n;
    }
    else
    {
        n->next = head;
        head = n;
    }
}
void sll::insertatend(int d)
{
    node *n = new node(d);

    if (head == NULL)
    {
        head = n;
    }
    else
    {
        node *h = head;
        while (h->next != NULL)
        {
            h = h->next;
        }
        h->next = n;
    }
}
void sll::print()
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
    }
    else
    {
        node *h = head;
        while (h != NULL)
        {
            cout << h->data << " ";
            h = h->next;
        }
        cout << endl;
    }
}

int main()
{
    sll ls;
    ls.insertathead(10);
    ls.insertathead(30);
    ls.insertatend(20);
    ls.print();
}
