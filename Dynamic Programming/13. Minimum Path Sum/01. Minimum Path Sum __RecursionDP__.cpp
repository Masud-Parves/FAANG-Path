/*
    Problems Link : https://leetcode.com/problems/minimum-path-sum/
    TC - O(rows*cols)
    SC - O(rows*cols) + O(max(rows, cols)) Recursion Stack Memory.
*/

class Solution {
private:
    int helper(int r, int c, int rows, int cols, vector<vector<int>>& grid, vector<vector<int>>& DP){
        if(r<0 || r == rows || c<0 || c == cols) return INT_MAX/2;
        if(r == rows-1 && c == cols-1){
            return grid[r][c];
        }

        int& cache = DP[r][c];
        if(cache != -1){
            return cache;
        }
        cache = 0;
        int way1, way2;
        way1 = grid[r][c] + helper(r, c+1, rows, cols, grid, DP);
        way2 = grid[r][c] + helper(r+1, c, rows, cols, grid, DP);
        return cache = min(way1, way2);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> DP(rows, vector<int>(cols, -1));
        return helper(0, 0, rows, cols, grid, DP);
    }
};