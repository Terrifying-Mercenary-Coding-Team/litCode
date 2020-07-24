#include<iostream>
#include<cmath>

using namespace std;

class Solution {
public:
	int hammingDistance(int x, int y) {
		int cnt = 0;

		while (x || y)
		{
			//cout << x << " " << y << endl;
			if (x % 2 != y % 2) cnt++;
			x /= 2;
			y /= 2;

		}

		return cnt;
	}
};

int main()
{
	Solution s;
	int ans = s.hammingDistance(1, 4);
	cout << ans;
}