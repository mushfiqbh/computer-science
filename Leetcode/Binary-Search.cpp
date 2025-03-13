#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int searchInsert(vector<int> nums, int target)
{
    if (target < nums[0])
    {
        return -1;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] >= target)
        {
            return i;
        }
    }

    return nums.size();
}

int mySqrt(int x) {
    unsigned left = 1;
    unsigned right = x + 1u;

    while (left < right) {
      const unsigned mid = (left + right) / 2;
      if (mid > x / mid)
        right = mid;
      else
        left = mid + 1;
    }

    // left := the minimum number s.t. left * left > x
    return left - 1;
}

int main()
{
    vector<int> nums = {-1, 3, 5, 6};
    int target = 7;
    cout << mySqrt(257);

    return 0;
}