#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& tree){
        int n=tree.size();
        queue<int> q;

        int ret=0;
        int tmp=0;
        int cnt=1;
        for(int i=0;i<n;i++){
            int cur=tree[i];
            if(q.empty()){
                q.push(cur);
                tmp++;
            }
            else if(q.size()==1){
                if(cur!=q.front())  q.push(cur);
                tmp++;
            }
            else{
                if(cur==q.front() || cur==q.back()){
                    if(cur==q.front()){
                        q.pop();
                        q.push(cur);
                        cnt=1;
                    }
                    else    cnt++;
                    tmp++;
                    continue;
                }
                q.pop();
                q.push(cur);
                ret = max(ret,tmp);
                tmp = cnt+1;
                cnt = 1;
            }
        }
        return ret = max(ret,tmp);
    }
};

int main(){
    Solution *sol = new Solution();
    vector<int> tmp={1,2,1};
    vector<int> tmp2={0,1,2,2};
    vector<int> tmp3={1,2,3,2,2};
    vector<int> tmp4={3,3,3,1,2,1,1,2,3,3,4};
    vector<int> tmp5={0,1,6,6,4,4,6};
    cout << sol->totalFruit(tmp) << endl;
    cout << sol->totalFruit(tmp2) << endl;
    cout << sol->totalFruit(tmp3) << endl;
    cout << sol->totalFruit(tmp4) << endl;
    cout << sol->totalFruit(tmp5) << endl;
}
