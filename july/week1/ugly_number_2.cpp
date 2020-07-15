#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n+1);

        dp[1]=1;
        int ind_2=1,ind_3=1,ind_5=1;
        int num_2=2,num_3=3,num_5=5;
        for(int i=2;i<=n;i++){
            dp[i] = min(num_2,min(num_3,num_5));
            if(dp[i]==num_2){
                ind_2++;
                num_2 = dp[ind_2]*2;
            }
            if(dp[i]==num_3){
                ind_3++;
                num_3 = dp[ind_3]*3;
            }
            if(dp[i]==num_5){
                ind_5++;
                num_5 = dp[ind_5]*5;
            }
        }

        return dp[n];
    }
};

int main(){
    Solution sol;
    cout << sol.nthUglyNumber(1690) << endl;

    return 0;
}
