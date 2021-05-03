/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    let charset = new Set();
    let l, r;
    l = r = 0;
    let maxlen = 0;
    while (r < s.length) {
        if (!charset.has(s[r])) {
            charset.add(s[r]);
            maxlen = Math.max(maxlen, r - l + 1);
            r++;
        } else {
            charset.delete(s[l]);
            l++;
        }
    }
    return maxlen;
};

console.log(lengthOfLongestSubstring("abba"));