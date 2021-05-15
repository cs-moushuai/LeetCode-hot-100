#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int n = s.size();
        if (n == 0)
            return 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int span = 1; span < n; span++)
        {
            for (int left = 0; left < n - 1; left++)
            {
                int right = left + span;
                if (right >= n)
                    break;
                dp[left][right] = max(dp[left + 1][right], dp[left][right - 1]) + ((s[left] == '(' && s[right] == ')' && (right - left + 1) % 2 == 0) ? 2 : 0);
                cout << left << "," << right << ": " << dp[left][right] << endl;
            }
        }
        return dp[0][n - 1];

    }
};

int main(void)
{
    Solution sy;
    //std::cout << sy.longestValidParentheses("(())") << std::endl;
    //std::cout << sy.longestValidParentheses("()()(())") << std::endl;
    //std::cout << sy.longestValidParentheses("") << std::endl;
    std::cout << sy.longestValidParentheses(")(((((()())()()))()(()))(") << std::endl;

    return 0;
}
