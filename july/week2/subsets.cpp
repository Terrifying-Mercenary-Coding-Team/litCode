#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void iterate(int ind, vector<int>& nums, vector<int>& cur, vector<vector<int>>& ret){
        if(ind == nums.size()){
            ret.push_back(cur);
            return;
        }
        cur.push_back(nums[ind]);
        iterate(ind+1,nums,cur,ret);
        cur.pop_back();
        iterate(ind+1,nums,cur,ret);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> cur;
        iterate(0,nums,cur,ret);

        return ret;
    }
};

int main(){
    vector<int> test={1,2,3};
    Solution sol;
    vector<vector<int>> ret = sol.subsets(test);
    for(auto &v: ret){
        for(int &e: v)  cout << e << " ";
        cout << endl;
    }

    return 0;
}
