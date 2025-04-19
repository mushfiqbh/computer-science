#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll findlcs(string &s, string &ss)
{
	ll m = s.size();
	ll n = ss.size();

	ll lcs[m + 1][n + 1];
	for (ll i = 0; i < m + 1; i++)
	{
		for (ll j = 0; j < n + 1; j++)
		{
			if (i == 0 || j == 0)
				lcs[i][j] = 0;
			else if (s[i - 1] == ss[j - 1])
			{
				lcs[i][j] = 1 + lcs[i - 1][j - 1];
			}
			else
			{
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
			}
		}
	}
	return lcs[m][n];
}

int main()
{
	string s, ss;
	cin >> s >> ss;

	ll ans = findlcs(s, ss);
	cout << "Longest common length is " << ans << endl;
}