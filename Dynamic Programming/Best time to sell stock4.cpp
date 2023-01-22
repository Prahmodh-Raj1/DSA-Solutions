//Memoization :TC: O(N*2*K) SC:O(N*2*K)
    int func1(int i,int trans,int k,vector<int>& prices,vector<vector<int>>& dp){
        if(i==prices.size() or trans==2*k) return 0;
      
        if(dp[i][trans]!=-1) return dp[i][trans];
        int profit=0;
        if(trans%2==0){
            profit=max(func1(i+1,trans+1,k,prices,dp)-prices[i],func1(i+1,trans,k,prices,dp));
        }else{
            profit=max(func1(i+1,trans+1,k,prices,dp)+prices[i],func1(i+1,trans,k,prices,dp));
        }
        return dp[i][trans]=profit;
    }


//Memoization -2
class Solution {
public:
    int func(int i,int b,int limit,vector<int>& prices,vector<vector<vector<int>>>& dp){
        if(i==prices.size()) return 0;
        if(limit==0) return 0;
        if(dp[i][b][limit]!=-1) return dp[i][b][limit];
        int profit=0;
        if(b){
            profit=max(func(i+1,0,limit,prices,dp)-prices[i],func(i+1,1,limit,prices,dp));
        }else{
            profit=max(func(i+1,1,limit-1,prices,dp)+prices[i],func(i+1,0,limit,prices,dp));
        }
        return dp[i][b][limit]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
       //int limit=2; //max no. of transactions
       vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
       return func(0,1,k,prices,dp);       
    }
};

//Tabulation
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
      
       vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
       for(int i=0;i<n;i++){ //if cap is 0;
           for(int j=0;j<=1;j++){
               dp[i][j][0]=0;
           } 
       }
       for(int j=0;j<=1;j++){
           for(int l=0;l<=k;l++){
               dp[n][j][l]=0;
           }
       }
       int profit=0;
       for(int i=n-1;i>=0;i--){
           for(int j=0;j<=1;j++){
               for(int limit=1;limit<=k;limit++){
                   if(j){
                       profit=max(dp[i+1][0][limit]-prices[i],dp[i+1][1][limit]);
                   }else{
                       profit=max(dp[i+1][1][limit-1]+prices[i],dp[i+1][0][limit]);
                   }
                   dp[i][j][limit]=profit;
               }
           }
       }
       return dp[0][1][k];      
    }
};

//1D space optimization:
    int maxProfit(int k, vector<int>& prices){
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2*k,-1));
        vector<int> ahead(2*k +1,0),cur(2*k +1,0);
        for(int i=n-1;i>=0;i--){
            for(int t=2*k -1;t>=0;t--){
                
                if(t%2==0){
                    cur[t]=max(ahead[t+1]-prices[i],ahead[t]);
                }else{
                    cur[t]=max(ahead[t+1]+prices[i],ahead[t]);
                }
            }
            ahead=cur;
        }
        return ahead[0];
    }
