//Prob link: https://leetcode.com/problems/largest-number
//TC: O(nlogN) sc: o(n)
class Solution {
private:
    static bool comp(string a,string b){
        return a+b > b+a;
        //in  normal sorting of strings, 6>55 and 54>5, so in the case of [54,5] we would choose 545 instrad of 554
    }
public:
    string largestNumber(vector<int>& nums) {
        vector<string> characters;
        for(int i:nums){
            characters.push_back(to_string(i));
        }
        string ans="";
        sort(characters.begin(),characters.end(),comp);
        for(string ch: characters){
            ans+=ch;
        }
        if(ans[0]=='0') return "0";
        return ans;
    }
};
