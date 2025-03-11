//Problem link: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters
//TC: O(N) SC: O(1)

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int i=0,j=0;
        int ans=0;
        int a=0,b=0,c=0;
        for(;j<n;j++){
            if(s[j]=='a') a++;
            if(s[j]=='b') b++;
            if(s[j]=='c') c++;
            while(a>=1 && b>=1 && c>=1){
                ans+= 1 + (n-j-1);  //the remaining characters make up the rest of the valid substrings
                // 1 = current substring, (n-j-1): remaining characters in string, that will anyways hold true coz condition's already satisfied
                if(s[i]=='a'){
                    a--;
                }
                if(s[i]=='b'){
                    b--;
                }
                if(s[i]=='c'){
                    c--;
                }
                i++;
            }

        }
        return ans;
    }
};
