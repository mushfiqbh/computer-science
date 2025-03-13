// Problem Solver: Mushfiq R.
#include <iostream>
#include <vector>
#include <cmath>
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
        int n;
        ll k;
        cin >> n >> k;

        vector<ll> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int same = 1;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != k)
            {
                same = 0;
                break;
            }
        }

        if (same)
        {
            cout << 0 << endl;
        }
        else
        {
            int low = -1, high = n;
            for (int i = 0; i < n; i++)
            {
                if (arr[i] != k)
                {
                    if (low == -1)
                    {
                        low = i;
                    }
                    high = i;
                }
            }

            if (low == high)
            {
                cout << 1 << endl;
            }
            else
            {
                int xor = 1, mod = 1;
                ll first_xor = (arr[low] ^ k);

                for (int i = low; i <= high; i++)
                {
                    if ((arr[i] ^ k) != first_xor)
                    {
                        xor = 0;
                    }

                    if (arr[i] % k != 0)
                    {
                        mod = 0;
                    }
                }

                cout << ((xor || mod) ? 1 : 2) << endl;
            }
        }
    }

    return 0;
}
