//Problem link: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days
//TC: O(NLOGV) SC: O(1)
class Solution {
public:
    
    bool feasible(vector<int>& weights, int c, int days) {
        int daysNeeded = 1, currentLoad = 0;
        for (int weight : weights) {
            currentLoad += weight;
            if (currentLoad > c) {
                daysNeeded++;
                currentLoad = weight;
            }
        }

        return daysNeeded <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int totalLoad = 0, maxLoad = 0;
        for (int weight : weights) {
            totalLoad += weight;
            maxLoad = max(maxLoad, weight);
        }

        int l = maxLoad, r = totalLoad;

        while (l < r) {
            int mid = (l + r) / 2;
            if (feasible(weights, mid, days)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
