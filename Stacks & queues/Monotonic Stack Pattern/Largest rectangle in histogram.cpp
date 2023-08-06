//problem link: https://leetcode.com/problems/largest-rectangle-in-histogram
//TC: O(N) SC: O(N)
//https://takeuforward.org/data-structure/area-of-largest-rectangle-in-histogram/
Area: arr[i] * (right smaller – left smaller -1 ).
  class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxarea=0;
        int n=heights.size();
        //we use the idea of a previous smaller element 
        for(int i=0;i<=n;i++){ //we do i<=n to ensure the case of continuously increasing array
            while(!st.empty() and (i==n || heights[st.top()]>=heights[i])){
                int length=heights[st.top()];
                st.pop();
                int breadth;
                if(st.empty()) breadth=i;
                else breadth=i-st.top()-1;
                maxarea=max(length*breadth,maxarea);
            }
            st.push(i);
        }
        return  maxarea;
    }
};
