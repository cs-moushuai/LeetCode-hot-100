/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function(nums1, nums2) {
    let i = 0,
        j = 0,
        k = 0;
    let m = nums1.length,
        n = nums2.length;
    let nums = new Array();
    while (k != (m + n)) {
        if (i == m) {
            nums = nums.concat(nums2.slice(j));
            break;
        }
        if (j == n) {
            nums = nums.concat(nums1.slice(i))
            break;
        }
        if (nums1[i] < nums2[j]) {
            nums.push(nums1[i++]);
        } else {
            nums.push(nums2[j++]);
        }
    }

    k = m + n;
    return k % 2 == 0 ? (nums[k/2] + nums[k/2-1]) / 2.0 : nums[Math.floor(k/2)];

};
console.log(findMedianSortedArrays([1,2], [3, 4]));