#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> nets(n, true);
        for(int i=2;i<n;i++){
            if(!nets[i])    continue;
            for(long long j=i;i*j<1LL*n;j++){
                nets[i*j] = false;
            }
        }
        int ret=0;
        for(int i=2;i<n;i++)   if(nets[i]) ret++;
        return ret;
    }
};

int main(){
    Solution *sol = new Solution;
    cout << sol->countPrimes(10) << endl;
    cout << sol->countPrimes(2) << endl;

    return 0;
}
