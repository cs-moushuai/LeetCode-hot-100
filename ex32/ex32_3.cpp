#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int left, right, maxlength;
        int n = s.size();
        left = right = maxlength = 0;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '(')
            {
                left++;
            }
            else
            {
                right++;
            }
            if (left == right)
                maxlength = max(maxlength, 2 * right);
            else if (right > left)
                left = right = 0;
        }
        left = right = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            if (s[i] == '(')
            {
                left++;
            }
            else
            {
                right++;
            }
            if (left == right)
                maxlength = max(maxlength, 2 * right);
            else if (left > right)
                left = right = 0;
        }
        return maxlength;

    }
};

int main(void)
{

    return 0;
}
