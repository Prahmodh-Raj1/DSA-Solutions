//Problem link: https://www.lintcode.com/problem/892/
class Solution {
private:
	int getInt(char c){
		return(c-'a');
	}
private:
	bool checkcycle(int node,vector<int> adj[],vector<int> &vis,vector<int> &pathvis,stack<int> &st){
		vis[node]=1;
		pathvis[node]=1;
		for(auto it: adj[node]){
			if(!vis[it]){
				if(checkcycle(it,adj,vis,it)==true) return true;
			}
			else if(!pathvis[it]){
				return true;
			}
		}
		pathvis[node]=0;
		st.push(node);
		return false;
	}
public:
 	//Edge cases:
	//if no mismatch is found, then longer word comes after shorter word
	//if there is a cycle in the Directed graph
  string alienOrder(vector<string> &words) {
 	int n=words.size();
	  //a:0, b:1, ...z:25
	vector<int> adj[26];
	vector<int> store(26,0),vis(26,0),pathvis(26,0);
	for(int i=0;i<n;i++){
		  for(auto it: words[i]){
			  store[getint(it)]=1;
		  }
	}
	for(int i=0;i<n;i++){
		string s1=words[i];
		string s2=words[i+1];
		for(int j=0;j<n;j++){
			if(j>=s2.size()){
				return "";
			}
			if(s1[j]!=s2[j]){
				store[getint(s1[j])]=1;
				store[getint(s2[j])]=1;
				adj[getint(s1[j])].push_back(getint(s2[j]));
				
				break;
			}
		}
		
	}
	stack<int> st;
	for(int i=0;i<26;i++){
		if(store[i] && !vis[i]){
			if(checkcycle(i,adj,vis,pathvis,st)==true){
				return "";
			}
		}
	}
	string ans="";
	while(!st.empty()){
		ans+=char(st.top() + 'a');
		st.pop();
	}
	return ans;
   }
};
