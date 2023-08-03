//problem link: https://leetcode.com/problems/insert-interval/
//TC: O(N)
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i=0;
        int n = intervals.size();
        vector<vector<int>> ans;
        //case 1: no overlapping case before the merge intervals
		//compare ending point of intervals to starting point of newInterval
        while(i<n && intervals[i][1]<newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }
        //overlapping case and merging of intervals
        while(i<n && newInterval[1]>=intervals[i][0]){
            newInterval[0] = min(newInterval[0],intervals[i][0]);
            newInterval[1] = max(newInterval[1],intervals[i][1]);
            i++;
        }
        
        ans.push_back(newInterval);
        //Case3: no overlapping of intervals before the new interval being merged
        //Adding the remaining intervals that do not interfere/overlap with the newinterval
        while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};
