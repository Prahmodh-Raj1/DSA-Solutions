//Problem link: https://leetcode.com/problems/longest-palindromic-substring
//TC: O(N*N) SC: O(N*N)
class Solution {
    public String longestPalindrome(String s) {
        //StringBuilder ans = new StringBuilder();
        //dp [i,j] represents whether s[i...j] can form a palindromic substring, dp(i,j) is true
        //when s[i] equals s[j] and s[i+1....j-1] is a palindromic substrinng
        //Keep updating the answer with the max length
        int n = s.length();
        String res = "";
        boolean dp[][] = new boolean[n][n];
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s.charAt(i)==s.charAt(j) && (j-i<3 || dp[i+1][j-1])){
                    //a palindrome can be recorded if the length of the remaining string is less than or equal to 2
                    dp[i][j]=true;
                }else{
                    dp[i][j]=false;
                }
                if(dp[i][j] && (res=="" || j-i+1>res.length())){
                    res=s.substring(i,j+1);
                }
            }
        }
        return res;
    }
}
