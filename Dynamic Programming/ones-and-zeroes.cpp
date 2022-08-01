//Problem link: https://leetcode.com/problems/ones-and-zeroes/
//TC :O(S*M*N)  SC:O(M*N)
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1)); //implementing 2d DP since we need to take care of two constraints-(m & n)
        for(int k=0;k<strs.size();k++){
            int zeroc=count(strs[k].begin(),strs[k].end(),'0');
            int onec=count(strs[k].begin(),strs[k].end(),'1');
            for(int i=m;i>=zeroc;i--){
                for(int j=n;j>=onec;j--){
                    dp[i][j]=max(dp[i][j],dp[i-zeroc][j-onec]+1); //either leaving the current string or adding one to optimal solution
                }
            }
        }
        return dp[m][n];
    }
};
