#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

class Solution {
public:
	int hammingDistance(int x, int y) {
		int n = x ^ y;

		int ans = 0;
		while (n != 0) {
			if (n % 2 == 1)
				ans++;
			n /= 2;
		}
		return ans;
	}
};

int main(void)
{
	Solution sol;
	printf("%d", sol.hammingDistance(1, 4));
	return 0;
}