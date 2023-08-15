//Problem link: https://leetcode.com/problems/generate-parentheses/
class Solution {
private:
    void findParantheses(string& cur,int open,int closed,int n,vector<string>& ans){
        if(cur.size()==2*n){
            ans.push_back(cur);
            return;
        }
        if(open<n){
            //we can add an open bracket
            cur+="(";
            findParantheses(cur,open+1,closed,n,ans);
            cur.pop_back();

        }
        if(closed<open){
          //we can add an open bracket
            cur+=")";
            findParantheses(cur,open,closed+1,n,ans);
            cur.pop_back();
        }
        
        
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur = "";
        cur+='(';
        findParantheses(cur,1,0,n,ans);
        return ans;
    }
};
