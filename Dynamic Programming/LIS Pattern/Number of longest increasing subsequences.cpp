//Problem link: https://leetcode.com/problems/number-of-longest-increasing-subsequence/
//TC: O(N^2) SC: O(N)
//Explanation: https://takeuforward.org/data-structure/number-of-longest-increasing-subsequences-dp-47/
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
       vector<int> dp(n,1),cnt(n,1);
       int maxi=-1;
       int maxind=0;
       //cnt[i] indicates the count of the LIS at original array that are possible of length dp[i]
       //with the element arr[i] as it's last element
       for(int i=0;i<n;i++){
           
           for(int j=0;j<i;j++){
               if(nums[i]>nums[j] and dp[i]<1+dp[j]){

                  cnt[i]=cnt[j];
                   dp[i]=1+dp[j];
                   
               }
               else if(nums[i]>nums[j] and dp[j]+1==dp[i]){
                       cnt[i]+=cnt[j];  //value of count will increase we get similar dp values
                }
           }
           
           
           if(dp[i]>maxi){
               maxi=dp[i];
               maxind=i;
           }
       }
       int ans=0;
       for(int i=0;i<n;i++){
           if(dp[i]==maxi) ans+=cnt[i];
       }
       return ans;
     
    }
};
