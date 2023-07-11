//Problem link: https://leetcode.com/problems/reverse-vowels-of-a-string/
//TC: O(N)  SC:O(1)
class Solution {
public:
    string reverseVowels(string s) {
        int n=s.size();
        int i=0,j=n-1;
        unordered_map<char,int> mp;
        mp['a']=1;
        mp['e']=1;
        mp['A']=1;
        mp['E']=1;
        mp['O']=1;
        mp['o']=1;
        mp['i']=1;
        mp['I']=1;
        mp['U']=1;
        mp['u']=1;
        for(auto it:mp) cout<<it.first<<" "<<it.second<<"\n";
        
        while(i<j){
            //cout<<i<<" "<<j<<"\n";
            while(mp.find(s[i])==mp.end() and i<j){
                i++;
            }
            while(mp.find(s[j])==mp.end() and i<j){
                j--;
            } 
            
            char temp = s[i];
            s[i]=s[j];
            s[j]=temp;
            i++;
            j--;
        }
        return s;

    }
};
