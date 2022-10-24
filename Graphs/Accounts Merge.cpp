//Problem link: https://leetcode.com/problems/accounts-merge/

class Solution {
public:
int parent[1005];
int rank[1005];

void init(){
	for(int i=1;i<=1000;i++){
		parent[i]=i;
		rank[i]=0;
	}
}
int find(int x){
	if(parent[x]==x) return x;
	else return parent[x]=find(parent[x]);  //path compression
}

void unite(int x,int y){
	x=find(x); //finding the root node of x
	y=find(y); //finding the root nod of y
	if(rank[x]>rank[y]){
		parent[y]=x;
	}
	else if(rank[y]>rank[x]){
		parent[x]=y;
	}
	else{
		parent[y]=x;
		rank[x]++;
	}
}
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        init();
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(mp.find(mail)==mp.end()){
                    mp[mail]=i;
                }
                else{
                    unite(i,mp[mail]);
                }
            }
        }
        vector<string> v[n];
        for(auto it:mp){
            string m=it.first;
            int utp=find(it.second);
            v[utp].push_back(m);
        }
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(v[i].size()==0) continue;
            sort(v[i].begin(),v[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it:v[i]) temp.push_back(it);
            ans.push_back(temp);
        }
        return ans;
    }
};
