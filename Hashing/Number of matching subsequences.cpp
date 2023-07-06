//Problem link: https://leetcode.com/problems/number-of-matching-subsequences/description/
//TC: O(N*K*LOGk) SC: O(N)
//Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> v(26);
        int n=words.size();
        int nl=s.size();
        int cnt=0;
        for(int i=0;i<nl;i++){
            v[s[i]-'a'].push_back(i);  //storing the occurences of each of the characters in s and their positions
        }
        for(auto it:words){
            int x=-1;
            bool found=true;
            int nl=it.size();
           for(char ch:it){  //applying binary search to check if it's a subsequence or not
               auto i = upper_bound(v[ch-'a'].begin(),v[ch-'a'].end(),x);  //for x=-1, it returns the first positive number
               if(i==v[ch-'a'].end()){
                   found=false;
                   break;
               }else x=*i; //marks the next index, moving to the next index

           }
           if(found) cnt++; 
        }
        return cnt;
    }
};
