//Problem link:https://leetcode.com/problems/find-number-of-ways-to-reach-the-k-th-stair/
//TC: O(50*50*2)
class Solution {
private:
    long long findways(int pos,int goback,int jumps,int backs,vector<long long>& exp,int k,vector<vector<vector<long long>>>& dp){
        if(pos>k+1) return 0; //no way to return to k after pos exceeds k+1
        
        if(dp[jumps][backs][goback]!=-1) return dp[jumps][backs][goback];

        long long ans=0;

        if(pos==k) ans++;  //dont end recursion as it's still possible to reach k after this
        if(goback==1){
            ans+=findways(pos-1,0,jumps,backs+1,exp,k,dp);
            ans+=findways(pos+exp[jumps],1,jumps+1,backs,exp,k,dp);
        }
        if(goback==0){
            ans+=findways(pos+exp[jumps],1,jumps+1,backs,exp,k,dp);
        }
        return dp[jumps][backs][goback]=ans;
        
    }
public:
    int waysToReachStair(int k) {
        vector<vector<vector<long long>>> dp(51,vector<vector<long long>>(51,vector<long long>(2,-1)));
        vector<long long> exp(33,0); //precomputing powers of 2
        for(int i=0;i<33;i++){
            exp[i] = pow(2,i);
        }
        long long ans = findways(1,1,0,0,exp,k,dp); 
        //the parameters include the position, variable representing if we can go back, no. of forward jumps made,no. of backsteps made
        return ans;
    }
};

/*
jump and back parameter will not exceed 40 as max value of k is 10^9( 2^40 >>> 10^9)
*/
