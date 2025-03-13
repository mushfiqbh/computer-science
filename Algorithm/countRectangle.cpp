#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

struct Point {
    int x, y;
};

int countRectangles(const vector<Point>& points) {
    map<pair<int, int>, int> count; // Map to count y-pairs
    int answer = 0;

    // Iterate through all points
    for (const Point& p : points) {
        for (const Point& p_above : points) {
            // Check if the points have the same x and p.y < p_above.y
            if (p.x == p_above.x && p.y < p_above.y) {
                pair<int, int> pair_y{p.y, p_above.y};
                answer += count[pair_y]; // Add the count of existing y-pairs
                count[pair_y]++;         // Increment the count for this y-pair
            }
        }
    }
    return answer;
}

int main() {
    // Example input
    vector<Point> points = {{1, 1}, {1, 3}, {2, 1}, {2, 3}};

    int rectangles = countRectangles(points);
    cout << "Number of rectangles: " << rectangles << endl;

    return 0;
}
