#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		int n = nums.size();
		vector<pair<int, int> > data;
		for (int i = 0; i < n; i++)
			data.push_back(make_pair(nums[i], i));
		sort(data.begin(), data.end());
		int p1 = 0;
		int p2 = 1;
		while (p2 < n)
		{
			long long int d1 = data[p1].first;
			long long int d2 = data[p2].first;
			if (abs(data[p1].second - data[p2].second) <= k && abs(d1 - d2) <= t)
				return true;
			if (abs(data[p1].second - data[p2].second) > k)
				p2++;
			if (abs(d1 - d2) > t)
				p1++;
			if (p1 == p2)
				p2++;
		}
		return false;
	}
};

int main(void)
{
	vector < int > input = { 1,2,3,1 };
	vector < int > input2 = { 1,0,1,1 };
	vector < int > input3 = { 1,5,9,1,5,9 };
	vector < int > input4 = { -1,2147483647 };
	Solution sol;

	cout << sol.containsNearbyAlmostDuplicate(input, 3, 0)<<endl;
	cout << sol.containsNearbyAlmostDuplicate(input2,1, 2) << endl;
	cout << sol.containsNearbyAlmostDuplicate(input3, 2, 3) << endl;
	cout << sol.containsNearbyAlmostDuplicate(input4, 1, 2147483647) << endl;
	return 0;
}