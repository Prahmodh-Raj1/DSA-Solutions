//Problem link: https://leetcode.com/problems/coin-change/description/
//Tabulated DP and Space optmized approach
//TC: O(N*Amount) SC :O(N*AMOUNT) / O(2*Amount)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        vector<int> prev(amount+1,0);
        vector<int> cur(amount+1,0);
        for(int t=0;t<=amount;t++){
            if(t%coins[0]==0){
                prev[t]=t/coins[0];
            }else{
                prev[t]=1e9;
            }
        }
        for(int i=1;i<n;i++){
            for(int a=0;a<=amount;a++){
               
                int nottake=prev[a];
                int take=INT_MAX;
                if(coins[i]<=a){
                    take=1+cur[a-coins[i]];  //staying in the same index, as we can collect more coins of the same denomination
                }
                cur[a]=min(nottake,take);  //dp[i] => cur[a], dp[i-1]=prev[a];
            }
            prev=cur;
        }
        int ans=prev[amount];
        if(ans>=1e9) return -1;
        return ans;
    }
};
