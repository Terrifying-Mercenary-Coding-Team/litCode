# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # Optimal Solution: Space Complexity O(1)
    def detectCycle(self, head: ListNode) -> ListNode:
        fast = head
        slow = head
        inter = None

        while fast is not None and fast.next is not None:
            slow = slow.next
            fast = fast.next.next

            if slow == fast:
                inter = slow
                break

        if inter is None:
            return None

        ptr1 = head
        ptr2 = inter
        while ptr1 != ptr2:
            ptr1 = ptr1.next
            ptr2 = ptr2.next

        return ptr1
        
        
