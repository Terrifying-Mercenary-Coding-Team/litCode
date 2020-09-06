class Solution {
public:
    void move_right(vector<vector<int>> &tar, int n){
        for(int i=0;i<n;i++){
            for(int j=n-1;j>=1;j--){
                tar[i][j] = tar[i][j-1];
            }
            tar[i][0] = 0;
        }
    }
    void move_left(vector<vector<int>> &tar, int n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n-1;j++){
                tar[i][j] = tar[i][j+1];
            }
            tar[i][n-1] = 0;
        }
    }
    void move_down(vector<vector<int>> &tar, int n){
        for(int i=n-1;i>=1;i--){
            for(int j=0;j<n;j++){
                tar[i][j] = tar[i-1][j];
            }
        }
        for(int j=0;j<n;j++){
            tar[0][j] = 0;
        }
    }
    void move_up(vector<vector<int>> &tar, int n){
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n;j++){
                tar[i][j] = tar[i+1][j];
            }
        }
        for(int j=0;j<n;j++){
            tar[n-1][j] = 0;
        }
    }
    int count(vector<vector<int>> &A, vector<vector<int>> &B){
        int ret=0,n=A.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ret += A[i][j]&B[i][j];
            }
        }
        return ret;
    }
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n=A.size();
        int ret=0;
        vector<vector<int>> A1(A);
        for(int i=0;i<n;i++){
            vector<vector<int>> tmp(A1);
            for(int j=0;j<n;j++){
                ret = max(ret,count(tmp,B));
                move_down(tmp,n);
            }
            move_right(A1,n);
        }
        vector<vector<int>> A2(A);
        for(int i=0;i<n;i++){
            vector<vector<int>> tmp(A2);
            for(int j=0;j<n;j++){
                ret = max(ret,count(tmp,B));
                move_down(tmp,n);
            }
            move_left(A2,n);
        }
        vector<vector<int>> A3(A);
        for(int i=0;i<n;i++){
            vector<vector<int>> tmp(A3);
            for(int j=0;j<n;j++){
                ret = max(ret,count(tmp,B));
                move_up(tmp,n);
            }
            move_right(A3,n);
        }
        vector<vector<int>> A4(A);
        for(int i=0;i<n;i++){
            vector<vector<int>> tmp(A4);
            for(int j=0;j<n;j++){
                ret = max(ret,count(tmp,B));
                move_up(tmp,n);
            }
            move_left(A4,n);
        }
        
        return ret; 
    }
};
