//Problem link: 
//TC :O(M*N) SC:O(M*N)


//Using DFS
class Solution {
public:
    bool vis[300][300];
    int di[4]={-1,0,1,0};
    int dj[4]={0,1,0,-1};
    bool isvalid(int i,int j,int m,int n){
        return i>=0 and i<m and j>=0 and j<n;
    }
    void dfs(int i,int j,vector<vector<char>>& grid){
        for(int k=0;k<4;k++){
            int ni=i+di[k];
            int nj=j+dj[k];
            if(isvalid(ni,nj,grid.size(),grid[0].size()) and !vis[ni][nj]){
                if(grid[ni][nj]=='1'){
                    
                    vis[ni][nj]=true;
                    dfs(ni,nj,grid);
                }
                
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        memset(vis,false,sizeof(vis));
        int m=grid.size();
        int n=grid[0].size();
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' and !vis[i][j]){
                    cnt++;
                    vis[i][j]=true;
                    
                    dfs(i,j,grid);
                }
            }
        }
        return cnt;
    }
};

//Using BFS:
class Solution {
public:
    bool vis[300][300];
    int di[4]={-1,0,1,0};
    int dj[4]={0,1,0,-1};
    bool isvalid(int i,int j,int m,int n){
        return i>=0 and i<m and j>=0 and j<n;
    }
    void bfs(int i,int j,vector<vector<char>>& grid){
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j]=true;
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            
            q.pop();
        
            for(int k=0;k<4;k++){
                int ni=x+di[k];
                int nj=y+dj[k];
                if(isvalid(ni,nj,grid.size(),grid[0].size()) and !vis[ni][nj]){
                    if(grid[ni][nj]=='1'){
                        vis[ni][nj]=true;
                        q.push({ni,nj});
                    }
                
                }
             }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        memset(vis,false,sizeof(vis));
        int m=grid.size();
        int n=grid[0].size();
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' and !vis[i][j]){
                    cnt++;
                    
                    bfs(i,j,grid);
                }
            }
        }
        return cnt;
    }
};
