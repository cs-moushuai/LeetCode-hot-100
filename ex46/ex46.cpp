#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        int n = nums.size();
        vector<vector<int>> res;
        function<void (int)> dfs = [&](int first)
        {
            if (first == n)
            {
                res.emplace_back(nums);
                return;
            }
            for (int i = first; i < n; ++i)
            {
                swap(nums[i], nums[first]);
                dfs(first + 1);
                swap(nums[i], nums[first]);
            }
        };
        dfs(0);
        return res;
    }
};


class Solution2
{
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        int n = nums.size();
        vector<vector<int>> res;
        function<void (vector<int>&, vector<int>&, int)> dfs = [&](vector<int> &visited, vector<int> &path, int size)
        {
            if (size == n)
            {
                res.emplace_back(path);
                return;
            }
            for (int i = 0; i < n; ++i)
            {
                if (!visited[i])
                {
                    path.emplace_back(nums[i]);
                    visited[i] = 1;
                    dfs(visited, path, size + 1);
                    visited[i] = 0;
                    path.pop_back();
                }
            }
        };
        vector<int> visited(n, 0), path;
        dfs(visited, path, 0);
        return res;
    }
};

int main(void)
{

    return 0;
}
