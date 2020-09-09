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
    vector<string> arr;
    void dfs(TreeNode *root, string cur){
        cur += '0'+root->val;
        if(!(root->left) && !(root->right)){
            arr.push_back(cur);
            return;
        }
        if(root->left)  dfs(root->left,cur);
        if(root->right) dfs(root->right,cur);
    }
    int convert(string tar){
        int ret=0,mul=1;
        for(int i=tar.size()-1;i>=0;i--){
            ret += (tar[i]-'0')*mul;
            mul *= 2;
        }
        return ret;
    }
    int sumRootToLeaf(TreeNode* root) {
        arr.clear();
        arr.resize(0);
        dfs(root,"");
        int ret = 0;
        for(string e: arr)  ret += convert(e);
        return ret;
    }
};
