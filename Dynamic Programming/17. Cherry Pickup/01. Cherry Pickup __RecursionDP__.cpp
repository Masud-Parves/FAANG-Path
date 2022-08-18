/*
    Problems Link : https://leetcode.com/problems/cherry-pickup/
    TC - O(row*col*col)
    SC - O(rows*cols*cols) + O(rows) Recursion Stack Memory.
*/
class Solution {
private:
    int helper(int r, int c1, int c2, vector<vector<int>>& grid, vector<vector<vector<int>>>& DP, int rows, int cols){
        int r2 = c1+r-c2;
        if(r2 == rows || r == rows || c1==cols || c2 == cols || grid[r][c1]==-1 || grid[r2][c2]==-1) return INT_MIN;
        if(r == rows-1 && c1==cols-1){
            return grid[r][c1];
        }
        
        int& cache = DP[r][c1][c2];
        if(cache != -1){
            return cache;
        }

        int cherry = 0;
        if(r==r2 and c1==c2) cherry = grid[r][c1];
        else  cherry += grid[r][c1] + grid[r2][c2];

        int ways = helper(r, c1+1, c2+1, grid, DP, rows, cols);
        ways = max(ways, helper(r, c1+1, c2, grid, DP, rows, cols));
        ways = max(ways, helper(r+1, c1, c2, grid, DP, rows, cols));
        ways = max(ways, helper(r+1, c1, c2+1, grid, DP, rows, cols));
        return cache = cherry + state;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<vector<int>>> DP(rows+1, vector<vector<int>>(cols+1, vector<int>(cols+1, -1)));
        return max(0,helper(0, 0, 0, grid, DP, rows, cols));
    }
};
