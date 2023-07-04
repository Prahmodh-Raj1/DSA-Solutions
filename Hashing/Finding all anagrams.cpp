//problem link:  https://leetcode.com/problems/find-all-anagrams-in-a-string
//TC: O(N) SC: O(M)
class Solution{
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> mp;  //map to store the frequencies of the characters in p
        for(auto it:p) mp[it]++;
        int i=0,j=0;
        int k = p.size(); //window size;
        int cnt = mp.size(); //count variable to check when all the characters present in the map have frequencies zero,which implies that an anagram is found.
        int n=s.size();
        vector<int> ans;
        while(j<n){
            if(mp.find(s[j])!=mp.end()){ //if a character is found which is present in the map then decrease it's frequency by 1.
                mp[s[j]]--;
                if(mp[s[j]]==0){
                    //if the frequency of a particular character in the map is zero it implies that all the occurences of that particular character is found in the current window size.
                    cnt--;
                }
            }
            if(j-i+1<k){  //window size not yet reached
                j++;
            }else if(j-i+1==k){
                //window size is reached
                if(cnt==0){ //if we've found the anagram
                    ans.push_back(i);  //i stores the starting index of the string

                }
                if(mp.find(s[i])!=mp.end()){
                    ////while sliding the window check if that character is present in the map then increase it's frequency by one as we have decreased the frequency of that character when it was first encountered while traversing the window.
                    mp[s[i]]++;
                    if(mp[s[i]]==1){
                        cnt++; //we need that character for the anagram chk now
                    }
                }
                i++;  //moving the window
                j++;  //moving the window
            }
            
        }
        return ans;
    }
};
