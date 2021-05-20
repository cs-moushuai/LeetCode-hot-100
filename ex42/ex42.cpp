#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int trap(vector<int>& height)
    {
        int n = height.size();
        int l = 0, r = n - 1;
        int lmax = 0, rmax = 0;
        int ans = 0;
        while (l < r)
        {
            lmax = max(height[l], lmax);
            rmax = max(height[r], rmax);
            if (height[l] < height[r])
                ans += lmax - height[l++];
            else
                ans += rmax - height[r--];
        }
        return ans;
    }
};

int main(void)
{

    return 0;
}
