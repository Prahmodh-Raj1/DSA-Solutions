//Prob link: https://leetcode.com/problems/decode-string/
//TC: O(N) SC: O(N)
class Solution {
public:
    string decodeString(string s) {
        stack<string> chars;
        stack<int> nums;
        string res="";
        int num=0;
        for(char c:s){
            if(isdigit(c)){
                num = num*10 + (c-'0');
            }
            else if(isalpha(c)) res+=c;
            else if(c=='['){
                chars.push(res);
                nums.push(num);
                res=""; //starting a new group
                num=0;
            }else{ //']'
                string temp=res;
                for(int i=1;i<=nums.top()-1;i++){
                    res+=temp;
                }
                res = chars.top()+res;
                chars.pop();
                nums.pop();
            }
        }
        return res;
    }
};
