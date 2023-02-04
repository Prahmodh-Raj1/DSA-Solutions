//Problem link: https://leetcode.com/problems/minimum-path-cost-in-a-grid/description/
//TC:O(M*N*K) SC:O(M*N) + Auxillary stack space
class Solution {
public:
    int m;
    int n;
    int func(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& moveCost,vector<vector<int>>& dp){
        if(i==m-1){
            return grid[m-1][j];
        }
        int res=INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int k=0;k<n;k++){
            res=min(res,func(i+1,k,grid,moveCost,dp)+moveCost[grid[i][j]][k]+grid[i][j]);
        }
        return dp[i][j]=res;
        
        
        
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        int ans=1e9;
        
        for(int k=0;k<n;k++){
            ans=min(ans,func(0,k,grid,moveCost,dp));
        }
        return ans;
    }
};

//Tabulation
//TC:O(M*N*K) SC:O(M*N)
int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,1e9));
        int ans=1e9;
        for(int j=0;j<n;j++){
            dp[m-1][j]=grid[m-1][j];
        }
        for(int i=m-2;i>=0;i--){
            for(int j=0;j<n;j++){
                int ans=1e9;
                for(int k=0;k<n;k++){
                    ans=min(ans,dp[i+1][k]+moveCost[grid[i][j]][k]+grid[i][j]);
                }
                dp[i][j]=ans;
            }
        }
        return *min_element(dp[0].begin(),dp[0].end());
}
