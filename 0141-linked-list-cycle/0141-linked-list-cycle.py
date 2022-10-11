# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

import sys
class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        if head is None: return False
        nodes = {}
        cur = head
        while cur:
            nodes[id(cur)] = True
            if id(cur.next) in nodes.keys(): return True
            cur = cur.next
        return False