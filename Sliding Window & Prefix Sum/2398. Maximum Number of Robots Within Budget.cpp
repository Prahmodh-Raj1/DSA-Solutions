//Problem link:https://leetcode.com/contest/biweekly-contest-86/problems/maximum-number-of-robots-within-budget/
//TC:O(NLOGN) SC:O(N)
class Solution {
public:
    int maximumRobots(vector<int>& c, vector<int>& r, long long budget) {
        multiset<int> st;
        int n=c.size();
        int i,j=0;
        long long sum=0;
        for(i=0;i<n;i++){
            sum+=r[i];
            st.insert(c[i]);
            if((i-j+1)*sum + *rbegin(st) > budget){
                sum-=r[j];
                st.erase(st.find(c[j]));
                j++;
            }
        }
        return i-j;
    }
};
