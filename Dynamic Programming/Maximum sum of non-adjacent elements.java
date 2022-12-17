//Problem link: https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261

//Memoization (Recursive DP)
//TC:O(N) SC:O(N)+O(N)
public static int maxisum(int i,ArrayList<Integer> nums,int[] dp){
        if(i<0) return 0;
        if(i==0) return nums.get(i);
        if(dp[i]!=-1) return dp[i];
        int lp=nums.get(i)+maxisum(i-2,nums,dp);
        int rp=maxisum(i-1,nums,dp);
        dp[i]=Math.max(lp,rp);
        return dp[i];
}
//Iterative DP(Tabulation)
//TC :O(N) SC:O(N)
public static int maximumNonAdjacentSum(ArrayList<Integer> nums) {
		
        int n = nums.size();
        int dp[] = new int[n];
        Arrays.fill(dp,-1);
        dp[0]=nums.get(0);
        for(int i=1;i<n;i++){
            int take=nums.get(i);
            if(i>1){
                take+=dp[i-2];
            }
            int nottake=dp[i-1];
            dp[i]=Math.max(take,nottake);
        }
        return dp[n-1];
	}

//Space Optimised TC :O(N) SC:O(1)
public static int maximumNonAdjacentSum(ArrayList<Integer> nums) {
       
        int n = nums.size();
        int prev=nums.get(0);
        int prev1=0;
        
        for(int i=1;i<n;i++){
            int take=nums.get(i);
            if(i>1){
                take+=prev1;
            }
            int nottake=prev;
            int curi=Math.max(take,nottake);
            prev1=prev;
            prev=curi;
            
        }
        return prev;
       
    }
