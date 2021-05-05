/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(s) {
    let n = s.length;
    if (n <= 1) {
        return s;
    }
    let dp = new Array(n);
    for (let i = 0; i < n; ++i) {
        dp[i] = new Array(n, false);
    }
    let maxlen = 1;
    let begin = 0;
    for (let i in dp) {
        dp[i][i] = true;
    }
    for (let L = 2; L <= n; ++L) {
        for (let i = 0; i < n; ++i) {
            let j = i + L - 1;
            if (j >= n) {
                break;
            }
            if (s[i] !== s[j])
                dp[i][j] = false;
            else {
                if (j - i + 1 <= 3)
                    dp[i][j] = true;
                else {
                    dp[i][j] = dp[i + 1][j - 1];
                }
            }
            if (dp[i][j] && j - i + 1 > maxlen) {
                maxlen = j - i + 1;
                begin = i;
            }
        }
    }
    return s.substring(begin, begin + maxlen);
};

console.log(longestPalindrome("babad"))