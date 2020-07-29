#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret=0;
        for(int i=0;i<32;i++){
            uint32_t tmp=n&(uint32_t(1)<<i);
            if(tmp) ret |= uint32_t(1)<<(31-i);
        }
        return ret;
    }
};

int main(){
    Solution sol;
    cout << sol.reverseBits(uint32_t(43261596)) << endl;

    return 0;
}
