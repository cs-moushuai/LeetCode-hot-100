#!/usr/bin/env python3

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        dummy = ListNode(0, head)
        p1 = dummy
        p2 = head
        while n:
            p2 = p2.next
            n -= 1
        while p1:
            if not p2:
                if p1 == dummy:
                    return head.next
                else:
                    p1.next = p1.next.next
                    return head
            p1 = p1.next
            p2 = p2.next
