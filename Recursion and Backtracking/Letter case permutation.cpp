//Problem link: https://leetcode.com/problems/letter-case-permutation 
//TC: O(2^N) SC: O(Stack space)
class Solution {
private:
    vector<string> ans;
    int n;
    //isalpha(s[i])
    void func(int i,string& s){
        if(i==n){
            ans.push_back(s);
            return;
        }
        char orig  = s[i];  //holding the inital character
        if(islower(s[i])){ //changing the case
            s[i] = toupper(s[i]);
        }else s[i] = tolower(s[i]);
        func(i+1,s);
        //resetting the character if it were an alphabet
        if(isalpha(s[i])){
            s[i]=orig;
            func(i+1,s);
        }
    }
public:
    vector<string> letterCasePermutation(string s) {
        n = s.size();
        func(0,s);
        return ans;
    }
};
