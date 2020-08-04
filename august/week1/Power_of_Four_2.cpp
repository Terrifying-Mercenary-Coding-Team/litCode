#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

class Solution {
public:
	bool isPowerOfFour(int num) {
		if (num <= 0)
			return false;

		double n = log(num) / log(4);

		return (n == (int)n);
	}
};

int main(void)
{
	Solution sol;
	printf("%d\n", sol.isPowerOfFour(16));
	printf("%d\n", sol.isPowerOfFour(5));
	return 0;
}