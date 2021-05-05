#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string centerSpread(string &str, int i, int j)
    {
        while (i >= 0 && j < str.size() && str[i] == str[j])
        {
            --i;
            ++j;
        }
        return str.substr(i + 1, j - i + 1 - 2);
    }
    string longestPalindrome(string s)
    {
        int n = s.size();
        int maxlen = 0;
        string res;
        for (int i = 0; i < n; ++i)
        {
            string oddstring = centerSpread(s, i, i);
            string evenstring = centerSpread(s, i, i + 1);
            string maxstring = oddstring.size() > evenstring.size() ? oddstring : evenstring;
            if (maxstring.size() > maxlen)
            {
                maxlen = maxstring.size();
                res = maxstring;
            }
        }
        return res;

    }
};

int main(void)
{

    return 0;
}
