// Problem Solver: Mushfiq R.
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define vsort(v) sort(v.begin(), v.end())

string getRank(int rating)
{
    if (rating < 1200)
    {
        return "newbie";
    }
    else if (rating < 1400)
    {
        return "pupil";
    }
    else if (rating < 1600)
    {
        return "specialist";
    }
    else if (rating < 1900)
    {
        return "expert";
    }
    else if (rating < 2100)
    {
        return "candidate master";
    }
    else if (rating < 2400)
    {
        return "master";
    }
    else
    {
        return "grandmaster";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        string handle;
        int current, maxx, delta;
        cin >> handle >> current >> maxx >> delta;

        int rating = current + delta;

        if (current >= maxx)
        {
            maxx = current;
        }

        if (rating > current && current >= maxx)
        {
            cout << getRank(rating) << endl;
        }
        else
        {
            cout << "Think about it, you can do it!" << endl;
        }
    }

    return 0;
}
