//Problem link: https://leetcode.com/problems/construct-k-palindrome-strings
//TC: O(N) SC: O(26)
class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        if(n==k) return true;
        if(k>n) return false;
        unordered_map<char,int> freq;
        for(auto it:s) freq[it]++;
        int cntodd=0;  //counting the elements with odd frequency 
        for(auto it:freq){
            if(it.second & 1) cntodd++;
        }
        if(cntodd>k) return false;   //if the odd count is greater than k, we can only construct >k valid palindromes only
        return true;
    }
};
