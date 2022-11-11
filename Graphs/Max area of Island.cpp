//Problem link: https://leetcode.com/problems/max-area-of-island/
//TC : O(M*N) SC:O(M*N)

class Solution {
public:
    bool vis[300][300];
    int di[4]={-1,0,1,0};
    int dj[4]={0,1,0,-1};
    int len=0;
    bool isvalid(int i,int j,int m,int n){
        return i>=0 and i<m and j>=0 and j<n;
    }
    int bfs(int i,int j,vector<vector<int>>& grid){
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j]=true;
        int cnt=0;
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            cnt++;
            q.pop();
        
            for(int k=0;k<4;k++){
                int ni=x+di[k];
                int nj=y+dj[k];
                if(isvalid(ni,nj,grid.size(),grid[0].size()) and !vis[ni][nj]){
                    if(grid[ni][nj]==1){
                        vis[ni][nj]=true;
                        q.push({ni,nj});
                    }
                
                }
             }
        }
        return cnt;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        memset(vis,false,sizeof(vis));
        int m=grid.size();
        int n=grid[0].size();
        //int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 and !vis[i][j]){
                    
                    len=max(len,bfs(i,j,grid));
                    
                }
            }
        }
        return len;
    }
};
