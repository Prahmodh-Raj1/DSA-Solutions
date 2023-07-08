//Prob link: https://leetcode.com/problems/backspace-string-compare/
//TC: O(N) SC: O(N)
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1;
        stack<char> st2;
        for(auto it:s){
            if(it!='#'){
                st1.push(it);
            }else{
                if(!st1.empty()){
                    st1.pop();
                }
                
            }
        }
        for(auto it:t){
            if(it!='#'){
                st2.push(it);
            }else{
                if(!st2.empty()){
                    st2.pop();
                }
                
            }
        }
        while(!st1.empty() and !st2.empty()){
            if(st1.top()!=st2.top()){
                return false;
            }
            st1.pop();
            st2.pop();
        }
        if(!st1.empty() or !st2.empty()) return false;
        return true;
    }
};

//Without stack SC: O(1)
string build(string s){
        int c=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='#') c=max(0,--c);
            else s[c++]=s[i];
        }
        return s.substr(0,c);
    }
    bool backspaceCompare(string s, string t) {
        return build(s)==build(t);
    }
