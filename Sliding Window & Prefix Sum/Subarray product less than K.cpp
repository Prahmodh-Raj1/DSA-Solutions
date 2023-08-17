//Prob link:https://leetcode.com/problems/subarray-product-less-than-k/
//TC: O(N) SC: O(1)
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt=0;
        int prod=1;
        int i=0;
        if(k==0) return 0;
        for(int j=0;j<n;j++){
            //here the state is the product of the numbers in the window
            //invalid state is when the product is >=k
            prod*=nums[j];
            while(i<=j and prod>=k){
                prod/=nums[i++];
            }
            cnt+=(j-i+1);
        }
        return cnt;
    }
};
