#include<iostream>
#include<cmath>

using namespace std;

class Solution {
public:
	bool isPowerOfFour(int num) {
		
		if (num < 1) return false;
		
		double x = log10(num) / log10(4);

		if (x == (int) x) return true;
		else return false;
	}
};

int main()
{
	Solution s;
	cout << s.isPowerOfFour(-21474836) << endl;
	cout << s.isPowerOfFour(1024*1024) << endl;
}