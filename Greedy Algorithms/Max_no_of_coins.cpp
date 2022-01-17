//problem link: https://leetcode.com/problems/maximum-number-of-coins-you-can-get/
//TC :O(N) SC:O(1)
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int n=piles.size();
        int j=n/3;
        int maxi=0;
        if(n==3){
            return piles[1];
        }
        while(j<n){
            maxi+=piles[j];
            j+=2;
        }
        return maxi;
    }
};
