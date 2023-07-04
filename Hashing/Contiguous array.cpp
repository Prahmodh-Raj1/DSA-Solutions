//Problem link: https://leetcode.com/problems/contiguous-array/
//TC: O(N) SC: O(N)
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        /*we make use of a HashMap mapmapmap to store the entries in the form of (index,count)(index, count)(index,count). We make an entry for a countcountcount in the mapmapmap whenever the countcountcount is encountered first, and later on use the correspoding index to find the length of the largest subarray with equal no. of zeros and ones when the same countcountcount is encountered again.*/
        unordered_map<int,int> mp;
        int n= nums.size();
        int ans=0;
        mp[0]=-1;  //given to get the count properly when we encounter equal number of zeroes and ones
        int sum=0;

        for(int i=0;i<n;i++){
            if(nums[i]==1) sum++;  //increment when we have 1, and decrement when we have 0
            else sum--;
            if(mp.find(sum)!=mp.end()){
                ans=max(ans,i-mp[sum]);
            }else mp[sum]=i;
        }
        return ans;

    }
};
