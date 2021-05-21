/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permute = function(nums) {
    let dfs = function(first) {
        if (first === n) {
            res.push([...nums]);
            return;
        }
        for (let i = first; i < n; ++i) {
            [nums[i], nums[first]] = [nums[first], nums[i]];
            dfs(first+1);
            [nums[i], nums[first]] = [nums[first], nums[i]];
        }
    };
    let n = nums.length;
    let res = [];
    dfs(0);
    return res;
};

console.log(permute([3,2,1]))
