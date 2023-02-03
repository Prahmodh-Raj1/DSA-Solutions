//Problem link: https://leetcode.com/problems/coin-change-2/
//TC:O(N) SC: O(N)
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int dp[amount+1];
        dp[0]=1;
        for(int i=1;i<=amount;i++) dp[i]=0;
        for(int i=0;i<coins.size();i++){
            for(int j=1;j<=amount;j++){
                if(coins[i]<=j){
                    dp[j]+=dp[j-coins[i]];
                }
            }
        }
        return dp[amount];
    }
};


//TC:O(N*Amount) SC:O(Amount)
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
       // vector<vector<int>> dp(n,vector<int>(amount+1,0));
        
        vector<int> prev(amount+1,0),cur(amount+1);
        for(int t=0;t<=amount;t++){
            if(t%coins[0]==0) prev[t]=1;
            else prev[t]=0;
            
        }
        for(int i=1;i<n;i++){
            for(int a=0;a<=amount;a++){
                int nottake=prev[a];
                int take=0;
                if(coins[i]<=a) take=cur[a-coins[i]];
                cur[a]=(take+nottake);
            }
            prev=cur;
        }
        return prev[amount];
    }
};
