//Problem link:https://leetcode.com/problems/minimum-size-subarray-sum/description/
//TC: O(NlogN) SC: O(1)
class Solution {
public:
    bool check(long long mid,vector<int>& nums,int target){
        int i=0,j=0;  //declaring a slow and fast pointer, using sliding window approach
        int sum=0;
        int maxi=0;
        while(j<nums.size()){
            sum+=nums[j];
            if(j-i+1==(int)mid){
                maxi=max(maxi,sum);  //finding the maximum sum possible until the size
                sum-=nums[i];
                i++;
            }
            j++;
        }
        if(maxi>=target) return true;  //if we find a sum>=target with the given subarray size
        return false;
    }
    int minSubArrayLen(int target, vector<int>& nums) {
        long long low= 0;
        bool flag=false;
        long long high=(long long)nums.size()+1;
        while(low<high){
            long long mid = (low+high)/2;
            if(check(mid,nums,target)){
                flag=true;
                high=mid;
            }else low=mid+1;
        }
        return (flag==true ? (int)low: 0 );
    }
};
