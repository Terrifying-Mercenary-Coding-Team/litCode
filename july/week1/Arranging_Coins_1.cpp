#include <iostream>
#include <cstdio>

using namespace std;

class Solution {
public:
	int arrangeCoins(int n) {
		long long int ans;

		for (ans = 0;; ans++) {
			if (ans*(ans + 1) / 2 > n)
				break;
		}

		return (int)ans - 1;
	}
};

int main(void) {
	int n;
	scanf("%d", &n);

	Solution s;
	printf("%d", s.arrangeCoins(n));

	return 0;
}