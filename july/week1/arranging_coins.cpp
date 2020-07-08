#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int arrangeCoins(int n) {
            long long left=0,right=1LL*n+1;
            while(left+1<right){
                long long mid=(left+right)/2;
                long long cur=mid*(mid+1)/2;
                if(n<cur)   right = mid;
                else    left = mid;
            }
            return left;
        }
};

int main(){
    Solution sol;
    int n;
    cin >> n;
    cout << sol.arrangeCoins(n) << endl;
    
    return 0;
}
