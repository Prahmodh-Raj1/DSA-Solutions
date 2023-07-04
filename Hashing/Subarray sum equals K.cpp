//Problem link: https://leetcode.com/problems/subarray-sum-equals-k/
//TC: O(N) SC: O(N)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;
        int sum=0;
        int cnt=0;
        mp[0]=1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            
            if(mp.find(sum-k)!=mp.end()){
                cnt+=mp[sum-k];
            }
            mp[sum]++;
        }
        return cnt;
    }
};
