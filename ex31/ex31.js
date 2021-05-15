/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var nextPermutation = function(nums) {
    let n = nums.length;
    for (let i = n - 1; i > 0; i--) {
        if (nums[i] > nums[i - 1]) {
            let min_index = i;
            for (let j = i + 1; j < n; ++j) {
                if (nums[j] > nums[i - 1] && nums[j] <= nums[min_index])
                    min_index = j;
            }
            swap(nums, i - 1, min_index);
            reverse(nums, i, n - 1);
            return;
        }
    }
    reverse(nums, 0, n - 1);
    return;
};

function swap(nums, i, j) {
    [nums[i], nums[j]] = [nums[j], nums[i]]
}

function reverse(nums, i, j) {
    while (i < j) {
        swap(nums, i, j)
        i++
        j--
    }
}