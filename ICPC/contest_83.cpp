// Author: Mushfiq R.
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
#define vsort(v) sort(v.begin(), v.end())
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL));
using namespace std;

int main()
{
    fastread();
    int t;
    cin >> t;
    while (t--)
    {
        
        


        vector<int> arr(3);
        arr = {1, 2, 3};
        // reverse the array
        reverse(arr.begin(), arr.end());
        
        for (int i = 0; i < 3; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << arr.size();
    }

    return 0;
}