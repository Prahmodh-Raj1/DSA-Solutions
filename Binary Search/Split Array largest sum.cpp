//Problem link: https://leetcode.com/problems/split-array-largest-sum/
//TC: O(NLOG(SUM)) SC: O(1)
class Solution {
public:
    bool feasible(vector<int>& nums,int mid,int k){
        int cnt=1;
        int sum=0;
        for(auto it:nums){
            sum+=it;
            if(sum>mid){
                cnt++;
                sum=it;
            }
        }
        return cnt<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        if(k==1) return accumulate(nums.begin(),nums.end(),0);
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        while(low<high){
            int mid=(low+high)/2;
            if(feasible(nums,mid,k)){
                high=mid;
            }else low=mid+1;
        }
        return low;
    }
};
