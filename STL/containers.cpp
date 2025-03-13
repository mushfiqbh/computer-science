#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <list>
#include <functional>
#include <algorithm>
using namespace std;

class Person
{
public:
    float age;
    string name;
    
    bool operator<(const Person &p) const { return age < p.age; };
    bool operator>(const Person &p) const { return age > p.age; };
};

int main()
{
    // Emplace
    // Forward List
    list<int> l = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    


    set<Person> s = {{23, "Mushfiq"}, {20, "Sadik"}, {30, "Sadman"}};
    multiset<int> mset = {1, 2, 3, 1, 4, 5, 1, 6, 7, 1, 8, 9, 1, 10}; // sorted array
    for (auto &p : s)
    {
        cout << p.age << " " << p.name << endl;
    }

    return 0;
}