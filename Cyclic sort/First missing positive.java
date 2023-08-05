//Problem link: https://leetcode.com/problems/first-missing-positive
class Solution {
    public int firstMissingPositive(int[] nums) {
        int i = 0;
        while (i < nums.length) {
            //apply cyclic sort only on positive integers
            int correctIdx = nums[i] - 1;
            if (nums[i]>0 && nums[i]<nums.length && nums[i] != nums[correctIdx]) {
                int temp = nums[i];
                nums[i] = nums[correctIdx];
                nums[correctIdx] = temp;
            } else {
				i++;
			}
        }

        for (i = 0; i < nums.length; i++) {
            if (nums[i] != i + 1) {
                return i+1;
            }
        }
        return nums.length+1;  //finally if all are positive integers in the array, then we can returnn size of array + 1
    }
}
