#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int d) : val(d), left(NULL), right(NULL) {}
};

struct TN
{
    TreeNode *root = NULL;

    void insertNode(int d);
}

TreeNode *insertRecursive(TreeNode *node, int d)
{
    if (!node)
    {
        // Create a new node with the given value
        return new TreeNode(d);
    }

    // Recurse left or right based on the value
    if (d < node->val)
    {
        node->left = insertRecursive(node->left, d);
    }
    else if (d > node->val)
    {
        node->right = insertRecursive(node->right, d);
    }
    // If d is equal to node->val, we handle duplicates as needed (e.g., ignore or insert)

    return node;
}

TN::insertNode(int d)
{
    root = insertRecursive(root, d);
}

int countNodes(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int l = countNodes(root->left);
    int r = countNodes(root->right);

    return 1 + l + r;
}

int main()
{
    TN::insertNode(5);
    // cout << countNodes();
}