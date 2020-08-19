#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool cmp(pair<int,int> &a, pair<int,int> &b){
        if(a.first==b.first)    return a.second<b.second;
        else    return a.first<b.first;
    }

    int oddEvenJumps(vector<int>& A) {
        int n=A.size();
        vector<int> odd(n,-1),even(n,-1);
        stack<int> nxt_odd,nxt_even;
        vector<vector<bool>> dp(n,vector<bool>(2));
        int ret=0;

        dp[n-1][0] = dp[n-1][1] = true;

        vector<pair<int,int>> B(n);
        for(int i=0;i<n;i++){
            B[i].first = A[i];
            B[i].second = i;
        }

        sort(B.begin(),B.end());
        for(int i=0;i<n;i++){
            while(!nxt_odd.empty() && nxt_odd.top() < B[i].second){
                int tmp = nxt_odd.top();
                odd[tmp] = B[i].second;
                nxt_odd.pop();
            }
            nxt_odd.push(B[i].second);
        }
        for(int i=0;i<n;i++)    B[i].first *= -1; 
        sort(B.begin(),B.end());
        for(int i=0;i<n;i++){
            while(!nxt_even.empty() && nxt_even.top() < B[i].second){
                int tmp = nxt_even.top();
                even[tmp] = B[i].second;
                nxt_even.pop();
            }
            nxt_even.push(B[i].second);
        }
        
        for(int i=n-1;i>=0;i--){
            if(odd[i]!=-1 && dp[odd[i]][1]) dp[i][0] = true;
            if(even[i]!=-1 && dp[even[i]][0])   dp[i][1] = true;
        }
        for(int i=0;i<n;i++){
            if(dp[i][0])    ret++;
        }

        return ret;
    }
};

int main(){
    Solution *sol = new Solution();
    vector<int> arr={1,2,3,2,1,4,4,5};
    cout << sol->oddEvenJumps(arr) << endl;

    return 0;
}
