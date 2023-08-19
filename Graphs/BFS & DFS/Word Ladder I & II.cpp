//Prob link: https://leetcode.com/problems/word-ladder/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> mp;
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        for(string str: wordList){
            mp[str]++;
        }
        while(!q.empty()){
            pair<string,int> cur = q.front();
            string curword = cur.first;
            int steps = cur.second;
            if(curword==endWord) return steps;
            q.pop();
            for(int i=0;i<curword.size();i++){
                char orig = curword[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    curword[i] = ch;
                    // check if it exists in the set and push it in the queue.
                    if (mp.find(curword) != mp.end())
                    {
                        mp.erase(curword);
                        q.push({curword, steps + 1});
                    }
                }
                curword[i]=orig;
            }
            
        }
        return 0;
    }
};
