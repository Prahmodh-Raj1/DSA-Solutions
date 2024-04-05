//Problem link: https://leetcode.com/problems/product-of-array-except-self
//TC: O(N) SC:  O(1)
class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n= nums.length;
        int[] ans = new int[n];
        ans[0]= 1;
        for(int i=1;i<n;i++){
            ans[i]= nums[i-1]*ans[i-1];  // calculating prefix sum (i.e from the left)
        }
        int value=1;
        for(int i=n-1;i>=0;i--){
            ans[i]*=value;  //value is the product from all elements from the right encountered so far
            value*=nums[i];
        }
        return ans;
    }
}
