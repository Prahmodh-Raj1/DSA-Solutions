//Problem link : https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/
//TC :O(E) SC :O(N)
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        vector<int> vec(n,0);
        for(auto it: edges){
            vec[it[1]]+=1;
        }
        for(int i=0;i<n;i++){
            if(vec[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
