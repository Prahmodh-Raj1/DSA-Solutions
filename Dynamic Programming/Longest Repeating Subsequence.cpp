//Problem Link: https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/
//TC :O(N^2) SC :O(N^2)class Solution {
class Solution{
public:
	  int dp[1002][1002];
    int FindLRS(int l,int r,string& s){
	        if(l<0 or r<0) return 0;
	        if(dp[l][r]!=-1) return dp[l][r];
	        int ans=0;
	        if(s[l]==s[r] and l!=r){
	            ans=1+FindLRS(l-1,r-1,s);
	        }else ans=max(FindLRS(l-1,r,s),FindLRS(l,r-1,s));
	        
	        dp[l][r]=ans;
	        return dp[l][r];
	  }
    int LongestRepeatingSubsequence(string str){
		    memset(dp,-1,sizeof(dp));
		    return FindLRS(str.length()-1,str.length()-1,str);
		    
		}
};
