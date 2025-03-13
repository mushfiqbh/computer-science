#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> ans;
        int mx = nums[0];
        for (int i = 0; i < k; i++)
        {
            mx = max(nums[i], mx);
        }
        ans.push_back(mx);

        while (k < nums.size())
        {
            mx = max(mx, nums[k]);
            ans.push_back(mx);
            k++;
        }

        return ans;
    }
};

int main()
{
    Solution solution;

    int k, n;
    cin >> k >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<int> ans;
    ans = solution.maxSlidingWindow(nums, k);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
