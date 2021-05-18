from typing import List


class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        def binarySearch(lower):
            l = 0
            r = n - 1
            ans = n
            while l <= r:
                mid = (l+r)//2
                if nums[mid] > target or lower and nums[mid] == target:
                    r = mid - 1
                    ans = mid
                else:
                    l = mid + 1
            return ans
        n = len(nums)
        l = binarySearch(True)
        r = binarySearch(False) - 1
        if l <= r and r < n and nums[l] == target:
            return [ l, r ]
        return [ -1, -1 ]


print(
    Solution().searchRange(
        [5, 7, 7, 8, 8, 10], 9
    )
)
