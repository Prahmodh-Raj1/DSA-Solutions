//Problem link: https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-ii/
//TC: O(N) SC: O(1)
class Solution {
public:
    int minOperations(vector<int>& nums) {
        //keep track of how many elements u have flipped
        int ans=0;
        //int flipped=0; //keeps track of how many sections have been flipped so far
        int flipsSoFar=0;
        for(int i=0;i<nums.size();i++){
            /*
            if((it ^ flipped)==0){
                //if it's been flipped odd number of times, then it's true value would've changed
                //a flip needs to be performed now to restore the value
                flipped^=1;
                ans++;
            }
            */

            //if flips done so far is odd, then current value would've changed
            if(flipsSoFar & 1){
                nums[i]^=1; //flipping it
            }

            //if current value  is 0, then we need to flip from [i,n]
            if(nums[i]==0) flipsSoFar++; 
        }
        //return ans;
        return flipsSoFar;
    }
};
