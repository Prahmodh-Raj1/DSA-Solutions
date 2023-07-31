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

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        //find the longest divisibe subsequence
        vector<int> dp(n,1),hash(n);
        int last=0;
        int maxi=-1;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                if(nums[i]%nums[prev]==0 and 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
            
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                last=i;
            }
        }
        vector<int> temp;
        temp.push_back(nums[last]);
        while(hash[last]!=last){
            last=hash[last];
            temp.push_back(nums[last]);
        }
        return temp;
    }
