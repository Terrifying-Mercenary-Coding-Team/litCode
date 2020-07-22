#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <string>

using namespace std;

set < string > s;
class Solution {
public:
	vector<int> prisonAfterNDays(vector<int>& cells, int N) {
		vector < int > tmp = cells;
		tmp[0] = tmp[7] = 0;
		for (int i = 1; i < 7; i++) {
			tmp[i] = (cells[i - 1] == cells[i + 1]) ? 1 : 0;
		}
		if (N == 1)
			return tmp;

		vector < int > ans = tmp;

		int num = getNum(tmp, 0);
		num = (N - 1) % num;
		//cout << num<<endl;
		
		for (int j = 0; j < num; j++) {
			for (int i = 1; i < 7; i++) {
				tmp[i] = (ans[i - 1] == ans[i + 1]) ? 1 : 0;
			}
			ans = tmp;
		}
		return tmp;
	}

	int getNum(vector<int>& cells, int n) {
		string str = "";
		for (int i = 0; i < cells.size(); i++)
			str += cells[i];

		if (s.count(str) == 0) {
			s.insert(str);
		}
		else {
			return n;
		}

		vector < int > tmp = cells;
		tmp[0] = tmp[7] = 0;
		for (int i = 1; i < 7; i++) {
			tmp[i] = (cells[i - 1] == cells[i + 1]) ? 1 : 0;
		}
		
		return getNum(tmp, n + 1);
	}
};

int main(void)
{
	vector < int > arr = { 1,1,0,0,0,0,0,1 };
	Solution sol;
	vector < int > ans = sol.prisonAfterNDays(arr, 8);

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	return 0;
}