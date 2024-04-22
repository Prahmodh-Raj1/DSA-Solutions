//Problem link: https://leetcode.com/problems/open-the-lock
//TC: O(10000 AT MAX) SC: O(N)
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
       unordered_set<string> st(begin(deadends),end(deadends));
       if(st.find("0000")!=st.end()) return -1;
       st.insert("0000");
       
       queue<pair<string,int>> q;
       q.push({"0000",0});
       //int xor=0;
       string temp1="",temp2="";
       while(!q.empty()){
        auto it = q.front();
        q.pop();
        if(it.first==target) return it.second;
        for(int i=0;i<4;i++){
            //switch forwards
            int digf = ((it.first[i]-'0')+1)%10;
            temp1 = it.first;
            temp1[i] = char(digf+48);
            //switch backwards
            int digb = ((it.first[i]-'0')-1)%10;
            if(digb<0) digb+=10;
            temp2 = it.first;
            temp2[i] = char(digb+48);
            if(st.find(temp1)==st.end()){
                q.push({temp1,it.second+1});
                st.insert(temp1);
            }
            if(st.find(temp2)==st.end()){
                q.push({temp2,it.second+1});
                st.insert(temp2);
            }
            
            
        }
       }
       return -1; 
    }
};
