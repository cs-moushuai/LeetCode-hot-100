from typing import List

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        n = len(candidates)
        res = []

        def backtracking(path, pos, target):
            # print(path)
            if target == 0:
                res.append(path)
                return
            elif target < 0:
                return
            else:
                for i in range(pos, n):
                    backtracking(path+[candidates[i]], i, target-candidates[i])
        backtracking([], 0, target)
        return res

print(Solution().combinationSum([2, 3, 4, 6], 8))