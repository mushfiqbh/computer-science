// Author: Mushfiq R.
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
#define vsort(v) sort(v.begin(), v.end())
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL));
using namespace std;

int main()
{
    fastread();
    int t;
    cin >> t;
    while (t--)
    {
        vector<vector<int>> grid(4, vector<int>(4));
        grid = {{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};

        int count = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    count += 4;
                    if (i > 0)
                    {
                        if (grid[i - 1][j] == 1)
                            count -= 2;
                    }
                    if (j > 0)
                    {
                        if (grid[i][j - 1] == 1)
                            count -= 2;
                    }
                }
            }
        }

        cout << count << endl;
    }

    return 0;
}