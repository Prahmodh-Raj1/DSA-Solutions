//Problem link: https://leetcode.com/problems/most-beautiful-item-for-each-query/description/
//TC: O(MlogN) SC:O(N)
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int len= queries.size();
        vector<int> ans(len,0);
        int n=items.size();
        vector<int> pref(n);
        sort(items.begin(),items.end());
        pref[0]=items[0][1];
        vector<int> v;
        for(auto it:items) v.push_back(it[0]);
        for(int i=1;i<n;i++){
            pref[i]= max(pref[i-1],items[i][1]);
        }
        for(int i=0;i<len;i++){
            int ind = upper_bound(v.begin(),v.end(),queries[i])-v.begin();
            if(ind==0){
                ans[i]=0;
                continue;
            }
            ans[i]=pref[ind-1];
        }
        return ans;
    }
}; 
