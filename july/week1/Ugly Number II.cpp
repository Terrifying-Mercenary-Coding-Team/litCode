#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int UglyNumber[1691];

class Solution {
public:
	int nthUglyNumber(int n) {
		int turn[3] = { 0,0,0 };
		int L[3] = { 2,3,5 };
		int useN[3] = { 2,3,5 };

		UglyNumber[0] = 1;

		for (int i = 1; i < n; i++)
		{
			int tmp = min(L[0],min(L[1],L[2]));
			UglyNumber[i] = tmp;
			for (int j = 0; j <= 2; j++)
			{
				if (tmp == L[j])
				{
					turn[j]++;
					L[j] = UglyNumber[turn[j]] * useN[j];
				}
			}

		}

		return UglyNumber[n-1];
	}
};

int main()
{
	Solution s;
	int ans = s.nthUglyNumber(10);

	cout << ans;
}

//1 2 4 8 16 32 64 128 256 512
//1 3 9 27 81 273 819
//1 5 25 125 625 1225