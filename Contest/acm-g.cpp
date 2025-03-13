#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string txt;
    cin >> txt;
    int n;
    cin >> n;
    int other = 0;
    vector<pair<char, int>> arr;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first - 1 >> arr[i].second - 1;
    }

    for (char c : txt)
    {
        for (int i = 0; i < n; i++)
        {
            if (c != arr[i].first)
            {
                other++;
            }else{
                
            }
        }
    }

    return 0;
}
