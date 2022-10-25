//Problem links: https://leetcode.com/problems/course-schedule/ , https://leetcode.com/problems/course-schedule-ii/
//TC :O(V+E) SC:O(V+E)

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size()==0) return true;
        int n=numCourses;
        vector<int> adj[n];
        vector<int> indegree(numCourses+1,0);
        int le=prerequisites.size();
        
        for(auto it:prerequisites){
                adj[it[1]].push_back(it[0]);
                indegree[it[0]]++;
        
        }
        queue<int> q;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)  q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            cnt++;
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(cnt==numCourses) return true;
        return false;
        
    }
};

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        if(prerequisites.size()==0){
            for(int i=0;i<numCourses;i++) ans.push_back(i);
            return ans;
        } 
        int n=numCourses;
        vector<int> adj[n];
        vector<int> indegree(numCourses+1,0);
        for(auto it:prerequisites){
                adj[it[1]].push_back(it[0]);
                indegree[it[0]]++;
        
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)  q.push(i);
        }
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(ans.size()==numCourses) return ans;
        return vector<int>();
    }
};
