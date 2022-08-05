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
