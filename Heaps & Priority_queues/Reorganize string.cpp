//PROBLEM LINK: https://leetcode.com/problems/reorganize-string
//TC: O(N) + O(LOGK) SC: O(N)
class Solution {
public:
    string reorganizeString(string s) {
        map<char,int> mp;
        for(auto it:s) mp[it]++;
        int maxi=INT_MIN;
        int n=s.size();
        priority_queue<pair<int,char>> pq;
        for(auto it:mp){
            maxi = max(maxi,it.second);
            pq.push({it.second,it.first});

        }
        int midlen = (n+1)/2;
        if(maxi>midlen){
            cout<<"hi\n";
            return "";
        }
        int len=0;
        string ans="";
        
        while(!pq.empty()){
                char charused = pq.top().second;
                int count = pq.top().first;
                pq.pop();
                if(ans=="" or ans[ans.size()-1]!=charused){
                    len++;
                    ans+=charused;
                    count--;
                    if(count>0) pq.push({count,charused});
                    
                }else{
                    if(pq.empty()){
                        cout<<"here\n";
                        return "";
                    } 
                    char nextchar = pq.top().second;
                    int curcount = pq.top().first;
                    pq.pop();
                    ans+=nextchar;
                    curcount--;
                    if(curcount>0){
                        pq.push({curcount,nextchar});
                    }
                    
                    pq.push({count,charused});  //gotta push back the removed ineligible character
                    
                }
            
        }
        
        return ans;
    }
};
/*Explanation: 
if the count of any character exceeds half the length of the string (i.e. if it appears more than ceil(length/2) times), it is not possible to rearrange the characters,
Initialize an empty list ans to store the rearranged characters.
Create a priority queue pq using a heap data structure. Each element in pq is a tuple containing the count of a character and the character itself. The priority queue is ordered in a way such that elements with higher counts have higher priority.
Pop the element with the highest priority from pq. Assign its count and character to count_first and char_first respectively.
If ans is empty or the current character char_first is different from the last character in ans, append char_first to ans. If the count of char_first is not zero, update its count by decreasing it by one and push it back to pq. Continue to the next iteration.
Otherwise, if char_first is the same as the last character in ans, it means we need to choose a different character. If pq is empty, return an empty string as it is impossible to rearrange the characters.
Pop the next element from pq, assigning its count and character to count_second and char_second respectively. Append char_second to ans.
If the count of char_second is not zero, update its count by decreasing it by one and push it back to pq.
Finally, push the original char_first back to pq.
Return the rearranged characters as a string by joining the elements in ans.*/
