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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ret;
        stack<TreeNode *> s;
        s.push(root1);
        while(!s.empty()){
            TreeNode *cur = s.top();
            s.pop();
            if(cur==nullptr)  continue;
            ret.push_back(cur->val);
            s.push(cur->left);
            s.push(cur->right);
        }
        s.push(root2);
        while(!s.empty()){
            TreeNode *cur = s.top();
            s.pop();
            if(cur==nullptr)  continue;
            ret.push_back(cur->val);
            s.push(cur->left);
            s.push(cur->right);
        }
        sort(ret.begin(),ret.end());
        return ret;
    }
};
