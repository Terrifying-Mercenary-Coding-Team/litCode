#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int arr[26];
class Solution {
public:
	vector<int> partitionLabels(string S) {
		vector < int > idx;

		for (int i = 0; i < S.size(); i++) {
			int num = S[i] - 'a';
			arr[num] = i;
		}

		int n = 0;
		while (n < S.size()) {
			int end = arr[S[n] - 'a'];
			int val = end;
			for (int i = n; i < end; i++) {
				val = max(val, arr[S[i] - 'a']);
				end = val;
			}

			idx.push_back(val + 1);
			n = val + 1;
		}

		vector < int > ret;
		ret.push_back(idx[0]);
		for (int i = 1; i < idx.size(); i++)
			ret.push_back(idx[i] - idx[i - 1]);
		
		return ret;
	}
};

int main(void)
{
	Solution sol;

	vector < int > ans = sol.partitionLabels("ababcbacadefegdehijhklij");

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	return 0;
}