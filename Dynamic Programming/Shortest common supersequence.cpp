//Problem link: https://leetcode.com/problems/shortest-common-supersequence/description/
//TC:O(N^2) SC:O(N^2)
class Solution {
public:

string shortestCommonSupersequence(string s1, string s2) {
    //keep the lcs between the two strings common and add the remaining characters from both strings
    //For every character that belongs to the longest common subsequence, the non-lcs characters coming before them in the strings S1 and S2 are placed before the lcs-character in the answer string
  int n = s1.size();
  int m = s2.size();

  vector < vector < int >> dp(n + 1, vector < int > (m + 1, 0));
  for (int i = 0; i <= n; i++) {
    dp[i][0] = 0;
  }
  for (int i = 0; i <= m; i++) {
    dp[0][i] = 0;
  }

  for (int ind1 = 1; ind1 <= n; ind1++) {
    for (int ind2 = 1; ind2 <= m; ind2++) {
      if (s1[ind1 - 1] == s2[ind2 - 1])
        dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
      else
        dp[ind1][ind2] = 0 + max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
    }
  }

 
  string ans="";
  int i=n,j=m;

  while (i > 0 && j > 0) {
    if (s1[i - 1] == s2[j - 1]) {
      ans+= s1[i - 1];
      i--;
      j--;
    } else if (dp[i-1][j] > dp[i][j-1]) {
        ans+=s1[i-1];
        i--;
    } else{
        ans+=s2[j-1];
         j--;
    } 
  }
  while(i>0){
      ans+=s1[i-1];
      i--;
  } 
  while(j>0){
      ans+=s2[j-1];
      j--;
  } 
  reverse(ans.begin(),ans.end());
  return ans;        
}
};
