//Problem Link: https://leetcode.com/problems/unique-binary-search-trees/
//TC: O(N^2) SC: O(N)
class Solution {
public:
    int dp[20];
    int numTrees(int n) {
        if(n<=1) return 1;
        if(dp[n]) return dp[n];
        for(int i=1;i<=n;i++){
            dp[n]+=numTrees(i-1)*numTrees(n-i);
        }
        return dp[n];
        
    }
};
