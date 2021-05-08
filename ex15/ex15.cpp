#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < len; ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int p1 = i + 1, p2 = len - 1;
            while (p1 < p2)
            {
                if (nums[p1] + nums[p2] + nums[i] < 0)
                {
                    p1++;
                }
                else if (nums[p1] + nums[p2] + nums[i] > 0)
                {
                    p2--;
                }
                else
                {
                    res.emplace_back(vector<int> {nums[i], nums[p1], nums[p2]});
                    while (p1 < p2 && nums[p1] == nums[p1 + 1])
                        p1++;
                    p1++;
                    while (p1 < p2 && nums[p2] == nums[p2 - 1])
                        p2--;
                    p2--;
                }
            }

        }
        return res;
    }
};

class Solution2
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        unordered_map<int, int> hashset;
        int len = nums.size();
        for (int i = 0; i < len; ++i)
        {
            hashset.emplace(-nums[i], i);
        }

        set<vector<int>> res;
        for (int i = 0; i < len; ++i)
        {
            for (int j = i + 1; j < len; ++j)
            {
                auto judge = hashset.count(nums[i] + nums[j]);
                if (judge && judge != i && judge != j)
                {
                    int a = nums[i];
                    int b = nums[j];
                    int c = -a - b;
                    int tmpa, tmpc ;
                    tmpa = min(a, min(c, b));
                    tmpc = max(a, max(b, c));
                    a = tmpa;
                    c = tmpc;
                    b = -a - c;
                    res.emplace(vector<int> {a, b, c});
                }

            }
        }
        vector<vector<int>> res2;
        for (auto &i : res)
        {
            res2.emplace_back(i);
        }
        return res2;
    }
};

int main(void)
{
    vector<int> vec = {-1, 0, 1, 2, -1, -4};
    Solution sy;
    sy.threeSum(vec);

    return 0;
}
