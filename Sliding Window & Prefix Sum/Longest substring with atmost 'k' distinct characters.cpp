//Prob link: https://www.codingninjas.com/studio/problems/longest-substring-with-at-most-two-distinct-characters_3125863?leftPanelTab=1
//TC: O(N) SC: O(K)
#include<bits/stdc++.h>
int longestKSubstr(string s, int k) {
    // your code here
        int n=s.size();
        int i=0,j=0;
        unordered_map<char,int> mp;
        int maxlen=-1;
        for(j=0;j<n;j++){
            mp[s[j]]++;
            while(mp.size()>k){
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;
            }
            if(mp.size()<=k) maxlen = max(maxlen,j-i+1);
            
        }
        return maxlen;
    }

int lengthOfLongestSubstring(string s) {
    // Write your code here.
    return longestKSubstr(s,2);
}

