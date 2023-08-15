//Prob link: https://leetcode.com/problems/permutation-sequence/
//TC: O(N^2) SC: O(N)
class Solution {
private:
    //TC: O(N*N) SC: O(N)
    
    
public:
    string getPermutation(int n, int k) {
        int fact=1; //stores (n-1)!
        vector<int> nums;
        for(int i=1;i<n;i++){
            fact*=i;
            nums.push_back(i);
        }
        nums.push_back(n); 
        string ans="";
        k--;  //since we are using 0-based indexing
        while(true){
            ans+=to_string(nums[k/fact]);
            nums.erase(nums.begin()+k/fact); //removing that particular element that has been added
            if(nums.size()==0) break;
            k=k%fact;
            fact = fact/nums.size(); //reducing the window of elements to be chosen from
        }
        return ans;

    }
};
