#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> res;
    unordered_set<int> set{nums1.begin(), nums1.end()};

    for (int num : nums2)
    {
        if (set.erase(num))
        {
            res.push_back(num);
        }
    }

    return res;
}

int main()
{
    vector<int> nums1 = {4,5,9};
    vector<int> nums2 = {9,4,9,8,4};

    vector<int> output = intersection(nums1, nums2);

    for (int num : output)
    {
        cout << num << " ";
    }
    return 0;
}