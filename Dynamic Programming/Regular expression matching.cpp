//Problem link: https://leetcode.com/problems/regular-expression-matching/description/
//TC:O(N*M) SC:O(N*M)
   bool func(int i,int j,string& s,string& p,vector<vector<int>>& dp){
        if(i<0 and j<0) return true;
        if( i>=0 and j<0) return false;
        if(i<0 and j>=0){
            int cnt=0;
            int len=j+1;
            if(len & 1) return false;
            while(j>=0){
                if(p[j--]=='*') cnt++;
            }
            
            return cnt == len/2;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==p[j] || p[j]=='.') return dp[i][j]=func(i-1,j-1,s,p,dp);
        else if(p[j]=='*'){
            return dp[i][j]= func(i,j-2,s,p,dp) || ((s[i]==p[j-1] || p[j-1]=='.') && func(i-1,j,s,p,dp));
        }
        return dp[i][j]=false;
    }
