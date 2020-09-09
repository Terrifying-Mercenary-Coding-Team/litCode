#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

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
	int ans = 0;

	int sumRootToLeaf(TreeNode* root) {
		string tmp = "";
		dfs(root, tmp);

		return ans;
	}

	int btoi(string num) {
		int ret = 0;
		int cnt = 1;
		
		while (!num.empty()) {
			ret += (num.back()-'0') * cnt;
			cnt *= 2;
			num.pop_back();
		}
		
		return ret;
	}
	void dfs(TreeNode* node, string num) {
		num += to_string(node->val);
		if (node->left == nullptr && node->right== nullptr) {
			ans += btoi(num);
			return;
		}

		if(node->left!=nullptr)
			dfs(node->left, num);
		if(node->right!=nullptr)
			dfs(node->right, num);
	}
};

int main(void)
{
	Solution sol;

	TreeNode* t1 = new TreeNode(0);
	TreeNode* t2 = new TreeNode(1);
	TreeNode* t3 = new TreeNode(0,t1,t2);
	TreeNode* t4 = new TreeNode(0);
	TreeNode* t5 = new TreeNode(1);
	TreeNode* t6 = new TreeNode(1,t4,t5);
	TreeNode* root = new TreeNode(1, t3, t6);
	cout << sol.sumRootToLeaf(root);
	return 0;
}