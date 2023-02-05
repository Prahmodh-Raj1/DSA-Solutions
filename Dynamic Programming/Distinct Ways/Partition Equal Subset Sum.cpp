//Problem link: https://leetcode.com/problems/partition-equal-subset-sum
//TC:O(N*target) SC:O(N*target)

class Solution {
public:
    bool func(int i,int sum,vector<int>& arr,vector<vector<int>>& dp){
        if(i==arr.size() or sum<=0){
            return (sum==0)? true:false;
        }
        if(dp[i][sum]!=-1) return dp[i][sum];
        bool take=func(i+1,sum-arr[i],arr,dp);
        bool nottake=func(i+1,sum,arr,dp);
        return dp[i][sum] = take | nottake;
    }
    bool canPartition(vector<int>& arr) {
        //we can say that initially, we need to find(n-1, target) which means that we need to find whether there exists a subsequence in the array from index 0 to n-1, whose sum is equal to the targe
        int total = accumulate(arr.begin(),arr.end(),0);
        if(total & 1) return false;
        int reqsum=total/2;
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int>(reqsum+1,-1));
        return func(0,reqsum,arr,dp);
    }
};
