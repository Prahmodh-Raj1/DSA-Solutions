//Problem link:https://leetcode.com/problems/maximum-subarray-min-product/description/
//TC:O(3*N) SC:O(N)

class Solution {
    long[] preSum;
    public int maxSumMinProduct(int[] nums) {
        int n = nums.length;
        int[] left_bound = new int[n], right_bound = new int[n];
        Stack<Integer> st = new Stack<>();
        for (int i = 0; i < n; ++i) {
            while (!st.isEmpty() && nums[st.peek()] >= nums[i]) st.pop();
            if (!st.isEmpty())
                left_bound[i] = st.peek() + 1;
            else
                left_bound[i] = 0;
            st.add(i);
        }
        //we consider each element as the minimum and then find the corresponding sum
        //stacks: find the next smaller element in the left and the next smaller element on the right
        //Eg: [2,3,3,1,2]
        //next smaller element to the right(Stores index)=[3,3,3,5,5] //outof bounds case is mentioned as size of the array
        //next smaller element to the left(Stores index, -1 if none exists) = [-1,0,0,-1,3]
        //sum of the window can be found and computed value (pref[right]-pref[left]+1)*nums[i]
        st = new Stack<>();
        for (int i = n - 1; i >= 0; --i) {
            while (!st.isEmpty() && nums[st.peek()] >= nums[i]) st.pop();
            if (!st.isEmpty())
                right_bound[i] = st.peek() - 1;
            else
                right_bound[i] = n - 1;
            st.add(i);
        }
        preSum = new long[n+1];
        for (int i = 0; i < n; ++i) preSum[i + 1] = preSum[i] + nums[i];
        long maxProduct = 0;
        for (int i = 0; i < n; ++i)
            maxProduct = Math.max(maxProduct, getSum(left_bound[i], right_bound[i]) * nums[i]);
        return (int) (maxProduct % 1000_000_007);
    }
    long getSum(int left, int right) { // left, right inclusive
        return preSum[right + 1] - preSum[left];
    }
}
