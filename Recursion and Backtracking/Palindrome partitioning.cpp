//prob link: https://leetcode.com/problems/palindrome-partitioning/
class Solution {
private:
    bool isPalindrome(string& s,int low,int high){
        while(low<high){
            if(s[low++]!=s[high--]) return false;
        }
        return true;
    }
    void addPalindromes(string& s,int ind,vector<string>& path,vector<vector<string>>& ans,int n){
        if(ind==n){
            ans.push_back(path);
            return;
        }
        for(int i=ind;i<n;i++){
            if(isPalindrome(s,ind,i)){
                path.push_back(s.substr(ind,i-ind+1));
                addPalindromes(s,i+1,path,ans,n);
                path.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        int n= s.size();
        vector<string> path;
        addPalindromes(s,0,path,ans,n);
        return ans;
    }
};
