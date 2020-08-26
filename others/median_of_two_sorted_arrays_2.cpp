#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(!nums1.size())   return (nums2.size()%2) ? nums2[nums2.size()/2]: (nums2[nums2.size()/2-1]+nums2[nums2.size()/2])/double(2);
        if(!nums2.size())   return (nums1.size()%2) ? nums1[nums1.size()/2]: (nums1[nums1.size()/2-1]+nums1[nums1.size()/2])/double(2);
        int n=nums1.size()+nums2.size();
        int p_num=(n+1)/2;
        if(nums1.size()>nums2.size())   nums1.swap(nums2);
        int left=0,right=nums1.size();
        while(left<right){
            int mid=(left+right)/2;
            int op_mid=p_num-mid-2;
            int first_left=nums1[mid],first_right=(mid==nums1.size()-1) ? INT_MAX : nums1[mid+1];
            int second_left=(op_mid<0) ? INT_MIN : nums2[op_mid],second_right=nums2[op_mid+1];
            if(first_left<=second_right && second_left<=first_right){
                return (n%2) ? max(first_left,second_left): (max(first_left,second_left)+min(first_right,second_right))/double(2);
            }
            else if(first_left>=second_right){
                right = mid;
            }
            else{
                left = mid;
            }
        }
        int first_left=INT_MIN,first_right=nums1[0];
        int second_left=nums2[p_num-1],second_right=(p_num==nums2.size()) ? INT_MAX: nums2[p_num];
        if(first_left<second_right && second_left<first_right){
            return (n%2) ? max(first_left,second_left): (max(first_left,second_left)+min(first_right,second_right))/double(2);
        }

        return 0;
    }
};
