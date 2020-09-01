#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	string largestTimeFromDigits(vector < int >& A) {
		string ret = "";
		
		int h_max = -1;
		int m_max = -1;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (i == j)
					continue;
				for (int l = 0; l < 4; l++) {
					if (l == i || l == j)
						continue;
					for (int k = 0; k < 4; k++) {
						if (k == i || k == j || k == l)
							continue;

						int hour = A[i] * 10 + A[j];
						int min = A[l] * 10 + A[k];

						if (hour > 23 || min > 60)
							continue;

						if (hour > h_max) {
							h_max = hour;
							m_max = min;
						}
						else if (hour == h_max && min > m_max) {
							m_max = min;
						}
					}
				}
			}
		}
		//cout << h_max << " " << m_max;
		if (h_max != -1 && m_max != -1) {
			string strh = to_string(h_max);
			string strm = to_string(m_max);
			if (h_max < 10)
				strh = '0' + strh;
			if (m_max < 10)
				strm = '0' + strm;
			ret = strh + ":" + strm;
		}
		return ret;
	}
};

int main(void)
{
	Solution sol;

	vector < int > input = {1,9,6,0};
	string ans = sol.largestTimeFromDigits(input);
	cout << ans;
	return 0;
}