//Problem link: https://leetcode.com/problems/ugly-number-iii/description/
//TC : O(nlog(1e10)) SC: O(1)
/*We need to design an enough function, given an input num, determine whether there are at least n ugly numbers less than or equal to num.
Since a might be a multiple of b or c, or the other way round, we need the help of greatest common divisor to avoid counting duplicate numbers.*/
class Solution {
public:    
   int nthUglyNumber(int k, int A, int B, int C) {
        int lo = 1, hi = 2 * (int) 1e9;
        long a = long(A), b = long(B), c = long(C);
        long ab = a * b / __gcd(a, b);
        long bc = b * c / __gcd(b, c);
        long ac = a * c / __gcd(a, c);
        long abc = a * bc / __gcd(a, bc);
        while(lo < hi) {
            int mid = lo + (hi - lo)/2;
            int cnt = mid/a + mid/b + mid/c - mid/ab - mid/bc - mid/ac + mid/abc;
            if(cnt < k) 
                lo = mid + 1;
            else
			   //the condition: F(N) >= k
                hi = mid;
        }
        return lo;
    }
};
