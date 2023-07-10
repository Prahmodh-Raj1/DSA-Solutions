//Problem link: https://leetcode.com/problems/4sum-ii/description/
//TC: O(N^2) SC: O(N)
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> mp;
        int cnt=0;
        for(auto it:nums3){
            for(auto i:nums4){
                mp[it+i]++;  //storing all possible combination sums of nums3 and nums4
            }
        }
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(mp.find(-1*(nums1[i]+nums2[j]))!=mp.end()){
                    cnt+=mp[-1*(nums1[i]+nums2[j])];
                }
            }
        }
        return cnt;
    }
};
