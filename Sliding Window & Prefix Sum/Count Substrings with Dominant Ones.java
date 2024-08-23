//Problem link:https://leetcode.com/problems/count-the-number-of-substrings-with-dominant-ones

//TC: O(N*Root(N)) SC: O(N)

/*
https://leetcode.com/problems/count-the-number-of-substrings-with-dominant-ones/solutions/5548547/well-explained-very-easy-java
*/
class Solution {
    public int numberOfSubstrings(String s) {
        int n = s.length(); 
        int[] prefix = new int[n]; //array to store prefix sums of '1's

        prefix[0] = ((int)(s.charAt(0) - '0')) == 1 ? 1 : 0;
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + (((int)(s.charAt(i) - '0')) == 1 ? 1 : 0);
        }

        int ans = 0;

        
        for (int i = 0; i < n; i++) { //i => starting index of substring

            int one = 0; // Count of '1's in the current substring
            int zero = 0; // Count of '0's in the current substring

            for (int j = i; j < n; j++) { // j=> ending index of current substring

                one = prefix[j] - (i == 0 ? 0 : prefix[i - 1]);
                zero = (j - i + 1) - one;
              
                //CASE->1
                if ((zero * zero) > one) { // Not dominant
                    j += (zero * zero - one - 1);
                } 
                //CASE->2
                else if ((zero * zero) == one) { //just this one is dominant
                    ans++; 
                } 
                //CASE->3
                else if ((zero * zero) < one) { 
                    ans++; 
                    // Calculate the difference to determine how far to skip forward
                    int diff = (int) Math.sqrt(one) - zero;
                    int nextj = j + diff; // Determine the next position to skip to

                    if (nextj >= n) {
                        ans += (n - j - 1);
                    } else {
                        ans += diff; 
                    }

                    j = nextj; // Update j to the next position
                }
            }
        }
        return ans; // Return the final answer
    }
}
