//Problem link: https://leetcode.com/problems/edit-distance/
//TC:O(N*M) SC:O(N*M)  + O(N+M) :Auxillary stack space
//Recursive DP
class Solution {
public:
    int edit(int i,int j,string& s1,string& s2,vector<vector<int>>& dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        if(s1[i]==s2[j]) ans=edit(i-1,j-1,s1,s2,dp);
        else{
            int ins=1+edit(i,j-1,s1,s2,dp);
            int del=1+edit(i-1,j,s1,s2,dp);
            int rep=1+edit(i-1,j-1,s1,s2,dp);
            ans=min(ins,min(del,rep));
        }
        return dp[i][j]=ans;

    }
  
  //Tabulation
      int minDistance(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        //we use 1-based indexing for tabulation
        for(int i=0;i<=n;i++){
            dp[i][0]=i;
        }
        for(int j=0;j<=m;j++) dp[0][j]=j;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1];
                else{
                    dp[i][j]=min(1+dp[i][j-1],min(1+dp[i-1][j],1+dp[i-1][j-1]));
                }
            }
        }
        return dp[n][m];
      }
 //Space optmization
    int minDistance(string s1, string s2) {
        int n=s1.size(),m=s2.size();
       
        vector<int> prev(m+1,0),cur(m+1,0);
        
        for(int j=0;j<=m;j++) prev[j]=j;
        for(int i=1;i<=n;i++){
            cur[0]=i;
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]) cur[j]=prev[j-1];
                else{
                    cur[j]=min(1+prev[j-1],min(1+cur[j-1],1+prev[j]));
                }
            }
            prev=cur;
        }
        return prev[m];
    }
