#!/usr/bin/env python3

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        carry = 0
        head = p = ListNode()
        while l1 or l2:
            val1 = l1.val if l1 else 0
            val2 = l2.val if l2 else 0
            sum = val1 + val2 + carry
            p.next = ListNode(sum % 10)
            p = p.next
            carry = sum // 10
            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next
        if carry > 0:
            p.next = ListNode(1)
        return head.next


class Solution2:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        carry = 0
        head = p = None
        while l1 or l2:
            val1 = l1.val if l1 else 0
            val2 = l2.val if l2 else 0
            sum = val1 + val2 + carry
            if not head:
                head = p = ListNode(sum % 10)
                carry = sum // 10
            else:
                p.next = ListNode(sum % 10)
                p = p.next
                carry = sum // 10
            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next
        if carry > 0:
            p.next = ListNode(1)
        return head
