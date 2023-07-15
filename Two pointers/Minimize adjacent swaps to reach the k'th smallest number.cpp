//Problem link: https://leetcode.com/problems/minimum-adjacent-swaps-to-reach-the-kth-smallest-number/
//TC: O(N*K) SC: O(N)
class Solution {
public:
    int getMinSwaps(string num, int k) {
        string original = num;
        for(int  i=1;i<=k;i++){
            next_permutation(num.begin(),num.end());  //finding the k'th permutation of the string
        }
        int n = original.size();
        
        int i=0,j=0;
        int cnt=0;
        while(i<n){  //finding the minimum swaps to convert the 
            j=i;
            while(original[j]!=num[i]) j++;
            while(i<j){
                swap(original[j],original[j-1]);
                cnt++;
                j--;
            }
            i++;
        }
        return cnt;
    }
};
