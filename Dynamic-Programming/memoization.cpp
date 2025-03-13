// Problem Solver: Mushfiq R.
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
#define NIL -1
#define MAX 1000
typedef long long ll;
int lookup[MAX];

void lookup_init()
{
    for (int i = 0; i < MAX; i++)
    {
        lookup[i] = NIL;
    }
}

int fib(int n)
{
    if (lookup[n] == NIL)
    {
        if (n <= 1)
        {
            lookup[n] = n;
        }
        else
        {
            lookup[n] = fib(n - 1) + fib(n - 2);
        }
    }
    return lookup[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lookup_init();
    int n = 10;
    cout << fib(n);

    return 0;
}
