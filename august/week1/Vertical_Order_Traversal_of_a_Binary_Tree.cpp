#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
	
};
 
bool compare(pair < int, int > a, pair < int, int > b)
{
	return a.second > b.second;
}

class Solution {
public:
	vector < vector < int > > verticalTraversal(TreeNode* root) {

		vector < vector < int > > t;
		map < int, vector < pair < int, int > > > m;
		traversal(root, m, 0, 0);

		for (auto& tmp : m) {
			//cout << tmp.first << "a" << endl;
			sort(tmp.second.begin(), tmp.second.end(), compare);
			vector < int > tmp2;
			for (auto& v : tmp.second)
				tmp2.push_back(v.first);
			t.push_back(tmp2);
		}
		return t;
	}

	void traversal(TreeNode* node, map < int, vector < pair < int, int > > > &m, int x, int y) {
		if (node == nullptr)
			return;

		traversal(node->left, m, x - 1, y - 1);
		if (m.count(x) == 0) {
			vector < pair < int , int > > v;
			v.push_back({ node->val, y});
			m[x] = v;
		}
		else {
			m[x].push_back({ node->val, y} );
		}
		traversal(node->right, m, x + 1, y - 1);
	}
};

int main(void)
{
	Solution sol;
	
	TreeNode* b = new TreeNode(9);
	TreeNode* d = new TreeNode(15);
	TreeNode* e = new TreeNode(7);
	TreeNode* c = new TreeNode(20, d, e);
	TreeNode* root = new TreeNode(3, b, c);

	vector < vector < int > > ans = sol.verticalTraversal(root);

	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}