//Prob link: https://leetcode.com/problems/minimum-size-subarray-in-infinite-array/
//TC: O(N) Sc: O(N)
class Solution {
    public int minSizeSubarray(int[] nums, int target) {
        int sum = 0;
        for (int num : nums) sum += num;

        int mul = target / sum;
        target = target % sum;

        int[] repArr = new int[nums.length * 2];
        for (int i = 0; i < nums.length; i++) {
            repArr[i] = nums[i];
            repArr[nums.length + i] = nums[i];
        }
        int ans = Integer.MAX_VALUE;
        sum = 0;
        for (int start = 0, end = 0; end < repArr.length; end++) {
            sum += repArr[end];
            while (sum > target) {
                sum -= repArr[start++];
            }
            if (sum == target) ans = Math.min(ans, end - start + 1);
        }
        return ans == Integer.MAX_VALUE ? -1 : ans + (mul * nums.length);
    }
}
