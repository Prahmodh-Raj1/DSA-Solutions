//Problem link:https://leetcode.com/problems/maximum-energy-boost-from-two-drinks/
//TC: O(N) SC: O(N) / O(1)

class Solution {
private:
    long long findmax(int index,vector<int>& ea,vector<int>& eb,int flag,vector<vector<long long>>& dp){
        if(index>=ea.size()) return (long long)0;
        if(dp[index][flag]!=-1) return dp[index][flag];
        long long ans=0;
        if(flag){
            ans = max(eb[index]+findmax(index+1,ea,eb,flag,dp),findmax(index+1,ea,eb,!flag,dp));
        }
        //max of picking and continuing with same thing, or not picking anything and shifting to next array
        else{
            ans = max(ea[index]+findmax(index+1,ea,eb,flag,dp),findmax(index+1,ea,eb,!flag,dp));
        }
        
        return dp[index][flag] = ans;
    }
public:
    long long maxEnergyBoost(vector<int>& ea, vector<int>& eb) {
        int n = ea.size();
        //Recursive DP
        //vector<vector<long long>> dp(n,vector<long long>(2,-1));

        //space optimized solution
        vector<long long> cur(2,0),nex(2,0);
        for(int i=n-1;i>=0;i--){
            cur[0] = max(eb[i]+nex[0],nex[1]);
            cur[1]= max(ea[i]+nex[1],nex[0]);
            nex=cur;
        }
        return max(nex[0],nex[1]);
        //return max((long long)findmax(0,ea,eb,0,dp),(long long)findmax(0,ea,eb,1,dp));
    }
};
