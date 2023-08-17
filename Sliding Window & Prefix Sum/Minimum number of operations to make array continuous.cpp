//Prob link: https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous
//TC: O(N) SC: O(1)
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int maxSizeOfValidWindow=0;
        int  i=0,j=0;
        sort(nums.begin(),nums.end());
        int len = nums.size();
        nums.erase(unique(begin(nums),end(nums)),end(nums));  //storing only unique values
        int n=nums.size();
        unordered_map<int,int> freq;
        int maxi=INT_MIN,mini=INT_MAX;
        //get the length of the largest subarray whose difference betweeen min and max elements is len-1;

        for(j=0;j<n;j++){
            //in the window, nums[j] is the largest element and nums[i] is the minimum element
            while(nums[j]-nums[i]>=len) i++; //i is the first element that is in the range a[j]-a[i]<n
            maxSizeOfValidWindow = max(maxSizeOfValidWindow,j-i+1); //maxSizeOfValidWindow stores the max subarray length that satisfies the condition
        }
        return len - maxSizeOfValidWindow;
    }
};
