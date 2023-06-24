//Problem link: 
//TC:O(Nlog(Max)) SC:O(1)
class Solution {
public:
    bool feasible(vector<int>& piles,int mid,int h){
        int cnt=0;
        int sum=0;
        for(auto it:piles){
            int val=(it+mid-1)/mid;
            cnt+=val;
        }
        return cnt<=h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        low=(long long)low;
        high=(long long)high;
        while(low<high){
            long long mid=(low+high)/2;
            if(feasible(piles,(int)mid,h)){
                high=mid;
            }else{
                low=mid+1;
            }
        }
        return low;
        
    }
};
