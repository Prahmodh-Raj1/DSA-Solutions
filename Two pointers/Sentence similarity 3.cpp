//Problem link: 
https://leetcode.com/problems/sentence-similarity-iii/
//TC: O(N) Sc: O(N)
class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        int n1 = sentence1.size();
        int n2 = sentence2.size();
        deque<string> dq1,dq2;
        string temp="";
        for(auto it:sentence1){
            if(it==' '){
                dq1.push_back(temp), temp="";
            } 
            else temp+=it;
        }
        dq1.push_back(temp);
        temp="";
        for(auto it:sentence2){
            if(it==' ') dq2.push_back(temp), temp="";
            else temp+=it;
        }
        dq2.push_back(temp); 
        //removing the common words from the  front
        while(!dq1.empty() and !dq2.empty() and (dq1.front()==dq2.front())){
            dq1.pop_front();
            dq2.pop_front();
        }
        //removing commond words from the back
        while(!dq1.empty() and !dq2.empty() and (dq1.back()==dq2.back())){
            dq1.pop_back();
            dq2.pop_back();
        }
        return (dq1.empty() || dq2.empty());
    }
};
