#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	bool wordPattern(string pattern, string str) {

		vector < string > v;
		string t = "";
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == ' ') {
				v.push_back(t);
				t = "";
			}
			else
				t += str[i];
		}
		v.push_back(t);
		
		if (pattern.size() != v.size())
			return false;

		map < string, char > m;
		map < char, string > m2;
		for (int i = 0; i < v.size(); i++) {
			//cout << v[i] << endl;
			if (m.count(v[i]) == 0) {
				m[v[i]] = pattern[i];
			}
			else {
				if (m[v[i]] != pattern[i])
					return false;
			}

			if (m2.count(pattern[i]) == 0) {
				m2[pattern[i]] = v[i];
			}
			else {
				if (m2[pattern[i]] != v[i])
					return false;
			}
		}

		return true;
	}
};

int main(void)
{
	Solution sol;

	cout << sol.wordPattern("abba", "dog cat cat dog") << endl;
	cout << sol.wordPattern("abba", "dog cat cat fish") << endl;
	cout << sol.wordPattern("aaaa", "dog cat cat dog") << endl;
	cout << sol.wordPattern("abba", "dog dog dog dog") << endl;
	return 0;
}