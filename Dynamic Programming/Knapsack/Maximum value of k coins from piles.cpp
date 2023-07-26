//Problem link: https://leetcode.com/problems/maximum-value-of-k-coins-from-piles
//TC: O(N*K) SC: O(N*K)
class Solution {
private:
    int helper(int ind,int k,vector<vector<int>>& piles,vector<vector<int>>& dp){
        if(ind==piles.size()){
            return 0;
        }
        
        if(dp[ind][k]!=-1){
            return dp[ind][k];
        }
        int nottake = helper(ind+1,k,piles,dp);
        int take =0;
        int ans = max(nottake,take);
        for(int j=0;j<piles[ind].size();j++){
            if(j+1<=k){
                //we can pick those many coins from the current pile
                take = piles[ind][j] + helper(ind+1,k-j-1,piles,dp);
                ans = max(ans,take);  //finding the maximum at every possibility
            }
        }
        return dp[ind][k]=ans;

    }
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        //form a prefix array for each pile
        //we either pick or not pick from a pile
        //if we have the capacity to pick coins from a pile,
        //then let's say we have chosen x coins from it
        //and we move to the next pile
        //Base cases:
        //if k==0,  return 0
        //if ind==n, return 0
        //Return the max from all the possibilites at the index
        for(int i=0;i<n;i++){
            for(int j=1;j<piles[i].size();j++){
                piles[i][j] = piles[i][j-1]+piles[i][j];  //using prefix sum to find the number of points that we'll obtain on collecting the piles[i][j] coin, this helps in reducing complexity
            }
        }
        return helper(0,k,piles,dp);
    }
};
