//Problem link: https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference
//TC: O(N) SC: O(N)
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        unordered_map<int,int> dp;
        int maxi=1;
        for(int i=0;i<n;i++){
            if(dp.find(arr[i]-difference)!=dp.end()){
                dp[arr[i]] = dp[arr[i]-difference]+1;
            }else dp[arr[i]]=1;
            maxi =  max(maxi,dp[arr[i]]);
        }
        return maxi;
    }
};
/*
Check if there exists a number num - difference in the dp map. If it does, it means we can extend the subsequence ending at num - difference by including the current number num. So, we set dp[num] to be dp[num - difference] + 1, indicating that the length of the subsequence ending at num is one greater than the length of the subsequence ending at num - difference.
If there is no num - difference in the dp map, it means we have found a new subsequence starting at num. So, we set dp[num] to 1, indicating the start of a new subsequence.
*/
