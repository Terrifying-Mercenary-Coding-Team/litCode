#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<bool> visited;
    vector<vector<int>> adj;
    bool traverse(int cur, int par){
        visited[cur] = true;
        for(int nxt: adj[cur]){
            if(nxt==par)    continue;
            if(visited[nxt])    return false;
            if(!traverse(nxt,cur))  return false;
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        adj.clear();
        adj.resize(n);
        visited.clear();
        visited.resize(n);
        for(auto edge: edges){
            int u=edge[0],v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bool ret=traverse(0,-1);
        for(int i=0;i<n;i++)    if(!visited[i]) ret = false;   
        return ret;
    }
};

int main(){
    Solution *sol = new Solution;
    vector<vector<int>> args={{0,1},{1,2},{2,3},{1,3},{1,4}};
    cout << sol->validTree(5,args) << endl;
    vector<vector<int>> args2={{0,1},{0,2},{0,3},{1,4}};
    cout << sol->validTree(5,args2) << endl;
}
