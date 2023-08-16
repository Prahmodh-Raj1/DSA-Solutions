//Prob link: https://leetcode.com/problems/zigzag-conversion
//TC : O(N*nUmrows) SC: O(N)
class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> vs(numRows, "");
        int n = s.length(), i = 0;
        while (i < n) {
            for (int j = 0; j < numRows && i < n; j++)
                vs[j].push_back(s[i++]); //adding the straight columns
            for (int j = numRows - 2; j >= 1 && i < n; j--) //adding the sliding columns, bottom to top
                vs[j].push_back(s[i++]);
        }
        string zigzag;
        for (string v : vs) zigzag += v;
        return zigzag;
    } 
};
