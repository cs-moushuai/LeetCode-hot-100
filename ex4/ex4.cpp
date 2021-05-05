#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int len1 = nums1.size();
        int len2 = nums2.size();
        vector<int> nums(len1 + len2);
        int k;
        int i, j;
        i = j = k = 0;
        while (k != (len1 + len2))
        {
            if (i == len1)
            {
                while (j != len2)
                {
                    nums[k++] = nums2[j++];
                }
                break;
            }
            if (j == len2)
            {
                while (i != len1)
                {
                    nums[k++] = nums1[i++];
                }
                break;
            }
            if (nums1[i] < nums2[j])
            {
                nums[k++] = nums1[i++];
            }
            else
            {
                nums[k++] = nums2[j++];
            }
        }
        return k % 2 == 0 ? (nums[k / 2] + nums[k / 2 - 1]) / 2.0 : nums[k / 2];

    }
};

int main(void)
{

    return 0;
}
