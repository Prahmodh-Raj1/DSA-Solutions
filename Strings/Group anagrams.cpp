//prob link: https://leetcode.com/problems/group-anagrams/
//TC: O(N*(maxlen(str[i]*log(maxlen(str[i])) SC: O(N)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> freq;
         /*
                Consider example 1 : strs = ["eat","tea","tan","ate","nat","bat"]
                
                After the below opeartion of for loop map will contain
                
                aet -- eat, tea, ate
                ant -- tan, nat
                abt -- bat
        */
        for(auto it:strs){
            string s = it;
            sort(it.begin(),it.end());
            freq[it].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto it:freq){
            ans.push_back(it.second);
        }
        return ans;
    }
};
