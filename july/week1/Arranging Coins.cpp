#include<iostream>
#include<cmath>

using namespace std;

class Solution {
public:
	int arrangeCoins(int n) {
		double tmp = -0.5 + sqrt(2 * n + 0.25);
		int ret = tmp;
		return ret;
	}
};

int main()
{
	int n; scanf("%d", &n);

	Solution s;
	int ans = s.arrangeCoins(n);

	printf("%d", ans);

	return 0;
}