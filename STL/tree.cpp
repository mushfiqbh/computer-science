#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    vector<vector<int>> Tree;
    int edge, n1, n2;
    cin >> edge;
    Tree.resize(edge);

    for (int i = 0; i < edge; i++)
    {
        cin >> n1 >> n2;
        Tree[n1].push_back(n2);
    }

    for (const auto &i : Tree)
    {
        for (const auto &j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}