#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{

    cout << "How many Coins?: ";
    ll n;
    cin >> n;

    cout << "Amount: ";
    ll m;
    cin >> m;
    cout << "List of coins: ";

    vector<ll> coin(n);
    for (ll i = 1; i <= n; i++)
        cin >> coin[i];

    ll coins[n + 1][m + 1];

    for (ll i = 0; i < n + 1; i++)
    {
        for (ll j = 0; j < m + 1; j++)
        {
            if (j == 0)
                coins[i][j] = 0;
            else if (i == 0)
                coins[i][j] = 9999;
            else if (j >= coin[i])
            {
                coins[i][j] = min(coins[i - 1][j], 1 + coins[i][j - coin[i]]);
            }
            else
            {
                coins[i][j] = coins[i - 1][j];
            }
        }
    }

    cout << "Matrix is: " << endl;
    for (ll i = 0; i <= n; i++)
    {
        for (ll j = 0; j <= m; j++)
            cout << coins[i][j] << " ";
        cout << endl;
    }

    cout << "Coins Needed: " << coins[n][m] << endl;

    return 0;
}