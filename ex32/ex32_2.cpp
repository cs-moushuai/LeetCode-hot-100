#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        stack<int> st;
        st.push(-1);
        int n = s.size();
        int maxans = 0;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '(')
                st.push(i);
            else
            {
                st.pop();
                if (st.empty())
                {
                    st.push(i);
                }
                else
                {
                    maxans = max(maxans, i - st.top());
                }
            }

        }

        return maxans;
    }
};

int main(void)
{

    return 0;
}
