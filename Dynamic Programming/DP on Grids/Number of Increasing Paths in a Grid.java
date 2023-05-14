//Problem link: https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/
//TC : O(N*M) SC:O(N*M)
class Solution {
    int mod = 1000000007;
    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};
    public int func(int i,int j,int[][] grid,int dp[][],int n,int m){
        if(dp[i][j]!=-1) return dp[i][j];
        dp[i][j]=1;
        for(int k=0;k<4;k++){
            int newi = i + dx[k];
            int newj= j+  dy[k];
            if(newi<0 || newj<0 || newi>=n || newj>=m || grid[i][j]>= grid[newi][newj]) continue;
            dp[i][j]=(dp[i][j]+func(newi,newj,grid,dp,n,m))%mod;
        }
        return dp[i][j]%mod;
    }
    public int countPaths(int[][] grid) {
        int n= grid.length;
        int m=grid[0].length;
        int dp[][] = new int[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dp[i][j]=-1;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=(ans+func(i,j,grid,dp,n,m))%mod;
            }
        }
        return ans;
    }
}
