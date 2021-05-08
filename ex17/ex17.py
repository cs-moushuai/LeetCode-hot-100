#!/usr/bin/env python3

from typing import List


class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        def dfs(path: str, i: int):
            nonlocal res
            if i == n:
                res.append(path)
            else:
                for c in mapped[digits[i]]:
                    path += c
                    dfs(path, i+1)
                    path = path[:-1]

        n = len(digits)
        if n == 0:
            return []
        res = []
        mapped = {
            '2': ['a', 'b', 'c'],
            '3': ['d', 'e', 'f'],
            '4': ['g', 'h', 'i'],
            '5': ['j', 'k', 'l'],
            '6': ['m', 'n', 'o'],
            '7': ['p', 'q', 'r', 's'],
            '8': ['t', 'u', 'v'],
            '9': ['w', 'x', 'y', 'z']
        }
        dfs("", 0)
        return res


obj = Solution()
print(obj.letterCombinations("23"))