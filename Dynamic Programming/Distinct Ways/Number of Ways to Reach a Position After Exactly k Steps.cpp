//Problem link: https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/
//TC:O(N*K)   SC:O(N*K)
class Solution {
public:
    const int mod=1e9 +7;
    //unordered_map<pair<int,int>,int> dp;
    int func(int i,int cnt,vector<vector<int>>& dp,int endpos,int k){
        
        if(cnt==k){
            if(i==endpos) return 1;
            return 0;
        }
        if(dp[i+2000][cnt]!=-1) return dp[i+2000][cnt]%mod;
        int ans=0;
        ans= (ans + func(i+1,cnt+1,dp,endpos,k))%mod;
        ans= (ans+ func(i-1,cnt+1,dp,endpos,k))%mod;
        return dp[i+2000][cnt]= ans%mod;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>> dp(4000,vector<int>(k+1,-1));
        return func(startPos,0,dp,endPos,k);
    
    }
};
