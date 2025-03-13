// Problem Solver: Mushfiq R.
#include <iostream>
#include <vector>
using namespace std;

bool isPalindrome(int x)
{
    if (x < 0)
        return false;

    long long xin = x, rev = 0;
    while (x)
    {
        rev = rev * 10 + (x % 10);
        x /= 10;
    }

    return xin == rev;
}

int main()
{
    int n;
    cin >> n;
    

    return 0;
}
