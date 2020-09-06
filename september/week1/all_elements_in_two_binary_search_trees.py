# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorder(self, root: TreeNode) -> List:
        return self.inorder(root.left) + [root.val] + self.inorder(root.right) if root else []
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        arr1 = self.inorder(root1)
        arr2 = self.inorder(root2)
        n = len(arr1)
        m = len(arr2)
        i = j = 0
        ret = []
        while i < n and j < m:
            if arr1[i]<arr2[j]:
                ret.append(arr1[i])
                i += 1
            else:
                ret.append(arr2[j])
                j += 1
        while i < n:
            ret.append(arr1[i])
            i += 1
        while j < m:
            ret.append(arr2[j])
            j += 1
        return ret
        
