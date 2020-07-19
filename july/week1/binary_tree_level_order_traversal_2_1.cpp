#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) { }	
};

class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector < vector < int > > ans;

		int depth = getDepth(root, 0);
		for (int i = 0; i < depth; i++) {
			vector < int > tmp;
			ans.push_back(tmp);
		}
			
		traverse(root, ans, 0, depth - 1);

		for (int i = 0; i < ans.size(); i++) {
			for (int j = 0; j < ans[i].size(); j++)
				cout << ans[i][j] << " ";
			cout << endl;
		}

		return ans;
	}

	int getDepth(TreeNode* node, int n) {
		if (node == nullptr)
			return n;

		
		return max(getDepth(node->left, n + 1), getDepth(node->right, n + 1));
	}
	void traverse(TreeNode* node, vector < vector < int > >& v, int n, int depth) {
		if (node == nullptr)
			return;

		v[depth-n].push_back(node->val);
		traverse(node->left, v, n + 1,depth);
		traverse(node->right, v, n+1,depth);
	}
};

int main(void) {
	TreeNode* a = &TreeNode(15);
	TreeNode* b = &TreeNode(7);
	TreeNode* c = &TreeNode(20, a, b);
	TreeNode* d = &TreeNode(9);
	TreeNode* e = &TreeNode(3, d, c);
	
	Solution sol;
	vector < vector < int > > v = sol.levelOrderBottom(e);
	return 0;
}
