//Problem Link: https://leetcode.com/problems/longest-palindromic-subsequence/
//TC : O(N^2) SC : O(N^2)
class Solution {
public:
    int dp[1002][1002];
    int FindLps(int left,int right,string& s){
        if(left>right) return 0;
        if(left==right) return 1;
        if(dp[left][right]!=-1) return dp[left][right];
        int ans=0;
        if(s[left]==s[right]) ans=2+FindLps(left+1,right-1,s);
        else ans=max(FindLps(left+1,right,s),FindLps(left,right-1,s));
        dp[left][right]=ans;
        return dp[left][right];
    }
    int longestPalindromeSubseq(string s) {
        memset(dp,-1,sizeof(dp));
        int n=s.length();
        return FindLps(0,n-1,s);
        
    }
};


//Tabulation
int longestPalindromeSubseq(string s) {
        int n=s.size();
        int l=0,r=n-1;

        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            dp[i][i]=1;
            for(int j=i+1;j<n;j++){
                if(i==j){
                    dp[i][j]=1;
                }
                if(i>j){
                    dp[i][j]=0;
                }
                int ans=0;
                if(s[i]==s[j]){
                    ans=2+dp[i+1][j-1];
                }else{
                    ans=max(dp[i+1][j],dp[i][j-1]);
                }
                dp[i][j]=ans;
            }
        }
        return  dp[0][n-1];
       
    }

//Can also be solved by reversing the string and finding the LCS btwn the two strings
