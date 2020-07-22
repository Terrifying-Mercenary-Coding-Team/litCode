#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>

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
    int widthOfBinaryTree(TreeNode* root) {
        // node,index
        queue<pair<TreeNode*,unsigned long long>> q;
        q.push({root,1});
        unsigned long long ret=1;
        while(!q.empty()){
            int s=q.size();
            unsigned long long std=q.front().second;
            for(int i=0;i<s;i++){
                TreeNode* cur=q.front().first;
                unsigned long long index=q.front().second;
                q.pop();
                if(cur->left)   q.push({cur->left,index*2});   
                if(cur->right) q.push({cur->right,index*2+1});
                ret = max(ret,index-std+1);
            }
        }
        return ret;
    }
};

int main(){
    Solution sol;
    TreeNode root(1),first_l(3),first_r(2),second_l(5),second_r(9),third_l(6),third_r(7);
    root.left = &first_l;
    root.right = &first_r;
    first_l.left = &second_l;
    first_r.right = &second_r;
    second_l.left = &third_l;
    second_r.right = &third_r;

    cout << sol.widthOfBinaryTree(&root) << endl;

    return 0;
}
