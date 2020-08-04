#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num<0)   return false;
        int tar=1431655765;
        if((num&tar) == num){
            int nums=0;
            while(num){
                if(num%2)   nums++;
                num >>= 1;
            }
            if(nums==1) return true;
            else    return false;
        }
        else return false;
    }
};

int main(){
    Solution sol;
    cout << sol.isPowerOfFour(16) << endl;
    cout << sol.isPowerOfFour(1) << endl;

    return 0;
}
