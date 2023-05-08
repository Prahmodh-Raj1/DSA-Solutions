class Solution {
    public int deleteAndEarn(int[] nums) {
        if(nums.length==1){
            return nums[0];
        }
        int n=nums.length;
        int dp[]= new int[10001];
        Arrays.fill(dp,0);
        Arrays.sort(nums);
        int sum[]= new int[10001];  //storing the points that can be obtained by choosing that element, all duplicate values would contribute to the total point tally
        for(int i=0;i<n;i++){
            sum[nums[i]]+=nums[i];
        }
        dp[0]=0;
        dp[1]=sum[1];
        int maxi=0;
        //dp[i] stores the maximum points that can be obtained till the index i
        for(int i=2;i<=10000;i++){
            dp[i]=Math.max(dp[i-2]+sum[i],dp[i-1]);  //either including the element or skipping the element
            maxi=Math.max(dp[i],maxi);
        }
        return maxi;
    }
}
