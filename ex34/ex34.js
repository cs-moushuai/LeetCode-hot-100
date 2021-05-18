/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var searchRange = function(nums, target) {

    let n = nums.length;
    let searchBinary = function(lower) {
        let l = 0;
        let r = n - 1;
        let ans = n;
        while (l <= r) {
            let mid = Math.floor((l + r) / 2);
            //cout << nums[mid] << endl;
            if (nums[mid] > target || (lower && nums[mid] === target)) {
                r = mid - 1;
                ans = mid;
            } else {
                l = mid + 1;
            }
        }
        //cout << ans << endl;
        return ans;

    };
    let left_index = searchBinary(true);
    let right_index = searchBinary(false) - 1;
    if (left_index <= right_index && right_index < n && nums[left_index] === target) {
        return [left_index, right_index];
    }
    return [-1, -1];

};