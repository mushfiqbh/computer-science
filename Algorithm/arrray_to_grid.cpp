#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct Node
{
    int data;
    bool visited;
    Node *next;
    Node *prev;
    Node *left;
    Node *right;
    Node *up;
    Node *down;

    Node(int value)
    {
        data = value;
        visited = false;
        next = NULL;
        prev = NULL;
        left = NULL;
        right = NULL;
        up = NULL;
        down = NULL;
    }
}

struct GRID
{
    Node *head = NULL;
    Node *tail = NULL;
    void vector_to_grid(vector<vector<int>> grid);
    void zigzag();
}

GRID::vector_to_grid(vector<vector<int>> grid)
{
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            Node *newNode = new Node(grid[i][j]);
            if (head == NULL)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        }
    }
}

GRID::zigzag()
{
    
}

int main()
{
    vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    GRID grid1;
    grid1.vector_to_grid(grid);

    return 0;
}