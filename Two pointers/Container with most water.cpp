//Problem link: https://leetcode.com/problems/container-with-most-water/submissions/
//TC: O(N) SC: O(N)
class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int i=0,j=n-1;
        int maxamount=0;
        while(i<j){
            int curh = min(heights[i],heights[j]);  //finding the current height
            maxamount = max(maxamount,(j-i)*curh);  //checking for the maximum amount covered at that point
            while(j>i and heights[j]<=curh) j--;  //finding the next larger height from the right
            while(i<j and heights[i]<=curh) i++; //finding the next larger height from the left
        }
        return maxamount;
    }
};
