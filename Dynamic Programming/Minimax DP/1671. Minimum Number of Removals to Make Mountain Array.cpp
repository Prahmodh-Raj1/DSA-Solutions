//Problem link: https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/
//TC :O(N^2) SC:O(N)

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n =nums.size();
        vector<int> lis(n+1,1);
        vector<int> minrem(n+1,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    lis[i]=max(lis[j]+1,lis[i]);
                }
                if(nums[j]>nums[i]){
                    if(minrem[j]>1) minrem[i]=max(minrem[j]+1,minrem[i]);
                    if(lis[j]>1) minrem[i]=max(lis[j]+1,minrem[i]);
                }
            }
        }
        int maxi=*max_element(minrem.begin(),minrem.end());
        return n-maxi;
    }
};
