#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector<int> ret(8);
        unsigned int num = 0;
        for(int i=1;i<=8;i++)   num += int(pow(2,8-i))*cells[i-1];
        for(int i=0;i<(N-1)%14+1;i++)    num = 126 & (~((num<<1) ^ (num>>1)));
        for(int i=0;i<8;i++){
            if(num & int(pow(2,7-i))) ret[i] = 1;
            else ret[i] = 0;
        }
        
        return ret;
    }
};

int main(){
    Solution sol;
    vector<int> test = {0,1,0,1,1,0,0,1};
    vector<int> ret = sol.prisonAfterNDays(test,7);
    for(int &e: ret)    cout << e << " ";
    cout << endl;
    
    return 0;
}
