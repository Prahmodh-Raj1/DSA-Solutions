//Problem link: https://leetcode.com/problems/heaters/
//TC: O(MlogN) SC: O(1)
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
    sort(heaters.begin(), heaters.end());
    int minRadius = 0;
    for (int i = 0; i < houses.size(); i++) {
    	// search for the closest heater whose position is at least the current house's position
    	auto larger = lower_bound(heaters.begin(), heaters.end(), houses[i]);
    	int curRadius = INT_MAX;
    	// if there is such a heater, update the radius for that heater to cover this house if necessary
    	if (larger != heaters.end())
    	    curRadius = *larger - houses[i];
    	// if the heater we found is not the first one, then the previous heater is the closest heater
    	// whose position is smaller than the current house's position
    	if (larger != heaters.begin()) {
    	    auto smaller = larger - 1;
    	   // the heater with the smaller required radius to cover the house wins
    	    curRadius = min(curRadius, houses[i] - *smaller);
    	}
    	minRadius = max(minRadius, curRadius);
    }
    return minRadius;
}
};
