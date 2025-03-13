#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

struct BinaryTree
{
    Node *root = NULL;
    queue<Node *> q;

    void insertNode(int val);
    void inorder(Node *n);
    void BFS(Node *rt);
};

void BinaryTree::insertNode(int val)
{
    Node *newNode = new Node(val);

    if (root == NULL)
    {
        root = newNode;
        q.push(root);
    }
    else
    {
        Node *parent = q.front();

        if (parent->left == NULL)
        {
            parent->left = newNode;
            q.push(parent->left);
        }
        else
        {
            parent->right = newNode;
            q.push(parent->right);
            q.pop();
        }
    }
}

void BinaryTree::inorder(Node *rt)
{
    if (rt == NULL)
    {
        return;
    }

    // cout here to Preorder
    inorder(rt->left);
    cout << rt->data << " ";
    inorder(rt->right);
    // cout here to Postorder
}

void BinaryTree::BFS(Node *rt)
{
    if (rt == NULL)
    {
        return;
    }

    queue<Node *> q;
    q.push(rt);

    while (!q.empty())
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
    }
}

int main()
{
    BinaryTree tr;

    tr.insertNode(1);
    tr.insertNode(2);
    tr.insertNode(3);
    tr.insertNode(4);
    tr.insertNode(5);

    // tr.inorder(tr.root);
    tr.BFS(tr.root);

    return 0;
}
