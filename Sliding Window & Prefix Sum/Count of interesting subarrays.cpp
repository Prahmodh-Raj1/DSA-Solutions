//Prob link: https://leetcode.com/problems/count-of-interesting-subarrays
//TC: O(N) SC: O(N)
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        //we make the elements which satisfy nums[i]%modulo == k as 1, and the rest as zero
        //now instead of focusing on the count of special elements in subarray
        //we can focus on the sum of elements in subarray
    //as count is same as sum now..

    //we have to find those subarrays whose sum % mod == k

        long long ans=0;
        int len = nums.size();
        for(int i=0;i<len;i++){
            if(nums[i]%modulo==k){
                nums[i]=1;
            }else nums[i]=0;
        }
        unordered_map<int,int> mp;
        mp[0]=0;
        int sum=0;
        for(int i=0;i<len;i++){
            sum+=nums[i];
            int modval = sum%modulo;
            if(modval==k) ans++;
            int findremain = modval - k;
            if(findremain<0){
                findremain+=modulo;
            }
            ans+=mp[findremain];
            mp[modval]++;
        }
        return ans;
    }
};
