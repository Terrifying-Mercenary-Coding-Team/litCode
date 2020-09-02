#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret=INT_MIN,cur=0;
        for(int i=0;i<nums.size();i++){
            cur = max(cur+nums[i],nums[i]);
            ret = max(ret,cur);
        }
        return ret;
    }
};
