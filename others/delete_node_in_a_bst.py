# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deleteNode(self, root: TreeNode, key: int) -> TreeNode:
        def findMaxNode(root: TreeNode, proot: TreeNode):
            if root.right:
                return findMaxNode(root.right, root)
            else:
                return root, proot

        def findMinNode(root: TreeNode, proot: TreeNode):
            if root.left:
                return findMinNode(root.left, root)
            else:
                return root, proot
            
        def findNode(root: TreeNode, proot: TreeNode, key: int):
            if not root:
                return None, None
            if root.val == key:
                return root, proot
            elif root.val < key:
                return findNode(root.right, root, key)
            else:
                return findNode(root.left, root, key)

        tar, ptar = findNode(root, root, key)
        if not tar:
            return root

        if tar.left:
            tmp, ptmp = findMaxNode(tar.left, tar)
            tar.val = tmp.val
            if ptmp is tar:
                if tmp.left:
                    ptmp.left = tmp.left
                else:
                    ptmp.left = None
            else:
                if tmp.left:
                    ptmp.right = tmp.left
                else:
                    ptmp.right = None
        elif tar.right:
            tmp, ptmp = findMinNode(tar.right, tar)
            tar.val = tmp.val
            if ptmp is tar:
                if tmp.right:
                    ptmp.right = tmp.right
                else:
                    ptmp.right = None
            else:
                if tmp.right:
                    ptmp.left = tmp.right
                else:
                    ptmp.left = None
        else:
            if tar is ptar:
                root = None
            else:
                if tar is ptar.left:
                    ptar.left = None
                else:
                    ptar.right = None
        return root
