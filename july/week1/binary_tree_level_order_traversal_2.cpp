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

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        traverse(ret,root,0);
        reverse(ret.begin(),ret.end());

        return ret;
    }
    void traverse(vector<vector<int>> &ret, TreeNode* node, int level){
        if(!node)   return;
        if(ret.size()<=level){
            vector<int> tmp(1,node->val);
            ret.push_back(tmp);
        }
        else    ret[level].push_back(node->val);
        if(node->left)  traverse(ret,node->left,level+1);
        if(node->right) traverse(ret,node->right,level+1);
    }
}; 

int main(){
    Solution sol;
    /* Test */
    TreeNode root(3),fl(9),fr(20),sl(15),sr(7);
    root.left = &fl;
    root.right = &fr;
    root.right->left = &sl;
    root.right->right = &sr;
    /* 3 9 20 null null 15 7 */

    vector<vector<int>> ret = sol.levelOrderBottom(&root);
    for(auto &vec: ret){
        for(int &e: vec)    cout << e << " ";
        cout << endl;
    }

    return 0;
}
