//problem link: https://leetcode.com/problems/predict-the-winner/
//TC: O(n*n) SC: O(N*N)
class Solution {
private:
    int helper(vector<int>& nums,int left,int right,vector<vector<int>>& dp){
        if(left>right) return 0;
        if(left==right) return nums[left];
        if(dp[left][right]!=-1) return dp[left][right];
        int ans = max(0,nums[left] + min(helper(nums,left+2,right,dp),helper(nums,left+1,right-1,dp)));
        ans = max(nums[right] + min(helper(nums,left+1,right-1,dp),helper(nums,left,right-2,dp)),ans);
        return dp[left][right]=ans;
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));  //indicates the score the first person can score in the range [left...right]
        int total = accumulate(nums.begin(),nums.end(),0);
        int firstscore = helper(nums,0,n-1,dp);
        if(firstscore>=total-firstscore) return true;
        return false;
    }
};
/*
currently 1st with choosable i, j,
        1.if 1st picks nums[i], 2nd can pick either ends of nums[i + 1, j]
            a.if 2nd picks nums[i + 1], 1st can pick either ends of nums[i + 2, j]
            b.if 2nd picks nums[j], 1st can pick either ends of nums[i + 1, j - 1]
            since 2nd plays to maximize his score, 1st can get nums[i] + min(1.a, 1.b)
						
        2.if 1st picks nums[j], 2nd can pick either ends of nums[i, j - 1]
            a.if 2nd picks nums[i], 1st can pick either ends of nums[i + 1, j - 1];
            b.if 2nd picks nums[j - 1], 1st can pick either ends of nums[i, j - 2];
            since 2nd plays to maximize his score, 1st can get nums[j] + min(2.a, 2.b)
        
        since the 1st plays to maximize his score, 1st can get max(nums[i] + min(1.a, 1.b), nums[j] + min(2.a, 2.b));*/
