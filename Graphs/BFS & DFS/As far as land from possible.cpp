//Problem link: https://leetcode.com/problems/as-far-from-land-as-possible
//TC: O(N^2) SC: O(N^2)
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        //Note: The copy matrix visited can be avoided by updating the original matrix grid but changing the input parameter is not considered under good practices. That's why we are taking extra 2d matrix visited
        vector<vector<int>> visited = grid;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == 1) 
                    q.push({i, j});  //perform bfs from 1
            }
        }
        if (q.empty() || q.size() == n * n) 
            return -1;  //no 1's or all 1's
        int distance = -1;
        // visit all four direction i.e. right, left, up, down
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty()) {
            int size = q.size();
            while (size--) { //running level by level
                auto [x, y] = q.front();
                q.pop();
                for (auto [dx, dy] : dirs) {
                    int i = x + dx, j = y + dy;
                    if (i >= 0 && i < n && j >= 0 && j < n && visited[i][j] == 0) {
                        visited[i][j] = 1;
                        q.push({i, j});
                    }
                }
            }
            distance++;
        }
        return distance;
    }
};
//Explanation: https://leetcode.com/problems/as-far-from-land-as-possible/solutions/3166138/day-41-c-bfs-easiest-beginner-friendly-approach-o-n-2-time-and-o-n-2-approach/
