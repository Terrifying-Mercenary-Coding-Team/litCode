#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();
        int ret=0;
        int dr[4] = {1,-1,0,0};
        int dc[4] = {0,0,1,-1};
        vector<vector<bool>> visited(r,vector<bool>(c,false));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(!visited[i][j] && grid[i][j]){
                    visited[i][j] = true;
                    int adder=4;
                    for(int k=0;k<4;k++){
                        int nr=i+dr[k];
                        int nc=j+dc[k];
                        if(nr<0 || nr>=r || nc<0 || nc>=c)  continue;
                        if(grid[nr][nc])    adder--;
                    }
                    ret += adder;
                }
            }
        }
        return ret;
    }
};

int main(){
    vector<vector<int>> maps = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
    Solution sol;
    cout << sol.islandPerimeter(maps) << endl;

    return 0;
}
