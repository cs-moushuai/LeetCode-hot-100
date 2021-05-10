/**
 * @param {string} s 
 * @returns {boolean}
 */
var isValid = function(s) {
    if (s.length % 2 === 1) {
        return false;
    }
    const stk = [];
    const pairs = new Map([
        ['(', ')'],
        ['{', '}'],
        ['[', ']']
    ]);
    for (let ch of s.split('')) {
        if (pairs.has(ch)) {
            stk.push(pairs.get(ch));
        } else {
            if (!stk.length || stk[stk.length - 1] !== ch) {
                return false;
            }
            stk.pop();
        }
    };
    return !stk.length;

};

console.log(isValid('([}}])'))