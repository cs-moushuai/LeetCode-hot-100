/**
 * @param {number[]} height
 * @return {number}
 */
var trap = function(height) {
    let n = height.length;
    let l = 0,
        r = n - 1;
    let lmax = 0,
        rmax = 0;
    let ans = 0;
    while (l < r) {
        lmax = Math.max(height[l], lmax);
        rmax = Math.max(height[r], rmax);
        if (height[l] < height[r])
            ans += lmax - height[l++];
        else
            ans += rmax - height[r--];
    }
    return ans;
};