//Problem link: https://leetcode.com/problems/find-the-winner-of-the-circular-game/
//TC: O(N) SC: Auxillary stack space
class Solution {
private:
    int helper(int n,int k){
        if(n==1) return 0;
        return (helper(n-1,k)+k)%n;  //using the recurrence relation, f(n) = (f(n-1) + k)%n;
    }
public:
    int findTheWinner(int n, int k) {
        return helper(n,k)+1;
    }
};

//TC: O(N)  Sc: O(1)
class Solution {
public:
    int findTheWinner(int n, int k) {
        int res = 1;
        for(int i = 1; i <= n; i++)res = (res+k)%i;
        
        return res+1;
    }
};
