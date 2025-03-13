#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

void bfs(queue<int> q)
{
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for(auto i : graph[node])
        {
            if(!visited[i])
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    vector<int> graph[4];
    int visited[4] = {0};

    int n;
    cin >> n;

    while (n--)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    queue<int> q;
    for (int i = 0; i < 4; i++)
    {
        if (!visited[i])
        {
            q.push(i);
            visited[i] = 1;
            bfs(q);
        }
    }

    return 0;
}