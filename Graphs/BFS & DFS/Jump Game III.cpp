//Problem link: https://leetcode.com/problems/jump-game-iii/
//TC: O(N) SC: O(N)
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int> q;
        q.push(start);
        vector<bool> vis(n,false);
        vis[start]=true;
        while(!q.empty()){
            int pos = q.front();
            q.pop();
            if(arr[pos]==0) return true;
            //addition
            if(pos+arr[pos]<n && !vis[pos+arr[pos]]){
              q.push(pos+arr[pos]);
              vis[pos+arr[pos]]=true;
            }

            //subtraction
            if(pos-arr[pos]>=0 && !vis[pos-arr[pos]]){
              q.push(pos-arr[pos]);
              vis[pos-arr[pos]]=true;
            }
        }
        return false;
    }
};
