//Problem link: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
//TC: O(N*M) SC:O(N*M) 
class Solution {
    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};
    public int func(int i,int j,int dp[][],int[][] matrix,int n,int m){
        if(dp[i][j]!=-1) return dp[i][j];
        dp[i][j]=1;
        for(int k=0;k<4;k++){
            int newi= i+dx[k];
            int newj = j+dy[k];
            if(newi <0 || newj<0 || newi >=n || newj>=m || matrix[i][j]>= matrix[newi][newj]) continue;
            dp[i][j]=Math.max(dp[i][j],1+func(newi,newj,dp,matrix,n,m));
        }
        return dp[i][j];
    }
    public int longestIncreasingPath(int[][] matrix) {
        int n=matrix.length;
        int m = matrix[0].length;
        int dp[][] = new int[n][m];
        

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) dp[i][j]=-1;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=Math.max(ans,func(i,j,dp,matrix,n,m));
            }
        }
        return ans;

    }
}
