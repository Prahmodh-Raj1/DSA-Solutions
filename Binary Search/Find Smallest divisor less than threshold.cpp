//Problem link:https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
//TC: O(Nlog(max)) Sc: o(1)
class Solution {
public:
    bool check(vector<int>& nums,int mid,int threshold){
        int sum=0;
        for(auto it:nums){
            sum+=(it+mid-1)/mid;
        }
        return sum<=threshold;  //checking if the current sum to be less than the given threshold
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        sort(nums.begin(),nums.end());
        int low=1;
        int high= nums[nums.size()-1];
        while(low<high){
            int mid = (low+high)/2;
            if(check(nums,mid,threshold)){
                //if the sum is less than threshold, we look for values less than the current value since we've been asked for the minimal value
                high=mid;
            }else low = mid+1;
        }
        return low;
    }
};
