//problem link: https://www.codingninjas.com/studio/problems/reverse-the-order-of-words-in-a-string_1264991?leftPanelTab=1
//tc: o(n) sc:o(1)
#include<bits/stdc++.h>
void reverseString(string& str,int start,int end){
    while(start<end){
        char temp = str[start];
        str[start]=str[end];
        str[end]=temp;
        start++; end--;
    }
}
string reverseOrderWords(string str) {
    // Write your code here
    int n = str.size();
    reverse(str.begin(),str.end());
    int start=0,end=0;
    while(end<n){
        if(str[end]!=' ') end++;
        else{
            reverseString(str,start,end-1);
            start=end+1;
            end++;
        }
    }
    //str+=' ';
    reverseString(str,start, end-1);
    return str;
    
}
