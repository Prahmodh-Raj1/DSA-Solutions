//Problem link: https://leetcode.com/problems/longest-increasing-subsequence
class Solution {
    private int LIS(int ind,int prevind,int[] nums,int[][] dp){
        if(ind==nums.length) return 0;
        if(dp[ind][prevind+1]!=-1) return dp[ind][prevind+1]; //doing prevind+1 to avoid -1 indexing and implementing 1-based indexing
        int nottake = LIS(ind+1,prevind,nums,dp);
        int take=0;
        if(prevind==-1 || nums[ind]>nums[prevind]){
            take = 1 + LIS(ind+1,ind,nums,dp);
        }
        dp[ind][prevind+1] = Math.max(take,nottake);
        return dp[ind][prevind+1]; 
    }
    public int lengthOfLIS(int[] nums) {
        //two states for DP
        //index and the prev_index chosen for the LIS
        //prev index can range from -1 to n-1, so we do a coordinate shift and implement 1-based indexing for that state
        int n= nums.length;
        int dp[][] = new int[n+1][n+1];
        //base case is when index reaches n, we have considered the entire array
        for(int row[]:dp){
            Arrays.fill(row,-1);
        }
        //Tabulation approach
        int mem[] = new int[n];
        int hashpick[] = new int[n];
        //Whenever we update our dp[i] value in the inner loop, we know that for index i, the previous index is prev_index. Therefore we simply store prev_index to hash[ i ]. In this way, we will have a way to trace back the LIS
        //Whenever we have computed the entire dp array and we find the maximum value in it. We store that maximum value’s index in a variable ( say last_index). Now with this last_index, and the hash array we can trace back the LIS elements.
        Arrays.fill(mem,1);
        Arrays.fill(hashpick,1);
        int maxi = 1;
        
        for(int i=0;i<n;i++){
            hashpick[i]=i; //initialising with the current index
            for(int prev=0;prev<i;prev++){
                if(nums[prev]<nums[i] && 1 + mem[prev]>mem[i]){
                    mem[i] = 1 + mem[prev];
                    hashpick[i] = prev;
                    maxi = Math.max(mem[i],maxi);
                }
            }
        }
        int ans=-1,lastpickindex=-1;
        for(int i=0;i<n;i++){
            if(mem[i]>ans){
                ans=mem[i];
                lastpickindex=i;
            }
        }
        ArrayList<Integer> lis = new ArrayList<>();
        lis.add(nums[lastpickindex]);
        while(hashpick[lastpickindex]!=lastpickindex){
            lastpickindex = hashpick[lastpickindex];
            lis.add(nums[lastpickindex]);
        }
        Collections.reverse(lis);
        for(int i=0;i<lis.size();i++){
            System.out.println(lis.get(i));
        }
        return maxi;
        //return LIS(0,-1,nums,dp);
    }
}
