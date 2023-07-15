//Problem link: https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/
//TC: O(N) SC: O(N)
class Solution {
public:
    bool isValid(string s) {
        vector<char> st;
       // We can use a stack to build the string, removing "abc" as we go. 
        for(auto it:s){
            if(it=='c' and st.size()>1 and st.back()=='b' and st[st.size()-2]=='a'){
                
                st.resize(st.size()-2);
                
            }else st.push_back(it);
                
            
        }
        return st.empty();
    }
};
