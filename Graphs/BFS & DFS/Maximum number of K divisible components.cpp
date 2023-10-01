//prob link: https://leetcode.com/problems/maximum-number-of-k-divisible-components/
//TC: O(N) SC: O(V+E)
class Solution {
private:
    vector<vector<int>> adj;
    long long cnt=0;
    long long dfs(int node,int parent,long long k,vector<int>& values){
        
        long long sum=values[node];
        for(auto it:adj[node]){
            if(it!=parent){
                sum+=dfs(it,node,k,values);
            }
        }
       
        if(sum%k==0){
            cnt++;
            return 0;
        }
        return sum;
    }
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        //int div = accumulate(values.begin(),values.end(),0) / k;
        adj.resize(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        dfs(0,-1,(long long)k,values);
        return cnt;
    }
};
