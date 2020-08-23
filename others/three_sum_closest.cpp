#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ret=0,diff=987654321;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int j=i+1,k=nums.size()-1;
            while(j<k){
                int cur=nums[i]+nums[j]+nums[k];
                if(cur==target) return target;
                int tmp_diff = abs(cur-target);
                if(tmp_diff<diff){
                    diff = tmp_diff;
                    ret = cur;
                }
                if(cur<target)  j++;
                else    k--;
            }
        }
        return ret;
    }
};

int main(){
    Solution *sol = new Solution;
    vector<int> tmp={-1,2,1,-4};
    cout << sol->threeSumClosest(tmp,1) << endl;
    return 0;
}
