//Problem link: https://leetcode.com/problems/next-greater-element-ii
//TC: O(N) SC: O(N)
class Solution {
    public int[] nextGreaterElements(int[] nums) {
        int n = nums.length;
        Stack<Integer> st = new Stack<>();
        int nextgreater[] = new int[n];
        Arrays.fill(nextgreater,-1);
        //since it's a circular array, we run the parent for loop twice, since the array wraps around itself and Which means, the next greater element for the last element in the array could be the first of the previous elements if it is bigger
        for(int j=0;j<2;j++){
            for(int i=0;i<n;i++){
                while(!st.isEmpty() && nums[st.peek()]<nums[i]){
                    nextgreater[st.peek()] = nums[i];
                    st.pop();
                }
                st.push(i);
            }
        }
        return nextgreater;
    }
}
