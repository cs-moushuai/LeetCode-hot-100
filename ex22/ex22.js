/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
    var dfs = function(curr, l, r) {
        if (l == n && r == n) {
            res.push(curr);
            return;
        }
        if (l < n) {
            dfs(curr + '(', l + 1, r);
        }
        if (r < l) {
            dfs(curr + ')', l, r + 1);
        }

    }
    res = [];
    dfs("", 0, 0);
    return res;
};

console.log(generateParenthesis(3));