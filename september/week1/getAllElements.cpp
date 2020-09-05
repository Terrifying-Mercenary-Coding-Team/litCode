#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

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
	vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
		vector < int > ret;

		dfs(root1, ret);
		dfs(root2, ret);

		sort(ret.begin(), ret.end());

		return ret;
	}

	void dfs(TreeNode* node, vector < int >& v)
	{
		if (node == nullptr)
			return;

		v.push_back(node->val);
		dfs(node->left, v);
		dfs(node->right, v);
	}
};

int main(void)
{
	Solution sol;

	TreeNode* t1 = new TreeNode(1);
	TreeNode* t2 = new TreeNode(4);
	TreeNode* root1 = new TreeNode(2,t1,t2);
	TreeNode* t3 = new TreeNode(0);
	TreeNode* t4 = new TreeNode(3);
	TreeNode* root2 = new TreeNode(1,t3,t4);

	vector < int > ans = sol.getAllElements(root1,root2);

	for (int i = 0; i < ans.size(); i++)
		printf("%d ", ans[i]);
	return 0;
}