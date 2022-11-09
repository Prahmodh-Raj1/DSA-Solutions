//Problem link: https://leetcode.com/problems/01-matrix/
//TC : O(M*N) SC:O(M*N)
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        
        queue<pair<int,int>> q;
        const int dx[4] = {0, 0, 1, -1};
        const int dy[4] = {1, -1, 0, 0};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                }else{
                    mat[i][j]=-1;
                }
            }
        }
        while(!q.empty()){
            auto it=q.front();
            int x=it.first;
            int y=it.second;
            //int steps=it.second;
            q.pop();
            
            
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 and nx<m and ny>=0 and ny<n and mat[nx][ny]==-1){
                    mat[nx][ny]=mat[x][y]+1;
                    q.push({nx,ny});
                }else{
                    continue;
                }
                
            }
        }
        return mat;
    }
};
