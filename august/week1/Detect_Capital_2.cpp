#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

class Solution {
public:
	bool detectCapitalUse(string word) {
		bool flag1 = true;
		for (int i = 0; i < word.size(); i++) {
			if (word[i] < 65 || word[i]>90) {
				flag1 = false;
				break;
			}
		}

		bool flag2 = true;
		for (int i = 0; i < word.size(); i++) {
			if (word[i] >= 65 && word[i] <= 90) {
				flag2 = false;
				break;
			}
		}

		bool flag3 = true;
		if (word[0] < 65 || word[0]>90)
			flag3 = false;
		else {
			for (int i = 1; i < word.size(); i++) {
				if (word[i] >= 65 && word[i] <= 90) {
					flag3 = false;
					break;
				}
			}
		}
		cout << flag1 << flag2 << flag3;
		if (flag1 || flag2 || flag3)
			return true;
		return false;
	}
};

int main(void)
{
	Solution sol;
	string word = "FlaG";
	bool ans = sol.detectCapitalUse(word);
	if (ans)
		printf("True");
	else
		printf("False");
	return 0;
}