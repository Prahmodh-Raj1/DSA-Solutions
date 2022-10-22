//Problem link: https://leetcode.com/problems/shortest-path-in-binary-matrix/
//TC :O(N*N) SC :O(N*N) 

class Solution {
public:
    
    bool isvalid(int x,int y,int n){
        if(x>=0 and y>=0 and x<n and y<n) return true;
        return false;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1) return -1;
        if(grid.size()==1 and grid[0][0]==0) return 1;
        int dx[8]={-1,-1,-1,0,1,1,1,0};
        int dy[8]={-1,0,1,1,1,0,-1,-1};
        int cnt=0;
        
        queue<pair<int,int>> q;
        q.push({0,0});
        int n=grid.size();
        grid[0][0]=1;
        while(!q.empty()){

            cnt++;
            int si=q.size();
            for(int i=0;i<si;i++){
              int xc=q.front().first;
              int yc=q.front().second;
            
              q.pop();
            
              for(int i=0;i<8;i++){
                int nx=xc+dx[i];
                int ny=yc+dy[i];
                if(isvalid(nx,ny,n) and grid[nx][ny]==0){
                    if(nx==n-1 and ny==n-1) return cnt+1;
                    q.push({nx,ny});
                    
                    grid[nx][ny]=1;
                }
              }
            }
        }
        return -1;
        
        
    }
};
