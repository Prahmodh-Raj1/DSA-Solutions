//Problem link: https://leetcode.com/problems/solving-questions-with-brainpower/

//Recursive DP: TC:O(N)  SC: O(N) + Auxillary stack space
class Solution {
public:
    int n;
    long long func(int ind,vector<vector<int>>& questions,vector<long long>& dp){
        
        if(ind==n-1) return questions[ind][0];
        
        if(ind>=n){
            return 0;
        }
        if(dp[ind]!=-1) return dp[ind];
        long long take= questions[ind][0]+func(ind+questions[ind][1]+1,questions,dp);
        long long nottake=func(ind+1,questions,dp);
        return dp[ind]=max(take,nottake);
        
    }
    long long mostPoints(vector<vector<int>>& questions) {
        n=questions.size();
        vector<long long> dp(n,-1);
        return func(0,questions,dp);
      
    }
};

//Iterative DP: TC:O(N) SC:O(N)
class Solution {
    public long mostPoints(int[][] questions) {
        int n=questions.length;
        long dp[] = new long[n];
        Arrays.fill(dp,-1);
        dp[n-1]=questions[n-1][0];
        for(int i=n-2;i>=0;i--){
            long take=0;
            long nottake=0;
            take+= questions[i][0]+(i+1+questions[i][1] < n ? dp[i+1+questions[i][1]] : 0);
            nottake+=dp[i+1];
            dp[i]=Math.max(take,nottake);
        
        } 
        return dp[0];
    }
}
