#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		string t = "";

		for (int i = 0; i < s.size(); i++) {
			if (s[i] >= 65 && s[i] <= 90)
				t += s[i] + 32;
			else if (s[i] >= 97 && s[i] <= 122)
				t += s[i];
			else if (s[i] >= 48 && s[i] <= 57)
				t += s[i];
		}

		bool ans = true;
		for (int i = 0; i < t.size() / 2; i++) {
			if (t[i] != t[t.size() - 1 - i]) {
				ans = false;
				break;
			}
		}

		return ans;
	}
};

int main(void)
{
	Solution sol;
	printf("%d", sol.isPalindrome("0P"));
	return 0;
}