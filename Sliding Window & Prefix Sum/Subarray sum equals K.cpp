//Problem link: https://leetcode.com/problems/subarray-sum-equals-k/description/
//TC:O(N) SC:O(N)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum=0,cnt=0;
        unordered_map<int,int> mp;
        mp[0]=1;
        for(auto it:nums){
            sum+=it;
            int req = sum-k;
            if(mp.find(req)!=mp.end()){
                cnt+=mp[req];
            }
            mp[sum]++;
        }
        return cnt;
        
    }
};
