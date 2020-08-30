#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height){
        int ret=0,n=height.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && height[st.top()]<height[i]){
                int top = st.top();
                st.pop();
                if(st.empty())  break;
                int dist = i-st.top()-1;
                ret += dist*(min(height[st.top()],height[i])-height[top]);
            }
            st.push(i);
        }
        return ret;
    }
};
