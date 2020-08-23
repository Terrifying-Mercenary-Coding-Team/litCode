#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1,ret=0;
        while(i<j){
            int cur=(j-i)*min(height[i],height[j]);
            ret = max(ret,cur);
            if(height[i]<height[j])   i++;
            else   j--;
        }
        return ret;
    }
};

int main(){
    Solution *sol = new Solution;
    vector<int> args={1,8,6,2,5,4,8,3,7};
    vector<int> args2={1,3,2,5,25,24,5};
    cout << sol->maxArea(args) << endl;
    cout << sol->maxArea(args2) << endl;

    return 0;
}
