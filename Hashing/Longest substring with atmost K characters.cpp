//Problem link: https://www.codingninjas.com/studio/problems/distinct-characters_2221410?leftPanelTab=0
//TC: O(N) SC: O(N)
//
#include<bits/stdc++.h>
using namespace std;
int kDistinctChars(int k, string &s)
{
    // Write your code here
    int n = s.size();
    int ans=0;
    int i=0,j=0;
    map<char,int> mp;  //stores character,frequency
    while(j<n){
        mp[s[j]]++;  //increment the frequency
        while(mp.size()>k){  //sliding through the window when we find more no. of characters
            mp[s[i]]--;
            if(mp[s[i]]==0){  //if it becomes zero, remove it
                mp.erase(s[i]);
            }
            i++;
        }
        
        ans=max(ans,j-i+1);  //marking the answer at each step
        j++;
        
    }
    return ans;
}


