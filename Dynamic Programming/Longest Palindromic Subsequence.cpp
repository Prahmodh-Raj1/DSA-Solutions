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
