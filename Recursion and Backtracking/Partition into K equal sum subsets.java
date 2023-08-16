//Prob link: https://leetcode.com/problems/partition-to-k-equal-sum-subsets
//TC: O(2^(k*n)) SC: O(N)
2^n ways to go to subset 1. For each of the way, we can go to another 2^n. So , (2^n )x (2^n) = 2 ^ (n + n). From subset 2 to subset 3, we have, 2 ^ (n + n) x 2^n = 2^(n + n + n) -> 2 ^ (3n) -> 2^(kn)
  class Solution {
    public boolean canPartitionKSubsets(int[] nums, int k) {
        int sum = 0;
        for(int num:nums)sum += num;
        if(k <= 0 || sum%k != 0)return false;
        int[] visited = new int[nums.length];
        return canPartition(nums, visited, 0, k, 0,sum/k);
    }
    
    public boolean canPartition(int[] nums, int[] visited, int start_index, int k, int cur_sum, int target){
        if(k==1)return true;
        if(cur_sum == target && k==0)return true;
        for(int i = start_index; i<nums.length; i++){
            if(visited[i] == 0 && nums[i]<=target){
                visited[i] = 1;
                if(canPartition(nums, visited, i+1, k-1, cur_sum + nums[i], target))return true;
                visited[i] = 0;
            }
        }
        return false;
    }
}
                                                                                                                                                                                                     
