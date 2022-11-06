//Problem  link: https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/
//TC : O(N^2) SC :O(N^2)
class Solution {
public:
    const int mod=1e9 + 7;
    long long dp[5001][2];
    //color=0 is the three color pattern and color=1 is the two color pattern
    long long ways(int i,int n,int color){
        if(i==n-1){
            return 1;
        }
        if(dp[i][color]!=-1) return (dp[i][color])%mod;
        long long ans=0;
        ans=((ways(i+1,n,color)*2)%mod + (ways(i+1,n,1-color)*2)%mod)%mod;
        if(color==0){
            ans+=(ways(i+1,n,color))%mod;
        }
        dp[i][color]=ans;
        return dp[i][color]; 
    }
    int numOfWays(int n) {
        memset(dp,-1,sizeof(dp));
        return (((ways(0,n,0)*6)%mod)+((ways(0,n,1)*6)%mod))%mod;
    }
};
