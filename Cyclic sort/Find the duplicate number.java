//Problem link: https://leetcode.com/problems/find-the-duplicate-number
class Solution {
    public int findDuplicate(int[] nums) {
        int i=0;
        int n = nums.length;
        while(i<n){
            int correctindex = nums[i]-1;
            if(nums[correctindex]!=nums[i]){
                int temp = nums[i];
                nums[i]=nums[correctindex];
                nums[correctindex] = temp;
            }else i++;
        }
        for(i=0;i<n;i++){
            if(nums[i]!=i+1) return nums[i];
        }
        return 0;
    }
}
