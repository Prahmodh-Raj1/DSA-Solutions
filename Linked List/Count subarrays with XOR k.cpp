//Problem link: https://www.codingninjas.com/studio/problems/count-subarrays-with-given-xor_1115652?leftPanelTab=1
//TC: O(NlogN) sc: O(n)
#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int k)
{
    //    Write your code here.
    map<int,int> mp;
    int cnt=0;
    int xo=0;
    int n=arr.size();
    for(int i=0;i<n;i++){
        xo=xo^arr[i];
        if(mp.find(xo^k)!=mp.end()){
            cnt+=mp[xo^k];
        }
        if(xo==k){
            cnt++;
        }
        mp[xo]++;
    }
    return cnt;
}
