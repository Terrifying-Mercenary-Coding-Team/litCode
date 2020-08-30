#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty())  return 0;
        int ret=0,n=height.size();
        vector<int> left(n,height[0]),right(n,height[n-1]);
        for(int i=1;i<n;i++)    left[i] = max(left[i-1],height[i]);
        for(int i=n-2;i>=0;i--)    right[i] = max(right[i+1],height[i]);
        for(int i=0;i<n;i++)    if(min(left[i],right[i])) ret += min(left[i],right[i])-height[i];
        return ret;
    }
};

