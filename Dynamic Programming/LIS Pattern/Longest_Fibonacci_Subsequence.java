//Problem link: https://leetcode.com/problems/length-of-longest-fibonacci-subsequence
//TC: O(N^2) SC:O(N^2)
class Solution {
    public int lenLongestFibSubseq(int[] arr) {
        int dp[][] = new int[arr.length][arr.length]; //dp[i][j] 

        //dp[i][j] represents the longest fibo sequence with last two terms as a[i] and a[j]
        for (int[] r : dp)
            Arrays.fill(r, 2);
        Map<Integer,Integer> mp = new HashMap<>(); //stores {value,index}
        int maxi=0;
        for(int i=0;i<arr.length;i++){
            mp.put(arr[i],i);
        }
        for(int i=1;i<arr.length;i++){
            //for each arr[i], find two elements that sum up to arr[i] - Two sum
            for(int prev=0;prev<i;prev++){
                // x + arr[prev] = arr[i]
                //x = arr[i] - arr[prev]
                int x = arr[i]-arr[prev];
                if(mp.containsKey(x)==true && mp.get(x)<prev){
                    dp[prev][i] = Math.max(dp[prev][i],dp[mp.get(x)][prev]+1);
                }
                maxi = Math.max(maxi,dp[prev][i]);
            }
        }

        if(maxi>2){
            return maxi;
        }
        return 0;
    }
}
