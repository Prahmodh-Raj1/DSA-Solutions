//problem link: https://leetcode.com/problems/rotate-array/
//TC: O(N) SC: O(1)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k%=n;
        if(k==0) return;
        int firsthalf=n-k;  //reverse the first n-k elements, then reverse the next k elements, followed by reversoing the entire array
        reverse(nums.begin(),nums.begin()+firsthalf);
        reverse(nums.begin()+firsthalf,nums.end());
        reverse(nums.begin(),nums.end());

    }
};
