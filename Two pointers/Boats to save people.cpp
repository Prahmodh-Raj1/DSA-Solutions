//Problem link: https://leetcode.com/problems/boats-to-save-people/
//TC: O(NlogN) SC: O(1)
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int cnt=0;
        int left=0,right=people.size()-1;
        while(left<=right){
            int curweight = people[left]+people[right];
            if(curweight<=limit){
                cnt++;
                left++;
                right--;
            }else{  //reduce the weight
                right--;
                cnt++; //sending only people[l] at this point
            }
        }
        return cnt;
    }
};
