//Problem link: https://leetcode.com/problems/minimum-time-to-complete-trips/
//TC:O(NlogV) SC: O(1), V: 1e14
class Solution {
public:
    long long check(vector<int>& time,long long mid){
        long long total=0;
        for(auto it:time){
            total+=(mid/it);
        }
        return total;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        sort(time.begin(),time.end());
        long long low=1,high=1e14;
        while(low<high){
            long long mid=(low+high)/2;
            if(check(time,mid)<totalTrips){
                low=mid+1;
            }else{
                high=mid;
            }
        }
        return low;
    }
};
