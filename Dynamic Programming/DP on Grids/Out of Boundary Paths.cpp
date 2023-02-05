//Problem link: https://leetcode.com/problems/out-of-boundary-paths/
//TC:O(M*N*Moves) SC:O(N*M*Moves)
class Solution {
public:
    const int mod = 1e9 +7;
    
    int m1,n1;
    
    int func(int i,int j,int moves,vector<vector<vector<int>>>& dp,int maxMove){
        if(i>=m1 or i<0 or j>=n1 or j<0) return 1;
        
        if(moves==maxMove){
            return 0;
        }
        if(dp[i][j][moves]!=-1) return dp[i][j][moves];
        int ans=0;
        ans=(ans+func(i,j-1,moves+1,dp,maxMove))%mod;
        ans=(ans+func(i,j+1,moves+1,dp,maxMove))%mod;
        ans= (ans+func(i-1,j,moves+1,dp,maxMove))%mod;
        ans=(ans+func(i+1,j,moves+1,dp,maxMove))%mod;
        return dp[i][j][moves]=ans%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        m1=m,n1=n;
        cout<<m1<<" "<<n1<<"\n";
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(maxMove+1,-1)));
        return func(startRow,startColumn,0,dp,maxMove);
    }
};
