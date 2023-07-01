//Problem link; https://cses.fi/problemset/task/1193/
#include <bits/stdc++.h>

using namespace std;

#define ii pair<int, int>
#define f first
#define s second
#define mp make_pair
bool isvalid(int i,int j,int m,int n){
    return i>=0 and i<m and j>=0 and j<n;
}

int main() {
	int n,m; cin>>n>>m;
    int inda1=0,inda2=0,indb1=0,indb2=0;
    vector<vector<char>> grid(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
            if(grid[i][j]=='A') {
                inda1=i;
                inda2=j;
            }else if(grid[i][j]=='B'){
                indb1=i;
                indb2=j;
            }
        }
    }
   // cout<<"indb1= "<<indb1<<" indb2= "<<indb2<<"\n";
    vector<vector<int>> prev(n,vector<int>(m));  //used to keep track of the path, stores the previous direction that we moved in to arrive at that cell
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    string stepdir = "URDL";
    bool visited[n][m];
    memset(visited,false,sizeof(visited));
    queue<pair<int,pair<int,int>>> q;
    q.push({0,{inda1,inda2}});
    
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int steps = it.first;
        int x = it.second.first;
        int y = it.second.second;
        //cout<<steps<<" "<<x<<" "<<y<<"\n";
        visited[x][y]=true;
        if(x==indb1 and y==indb2){
            //cout<<"here x,y is "<<visited[x][y]<<"\n";
            break;
        }
        
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y + dy[i];
            if(isvalid(nx,ny,n,m) and !visited[nx][ny] and (grid[nx][ny]=='.' or grid[nx][ny]=='B')){
                prev[nx][ny]=i;
                //cout<<prev[nx][ny]<<"\n";
                visited[nx][ny]=true;
                q.push({steps+1,{nx,ny}});
            }
        }
    }
    //cout<<visited[indb1][indb2]<<"\n";
    if(visited[indb1][indb2]){
        vector<char> path;
        pair<int,int> begin = make_pair(inda1,inda2);
        pair<int,int> end = make_pair(indb1,indb2);
        while(begin!=end){
            int p = prev[end.first][end.second];
            path.push_back(stepdir[p]);
            end = make_pair(end.f - dx[p],end.s - dy[p]);
        }
        reverse(path.begin(),path.end());
        cout<<"YES\n";
        cout<<path.size()<<"\n";
        for(auto it:path){
            cout<<it;
        }
        
        
    }else{
    	cout<<"NO\n";
    }
    
    return 0;
 
}
