//problem link:https://leetcode.com/problems/combinations
//TC: O(K* nCk)  
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> >res;
        if(n<k)return res;
        vector<int> temp;
        combine(res,temp,0,0,n,k);
        return res;
    }
    
    void combine(vector<vector<int> > &res,vector<int> &temp,int start,int num,int n ,int k){
        if(num==k){
            res.push_back(temp);
            return;
        }
        for(int i = start;i<n;i++){
            temp.push_back(i+1);  //including that element  
            combine(res,temp,i+1,num+1,n,k);  //incrementing the count of the element chosen so far
            temp.pop_back(); //removing that element
            }
        }
};
