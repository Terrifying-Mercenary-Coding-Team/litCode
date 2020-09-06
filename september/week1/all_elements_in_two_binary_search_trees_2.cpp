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
    void inorder(TreeNode *root, vector<int> &arr){
        if(root){
            inorder(root->left,arr);
            arr.push_back(root->val);
            inorder(root->right,arr);
        }
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> arr1,arr2,ret;
        inorder(root1,arr1);
        inorder(root2,arr2);
        int i=0,j=0,n=arr1.size(),m=arr2.size();
        while(i<n && j<m){
            if(arr1[i]<arr2[j]){
                ret.push_back(arr1[i++]);
            }
            else{
                ret.push_back(arr2[j++]);
            }
        }
        while(i<n){
            ret.push_back(arr1[i++]);
        }
        while(j<m){
            ret.push_back(arr2[j++]);
        }
        return ret;
    }
};
