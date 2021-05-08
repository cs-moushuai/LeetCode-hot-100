/**
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations = function(digits) {
    let mapped = {

        '2': ['a', 'b', 'c'],
        '3': ['d', 'e', 'f'],
        '4': ['g', 'h', 'i'],
        '5': ['j', 'k', 'l'],
        '6': ['m', 'n', 'o'],
        '7': ['p', 'q', 'r', 's'],
        '8': ['t', 'u', 'v'],
        '9': ['w', 'x', 'y', 'z']
    };

    function dfs(path, i) {
        if (i == len) {
            res.push(path)
            return;
        }

        for (let c of mapped[digits[i]]) {
            path += c;
            dfs(path, i + 1);
            path = path.substring(0, path.length - 1)
        }
    }

    len = digits.length;
    if (len == 0)
        return [];
    res = []
    dfs("", 0);

    return res;
};
/**
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations2 = function(digits) {
    function getCharByNum(i) {
        switch (i) {
            case '2':
                return ['a', 'b', 'c'];
            case '3':
                return ['d', 'e', 'f'];
            case '4':
                return ['g', 'h', 'i'];
            case '5':
                return ['j', 'k', 'l'];
            case '6':
                return ['m', 'n', 'o'];
            case '7':
                return ['p', 'q', 'r', 's'];
            case '8':
                return ['t', 'u', 'v'];
            case '9':
                return ['w', 'x', 'y', 'z'];
            default:
                return [];
        }
    }

    function dfs(path, i) {
        if (i == len) {
            res.push(path)
            return;
        }
        arr = getCharByNum(digits[i]);

        for (let c of arr) {
            path += c;
            dfs(path, i + 1);
            path = path.substring(0, path.length - 1)
        }
    }

    len = digits.length;
    if (len == 0)
        return [];
    res = []
    dfs("", 0);

    return res;
};

console.log(letterCombinations("23"));