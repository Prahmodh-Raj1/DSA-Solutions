//Problem link: https://leetcode.com/problems/minimum-score-triangulation-of-polygon/description/
//TC:O(N^3) SC:O(N^2)
class Solution {
public:
    int func(int i,int j,vector<int>& values,vector<vector<int>>& dp){
        if(i==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=1e9;
        for(int k=i;k<=j-1;k++){
            int ans=values[i-1]*values[k]*values[j] + func(i,k,values,dp)+ func(k+1,j,values,dp);
            mini=min(mini,ans);
        }
        return dp[i][j]=mini;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return func(1,n-1,values,dp);
    }
};

//Tabulation
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        for(int i=1;i<n;i++) dp[i][i]=0; //base case
        for(int i=n-1;i>=1;i--){
            for(int j=i+1;j<n;j++){  //j is always to the right of j, so it starts from i+1
               
                int mini=1e9;
                for(int k=i;k<=j-1;k++){
                    int ans=values[i-1]*values[j]*values[k] + dp[i][k]+dp[k+1][j];
                    mini=min(ans,mini);
                }
                dp[i][j]=mini;

            }
        }
        return dp[1][n-1];
    }
