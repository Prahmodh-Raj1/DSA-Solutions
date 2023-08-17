//prob link: https://leetcode.com/problems/max-consecutive-ones-iii
//TC: O(N) SC: O(1)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeroes=0;
        int n=nums.size();
        int i=0,j=0;
        int ans=0;
        for(j=0;j<n;j++){
            if(nums[j]==0) zeroes++;
            while(i<=j && zeroes>k){
                if(nums[i]==0) zeroes--;
                i++;
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};
