//Prob link: https://leetcode.com/problems/nth-magical-number/
//TC: O(log(1e14)) SC: O(1)
class Solution {
public:
    const int mod = 1e9+7;
    long long gcd(long long a, long long b)
{
    return b == 0 ? a : gcd(b, a % b);   
}
    bool check(long long mid,int n,int a,int b){
        long long hcf = gcd((long long)a,(long long)b);
        long long lcm = (a*b)/hcf;
    
        long long ans = (mid/a) + (mid/b) - (mid/lcm); //inclusion exclusion principle
        return ans>=n;
    }
    int nthMagicalNumber(int N, int A, int B) {
        long lcm = A * B / __gcd(A, B), l = 2, r = 1e14, mod = 1e9 + 7;
        while (l < r) {
            long m = (l + r) / 2;
            if (m / A + m / B - m / lcm < N) l = m + 1;
            else r = m;
        }
        return l % mod;
    }
};
