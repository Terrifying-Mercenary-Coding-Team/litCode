#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        bool flag = (x<0) ? true : false;
        x = abs(x);
        queue<int> q;
        long long s=1;
        while(x){
            q.push(x%10);
            x /= 10;
            s *= 10;
        }
        s /= 10;
        long long ret=0;
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            ret += cur*s;
            s /= 10;
        }
        if(ret<0 || ret>INT_MAX) return 0;
        if(flag){
            ret *= -1;
            if(ret<INT_MIN) return 0;
        }
        return ret;
    }
};

int main(){
    Solution *sol = new Solution;
    cout << sol->reverse(-2147483648) << endl;

    return 0;
}
