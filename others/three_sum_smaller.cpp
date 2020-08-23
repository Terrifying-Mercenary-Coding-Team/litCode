#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int ret=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int j=i+1,k=nums.size()-1;
            while(j<k){
                int cur=nums[i]+nums[j]+nums[k];
                if(cur<target){
                    ret += k-j;
                    j++; 
                }
                else    k--;
            }
        }
        return ret;
    }
};

int main(){
    Solution *sol = new Solution;
    vector<int> tmp={-2,0,1,3};
    cout << sol->threeSumSmaller(tmp,2) << endl;

    return 0;
}
