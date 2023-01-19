//Problem link:https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/
//TC:O(N^2) SC;o(N^2)

class Solution {
public:
    int minInsertions(string s) {
        //keep the longest palindromic subseq constant, then
        //for the characters that do  not have a matching character, we just reverse that character and add it to the string on the other side
        //leetcode, the lps is eee
        //so we reverse it and write as leetcodocteel
        //EG: abcaa, lps: aaa
        //write it as abcacba
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
        return n-dp[0][n-1];
    }
};
