#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> hashtable;
        int len = nums.size();
        for (int i = 0; i < len; ++i)
        {
            if (hashtable.count(target - nums[i]))
            {
                return {hashtable[target - nums[i]], i};
            }
            else
            {
                hashtable[nums[i]] = i;
            }
        }
        return {};
    }
};

int main(void)
{

    return 0;
}
