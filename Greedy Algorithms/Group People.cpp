//Problem link: https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to
//TC: O(N^2) SC: O(N)
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& grp) {
        vector<vector<int>> ans;
        map<int,vector<int>> mp;
        int n = grp.size();
        for(int ind=0;ind<n;ind++){
            mp[grp[ind]].push_back(ind);
        }
        for(auto it:mp){
            cout<<it.first<<"-";
            for(auto t:it.second) cout<<t<<" ";
            cout<<"\n";
            vector<int> temp = it.second;
            int groups = it.second.size()/it.first;
            int i=0;
            for(int j=0;j<groups;j++){
                vector<int> cur;
                int k=j*it.first;
                while(cur.size()<it.first){
                    cur.push_back(temp[k++]);
                }

                ans.push_back(cur);
            }
        }
        return ans;
    }
};
