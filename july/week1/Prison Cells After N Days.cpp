#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	vector<int> prisonAfterNDays(vector<int>& cells, int N) {
		if (cells[0] == 0 && cells[7] == 0)
		{
			long long day = findRule(cells, N);

			N %= day;

			return repeatRule(cells, N);
		}

		else
		{
			vector<int> tmp = repeatRule(cells, 1);
			N--;

			long long day = findRule(tmp, N);

			N %= day;

			return repeatRule(tmp, N);
		}
	}

	bool checkSameVectors(vector<int>& A, vector<int>& B)
	{
		for (int i = 0; i < 8; i++) if (A[i] != B[i]) return false;

		return true;
	}

	vector<int> repeatRule(vector<int>& cells, int N)
	{
		vector<int> ret=cells;

		while (N--)
		{
			ret = Rule(ret);
		}

		return ret;
	}

	vector<int> Rule(vector<int>& cells)
	{
		vector<int> ret(8);

		for (int i = 0; i < 8; i++)
		{
			if (i == 0 || i == 7) ret[i] = 0;
			else
			{
				if (cells[i - 1] == cells[i + 1]) ret[i] = 1;
				else ret[i] = 0;
			}
		}

		return ret;
	}

	long long findRule (vector<int>& cells, int N)
	{
		long long day = 0;
		vector<int> tmp = Rule(cells);

		//for (int i = 0; i < 8; i++) cout << cells[i] << " ";
		//cout << endl << endl;

		while (!(checkSameVectors(cells, tmp)))
		{
			//for (int i = 0; i < 8; i++) cout << tmp[i] << " ";
			//cout << endl;
			day++;
			tmp = Rule(tmp);
			//cout << N <<endl;
			if (day > N) break;
		}

		return day+1;
	}
};

int main()
{
	vector<int> cells(8);
	cells[0] = 1;
	cells[1] = 0;
	cells[2] = 0;
	cells[3] = 1;
	cells[4] = 0;
	cells[5] = 0;
	cells[6] = 1;
	cells[7] = 0;

	int N = 1000000000;

	Solution s;

	vector<int> ans = s.prisonAfterNDays(cells, N);

	for (int i = 0; i < 8; i++) cout << ans[i] << " ";
}