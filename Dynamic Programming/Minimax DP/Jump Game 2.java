//problem link: https://leetcode.com/problems/jump-game-ii/
//TC: O(N) SC: O(N)
class Solution {
    public int func(int[] nums,int dp[],int i){
        if(i>=nums.length-1){  // when we reach end, return 0 denoting no more jumps required
            return 0;
        }
        if(dp[i]!=100000){
            return dp[i];
        }
        for(int j=1;j<=nums[i];j++){
            dp[i]=Math.min(dp[i],1+func(nums,dp,i+j));
        }
        return dp[i];
    }
    public int jump(int[] nums) {
        int n = nums.length;
        int dp[] = new int[n];  //dp[i]= number of jumps required to reach the index i
        Arrays.fill(dp,100000);
       
        return func(nums,dp,0);
        
    }
}

//iterative DP:
public int jump(int[] nums) {
        int n = nums.length;
        int dp[] = new int[n];
        Arrays.fill(dp,100000);
        dp[n-1]=0;  //we need 0 jumps from the last index
       for(int i=n-2;i>=0;i--){
           for(int jlen=1;jlen<=nums[i];jlen++){  //looking for all possible jumps
               dp[i]=Math.min(dp[i],1+dp[Math.min(n-1,i+jlen)]);  //keeping a check on index out of bounds error
           }
       }
       return dp[0];
}
