//Problem link: https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/description/
//TC: O(nlog(maxi)) SC: O(1)
class Solution {
public:
    bool check(int mid,vector<int>& qt,int n){
        int cnt=0;
        for(auto it:qt){
            cnt+=((it+mid-1)/mid);  //COUNTING THE NUMBER OF STORES THAT WE CAN DISTRIBUTE TO the stores
        }
        return cnt<=n;  //checking if we have enough number of stores
    }
    int minimizedMaximum(int n, vector<int>& qt) {
        int low=1,high=*max_element(qt.begin(),qt.end());
        while(low<high){
            int mid = (low+high)/2;
            if(check(mid,qt,n)){
                high=mid;
            }else low=mid+1;
        }
        return low;
    }
};
