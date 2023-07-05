//problem link: https://leetcode.com/problems/prison-cells-after-n-days/
//TC: O(2^6) SC: O(2^6)
//There are 64 different states in total, first and last will become zero at some stage always
/* Description
  There are 8 prison cells in a row and each cell is either occupied or vacant.

Each day, whether the cell is occupied or vacant changes according to the following rules:

If a cell has two adjacent neighbors that are both occupied or both vacant, then the cell becomes occupied.
Otherwise, it becomes vacant.
Note that because the prison is a row, the first and the last cells in the row can't have two adjacent neighbors.

You are given an integer array cells where cells[i] == 1 if the ith cell is occupied and cells[i] == 0 if the ith cell is vacant, and you are given an integer n.

Return the state of the prison after n days (i.e., n such changes described above).

 

Example 1:

Input: cells = [0,1,0,1,1,0,0,1], n = 7
Output: [0,0,1,1,0,0,0,0]
Explanation: The following table summarizes the state of the prison on each day:
Day 0: [0, 1, 0, 1, 1, 0, 0, 1]
Day 1: [0, 1, 1, 0, 0, 0, 0, 0]
Day 2: [0, 0, 0, 0, 1, 1, 1, 0]
Day 3: [0, 1, 1, 0, 0, 1, 0, 0]
Day 4: [0, 0, 0, 0, 0, 1, 0, 0]
Day 5: [0, 1, 1, 1, 0, 1, 0, 0]
Day 6: [0, 0, 1, 0, 1, 1, 0, 0]
Day 7: [0, 0, 1, 1, 0, 0, 0, 0]
*/
class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        map<vector<int>,int> mp;
        while(n>0){
            vector<int> cellstemp(8,0);
            mp[cells]=n;  //marking the last time this same cell pattern was found
            n--;
            for(int i=1;i<7;i++){
                if(cells[i-1]==cells[i+1]){
                    cellstemp[i]=1;
                }else cellstemp[i]=0;
                
                
            }
            cells=cellstemp;
            if(mp.find(cells)!=mp.end()){
                n= n % (mp[cells]-n);  //skipping unnecessary repetitive states
            }
            
        }
        return cells;
    }
};
