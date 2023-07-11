//Problem link: https://leetcode.com/problems/next-permutation/
//TC: O(N) SC: O(1)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //brute approach:
        //find all permutations and figure out the next permutation
        //optimal soln
        //traverse from the back, find the first index i (say index) such that a[i] is lesser than a[i+1
        //again traverse from back and find the index(say index1) that is greater than a[index]
        //swap values at index  and index1
        //next reverse everything that is to the right of index1
        //if we dont get an index, then just reverse the entire array
        if(nums.size()==1) return;
        int n=nums.size();
        int index=n;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                index=i;
                break;
            }
        }
        if(index==n){
            reverse(nums.begin(),nums.end());
            return;
        }
        int index1=-1;
        for(int i=n-1;i>=0;i--){
            if(nums[i]>nums[index]){
                index1=i;
                break;
            }
        }
        swap(nums[index],nums[index1]);
        reverse(nums.begin()+index+1,nums.end());
        return;
    }
};
