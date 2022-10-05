//Problem link: https://leetcode.com/problems/target-sum/
//Recursive Solution, TC: O(2^N) SC:O(1)
class Solution {
public:
    int total(vector<int>& nums,int cursum,int i,int target){
        if(i<0 and cursum==target){
            return 1;
        }
        if(i<0){
            return 0;
        }
        int add=total(nums,cursum+nums[i],i-1,target);
        int sub=total(nums,cursum-nums[i],i-1,target);
        return add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return total(nums,0,nums.size()-1,target);
    }
};
//DP Solution, Memoization done with the help of a map 
class Solution {
public:
    map<pair<int,int>,int> dp;
    int total(vector<int>& nums,int cursum,int i,int target){
        if(dp.find({i,cursum})!=dp.end()){
            return dp[{i,cursum}];
        }
        if(i<0 and cursum==target){
            return 1;
        }
        if(i<0){
            return 0;
        }
        
        return dp[{i,cursum}]=total(nums,cursum+nums[i],i-1,target)+total(nums,cursum-nums[i],i-1,target);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return total(nums,0,nums.size()-1,target);
    }
};