// Author: Mushfiq R.
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define ld long double
#define ull unsigned long long
#define vsort(v) sort(v.begin(), v.end())
#define rsort(v) sort(v.begin(), v.end(), greater<int>())
#define fastIO() (ios_base::sync_with_stdio(false), cin.tie(NULL))
using namespace std;

int main()
{
    fastIO();
    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> arr;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        arr.push_back({m, i + 1});
    }

    sort(arr.begin(), arr.end());

    for (int p1 = 0; p1 < n - 2; p1++)
    {
        int p2 = p1 + 1, p3 = n - 1;
        while (p2 < p3)
        {
            int sum = arr[p1].first + arr[p2].first + arr[p3].first;

            if (sum == x)
            {
                cout << arr[p1].second << " " << arr[p2].second << " " << arr[p3].second << endl;
                return 0;
            }
            else if (sum < x)
            {
                p2++;
            }
            else if(sum > x)
            {
                p3--;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
