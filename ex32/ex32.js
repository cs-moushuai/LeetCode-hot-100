/**
 * @param {string} s
 * @return {number}
 */
var longestValidParentheses = function(s) {

    let n = s.length;
    let dp = new Array(n).fill(0);
    let maxans = 0;
    for (let i = 1; i < n; ++i) {
        if (s[i] == ')') {
            if (s[i - 1] == '(')
                dp[i] = (i - 2 >= 0 ? dp[i - 2] : 0) + 2;
            else if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(')
                dp[i] = dp[i - 1] + 2 + (i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0);
        }
        maxans = Math.max(maxans, dp[i]);

    }
    return maxans;


};
console.log(longestValidParentheses('(()))'))