#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

char nextGreatestLetter(vector<char> &letters, char target)
{
    int l = 0, h = letters.size() - 1;
    while (l <= h)
    {
        int m = (l + h) / 2;
        if (letters[m] <= target)
        {
            l = m + 1;
        }
        else
        {
            h = m - 1;
        }
    }

    return letters[l % letters.size()];
}

int main()
{
    vector<char> lt = {'c', 'f', 'j'};

    cout << nextGreatestLetter(lt, 'a');

    return 0;
}
