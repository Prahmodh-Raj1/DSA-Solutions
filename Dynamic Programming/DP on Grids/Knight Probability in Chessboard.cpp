//Problem link:https://leetcode.com/problems/knight-probability-in-chessboard/
//TC:O(N^2 * K) SC:O(N^2 *K)
 double func(int i,int j,int n,int k,vector<vector<vector<double>>>& dp){
        if(i<0 or i>=n or j<0 or j>=n){
            return 0;
        }
        if(k==0){
            
            return 1;
            
        }
        

        
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        double ans=0;
        ans+=0.125*func(i-2,j-1,n,k-1,dp);
        ans+=0.125*func(i-2,j+1,n,k-1,dp);
        ans+=0.125*func(i-1,j-2,n,k-1,dp);
        ans+=0.125*func(i-1,j+2,n,k-1,dp);
        ans+=0.125*func(i+1,j-2,n,k-1,dp);
        ans+=0.125*func(i+2,j-1,n,k-1,dp);
        ans+=0.125*func(i+2,j+1,n,k-1,dp);
        ans+=0.125*func(i+1,j+2,n,k-1,dp);
        return dp[i][j][k]=ans;
    }
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n+1,vector<vector<double>>(n+1,vector<double>(k+1,-1)));
        return func(row,column,n,k,dp);
       
        //return res;
    }
