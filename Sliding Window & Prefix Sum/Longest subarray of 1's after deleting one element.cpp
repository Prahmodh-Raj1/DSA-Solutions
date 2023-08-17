//Prob link: https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/
//TC: O(N) SC: O(1)
class Solution {
public:
   
    int longestSubarray(vector<int>& A) {
        int i = 0, j = 0, N = A.size(), cnt = 0, ans = 0;
        //state here is the number of zeroes
        for (; j < N; ++j) {
            cnt += A[j] == 0;
            while (cnt > 1) cnt -= A[i++] == 0; //INVALID STATE
            ans = max(ans, j - i); // note that the window is of size `j - i + 1`. We use `j - i` here because we need to delete a number.
        }
        return ans;
    }
    
};
