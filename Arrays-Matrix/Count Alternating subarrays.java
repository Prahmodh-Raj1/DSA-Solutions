//Problem link: https://leetcode.com/problems/count-alternating-subarrays/
//TC: O(N) SC: O(1)
class Solution {
    public long countAlternatingSubarrays(int[] nums) {
        int n= nums.length;
        if(n==1) return 1;
        long ans=0,range=0;
        int i,j;
        for(i=0,j=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                range = (i-j+1);
                ans+=(long)(range*((long)range+1)/2);
                j=i+1;
            }
        }
        range = (i-j+1); //for the final range when I is at the last index
        ans+=(long)(range*((long)range+1)/2);
        return ans;
    }
    
}
