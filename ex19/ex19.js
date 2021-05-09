function ListNode(val, next) {
    this.val = (val === undefined ? 0 : val)
    this.next = (next === undefined ? null : next)
}
/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function(head, n) {
    let dummy = new ListNode(0, head);
    let p1 = dummy;
    let p2 = head;
    while (n) {
        p2 = p2.next;
        n--;
    }
    while (p1) {
        if (!p2) {
            if (p1 == dummy) {
                return dummy.next;
            }
            else {
                p1.next = p1.next.next;
                return head;
            }
        }
        p1 = p1.next;
        p2 = p2.next;
    }
};