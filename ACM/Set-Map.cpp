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

int main()
{
    fastIO();
    int n, k;
    cin >> n >> k;
    map<int, int> prefixSum;
    int sum = 0, count = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        sum += x;

        if(sum == k){
            count++;
        }

        if(prefixSum.find(sum - k) != prefixSum.end()){
            count += prefixSum[sum - x];
        }

        prefixSum[sum]++;
    }

    cout << count << endl;

    return 0;
}