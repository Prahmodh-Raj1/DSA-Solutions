//PROBLEM LINK: https://leetcode.com/problems/neighboring-bitwise-xor/
//TC: O(N) SC: O(1)
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int xorr=0;
        for(auto it:derived){
            xorr^=it;
        }
        if(xorr>0) return false;
        return true;
    }
};
