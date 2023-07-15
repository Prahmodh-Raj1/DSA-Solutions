//Problem link: https://leetcode.com/problems/number-of-adjacent-elements-with-the-same-color/description/
//Tc: O(N+M) SC: O(N)
class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        int cnt=0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[i]=0;
        }
        for(auto it:queries){
            int ind = it[0];
            int col = it[1];
            //checking left side
            int prev;
            if(ind>0){
                prev=mp[ind-1];
            }else prev=0;
            int next=0;
            if(ind<n-1){
                next=mp[ind+1];
            }
            if(mp[ind]!=0 and mp[ind]==prev) cnt--;
            if(mp[ind]!=0 and mp[ind]==next) cnt--;
            //checking right side
            

            mp[ind]=col;
            if(mp[ind-1]==col){
                cnt++;
            }
            if(mp[ind+1]==col){
                cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
