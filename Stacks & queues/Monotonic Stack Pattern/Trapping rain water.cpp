//problem link: https://leetcode.com/problems/trapping-rain-water/
//TC: O(N) SC: O(N)
class Solution {
public:
    int trap(vector<int>& heights) {
        int n=heights.size();
        stack<int> st;
        int ans=0;
        for(int i=0;i<n;i++){
            //we need to keep a tab on both the next greater and the previous greater element
            while(!st.empty() and heights[st.top()]<=heights[i]){
                int top = st.top();
                st.pop();
                if(!st.empty()){
                    // h (height) is the minimum of the previous greater or the next greater elements
                    int h = min(heights[st.top()], heights[i]) - heights[top];
    
                    // w (width) is the space between next greater and previous greater element
                    int w = i - (st.top() + 1);
                    ans+= h*w;
                }
                
            }
            st.push(i);
        }
        return ans;
        
    }
};
