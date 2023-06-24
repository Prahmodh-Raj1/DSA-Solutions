//Problem link:  https://leetcode.com/problems/arranging-coins/ 
//TC: O(logN) SC: O(1)
class Solution {
public:
    int arrangeCoins(int n) {
        long left=0,right=(long)n;
        while(left<=right){
            long mid = (left+right)/2;
            long val = mid*(mid+1)/2;
            if(val==n){
                return mid;
            }else if(n<val){
                right=mid-1;
            }else left=mid+1;
        }
        return (int)right;
    }
};
