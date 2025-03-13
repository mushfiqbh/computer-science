#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

struct BST
{
    Node *root = NULL;

    void insertNode(int d);
    void deleteNode(int x);
    void BFS(Node *rt);
};

void BST::insertNode(int d)
{
    Node *newNode = new Node(d);
    if (root == NULL)
    {
        root = newNode;
        return;
    }

    Node *current = root;
    Node *parent = NULL;

    while (current != NULL)
    {
        parent = current;
        if (d < parent->data)
        {
            current = current->left;
            if (current == NULL)
            {
                parent->left = newNode;
                return;
            }
        }
        else
        {
            current = current->right;
            if (current == NULL)
            {
                parent->right = newNode;
                return;
            }
        }
    }
}

Node *getSuccessor(Node *curr)
{
    curr = curr->right;
    while (curr != nullptr && curr->left != nullptr)
        curr = curr->left;
    return curr;
}

Node *deleteNodeRec(Node *rt, int x)
{
    if (rt == NULL)
    {
        return NULL;
    }

    if (rt->data > x)
    {
        rt->left = deleteNodeRec(rt->left, x);
    }
    else if (rt->data < x)
    {
        rt->right = deleteNodeRec(rt->right, x);
    }
    else
    {
        // Node with one or no child
        if (rt->left == nullptr)
        {
            Node *temp = rt->right;
            delete rt;
            return temp;
        }
        else if (rt->right == nullptr)
        {
            Node *temp = rt->left;
            delete rt;
            return temp;
        }

        // Node with two children
        Node *succ = getSuccessor(rt);
        rt->data = succ->data;
        rt->right = deleteNodeRec(rt->right, succ->data);
    }

    return rt; // Ensure updated root is returned
}

void BST::deleteNode(int x)
{
    root = deleteNodeRec(root, x); // Update root in case it's deleted
}

void BST::BFS(Node *rt)
{
    if (rt == NULL)
    {
        cout << "Empty Tree";
        return;
    }

    queue<Node *> q;
    q.push(rt);

    while (!q.empty())
    {
        int levelSize = q.size(); // Number of nodes at the current level
        while (levelSize > 0)
        {
            Node *curr = q.front();
            cout << curr->data << " ";
            q.pop();

            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }

            levelSize--;
        }

        // End the line after each level
        cout << endl;
    }
}

int main()
{
    BST bst;
    bst.insertNode(40);
    bst.insertNode(30);
    bst.insertNode(50);
    bst.insertNode(20);
    bst.insertNode(35);
    bst.insertNode(45);

    bst.BFS(bst.root);

    bst.deleteNode(30);
    bst.BFS(bst.root);

    return 0;
}