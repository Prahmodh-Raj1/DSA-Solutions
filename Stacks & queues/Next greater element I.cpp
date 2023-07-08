//Problem link:https://leetcode.com/problems/next-greater-element-i/ 
//TC: O(NlogN) SC:O(N)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        int m=nums2.size();
        map<int,int> store;
        for(int i=m-1;i>=0;i--){
            while(!st.empty() and st.top()<=nums2[i]){
                st.pop();
            }
            if(!st.empty()){
                store[nums2[i]]=st.top();
            }else store[nums2[i]]=-1;
            st.push(nums2[i]);
        }
        
        int n=nums1.size();
        vector<int> res(n);
        for(int i=0;i<n;i++){
            res[i]=store[nums1[i]];
        }
        return res;

    }
};
