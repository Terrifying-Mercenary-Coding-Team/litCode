#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> par;
    int find(int a){
        if(par[a]<0)    return a;
        return par[a] = find(par[a]);
    }
    bool merge(int a, int b){
        a = find(a);
        b = find(b);
        if(a==b)    return false;
        if(a>b) swap(a,b);
        par[b] = a;
        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1)   return false;
        par.clear();
        par.resize(n,-1);
        for(auto edge: edges){
            int u=edge[0],v=edge[1];
            if(!merge(u,v)) return false;
        }
        return true;
    }
};

int main(){
    Solution *sol = new Solution;
    vector<vector<int>> args={{0,1},{1,2},{2,3},{1,3},{1,4}};
    cout << sol->validTree(5,args) << endl;
    vector<vector<int>> args2={{0,1},{0,2},{0,3},{1,4}};
    cout << sol->validTree(5,args2) << endl;
}
