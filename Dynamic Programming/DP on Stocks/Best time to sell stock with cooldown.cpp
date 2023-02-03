//Memoization: TC:O(N*2) SC:O(N*2) + Auxilliary stack space
//Tabulation: TC:O(N*2) SC:O(N*2)
class Solution {
public:
    int func(int i,int canbuy,int n,vector<int>& prices,vector<vector<int>>& dp){
        if(i>=n) return 0;
        if(dp[i][canbuy]!=-1) return dp[i][canbuy];
        int profit=0;
        if(canbuy){
            int take=-1*prices[i] + func(i+1,0,n,prices,dp);
            int nottake=func(i+1,1,n,prices,dp);  //not selling, so we can buy
            profit=max(take,nottake);
        }
        else{
            profit=max(prices[i]+func(i+2,1,n,prices,dp),func(i+1,0,n,prices,dp));
        }
        return dp[i][canbuy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        //vector<int> prev(3,0),cur(3,0);

        int profit;
        for(int i=n-1;i>=0;i--){ //opp to the memoization flow
            for(int b=0;b<2;b++){
                profit=0;
                if(b){
                  profit=max(dp[i+1][0]-prices[i],dp[i+1][1]);  
                }else{
                    profit=max(dp[i+2][1]+prices[i],dp[i+1][0]);
                }
                dp[i][b]=profit;
            }
            
        }
        return dp[0][1]; 
    }
};

//Space optimization
    int maxProfit(vector<int>& Arr) {
        int n=Arr.size();
    vector<int> cur(2,0);
    vector<int> front1(2,0);
    vector<int> front2(2,0);
    
    for(int ind = n-1; ind>=0; ind--){
        for(int buy=0; buy<=1; buy++){
            int profit;
            
            if(buy==0){// We can buy the stock
                profit = max(0+front1[0], -Arr[ind] + front1[1]);
            }
    
            if(buy==1){// We can sell the stock
                profit = max(0+front1[1], Arr[ind] + front2[0]);
            }
            
            cur[buy] = profit;
        }
        
        front2 = front1;
        front1 = cur;
        
    }
    
    return cur[0];
 
    }
