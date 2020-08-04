#include<iostream>
#include<string.h>

using namespace std;

class Solution {
public:
	bool detectCapitalUse(string word) 
	{
		//a 97 z 122 A 65 Z 90
		bool first_capital = false;
		int first = (int)word[0];

		if (first >= 65 && first <= 90) first_capital = true;

		int len = word.length();

		if (first_capital)
		{
			bool ret = true;
			bool all_cap = false;
			for (int i = 1; i < len; i++)
			{
				int tmp = (int)word[i];
				if (i == 1 && tmp >= 65 && tmp <= 90) all_cap = true;

				if (all_cap && (tmp < 65 || tmp>90))
				{
					ret = false;
					break;
				}

				else if (!all_cap && tmp >= 65 && tmp <= 90)
				{
					ret = false;
					break;
				}
			}
			return ret;
		}

		else
		{
			bool ret = true;
			for (int i = 1; i < len; i++)
			{
				int tmp = (int)word[i];
				if (tmp < 97 || tmp>122)
				{
					ret = false;
					break;
				}
			}
			return ret;
		}
		
	}
};

int main()
{
	Solution s;

	string word[3] = { "USA","FlaG","Google" };

	for (int i = 0; i < 3; i++)
	{
		if (s.detectCapitalUse(word[i])) cout << "True\n";
		else cout << "No\n";
	}
}