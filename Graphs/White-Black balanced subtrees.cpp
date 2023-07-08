//Problem link: https://codeforces.com/problemset/problem/1676/G
//TC: O(N)  SC: O(N^2)
int dfscol(vector<vector<int>>& children,string& s,int node,int& cnt){
    int bal;
    if(s[node-1]=='B') bal=-1;
    else bal=1;
    if(children[node].empty()){
        return bal;
    }
    for(auto it:children[node]){
        bal+=dfscol(children,s,it,cnt);
    }
    if(bal==0){
        cnt++;
    }
    return bal;
    
}
void solve()
{
    int n; cin>>n;
    vector<vector<int>> children(n+1);
    int x;
    for(int i=2;i<=n;i++){
        cin>>x;
        children[x].pb(i);
    }
    string s; cin>>s;
    int nl = s.size();
    
    int cnt=0;
    
    int val=dfscol(children,s,1,cnt);
    cout<<cnt<<"\n";
    
}
//Explanation: For each vertex store the values of the number of balanced subtrees, as well as the number of white and black vertices in it.

Then from a vertex we can count the total number of white vertices in its subtree as well as the black vertices in its subtree, and update our total if they are equal. Remember to include the color of the vertex itself in these counts. The answer is the answer at the root.

Therefore the problem is solved in O(n)
 time.
