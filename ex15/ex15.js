/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function(nums) {
    let len = nums.length;
    nums.sort((x,y) => x - y);
    let res = new Array();
    for (let i = 0; i < len; ++i) {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        let p1 = i + 1,
            p2 = len - 1;
        while (p1 < p2) {
            if (nums[p1] + nums[p2] + nums[i] < 0) {
                p1++;
            } else if (nums[p1] + nums[p2] + nums[i] > 0) {
                p2--;
            } else {
                res.push([nums[i], nums[p1], nums[p2]]);
                while (p1 < p2 && nums[p1] == nums[p1 + 1])
                    p1++;
                p1++;
                while (p1 < p2 && nums[p2] == nums[p2 - 1])
                    p2--;
                p2--;
            }
        }

    }
    return res;
};