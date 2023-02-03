//Recursive DP: TC:O(N*2*3) SC:O(N*2*3) + Auxillary stack space
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
    int maxProfit(vector<int>& prices) {
       int n=prices.size();
       int limit=2; //max no. of transactions
       vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
       return func(0,1,limit,prices,dp); 
    }
};

//Iterative DP: TC:O(N*2*3) SC:O(N*2*3)
    int maxProfit(vector<int>& prices) {
       int n=prices.size();
       int limit=2; //max no. of transactions
       vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
       for(int i=0;i<n;i++){ //if cap is 0;
           for(int j=0;j<1;j++){
               dp[i][j][0]=0;
           } 
       }
       for(int j=0;j<=1;j++){
           for(int l=0;l<=2;l++){
               dp[n][j][l]=0;
           }
       }
       int profit=0;
       for(int i=n-1;i>=0;i--){
           for(int j=0;j<=1;j++){
               for(int limit=1;limit<=2;limit++){
                   if(j){
                       profit=max(dp[i+1][0][limit]-prices[i],dp[i+1][1][limit]);
                   }else{
                       profit=max(dp[i+1][1][limit-1]+prices[i],dp[i+1][0][limit]);
                   }
                   dp[i][j][limit]=profit;
               }
           }
       }
       return dp[0][1][2];
    }

//2-D Array Space optimization
    int maxProfit(vector<int>& prices) {
       int n=prices.size();
       vector<vector<int>> prev(2,vector<int>(3,0)),cur(2,vector<int>(3,0));
       for(int j=0;j<=1;j++) prev[j][0]=0;

       int profit=0;
       for(int i=n-1;i>=0;i--){
           for(int j=0;j<=1;j++){
               for(int limit=1;limit<=2;limit++){
                   if(j){
                       profit=max(prev[0][limit]-prices[i],prev[1][limit]);
                   }else{
                       profit=max(prev[1][limit-1]+prices[i],prev[0][limit]);
                   }
                   cur[j][limit]=profit;
               }
           }
           prev=cur;
       }
       return prev[1][2];
        
    }

//1-D array space optimization(ALmost constant) TC:O(N*4)
    int maxProfit(vector<int>& prices) {
       int n=prices.size();
     
        //This prob can also be solved in N*4 Space, 
        //Buy:0, Sell:1, Buy: 2, Sell: 3
        //The even indices indicate a buy and the odd indices indicate a sell
        vector<int> prev(5,0),cur(5,0);

       int profit=0;
       for(int i=n-1;i>=0;i--){
           for(int j=3;j>=0;j--){
               
               //for(int limit=1;limit<=2;limit++){
                   if(j%2==0){
                       profit=max(prev[j+1]-prices[i],prev[j]);
                   }else{
                       profit=max(prev[j+1]+prices[i],prev[j]);
                   }
                   cur[j]=profit;
               }
           
                prev=cur;
       }
       return prev[0];
       
    }
