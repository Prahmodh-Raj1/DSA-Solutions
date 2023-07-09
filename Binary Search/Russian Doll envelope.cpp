//problem link: https://leetcode.com/problems/russian-doll-envelopes/description/
//TC: O(NlogN) sc: o(n)
class Solution {
private:
    static bool comp(vector<int>& v1,vector<int>& v2){
        if(v1[0]==v2[0]){
            return v1[1]>v2[1];  //if two widths are same, sort them by decreasing order of height to ensure that no width is counted more than once, to remove duplicacy
        }
        return v1[0]<v2[0];
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),comp);
        //we do LIS on the heights
        int n= envelopes.size();
        
        vector<int> lis;
        //we need to accommodate a smaller envelope in a larger one, which can be achieved by sorting by widths and running LIS on the heights
        int len=1;
        for(int i=0;i<n;i++){
            if(i==0){
                lis.push_back(envelopes[i][1]);
                continue;
            }
            if(envelopes[i][1]>lis.back()){
                lis.push_back(envelopes[i][1]);
                len++;
            }else{
                int ind = lower_bound(lis.begin(),lis.end(),envelopes[i][1]) - lis.begin();
                lis[ind]=envelopes[i][1];
            }
        }
        return len;
    }
};
