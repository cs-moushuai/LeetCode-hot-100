function ListNode(val, next) {
    this.val = (val === undefined ? 0 : val)
    this.next = (next === undefined ? null : next)
}

/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var mergeTwoLists = function(l1, l2) {
    let l = new ListNode();
    let p = l;
    while (l1 || l2) {
        if (!l1) {
            p.next = l2;
            break;
        }
        if (!l2) {
            p.next = l1;
            break;
        }
        if (l1.val < l2.val) {
            p.next = new ListNode(l1.val);
            p = p.next;
            l1 = l1.next;
        } else {
            p.next = new ListNode(l2.val);
            p = p.next;
            l2 = l2.next;
        }

    }
    return l.next;
};