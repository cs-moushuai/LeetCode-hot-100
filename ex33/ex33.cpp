#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int search(vector<int>& nums, int target)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0] == target ? 0 : -1;
        int left = 0;
        int right = n - 1;
        while (left <= right)
        {
            int middle = (left + right) / 2;

            if (nums[middle] == target)
                return middle;
            if (nums[left] < nums[middle - 1])
            {
                if (nums[left] <= target && nums[middle - 1] >= target)
                    right = middle - 1;
                else
                    left = middle + 1;
            }
            else
            {
                if (nums[middle + 1] <= target && nums[right] >= target)
                    left = middle + 1;
                else
                    right = middle - 1;

            }

        }
        return -1;
    }
};

class Solution2
{
public:
    int search(vector<int>& nums, int target)
    {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        while (left <= right)
        {
            int middle = (left + right) / 2;
            int val = nums[middle];
            int index = middle;
            if (val == target)
                return index;
            else if (val > target)
            {
                if (nums[left] <= target)
                {
                    right = middle - 1;
                }
                else
                {
                    left = middle + 1;
                }
            }
            else
            {
                if (nums[right] >= target)
                {
                    left = middle + 1;
                }
                else
                {
                    right = middle - 1;
                }
            }

        }
        return -1;

    }
};

int main(void)
{
    Solution sy;
    std::vector<int> v = {4, 5, 6, 7, 0, 1, 2};
    std::cout << sy.search(v, 4) << std::endl;

    return 0;
}
