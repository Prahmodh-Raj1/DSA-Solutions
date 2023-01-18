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

//Space optimised soln
class Solution {
public:
    //we divide the array into two subsets such that the difference between the first and the second set is equal to target
    int findTargetSumWays(vector<int>& nums, int targ) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum-targ<0 or (sum-targ)%2) return 0;
        int target=(sum-targ)/2;
        vector<int> prev(target+1,0),cur(target+1,0);
        int n=nums.size();
        if(nums[0]==0){
            prev[0]=2;
        }else{
            prev[0]=1;
        }
        if(nums[0]!=0 and nums[0]<=target) prev[nums[0]]=1;
        for(int i=1;i<n;i++){
            for(int t=0;t<=target;t++){
                int nottake=prev[t];
                int take=0;
                if(nums[i]<=t) take=prev[t-nums[i]];
                cur[t]=take+nottake;
            }
            prev=cur;
        }
        return prev[target];
    
    }
};
