//Problem link: https://leetcode.com/problems/non-overlapping-intervals/
class Solution {

public:
    static bool comp(vector<int>& a,vector<int>& b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int cnt=1;
        int n = intervals.size();
        int end=intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]>=end){
                cnt++;
                end = intervals[i][1];
            }
        }
        return n-cnt;
    }
};
