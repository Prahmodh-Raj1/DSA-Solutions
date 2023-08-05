//Problem link: https://leetcode.com/problems/interval-list-intersections/
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        int n = firstList.size();
        int m = secondList.size();
        int i=0,j=0;
        while(i<n and j<m){
            int start = max(firstList[i][0],secondList[j][0]);
            int end = min(firstList[i][1],secondList[j][1]);
            if(start<=end){
                vector<int> temp;
                temp.push_back(start);
                temp.push_back(end);
                ans.push_back(temp);
            }
            if(firstList[i][1]<secondList[j][1]){
                i++;
            }else if(firstList[i][1]>secondList[j][1]) j++;
            else{
                i++;
                j++;
            }
        }
        return ans;
    }
};
