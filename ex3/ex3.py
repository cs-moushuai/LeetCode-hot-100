#!/usr/bin/env python3

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        charset = set()
        l = r = 0
        maxlen = 0
        while r < len(s):
            if s[r] not in charset:
                charset.add(s[r])
                maxlen = max(maxlen, r - l + 1)
                r += 1
            else:
                charset.remove(s[l])
                l += 1
        return maxlen

sy = Solution()
print(sy.lengthOfLongestSubstring("abba"))