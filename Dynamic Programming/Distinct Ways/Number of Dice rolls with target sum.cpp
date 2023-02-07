//Problem link: https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
//TC:O(N*Target*K) SC:O(N*target)
class Solution {
public:
    const int mod=1e9 +7;
    int func(int n,int k,int target,vector<vector<int>>& dp){
        if(n==0 or target<0){
            if(target==0) return 1;
            return 0;
        }
        
        if(dp[n][target]!=-1) return dp[n][target]%mod;
        int ans=0;
        for(int i=1;i<=k;i++){
            ans=(ans+func(n-1,k,target-i,dp))%mod;
        }
        return dp[n][target]=ans%mod;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        int ans= (func(n,k,target,dp))%mod;
        return ans;
    }
};
