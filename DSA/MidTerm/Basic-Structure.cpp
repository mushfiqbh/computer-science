#include <iostream>
using namespace std;

struct StudentInfo
{
    string name;
    int id;
    float cgpa;
    int ban, eng, math;
    int total;

    StudentInfo(string str, int id)
    {
        name = str;
        id = id;
    }

    void print(StudentInfo s);
};

// Print ban, eng, math marks of a student
void StudentInfo::print(StudentInfo s)
{
    cout << s.ban << " " << s.eng << " " << s.math << endl;
}

int main()
{
    // Single student
    StudentInfo student("Hello", 20);
    cout << student.name << " " << student.id << endl;

    // Array of n students
    int n;
    cin >> n;
    StudentInfo students[n];
    for (int i = 0; i < n; i++)
    {
        cin >> students[i].name >> students[i].id >> students[i].ban >> students[i].eng >> students[i].math;
        students[i].total = students[i].ban + students[i].eng + students[i].math;
    }

    // Maximum Total (or cgpa)
    int mx = 0;
    string best;
    for (int i = 0; i < n; i++)
    {
        if (students[i].total > mx)
        {
            mx = students[i].total;
            best = students[i].name;
        }
    }
    cout << best << endl;

    return 0;
}