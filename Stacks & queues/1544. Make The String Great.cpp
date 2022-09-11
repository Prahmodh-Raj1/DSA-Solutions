Q.Given a string s of lower and upper case English letters.

A good string is a string which doesn't have two adjacent characters s[i] and s[i + 1] where:

0 <= i <= s.length - 2
s[i] is a lower-case letter and s[i + 1] is the same letter but in upper-case or vice-versa.
To make the string good, you can choose two adjacent characters that make the string bad and remove them. You can keep doing this until the string becomes good.

Return the string after making it good. The answer is guaranteed to be unique under the given constraints.

Notice that an empty string is also good.

 

Example 1:

Input: s = "leEeetcode"
Output: "leetcode"
Explanation: In the first step, either you choose i = 1 or i = 2, both will result "leEeetcode" to be reduced to "leetcode".
Example 2:

Input: s = "abBAcC"
Output: ""
Explanation: We have many possible scenarios, and all lead to the same answer. For example:
"abBAcC" --> "aAcC" --> "cC" --> ""
"abBAcC" --> "abBA" --> "aA" --> ""

#include<bits/stdc++.h>
using namespace std;
int main(){
	    string s="abBAcC";
        int i=0;
        while(s.length()!=0 && i<s.length()-1){
            if((s[i+1]-0) - (s[i]-0) == 32 or (s[i+1]-0) - (s[i]-0)==-32){
                s.erase(i,2);
                i=0;
            }else{
                i++;
            }
        }
        cout<<"answer "<<s<<endl;
        return 0;
    }
    //Another solution
    class Solution {
public:
    string makeGood(string s) {
        int i = 0;
        int j = 1;
        while(s[i] !=NULL and s[j]!=NULL){
            if(s[i] - s[j] == 32 || s[j] - s[i] == 32){
                s.erase(i,2);
                i = i/2;
                j = i+1;
            }

            else{
                i++;
                j++;
            }
        }
        return s;
    }
};
//Faster solution
class Solution {
    public:
    string makeGood(string s) {
        stack<char> temp;
        int i = 0;
        while (i < s.length()) {
            if (temp.empty() == true) {
                temp.push(s[i]);
            } else {
                char top = temp.top();
                char cur = s[i];
                if (top == cur) {
                    temp.push(s[i]);
                } else if (top == toupper(cur) || cur == toupper(top)) {
                    temp.pop();
                } else {
                    temp.push(s[i]);
                }
            }
            i++;
        }
        string ans;
        while (temp.size() != 0) {
            char q = temp.top();
            temp.pop();
            ans += q;
        }

