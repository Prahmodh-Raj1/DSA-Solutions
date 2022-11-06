//Problem link: https://leetcode.com/problems/minimum-path-sum/
//TC :O(N^2) SC:O(N^2)
class Solution {
public:
    int dp[201][201];
    int summ(vector<vector<int>>& grid,int i,int j){
        if(i<0 or j<0) return 1e9;
        if(i==0 and j==0) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        dp[i][j]=min(summ(grid,i-1,j),summ(grid,i,j-1))+grid[i][j];
        return dp[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        //dp[0][0]=grid[0][0];
        return summ(grid,grid.size()-1,grid[0].size()-1);
    }
};
