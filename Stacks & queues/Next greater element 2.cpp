//problem link: https://leetcode.com/problems/next-greater-element-ii/
//TC: O(N) SC: O(N)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n =nums.size();
        vector<int> res(n,-1);
        for(int i=2*n -1;i>=0;i--){
            while(!st.empty() and st.top()<=nums[i%n]){
                st.pop();
            }
            if(!st.empty()){
                res[i%n]=st.top();
            }else res[i%n]=-1;
            st.push(nums[i%n]);
        }
        return res;
    }
};
