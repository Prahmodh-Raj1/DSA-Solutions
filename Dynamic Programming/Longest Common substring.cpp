//TC:O(N*M) SC:O(N*M)
int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        //for a substring, we don't need to depend on the previous tabulated values
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        int maxi=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    
                }
                else{
                    dp[i][j]=0;
                }
                maxi=max(maxi,dp[i][j]);
            }
        }
        return maxi;
    }

//Space optimised solution : SC:O(2*M)

int longestCommonSubstr (string s1, string s2, int n, int m)
    {
      
        vector<int> prev(m+1,0),cur(m+1,0);
        prev[0]=0; cur[0]=0;
        int maxi=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    cur[j]=1+prev[j-1];
                }   
                else{
                    cur[j]=0;
                }
                maxi=max(maxi,cur[j]);
                
            }
            prev=cur;
        }
        return maxi;
    }


