# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # Naive Solution: Space Complexity O(N)
    def detectCycle(self, head: ListNode) -> ListNode:
        cur = head
        visited = []
        
        while cur is not None and cur not in visited:
            visited.append(cur)
            cur = cur.next

        if cur is None:
            return None

        return cur
