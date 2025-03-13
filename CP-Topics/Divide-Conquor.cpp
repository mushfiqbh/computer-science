// Author: Mushfiq R.
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define ld long double
#define ull unsigned long long
#define vsort(v) sort(v.begin(), v.end())
#define rsort(v) sort(v.begin(), v.end(), greater<int>())
#define fastIO() (ios_base::sync_with_stdio(false), cin.tie(NULL));
using namespace std;

int minimum(int start, int end, vector<int> arr)
{
    if (start == end)
    {
        return arr[0];
    }
    else if (end - start == 1)
    {
        return min(arr[start], arr[end]);
    }
    else if (end - start == 2)
    {
        return min(arr[start], min(arr[start + 1], arr[end]));
    }

    int third = (end - start) / 3;
    int mid1 = start + third;
    int mid2 = start + 2 * third;

    int m1 = minimum(start, mid1, arr);
    int m2 = minimum(mid1 + 1, mid2, arr);
    int m3 = minimum(mid2 + 1, end, arr);

    return min(m1, min(m2, m3));
}

int main()
{
    fastIO();
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        cout << minimum(0, n - 1, arr);
    }

    return 0;
}