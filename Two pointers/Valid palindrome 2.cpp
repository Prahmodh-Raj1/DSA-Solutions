//Problem link: https://leetcode.com/problems/valid-palindrome-ii
//TC: O(N) SC:O(1)
class Solution {
bool ispalindrome(string s,int l,int r){
    while(l<r){
        if(s[l]!=s[r]) return false;
        l++;
        r--;
    }
    return true;
}
public:
    bool validPalindrome(string s) {
        int i=0, j=s.size()-1;
        //atmost one character mismatch can happen
        bool fl=false;
        while(i<j){
            if(s[i]!=s[j]){
                //then the previous character must match
                return ispalindrome(s,i+1,j) || ispalindrome(s,i,j-1);
            }else{
                i++;
                j--;
            }
        }
        return true;
    }
};
