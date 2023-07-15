//Problem link: https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/
//TC: O(nlogn) sc: O(1)
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        int maxi=0;
        while(i<j){
            maxi=max(maxi,nums[i]+nums[j]);
            i++;
            j--;
        }
        return maxi;
    }
};
