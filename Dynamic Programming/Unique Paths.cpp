//Problem link: https://leetcode.com/problems/unique-paths/
//TC :O(N*M) SC:O(N*M)
//Top-Down Approach
class Solution {
public:
    int dp[104][104];
    int countpaths(int m,int n){
        if(m==1 or n==1){
            dp[m][n]=1;
            return dp[m][n];
        }
        if(dp[m][n]==0) dp[m][n]=countpaths(m-1,n)+countpaths(m,n-1);
        return dp[m][n];
    }
    int uniquePaths(int m, int n) {
       memset(dp,0,sizeof(dp));
       return countpaths(m,n);
    }
};

//Bottom Up Approach
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 or j==0){
                    dp[i][j]=1;
                }else{
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};
