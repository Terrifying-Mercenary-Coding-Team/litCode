#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		vector < int > ans;
		set < int > s;

		for (int i = 0; i < nums.size(); i++) {
			if (s.count(nums[i]) != 0)
				ans.push_back(nums[i]);
			else {
				s.insert(nums[i]);
			}
		}

		return ans;
	}
};

int main(void)
{
	Solution sol;
	
	vector < int > arr = { 4,3,2,7,8,2,3,1 };
	vector < int > v = sol.findDuplicates(arr);

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	return 0;
}