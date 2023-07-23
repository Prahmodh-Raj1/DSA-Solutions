//Prob link: https://leetcode.com/problems/climbing-stairs
//TC: O(N) SC: O(1)
class Solution {
    public int climbStairs(int n) {
        
        if(n==1) return 1;
        int prev2=1;
        int prev1=2;
        int cur;
        for(int i=3;i<=n;i++){
            cur=prev1+prev2;
            prev2=prev1;
            prev1=cur;
        }
        return prev1;
        
    }
}
