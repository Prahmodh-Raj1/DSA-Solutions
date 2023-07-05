//Problem link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
//TC: O(N) SC: O(N)
//Description and example: Given a string s, find the length of the longest 
substring
 without repeating characters.
Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>  mp;
        int maxlength=0;
        int l=0,r=0;
        int n=s.size();
        int i=0,j=0;
        int ans=0;
        while(j<n){
            if(mp.find(s[j])!=mp.end()){
                ans=max(ans,j-i);
                i=max(i,mp[s[j]]+1);  //keeping the window at the current i, or at the updated occurence index
               
            }
            mp[s[j]]=j;  //last time it was found
            j++;
        }
        return max(ans,j-i);
       
    }
};
