// Problem Solver: Mushfiq R.
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define vsort(v) sort(v.begin(), v.end())

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    cout << (n * (n - 1) / 2) * (m * (m - 1) / 2) << endl;

    return 0;
}