
//Problem link: https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
//TC: O(N) SC: O(K)
class Solution{
  public:
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
            if(mp.size()==k) maxlen = max(maxlen,j-i+1);
            
        }
        return maxlen;
    }
};
