/*
    Problems Link : https://leetcode.com/problems/minimum-falling-path-sum-ii/
    TC - O(N^3)
    SC - O(N*N) + O(N*N) Recursion Stack Memory.
*/

class Solution {
private:
    int helper(int r, int prev, vector<vector<int>>& grid, int rows, int cols, vector<vector<int>>& DP){
        if(r == rows){
            return 0;
        }
        int& cache = DP[r][prev];
        if(cache != -1){
            return cache;
        }
        
        cache = INT_MAX;
        for(int c=0; c<cols; c++){
            if(c==prev) continue;
            cache = min(cache , grid[r][c] + helper(r+1, c, grid, rows, cols, DP));
        }
        return cache;
    }
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> DP(rows+1, vector<int>(cols+1, -1));
        return helper(0, cols, grid, rows, cols, DP);
    }
};