//Problem link: https://leetcode.com/problems/word-ladder/
//TC:O(Len(Word)*26*N*Logn)  SC :0(N)
class Solution {
public:
    int ladderLength(string bg, string end, vector<string>& word) {
        set<string> st;
        for(auto it:word) st.insert(it); 
        st.erase(bg);
        queue<pair<string,int>> q;
        q.push({bg,1});
        while(!q.empty()){
            string cur=q.front().first;
            int steps=q.front().second;
            q.pop();
            
            if(cur==end){
                return steps;
            }
            int n=cur.length();
            for(int i=0;i<n;i++){
                char orig=cur[i];
                for(int j=0;j<26;j++){
                    cur[i]=(char)(j+'a');
                    if(st.find(cur)!=st.end()){
                        q.push({cur,steps+1});
                        st.erase(cur);
                    }
                }
                cur[i]=orig;
            }
        }
        return 0;   
    }
};
