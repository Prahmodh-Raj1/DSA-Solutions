//Problem link: https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/
//TC:O(N*(Len of words)*(Len of each word)) SC:O(2*N)
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int m=words.size();
        int len=words.size()*words[0].size();
        //window shoould be of size len
        map<string,int> wordmp;
        for(auto it:words){
            wordmp[it]++;
        }
        vector<int> ans;
        bool fl=true;
        int lenword=words[0].size();
        int n=s.size();
        for(int i=0;i<n-len+1;i++){
            unordered_map<string,int> mp;
            int j=0;
            for(;j<m;j++){
                string tem=s.substr(i+j*lenword,lenword);
                if(wordmp.find(tem)!=wordmp.end()){
                    mp[tem]++;
                    if(mp[tem]>wordmp[tem]){
                        break;
                    }
                }else break;
            }
            if(j==m) ans.push_back(i);
            
        }
        return ans;
    }
};
