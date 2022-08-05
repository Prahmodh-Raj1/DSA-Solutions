//Problem link: https://leetcode.com/problems/combination-sum-iv/
//TC: O(target*N)  sc: O(target)
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target){
        unsigned int dp[target+1];
        dp[0]=1;
        for(int i=1;i<=target;i++) dp[i]=0;
        for(int i=1;i<=target;i++){
            for(int j=0;j<nums.size();j++){
                if(i>=nums[j]){
                    dp[i]+=dp[i-nums[j]];
                }
            }
            
        }
        return dp[target];
    }
};
