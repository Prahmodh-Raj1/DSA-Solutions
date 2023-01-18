//Problem link: https://leetcode.com/problems/longest-common-subsequence/
//TC : O(N*M) SC: O(N*M)
//Recursive DP
class Solution {
public:
    int dp[1004][1004];
    int FindLcs(int i,int j,string& text1,string& text2){
        if(i==text1.size() or j==text2.size()){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        ans=max(ans,FindLcs(i+1,j,text1,text2));
        ans=max(ans,FindLcs(i,j+1,text1,text2));
        if(text1[i]==text2[j]){
            ans=max(ans,1+FindLcs(i+1,j+1,text1,text2));
        }
        ans=max(ans,FindLcs(i+1,j+1,text1,text2));
        dp[i][j]=ans;
        return dp[i][j];
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        int lcs=FindLcs(0,0,text1,text2);
        return lcs;
    }
};

//Iterative DP

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(text1[i]==text2[j]){
                    dp[i+1][j+1]=1+dp[i][j];
                }else{
                    dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        return dp[n][m];
    }
};

//Space optimised soln SC:O(2*N)

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<int> prev(m+1,0),cur(m+1,0);
        
        for(int i=0;i<=m;i++) prev[i]=0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    cur[j]=1+prev[j-1];
                }else{
                    cur[j]=max(prev[j],cur[j-1]);
                }
            }
            prev=cur;
        }
        return prev[m];
    }
};

