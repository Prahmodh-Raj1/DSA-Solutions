//Prob link: https://leetcode.com/problems/frequency-of-the-most-frequent-element
//TC: O(NLOGN) SC: O(1)
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long start=0,end=0,ans=1,sum=0;
        int n= nums.size();
        for(end=0;end<n;end++){
            sum+=nums[end];
            int sizeofwindow = end-start+1;
            while( (((end-start+1)*nums[end]) - sum) > k){
                //window is invalid
                sum-=nums[start++];
                
            }
            sizeofwindow =end-start+1;
            ans=max((int)ans,sizeofwindow);
        }
        return ans;
    }
};
