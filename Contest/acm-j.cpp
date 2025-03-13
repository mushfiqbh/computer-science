// Problem Solver: Mushfiq R.
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;
#define ll long long
#define ld long double
#define vsort(v) sort(v.begin(), v.end())

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        cout << fixed << setprecision(3);
        cout << n * n * 3.1416 << endl;
    }

    return 0;
}