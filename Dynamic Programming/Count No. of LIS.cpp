//Problem link: https://leetcode.com/problems/number-of-longest-increasing-subsequence/
//TC: O(N^2) SC:O(N)
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return n;
        vector<int> dp(n+1, 1);
        vector<int> cnt(n+1, 1);
        dp[0] = 1;
        int maxLen = 1;
        for(int i = 1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j] < nums[i]){
                    if(dp[j] == dp[i]) { 
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    }else if (dp[j] + 1 == dp[i]){
                        cnt[i] += cnt[j];
                    }                      
                }
            }
            maxLen = max(maxLen, dp[i]);
            
        }
        int ans = 0;
        for(int i = 0; i < n;i++){
            if(dp[i] == maxLen) ans+= cnt[i];
        }
        return ans;
    }
};
