//Problem link: https://leetcode.com/problems/largest-divisible-subset/
//TC:O(N^2) SC:O(N)

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size()==1){
            vector<int> v(1,nums[0]);
            return v;
        }
        int n=nums.size();
        vector<int> dp(n+1,1);
        sort(nums.begin(),nums.end());
        vector<int> ans;
       // int n=nums.size();
        int maxi=1;
        for(int i=1;i<n;i++){
            
            for(int j=i-1;j>=0;j--){
                if(nums[i]%nums[j]==0){
                    int curmax=dp[j]+1;
                    if(curmax>dp[i]) dp[i]=curmax;
                }
            }
            maxi=max(dp[i],maxi);
        }
        int prev=0;
        for(int i=n-1;i>=0;i--){
            if((dp[i] == maxi) &&(prev%nums[i]==0)){  
                ans.push_back(nums[i]);
                maxi--;
                prev = ans.back();
            }
        }
        return ans;
    }
};
