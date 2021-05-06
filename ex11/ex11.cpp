#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxArea(vector<int>& height)
    {
        int len = height.size();
        int l = 0, r = len - 1;
        int maxarea = 0;
        while (l < r)
        {
            int high = min(height[l], height[r]);
            int wide = r - l;
            int area = wide * high;
            maxarea = max(area, maxarea);

            if (height[l] < height[r])
            {
                ++l;
            }
            else
            {
                --r;
            }
        }
        return maxarea;

    }
};

int main(void)
{

    return 0;
}
