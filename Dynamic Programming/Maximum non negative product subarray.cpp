

int maxProductPath(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        long dp[m][n][2];
        dp[0][0][0]=grid[0][0];
        dp[0][0][1]=grid[0][0];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 and j==0) continue;
                if(i==0){
                    dp[i][j][0]=grid[i][j]*dp[i][j-1][0];
                    dp[i][j][1]=grid[i][j]*dp[i][j-1][1];
                }else if(j==0){
                    dp[i][j][0]=grid[i][j]*dp[i-1][j][0];
                    dp[i][j][1]=grid[i][j]*dp[i-1][j][1];
                }
                else{
                    long p1=grid[i][j]*max(dp[i][j-1][0],dp[i-1][j][0]);
                    long p2=grid[i][j]*min(dp[i][j-1][1],dp[i-1][j][1]);
                    dp[i][j][0]=max(p1,p2);
                    dp[i][j][1]=min(p1,p2);
                }
            }
        }
        if(dp[m-1][n-1][0]<0) return -1;
        return (int)(dp[m-1][n-1][0]%mod);  
        
        
}
