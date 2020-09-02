#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> prev,nxt;
        for(int i=0;i<nums.size();i++){
            long long cur=nums[i];
            auto pit = prev.lower_bound(-1*cur); 
            auto nit = nxt.lower_bound(cur);
            if(pit!=prev.end() && (*pit)+cur<=1LL*t)    return true;
            if(nit!=nxt.end() && (*nit)-cur<=1LL*t)    return true;

            prev.insert(-1*cur);
            nxt.insert(cur);
            if(prev.size()>k)   prev.erase(-1*nums[i-k]);
            if(nxt.size()>k)   nxt.erase(nums[i-k]);
        }
        return false; 
    }
};
