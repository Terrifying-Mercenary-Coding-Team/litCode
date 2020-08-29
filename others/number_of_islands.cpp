#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int r,c;
    int dr[4]={1,-1,0,0};
    int dc[4]={0,0,1,-1};
    vector<vector<bool>> visited;
    void dfs(vector<vector<char>>& grid, int cur_r, int cur_c){
        visited[cur_r][cur_c] = true;
        for(int i=0;i<4;i++){
            int nxt_r = cur_r + dr[i];
            int nxt_c = cur_c + dc[i];
            if(nxt_r<0 || nxt_r>=r || nxt_c<0 || nxt_c>=c)  continue;
            if(visited[nxt_r][nxt_c])   continue;
            if(grid[nxt_r][nxt_c]!='1')   continue;
            dfs(grid,nxt_r,nxt_c);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        r=grid.size(),c=grid[0].size();
        visited.resize(r, vector<bool>(c, false));
        int ret=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    ret++;
                    dfs(grid, i, j);
                }
            }
        }

        return ret;
    }
};
