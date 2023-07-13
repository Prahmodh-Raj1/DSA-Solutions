//Problem link: https://leetcode.com/problems/sum-of-square-numbers
//TC: O(root(N)) SC: O(1)
class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c==0) return true;
        long long l=0,r=sqrt(c);
        while(l<=r){
            long long lsquare = l*l;
            long long rsquare = r*r;
            long long mid = lsquare+rsquare;
            
            if(mid>c){
                r--;
            }else if(mid<c){
                l++;
            }else return true;
        }
        return false;
    }
};
