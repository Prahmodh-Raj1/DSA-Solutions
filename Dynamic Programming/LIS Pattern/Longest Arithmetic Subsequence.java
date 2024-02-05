//Problem link: https://leetcode.com/problems/longest-arithmetic-subsequence/
//TC: O(N^2) SC: O(N*diff)
class Solution {
    public int longestArithSeqLength(int[] nums) {
        int n = nums.length;
        if(n<=2) return n;
        Map<Integer,Integer>[] dp = new HashMap[n];  //creating a hashing structure of array->map
       
        int maxi = 2;
        int diff=0;
        for(int i=0;i<n;i++){
            dp[i] = new HashMap<>();
            for(int prev=0;prev<i;prev++){
                diff = nums[i]-nums[prev];  //calculating the current difference
                //update dp[i][diff] based on whether we have seen a previous arithmetic subsequence ending at index j with a common difference of diff
                dp[i].put(diff,dp[prev].getOrDefault(diff,1)+1);
                //This retrieves the value associated with the key diff from another map at index j in the dp array. If the key diff is not present in the map at dp[j], it returns the default value 1.
                //Finally, it puts the incremented value back into the map at dp[i] with the same key diff
                maxi = Math.max(maxi,dp[i].get(diff));
                
            }
        }
        return maxi;
    }
}
