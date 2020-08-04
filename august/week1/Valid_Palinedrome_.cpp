#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		// a 97 z 122 A 65 Z 90
		// 0 48 9 57
		vector<int> v;
		int len = s.size();

		for (int i = 0; i < len; i++)
		{
			if ((int)s[i] >= 48 && (int)s[i] <= 57)
				v.push_back((int)s[i]);

			if ((int)s[i] >= 97 && (int)s[i] <= 122)
				v.push_back((int)s[i]);

			if ((int)s[i] >= 65 && (int)s[i] <= 90)
				v.push_back((int)s[i] + 32);
		}
		int leng = v.size();
		int front;
		front = leng / 2 - 1;
			
		for (int i = 0; i <= front; i++)
		{
			if (v[i] != v[leng - i - 1])
			{
				return false;
			}
		}

		return true;
	}
};

int main()
{
	Solution s;

	string a = "A man, a plan, a canal: Panama";
	string b = "race a car";
	//cout << (int)'0' << endl;
	//cout << (int)'9' << endl;
	cout << s.isPalindrome(a) << " " << s.isPalindrome(b)<<" "<<s.isPalindrome("0p");
}