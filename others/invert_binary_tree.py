# Definition for a binary tree node.
class TreeNode:
     def __init__(self, val=0, left=None, right=None):
         self.val = val
         self.left = left
         self.right = right


class Solution:
    def traverse(self, source, target):
        target.val = source.val
        if source.left:
            target.right = TreeNode()
            self.traverse(source.left, target.right)
        if source.right:
            target.left = TreeNode()
            self.traverse(source.right, target.left)


    def invertTree(self, root: TreeNode) -> TreeNode:
        if not root:
            return None
        new_root = TreeNode()
        self.traverse(root, new_root)
        return new_root


if __name__ == "__main__":
    sl = TreeNode(2, TreeNode(1), TreeNode(3))
    sr = TreeNode(7, TreeNode(6), TreeNode(9))
    root = TreeNode(4, sl, sr)
    sol = Solution()
    new_root = sol.invertTree(root)
    queue = [new_root]
    while queue:
        cur = queue.pop(0)
        print(cur.val)
        if cur.left:
            queue.append(cur.left)
        if cur.right:
            queue.append(cur.right)




