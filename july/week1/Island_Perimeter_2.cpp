#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
class Solution {
public:
	int islandPerimeter(vector<vector<int>>& grid) {
		int row = grid.size();
		int col = grid[0].size();

		int ans = 0;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {

				if (grid[i][j] == 0)
					continue;

				for (int k = 0; k < 4; k++) {
					int next_r = i + dy[k];
					int next_c = j + dx[k];
					if (next_r < 0 || next_c < 0 || next_r >= row || next_c >= col || grid[next_r][next_c] == 0) {
						ans++;
						continue;
					}
				}
			}
		}
		return ans;
	}
};

int main(void)
{
	vector < vector < int > > v = { {0, 1, 0, 0},
		{1, 1, 1, 0},
		{0, 1, 0, 0},
	{1, 1, 0, 0} };
	Solution sol;
	cout << sol.islandPerimeter(v);
	return 0;
}