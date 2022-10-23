//Problem link: https://leetcode.com/problems/minimum-cost-to-make-array-equal/
//TC: O(N* log(max(arr)) SC :O(1)
class Solution {
public:
    long long summ(vector<int>& nums,vector<int>& cost, long long mid){
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=1L* abs(nums[i]-mid) * cost[i];
        }
        return ans;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long l=*min_element(nums.begin(),nums.end());
        long long r=*max_element(nums.begin(),nums.end());
        while(l<r){
            long long mid=(l+r)/2;
            long long lsum=summ(nums,cost,mid);
            long long rsum=summ(nums,cost,mid+1);
            if(rsum>lsum) r=mid;
            else l=mid+1;
        }
        return summ(nums,cost,l);
    }
};
