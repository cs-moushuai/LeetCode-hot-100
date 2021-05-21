#!/usr/bin/env python3

from typing import List


class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        def dfs(first):
            if n == first:
                res.append(nums[:])
                return
            for i in range(first, n):
                nums[i], nums[first] = nums[first], nums[i]
                dfs(first + 1)
                nums[i], nums[first] = nums[first], nums[i]

        n = len(nums)
        res = []
        dfs(0)
        return res

print(Solution().permute([2,3,1]))
