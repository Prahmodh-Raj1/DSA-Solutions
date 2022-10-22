//Problem link: https://leetcode.com/problems/keys-and-rooms/
//TC :O(N) SC:O(N)
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        bool visited[n];
        memset(visited,false,sizeof(visited));
        visited[0]=true;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            visited[node]=true;
            for(int i=0;i<rooms[node].size();i++){
                if(!visited[rooms[node][i]]){
                    q.push(rooms[node][i]);
                    visited[rooms[node][i]]=true;
                }
            }
        }
       
        for(int i=0;i<n;i++){
            if(visited[i]==0) return false;
        }
        return true;
    }
};
