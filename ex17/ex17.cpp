#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution
{
private:
    vector<string> res;
    string str;
    int len;
    vector<char> getCharByNum(int i)
    {
        switch(i)
        {
        case '2':
            return {'a', 'b', 'c'};
        case '3':
            return {'d', 'e', 'f'};
        case '4':
            return {'g', 'h', 'i'};
        case '5':
            return {'j', 'k', 'l'};
        case '6':
            return {'m', 'n', 'o'};
        case '7':
            return {'p', 'q', 'r', 's'};
        case '8':
            return {'t', 'u', 'v'};
        case '9':
            return {'w', 'x', 'y', 'z'};
        default:
            return {};
        }
    }
    void dfs(string &path, int i)
    {
        if (i == len)
        {
            res.emplace_back(path);
            return;
        }
        vector<char> arr = getCharByNum(str[i]);

        for (auto &c : arr)
        {
            path += c;
            dfs(path, i + 1);
            path.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        str = digits;
        len = digits.size();
        if (len == 0)
            return {};
        string path;
        dfs(path, 0);

        return res;
    }
};

int main(void)
{

    return 0;
}
