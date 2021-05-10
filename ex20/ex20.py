#!/usr/bin/env python3

class Solution:
    def isValid(self, s: str) -> bool:
        if len(s) % 2 == 1:
            return False
        stack = list()
        pairs = {
            '(': ')',
            '{': '}',
            '[': ']'
        }
        for ch in s:
            if ch in pairs:
                stack.append(pairs[ch])
            else:
                if not stack or stack[-1] != ch:
                    return False
                stack.pop()
        return not stack


class Solution2:
    def isValid(self, s: str) -> bool:
        st = []
        for i in s:
            if i == '(' or i == '{' or i == '[':
                st.append(i)
            else:
                if i == ')' and len(st) and st[-1] == '(':
                    st.pop()
                elif i == '}' and len(st) and st[-1] == '{':
                    st.pop()
                elif i == ']' and len(st) and st[-1] == '[':
                    st.pop()
                else:
                    return False
        return False if len(st) else True


sy = Solution()
print(sy.isValid('(()'))
print(sy.isValid('(()[]){}'))
print(sy.isValid('(['))
