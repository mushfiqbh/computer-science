// Problem Solver: Mushfiq R.
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
#define ll long long
#define ld long double
#define vsort(v) sort(v.begin(), v.end())

int minOperation(int n)
{
    if (n <= 0)
    {
        return 0;
    }
    return 1 + min(minOperation(n - 2), minOperation(n - 3));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;

    int echo = minOperation(n);
    cout << echo << endl;

    return 0;
}