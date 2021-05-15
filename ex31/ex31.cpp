#include <bits/stdc++.h>

using namespace std;


class Solution {
    public:
        void nextPermutation(vector<int>& nums) {
            int n = nums.size();
            int max_index = n-1;
            for (int r = n - 2; r >= 0; r--)
            {
                if (nums[max_index] > nums[r])
                {
                    int min_index = max_index;
                    for (int i = r+1; i < n; ++i) {
                        if (nums[i] > nums[r] && nums[i] < nums[min_index])
                            min_index = i;

                    }
                    swap(nums[r], nums[min_index]);
                    sort(nums.begin() + r+1, nums.end());
                    return;
                }
                if (nums[r] > nums[max_index])
                    max_index = r;
            }
            reverse(nums.begin(), nums.end());
            return;
        }
};


class Solution2 {
    public:
        void nextPermutation(vector<int>& nums) {
            auto min_nums = nums.rbegin();
            for (auto r = nums.rbegin(); r+1!=nums.rend(); r++) {
                if (*r < *min_nums) {
                    min_nums = r;
                }
                if (*r > *(r+1)) {
                    swap(*(r+1), *min_nums);
                    return;
                }
            }
            reverse(nums.begin(), nums.end());
        }
};

int main(void)
{
    return 0;
}
