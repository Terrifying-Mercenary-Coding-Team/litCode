#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		vector < int > ans;
		
		bool up = (digits[digits.size() - 1] == 9);
		if (up)
			digits[digits.size() - 1] = 0;
		else
			digits[digits.size() - 1]++;
		for (int i = 1; i < digits.size()&&up; i++) {
			if (digits[digits.size()-1-i] == 9) {
				digits[digits.size() - 1 - i] = 0;
				continue;
			}
			digits[digits.size() - 1 - i]++;
			up = false;
			break;
		}
		
		if (up) {
			ans.push_back(1);
			for (int i = 0; i < digits.size(); i++)
				ans.push_back(digits[i]);
		}
		else {
			for (int i = 0; i < digits.size(); i++)
				ans.push_back(digits[i]);
		}
		return ans;
	}

};

int main(void)
{
	Solution sol;
	vector < int > a = { 1,0,0,9 };
	vector < int > v = sol.plusOne(a);
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	return 0;
}