//Problem link: https://leetcode.com/problems/number-of-ways-to-earn-points/
//TC:O(N*TARGET) SC:O(N*TARGET)

class Solution {
public:
    const int mod=1e9+7;
    int func(vector<vector<int>>& types,int i,int curmarks,int target,vector<vector<int>>& dp){
        if(curmarks==target) return 1;
        if(curmarks>target) return 0;
        if(i==types.size()) return 0;
        if(dp[i][curmarks]!=-1) return dp[i][curmarks];
        int ans=0;
        for(int j=0;j<=types[i][0];j++){
            ans+=func(types,i+1,curmarks + j*types[i][1],target,dp);
            ans%=mod;
        }
        return dp[i][curmarks]=ans%mod;
    }
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n=types.size();

        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return func(types,0,0,target,dp);
    }
};
