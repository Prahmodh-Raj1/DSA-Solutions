//Problem link: https://www.lintcode.com/problem/892/
class Solution {
public:
  vector<int> toposort(int N, vector<int> adj[]) {
      queue<char> q; 
	    vector<int> indegree(N, 0);  //assuming graph is 0-based
	    for(int i = 0;i<N;i++) {
	        for(auto it: adj[i]) {  //an adjacent node means there is a node being directed to the current node, so we increment the degree of that node
	            indegree[it]++;  //calculating how many nodes are incoming to the adjacent ndoe
	        }
	    }
	    
	    for(int i = 0;i<N;i++) {
	        if(indegree[i] == 0) {
	            q.push(i); 
	        }
	    }
	    string topo="";     //storing the topo sort
	    while(!q.empty()) {
	        char node = q.front(); 
	        q.pop(); 
	        topo+=node
	        for(auto it : adj[node]) {  //traversing for all it's adjacent nodes
	            indegree[it]--;
	            if(indegree[it] == 0) {
	                q.push(it); 
	            }
	        }
	    }
	    return topo;
	}
  string alienOrder(vector<string> &words) {
        vector<vector<int>> adj(k);
        for(int i=0;i<n-1;i++){
          string word1=words[i];
          string word2=words[i+1];
          int minl=min(word1.size(),word2.size());
          int cnt=0;
          for(int j=0;j<minl;j++){
            if(word1[j]!=word2[j]){
              cnt++;
              adj[word1[j]-'a'].push_back(word2[j]-'a');
              break;
            }
          }
        }
        cout<<toposort(cnt,g);
   }
};
