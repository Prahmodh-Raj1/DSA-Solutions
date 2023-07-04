//Problem  link: https://leetcode.com/problems/sort-characters-by-frequency/description/

//TC: O(NlogN) SC: O(2*N)
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(auto it:s) mp[it]++;
        string ans="";
        vector<pair<int,char>> v;
        for(auto it:mp){
            v.push_back({it.second,it.first});
        }
        sort(v.begin(),v.end(),greater<pair<int,int>>());
        
        for(auto it:v){
            int count = it.first;
            char ch = it.second;
            for(int i=0;i<count;i++){
                ans+=ch;
            }
        }
        return ans;
    }

};
//using hashing and bucket sort

//TC: O(N) SC: O(2*N)
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        vector<string> bucket(s.size()+1, "");
        string res;
        
        //count frequency of each character
        for(char c:s) freq[c]++;
        //put character into frequency bucket
        for(auto& it:freq) {
            int n = it.second;
            char c = it.first;
            bucket[n].append(n, c);
        }
        //form descending sorted string
        for(int i=s.size(); i>0; i--) {
            if(!bucket[i].empty())
                res.append(bucket[i]);
        }
        return res;
    }
};
