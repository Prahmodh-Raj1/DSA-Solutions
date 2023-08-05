//problem link: https://leetcode.com/problems/daily-temperatures
//TC: O(N) SC: O(N)
class Solution {
    public int[] dailyTemperatures(int[] temp) {
        int n = temp.length;
        int wait[] = new int[n];
        Arrays.fill(wait,0);
        Stack<Integer> st = new Stack<>();
        //forming a non-increasing monotonic stack,finding the next greater element
        for(int i=0;i<n;i++){
            while(!st.isEmpty() && temp[st.peek()]<temp[i]){
                wait[st.peek()]=i-st.peek();
                st.pop();
            }
            st.push(i);
        }
        return wait;
    }
}
