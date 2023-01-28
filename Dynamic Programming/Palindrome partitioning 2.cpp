//Problem link: https://leetcode.com/problems/palindrome-partitioning-ii/

class Solution {
public:
    //TC:O(N^2) SC:O(N)
    bool ispalindrome(int i,int j,string& s){
        while(i<j){
            if(s[j]!=s[i]) return false;
            i++;
            j--;
        }
        return true;
    }
    int func(int i,string& s,vector<int>& dp){
        if(i>=s.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        
        int mini=1e9;
        for(int j=i;j<s.size();j++){
            
            if(ispalindrome(i,j,s)){
                int cost=1+func(j+1,s,dp);
                mini=min(cost,mini);
            }
        }
        return dp[i]=mini;
    }
    int minCut(string s) {
        int n=s.size();
        if(n==1){
            return 0;
        }
        vector<int> dp(n+1,0);
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
            int mini=1e9;
            for(int j=i;j<s.size();j++){
            
                if(ispalindrome(i,j,s)){
                    int cost=1+dp[j+1];
                    mini=min(cost,mini);
                }
            }
            dp[i]=mini;
        }
        return dp[0]-1;  //subtracting one from the computed value, since we are also considering thr partioning at the end of the string, which is to be avoided while returning  the answer
        //return func(0,s,dp)-1;
    }
};
