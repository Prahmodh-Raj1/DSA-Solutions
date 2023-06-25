//Problem link:  https://leetcode.com/problems/find-the-duplicate-number/
//TC: O(NlogN) SC: O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int low=0;
        int high=nums.size();
        while(low<high){
            int mid = (low+high)/2;
            int cnt=0;
            for(auto it:nums){
                if(it<=mid) cnt++;
            }
            if(cnt>mid) high=mid;
            else low=mid+1;
        }
        return low;
    }
};
