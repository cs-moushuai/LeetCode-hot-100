#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> res;
        int n = candidates.size();
        //auto backtracing = [&](vector<int> &path, int sum, int i) -> void
        function<void (vector<int>&, int, int)> backtracing = [&](vector<int> &path, int sum, int i) -> void
        {
            //for (auto &i: path)
                //cout << i << " ";
            //cout << endl;
            if (sum == target)
            {
                res.emplace_back(path);
                return;
            }
            else if (sum > target)
            {
                return;
            }
            else // sum < target
            {
                for (int j = i; j < n; ++j)
                {
                    path.emplace_back(candidates[j]);
                    backtracing(path, sum + candidates[j], j);
                    path.pop_back();
                }
            }

        };
        vector<int> path;
        backtracing(path, 0, 0);
        return res;
    }
};

int main(void)
{

    return 0;
}
