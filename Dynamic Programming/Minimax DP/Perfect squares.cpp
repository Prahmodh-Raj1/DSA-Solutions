//Problem link: 

//TC:O(N*ROOT(N)) SC:O(N)
//Memoization
    int find(int n,vector<int>& dp){
        if(n<=3) return n;
        if(dp[n]!=-1) return dp[n];
        int ans=n;
        for(int i=1;i*i<=n;i++){
            ans=min(ans,1+find(n-(i*i),dp));
        }
        return dp[n]=ans;
    }
//Tabulation
    int numSquares(int n) {
        vector<int> dp(n+1,0);
        
        for(int i=1;i<=n;i++){
            
            dp[i]=i;
            for(int j=1;j*j<=i;j++){
                dp[i]=min(dp[i],1+dp[i-(j*j)]);
            }
        }
        return dp[n];
        //return find(n,dp);
    }
