#!/usr/bin/env python3

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if not l1:
            return l2
        if not l2:
            return l1
        l = ListNode()
        if l1.val < l2.val:
            l.val = l1.val
            l.next = self.mergeTwoLists(l1.next, l2)
        else:
            l.val = l2.val
            l.next = self.mergeTwoLists(l1, l2.next)
        return l