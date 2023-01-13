//Problem link: https://leetcode.com/problems/minimum-falling-path-sum/description/

//TC:O(N^2) SC:O(N^2);
int dp[101][101];
int func(int i,int j,vector<vector<int>>& grid){
        if(j<0 or j>=grid.size()) return 1e9;
        if(i==0) return grid[i][j];//we have reached the first row
        //we've gotta explore three different paths, up,diagleft,diagright
        if(dp[i][j]!=-1) return dp[i][j];
        int up=grid[i][j]+func(i-1,j,grid);
        int left=grid[i][j]+func(i-1,j-1,grid);
        int right=grid[i][j]+func(i-1,j+1,grid);
        return dp[i][j]= min(up,min(left,right));
}
int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int ans=INT_MAX;
        for(int i=0;i<n-1;i++){
          memset(dp,-1,sizeof(dp));
          ans=min(ans,func(n-1,0,grid));
        }
        return ans;
}

//iterative DP
//TC:O(N^2) SC:O(N^2)
int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();

        int ans=INT_MAX;
        int dp[n][n];
        for(int i=0;i<n;i++){
            dp[0][i]=grid[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                
            
                    int up=grid[i][j]+dp[i-1][j];
                    int left=grid[i][j],right=grid[i][j];
                    if(j>0){
                        left+=dp[i-1][j-1];
                    }else left+=1e8;
                    if(j<n-1){
                        right+=dp[i-1][j+1];
                    }else right+=1e8;
                   
                    dp[i][j]=min(up,min(left,right));
                
            }
        }
        for(int i=0;i<n;i++){
            ans=min(ans,dp[n-1][i]);
        }
        return ans;
    }

//Space optimized approach( keeeping track of the previous row and the current row)

int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
      
        int ans=INT_MAX;
        vector<int> prev(n,0),cur(n,0);

        for(int i=0;i<n;i++){
            prev[i]=grid[0][i];
        }
        for(int i=1;i<n;i++){
            
            for(int j=0;j<n;j++){
                
            
                    int up=grid[i][j]+prev[j];
                    int left=grid[i][j],right=grid[i][j];
                    if(j>0){
                        left+=prev[j-1];
                    }else left+=1e8;
                    if(j<n-1){
                        right+=prev[j+1];
                    }else right+=1e8;
                   
                    cur[j]=min(up,min(left,right));
                
            }
            prev=cur;
        }
        for(int i=0;i<n;i++){
            ans=min(ans,prev[i]);
        }
        return ans;
    }

};
