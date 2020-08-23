#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0,j=numbers.size()-1;
        vector<int> ret;
        while(i<j){
            int cur = numbers[i]+numbers[j];
            if(cur==target){
                ret.push_back(i+1);
                ret.push_back(j+1);
                break;
            }
            else if(cur<target) i++;
            else    j--;
        }
        return ret;
    }
};

int main(){
    Solution *sol = new Solution;
    vector<int> args={2,7,11,15};
    for(int &e: sol->twoSum(args,9))    cout << e << endl;

    return 0;
}
