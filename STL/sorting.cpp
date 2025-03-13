#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Point
{
public:
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    bool operator<(const Point &p)
    {
        return (x + y) < (p.x + p.y);
    }
};

int main()
{
    vector<Point> points = {{1, 2}, {0, 1}, {3, 4}};

    sort(points.begin(), points.end());

    for (auto p : points)
    {
        cout << p.x << " " << p.y << endl;
    }

    vector<int> arr = {4, 2, 3, 4, 6, 5, 0, 7, 9};

    sort(arr.begin(), arr.end(), [](int a, int b)
         { return a < b; });

    for (auto x : arr)
    {
        cout << x << " ";
    }

    cout << is_sorted(arr.begin(), arr.end(), greater<int>());

    return 0;
}