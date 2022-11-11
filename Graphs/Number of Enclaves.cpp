

class Solution {
public:
   
    int di[4]={-1,0,1,0};
    int dj[4]={0,1,0,-1};
    bool isvalid(int i,int j,int m,int n){
        return i>=0 and i<m and j>=0 and j<n;
    }
    void dfs(int i,int j,vector<vector<int>>& grid){
        grid[i][j]=0;
        for(int k=0;k<4;k++){
            int ni=i+di[k];
            int nj=j+dj[k];
            if(isvalid(ni,nj,grid.size(),grid[0].size()) and grid[ni][nj]==1){
                dfs(ni,nj,grid);    
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
       
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        for(int i=0;i<n;i++){
            int j=0;
            if(grid[i][j]==1){
               
                dfs(i,j,grid);
            }
            j=m-1;
            if(grid[i][j]==1){
               
                dfs(i,j,grid);
            }
        }
        for(int j=0;j<m;j++){
            int i=0;
            if(grid[i][j]==1){
           
                dfs(i,j,grid);
            }
            i=n-1;
            if(grid[i][j]==1){
          
                dfs(i,j,grid);
            }
        }
        int enclaves=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) enclaves++;
            }
        }
        return enclaves;
    }
};
