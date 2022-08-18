/*
    Problems Link : https://leetcode.com/problems/unique-paths-ii/
    TC - O(row*col)
    SC - O(row*col) + O(min(row, col)) Recursion Stack Memory.
*/

class Solution {
private:
    int helper(int r, int c, int row, int col, vector<vector<int>>& grid, vector<vector<int>>& DP){
        if(r<0 || r == row || c<0 || c == col || grid[r][c] == 1) return 0;
        if(r == row-1 && c == col-1){
            return 1;
        }
      
        int& cache = DP[r][c];
        if(cache != -1){
            return cache;
        }

        int way1, way2;
        way1 = helper(r, c+1, row, col, grid, DP);
        way2 = helper(r+1, c, row, col, grid, DP);
        return cache = (way1 + way2);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size(), col = obstacleGrid[0].size();
        vector<vector<int>> DP(row, vector<int>(col, -1));
        return helper(0, 0, row, col, obstacleGrid, DP);
    }
};