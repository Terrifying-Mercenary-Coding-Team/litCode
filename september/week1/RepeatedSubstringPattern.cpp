#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	bool repeatedSubstringPattern(string s) {

		for (int i = 1; i < s.size(); i++) {
			string pivot = "";
			bool flag = true;
			if (s.size() % i != 0)
				continue;
			for (int j = 0; j < i; j++)
				pivot += s[j];

			for (int j = i; j < s.size(); j += i) {
				string cp = "";
				for (int k = j; k < j + i; k++) {
					cp += s[k];
				}

				if (pivot != cp) {
					flag = false;
					break;
				}
			}

			if (flag)
				return true;
		}
		return false;
	}
};

int main(void)
{
	Solution sol;
	cout << sol.repeatedSubstringPattern("abab") << endl;
	cout << sol.repeatedSubstringPattern("aba") << endl;
	cout << sol.repeatedSubstringPattern("abcabcabcabc") << endl;
	return 0;
}