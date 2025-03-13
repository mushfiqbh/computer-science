#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    multimap <string, int> mp;

    // mp["Ab"] = 3;
    mp.insert({"Ab", 4});
    mp.insert({"Ab", 4});
    mp.insert({"Ab", 4});
    mp.insert({"Bc", 5});

    for(const auto& item : mp)
    {
        cout << item.first << " " << item.second;
    }
    return 0;
}