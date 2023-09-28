//Prob link: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/  && https://leetcode.com/problems/remove-duplicate-letters
//TC: O(N) SC: O(26)
class Solution {
public:
    string smallestSubsequence(string s) {
        string ans="";
        vector<int> lastpos(26,0);
        vector<int> seen(26,0);
        int n = s.size();
        for(int i=0;i<n;i++) lastpos[s[i]-'a']=i;
        for(int i=0;i<n;i++){
            if(seen[s[i]-'a']++ > 0) continue;
            while(!ans.empty() && ans.back()>s[i] && i < lastpos[ans.back()-'a']){
                seen[ans.back()-'a'] = 0;
                ans.pop_back();
            }
            ans.push_back(s[i]);
        }
        return ans;
    }
};
/*
Find the index of last occurrence for each character.
Use a stack to keep the characters for result.
Loop on each character in the input string S,
if the current character is smaller than the last character in the stack,
and the last character exists in the following stream,
we can pop the last character to get a smaller result*/
