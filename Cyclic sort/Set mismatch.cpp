//problem link : https://leetcode.com/problems/set-mismatch/
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        //int i = 0;
        while (i < n) {
            int correctIdx = nums[i] - 1;
            if (nums[i] != nums[correctIdx]) {
                swap(nums[i], nums[correctIdx]);
            } else {
				i++;
			}
        }
        vector<int> ans;
        for (i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                ans = {nums[i],i+1};
                return ans;
            }
        }
        return ans;
    }
};
