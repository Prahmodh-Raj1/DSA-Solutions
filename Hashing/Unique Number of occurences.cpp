//Problem link: https://leetcode.com/problems/unique-number-of-occurrences/
//TC: O(N) SC: O(N)class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto it:arr) mp[it]++;
        unordered_set<int> st;
        for(auto it:mp){
            if(st.find(it.second)!=st.end()) return false;
            st.insert(it.second);
        }
        return true;
    }
};
