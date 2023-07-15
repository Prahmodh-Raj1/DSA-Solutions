//Prob link: https://leetcode.com/problems/sort-array-by-parity
//TC: O(N) SC: O(1)
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size();
        for(int  i=0,j=0;j<n;j++){
            if(nums[j]%2==0){
                swap(nums[i++],nums[j]);
            }
        }
        return nums;
    }
};
