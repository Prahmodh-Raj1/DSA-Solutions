//Problem link: https://leetcode.com/problems/dungeon-game/
//TC:O(M*N) SC:O(M*N)

class Solution {
public:
    int func(int i,int j,int m,int n,vector<vector<int>>& dungeon,vector<vector<int>>& dp){
        if(i==m-1 and j==n-1){
            if(dungeon[i][j]<=0) return 1-dungeon[i][j];
            return 1;
        }
        if(i>=m or j>=n) return 1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        int down = func(i+1,j,m,n,dungeon,dp);
        int right = func(i,j+1,m,n,dungeon,dp);
        int health= min(down,right) - dungeon[i][j];
        return dp[i][j]= (health<=0)?1:health;
        
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size(),n=dungeon[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return func(0,0,m,n,dungeon,dp);
    }
};
