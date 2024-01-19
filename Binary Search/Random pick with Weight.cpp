//Problem link: https://leetcode.com/problems/random-pick-with-weight
//TC: O(NLOGN) SC: O(N)
class Solution {
public:
    std::vector<int> arr;
    int max = 0;

    Solution(std::vector<int>& w) {
        std::vector<int> temp(w.size());
        temp[0] = w[0];
        max += w[0];

        for (int i = 1; i < w.size(); ++i) {
            temp[i] = temp[i - 1] + w[i];
            max += w[i];
        }

        arr = temp;
    }

    int pickIndex() {
        int rnd = std::rand() % max + 1; // generate random number in [1, max]
        auto it = std::lower_bound(arr.begin(), arr.end(), rnd);

        int ret = std::distance(arr.begin(), it);

        return ret;
    }
};
/*
For a given array: {1,5,2}, we construct the following array (accumulated sum)
{1, 6, 8} generate a number between 1-8 and say all numbers generated up to 1 is index 0. all numbers generated greater than 1 and
  up to 6 are index 1 and all numbers greater than 6 and up to 8 are index 2. After we generate a random number to find which index to
return we use binary search.*/
