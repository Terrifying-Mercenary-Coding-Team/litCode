# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumRootToLeaf(self, root: TreeNode) -> int:
        stack = [(root, 0)]
        ret = 0
        while stack:
            node, cur_val = stack.pop()
            if node:
                nxt_val = (cur_val << 1) | node.val
                if not node.left and not node.right:
                    ret += nxt_val
                else:
                    stack.append((node.left, nxt_val))
                    stack.append((node.right, nxt_val))
        return ret
