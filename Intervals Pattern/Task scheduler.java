//Problem link: https://leetcode.com/problems/task-scheduler
class Solution {
    public int leastInterval(char[] tasks, int n) {
        //Answer is  the number of idles + number of tasks
        int len = tasks.length;
        //the number of idles is the number of idles taken for the task with the most frequency
       /* First count the number of occurrences of each element.
Let the max frequency seen be M for element E
We can schedule the first M-1 occurrences of E, each E will be followed by at least N CPU cycles in between successive schedules of E
Total CPU cycles after scheduling M-1 occurrences of E = (M-1) * (N + 1) // 1 comes for the CPU cycle for E itself
Now schedule the final round of tasks. We will need at least 1 CPU cycle of the last occurrence of E. If there are multiple tasks with frequency M, they will all need 1 more cycle.
Run through the frequency dictionary and for every element which has frequency == M, add 1 cycle to result.
If we have more number of tasks than the max slots we need as computed above we will return the length of the tasks array as we need at least those many CPU cycles.*/
        Map<Character,Integer> mp = new HashMap<>();
        int maxfreq=1;
        for(char ch: tasks){
            if(mp.containsKey(ch)){
                int val = mp.get(ch);
                mp.put(ch,val+1);
                maxfreq = Math.max(maxfreq,val+1);
            }else mp.put(ch,1);
        }
        int curans = (maxfreq-1)*(n+1);
        for(char ch: mp.keySet()){
            if(mp.get(ch)==maxfreq) curans++;
        }
        return Math.max(len,curans);
    }
}
