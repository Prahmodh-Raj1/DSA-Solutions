//Problem link: https://leetcode.com/problems/shortest-unsorted-continuous-subarray
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        //have a prefix max and a suffix min
        /*
        From the left, for a number to stay untouched, there need to be no number less than it on the right hand side;
From the right, for a number to stay untouched, there need to be no number greater than it on the left hand side;*/
        int n = nums.size();
        vector<int> maxlhs(n,INT_MIN);
        vector<int> minrhs(n,INT_MAX);
        for(int i=n-1,minr=INT_MAX;i>=0;i--) minrhs[i] = minr = min(minr,nums[i]);
        for(int i=0,maxl = INT_MIN;i<n;i++) maxlhs[i] = maxl= max(maxl,nums[i]);
        int i=0,j=n-1;
        while(i<n && nums[i]<=minrhs[i]) i++;
        while(j>i && nums[j]>=maxlhs[j]) j--;
        return j-i+1;
    }
};
/*
*            /------------\
 * nums:  [2, 6, 4, 8, 10, 9, 15]
 * minr:   2  4  4  8   9  9  15
 *         <--------------------
 * maxl:   2  6  6  8  10 10  15
 *         -------------------->
 */
