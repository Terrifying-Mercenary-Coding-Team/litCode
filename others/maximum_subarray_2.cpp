#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int calc(vector<int>& nums, int left, int mid, int right){
        int left_sum=INT_MIN,right_sum=INT_MIN,cur=0;

        for(int i=mid;i>=left;i--){
            cur += nums[i];
            left_sum = max(left_sum,cur);
        }
        cur = 0;
        for(int i=mid+1;i<=right;i++){
            cur += nums[i];
            right_sum = max(right_sum,cur);
        }
        return left_sum+right_sum;
    }

    int solve(vector<int>& nums, int left, int right){
        if(left==right) return nums[left];
        int mid=(left+right)/2;
        int left_sum = solve(nums,left,mid);
        int right_sum = solve(nums,mid+1,right);
        int cross_sum = calc(nums,left,mid,right);
        return max(cross_sum,max(left_sum,right_sum));
    }

    int maxSubArray(vector<int>& nums) {
        return solve(nums,0,nums.size()-1);
    }
};
