//Problem link: https://leetcode.com/problems/reducing-dishes/
//TC:O(N^2) SC:O(N^2)
class Solution {
public:
    int func(int i,int cnt,vector<int>& sat,vector<vector<int>>& dp){
        if(i>=sat.size()) return 0;
        if(dp[i][cnt]!=-1) return dp[i][cnt];
        int nottake= func(i+1,cnt,sat,dp);
        int take=sat[i]*cnt + func(i+1,cnt+1,sat,dp);
        return dp[i][cnt]=max(take,nottake);
    }
    int maxSatisfaction(vector<int>& sat) {
        int n=sat.size();
        sort(sat.begin(),sat.end());
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return func(0,1,sat,dp);

    }
};
