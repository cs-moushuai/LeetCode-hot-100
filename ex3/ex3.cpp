#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> charset;
        int left = 0, right = 0;
        int len = s.size();
        int maxlen = 0, currlen = 0;
        while (right < len)
        {
            if (charset.count(s[right]))
            {
                left = charset[s[right]] + 1;
                for (auto i = charset.begin(); i != charset.end();)
                {
                    if (i->second < left)
                    {
                        auto tmp = i;
                        ++i;
                        charset.erase(tmp->first);
                    }
                    else
                        ++i;
                }
            }
            charset[s[right]] = right;
            currlen = right - left + 1;
            maxlen = max(currlen, maxlen);
            right++;
        }
        return maxlen;
    }
};

int main(void)
{
    Solution sy;
    cout << sy.lengthOfLongestSubstring("abba") << endl;
    return 0;
}