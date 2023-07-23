//prob link: https://leetcode.com/problems/house-robber-ii
//TC: O(N) SC: O(2*N)
class Solution {
public:
    int maxrob(vector<int>& robb){
        int prev=robb[0];
        int prev2=0;
        int n=robb.size();
        for(int i=1;i<n;i++){
            int take=robb[i];
            if(i>1) take+=prev2;
            int cur=max(take,prev);
            prev2=prev;
            prev=cur;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int n=nums.size();
        vector<int> dp1,dp2;
        for(int i=0;i<n;i++){
            if(i==0){
                dp2.push_back(nums[i]);
            }
            else if(i==n-1) dp1.push_back(nums[i]);
            else{
                dp1.push_back(nums[i]);
                dp2.push_back(nums[i]);
            }
        }
        return max(maxrob(dp1),maxrob(dp2));
       
    }
};
