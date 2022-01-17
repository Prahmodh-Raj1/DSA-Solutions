//https://leetcode.com/problems/boats-to-save-people/
//TC :O(NLOGN) SC:O(1)
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        if(people.size()==1){
            return 1;
        }
        sort(people.begin(),people.end());
        int ans=0;
        int i=0,j=people.size()-1;
        //bool flag=false;
        while(i<=j){
            if(people[i]+people[j]<=limit){
                ans++;
                i++;
                j--;
            }else{
                ans++;
                j--;
            }
        }
        return ans;
    }
};
