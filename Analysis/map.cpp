#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    map<string, int> mp;

    mp["Ab"] = 5;
    mp["Bc"] = 4;
    mp["Cd"] = 6;
    string D = "De";
    mp[D] = 7;

    mp.erase("Cd");
    auto iter = next(mp.begin(), 0); // 0: first, 1: second
    mp.erase(iter);

    for(const auto& pair : mp){
        cout << pair.first << " " << pair.second << endl;
    }

    

    return 0;
}