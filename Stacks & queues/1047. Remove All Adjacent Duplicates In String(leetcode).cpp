/*Q.You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

We repeatedly make duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

 

Example 1:

Input: s = "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
*/
string removeDuplicates(string s) {
        /*int i=1;
        while(s.length()!=0 && i<s.length()){
            if(s[i]==s[i-1]){
                s.erase(i-1,2);
                i=1;
            }else{
                i++;
            }
        }
        return s;
        */
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(st.empty() || st.top()!=s[i]){
                st.push(s[i]);
               
            }
            else{
                st.pop();
            }
        }
        string ans="";
        //cout<<s.size();
        while(!st.empty()){
          ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }

