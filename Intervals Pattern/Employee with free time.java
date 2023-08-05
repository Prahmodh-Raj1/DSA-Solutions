//Problem link: https://www.lintcode.com/problem/850/description
/**
 * Definition of Interval:
 * public class Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this.start = start;
 *         this.end = end;
 *     }
 * }
 */

public class Solution {
    /**
     * @param schedule: a list schedule of employees
     * @return: Return a list of finite intervals 
     */
    public List<Interval> employeeFreeTime(int[][] schedule) {
        // Write your code here
        List<Interval> result = new ArrayList<>();
        List<Interval> timeLine = new ArrayList<>();
        int n = schedule.length;
        for(int i=0;i<n;i++){
            for(int j=0;j<schedule[i].length;j+=2){
                timeLine.add(new Interval(schedule[i][j], schedule[i][j+1]));
            }
        }
        Collections.sort(timeLine, ((a, b) -> a.start - b.start));

        Interval temp = timeLine.get(0);
        for (Interval each : timeLine) {
            if (temp.end < each.start) {
                result.add(new Interval(temp.end, each.start));
                temp = each;
            } else {
                temp = temp.end < each.end ? each : temp;
            }
        }
        return result;
    }
};
