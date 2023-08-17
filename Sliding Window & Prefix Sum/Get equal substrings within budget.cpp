//Prob link: https://leetcode.com/problems/get-equal-substrings-within-budget
//TC: O(N) SC: O(1)
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int maxlen=0;
        int n = s.size();
        int i=0,j=0;
        int cost=0;
        for(j=0;j<n;j++){
            cost+=abs((s[j]-'a')-(t[j]-'a'));
            while(cost>maxCost){
                cost-=abs((s[i]-'a')-(t[i]-'a'));
                i++;
            }
            maxlen = max(maxlen,j-i+1);
        }
        return maxlen;
    }
};
