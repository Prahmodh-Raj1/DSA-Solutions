//Memoization: TC:O(N*2) SC:O(N*2) +Auxillary stack space
    int func(int i,int canbuy,int n,vector<int>& prices,vector<vector<int>>& dp){  //canbuy is initialised to one 
        if(i==n) return 0;
        if(dp[i][canbuy]!=-1) return dp[i][canbuy];
        int profit=0;
        if(canbuy){
            int take=-1*prices[i] + func(i+1,0,n,prices,dp);
            int nottake=func(i+1,1,n,prices,dp);  //not selling, so we can buy
            profit=max(take,nottake);
        }
        else{
            profit=max(prices[i]+func(i+1,1,n,prices,dp),func(i+1,0,n,prices,dp));
        }
        return dp[i][canbuy]=profit;
    }

//Iterative DP: TC:O(N*2) SC:O(N*2)
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        dp[n][0]=dp[n][1]=0;
        int profit;
        for(int i=n-1;i>=0;i--){ //opp to the memoization flow
            for(int b=0;b<2;b++){
                profit=0;
                if(b){
                  profit=max(dp[i+1][0]-prices[i],dp[i+1][1]);  
                }else{
                    profit=max(dp[i+1][1]+prices[i],dp[i+1][0]);
                }
                dp[i][b]=profit;
            }
        }
        return dp[0][1];  //we return the case where we initially started with the case of buying possible
    }

//Space optmization: TC:O(N*2) SC:O(1), can also be done using 4 variables, instead of two 2-sized arrays
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
       
        vector<int> prev(2,0),cur(2,0);
        prev[0]=prev[1]=0;
        int profit;
        for(int i=n-1;i>=0;i--){ //opp to the memoization flow
            for(int b=0;b<2;b++){
                profit=0;
                if(b){
                  profit=max(prev[0]-prices[i],prev[1]);  
                }else{
                    profit=max(prev[1]+prices[i],prev[0]);
                }
                cur[b]=profit;
            }
            prev=cur;
        }
        return prev[1];
    }
