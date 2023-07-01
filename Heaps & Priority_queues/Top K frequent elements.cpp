//Problem link: https://leetcode.com/problems/top-k-frequent-elements
//TC : O(KlogN) SC: O(N) + o(k)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto it:nums) mp[it]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto it:mp){
            auto freq = it.second;
            int val = it.first;
            pq.push({freq,val});
            if(pq.size()>k) pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
            
        }
        return ans;
    }
};
