//Problem link: https://leetcode.com/problems/find-the-punishment-number-of-an-integer/
//TC: O(N* 2^6) SC: O(N) - Auxillary stack space
class Solution {
public:
    bool canPartition(string s, int target)
    {
        if (s == "" && target == 0) return true;
        if (target < 0) return false;
        
        bool ans = false;
       
        for (int i = 0; i < s.size(); i++) //try all possible pivot points
        {
            string left = s.substr(0, i + 1); //keep the left part
            string right = s.substr(i + 1); //recurse for right  part
            int leftNum = stoi(left);
            
            bool isPossible = canPartition(right, target - leftNum);
            if (isPossible) { ans = true; break; }
        }
        
        return ans;
    }
    int punishmentNumber(int n)
    {
        int sum = 0;
        for (int num  = 1; num <= n; num++)
        {
            int sqr = num * num;
            if (canPartition(to_string(sqr), num)) 
            {
                sum += sqr;
            }
        }
        return sum;
    }
};
//More efficient approach
class Solution {
public:
    bool canPartition(string s, int target,int ind)
    {
        if (ind==s.size() && target == 0) return true;
        if (target < 0) return false;
        
        int leftval=0;
       bool ans=false;
        for (int i = ind; i < s.size(); i++) //try all possible pivot points
        {
            leftval = 10*leftval + (s[i]-'0');  //keeping the left
            bool isPossible = canPartition(s, target - leftval,i+1);
            if (isPossible) { ans = true; break; }
        }
        
        return ans;
    }
    int punishmentNumber(int n)
    {
        int sum = 0;
        for (int num  = 1; num <= n; num++)
        {
            int sqr = num * num;
            string val = to_string(sqr);
            if (canPartition(val, num,0)) 
            {
                sum += sqr;
            }
        }
        return sum;
    }
};
