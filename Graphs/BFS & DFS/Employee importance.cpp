//Prob link: https://leetcode.com/problems/employee-importance/description

//TC: O(N) SC: O(N)
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
private:
    void dfs(vector<vector<int>>& adj,int id,int& sum,unordered_map<int,int>& mp,vector<bool>& vis){
        vis[id]=true;
        sum+=mp[id];
        cout<<sum<<"\n";
        for(auto it:adj[id]){
            if(!vis[it]){
                dfs(adj,it,sum,mp,vis);
            }
        }
        return;
    }
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,int> mp;  //empl -> importance
        //adj list to be created wrt id;
        for(auto it:employees){
            mp[it->id]=it->importance;
        }
        
        int n= employees.size();
        vector<vector<int>> adj(2001);
        for(int i=0;i<n;i++){
            vector<int> sub  =  employees[i]->subordinates;
            for(int j=0;j<sub.size();j++){
                adj[employees[i]->id].push_back(sub[j]);
            }
        }
        int sum=0;
        vector<bool> vis(2001,false);
        dfs(adj,id,sum,mp,vis);
        return sum;
    }
};
