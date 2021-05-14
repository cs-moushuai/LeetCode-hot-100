#!/usr/bin/env python3

from typing import List


class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def dfs(curr, l, r):
            if l == r == n:
                res.append(curr)
                return
            if l < n:
                dfs(curr+'(', l+1, r)
            if r < l:
                dfs(curr+')', l, r+1)
        res = []
        dfs("", 0, 0)
        return res

print(Solution().generateParenthesis(3))
