#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int n = nums.size();
        auto searchBinary = [&](bool lower)
        {
            int l = 0;
            int r = n - 1;
            int ans = n;
            while (l <= r)
            {
                int mid = (l + r) / 2;
                //cout << nums[mid] << endl;
                if (nums[mid] > target || (lower && nums[mid] == target))
                {
                    r = mid - 1;
                    ans = mid;
                }
                else
                {
                    l = mid + 1;
                }
            }
            //cout << ans << endl;
            return ans;

        };
        auto left_index = searchBinary(true);
        auto right_index = searchBinary(false) - 1;
        if (left_index <= right_index && right_index < n && nums[left_index] == target)
        {
            return {left_index, right_index};
        }
        return {-1, -1};
    }

};


class Solution3
{
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        auto [l, r] = equal_range(nums.begin(), nums.end(), target);
        if (l == r)
            return {-1, -1};
        return {(int)std::distance(nums.begin(), l), (int)std::distance(nums.begin(), r) - 1};
    }
};


class Solution2
{
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        auto l = lower_bound(nums.begin(), nums.end(), target);
        auto r = upper_bound(nums.begin(), nums.end(), target);
        if (l == r)
            return {-1, -1};
        //if (l == nums.end() || *l != target)
        //return {-1, -1};
        return {(int)std::distance(nums.begin(), l), (int)std::distance(nums.begin(), r) - 1};
    }
};

int main(void)
{
    Solution sy;
    vector<int> v{2, 33, 39, 99, 99, 99};
    auto res = sy.searchRange(v, 99);
    for (auto &i : res)
        cout << i << " ";
    cout << endl;

    return 0;
}
