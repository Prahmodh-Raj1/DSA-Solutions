//problem link: https://leetcode.com/problems/find-the-safest-path-in-a-grid
//TC: O(N*M*K*LOG(N*K))
import java.util.*;

class Solution {
    public int maximumSafenessFactor(List<List<Integer>> grid) {
        // Create a priority queue to store cells in descending order of their safeness factor.
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> (b[2] - a[2]));
        
        // Store the positions of cells containing thieves.
        List<int[]> thiefPositions = new ArrayList<>();
        
        // Find the minimum manhattan distance from the starting cell (0,0) to any thief.
        int minDistanceToThief = Integer.MAX_VALUE;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.get(0).size(); j++) {
                if (grid.get(i).get(j) == 1) {
                    thiefPositions.add(new int[]{i, j});
                    minDistanceToThief = Math.min(minDistanceToThief, i + j);
                }
            }
        }
        
        // Add the starting cell (0,0) to the priority queue with its safeness factor (minimum distance to a thief).
        pq.add(new int[]{0, 0, minDistanceToThief});
        
        int n = grid.size();
        int m = grid.get(0).size();
        boolean[][] visited = new boolean[n][m];
        visited[0][0] = true;
        
        // If the starting cell or the destination cell contains a thief, the maximum safeness factor is 0.
        if (grid.get(0).get(0) == 1 || grid.get(n - 1).get(m - 1) == 1) {
            return 0;
        }
        
        // Explore the cells in the grid using BFS until reaching the destination cell or all possible paths are considered.
        while (!pq.isEmpty()) {
            int[] currentCell = pq.remove();
            
            // If we reach the destination cell, return its safeness factor.
            if (currentCell[0] == n - 1 && currentCell[1] == m - 1) {
                return currentCell[2];
            }
            
            // Explore adjacent cells and add them to the priority queue if they are not thieves and not visited before.
            // Update their safeness factor based on the minimum distance to any thief.
            int[][] directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            for (int[] direction : directions) {
                int newRow = currentCell[0] + direction[0];
                int newCol = currentCell[1] + direction[1];
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && !visited[newRow][newCol] && grid.get(newRow).get(newCol) != 1) {
                    int newSafeness = Math.min(currentCell[2], getDistanceToThief(thiefPositions, newRow, newCol));
                    pq.add(new int[]{newRow, newCol, newSafeness});
                    visited[newRow][newCol] = true;
                }
            }
        }
        
        // If no valid path is found, return 0.
        return 0;
    }
    
    // Calculate the minimum manhattan distance from the cell (x, y) to any thief in the grid.
    public int getDistanceToThief(List<int[]> thiefPositions, int x, int y) {
        int minDistance = Integer.MAX_VALUE;
        for (int[] thief : thiefPositions) {
            int distance = Math.abs(x - thief[0]) + Math.abs(y - thief[1]);
            minDistance = Math.min(minDistance, distance);
        }
        return minDistance;
    }
}
