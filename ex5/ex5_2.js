/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(s) {
    let n = s.length;
    let maxlen = 0;
    let res;

    function centerSpread(i, j) {
        while (i >= 0 && j < n && s[i] === s[j]) {
            i--;
            j++;
        }
        return s.substring(i + 1, j);
    }
    for (let i = 0; i < n; ++i) {
        let oddstring = centerSpread(i, i)
        let evenstring = centerSpread(i, i + 1)
        let maxstring = oddstring.length > evenstring.length ? oddstring : evenstring;
        if (maxstring.length > maxlen) {
            maxlen = maxstring.length;
            res = maxstring;
        }
    }
    return res;

};