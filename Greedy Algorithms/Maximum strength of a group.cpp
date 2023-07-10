//problem link: https://leetcode.com/problems/maximum-strength-of-a-group/
//TC: O(NlogN) sc: o(1)
class Solution {
public:
    
    long long maxStrength(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        long long ans=1;
        bool fl=false;
        for(int i=0;i<n;i++){
            //we take all the positive scores along with the even no. of negative scores
            //we skip the odd negative score with smallest absolute value - done in (i+1<n and nums[i+1]<0)
            if(ans*nums[i]>0 or (i+1<n and nums[i+1]<0)){
                ans*=nums[i];
                fl=true;
            }
        }
        if(fl) return ans;
        return nums[n-1]; //returning the maximum element
    }
};
