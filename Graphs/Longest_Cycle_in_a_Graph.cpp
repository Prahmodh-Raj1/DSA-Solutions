//Problem link:https://leetcode.com/problems/longest-cycle-in-a-graph/
//TC: O(V+E) SC:O(V)-Auxillary stack space
class Solution {
    int ans = -1;
    int len = 0;
    void dfs(int i, vector<int>& edges, vector<int>& visited,int st) {
        visited[i] = len++;
        if (edges[i] == -1)
            return;
        else if (visited[edges[i]] == -1)
            dfs(edges[i],edges, visited,st);
        else if (visited[edges[i]] >= st)
            ans = max(ans, visited[i] - visited[edges[i]] + 1);  //updating the length of the longest cycle
    }
public:
    int longestCycle(vector<int>& edges) {
        vector<int> visited(edges.size(), -1);
        for (int i = 0; i < edges.size(); i++){
            if (visited[i] == -1 && edges[i] != -1){
                dfs(i,edges, visited,len);
            }
        }
        return ans;
    }
};
