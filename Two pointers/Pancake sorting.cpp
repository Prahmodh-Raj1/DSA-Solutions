//Prob link: https://leetcode.com/problems/pancake-sorting
//TC: O(N^2) SC: O(1)
class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        if(is_sorted(arr.begin(),arr.end())){
            return vector<int>();
        }
        vector<int> res;
        int n=arr.size();
        int j;
        for(int i=n;i>0;i--){
            for(j=0;arr[j]!=i;j++);
            reverse(arr.begin(),arr.begin()+j+1);
            res.push_back(j+1);
            reverse(arr.begin(),arr.begin()+i);
            res.push_back(i);
        }
        return res;
    }
};
