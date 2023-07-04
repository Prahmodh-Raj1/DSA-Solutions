//Base problem link: https://leetcode.com/problems/continuous-subarray-sum/description/
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size()<2) return false;
       
        map<int,int> mp; //remainder and the index where that remainder is found
        //if the value is not part of the map, add it to the map as mp[rem]=i; where rem =running sum % k
        //if the remainder is alreaady part of the map, chek if both the indices are unequal, then return true, since the good array is formed
        int sum=0;
        mp[0]=-1;  //used for the case where an empty array is considered part of ur prefix sum
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(mp.find(sum%k)==mp.end()){
                mp[sum%k]=i;
            }else{
                if(i-mp[sum%k]>1){
                    return true;
                }
            }
        }
        return false;
    }
};

//Main problem link: https://leetcode.com/problems/subarray-sums-divisible-by-k/
//TC: O(N) SC: O(N)
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum=0;
        int cnt=0;
        int n=nums.size();
        unordered_map<int,int> mp;  //stores (sum%k),count of sum%k
        //based on the intuition that sum[i]%k == sum[j]%k, where i<j
       
        mp[0]=1; //the case of the whole array being a subarray whose sum is divisible by k, we need to initialize count[0] = 1, also for the case where we consider an empty array, sum of an empty array is 0, so we already have a sum 0 even before starting
        for(int i=0;i<n;i++){
            sum+=(nums[i]);  //we need only the mod-ed value of nums
            int mod = (sum%k + k)%k; //used to negate the negative remainders that may arise
            if(mp.find(mod)!=mp.end()) cnt+=mp[mod];  //already that sum%k is present, so it contributes to overall count
            mp[mod]++; //if it hasn't been found yet,add to the map or if already found, increment it's count
            
        }
        return cnt;
    }
};
