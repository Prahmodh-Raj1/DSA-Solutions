//Problem link: https://leetcode.com/problems/maximum-length-of-pair-chain/
//TC: O(N^2) SC: O(N)
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        //sort by left(i)
        sort(pairs.begin(),pairs.end());
        int maxi=1;
        vector<unordered_map<int,int>> dp;
        int n = pairs.size();
        
        vector<int> mem(n,1);
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(pairs[i][0]>pairs[prev][1] and mem[i]<1+mem[prev]){
                    mem[i] = 1+mem[prev];
                    maxi = max(maxi,mem[i]);
                }
            }
        }
        return maxi;
    }
};
