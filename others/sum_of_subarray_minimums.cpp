#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int ret=0,n=A.size();
        vector<int> left(n), right(n);
        stack<int> prev,nxt;

        for(int i=0;i<n;i++)    right[i] = n-i;

        for(int i=0;i<n;i++){
            while(!prev.empty() && A[prev.top()] > A[i]) prev.pop();
            left[i] = prev.empty() ? i+1 : i-prev.top();
            prev.push(i);

            while(!nxt.empty() && A[nxt.top()] > A[i]){
                int tmp = nxt.top();
                right[tmp] = i-tmp;
                nxt.pop();
            }
            nxt.push(i);
        }
        for(int i=0;i<n;i++)    ret = (ret+A[i]*left[i]*right[i])%1000000007;
        return ret;
    }
};

int main(){
    vector<int> tmp={3,1,2,4};
    vector<int> tmp2={1,1,1,1};
    Solution *sol = new Solution();
    cout << sol->sumSubarrayMins(tmp) << endl;
    cout << sol->sumSubarrayMins(tmp2) << endl;

    return 0;
}
