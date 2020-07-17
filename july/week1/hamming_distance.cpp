#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int ret=0;
        int z = x ^ y;
        while(z){
            if(z&1) ret++;
            z >>= 1;
        }
        return ret;
    }
};

int main(){
    Solution sol;
    cout << sol.hammingDistance(1,4) << endl;

    return 0;
}
