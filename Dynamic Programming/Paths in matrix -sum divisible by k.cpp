//Problem link: https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/
//TC :O(M*N) SC:O(M*N*K)
class Solution {
public:
    const int mod=1e9+7;
    int m,n,K;
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m=grid.size();
        n=grid[0].size();
        K=k;
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(K+1,-1)));
        return countpaths(0,0,0,grid,dp);
    }
    int countpaths(int i,int j,int cursum,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){
        if(i==m || j==n) return 0;
        if(i==m-1 && j==n-1){
            if((cursum+grid[i][j]) % K ==0)
                return 1;
            return 0;
        }
        if(dp[i][j][cursum]!=-1) return dp[i][j][cursum];
        dp[i][j][cursum]=(countpaths(i+1,j,(cursum+grid[i][j]) % K,grid,dp)+countpaths(i,j+1,(cursum+grid[i][j]) % K,grid,dp)) % mod;
        return dp[i][j][cursum];
    }
};
