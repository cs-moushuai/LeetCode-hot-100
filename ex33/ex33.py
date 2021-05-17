
from typing import List


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        def searchImplement(l, r):
            mid = (l+r)//2
            if l > r:
                return -1
            if nums[mid] == target:
                return mid
            if nums[l] == target:
                return l
            if nums[r] == target:
                return r
            if nums[l] <= nums[mid]:
                if nums[l] < target and target < nums[mid]:
                    return searchImplement(l+1, mid-1)
                else:
                    return searchImplement(mid+1, r-1)
            else:
                if nums[mid] < target and target < nums[r]:
                    return searchImplement(mid+1, r)
                else:
                    return searchImplement(l+1, mid-1)
        return searchImplement(0, len(nums)-1)

print(Solution().search([8,1,2,3,4,5,6,7], 6))