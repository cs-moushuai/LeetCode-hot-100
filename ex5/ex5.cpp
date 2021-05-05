#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int len = s.size();
        if (len <= 1)
            return s;
        vector<vector<int>> dp(len, vector<int>(len, 0));
        int maxlen = 1;
        int begin = 0;
        for (int i = 0; i < len; ++i)
        {
            dp[i][i] = 1;
        }
        for (int L = 2; L <= len; ++L)
        {
            for (int i = 0; i < len; ++i)
            {
                int j = i + L - 1;
                if (j >= len)
                    continue;
                if (s[i] != s[j])
                    dp[i][j] = 0;
                else
                {
                    if (j - i + 1 <= 3)
                    {
                        dp[i][j] = true;
                    }
                    else
                    {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
                if (dp[i][j] && j - i + 1 > maxlen)
                {
                    maxlen = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substr(begin, maxlen);

    }
};

int main(void)
{

    return 0;
}
