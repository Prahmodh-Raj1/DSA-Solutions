//Problem link: https://leetcode.com/problems/number-of-visible-people-in-a-queue
//TC: O(N) SC: O(N)
class Solution {
    public int[] canSeePersonsCount(int[] heights) {
        int n = heights.length;
        Stack<Integer> st = new Stack<>();
        int ans[] = new int[n];
        Arrays.fill(ans,0);
        //we use a monotonic stack that stores heights in decreasing order
        //same template as next greater element
        for(int i=0;i<n;i++){
            while(!st.isEmpty() && heights[st.peek()]<heights[i]){  
                ans[st.peek()]++;//when we reach the next larger element, we add 1 and pop from stack
                st.pop();
            }
            if(!st.isEmpty()){ 
                ans[st.peek()]++;  //the larger eleemnt is still on top so it can see all the current elements
            }
            st.push(i);
        }
        return ans;
    }
}
