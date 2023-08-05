//Problem link:https://leetcode.com/problems/missing-number
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        while (i < n) {
            int correctIdx = nums[i];
            if (nums[i] < n && nums[i] != nums[correctIdx]) {
                int temp = nums[i];
                nums[i] = nums[correctIdx];
                nums[correctIdx] = temp;
            } else {
				i++;
			}
        }
        
        for(int i=0;i<n;i++){
            if(nums[i]!=i) return i;
        }
        return n;
    }
};
