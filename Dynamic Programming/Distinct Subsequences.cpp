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

//Tabulation
  int numDistinct(string s, string t) {
        int n=s.size(),m=t.size();
        vector<vector<double>> dp(n+1,vector<double>(m+1,0));
        //we'll use 1-based indexing for tabulation
        for(int i=0;i<=n;i++){
            
            dp[i][0]=1;
        }
        for(int j=1;j<=m;j++){
            dp[0][j]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return (int)dp[n][m];
        
    }
};

//Space optimization - 2 arrays
 int numDistinct(string s, string t) {
        int n=s.size(),m=t.size();
        //vector<vector<double>> dp(n+1,vector<double>(m+1,0));
        //we'll use 1-based indexing for tabulation
        vector<double> prev(m+1,0),cur(m+1,0);

        prev[0]=cur[0]=1;
       
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    cur[j]=prev[j]+prev[j-1];
                }else{
                    cur[j]=prev[j];
                }

            }
            prev=cur;
        }
        return (int)prev[m];
        
    }

    int numDistinct(string s, string t) {
        int n=s.size(),m=t.size();
        //vector<vector<double>> dp(n+1,vector<double>(m+1,0));
        //we'll use 1-based indexing for tabulation
        vector<double> prev(m+1,0);

        prev[0]=1;
       
        for(int i=1;i<=n;i++){
            for(int j=m;j>=1;j--){
                if(s[i-1]==t[j-1]){
                    prev[j]=prev[j]+prev[j-1];
                }

            }
            
        }
        return (int)prev[m];
        
    }
};

