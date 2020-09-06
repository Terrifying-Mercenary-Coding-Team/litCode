#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
	int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
		int size = A.size();

		vector < pair < int, int > > pv;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (A[i][j] == 1)
					pv.push_back({ i,j });
			}
		}

		int ans = 0;
		set < pair < int, int > > s;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				for (int k = 0; k < size; k++) {
					for (int l = 0; l < size; l++) {
						if (s.count({ i - j,l - k }) != 0)
							continue;
						s.insert({ i - j,l - k });
						ans = max(ans, check(i, j, k, l, pv, B));
					}
				}
			}
		}

		return ans;
	}

	int check(int l, int r, int u, int d, vector< pair < int , int > >& pv, vector<vector<int>>& B)
	{
		int x = l - r;
		int y = u - d;

		int ret = 0;
		for (int i = 0; i < pv.size(); i++) {
			int next_x = pv[i].first + x;
			int next_y = pv[i].second + y;

			if (next_x < 0 || next_x >= B.size() || next_y < 0 || next_y >= B.size())
				continue;

			if (B[next_x][next_y] == 1)
				ret++;
		}
		
		return ret;
	}
};

int main(void)
{
	vector < vector < int > > a = {{1, 1, 0},
		{0, 1, 0},
		{0, 1, 0}};
	vector < vector < int > > b = { {0, 0, 0},
		{0, 1, 1},
		{0, 0, 1} };

	Solution sol;
	cout << sol.largestOverlap(a, b) << endl;
	return 0;
}