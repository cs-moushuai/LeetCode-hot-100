#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<string> res;
    int len;
    void dfs(string &curr, int l, int r) {
        if (l == r && l == len) {
            res.emplace_back(curr);
            return;
        }
        if (l < len) {
            curr += "(";
            dfs(curr, l+1, r);
            curr.pop_back();
        }
        if (r < l){
            curr += ")";
            dfs(curr, l, r+1);
            curr.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        len = n;
        string str;
        dfs(str, 0, 0);
        return res;
    }
};

int main(void)
{
    Solution sy;
    auto res = sy.generateParenthesis(3);
    for (auto &i: res)
        cout << i << endl;

    return 0;
}
