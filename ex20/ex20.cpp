#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        int n = s.size();
        if (n % 2 == 1)
            return false;
        stack<char> st;
        unordered_map<char, char> hashtable = {{'(', ')'}, {'{', '}'}, {'[', ']'}};
        for (auto &c : s)
        {
            if (hashtable.count(c))
            {
                st.push(hashtable[c]);
            }
            else
            {
                if (st.empty() || st.top() != c)
                    return false;
                st.pop();
            }
        }
        return st.empty();

    }
};

int main(void)
{

    return 0;
}
