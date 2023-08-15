//Prob link: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
//TC: O(N) SC: O(N)
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        int n= s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push(i); //for opening parentheses
            else if(s[i]==')'){
                if(st.empty()){
                    s[i]='#'; //we can't find a corresponding opening bracket, so mark that index as # (invalid - not to be included in answer)
                }
                else st.pop(); //we've found a corresponding opening 
            }
        }
        while(!st.empty()){
            //means there's an imbalance in opening and closing brackets
            s[st.top()]='#';
            st.pop();
        }
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]!='#') ans+=s[i];
        }
        return  ans;

    }
};

//TC : O(N) SC: O(1)
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        int n= s.size();
        int cnt=0; //stores the number of  opening brackets
        for(int i=0;i<n;i++){
            if(s[i]=='(') cnt++; //for opening paranthesis
            else if(s[i]==')'){
                if(cnt==0){ 
                    s[i]='#'; //we can't find a corresponing opening bracket, so mark that index as # (invalid - not to be included in answer)
                }
                else cnt--; //we've found a corresponding opening 
            }
        }
        cnt=0; //stores the number of closing brackets now and chk from the back to the end 
        for(int i=n-1;i>=0;i--){
            if(s[i]==')') cnt++;
            else if(s[i]=='('){
                if(cnt==0) s[i]='#'; //if there's no closing bracket found
                else cnt--; //else reduce
            }
        }

        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]!='#') ans+=s[i];
        }
        return  ans;

    }
};
