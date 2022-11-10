//Problem link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
//TC: O(4^N*N) SC:O(N)
class Solution {
public:
    
    map<int,string> mp;
    void combos(int i,string& temp,string& digits,vector<string>& ans){
        if(i==digits.size()){
            ans.push_back(temp);
            return;
        }
        for(auto it:mp[digits[i]-'0']){
            temp+=it;
            combos(i+1,temp,digits,ans);
            temp.pop_back();
           
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return vector<string>();
        vector<string> ans;
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        string temp;
        combos(0,temp,digits,ans);
        return ans;
    }
};
