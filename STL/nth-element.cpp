#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
    vector<int> vec = {4, 5, 1, 7, 0, 2, 3, 6, 9, 8};

    // is sorted until
    auto it = is_sorted_until(vec.begin(), vec.end());
    auto diff = distance(vec.begin(), it);
    cout << diff << endl;

    // second largest
    nth_element(vec.begin(), vec.begin() + 1, vec.end(), greater<int>());
    int secondLargest = vec[1];
    cout << secondLargest << endl;

    // median
    nth_element(vec.begin(), vec.begin() + vec.size() / 2, vec.end());
    int median = vec[vec.size() / 2];
    cout << median << endl;

    return 0;
}