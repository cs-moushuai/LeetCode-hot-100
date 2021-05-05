#!/usr/bin/env python3

from typing import List


class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        m = len(nums1)
        n = len(nums2)
        nums = []
        i = j = 0
        while True:
            if i == m:
                nums.extend(nums2[j:])
                break
            if j == n:
                nums.extend(nums1[i:])
                break
            if nums1[i] < nums2[j]:
                nums.append(nums1[i])
                i += 1
            else:
                nums.append(nums2[j])
                j += 1
        k = m + n
        return nums[k//2] if k % 2 == 1 else (nums[k//2] + nums[k//2-1])/2


sy = Solution()
print(sy.findMedianSortedArrays([1, 3], [2]))
