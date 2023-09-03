//Prob link:   https://leetcode.com/problems/count-number-of-nice-subarrays/
//TC: O(N) SC: O(1)
class Solution {
private:
    int atmost(vector<int>& nums,int k){
        int len = nums.size();
        int cnt=0;
        int ans=0;
        int i=0,j=0;
        for(int j=0;j<len;j++){
            if(nums[j] & 1) cnt++;
            while(cnt>k){
                
                if(nums[i] & 1) cnt--;
                i++;
                
            }
            ans+=(j-i+1);
        }
        return ans;

    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        //For any condition of exactly k times = atmost(k times)  - atmost(k-1 times)
        return atmost(nums,k) - atmost(nums,k-1);
    }
};
