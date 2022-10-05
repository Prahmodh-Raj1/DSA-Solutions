//Problem link: https://leetcode.com/problems/number-of-provinces/
//TC :O(N+E) SC: O(N)
class Solution {
public:
    bool visited[204];
    vector<int> adj[204];
    void dfs(int cur){
        visited[cur]=true;
        for(auto it:adj[cur]){
            if(!visited[it]) dfs(it);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j){
                    if(isConnected[i][j]==1){
                        adj[i].push_back(j);
                        adj[j].push_back(i);
                    }
                }
            }
        }
        int cnt=0;
        memset(visited,false,sizeof(visited));
        for(int i=0;i<n;i++){
            if(!visited[i]){
                cnt++;
                dfs(i);
            }
        }
        return cnt;
    }
};
