//Problem link: https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/
//TC: O(N*M) SC:O(N*M)
class Solution {
    int dx[] = {-1,0,1};
    int dy[] = {1,1,1};
    public int func(int i,int j,int[][] grid,int dp[][],int n,int m){
        if(dp[i][j]!=-1) return dp[i][j];
        dp[i][j]=0;
        for(int k=0;k<3;k++){
            int newi = i + dx[k];
            int newj = j+ dy[k];
            if(newi <0 || newj<0 || newi>=n || newj>=m || grid[i][j]>=grid[newi][newj]) continue;
            dp[i][j]= Math.max(dp[i][j],1+func(newi,newj,grid,dp,n,m));
        }
        return dp[i][j];
    }
    public int maxMoves(int[][] grid) {
        int n=grid.length;
        int m= grid[0].length;
        int dp[][] = new int[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) dp[i][j]=-1;
        }
        int ans=0;
        for(int j=0;j<n;j++){
            ans=Math.max(ans,func(j,0,grid,dp,n,m));
        }
        return ans;
    }
}
