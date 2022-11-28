//Problem link:https://leetcode.com/problems/distinct-subsequences/
//TC:O(N^2) SC:O(N^2)

class Solution {
public:
    int dp[1001][1001];
    int distinctsub(int i,int j,string& s,string& t){
        if(j>=t.length()) return 1;
        if(i>=s.length()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i]==t[j]){
            dp[i][j]=distinctsub(i+1,j,s,t)+distinctsub(i+1,j+1,s,t);
        }else dp[i][j]=distinctsub(i+1,j,s,t);
    
        return dp[i][j];
    }
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return distinctsub(0,0,s,t);
    }
};
