#include <iostream>
using namespace std;

struct StdInfo
{
    int id;
    string name;
    float cgpa;
};

bool comp(StdInfo a, StdInfo b)
{
    return a.cgpa > b.cgpa;
}

int main()
{
    // Sorting array of structure
    int sz = 3;
    StdInfo students[sz];
    for (int i = 0; i < sz; i++)
    {
        cin >> students[i].id >> students[i].cgpa >> students[i].name;
    }

    // sort(students, students + sz, comp);
    // BUBBLE SORT Below
    for (int i = 0; i < sz; i++)
    {
        for (int j = 0; j < sz - i - 1; j++)
        {
            if (students[j].cgpa < students[j + 1].cgpa)
            {
                swap(students[j], students[j + 1]);
            }
        }
    }

    for (int i = 0; i < sz; i++)
    {
        cout << students[i].id << " " << students[i].name << endl;
    }
}
