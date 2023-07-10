//Problem link: https://leetcode.com/problems/extra-characters-in-a-string/
//TC: O(N^2) SC:O(N)
class Solution {
private:
    unordered_map<string,int> mp;
    int func(string& s,vector<string>& dictionary,int ind,vector<int>& dp){
        if(ind>=s.size()) return 0;
        if(dp[ind]!=-1) return dp[ind];
        string cur="";
        int minextra = s.size();
        for(int ctind=ind;ctind<s.size();ctind++){
            cur+=s[ctind];
            int currentExtra=0;
            int nextExtra=0;
            if(mp.find(cur)!=mp.end()){
                currentExtra = 0;
            }else{
                currentExtra = cur.size();
            }
            nextExtra = func(s,dictionary,ctind+1,dp);
            minextra = min(minextra,currentExtra+nextExtra);
        }
        return dp[ind]=minextra;
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        
        for(auto it:dictionary){
            mp[it]++;
        }
        int n=s.size();
        vector<int> dprec(n,-1);  //dp[i] indicates the minimum no. of characters skipped by applying optimal partition from [i...n-1]
        vector<int> dpit(n+1,0);
        //In iterative DP, we move from n-1 to 0
        
        for(int i=n-1;i>=0;i--){
            string cur="";
            int minextra = s.size();
            for(int ctind=i;ctind<s.size();ctind++){
                cur+=s[ctind];
                int currentExtra=0;
                int nextExtra=0;
                if(mp.find(cur)!=mp.end()){
                    currentExtra = 0;
                }else{
                    currentExtra = cur.size();
                }
                nextExtra = dpit[ctind+1];
                minextra = min(minextra,currentExtra+nextExtra);
            }
            dpit[i]=minextra;
        }
        return dpit[0];
       // return func(s,dictionary,0,dp); - Recursive DP
        
    }
};
/*DRY RUN:
leetscode, dictionary = ["leet","code","leetcode"]

[l + eetscode]
#Make a cut “l” and fix the string
#Then get the extra character count for “eetscode” (recursion)
#Now “l” is not in dictionary so
totalExtra = sizeof(“l”) + nextExtra(got via recursion)
//====================================================
[le + etscode]
#Make a cut “le” and fix the string
#Then get the extra character count for “etscode” (recursion)
#Noe “le” is not in dictionary
totalExtra = sizeof(“le”) + nextExtra(got via recursion)
//====================================================
[lee + tscode]
#Similarly for “lee”
//================================================================
[leet + scode]
#Make a cut “leet” and fix the string
#Then get the extra character count for “scode” (recursion)
#Now “leet” is in dictionary :) [A relief]
totalExtra = 0 + nextExtra(got via recursion)
//==================================================================
#Similarly other calls are made*/
