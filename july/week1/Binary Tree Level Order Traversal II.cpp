#include<iostream>
#include<vector>

using namespace std;

// Definition for a binary tree node.
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
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> ans;

		traverse(ans, 0, root);
		reverse(ans.begin(), ans.end());
		int len = ans.size();
		for (int i = 0; i < len; i++) reverse(ans[i].begin(), ans[i].end());

		return ans;
	}

	void traverse(vector<vector<int>>  &v, int depth, TreeNode* tree)
	{
		if (tree != nullptr)
		{
			if (depth >= v.size())
			{
				vector<int> vv;
				v.push_back(vv);
			}
			//cout << tree->val << v.size() << endl;
			v[depth].push_back(tree->val);
			traverse(v, depth + 1, tree->right);
			traverse(v, depth + 1, tree->left);
		}
	}
};

int main(void) {
	TreeNode* a = &TreeNode(15);
	TreeNode* b = &TreeNode(7);
	TreeNode* c = &TreeNode(20, a, b);
	TreeNode* d = &TreeNode(9);
	TreeNode* e = &TreeNode(3, d, c);

	Solution sol;
	vector < vector < int > > vvv = sol.levelOrderBottom(e);
	//cout << vvv.size();
	for (int i = 0; i < vvv.size(); i++)
	{
		for (int j = 0; j < vvv[i].size(); j++)
		{
			cout << vvv[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}