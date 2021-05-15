from typing import List


class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        for i in range(n-1, 0, -1):
            if nums[i] > nums[i-1]:
                min_index = i
                for j in range(i+1, n):
                    # print(j, ',', nums[j])
                    if nums[j] > nums[i-1] and nums[j] < nums[min_index]:
                        min_index = j
                # print(nums[min_index])
                nums[i-1], nums[min_index] = nums[min_index], nums[i-1]
                nums[i:] = sorted(nums[i:])
                return
        nums.reverse()

obj = Solution()
nums = [1,3,2]
obj.nextPermutation(nums)
print(nums)