//Problem link: https://leetcode.com/problems/maximum-product-subarray/
//TC: O(N) SC: O(2*N)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi[nums.size()];
        int mini[nums.size()];
        maxi[0]=nums[0];
        mini[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            maxi[i]=max(maxi[i-1]*nums[i],max(nums[i],mini[i-1]*nums[i]));
            mini[i]=min(mini[i-1]*nums[i],min(nums[i],maxi[i-1]*nums[i]));
        }
        
        int ans=INT_MIN;
        for(auto it: maxi){
            ans=max(ans,it);
        }
        return ans;
    }
};
