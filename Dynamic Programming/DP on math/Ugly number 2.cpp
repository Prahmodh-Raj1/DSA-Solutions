//Problem link: https://leetcode.com/problems/ugly-number-ii/
//TC: O(N) SC: O(N)
class Solution {
public:
    
    int nthUglyNumber(int n) {
        vector<int> dp(1,1);
        int two=0,three=0,five=0;
        for(int i=1;i<n;i++){
            int p2val = dp[two]*2;
            int p3val = dp[three]*3;
            int p5val = dp[five]*5;
            int val = min(dp[two]*2,min(dp[three]*3,dp[five]*5));
            if(val==p2val) two++;
            if(val==p3val) three++;
            if(val==p5val) five++;
            dp.push_back(val);
        }
        return dp[n-1];
    }
};
//Explanation: https://leetcode.com/problems/ugly-number-ii/solutions/69364/my-16ms-c-dp-solution-with-short-explanation/ (refer 2nd comment)
