//Problem link: https://leetcode.com/problems/sort-colors/
//TC: O(2*N) SC: O(1)
//TC: O(N) SC: O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        /*counting sort
        int n=nums.size();
        int cnt0=0,cnt1=0,cnt2=0;
        for(auto it:nums){
            if(it==0) cnt0++;
            else if(it==1) cnt1++;
            else cnt2++;
        }
        int i=0;
        for(;i<cnt0;i++) nums[i]=0;
        for(;i<cnt0+cnt1;i++) nums[i]=1;
        for(;i<cnt0+cnt1+cnt2;i++) nums[i]=2;
        return;*/

        //using Dutch National flag algorithm
        //nums[0...l-1] contains 0, nums[r+1...n] contains 2
        int l=0,mid=0,r=nums.size()-1;
        while(mid<=r){
            if(nums[mid]==0){
                swap(nums[mid],nums[l]);
                l++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }else{
                swap(nums[mid],nums[r]);
                r--;
            }
        }
        return;
    }
};
