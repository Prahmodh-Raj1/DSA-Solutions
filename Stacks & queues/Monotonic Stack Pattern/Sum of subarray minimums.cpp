//Prob link: https://leetcode.com/problems/sum-of-subarray-minimums
//TC: O(N) SC: O(N)
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        /*Denote by left[i] the distance between element A[i] and its PLE.
Denote by right[i] the distance between element A[i] and its NLE.

The final answer is,
sum(A[i]*left[i]*right[i] )*/
        int n = arr.size();
        vector<int> leftdist(n,0),rightdist(n,0); 
        stack<int> prev,next; //find the prev smaller ele and the next smaller ele for each ele
        int sum=0;
        for(int i=0;i<n;i++) leftdist[i] = i+1;
        for(int i=0;i<n;i++) rightdist[i] = n-i;
        for(int i=0;i<n;i++){
            while(!prev.empty() and arr[prev.top()]>arr[i]){
                prev.pop();
            }
            if(prev.empty()){
                leftdist[i]  = i+1; //there' no prev smaller element
            }else leftdist[i] = i - prev.top();
            prev.push(i);
        }
        
        for(int i=0;i<n;i++){
            while(!next.empty() and arr[next.top()]>arr[i]){
                
                rightdist[next.top()] = i-next.top();
                next.pop();
            }
            next.push(i);
        }
        int mod = 1e9+7;
        for(int i=0;i<n;i++){
            sum = (sum + (long long)((((long long)arr[i] * (long long)leftdist[i])%mod) * rightdist[i])%mod)%mod; 
        }
        return sum;
    }
};
