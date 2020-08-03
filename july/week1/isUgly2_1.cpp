#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int arr[1700];
class Solution {
public:
	int nthUglyNumber(int n) {
		arr[1] = 1;

		int p2, p3, p5;
		p2 = p3 = p5 = 1;

		int min;
		for (int i = 2; i <= n; i++) {
			if (arr[p2] * 2 < arr[p3] * 3)
				min = arr[p2] * 2;
			else
				min = arr[p3] * 3;
			if (min > arr[p5] * 5)
				min = arr[p5] * 5;

			if (min == arr[p2] * 2)
				p2++;
			if (min == arr[p3] * 3)
				p3++;
			if(min==arr[p5]*5)
				p5++;

			arr[i] = min;
		}
		return arr[n];
	}
};

int main(void)
{
	int n = 10;
	Solution sol;
	printf("%d", sol.nthUglyNumber(n));

	return 0;
}