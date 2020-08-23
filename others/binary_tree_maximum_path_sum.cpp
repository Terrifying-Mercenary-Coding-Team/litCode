#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int ans=-987654321;
    int traverse(TreeNode* root){
        if(!root)   return 0;
        int left = max(traverse(root->left),0);
        int right = max(traverse(root->right),0);
        int ret = root->val + left + right;

        ans = max(ret,ans);

        return root->val + max(left,right);
    }

    int maxPathSum(TreeNode* root) {
        traverse(root);

        return ans;
    }
};
