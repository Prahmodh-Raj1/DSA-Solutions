//Problem link: https://leetcode.com/problems/find-minimum-cost-to-remove-array-elements/
//TC: O(N^2) SC: O(N^2)

class Solution {
private:
    int dp[1001][1001];
    
    int helper(int prev,int ind,vector<int>& nums){
        //prev - index of element that's still available after prev operation
        //ind = index that we're currently considering removing elements
        if(ind==nums.size()){
            return nums[prev]; //only 1 element left
        }
        if(ind==nums.size()-1){
            //2 elements left
            return max(nums[prev],nums[ind]);
        }

        if(dp[prev][ind]!=-1) return dp[prev][ind];

        //Explore 3 different choices
        int choice1 = max(nums[ind],nums[ind+1]) + helper(prev,ind+2,nums);
        int choice2 = max(nums[prev],nums[ind+1]) + helper(ind,ind+2,nums);
        int choice3 = max(nums[prev],nums[ind]) +helper(ind+1,ind+2,nums);

        return dp[prev][ind] = min(choice1,min(choice2,choice3));
    }
public:

    int minCost(vector<int>& nums) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        return helper(0,1,nums);

    }
};
