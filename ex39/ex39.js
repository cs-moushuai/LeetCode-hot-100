/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum = function(candidates, target) {
    let res = [];
    let n = candidates.length;
    candidates.sort((a, b) => a - b);
    let backtracing = function(path, sum, i) {
        if (sum === target) {
            res.push([...path]);
            return;
        }
        for (let j = i; j < n; ++j) {
            if (sum + candidates[j] > target)
                return;
            path.push(candidates[j]);
            backtracing(path, sum + candidates[j], j);
            path.pop();
        }

    };
    backtracing([], 0, 0);
    return res;
};

console.log(combinationSum([2, 9, 5, 6], 8))