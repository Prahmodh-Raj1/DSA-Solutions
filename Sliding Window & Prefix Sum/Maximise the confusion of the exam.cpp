//PROB link: https://leetcode.com/problems/maximize-the-confusion-of-an-exam
//TC: O(2*N) SC: O(1)
class Solution {
private:
    int findMaxConsecutiveValues(string s,char ch,int k){
        int cnt=0;
        int n=s.size();
        int i=0,j=0;
        int maxcount=0;
        for(j=0;j<n;j++){
            if(s[j]==ch) cnt++;
            while(i<=j && cnt>k){
                if(s[i]==ch) cnt--;
                i++;
            }
            maxcount = max(maxcount,j-i+1);
        }
        return maxcount;
    }
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        
        return max(findMaxConsecutiveValues(answerKey,'T',k),findMaxConsecutiveValues(answerKey,'F',k));
        
    }
};
