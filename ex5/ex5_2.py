class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        maxlen = 0
        res = ""

        def centerSpread(i, j):
            while i >= 0 and j < n and s[i] == s[j]:
                i -= 1
                j += 1
            return s[i+1:i+1+j-i+1-2]
        for i in range(n):
            oddstring = centerSpread(i, i)
            evenstring = centerSpread(i, i+1)
            maxstring = oddstring if len(oddstring) > len(
                evenstring) else evenstring
            if len(maxstring) > maxlen:
                maxlen = len(maxstring)
                res = maxstring
        return res