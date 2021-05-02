#!/usr/bin/env python3

from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashable = dict()
        for i, val in enumerate(nums):
            if target-val in hashable:
                return [hashable[target-val], i]
            else:
                hashable[val] = i
        return []
