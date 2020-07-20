#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		set<vector<int>> sret;
		vector<vector<int>> ret;
 		sort(nums.begin(),nums.end());
		int n=nums.size();
		for(int i=0;i<n;i++){
			int s=i+1,e=n-1;
			int tar=-nums[i];
			//nums[s] + nums[e] == tar
			while(s<e){
				if(nums[s]+nums[e]<tar) s++;
				else if(nums[s]+nums[e]>tar) e--;
				else	sret.insert({nums[i],nums[s++],nums[e--]});
			}
		}
		for(auto &s: sret)	ret.push_back(s);
		return ret;
    }
};

int main(){
	Solution sol;
	vector<int> inputs={-1,0,1,2,-1,-4};
	vector<vector<int>> ret=sol.threeSum(inputs);
	for(auto &v: ret){
		for(int &e: v)	cout << e << " ";
		cout << endl;
	}

	return 0;
}
