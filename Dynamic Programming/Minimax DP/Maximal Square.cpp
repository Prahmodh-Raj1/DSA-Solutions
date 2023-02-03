//Problem link: https://leetcode.com/problems/maximal-square/
//TC:O(N*M) SC:O(N*M)

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n= matrix[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        if(m==1 and n==1){
            return matrix[m-1][n-1]-'0';
        }
        int cnt=0;
        for(int i=0;i<m;i++){
            if(matrix[i][0]=='1'){
                dp[i][0]=1;
                cnt++;
            }else dp[i][0]=0;
        
        }
        for(int i=0;i<n;i++){
            if(matrix[0][i]=='1'){
                dp[0][i]=1;
                cnt++;
            }else dp[0][i]=0;
        }
        int maxi=(cnt>0)? 1:0;
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]=='1'){
                    dp[i][j]=min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]))+1;
                    maxi=max(maxi,dp[i][j]);
                   
                }else{
                    dp[i][j]=0;
                }
              
            }
        }
        return maxi*maxi;
    }
};
