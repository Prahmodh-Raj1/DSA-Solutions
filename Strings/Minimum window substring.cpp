//Prob link: https://leetcode.com/problems/minimum-window-substring
//TC: O(N) SC: O(N)
class Solution {
public:
    string minWindow(string s, string t) {
        int ans=0;
        unordered_map<char,int> mp,freq;
        int startindex=0,numchars=0;;
        int start=0,end=0;
        int len = s.size();
        for(char c:t) mp[c]++;
        int minlength=INT_MAX;
        int counter=t.size();
        while(end<len){
            if(mp[s[end]]>0) counter--; //character present in t
            mp[s[end]]--;
            end++;
            while(counter==0){ //valid case, we need to move the start pointer such that the window becomes invalid
                if((end-start)<minlength){
                    minlength = end-start;
                    startindex=start;
                    numchars=end-start;
                }
                if(mp[s[start++]]++ ==0) counter++;
                
            }
            
        }
        if(minlength==INT_MAX) return "";
        return s.substr(startindex,numchars);
    }
};
