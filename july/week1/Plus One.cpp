#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int len = digits.size();

		vector<int> ans;
		int carry = 1;

		for (int i = len - 1; i >= 0; i--)
		{
			int tmp = carry + digits[i];
			if (tmp - 9 > 0) carry = 1;
			else carry = 0;

			tmp %= 10;
			ans.push_back(tmp);

			//cout << tmp << endl;
		}

		if (carry) ans.push_back(carry);

		reverse(ans.begin(), ans.end());

		return ans;
	}
};

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(9);

	Solution s;
	vector<int> ans = s.plusOne(v);

	for (int i = 0; i < ans.size();i++) cout << ans[i] << " ";
}