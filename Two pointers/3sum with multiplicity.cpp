//Problem link: https://leetcode.com/problems/3sum-with-multiplicity/

//TC: O(N^2) SC: O(N)
class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        
        int n=arr.size();
        unordered_map<int,int> mp;
        int mod  = 1e9 + 7;
        //using a map to count the sums of two numbers
        //if target-arr[i] is in the map, it means we have found a three sum, so add it to cnt
        int cnt=0;
        for(int i=0;i<n;i++){
            int rem = target - arr[i];
            cnt = (cnt+ mp[rem])%mod;
            for(int j=0;j<i;j++) mp[arr[i]+arr[j]]++;
        }
        return cnt;
    }
};
