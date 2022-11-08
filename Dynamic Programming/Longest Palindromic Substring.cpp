//Problem link: https://leetcode.com/problems/longest-palindromic-substring/
//TC : O(N^2) SC:O(N^2)
class Solution {
public:
    bool dp[1001][1001];
    
    string longestPalindrome(string s) {
        
        int n=s.length();
        int maxi=INT_MIN;
        string ans="";
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i]==s[j]){
                    if(j-i<=2) dp[i][j]=true;
                    else dp[i][j]=dp[i+1][j-1];
                }
                if(dp[i][j]==true and j-i+1>maxi){
                    maxi=j-i+1;
                    ans=s.substr(i,j-i+1);
                } 
            }
        }
        return ans;
    }
};
