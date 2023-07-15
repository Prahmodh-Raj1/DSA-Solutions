//Problem link: https://leetcode.com/problems/bag-of-tokens
//TC: O(NlogN) SC: O(1)
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score=0;
        sort(tokens.begin(),tokens.end());
        int l=0,r=tokens.size()-1;
        while(l<=r){
            int left = tokens[l];
            int right = tokens[r];
            if(power>=tokens[l]){
                score++;
                power-=tokens[l];
                l++;
            
            }else{
                //only  decrease score and increase power
                if(score>0 and l!=r){
                    power+=right;
                    
                    score--;
                }
                r--;
                
            }
        }
        return score;
    }
};
