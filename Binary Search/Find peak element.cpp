//Problem link: https://leetcode.com/problems/find-peak-element/
//TC:O(LOGN) SC:O(1)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        int mid;
        while(l<r){
            mid= l + (r-l)/2;
            if(nums[mid]>nums[mid+1]){
                r=mid;
            }else if(nums[mid]<=nums[mid+1]){
                l=mid+1;
            }
        }
        return l;
    }
};
