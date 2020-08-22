#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)   return nullptr;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *cur=q.front();
            q.pop();
            TreeNode *tmp=cur->left;
            cur->left = cur->right;
            cur->right = tmp;
            if(cur->left)   q.push(cur->left);
            if(cur->right)   q.push(cur->right);
        }

        return root;
    }
};

int main(){
    TreeNode *ll = new TreeNode(1);
    TreeNode *lr = new TreeNode(3);
    TreeNode *rl = new TreeNode(6);
    TreeNode *rr = new TreeNode(9);
    TreeNode *l = new TreeNode(2,ll,lr);
    TreeNode *r = new TreeNode(7,rl,rr);
    TreeNode *root = new TreeNode(4,l,r);

    Solution *sol = new Solution;
    TreeNode *new_root = sol->invertTree(root);
    queue<TreeNode*> q;
    q.push(new_root);
    while(!q.empty()){
        TreeNode *cur = q.front();
        q.pop();
        cout << cur->val << endl;
        if(cur->left)    q.push(cur->left);
        if(cur->right)   q.push(cur->right);
    }

    return 0;
}
