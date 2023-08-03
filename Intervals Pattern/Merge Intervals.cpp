//Problem link: https://leetcode.com/problems/merge-intervals
//TC: O(Nlogn)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int n = intervals.size();
        if(n==1){
            vector<int> temp = {intervals[0][0],intervals[0][1]};
            
            ans.push_back(temp);
            return ans;
        }
        ans.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=ans.back()[1]){  //overlapping interval,prev end checked with curstart
                ans.back()[1] = max(ans.back()[1],intervals[i][1]);
            }else{  //non overlapping interval
                ans.push_back(intervals[i]);
            }
        }
        
        return ans;
    }
};
