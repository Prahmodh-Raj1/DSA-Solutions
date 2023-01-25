//Problem link: https://leetcode.com/problems/burst-balloons/
class Solution {
public:
//TC:O(N^3) SC:O(N^2)
    int func(int i,int j,vector<int>& nums,vector<vector<int>>& dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int maxi=INT_MIN;
        for(int k=i;k<=j;k++){
            int cost=nums[i-1]*nums[k]*nums[j+1] + func(i,k-1,nums,dp)+func(k+1,j,nums,dp);
            maxi=max(cost,maxi);
        }
        return dp[i][j]=maxi;
    }
    
    int maxCoins(vector<int>& nums) {
        
        int n=nums.size();
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        //move in the opposite direction
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        for(int i=n;i>=1;i--){
            for(int j=1;j<=n;j++){
                if(i>j) continue; //base case
                int maxi=INT_MIN;
                for(int k=i;k<=j;k++){
                    int cost=nums[i-1]*nums[k]*nums[j+1] +dp[i][k-1]+dp[k+1][j];
                    maxi=max(maxi,cost);
                }
                dp[i][j]=maxi;
            }
        }
        return dp[1][n];
        //return func(1,n,nums,dp);
    }
};
