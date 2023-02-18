//Problem link: https://leetcode.com/problems/maximum-length-of-repeated-subarray/
//TC:O(M*N) SC:O(M*N)
class Solution {
public:
int longestCommonSubstringLength(string s1, string s2, int n1, int n2)
  {
   int maxLen = 0;
   int dp[n1 + 1][n2 + 1];
    
   for(int i = 0; i <= n1; i++)
     {
      for(int j = 0; j <= n2; j++)
        {
         if(i == 0 || j == 0) dp[i][j]=0;
          
         else if(s1[i - 1] == s2[j - 1])
           {
            dp[i][j] = 1 + dp[i-1][j-1];
            maxLen = max(maxLen, dp[i][j]);
           }
         else {
           dp[i][j]=0;
         }
        }
     }
      
   return maxLen;
  }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        string s1="",s2="";
        int n1=nums1.size();
        int n2=nums2.size();
        for(int i=0;i<n1;i++){
            s1+=nums1[i]+'0';
        }
        for(int i=0;i<n2;i++){
            s2+=nums2[i]+'0';
        }
        return longestCommonSubstringLength(s1,s2,n1,n2);
    }
};
