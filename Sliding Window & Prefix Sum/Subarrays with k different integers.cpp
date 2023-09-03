//Prob link: https://leetcode.com/problems/subarrays-with-k-different-integers
//TC: O(N) SC: O(N)
class Solution {
private:
    int atmost(vector<int>& nums,int k){
        unordered_map<int,int> mp;
        int l=0,r=0;
        int ans=0;
        for(r=0;r<nums.size();r++){
            mp[nums[r]]++;
            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0) mp.erase(nums[l]);
                l++;

            }
            ans+=(r-l+1);
        }
        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
      //exactly equal to k = atmost(k times) - atmost(k-1 times)
        return atmost(nums,k) - atmost(nums,k-1);
    }
};
