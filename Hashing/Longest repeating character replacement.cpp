//Problem link: https://leetcode.com/problems/longest-repeating-character-replacement/
//TC: O(N) SC: O(N)
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mp;
        int n= s.size();
        //we always try to make the other chars equal to the char with the highest frequency in the window, if maxf = m and if (n-m)<=k, then we would call that a valid substring and we could use that for our answer
        int i=0,maxcount=0,maxlen=0;
        for(int j=0;j<n;j++){
            mp[s[j]]++;  //increasing the frequency of the character
            maxcount = max(maxcount,mp[s[j]]);  //maxfrequency in that window
            while(j-i+1 - maxcount > k){  //reducing the window size, so we reduce the character's frequency and slide through the window
                mp[s[i]]--;
                i++;
            }
            maxlen = max(maxlen,j-i+1);  //updating the answer at every iteration
        }
        return maxlen;

    }
};
