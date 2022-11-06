//Problem link: https://leetcode.com/problems/cherry-pickup/description/
//TC: O(N^3) SC:O(N^3)

class Solution {
public:

    int dp[51][51][51];
    int ways(int r1,int c1,int r2,int n,vector<vector<int>>& grid){
        int c2=r1+c1-r2;
        if (r1 >= grid.size() || c1 >= grid.size() || r2 >=grid.size() || c2>=grid.size() or grid[r1][c1]==-1 or grid[r2][c2]==-1) return INT_MIN;
        if(dp[r1][c1][r2]!=-1) return dp[r1][c1][r2];
        if(r1==grid.size()-1 and c1==grid.size()-1) return grid[r1][c1];
        
        int ans=grid[r1][c1]; 
        if(r1!=r2) ans+=grid[r2][c2];
        int first=max(ways(r1+1,c1,r2+1,n,grid),ways(r1+1,c1,r2,n,grid));
        
        first=max(first,ways(r1,c1+1,r2+1,n,grid));
        first=max(first,ways(r1,c1+1,r2,n,grid));
        ans+=first;
        dp[r1][c1][r2]=ans;
        return dp[r1][c1][r2];
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        memset(dp,-1,sizeof(dp));
        return max(0,ways(0,0,0,grid.size(),grid));
    }
};
