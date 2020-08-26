#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size()+nums2.size();
        vector<int> merged(n);
        int i1=0,i2=0,i=0;
        while(i1<nums1.size() && i2<nums2.size()){
            if(nums1[i1]<nums2[i2]) merged[i++] = nums1[i1++];
            else    merged[i++] = nums2[i2++];
        }
        while(i1<nums1.size())   merged[i++] = nums1[i1++];
        while(i2<nums2.size())   merged[i++] = nums2[i2++];
        double ret=0;
        if(n%2) ret = merged[int(n/2)];
        else    ret = (merged[int(n/2)-1]+merged[int(n/2)])/double(2);
        return ret;
    }
};
